//Nick LS
//who knows

//game of pig

#include <iostream>
#include <cmath>
#include "ComputerClass.cpp"
#include "UserClass.cpp"
using namespace std;

int main(){

Computer CPU;
User USER;
int temp_num_;

while((CPU.GetWin() == 1) && (USER.GetWin() == 1)){      //Overall loop iterates until one of the two players (User & CPU) wins.

    USER.SetContinue('y');           //Resets User's ability to have their turn, so following loop works. 
    //USER turn
    while (USER.GetContinue() == 'y'){
        
        cout << "Your turn" << endl;
        
        temp_num_ = USER.RandomNumGen();
        USER.DetermineAddScore(temp_num_); 
        
        cout << "You rolled a " << temp_num_ << endl;
        cout << "After that roll, your score is now: " << USER.GetScore() << endl;
        
        USER.DetermineToContinue();
        
        USER.DetermineIfWon();
    }
    
    CPU.SetContinue('y');        //Resets CPU's ability to have their turn, so following loop works.
    //CPU turn
    while (CPU.GetContinue() == 'y'){
        
        cout << "CPU's turn" << endl;
        
        temp_num_ = CPU.RandomNumGen();
        CPU.DetermineAddScore(temp_num_);
        
        cout << "CPU rolled a " << temp_num_ << endl;
        cout << "After that roll, it's score is now: " << CPU.GetScore() << endl;
        cout << endl;
        
        CPU.DetermineToContinue();
        
        CPU.DetermineIfWon();
    }
}

if ((USER.GetWin() == 0) && (CPU.GetWin() == 0)){   //The only time the main loop will end with both players having a score over 100, is when the user won during their turn, and then the CPU won in their proceeding turn, which means the User won
    cout << "User wins!" << endl;
}
else if (USER.GetWin() == 0){                     //If the User is the only one with a score over 100, then obviously they win
    cout << "User wins!" << endl;
}
else {
    cout << "CPU wins!" << endl;
}
    
    return 0;
}