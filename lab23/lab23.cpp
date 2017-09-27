//created by: nick ls
//created on: 9/26/17

#include <iostream>
#include <cmath>
using namespace std;

int SwapNums(int& num_1, int& num_2){ //function that swaps the first argument with the second
    int temp_num = 0;
    temp_num = num_1;
    num_1 = num_2;
    num_2 = temp_num;
    
    return 0;
}

int RandomNumGen(int num_1, int num_2) {    //function that gives user random num between num_1 and num_2
    srand(time(0));                         //seeds the random numbers
    SwapNums(num_1, num_2);                 //swap function called
    return (rand() % (num_1 - num_2 - 1)) + num_2 + 1; //outputs random num in the range between num_1 and num_2
}

int main(){
    
    int number_1 = 0;   //variable for lower number
    int number_2 = 0;   //variable for higher number
    
    cout << "Enter Small number: " << endl; //user inputs smaller number
    cin >> number_1;
    
    cout << "Enter Large number: " << endl; //user inputs larger number
    cin >> number_2;
    
    cout << " Your Random number between: " << number_2 << " and " << number_1 << " is: " << RandomNumGen(number_1, number_2);
    //outputs answer by calling function RandomNumGen()
    return 0;
}