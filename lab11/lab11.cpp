//Created By: Nick LS
//Created on: 8-24-2017


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
    
    
int main()
{
    srand(time(0));
    int randomNum = ((rand() % 100) + 1);
    
    
    cout << "The random number generated is: " << randomNum << endl;
    
}

    


