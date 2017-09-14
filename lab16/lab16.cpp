//created by: nick ls

//the following algorithm is intended to simulate a stock portfolio in the form
//of a struct holding said relavent data and then outputting it accordingly

#include <iostream>
#include <string>
using namespace std;

struct stockPortfolio{
            string stock_name;              //storing stock's name here
            char stock_sector;              //used for sorting purposes
            double current_share_price = 0.0;       //placeholder for stock's share price, will be entered later
            double num_shares_owned = 0.0;          //placeholder for stock's # of shares owned, enter later
            double calculate_total_stock_value(double current_share_price, double num_shares_owned);
};                  //the line above is a declaration of a function designed to determine total stock
            //value based on current share price and number of shares owned

double stockPortfolio::calculate_total_stock_value(double current_share_price, double num_shares_owned){
    return (current_share_price * num_shares_owned);    //the actual definition of the function is here
}

int main(){
    
    stockPortfolio stock1;      //first object declared, only one that is actually used
    stockPortfolio stock2;
    stockPortfolio stock3;
    stockPortfolio stock4;
    stockPortfolio stock5;
    stockPortfolio stock6;
    
    cout << "Please enter the first stock's name: " << endl;
    cin >> stock1.stock_name;
    
    cout << "Please enter the first stock's sector: " << endl;
    cin >> stock1.stock_sector;
    
    cout << "Please enter the first stock's current share price: " << endl;
    cin >> stock1.current_share_price;
    
    cout << "Please enter the number of shares owned of the first stock: " << endl;
    cin >> stock1.num_shares_owned;
    
    //the following lines just output the data collected into a nice orderly fashion.
    
    cout << "Stock Name    No of Shares    Current Value    Total Value" << endl;
    cout << "----------    ------------    -------------    -----------" << endl;
    cout << stock1.stock_name << "          " << stock1.num_shares_owned << "               ";
    cout << stock1.current_share_price << "             ";
    cout << stock1.calculate_total_stock_value(stock1.current_share_price, stock1.num_shares_owned) << endl;
    cout << "Total Portfolio: $" << stock1.calculate_total_stock_value(stock1.current_share_price, stock1.num_shares_owned) << endl;
    
    return 0;
    
}