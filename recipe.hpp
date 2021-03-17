// interface for recipe
#ifndef RECIPE_H
#define RECIPE_H


#include<iostream>
#include<string>
#include "ingredient.hpp"
#include<vector>
class recipe
{
private:
    string recipeName, instructions;
    int ingredientNum, servings;
    float recipeCost;
public:
    vector<ingredient> ingredientList;
     // Constructors
     recipe();
     recipe(string name, string instruc, int servs);

     // General setters
     void setRecipeName(string name);
     void setInstructions(string instruc);
     //void setIngredientNum(int num);  #maybe not uses
     void setServings(int servs);
     //void setRecipeCost(float cost);    #maybe not uses

     // General Getters
     string getRecipeName();
     string getInstructions();
     int getIngredientNum();
     int getServings();
     float getRecipeCost();

     // Vector Manipulation
     void addEmptyIngredient();
     void addFullIngredient(string n, string unit, float usedamount,
               float packprice = 0.0, float packamount = 0.0);

     void removeIngredient(int IngredientPosition);
     void clearIngredients();

     // other utility functions
     float getCalcRecipePrice();

};
#endif // RECIPE_H
