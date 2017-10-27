
#include <iostream>
#include <cmath>
#include "ComputerClass.cpp"
using namespace std;

int main(){

    Computer CPU;
    int temp_num_ = CPU.RandomNumGen();
    
    cout << "Random number: " << temp_num_<< endl;
    cout << "Score before adding: " << CPU.GetScore() << endl;
    cout << "Continue before adding: " << CPU.GetContinue() << endl;
    cout << "Win before adding: " << CPU.GetWin() << endl;
    
    CPU.DetermineAddScore(temp_num_);
    
    cout << "Score after adding: " << CPU.GetScore() << endl;
    cout << "Continue after adding: " << CPU.GetContinue() << endl;
    cout << "Win after adding: " << CPU.GetWin() << endl;
    return 0;
}