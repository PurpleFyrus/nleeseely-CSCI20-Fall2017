#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
#include <iomanip>
using namespace std;

//it will have all the ingredients stored in it,
//but only the ingredients that have an amount of 1 or more will be displayed in the final result

class shopping_list{
    public:
        void add_to_list(string recipe_ingredient, int amount_recipe_ingredient);
        int GetListIngredientsNumber();
        string GetListIngredient(int ingredient);
        int GetListIngredientAmount(int ingredient);
        double GetListIngredientPrice(int ingredient);
        double GetTotalListPrice();
        
        void SetData(int num_ingredients, string name_ingredient[], double price_ingredient[]);
        
    private:
        int list_ingredients_number = 0;        //holds the amount of different ingredient types are on the shopping list
        //the following 3 arrays are parallel
        string list_ingredient[10];         //holds all the ingredients names in the list
        int list_ingredient_amount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};     //holds the amount of each ingredient stored for the shopping list
        double list_ingredient_price[10];   //holds all the prices for each ingredient in the list
        double total_list_price = 0.0;            //holds the total price of the ingredients in the shopping list

};

void shopping_list::add_to_list(string recipe_ingredient, int amount_recipe_ingredient){
                for (int j = 0; j < list_ingredients_number; j++){                              //iterates through all the ingredients in the list
                if(recipe_ingredient == list_ingredient[j]){                                //if the recipe ingredient is found in the ingredients list
                    list_ingredient_amount[j] = list_ingredient_amount[j] + amount_recipe_ingredient;                  //amount of each ingredient required for the recipe is added to the shopping list
                    total_list_price += (list_ingredient_price[j] * amount_recipe_ingredient); //amount each ingredient (times the amount they cost) is added to final shopping list price
                }
            }
        }

int shopping_list::GetListIngredientsNumber(){                  //returns the number of different types of ingredients in the list
    return list_ingredients_number;
}

string shopping_list::GetListIngredient(int ingredient){        //returns the name of the chosen ingredient from the list
    return list_ingredient[ingredient];
}

int shopping_list::GetListIngredientAmount(int ingredient){            //returns the amount of the chosen ingredient from the list
    return list_ingredient_amount[ingredient];
}

double shopping_list::GetListIngredientPrice(int ingredient){          //returns the price of the chosen ingredient from the list
    return list_ingredient_price[ingredient];
}

double shopping_list::GetTotalListPrice(){                             //returns the total list price
    return total_list_price;
}

void shopping_list::SetData(int num_ingredients, string name_ingredient[], double price_ingredient[]){
    list_ingredients_number = num_ingredients;
    for(int i = 0; i < num_ingredients; i++){
    list_ingredient[i] = name_ingredient[i];
    list_ingredient_price[i] = price_ingredient[i];
    }
}