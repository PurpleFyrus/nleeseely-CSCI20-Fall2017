//Created by: Nick LS
//Created on: 10/10/2017

/* fill in about */

#include <iostream>
#include <string>
using namespace std;

int CalculateATTUPPPrice(int phones, int tablets);
int CalculateATTUCPPrice(int phones, int tablets);
int CalculateATTFPPrice(int phones, int tablets, int data);
int CalculateVerizonUPrice(int phones, int tablets);
int CalculateSprintUPrice(int phones, int tablets);
int CalculateSprint2GBPlan(int phones, int tablets, int data);

int main() {
    
    int plan_price[6];  //0 is Att UPP, 1 is ATT UCP, 2 is ATT FP, 3 is Verizon U, 4 is Sprint U, 5 is Sprint 2GBP
    string plan_name[6];    //The values in the array will be assigned later to correspond to the array above
    int num_phones;
    int num_tablets;
    int data_amount;
    int final_plan_price = 0;
    string final_plan_name;
    
    cout << "Please enter number of phones: " << endl;
    cin >> num_phones;
    
    cout << "Please enter number of tablets: " << endl;
    cin >> num_tablets;
    
    cout << "Please enter amount of data used on average: " << endl;
    cin >> data_amount;
    
    plan_name[0] = "At&t Unlimited Plus Plan";
    plan_name[1] = "At&t Unlimited Choice Plan";
    plan_name[2] = "At&t Family Plan";
    plan_name[3] = "Verizon Unlimted Plan";
    plan_name[4] = "Sprint Unlimited Plan";
    plan_name[5] = "Sprint 2GB Plan";
    
    plan_price[0] = CalculateATTUPPPrice(num_phones, num_tablets);
    plan_price[1] = CalculateATTUCPPrice(num_phones, num_tablets);
    plan_price[2] = CalculateATTFPPrice(num_phones, num_tablets, data_amount);
    plan_price[3] = CalculateVerizonUPrice(num_phones, num_tablets);
    plan_price[4] = CalculateSprintUPrice(num_phones, num_tablets);
    plan_price[5] = CalculateSprint2GBPlan(num_phones, num_tablets, data_amount);
    
    final_plan_price = plan_price[0];
    final_plan_name = plan_name[0];
    
    for (int i = 0; i < 6; i++){
        if (plan_price[i] == 0){
            break;
        }
        else if(final_plan_price > plan_price[i]){
            final_plan_price = plan_price[i];
            final_plan_name = plan_name[i];
        }
        else{
            
        }
    }
    
    cout << endl;
    cout << "Cheapest plan price is the " << final_plan_name << " for: $" << final_plan_price << endl;

}










int CalculateATTUPPPrice(int phones, int tablets){
    int plan_price = 0;
    int num_lines = tablets + phones;
    
    if (num_lines == 1){
        plan_price = 90;
    }
    else if (num_lines == 2) {
        plan_price = 145;
    }
    else if ((num_lines > 2) && (phones <= 10)){
        if (phones > 2){
            plan_price = 145 + ((phones - 2) * 20);
        }
        else{
            plan_price = 145;
        }
    }
    else if (phones > 10) { 
        cout << "Too many phones for ATT Unlimited Plus Plan" << endl;
    }
    else {
        cout << "Insufficient lines for ATT Unlimited Plus Plan" << endl;
    }
    
    plan_price = plan_price + (tablets * 10);
    
    return plan_price;
}

int CalculateATTUCPPrice(int phones, int tablets){
    int plan_price = 0;
    int num_lines = tablets + phones;
    
    if (num_lines == 1){
        plan_price = 60;
    }
    else if (num_lines == 2){
        plan_price = 115;
    }
    else if ((num_lines > 2) && (num_lines <= 10)){
        if (phones > 2){
            plan_price = 115 + ((phones - 2) * 20);
        }
        else{
            plan_price = 145;
        }
    }
    else if (phones > 10) { 
        cout << "Too many phones for ATT Unlimited Choice Plan" << endl;
    }
    else {
        cout << "Insufficient lines for ATT Unlimited Choice Plan" << endl;
    }
    
    plan_price = plan_price + (tablets * 10);
    
    return plan_price;
}

int CalculateATTFPPrice(int phones, int tablets, int data){
    int plan_price = 0;
    int num_lines = tablets + phones;
    
    if (data <= 1) {
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
    else if (data > 25){
        cout << "Too much data usage to qualify for ATT Family Plan" << endl;
    }
    else if (num_lines == 0){
        cout << "Insufficient lines for ATT Family Plan" << endl;
    }
    
    plan_price = plan_price + ((phones * 20) + (tablets * 10));
    
    return plan_price;
}

int CalculateVerizonUPrice(int phones, int tablets){
    int plan_price = 0;
    int num_lines = tablets + phones;
    
    if (num_lines == 1){
        plan_price = 80;
    }
    else if (num_lines > 1){
        plan_price = 110;
    }
    else {
        cout << "Insufficient number of lines for Verizon Unlimited Plan" << endl;
    }
    
    plan_price = plan_price + (phones * 20);
    plan_price = plan_price + (tablets * 10);
    
    return plan_price;
}

int CalculateSprintUPrice(int phones, int tablets){
    int plan_price = 0;
    int num_lines = tablets + phones;
    
    if (num_lines == 1){
        plan_price = 60;
    }
    else if(num_lines == 2){
        plan_price = 100;
    }
    else if(num_lines > 2){
        plan_price = 100 + (num_lines * 30);
    }
    else{
        cout << "Insufficient number of lines for Sprint Unlimited Plan" << endl;
    }
    
    return plan_price;
}

int CalculateSprint2GBPlan(int phones, int tablets, int data){
    int plan_price = 0;
    int num_lines = tablets + phones;
    
    if (data <= 2){
        plan_price = num_lines * 40;
    }
    else {
        cout << "Too much data usage for Sprint 2GB Plan" << endl;
    }
    
    return plan_price;
}