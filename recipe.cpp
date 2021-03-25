/*
#Over view#
    This is a container data structure to hold ingredients
    aswell as provide some extra functionality and recipe information.

#Additional notes#

#What needs to be done# (remove when complete)
    o testing
#Changelog#
    02/03/2021- added a few setters
    04/03/2021- added a shit load of implemented functions
*/

#include "recipe.hpp"

using namespace std;        // only using std objects so its fine

// constructors
recipe::recipe()
{

    recipeName = "Default name";
    instructions = "Place holder";

    ingredientNum = 0;
    servings = 0;

    recipeCost = 0.0;
}

recipe::recipe(QString name, QString instruc, int servs)
{
    recipeName = name;
    instructions = instruc;
    servings = servs;

    ingredientNum = 0;
    recipeCost = 0.0;
}

void recipe::replaceIngredient(ingredient ing1, int ingPos)
{
    ingredientList[ingPos] = ing1;
}

// General setters
void recipe::setRecipeName(QString name)
{
    recipeName = name;
}

void recipe::setInstructions(QString instruc)
{
    instructions = instruc;
}

//void recipe::setIngredientNum(int num) #not gonna use maybe

void recipe::setServings(int servs)
{
    if (servs <= 0)
    {
        servs = 1;
    }
    servings = servs;
}

//void recipe::setRecipeCost(float cost) #not gonna use maybe


// General Getters
QString recipe::getRecipeName()
{
    return recipeName;
}

QString recipe::getInstructions()
{
    return instructions;
}

int recipe::getIngredientNum()
{
    return ingredientNum;
}

int recipe::getServings()
{
    return servings;
}

float recipe::getRecipeCost()
{
    return recipeCost;
}

// Vector Manipulation
void recipe::addEmptyIngredient()
// creates an ingredient object with default values and stores it in ingredient list
{
    ingredientList.push_back(ingredient());
}

void recipe::addFullIngredient(QString n, QString unit, float usedamount, float packprice, float packamount)
{// creates an ingredient object with parameter values and stores it in ingredient list
    ingredientList.push_back(ingredient(n, unit, usedamount, packprice, packamount));
}

void recipe::removeIngredient(int IngredientPosition)
{
   ingredientList.erase(ingredientList.begin() + IngredientPosition);
}

void recipe::clearIngredients()
{
    ingredientList.clear();
}

// other utility functions
float recipe::getCalcRecipePrice()
{
    float total = 0;

    for (int i = 0; i < ingredientList.size(); i++)
    {
        total += ingredientList[i].getUnitPrice();
    }

    return total;
}


