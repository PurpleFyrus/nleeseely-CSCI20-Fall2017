//Created by: Nick LS
//Created on: 10/12/17

/*Following program takes into account user's marriage status, then determines a personal exemption.
Next it determines whether to take into account taxes and if so follows to two routes depending on marital status.
Finally the final tax amount calculated is compared to income withheld and does the final check if taxes are due.*/

#include <iostream>
#include <iostream>
using namespace std;

int main(){
    string user_name;                               //Variable used to store user's name
    int filing_status = 0;                          //Variable used for later use with user's martial status
    double gross_income = 0.0;                      //Variable used to store user's initial gross income
    double adjusted_gross_income = 0.0;             //Variable used to store later adjusted gross income
    double taxes_due = 0.0;                         //Variable used to store later determined taxes that are due
    double tax_withheld = 0.0;                      //Variable used to store user's input for withheld money
    int need_for_taxes = 1;                         //Variable used to determine whether to take the switch case later on used for determining taxes due

    cout << "Please enter your name: ";             //User inputs their name
    getline(cin, user_name);

    
    cout << "Please enter your Filing Status, 1 for single and 2 for married: ";    //User inputs their filing status
    cin >> filing_status;
        
    cout << "Please enter your Gross Income: ";                                     //User inputs their overall gross income
    cin >> gross_income;
    
    cout << "Please enter amount of tax withheld: ";                                //User inputs their tax withheld
    cin >> tax_withheld;
    
    adjusted_gross_income = gross_income - 4050;                                    //First part of determining adjusted gross income
    
    switch(filing_status){                                                          //Second part of determining adjusted gross income, determined by filing status
        case 1:
            adjusted_gross_income = adjusted_gross_income - 6350;                   //This branch is taken if the user is filing as single
            break;
        case 2:
            adjusted_gross_income = adjusted_gross_income - 12700;                  //This branch is taken if the user is filing as married
            break;
        default:
            cout << "Issue with filing status, please enter 1 or 2 next time" << endl;      //This happens if they didn't enter either 1 or 2
            break;
    }
    
    if (adjusted_gross_income <= 0){                      //This if else is used to determine if the user needs to have their taxes calculated depending on what the outcome is after the deductions from above.
        cout << "No need to calculate taxes, no taxes are due." << endl;
        need_for_taxes = 0;
    }
    else {
    }

    if (need_for_taxes == 1){                           //If the previous if else case was not necessary, then the adjusted gross income is determined via filing status.
        switch(filing_status){
            case 1:                                                                                 //Each if else path is used depending on the adjusted gross income to determine taxes owed.
                if ((adjusted_gross_income > 0) && (adjusted_gross_income <=9325)){
                    taxes_due = adjusted_gross_income * 0.1;
                }
                else if((adjusted_gross_income > 9325) && (adjusted_gross_income <= 37950)){
                    taxes_due = 932.50 + ((adjusted_gross_income - 9325) * 0.15);
                }
                else if((adjusted_gross_income > 37950) && (adjusted_gross_income <= 91900)){
                    taxes_due = 5226.25 + ((adjusted_gross_income - 37950) * 0.25);
                }
                else if((adjusted_gross_income > 91900) && (adjusted_gross_income <= 191650)){
                    taxes_due = 18713.75 + ((adjusted_gross_income - 91900) * 0.28);
                }
                else if((adjusted_gross_income > 191650) && (adjusted_gross_income <= 416700)){
                    taxes_due = 46643.75 + ((adjusted_gross_income - 191650) * 0.33);
                }
                else if(adjusted_gross_income > 416700){
                    taxes_due = 120910.25 + ((adjusted_gross_income - 416700) * 0.396);
                }
                break;
            case 2:
                if ((adjusted_gross_income > 0) && (adjusted_gross_income <=18650)){
                    taxes_due = adjusted_gross_income * 0.1;
                }
                else if((adjusted_gross_income > 18650) && (adjusted_gross_income <= 75900)){
                    taxes_due = 1865 + ((adjusted_gross_income - 18650) * 0.15);
                }
                else if((adjusted_gross_income > 75900) && (adjusted_gross_income <= 153100)){
                    taxes_due = 10452.5 + ((adjusted_gross_income - 75900) * 0.25);
                }
                else if((adjusted_gross_income > 153100) && (adjusted_gross_income <= 233350)){
                    taxes_due = 29752.5 + ((adjusted_gross_income - 153100) * 0.28);
                }
                else if((adjusted_gross_income > 233350) && (adjusted_gross_income <= 416700)){
                    taxes_due = 52222.5 + ((adjusted_gross_income - 233350) * 0.33);
                }
                else if(adjusted_gross_income > 416700){
                    taxes_due = 112728 + ((adjusted_gross_income - 470700) * 0.396);
                }
                break;
            default:
                break;
        }
    }
    
    cout << endl;
    cout << "Total Gross Adjusted Income for " << user_name << ": " << adjusted_gross_income << endl;               //Adjusted gross income is then output with their name
    
    if (taxes_due > tax_withheld){                                      //If there are more taxes due than the amount withheld, then the user owes taxes and that is determined and output.
        taxes_due = taxes_due - tax_withheld;
        cout << "You owe: $" << taxes_due << " in taxes" << endl;
    }
    else if (taxes_due <= tax_withheld){                                //If there are less taxes due than the amount withheld, then the user is entitled to a refund, which is determined and then output.
        taxes_due = tax_withheld - taxes_due;
        cout << "Your refund is: $" << taxes_due << endl;
    }
}