//created by: Nick LS
//created on: 11/5/17

/*following file is the class declaration and definition for the class shop.
It has the options of returning values from 30 indexes, setting new values in those indexes,
printing those values, and simulating a purchase from the store as well.*/

#include <iostream>
#include <string>
using namespace std;

class shop {
    private:
        double shop_wares[3][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},{1.25, 1.75, 2.45, 6.45, 1.75, 2.75, 3.50, 4.75, 5.75, 5.25},{0, 5, 2, 3, 5, 4, 3, 5, 6, 4}};
        //All the shop's wares are stored in this multi array above, and can be changed here or later on with functions
        int num_rows = 3;   //This corresponds to the value j in shop_wares[j][10] at the array's declaration. How many attributes there are of the items in the shop (or rows)
        int num_cols = 10;   //This corresponds to the value i in shop_wares[3][i] at the array's declaration. How many items types there are in the shop (or columns)
    public:
        double GetItemNumber(int number_index);   //Used to get the ID # of the item stored in shop_wares[0][number_index]
        double GetItemPrice(int price_index);     //Used to get the price which is stored in shop_wares[1][price_index]
        double GetItemStock(int stock_index);     //Used to get the amount of stock of an item which is stored in shop_wares[2][stock_index]
        
        void SetItemNumber(int index, double number);      //Used to augment the value stored in shop_wares[0][number]
        void SetItemPrice(int index, double price);        //Used to augment the value stored in shop_wares[1][price]
        void SetItemStock(int index, double stock);        //Used to augment the value stored in shop_wares[2][stock]
        
        void PrintWares();      //Used to print all the wares of the shop including corresponding ID numbers, Price and Stock
        double PurchaseItem(int item_index);    //Used to purchase an item and make sufficient changes to the shop's inventory.   It subtracts 1 from shop_wares[2][item_index] and returns the corresponding price shop_wares[1][item_number]
};

double shop::GetItemNumber(int number_index) {
    return shop_wares[0][number_index];
};   //Used to get the ID # of the item stored in shop_wares[0][number_index]

double shop::GetItemPrice(int price_index) {
    return shop_wares[1][price_index];
};     //Used to get the price which is stored in shop_wares[1][price_index]
        
double shop::GetItemStock(int stock_index) {
    return shop_wares[2][stock_index];
};     //Used to get the amount of stock of an item which is stored in shop_wares[2][stock_index]
        
void shop::SetItemNumber(int index, double number) {
    shop_wares[0][index] = number;
};      //Used to augment the value stored in shop_wares[0][index]
        
void shop::SetItemPrice(int index, double price) {
    shop_wares[1][index] = price;
};        //Used to augment the value stored in shop_wares[1][index]

void shop::SetItemStock(int index, double stock) {
    shop_wares[2][index] = stock;
};        //Used to augment the value stored in shop_wares[2][index]
        
void shop::PrintWares() {
    cout << "ID #     Price     Stock" << endl;
    cout << "________________________" << endl;
    for (int i = 0; i < num_cols; i++){
        cout << endl;
        for (int  j= 0; j < num_rows; j++){
            cout << shop_wares[j][i] << "        ";
        }
    }
};      //Used to print all the wares of the shop including corresponding ID numbers, Price and Stock
        
double shop::PurchaseItem(int item_index) {     //User inputs item ID
    if (shop_wares[2][item_index-1] > 0){     //If there is any of the item in stock
    shop_wares[2][item_index-1] = shop_wares[2][item_index-1] - 1;          // It Subtracts 1 from inventory
    return shop_wares[1][item_index-1];
    }
    else{
        cout << "Out of stock of that item" << endl;
    return 0.0;
    }
};