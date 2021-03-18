// interface for recipe
#ifndef RECIPE_H
#define RECIPE_H


#include<iostream>
#include<QString>
#include "ingredient.hpp"
#include<vector>
class recipe
{
private:
    QString recipeName, instructions;
    int ingredientNum, servings;
    float recipeCost;
public:
    vector<ingredient> ingredientList;
     // Constructors
     recipe();
     recipe(QString name, QString instruc, int servs);

     // General setters
     void setRecipeName(QString name);
     void setInstructions(QString instruc);
     //void setIngredientNum(int num);  #maybe not uses
     void setServings(int servs);
     //void setRecipeCost(float cost);    #maybe not uses

     // General Getters
     QString getRecipeName();
     QString getInstructions();
     int getIngredientNum();
     int getServings();
     float getRecipeCost();

     // Vector Manipulation
     void addEmptyIngredient();
     void addFullIngredient(QString n, QString unit, float usedamount,
               float packprice = 0.0, float packamount = 0.0);

     void removeIngredient(int IngredientPosition);
     void clearIngredients();

     // other utility functions
     float getCalcRecipePrice();

};
#endif // RECIPE_H
