#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
#include <iomanip>
#include "shoppinglist.cpp"
using namespace std;

//this file is just for testing ingredients stuff that will later be put in main assignment file

int main(){

ifstream fin;

int master_num_ingredients;
string master_ingredient_name[10];
double master_ingredient_price[10];

fin.open("ingredientprices.txt");

    fin >> master_num_ingredients;
    fin.ignore(1000, '\n');
    for (int i = 0; i < master_num_ingredients; i++){
        getline(fin, master_ingredient_name[i]);
        fin >> master_ingredient_price[i];
        fin.ignore(1000, '\n');
        }

fin.close();        //might have issue with first and last master ingredients and prices'

cout << master_ingredient_name[0] << endl;
cout << master_ingredient_price[0] << endl;
cout << master_ingredient_name[1] << endl;
cout << master_ingredient_price[1] << endl;
cout << master_ingredient_name[2] << endl;
cout << master_ingredient_price[2] << endl;
cout << master_ingredient_name[3] << endl;
cout << master_ingredient_price[3] << endl;

cout << endl;

shopping_list list1;

list1.SetData(master_num_ingredients, master_ingredient_name, master_ingredient_price);

list1.add_to_list(master_ingredient_name[0], 2);
list1.add_to_list(master_ingredient_name[1], 1);


cout << list1.GetListIngredientsNumber() << endl;
cout << list1.GetListIngredient(0) << endl;
cout << list1.GetListIngredientAmount(0) << endl;
cout << list1.GetListIngredientPrice(0) << endl;
cout << endl;
cout << list1.GetListIngredient(1) << endl;
cout << list1.GetListIngredientAmount(1) << endl;
cout << list1.GetListIngredientPrice(1) << endl;
cout << list1.GetTotalListPrice() << endl;

}