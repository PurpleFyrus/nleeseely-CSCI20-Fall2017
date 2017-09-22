//created by: nick ls
//created on: 9/21/17

//random num generator guess game, thats the deal, lets make it real

#include <iostream>
#include <cmath>
using namespace std;

int randomNumGen(){         //this is the function declaration, everyting post up to return 0; is definition and body
        srand(time(0));              //seed for the random number generator
    
    cout << "Your random number is ";       //output telling user what their number is
    cout << ((rand() % 100) + 1);           //output of their number
    cout << ".";                            //output of a period for gramatical purposes
    
    return 0;
};

int main(){
    
    randomNumGen();                         //calling of the function
    
    return 0;
}