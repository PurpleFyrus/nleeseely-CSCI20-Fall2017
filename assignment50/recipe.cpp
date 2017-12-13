#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
#include <iomanip>
using namespace std;

class recipe{
    public:
        
        string GetRecipePart(int part);
        string GetRecipeName();
        int GetNumIngredients();
        int GetRecipeIngredientAmount(int ingredient);
        string GetRecipeIngredientName(int ingredient);
        int GetRecipeNumInstructions();
        string GetRecipeInstructions(int instruction);
        
        void SetRecipePart(string part[]);
        void SetRecipeName(string name);
        void SetNumIngredients(int num);
        void SetRecipeIngredientAmount(int amount[]);
        void SetRecipeIngredientName(string name[]);
        void SetNumInstructions(int num);
        void SetRecipeInstructions(string instructions[]);
        
    private:
        string recipe_part[3];  
        string recipe_name;                 //the recipe's name is stored here
        int num_ingredients;                //variable to hold the number of different types of ingredients in the recipe  
        //the following two arrays are parallel
        int recipe_ingredient_amount[10];   //Holds the amount of each ingredient
        string recipe_ingredient_name[10];  //Holds the name of each ingredient

        int recipe_num_instructions;        //the number of instructions in a recipe is stored here
        string recipe_instructions[10];     //Holds the instructions for the recipe
    
};

void recipe::SetRecipePart(string part[]){
    for(int i = 0; i < 3; i++){
        recipe_part[i] = part[i];
    }
}

void recipe::SetRecipeName(string name){
    recipe_name = name;
}

void recipe::SetNumIngredients(int num){
    num_ingredients = num;
}

void recipe::SetRecipeIngredientAmount(int amount[]){
    for(int i = 0; i < num_ingredients; i++){
        recipe_ingredient_amount[i] = amount[i];
    }
}

void recipe::SetRecipeIngredientName(string name[]){
    for(int i = 0; i < num_ingredients; i++){
        recipe_ingredient_name[i] = name[i];
    }
}

void recipe::SetNumInstructions(int num){
    recipe_num_instructions = num;    
}

void recipe::SetRecipeInstructions(string instructions[]){
    for(int i = 0; i < recipe_num_instructions; i++){
        recipe_instructions[i] = instructions[i];
    }
}

string recipe::GetRecipePart(int part){
    return recipe_part[part];
}

string recipe::GetRecipeName(){
    return recipe_name;
}

int recipe::GetNumIngredients(){
    return num_ingredients;
}

int recipe::GetRecipeIngredientAmount(int ingredient){
    return recipe_ingredient_amount[ingredient];
}

string recipe::GetRecipeIngredientName(int ingredient){
    return recipe_ingredient_name[ingredient];
}

int recipe::GetRecipeNumInstructions(){
    return recipe_num_instructions;
}

string recipe::GetRecipeInstructions(int instruction){
    return recipe_instructions[instruction];
}

/*
int main(){

recipe recipe1;

string test_string[3];
test_string[0] = "recipe:";
test_string[1] = "ingredients:";
test_string[2] = "instructions:";

recipe1.SetRecipePart(test_string);

cout << recipe1.GetRecipePart(0);
cout << recipe1.GetRecipePart(1);
cout << recipe1.GetRecipePart(2);

return 0;
}
*/

/*cout << recipe_part[0] << recipe_part[1] << recipe_part[2] << endl;
cout << recipe_name << endl;

cout << "Ingredients: " << num_ingredients << endl;
cout << recipe_ingredient_amount[0] << " " << recipe_ingredient_name[0] << endl;
cout << recipe_ingredient_amount[1] << " " << recipe_ingredient_name[1] << endl;
cout << recipe_ingredient_amount[2] << " " << recipe_ingredient_name[2] << endl;
cout << recipe_ingredient_amount[3] << " " << recipe_ingredient_name[3] << endl;

cout << "Instructions: " << recipe_num_instructions << endl;
cout << recipe_instructions[0] << endl;
cout << recipe_instructions[1] << endl;
cout << recipe_instructions[2] << endl;
cout << recipe_instructions[3] << endl; */