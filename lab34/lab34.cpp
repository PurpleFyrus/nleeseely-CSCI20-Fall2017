 // This program reads in a letter and reports whether
// it is an uppercase letter, a lowercase letter, or neither.
// it should continue reading in values until the user enters a -1.
#include <iostream> 
using namespace std; 
int main() {
        // Read a character in
        char ch;
        
    while (ch != -1){
        cout << "Please enter a character: ";
        cin  >> ch;
         
// check -- is it a letter??
        if ((ch >= 'A') && (ch <= 'Z')) {
               cout << "Yes, that is a uppercase letter." << endl;
        }
        else if ((ch >= 'a') && (ch <= 'z')) {
               cout << "Yes, that is a lowercase letter" << endl;
        }        
        else {
            cout << "Not a letter" << endl;
        }
    }
    return 0;
}