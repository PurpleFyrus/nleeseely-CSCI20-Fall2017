
#include <iostream>
#include <cmath>
using namespace std;

class Computer{
    private: 
        int score_;
        char continue_;             //Used for both determining if the CPU has the "Ability / Opportunity" to continue, and also if it wants to
        int win_;                   //0 means it won, 1 means it hasn't won (yet)
        int random_seed_;
        int temp_continue_;
    public:
        Computer();
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

Computer::Computer(){
    score_ = 0;
    continue_ = 'y';
    win_ = 1;
    random_seed_ = 0;
}

int Computer::RandomNumGen(){
    srand(time(0));
    return ((rand() % 6) + 1);
}

void Computer::DetermineAddScore(int value_){
    if (value_ == 1){       //In the event the CPU rolls a 1
        score_ = 0;         //It's score is set to 0
        continue_ = 'n';    //And it's continue opportunity is set to no ('n')
    }
    else{                   //Otherwise
        score_ = score_ + value_;       //The CPU gets the score it rolled between 2 & 6 added to its total score
        continue_ = 'y';                //Then gets the opportunity to roll again if it chooses.
    }
    return;
}

void Computer::DetermineToContinue(){       //This determines if the CPU can and will continue, but I don't check for their score since the continue question isn't really seen, so it doesn't matter either way.
    
    if (continue_ == 'y'){          //Only executes if the CPU has the opportunity to continue, when continue_ == 'y'
        if ((score_ >= 0) && (score_ < 10)){
            continue_ = 'n';
        }
        else if ((score_ >= 10) && (score_ < 16)){
            continue_ = 'y';
        }
        else if ((score_ >= 16) && (score_ < 19)){
            continue_ = 'y';
        }
        else if ((score_ >= 19) && (score_ < 22)){
            continue_ = 'n';
        }
        else if ((score_ >= 22) && (score_ < 39)){
            continue_ = 'y';
        }
        else if ((score_ >= 39) && (score_ < 41)){
            continue_ = 'n';
        }
        else if ((score_ >= 41) && (score_ < 45)){
            continue_ = 'y';
        }
        else if ((score_ >= 45) && (score_ < 55)){
            continue_ = 'n';
        }
        else if ((score_ >= 55) && (score_ < 59)){
            continue_ = 'n';
        }
        else if ((score_ >= 59) && (score_ < 64)){
            continue_ = 'y';
        }
        else if ((score_ >= 64) && (score_ < 67)){
            continue_ = 'n';
        }
        else if ((score_ >= 67) && (score_ < 71)){
            continue_ = 'n';
        }
        else if ((score_ >= 71) && (score_ < 73)){
            continue_ = 'n';
        }
        else if ((score_ >= 73) && (score_ < 75)){
            continue_ = 'n';
        }
        else if ((score_ >= 75) && (score_ < 79)){
            continue_ = 'y';
        }
        else if ((score_ >= 79) && (score_ < 82)){
            continue_ = 'n';
        }
        else if ((score_ >= 82) && (score_ < 88)){
            continue_ = 'y';
        }
        else if ((score_ >= 88) && (score_ < 92)){
            continue_ = 'n';
        }
        else if ((score_ >= 92) && (score_ < 96)){
            continue_ = 'y';
        }
        else if ((score_ >= 96) && (score_ < 100)){
            continue_ = 'y';
        }
        else {
        }
    }                           //If CPU doesn't have the choice to continue, it stays that way (in the event it rolled a 1)
    return;
}

void Computer::DetermineIfWon(){
    if (score_ >= 100){         //If they have 100 or more points
        win_ = 0;               //Then the CPU wins!
        continue_ = 'n';        //And continue_ is assigned n so that it won't loop any more turns for the CPU.
    }
    return;
}

int Computer::GetScore(){
    return score_;
}

char Computer::GetContinue(){
    return continue_;
}

int Computer::GetWin(){
    return win_;
}

void Computer::SetScore(int score_value_){
    score_ = score_value_;
    return;
}

void Computer::SetContinue(char continue_value_){
    continue_ = continue_value_;
    return;
}

void Computer::SetWin(int win_value_){
    win_ = win_value_;
    return;
}