/*                          WARNING WARNING
 * BIOHAZARD IN THE FILE I/O SECTIONS KEEPOUT MAJOR ISSUES FROM QSTRING USE.
 */
#include "RecipeManager.hpp"

using namespace std;

RecipeManager::RecipeManager()
{

}

// recipe functions
void RecipeManager::addRecipe(QString recipeName, QString instruc, int serves)
{
    recipeList.push_back(recipe(recipeName, instruc, serves));
}

void RecipeManager::addRecipe(recipe tempRecipe)
{
    recipeList.push_back(tempRecipe);
}
bool RecipeManager::deleteRecipe(QString recipeName)
{
    int recipeLocation = findRecipe(recipeName);

    if (recipeLocation == -1)
    {
        return false;
    }
    // delete from vector
    recipeList.erase(recipeList.begin() + recipeLocation);
    return true;    // successfully found and deleted recipe
}

void RecipeManager::deleteRecipe(int recipePos)
{
     recipeList.erase(recipeList.begin() + recipePos);
}

void RecipeManager::replaceRecipe(recipe r1, int recipePos)
{
    recipeList[recipePos] = r1;
}

void  RecipeManager::deleteAllRecipes()
{
    recipeList.clear();
}

// print to textfile
void RecipeManager::printToText(QString recipeName)
{
    // check if empty
    if (recipeList.empty())
    {
        return;
    }

    // find recipe
    int recipePosition = findRecipe(recipeName);

    if (recipePosition == -1)
    {
        return;
    }

    // get recipe data
    QString name = recipeList[recipePosition].getRecipeName();
    QString instructions = recipeList[recipePosition].getInstructions();
    int ingredientNum = recipeList[recipePosition].getIngredientNum();
    int servings = recipeList[recipePosition].getServings();
    float cost = recipeList[recipePosition].getRecipeCost();

    // create file named recipeName
    ofstream outfile;
    outfile.open(recipeName.toStdString()+".txt");

    // write data to file
    outfile<< "#########################################"<<endl;
    outfile<< name.toStdString()<<endl<< instructions.toStdString()<<endl<< ingredientNum<<endl<< servings<<endl<<cost;


    // file stream
    outfile.close();
}

// Save all recipes to dat file
void RecipeManager::saveToFile()
{
    QFile outfile("Recipe List.dat");
    if (outfile.open(QFile::WriteOnly))
    {
        QTextStream out(&outfile);
        for (int i = 0; i < recipeList.size(); i++)
        {
            out<< recipeList[i].getRecipeName()<< "{";

            // strip \n out of instructions
            QString instruct = recipeList[i].getInstructions();
            if (instruct.contains("\n")){
                instruct.remove("\n");
            }

            out<< instruct<< "{";
            out<< recipeList[i].getServings();

            out<< "[";
            for (int j = 0; j < recipeList[i].ingredientList.size(); j++)
            {
                out<< recipeList[i].ingredientList[j].getName()<< "{";
                out<< recipeList[i].ingredientList[j].getMeasurementUnit()<< "{";
                out<< recipeList[i].ingredientList[j].getUsedAmount()<< "{";
                out<< recipeList[i].ingredientList[j].getPackagePrice()<< "{";
                out<< recipeList[i].ingredientList[j].getPackageAmount()<< "{";
            }
            out<< "\n";
        }
        outfile.close();
        return;
    }

}

// Load from dat file
void RecipeManager::loadFromFile()
{
    QFile infile("Recipe List.dat");
    if (infile.open(QFile::ReadOnly | QIODevice::Text))
    {
      QTextStream in(&infile);
      while (!infile.atEnd())
      {
          // get a line and split it into recipe and ingredient data
          QString fullLine = infile.readLine();
          QStringList splitList = fullLine.split("[");
          QString recipeString = splitList[0];
          QString ingredientString = splitList[1];

          // strip \n
          ingredientString.remove("\n");

          // futher split each into individual variables
          QStringList recipeData = recipeString.split("{");
          QStringList ingredientData = ingredientString.split("{",Qt::SkipEmptyParts);

          // create objects
          recipe tempRecipe;
          tempRecipe.setRecipeName(recipeData[0]);
          tempRecipe.setInstructions(recipeData[1]);
          tempRecipe.setServings(recipeData[2].toInt());

          for (int i = 0; i < ingredientData.size(); i= i+5)
          {
              ingredient tempIngredient;
              tempIngredient.setName(ingredientData[i]);
              tempIngredient.setMeasurmentUnit(ingredientData[i+1]);
              tempIngredient.setUsedAmount(ingredientData[i+2].toFloat());
              tempIngredient.setPackagePrice(ingredientData[i+3].toFloat());
              tempIngredient.setPackageAmount(ingredientData[i+4].toFloat());

              tempRecipe.ingredientList.push_back(tempIngredient);

          }

          // store objects
          recipeList.push_back(tempRecipe);
      }
    }
}

// utilities
int RecipeManager::findRecipe(QString name)
{
    // find recipe by name
    for (int i = 0; i < recipeList.size(); i++)
    {
        if ( recipeList[i].getRecipeName() == name)
        {// found now return index
            return i;
        }
    }
    return -1;   // couldn't find the recipe return -1
}

bool RecipeManager::is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}
