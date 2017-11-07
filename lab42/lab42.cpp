//Created By: Nick LS
//Created on: 11/5/17

/*The following is simulating a shop with inventory and prices, along with a customer
choosing what they want and what it will cost in the end. Also can't let inventory of the
shop fall below 0 obviously*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    
    int item_being_purchased = 1;                                         //Used for user input on what they are purchasing.
    double cart_total = 0;                                       //Keeps track of customer's cart total.
    
    int customer_cart[2][10] = {                              //Customer's cart info is stored here.
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},                                            //item ID numbers
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}                                              //item tally
    };
    
    double item_price_inventory[3][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},                                            //item ID numbers
        {1.35, 1.75, 2.45, 6.45, 1.75, 1.75, 3.55, 4.75, 5.25, 5.25},               //item prices 
        {4, 3, 2, 3, 5, 6, 3, 5, 9, 4}                                              //item inventory
    };
    
        while ((item_being_purchased >= 1) && (item_being_purchased <= 10)) {                     //keeps looping, letting the customer add more items to the cart, until they input a number not corresponding to an inventory item
    
        for (int i = 0; i < 10; i++) {                                                      //this is the wares being shown to the customer
            cout << "Item ID #: " << item_price_inventory[0][i] << " and Price: $" << item_price_inventory[1][i] << endl;
        }
        cout << endl;
        cout << "What would you like to buy?" << endl;
        cout << "Choose from item ID numbers 1-10 OR type any other integer to Proceed to checkout" << endl;
        
        cin >> item_being_purchased;                          //customer inputting what item they wish to purchase
        
            switch (item_being_purchased) {                   //this then adds that item the customer chose to their cart if it is in stock, adds the price to the customer total, and subtracts from the store's corresponding item stock
                case 1:                                                 //in the case customer chooses Item 1
                    if (item_price_inventory[2][0] <= 0) {                         //if the item is out of stock
                        cout << "This item is out of stock" << endl;    //it will say it's out of stock
                    }
                    else {                                              //if the item is in stock
                        item_price_inventory[2][0] = (item_price_inventory[2][0] - 1);        //it will deduct 1 from the stock first
                        cart_total = cart_total + item_price_inventory[1][0]; //then it will add the item's price to customer's total cart balance
                        customer_cart[1][0] = customer_cart[1][0] + 1;
                    }
                    break;
                case 2:                                                 //in the case customer chooses Item 1
                    if (item_price_inventory[2][1] <= 0) {                         //if the item is out of stock
                        cout << "This item is out of stock" << endl;    //it will say it's out of stock
                    }
                    else {                                              //if the item is in stock
                        item_price_inventory[2][1] = (item_price_inventory[2][1] - 1);        //it will deduct 1 from the stock first
                        cart_total = cart_total + item_price_inventory[1][1]; //then it will add the item's price to customer's total cart balance
                        customer_cart[1][1] = customer_cart[1][1] + 1;
                    }
                    break;
                case 3:                                                 //in the case customer chooses Item 1
                    if (item_price_inventory[2][2] <= 0) {                         //if the item is out of stock
                        cout << "This item is out of stock" << endl;    //it will say it's out of stock
                    }
                    else {                                              //if the item is in stock
                        item_price_inventory[2][2] = (item_price_inventory[2][2] - 1);        //it will deduct 1 from the stock first
                        cart_total = cart_total + item_price_inventory[1][2]; //then it will add the item's price to customer's total cart balance
                        customer_cart[1][2] = customer_cart[1][2] + 1;
                    }
                    break;
                case 4:                                                 //in the case customer chooses Item 1
                    if (item_price_inventory[2][3] <= 0) {                         //if the item is out of stock
                        cout << "This item is out of stock" << endl;    //it will say it's out of stock
                    }
                    else {                                              //if the item is in stock
                        item_price_inventory[2][3] = (item_price_inventory[2][3] - 1);        //it will deduct 1 from the stock first
                        cart_total = cart_total + item_price_inventory[1][3]; //then it will add the item's price to customer's total cart balance
                        customer_cart[1][3] = customer_cart[1][3] + 1;
                    }
                    break;
                case 5:                                                 //in the case customer chooses Item 1
                    if (item_price_inventory[2][4] <= 0) {                         //if the item is out of stock
                        cout << "This item is out of stock" << endl;    //it will say it's out of stock
                    }
                    else {                                              //if the item is in stock
                        item_price_inventory[2][4] = (item_price_inventory[2][4] - 1);        //it will deduct 1 from the stock first
                        cart_total = cart_total + item_price_inventory[1][4]; //then it will add the item's price to customer's total cart balance
                        customer_cart[1][4] = customer_cart[1][4] + 1;
                    }
                    break;
                case 6:                                                 //in the case customer chooses Item 1
                    if (item_price_inventory[2][5] <= 0) {                         //if the item is out of stock
                        cout << "This item is out of stock" << endl;    //it will say it's out of stock
                    }
                    else {                                              //if the item is in stock
                        item_price_inventory[2][5] = (item_price_inventory[2][5] - 1);        //it will deduct 1 from the stock first
                        cart_total = cart_total + item_price_inventory[1][5]; //then it will add the item's price to customer's total cart balance
                        customer_cart[1][5] = customer_cart[1][5] + 1;
                    }
                    break;
                case 7:                                                 //in the case customer chooses Item 1
                    if (item_price_inventory[2][6] <= 0) {                         //if the item is out of stock
                        cout << "This item is out of stock" << endl;    //it will say it's out of stock
                    }
                    else {                                              //if the item is in stock
                        item_price_inventory[2][6] = (item_price_inventory[2][6] - 1);        //it will deduct 1 from the stock first
                        cart_total = cart_total + item_price_inventory[1][6]; //then it will add the item's price to customer's total cart balance
                        customer_cart[1][6] = customer_cart[1][6] + 1;
                    }
                    break;
                case 8:                                                 //in the case customer chooses Item 1
                    if (item_price_inventory[2][7] <= 0) {                         //if the item is out of stock
                        cout << "This item is out of stock" << endl;    //it will say it's out of stock
                    }
                    else {                                              //if the item is in stock
                        item_price_inventory[2][7] = (item_price_inventory[2][7] - 1);        //it will deduct 1 from the stock first
                        cart_total = cart_total + item_price_inventory[1][7]; //then it will add the item's price to customer's total cart balance
                        customer_cart[1][7] = customer_cart[1][7] + 1;
                    }
                    break;
                case 9:                                                 //in the case customer chooses Item 1
                    if (item_price_inventory[2][8] <= 0) {                         //if the item is out of stock
                        cout << "This item is out of stock" << endl;    //it will say it's out of stock
                    }
                    else {                                              //if the item is in stock
                        item_price_inventory[2][8] = (item_price_inventory[2][8] - 1);        //it will deduct 1 from the stock first
                        cart_total = cart_total + item_price_inventory[1][8]; //then it will add the item's price to customer's total cart balance
                        customer_cart[1][8] = customer_cart[1][8] + 1;
                    }
                    break;
                case 10:                                                 //in the case customer chooses Item 1
                    if (item_price_inventory[2][9] <= 0) {                         //if the item is out of stock
                        cout << "This item is out of stock" << endl;    //it will say it's out of stock
                    }
                    else {                                              //if the item is in stock
                        item_price_inventory[2][9] = (item_price_inventory[2][9] - 1);        //it will deduct 1 from the stock first
                        cart_total = cart_total + item_price_inventory[1][9]; //then it will add the item's price to customer's total cart balance
                        customer_cart[1][9] = customer_cart[1][9] + 1;
                    }
                    break;
                default:
                    cout << "You will now be sent to checkout" << endl;         //in the event the customer chooses a number other than 1-10 they will be sent to checkout
                    break;
            }
    
    }
    
        cout << "Contents of Cart: " << endl;
    for (int i = 0; i < 10; i++) {
         cout << "Item Count: " << customer_cart[1][i] << " of Item ID #: " << customer_cart[0][i] << endl;           //this then goes through the customer's cart and shows how much of each item they bought from all the wares
    }
    
    cout << "Total Price: $" << cart_total << endl;                     //this is the final balance in how much the customer needs to pay to get their items
    return 0;
    
    return 0;
}