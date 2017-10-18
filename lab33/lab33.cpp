//Created by: Nick LS
//Created on: 10/17/17

/*The following lab is meant to simulate a guessing game. The user will input a number between 1 and 50,
and depending on whether it is higher or lower than the selected number, the algorithm will output either:
"Too high" or "Too low". Once the user guesses the correct number it ends the program.*/

#include <iostream>
#include <iostream>
using namespace std;

int main() {
    
    srand(time(0));                                 //seeds random number generator
    int random_number = 0;             //generates the random number and stores the value
    int user_input = 0;                                  //User's input is stored here
    int top_loop_count = 5;
    int loop_count;                                 //Variable used to determine how many tries the user gets
    char play_again = 'y';                              //


    while (play_again == 'y') {
        cout << "Please enter a number between 1 and 50: " << endl;
        cin >> user_input;                               //user assigns a value to enter into the loop with
        cout << endl;
        loop_count = top_loop_count;
        int random_number = ((rand() % 50) + 1);
        
        for (int i = 0; i < loop_count; i++){
            
            if (user_input != random_number) {             
                
                if (user_input <= 50 && user_input >= 1) {        //this line is to preface if the input number is between 1 and 50
                    if (user_input < random_number) {
                        cout << "Too low, Enter a Higher Number: " << endl;          //this lets the user know their number is comparitively 
                    }                                                       //low to the random number
                    else if (user_input > random_number) {
                        cout << "Too high, Enter a Lower Number: " << endl;           //this lets the user know their number is comparitively
                    }
                }
                else {
                    cout << "Number is not between 1 and 50" << endl;       //this is in case the input number is not between 1 and 50
                }
                
            cout << "You have " << (loop_count - i) << " tries left" << endl; 
            
            cout << "Please enter a number between 1 and 50: " << endl;     //this is reached if the user did not guess the right number
            cin >> user_input;                                               //and gives the user a chance to guess again before the loop starts over
            cout << endl;
            }
            
            if (user_input == random_number) {
                cout << "Just Right" << endl;
                loop_count = 0;
            }
            
            if ((user_input != random_number) && ((loop_count - i) == 0)){
                cout << "You lose!" << endl;
            }
        }
        
        cout << "Play again? (Enter y for Yes, and n for No: " << endl;
        cin >> play_again;
        cout << endl;
    }
    
    cout << "Goodbye!" << endl;
    
    return 0;
}