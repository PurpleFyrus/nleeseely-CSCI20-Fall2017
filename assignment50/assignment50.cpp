#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
#include <iomanip>
#include "recipe.cpp"
#include "shoppinglist.cpp"
using namespace std;

int main(){
    
    string top_recipe_part[3];  
    string top_recipe_name;                 //the recipe's name is stored here
    int top_num_ingredients;                //variable to hold the number of different types of ingredients in the recipe  
    //the following two arrays are parallel
    int top_recipe_ingredient_amount[10];   //Holds the amount of each ingredient
    string top_recipe_ingredient_name[10];  //Holds the name of each ingredient
        
    int top_recipe_num_instructions;        //the number of instructions in a recipe is stored here
    string top_recipe_instructions[10];     //Holds the instructions for the recipe

//step 1
//this part is taking in the first recipe and storing it in the place holder variables declared in this main function

    ifstream fin;
    
    fin.open("recipe1.txt");
    
        getline(fin, top_recipe_part[0]);                       //We take in the first line which will execute a branch depending on if it is "recipe:", "ingredients", or "instructions"                    //If it is "recipe:"
            getline(fin, top_recipe_name);                      //The next line will be the recipe name which we store in "recipe_name"
        
        getline(fin, top_recipe_part[1]);
            fin >> top_num_ingredients;                         //It knows to take in the number of ingredients for the next proceeding lines
            for(int i = 0; i < top_num_ingredients; i++){       //Loop that iterates num_ingredients times, to take in each ingredient amount and ingredient name
                fin >> top_recipe_ingredient_amount[i];         //Stores each ingredient amount in recipe_ingredient_amount int array
                fin.ignore(1000, '\n');                     //Clear buffer between using fin and getline(fin, string)
                getline(fin, top_recipe_ingredient_name[i]);    //Stores each ingredient name in recipe_ingredient_name string array
            }
    
        getline(fin, top_recipe_part[2]);
            fin >> top_recipe_num_instructions;                        //It knows to take in the number of instructions with the next line's value                        //Clear buffer since we are swapping from cin to getline()
            fin.ignore(1000, '\n');                         //Clear buffer between using fin and getline(fin, string)
            for(int i=0; i<top_recipe_num_instructions; i++){          //Loop that iterates num_instructions times, to take in each instruction
                getline(fin, top_recipe_instructions[i]);       //Stores each instruction in the recipe_instruction string array
            }
        
    fin.close();

//step 2
//this part is taking in the master information from the ingredients.txt file

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

fin.close();

//this part is using the information from step 1 and storing it in the object created from class "recipe"

recipe recipe1;

recipe1.SetRecipeName(top_recipe_name);           //stores recipe parts in the object recipe1

recipe1.SetNumIngredients(top_num_ingredients);

recipe1.SetRecipeIngredientAmount(top_recipe_ingredient_amount);

recipe1.SetRecipePart(top_recipe_part);

recipe1.SetNumInstructions(top_recipe_num_instructions);

recipe1.SetRecipeInstructions(top_recipe_instructions);

recipe1.SetRecipeIngredientName(top_recipe_ingredient_name);


//this part is using the shoppinglist class to create a shopping list and output it into another file

shopping_list list1;

list1.SetData(master_num_ingredients, master_ingredient_name, master_ingredient_price);

/*string user_input;
while(user_input!="end"){
    cout << "what do you want?" << endl;
    cout << "1. " << recipe1.GetRecipeName << endl;
    cin >> user_input;
    
    if(user_input == 1){
        for(int j = 0; j < recipe1.GetNumIngredients(); j++){
            list1.add_to_list(recipe1.GetRecipeIngredientName(j), recipe1.GetRecipeIngredientAmount(j));
        }
    }
    else if(other branch)
    
}
/*for(int i = 0; i < total_number_of_chosen_recipes; i++) { */

for(int j = 0; j < recipe1.GetNumIngredients(); j++){
list1.add_to_list(recipe1.GetRecipeIngredientName(j), recipe1.GetRecipeIngredientAmount(j));
}

ofstream fout;

fout.open("shopping_list.txt");

fout << "Total Shopping List Price: " << list1.GetTotalListPrice() << endl;

fout << endl;

fout << "Ingredients Amount, Name, and Market Price for " << recipe1.GetRecipeName() << ": " << endl;
for(int i = 0; i < 4; i++){
    fout << list1.GetListIngredientAmount(i) << " " << list1.GetListIngredient(i) << " " << list1.GetListIngredientPrice(i) << endl;
}

fout << endl;

fout << "Happy Shopping!";

fout.close();

/* 1. next we need to use the recipe class to move all the data taken in from the recipe1.txt (stored in variables
    into an object under the name recipe1.
    2. then we can focus on creating a shopping list class that will use the data from the recipe class to
    create a list with:
    - total shopping list price
    - columns of ingredients and their prices and how many to get
    3. then we finally can focus on presenting the user with the recipe names, so they can choose what they want
    to plan on shopping for, and they can then "checkout" and proceed to creating the shopping list. 
*/

return 0;

}


//this following code is used to test the correct storing of all values from "top" variables into the recipe1 object
/*
cout << "Name: " << recipe1.GetRecipeName() << endl;

cout << "Amounts:" << endl;
cout << recipe1.GetRecipeIngredientAmount(0) << endl;
cout << recipe1.GetRecipeIngredientAmount(1) << endl;
cout << recipe1.GetRecipeIngredientAmount(2) << endl;
cout << recipe1.GetRecipeIngredientAmount(3) << endl;

cout << "Parts:" << endl;
cout << recipe1.GetRecipePart(0) << endl;
cout << recipe1.GetRecipePart(1) << endl;
cout << recipe1.GetRecipePart(2) << endl;

cout << "Num Ingredients: " << recipe1.GetNumIngredients() << endl;

cout << "Ingredient Names: " << endl;
cout << recipe1.GetRecipeIngredientName(0) << endl;
cout << recipe1.GetRecipeIngredientName(1) << endl;
cout << recipe1.GetRecipeIngredientName(2) << endl;
cout << recipe1.GetRecipeIngredientName(3) << endl;

cout << "Num Instrucstions: " << recipe1.GetRecipeNumInstructions() << endl;

cout << "Instructions: " << endl;
cout << recipe1.GetRecipeInstructions(0) << endl;
cout << recipe1.GetRecipeInstructions(1) << endl;
cout << recipe1.GetRecipeInstructions(2) << endl;
cout << recipe1.GetRecipeInstructions(3) << endl;
*/