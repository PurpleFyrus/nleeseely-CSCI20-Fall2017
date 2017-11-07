//created by: Nick LS
//created on: 11/5/17

/*following file is for the customer's cart which includs a class
with constructors, accessors, and mutators.*/

#include <iostream>
#include <string>
using namespace std;

class cart {
    private:
        int customer_cart[2][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};       //Used to store the customer's count of items purchased
        double cart_total;       //Used to store the customer's cart total
        
    public:
        cart();
        
        double GetItemNumber(int number_index);     //Returns customer's item number in index cart[0][number_index], probably wont be used, but is there just in case file is augmented later
        double GetItemCount(int count_index);       //Returns customer's count of the item in index cart[1][count_index]                 
        
        void SetItemNumber(int index, int number);  //Set's the ID # for the item stored in cart[0][index]
        void SetItemCount(int index, int count);    //Set's the item count for the corresponding item in cart[1][index]
        
        void AddToCustomerCartCount(int index);
        void AddToCustomerCartTotal(double added_amount);        //Adds the value added_amount to the variable cart_total
        double GetCustomerCartTotal();                          //Returns the value stored in cart_total

        void PrintCart();    
};

cart::cart(){
    cart_total = 0.0;
};

double cart::GetItemNumber(int number_index) {
    return customer_cart[0][number_index];
};     //Returns customer's item number in index cart[0][number_index], probably wont be used, but is there just in case file is augmented later
        
double cart::GetItemCount(int count_index) {
    return customer_cart[1][count_index];
};       //Returns customer's count of the item in index cart[1][count_index]                 
        
void cart::SetItemNumber(int index, int number) {
    customer_cart[0][index] = number;
};  //Set's the ID # for the item stored in cart[0][index]
    
void cart::SetItemCount(int index, int count) {
    customer_cart[1][index] = count;
};    //Set's the item count for the corresponding item in cart[1][index]

void cart::AddToCustomerCartCount(int index) {              //Changes the cart count of the corresponding item to what it was originally plus 1
    SetItemCount((index-1), (customer_cart[1][index-1] +1));
};
        
void cart::AddToCustomerCartTotal(double added_amount) {
    cart_total = cart_total + added_amount;
};        //Adds the value added_amount to the variable cart_total
        
double cart::GetCustomerCartTotal() {
    return cart_total;
};                          //Returns the value stored in cart_total

void cart::PrintCart(){         //This outputs all the id #'s and corresponding stock the customer bought
    cout << "ID #     Stock" << endl;
    cout << "______________" << endl;
    for (int i = 0; i < 10; i++) {
        cout << endl;
        for (int j = 0; j < 2; j++){
            cout << customer_cart[j][i] << "        ";
        }
    }
};