//Created by: Nick LS
//Created on: 10/3/17

/*About: the following algorithm is meant to take in 3 parts of a book for 5 books
It also is supposed to have a class predefined with setters and getters for each variable
that is private, and finally a print function. For each input of a variable the value is 
then output so the user knows what they input. Then at the end everything is output for review */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class book {                            //This is the class for storing book info.
        private:
            string title_;              //Book title goes in this variable.
            string author_;             //Book author goes in this variable.
            int copyright_year_;        //Book copyright_year goes in this variable.
        public:     //The following 7 lines are just function declarations, the definitions follow after the class "book"'s body.
            void SetTitle(string title);        //Function used to assign a string literal to the title_ variable.
            string GetTitle() const;            //Function used to call the value of the title_ variable.
            void SetAuthor(string author);      //Function used to assign a string literal to the author_ variable.
            string GetAuthor() const;           //Function used to call the value of the author_ variable.
            void SetCopyrightYear(int year);    //Function used to assign an integer value to the copyright_year_ variable.
            int GetCopyrightYear() const;       //Function used to call the value of the copyright_year_ variable.
            void Print();                       //Function used to output all the values of the 3 variables in this class.
};

//the following 33 lines are the definitions of the 7 functions declared above.
void book::SetTitle(string title){
    title_ = title;
    return;
}

string book::GetTitle() const{
    return title_;
}

void book::SetAuthor(string author){
    author_ = author;
    return;
}

string book::GetAuthor() const{
    return author_;
}

void book::SetCopyrightYear(int year){
    copyright_year_ = year;
    return;
}

int book::GetCopyrightYear() const{
    return copyright_year_;
}

void book::Print(){
    cout << "Title: " << title_ << endl;
    cout << "Author: " << author_ << endl;
    cout << "Copyright Year: " << copyright_year_ << endl;
    return;
}

int main(){
    
    string variable;            //Variable used to store string values for a short time in between assignment to different object's variables.
    int variable_2;             //Like the first variable, serves the same purpose except is for integer values.
    
    int number_of_books = 5;        //Number of books needed to be defined
    book novel[number_of_books];    //Class array for easier use in later loops, these objects are using the "book" class.
    
    for (int i = 0; i < number_of_books; i++) {     //Start of a loop iterating only the "number of books" times.
    
    cout << "Please enter novel " << i + 1 << "'s title: ";
    getline(cin, variable);                         //Storing of first input, title into placeholder variable.
    
    novel[i].SetTitle(variable);                    //Storing of placeholder's value into actual variable of the iteration's object. For the title.
    cout << novel[i].GetTitle() << endl;            //Returning of that variable to ensure correct input and verify Getter function of object works.
    
    cout << "Please enter novel " << i + 1 << "'s author: ";
    getline(cin, variable);                         //Another storing of a string temporarily.
    
    novel[i].SetAuthor(variable);                   //Storing of placeholder's value into actual variable of the iteration's object, this time for the author not the title.
    cout << novel[i].GetAuthor() << endl;;          //Once again outputting the object's variable's value for visual confirmation.
    
    cout << "Please enter novel " << i + 1 << "'s copyright year: ";
    cin >> variable_2;                              //Final storing of user input during the loop iteration for the integer value stored later on in copyright_year_.
    cin.ignore(1000, '\n');     //used to prevent issues from transerring between getline() and cin.
    
    novel[i].SetCopyrightYear(variable_2);          //Variable_2's stored value is assigned to the iteration's object's variable copyright_year_.
    cout << novel[i].GetCopyrightYear() << endl;    //One last time that variable is then output.
    }   //then either another loop iteration begins or if that was the 5th iteration it ends and proceeds onwards.
    
    cout << "  " << endl;
    cout << "Now comes the output of everything" << endl;
    cout << "  " << endl;
    
    for (int i = 0; i < number_of_books; i++) {     //This loop uses the print function of each object to output all results of the stored values.
        cout << "Book: " << i + 1 << endl;
        novel[i].Print();
        cout << "  " << endl;
    }
    
    return 0;
}