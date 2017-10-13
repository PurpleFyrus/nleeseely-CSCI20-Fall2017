//Created by: Nick LS
//Created on: 10/12/17

/*Following program takes into account user's marriage status, then determines a personal exemption.
Next it determines whether to take into account taxes and if so follows to two routes depending on marital status.
Finally the final tax amount calculated is compared to income withheld and does the final check if taxes are due.*/

#include <iostream>
#include <iostream>
using namespace std;

int main(){
    string user_name;
    int filing_status = 0;
    double gross_wages = 0.0;
    double adjusted_gross_wages = 0.0;
    double tax_withheld = 0.0;
    int need_for_taxes = 1;
    
    cout << "Please enter your name: ";
    getline(cin, username);
    
    cin.ignore(1000, '\n');
    
    cout << "Please enter your Filing Status, 1 for single and 2 for married: ";
    cin >> filing_status;
    
    cout << "Please enter your Gross Wages: ";
    cin >> gross_wages;
    
    cout << "Please enter amount of tax withheld: ";
    cin >> tax_withheld;
    
    gross_wages = gross_wages - 4050;           //first part of adjusted gross income
    
    switch(gross_wages){                        //second part of determining gross income
        case 1:
            gross_wages = gross_wages - 6350;   //This branch is taken if the user is filing as single
            break;
        case 2:
            gross_wages = gross_wages - 12700;  //This branch is taken if the user is filing as married
            break;
        default:
            cout << "Issue with filing status" << endl;
            break;
    }
    
    if (gross_wages <= 0){                      //This if else is used to determine if the user needs to have their taxes calculated depending on what the outcome is after the deductions from above.
        cout << "No need to calculate taxes, no taxes are due." << endl;
        need_for_taxes = 0;
    }
    else {
    }
    
    
    if (need_for_taxes == 1){
        switch(filing_status){
            case 1:
                if ((gross_wages >= 0) && (gross_wages <=9325)){
                    adjusted_gross_wages = gross * 0.1;
                }
                else if((gross_wages > 9325) && (gross_wages <= 37950)){
                    adjusted_gross_wages = 932.50 + ((gross_wages - 9325) * 0.15);
                }
                else if((gross_wages > 37950) && (gross_wages <= 91900)){
                    adjusted_gross_wages = 5226.25 + ((gross_wages - 37950) * 0.25);
                }
                else if((gross_wages > 91900) && (gross_wages <= )){
                    adjusted_gross_wages =  + ((gross_wages - ) * );
                }
                else if((gross_wages > ) && (gross_wages <= )){
                    adjusted_gross_wages =  + ((gross_wages - ) * );
                }
                else if((gross_wages > ) && (gross_wages <= )){
                    adjusted_gross_wages =  + ((gross_wages - ) * );
                }
                break;
            case 2:
            
                break;
            default:
                break;
        }
    }
}