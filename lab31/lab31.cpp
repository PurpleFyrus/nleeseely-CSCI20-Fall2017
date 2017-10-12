//Created by: Nick LS
//Created on: 10/10/2017

/* The following algorithm is supposed to first take in a set of values in the form of a User's number of required phones, tablets and then data usage.
Next, the program will used predefined custom functions to perform calculations with those values stored in variables, to determine how much each of the six phone plans would cost.
Finally it goes through a loop and compares each one to each other to determine the cheapest of the plans, and then output the cheapest plan name and price.*/

#include <iostream>
#include <string>
using namespace std;

int CalculateATTUPPPrice(int phones, int tablets);                      //This function takes in 2 variables (phones and tablets) and charges $90 for the first line, an additional $55 for the second, $20 more for each additional phone and $10 for tablets. Also has a limit of 10 phones.
int CalculateATTUCPPrice(int phones, int tablets);                      //This function takes in 2 variables (phones and tablets) and charges $60 for the first line, an additional $55 for the second, $20 more for each additional phone and $10 for tablets. Also has a limit of 10 phones.
int CalculateATTFPPrice(int phones, int tablets, int data);             //This function takes in 3 variables (phones, tablets and data) and charges $20 per phone and $10 per tablet. And then goes in tiers of data usage from $30 to $110 for the plan. If the user uses more than 25GB of data they can't use this plan.
int CalculateVerizonUPrice(int phones, int tablets);                    //This function takes in 2 variables (phones and tablets) and charges $20 per phone and $10 per tablet. Also charges $80 for only one line and $110 if you have more than one line.
int CalculateSprintUPrice(int phones, int tablets);                     //This function takes in 2 variables (phone and tablets) and charges $60 for the first line, an additional $40 for a second line, and an additional $30 for each additional line after.
int CalculateSprint2GBPlan(int phones, int tablets, int data);          //This function takes in 3 variables (phones, tablets and data) and charges $40 per line and doesn't work for the user if they use more than 2GB of data.

int main() {
    
    int plan_price[6];      //0 is Att UPP, 1 is ATT UCP, 2 is ATT FP, 3 is Verizon U, 4 is Sprint U, 5 is Sprint 2GBP.
    string plan_name[6];    //The values in the array will be assigned later to correspond to the array above.
    int num_phones;         //User's number of phones is stored here.
    int num_tablets;        //User's number of tablets is stored here.
    int data_amount;        //User's amount of data used on average stored here.
    int final_plan_price = 0;       //Used to output final plan price later on.
    string final_plan_name;         //Used to output final plan name later on.
    
    cout << "Please enter number of phones: " << endl;
    cin >> num_phones;          //User inputs the number of phones they use.
    
    cout << "Please enter number of tablets: " << endl;
    cin >> num_tablets;         //User inputs the number of tablets they use.
    
    cout << "Please enter amount of data used on average: " << endl;
    cin >> data_amount;         //User inputs the amount of data they use.
    
    //Each plan's name is assigned to a different slot in the array for later use in the loop and output.
    plan_name[0] = "At&t Unlimited Plus Plan";
    plan_name[1] = "At&t Unlimited Choice Plan";
    plan_name[2] = "At&t Family Plan";
    plan_name[3] = "Verizon Unlimted Plan";
    plan_name[4] = "Sprint Unlimited Plan";
    plan_name[5] = "Sprint 2GB Plan";
    
    //Each plan's price is calculated and then stored here for later use in the loop and then output.
    plan_price[0] = CalculateATTUPPPrice(num_phones, num_tablets);
    plan_price[1] = CalculateATTUCPPrice(num_phones, num_tablets);
    plan_price[2] = CalculateATTFPPrice(num_phones, num_tablets, data_amount);
    plan_price[3] = CalculateVerizonUPrice(num_phones, num_tablets);
    plan_price[4] = CalculateSprintUPrice(num_phones, num_tablets);
    plan_price[5] = CalculateSprint2GBPlan(num_phones, num_tablets, data_amount);
    
    final_plan_price = plan_price[0];       //The variable here is assigned the value in the first memory location of the array plan_price for logic purposes in the loop coming up ahead.
    final_plan_name = plan_name[0];         //The same goes for the plan's name as well. 
    
    for (int i = 0; i < 6; i++){            //This loop iterates 6 times, once for each of the array plan_price's locations. (and also plan_name)
        if (plan_price[i] == 0){            //This is in case the value stored a plan's price is 0, it will not compare to the other value, since 0 is the cheapest possible, but also indicates an incompatability with the plan. 
            break;
        }
        else if(final_plan_price > plan_price[i]){      //Here is where each plan price is compared, and if the current stored value (which starts from the first location in the array)  
            final_plan_price = plan_price[i];           //is greater than the one it's being compared to, it'll assign the new value of the variable it's being compared too. 
            final_plan_name = plan_name[i];             //Along with the name of the plan as well that it corresponds to.
        }
        else{                                           //If the value stored in final_plan_price is smaller than plan_price[i] then it just will keep the value in final_plan_price instead.
                                                        //Same goes for the plan name.
        }
    }
    
    cout << endl;
    cout << "Cheapest plan price is the " << final_plan_name << " for: $" << final_plan_price << endl;      //Finally the cheapest plan price and name is output 

}










int CalculateATTUPPPrice(int phones, int tablets){ 
    int plan_price = 0;
    int num_lines = tablets + phones;       //Adding up the lines for easier use in comparison for first two price tiers.
    int num_tablets = tablets;
    
    if (num_lines == 1){                    //If one line is only being asked, the plan price is 90 bucks.
        plan_price = 90;
    }
    else if (num_lines == 2) {              //If two lines is only being asked, the plan price is 145 bucks.
        plan_price = 145;
    }
    else if ((num_lines > 2) && (phones <= 10)){        //If there are more than two lines but less than or equal to 10 phones, we get the 3rd scenario of the price plan.
        if (phones > 2){                                //If there are more than 2 phone lines,
            plan_price = 145 + ((phones - 2) * 20);     //Then the price plan is $145 plus an additional 20 dollars for each additional phone.
        }
        else{                                           //If there aren't more than 2 phones, but still more than 2 lines, those lines are probably tablets, so to avoid negative answers for phone prices, we save the tablets for last and set plan price to $145
            plan_price = 145;
        }
    }
    else if (phones > 10) {                             //This plan only supports up to 10 phones but unlimited tablets, so if there are more than 10 phones, it cancels further calculations and sets it all equal to 0, so it's skipped in the loop for comparison purposes.
        cout << "Too many phones for ATT Unlimited Plus Plan" << endl;
        plan_price = 0;
        num_tablets = 0;                                //We use a variable for tablets because we can't assign a value to an argument inside a custom function, unless it's pass by reference. Or maybe we can, but i don't know that lol.
    }
    else {                                              //In the off chance the user forgets to input anything this cout statement goes through
        cout << "Insufficient lines for ATT Unlimited Plus Plan" << endl;
    }
    
    plan_price = plan_price + (num_tablets * 10);       //The final price is then tacked on with tablet prices for 10 dollars a tablet. This equals 0 if it took the 4th if branch. 
    
    return plan_price;                                  //Plan price is then output
}

int CalculateATTUCPPrice(int phones, int tablets){
    int plan_price = 0;
    int num_lines = tablets + phones;                   //Lines are added up here.
    int num_tablets = tablets;
    
    if (num_lines == 1){                                //If there is only 1 line, the plan price is 60 bucks
        plan_price = 60;
    }
    else if (num_lines == 2){                           //If there are two lines, the plan price is 115 bucks
        plan_price = 115;
    }
    else if ((num_lines > 2) && (phones <= 10)){     //If there are more than 2 lines, but less than 10 it goes through as 115 bucks for the plan
        if (phones > 2){
            plan_price = 115 + ((phones - 2) * 20);     //and 20 dollars for each additional phone
        }
        else{                                           //but if there are only 1 or 2 phones the plan price is just 115, tablets are taken into account later
            plan_price = 115;
        }
    }
    else if (phones > 10) {                             //Too many phones? then you don't qualify for this plan bucko!
        cout << "Too many phones for ATT Unlimited Choice Plan" << endl;
        plan_price = 0;                         //Plan price is set to 0 so it's not used in the loop later on.
        num_tablets = 0;                        //Same as above, taking into account too many phones has to set tablets to 0 for final 0 value output. 
    }
    else {  //No phones? No tablets? No cigar
        cout << "Insufficient lines for ATT Unlimited Choice Plan" << endl;
    }
    
    plan_price = plan_price + (tablets * 10);           //Here is where tablets are added on, or nothing if the 4th branch was taken.
    
    return plan_price;  //Plan price is output
}

int CalculateATTFPPrice(int phones, int tablets, int data){
    int plan_price = 0;
    int num_lines = tablets + phones;               //Here are some variables for later manipulation
    int num_phones = phones;
    int num_tablets = tablets;
    
    if (data <= 1) {                                //Each branch just takes into account how much data is used, and chooses a plan price for the next 
        plan_price = 30;
    }
    else if ((data <= 3) && (data < 1)){
        plan_price = 40;
    }
    else if ((data <= 6) && (data > 3)){
        plan_price = 60;
    }
    else if ((data <= 10) && (data > 6)){
        plan_price = 80;
    }
    else if ((data <=16) && (data > 10)){
        plan_price = 90;
    }
    else if ((data <= 25) && (data > 16)){
        plan_price = 110;
    }
    else if (data > 25){                        //Too much data means ineligible, so values of the phones and tablets are set to 0 and plan price was already 0 so nothing is changed.
        cout << "Too much data usage to qualify for ATT Family Plan" << endl;
        num_phones = 0;
        num_tablets = 0;
    }
    else if (num_lines == 0){                   //No lines == no plan
        cout << "Insufficient lines for ATT Family Plan" << endl;
    }
    
    plan_price = plan_price + ((num_phones * 20) + (num_tablets * 10));         //Here the final plan price is determined by adding the phones and tablets individual values.
    //If plan price is 0, it doesn't get used in the loop for comparison
    return plan_price;                                                          //Finally plan_price value is output.
}

int CalculateVerizonUPrice(int phones, int tablets){    
    int plan_price = 0;
    int num_lines = tablets + phones;
    
    if (num_lines == 1){                //The plan price is 80 at first for just 1 line
        plan_price = 80;
    }
    else if (num_lines > 1){            //For any more lines, the plan price is 110
        plan_price = 110;
    }
    else {                              //No lines means no plan
        cout << "Insufficient number of lines for Verizon Unlimited Plan" << endl;
    }
    
    plan_price = plan_price + (phones * 20);            //Then the phones are taken into account
    plan_price = plan_price + (tablets * 10);           //Then the tablets are taken into account.
    
    return plan_price;          //final price is output
}

int CalculateSprintUPrice(int phones, int tablets){
    int plan_price = 0;
    int num_lines = tablets + phones;
    
    if (num_lines == 1){                                //Price of plan is 60 for one line
        plan_price = 60;
    }
    else if(num_lines == 2){                            //Price of plan is 100 for two lines
        plan_price = 100;
    }
    else if(num_lines > 2){                             //If more than 2 lines you just add 30 bucks for each extra line on top of the initial 100
        plan_price = 100 + (num_lines * 30);
    }
    else{   //no lines == no plan
        cout << "Insufficient number of lines for Sprint Unlimited Plan" << endl;
    }
    
    return plan_price;          //Final price is output
}

int CalculateSprint2GBPlan(int phones, int tablets, int data){
    int plan_price = 0;
    int num_lines = tablets + phones;
    
    if (data <= 2){                             //First the data is compared to see if it's equal to or less than 2, if so then it qualifies.
        plan_price = num_lines * 40;            //Then the plan price is just 40 dollars per line
    }
    else {                                      //However, if the data is more than 2, the plan price stays at 0 so the final output is 0 so it can't be used in the loop for comparison
        cout << "Too much data usage for Sprint 2GB Plan" << endl;
    }
    
    return plan_price;  //Final price is output.
}