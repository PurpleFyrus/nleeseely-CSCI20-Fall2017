
#include <iostream>
#include <cmath>
using namespace std;

class User{
    private:
        int score_;
        char continue_;             //Used for both determining if the User has the "Ability / Opportunity" to continue, and also if they want to
        int win_;                   //0 means the user won, 1 means the user hasn't won (yet)
    
    public:
        User();
        int RandomNumGen();
        void DetermineAddScore(int value_);
        void DetermineToContinue();
        void DetermineIfWon();
        
        int GetScore();
        char GetContinue();
        int GetWin();
        
        void SetScore(int score_value_);
        void SetContinue(char continue_value_);
        void SetWin(int win_value_);
        
};

User::User(){               //Constructor designed to set each variable to proper values that run the file smoothly from the start
    score_ = 0;        //User should start from a score of 0 obviously.
    continue_ = 'y';
    win_ = 1;          //User should not start out with already winning, therefore it's set to 1
}

int User::RandomNumGen(){
    srand(time(0));
    return ((rand() % 6) + 1);
}

void User::DetermineAddScore(int value_){
    if (value_ == 1){       //In the event the User rolls a 1
        score_ = 0;         //Their score is set to 0
        continue_ = 'n';    //And their continue opportunity is set to no ('n')
    }
    else{                   //Otherwise
        score_ = score_ + value_;       //The User gets the score it rolled between 2 & 6 added to their total score
        continue_ = 'y';                //Then they get the opportunity to roll again they choose to do so.
    }
    return;
}

void User::DetermineToContinue(){
    if((score_ < 100) && (continue_ == 'y')){              //Only allows the user to even get to the point of being determined if they want to continue, if they haven't won already & have the ability to choose to continue
                cout << "Do you want to continue your turn? (enter y or n)" << endl;
                cin >> continue_;
    }                          //If User doesn't have the choice to continue, it stays that way (in the event they rolled a 1)
    return;
}

void User::DetermineIfWon(){
    if (score_ >= 100){
        win_ = 0;
        continue_ = 'n';        //And continue_ is assigned n so that it won't loop any more turns for the User.
    }
    return;
}

int User::GetScore(){
    return score_;
}

char User::GetContinue(){
    return continue_;
}

int User::GetWin(){
    return win_;
}

void User::SetScore(int score_value_){
    score_ = score_value_;
    return;
}

void User::SetContinue(char continue_value_){
    continue_ = continue_value_;
    return;
}

void User::SetWin(int win_value_){
    win_ = win_value_;
    return;
}