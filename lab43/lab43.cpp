//created by: Nick LS
//created on: 11/5/17

/*following file simulates a shop with the included use of a class
with constructors, accessors, and mutators.*/

#include <iostream>
#include <string>
#include "lab43shopclass.cpp"
#include "lab43customerclass.cpp"
using namespace std;


int main(){
    
shop a;
cart b[10];

int input = 1;

while ((input > 0) && (input < 11)) {
    
    cout << "Here is the shop inventory: " << endl;
    
    a.PrintWares();     //outputs the shop's item ID #'s, Prices, and Inventory
    
    cout << endl << "(Input 1-10 to choose item, or anything else to go to checkout" << endl;
     
    cin >> input;       //takes in user's choice of item
    
    if ((input > 0) && (input < 11)) {          //if the user chose an item between 1 and 10
    
    b[0].AddToCustomerCartTotal(a.PurchaseItem(input));    //Adds the purchased item's price to the customer's cart total
    
    if (a.GetItemStock(input-1) > 0){
    b[0].AddToCustomerCartCount(input);                    //Adds the purchased item's count as well.
    }
    }
    
}

cout << "Customer Cart Total: $" << b[0].GetCustomerCartTotal() << endl;    //Outputs customer's total checkout price

cout << "Here is what you bought: " << endl;

b[0].PrintCart();           //Outputs how much of each item they bought

    return 0;
}