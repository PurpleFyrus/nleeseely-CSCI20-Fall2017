//Created by: Nick LS
//Created on: 9/28/17

/*The following program is designed to take input in the form of 2 variables holding integer values,
then proceed to swap the values stored in the variables, then run it through a function that converts
from pounds to kilograms, and then run through another function that converts from kilograms back to 
pounds.*/

//Im going to fix this program so it outputs what is necessary, unless you are ok with where it is currently.
//Up to you.

#include <iostream>
using namespace std;

int RandomNumGen(int& num_1, int& num_2) {    //Function that takes in two double varaibles.
    int temp_num = 0;                           //Then it proceeds to swap the values stored in those variables.
    temp_num = num_1;
    num_1 = num_2;
    num_2 = temp_num;
    
    srand(time(0));                         //Seeds the random numbers.
    return (rand() % (num_1 - num_2 - 1)) + num_2 + 1; //Outputs random number in the range between num_1 and num_2.
}

double PoundsToKilograms(double pounds){    //Function takes in a variable, assumes it's a unit of pounds and converts to kilograms which it outputs.
    return pounds * 0.453592;
}

double KilogramsToPounds(double kilograms){ //Function takes in a variable, assumes it's a unit of kilograms and converts to pounds
    return kilograms * 2.20462;
}

int main(){
    int number_1;                           //Variable for storage of first user input value.
    int number_2;                           //Variable for storage of second user input value.
    double random_number    = 0.0;          //Variable for storage of random number after function RandomNumGen call
    double kilograms        = 0.0;          //Variable for storage of converted number after function PoundsToKilograms call
    double pounds           = 0.0;          //Variable for storage of converted number after function KilogramsToPounds call
    
    cout << "Enter a num num yah dum dum: ";    
    cin >> number_1;                                    //User input for first number.
    
    cout << "Enter another num num yah dum dum: ";
    cin >> number_2;                                    //User input for second number.
    
    random_number   = RandomNumGen(number_1, number_2);         //Function call of RandomNumGen and storage of result in variable random_number.
    kilograms       = PoundsToKilograms(random_number);         //Function call of PoundsToKilograms and storage of result in variable Kilograms.
    pounds          = KilogramsToPounds(kilograms);             //Function call of KilogramsToPounds and storage of result in variable Pounds.
    
    cout << random_number << " Is your random amount of Pounds" << endl;                //Output of random_number value
    
    cout << "Here are how many Kilograms that would be: " << kilograms << endl;         //Output of kilograms' value
    cout << "Here are how many Pounds those Kilograms would be: " << pounds << endl;    //Output of pounds' value
    
    return 0;
}