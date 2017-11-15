//Created by: Nick LS
//Created on: 11/9/17

/*the following file is meant to take in user input of a first and last name, run it through some checkpoints for warnings
and then output some username options at the end*/

/*got some stack overflow info on functions to use in regards to counting string size: https://stackoverflow.com/questions/20180874/how-to-get-length-of-a-string-using-strlen-function */

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
    
    string first_name;    //C string of size 50 is made for first name.
    string last_name;     //C string of size 50 is made for last name.
    int i[3] = {1,1,1};       //Int variable used for loops and stuff.
    
    while(i[2] != 0) {          //This loop is the overall loop, which is related to the comparison of the first and last name strings later on.
    
        while(i[0] != 0) {      //Loop will iterate as long as i has a value other than 0.
            
            cout << "Please enter your first name: " << endl;
            getline(cin, first_name);
            
            if(first_name.length() > 10) {
                cout << "First Name entered is too long, please enter a name under character limit of 10" << endl;
            }
            else{
                i[0] = 0;           //This will break the loop if the user inputs a first name of the correct length.
            }
        }
        
        while(i[1] != 0) {      //Loop will iterate as long as i has a value other than 0.
        
            cout << "Please enter your last name: " << endl;
            getline(cin, last_name);
            
            if(last_name.length() > 20) {
                cout << "Last Name entered is too long, please enter a name under character limit of 20" << endl;
            }
            else{
                i[1] = 0;           //This breaks the loop if the user inputs a last name of the correct length.
            }
        }
        
        if(first_name == last_name) {       //If the names are the same, it resets the loop breaker variable values, and loops back to the beginning of the overall loop.
            cout << "First and Last name are the same, please have different names for each. Sending you back to the beginning now." << endl;
            i[0] = 1;
            i[1] = 1;
        }
        else{                               //If the names are not the same, the overall loop is broken and proceed to the end.
            i[2] = 0;
        }
    }
    
    cout << "Thank you for your info, now generating suggested user names: " << endl;
    
    cout << "User Name 1: " << first_name[0] << first_name[1] << last_name << endl;
    
    cout << "User Name 2: " << first_name << last_name << endl;
    
    cout << "User Name 3: " << first_name[0] << last_name << endl;
    
    return 0;
}