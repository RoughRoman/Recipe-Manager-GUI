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
#include <QString>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include "recipe.hpp"


class RecipeManager
{
private:


public:
    vector<recipe> recipeList;
    RecipeManager();

    // recipe functions
    void addRecipe(QString recipeName, QString instruc, int serves);
    void addRecipe(recipe tempRecipe);
    bool deleteRecipe(QString recipeName);
    void deleteRecipe(int recipePos);
    void replaceRecipe(recipe r1, int recipePos);
    void deleteAllRecipes();

    // print to textfile
    void printToText(QString recipeName);

    // Save all recipes to dat file
    void saveToFile();

    // Load from dat file
    void loadFromFile();

    // utility functions
    int findRecipe(QString name);
    bool is_empty(std::ifstream& pFile);

};
#endif

