/*
    o This class should manage a list of recipes.
    o It should display a list of recipes by name.
    o It should display a more detailed view of an individual recipe
    o It should print a recipe to a textfile
    o It should load recipe/s from a .dat file
    o It should save recipe/s to a .dat file.
*/
#ifndef RECIPE_MANAGER_H
#define RECIPE_MANAGER_H


#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "recipe.hpp"


class RecipeManager
{
private:
    vector<recipe> recipeList;

public:
    RecipeManager();
    // display functions
    void displayRecipe(string recipeName);

    // recipe functions
    void addRecipe(string recipeName, string instruc, int serves);
    bool deleteRecipe(string recipeName);

    // print to textfile
    void printToText(string recipeName);

    // Save all recipes to dat file
    void saveToFile();

    // Load from dat file
    void loadFromFile();

    // utility functions
    int findRecipe(string name);
    bool is_empty(std::ifstream& pFile);

};
#endif

