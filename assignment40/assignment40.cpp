//Created by: Nick LS
//Created on: 11/19/17

/*concordance*/

#include <iostream>
#include <fstream>
#include <string> 
#include <cstring> 
#include <cctype>  
#include <cstdlib> 
#include <iomanip>
using namespace std;


int main(){
    
    ifstream fin;
    ofstream fout;
    
    string source[100];     //String array used for the first storing of the input .txt file's contents, and later curated for punctuation and capitalization
    string source_2[100];   //String array used for the storing of the input .txt file's contents, uncurated when it comes to punctuation
    string word[100];       //String array that will hold all the stored words from the source file after being curated
    string word_2[100];     //String array that will hold all the stored words from the source file after being curated for capitalization ONLY (not punctuation)
    string stop[571];       //String array that will hold all the stop words from the stop.txt file
    int num_occur[100];     //Integer array that will be parallel to the word[100] array, and will have the corresponding occurrences of each word
    int first_occur[100];   //Integer array that will be parallel to the word[100] array, and will have the corresponding first occurrence of each word
    string is_new = "yes";  //String variable used later on to differentiate when a word is new or has already been stored before in word[]
    string is_stop = "no";  //String variable used to tell whether it's a stop word or not
    string input_text_full;     //String variable used later on to print out the input.txt file's contents
    string input_text_full_2;   //String variable used later on to find the First Occurrence of a word from the original input.txt file
    int num_source_words = 0;   //Integer variable used in a later loop, mainly for the counting of words coming in from the input.txt file, but also used for later loop iteration counters.
    int num_word_words = 0;     //Integer variable used in a later loop, mainly for the counting of words stored in the string array word[], but also used for later loop iteration counters.
    int num_stop_words = 0;     //Integer variable used in a later loop, to count the number of words in the stop.txt
    
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//First is the opening of the input.txt and taking in each word as it's own separate string, and storing it all into source[] array
    fin.open("input.txt");
    
    for(int i=0;!fin.eof(); i++){   //Here we transfer the input.txt file into a string array for safe keeping
        fin >> source[i];
        num_source_words = num_source_words + 1;
    }
    
    fin.close();
    
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Next is the opening of the stop.txt and taking in each word into the stop[] array
    fin.open("stop.txt");
    
    for(int i=0;!fin.eof(); i++){   //here we transfer the contents of stop.txt file into a string array for later use.
        fin >> stop[i];
        num_stop_words = num_stop_words + 1;
    }
    
    fin.close();
    
//----------------------------------------------------------------------------------------------------------------------------------------------------------------- 
//Then we create a separate string for later use to print out the original input for visual reasons
    
    input_text_full = source[0];        //I first assign source[0] to input_text_full so that there is no space at the beginning
    
    for(int i = 1; i < num_source_words; i++){
        input_text_full = input_text_full + ( " " + source[i]);
    }
    
    for(int i = 0; i<100; i++){       //This should copy all the contents from source string array to source_2 string array, so that the following section doesn't affect source_2 contents.
      source_2[i] = source[i];
    }
    
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//Then we clean up all the values stored in source[] array, by removing all punctuation
    for(int i = 0; i < 100; i++){       //This for loop goes through the source string array and removes all punctuation
        string temp_string = source[i];
        for(int j = 0; j < temp_string.length(); j++){
            if(ispunct(temp_string[j])){
                temp_string.erase(j);
            }
        }
        source[i] = temp_string;
    }

//And then we do the same for uppercase, changing it all to lower case  
    for(int i = 0; i < 100; i++){       //This for loop goes through the source string array and changes all upper case letters to lower case
        string temp_string = source[i];
        for(int j = 0; j < temp_string.length(); j++){
            if(isupper(temp_string[j])){
                temp_string[j] = tolower(temp_string[j]);
            }
        }
        source[i] = temp_string;
    }
    
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------    
//This part is just like the above section, but made specifically to have a copy of the source array, but still with the punctuation, for "first occurrence" reasons  
    
    for(int i = 0; i < 100; i++){       //This for loop goes through the source_2 string array and changes all upper case letters to lower case
        string temp_string = source_2[i];
        for(int j = 0; j < temp_string.length(); j++){
            if(isupper(temp_string[j])){
                temp_string[j] = tolower(temp_string[j]);
            }
        }
        source_2[i] = temp_string;
    }
    
    input_text_full_2 = source_2[0];        //I first assign source_2[0] to input_text_full so that there is no space at the beginning
    
    for(int i = 1; i < num_source_words; i++){
        input_text_full_2 = input_text_full_2 + ( " " + source_2[i]);
    }
    
    
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//The following section is what goes through the string array source[], stores a new word in the string array word[], and adds a count to the word occurrence if it has already been stored in word[]
    for (int j = 0; j < num_source_words; j++){

        is_new = "yes";                             //This is set to yes, so that after the main loop's iteration's word being compared (source[j]) is compared to all words already stored in word[], if it did not match at all, it will be stored into word[] as a new found word.
        is_stop = "no";                             //This is set to no, so that after the following nested loop iterates all the way through, if source[j] did not come out to be a stop word, it will continue onwards in the following if statement
        
        for (int h = 0; h < num_stop_words; h++){   //This loop iterates through all the stop words provided by the stop.txt
            if(source[j] == stop[h]){               //If the main overall loop's iteration's word from source[j] is a stop word
                is_stop = "yes";                    //Then the string variable is_stop is assigned "yes" so that the following if statement & loops within it are not run.
            }
        }
        
        if(is_stop == "no"){
            for (int i = 0; i < num_word_words; i++){              //This loop iterates all the way through word[] so that it can be fully searched through for matching words, in case source[j] has already been found and stored.
    
                if(source[j] == word[i]){               //If the main loop's iteration's word from the string array source[] has already been stored in the string array word[]
                    num_occur[i] = num_occur[i] + 1;    //Then that corresponding word gets +1 to it's occurrence count
                    is_new = "no";                      //And the is_new counter stays set to no, since it's not a word found.
                }
            }
        
            if(is_new == "yes"){                        //If the nested loop from a few lines before iterated all the way through, and didn't find any matches of already stored words in word[] to source[j]
               word[num_word_words] = source[j];        //Then that word is then stored into the word[] array
               num_occur[num_word_words] = 1;           //Seeing as word[j] is a new word, then it needs to be given a counter of 1.
               word_2[num_word_words] = source_2[j];    //And also, the corresponding source word in lower case & punctuated format is copied into word_2 string array, for later occurrence searching.
               
               num_word_words = num_word_words + 1;     //And the word count is added 1 so that the next new word entered on a following iteration of the overall loop, won't overwrite this value stored in word[].
            }                                           //Have to make sure the word count is add to after the previous 4 lines, because then the wrong memory locations are accessed
        }
    }

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

//possible code for first occurrence finder: first_occur[i] = source.find(word[i]);

for(int i=0; i<num_word_words; i++){
    first_occur[i] = input_text_full_2.find(word_2[i]);
} 

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//Here is the output of the words, number of occurrences, and location of first occurrences to an html file.

fout.open("output.html");

    for(int i=0; i<num_word_words; i++){
        fout << word[i] << " " << num_occur[i] << " " << first_occur[i] << endl;
    }

fout.close();

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//Here is the input.txt printed for easier readability
    for(int i=0; i<num_source_words; i++){
       cout << source[i] << " ";
    }
    
    cout << endl;
    
    for(int i=0; i<num_source_words; i++){
       cout << source_2[i] << " ";
    }
    
    cout << endl;       //These are for spacing reasons
    cout << endl;
    
//Here is the printing of the words that got stored in word[] array that weren't stop words, their number of occurrences, and the location of their first occurrence
    for (int i = 0; i < num_word_words; i++){
        cout << word[i] << " " << num_occur[i] << " " << first_occur[i] << endl;
    }
    
    cout << input_text_full << endl;
    cout << input_text_full_2 << endl;
    
    
    return 0;
}