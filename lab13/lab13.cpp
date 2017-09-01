//Created by: Nick LS  
//Created on: 8/31/2017

//following program is designed to estimate current population depending on input

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    
    double sec_per_birth;
    double sec_per_death;
    double sec_per_immigrant;
    
    double current_population;
    
    long int total_gain;
    
    int current_year;
    int years_passed;
    
    int days_passed;
    int hours_passed;
    int minutes_passed;
    long int sec_passed;
    
    sec_per_birth     = 8;
    sec_per_death     = 12;
    sec_per_immigrant = 33;
    
    cout << "Enter the current year: " << endl;
    cin >> current_year;
    
    cout << "Enter the current population: " << endl;
    cin >> current_population;
    
    cout << "Enter the number of year in the future you want to go: " << endl;
    cin >> years_passed;
    
    days_passed         = years_passed * 365;
    hours_passed        = days_passed * 24;
    minutes_passed      = hours_passed * 60;
    sec_passed          = minutes_passed * 60;
    
    total_gain = ((sec_passed / sec_per_birth) + (sec_passed / sec_per_immigrant)) - (sec_passed / sec_per_death);
    
    current_population += total_gain;
    
    total_gain *= years_passed;
    
    cout << "Population in that year: " << current_population << endl;
    
    cout << "Total gain is: " << total_gain;
    
    return 0;
    
    
    
}