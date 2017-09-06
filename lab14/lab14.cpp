//Created by: Nick LS
//Created on: 9/5/17

/*About Algorithm: the following is supposed to be a coinstar simulator, 
taking in a large amount of coins, placing them in an organized manner 
of least of each coin into separate variables. Then take a 10.9% tax of the 
cash total and giving the inputter a message of what they get back. */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int cash_in     = 0;
    
    int quarters    = 0;
    int dimes       = 0;
    int nickels     = 0;
    int pennies     = 0;
    
    int post_quarters   = 0;
    int post_dimes      = 0;
    int post_nickels    = 0;
    
    double cash_out     = 0.0;
    double fee_percent  = 0.109;
    double fee          = 0.0;
    
    cout << "Please enter the amount of change you have in pennies, no decimal place:" << endl;
    cin >> cash_in;         //amount of cash going into coinstar in the form of pennies
    
    quarters = cash_in / 25;            //determing amount of quarters
    post_quarters = cash_in % 25;
    
    dimes = post_quarters / 10;         //determing amount of dimes
    post_dimes = post_quarters % 10;
    
    nickels = post_dimes / 5;           //determing amount of nickels
    post_nickels = post_dimes % 5;      //determing amount of pennies
    
    pennies = post_nickels;             
    
    cout << fixed;
    cout << setprecision(2);

    cash_out = (cash_in * (1.0 - fee_percent)) / 100;       //calculating final amount after fee
    fee = (cash_in * fee_percent) / 100;                    //calculating fee
    
    cout << "You inserted: " << endl;
    cout << quarters << " quarters" << endl;
    cout << dimes << " dimes" << endl;
    cout << nickels << " nickels" << endl;
    cout << pennies << " pennies" << endl;
    
    cout << "After a fee of: " << fee << ", you are left with: $" << cash_out << endl;
    
    return 0;
    
}