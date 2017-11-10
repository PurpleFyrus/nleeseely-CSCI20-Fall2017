//Created by: Nick LS
//Created on: 11/9/17

/*the following file is meant to take in user input of a first and last name, run it through some checkpoints for warnings
and then output some username options at the end*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main(){
    
    char first_name[50];    //C string of size 50 is made for first name.
    char last_name[50];     //C string of size 50 is made for last name.
    
    cout << "Input your first name: ";      //Asks for user input of first name.
    cin >> first_name;                      //Takes that user input and stores it in the C-String "first_name".
    
    cout << "Input your last name: ";       //Asks for user input of last name.
    cin >> last_name;                       //Takes that user input and stores it in the C-String "last_name".
    
    if (strlen(first_name) > 10){           //Compares the length of the C-string "first_name" to see if it is greater than 10.
        cout << "Warning: First name is too long" << endl;      //If it is, then it outputs a warning.
    }
    
    if (strlen(last_name) > 20){            //Compares the length of the C-string "last_name" to see if it is greater than 20.
        cout << "Warning: Last name is too long" << endl;       //If it is, then it outputs a warning.
    }
    
    if (strcmp(first_name, last_name) == 0){        //Compares the C-string "first_name" with the C-string "last_name".
        cout << "Warning: First name and last name are the same" << endl;       //If they are then the boolean outputs 0, which then fulfills the condition and outputs a warning.
    }
    
    //The following 5 lines are just version of user names made with the input the user put in.
    cout << "User Name 1: " << first_name[0] << first_name[1] << last_name << endl;
    
    cout << "User Name 2: " << first_name << last_name << endl;
    
    cout << "User Name 3: " << first_name[0] << last_name << endl;
    
    
    return 0;
}