// program to actually manage,contain and organize the recipe objects
// in the console.

// need to make a findRecipe function

#include "RecipeManager.hpp"

void pause()
    {// pause display and return
        string dummyinput = " ";
        cout<< "Press enter to return to the main menu."<<endl;
        getline(cin,dummyinput);
        return;
    }

int intInput(string message = "", int lowerBound = 0, int upperBound = 99)
{// basic integer input sanitizer
  string input;
  while (true)
  {
      cout<< message<<endl;
      cout<<"->";
      getline(cin, input);
      int num = stoi(input);

      if (  num < lowerBound || num > upperBound)
      {
          cout<< "Invalid Input";
          continue;
      }
      else
      {
         return num;
      }
  }
}

using namespace std;

RecipeManager::RecipeManager()
{

}
// display functions
void RecipeManager::displayRecipe(string recipeName)
{
    // check if recipeList is empty
    if (recipeList.empty())
    {
        return;
    }

    // find recipe
    int recipePosition = findRecipe(recipeName);




    //get recipe data
    string name = recipeList[recipePosition].getRecipeName();
    string instructions = recipeList[recipePosition].getInstructions();
    int ingredientNum = recipeList[recipePosition].getIngredientNum();
    int servings = recipeList[recipePosition].getServings();
    float cost = recipeList[recipePosition].getRecipeCost();

    // display recipe data
    cout<< "Recipe :"<< name<< endl;
    cout<< "Servings :"<< servings<<endl;
    cout<< "Instructions\n"<< instructions<< endl;
    cout<< ingredientNum<<" Ingredients"<< endl;

    for (int i = 0; i < recipeList[recipePosition].ingredientList.size(); i++)
    {
        cout<< recipeList[recipePosition].ingredientList[i];
    }
    cout<< "Cost to make :"<< cost<<"|  Cost per serving: "<<cost/servings<<endl;

    return;
}

// recipe functions
void RecipeManager::addRecipe(string recipeName, string instruc, int serves)
{
    recipeList.push_back(recipe(recipeName, instruc, serves));
}
bool RecipeManager::deleteRecipe(string recipeName)
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

// print to textfile
void RecipeManager::printToText(string recipeName)
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
    string name = recipeList[recipePosition].getRecipeName();
    string instructions = recipeList[recipePosition].getInstructions();
    int ingredientNum = recipeList[recipePosition].getIngredientNum();
    int servings = recipeList[recipePosition].getServings();
    float cost = recipeList[recipePosition].getRecipeCost();

    // create file named recipeName
    ofstream outfile;
    outfile.open(recipeName);

    // write data to file
    outfile<< "#########################################"<<endl;
    outfile<< name<<endl<< instructions<<endl<< ingredientNum<<endl<< servings<<endl<<cost;


    // file stream
    outfile.close();
}

// Save all recipes to dat file
void RecipeManager::saveToFile()
{
    ofstream outfile;
    outfile.open("recipeList.dat"); // if it was present then it would open.
                                    // if not it wil make one

    /*
       write to the file in the specified format.
       each recipe is on a new line so as soon as a \n is encountered we know its a new recipe
       each variable is prefixed by {
       so anything read from a { is a single variable.
       ingredient list is prefixed by a [
       ingredient data has the same { as the recipe data.
       finally we order the data recipe data first then ingredients as follows
       {recipename{instructions{servings[{ingredient1name{ingredient1cost etc{
    */

    for (int i; i < recipeList.size(); i++)
    {
        // print recipe data
        outfile<< recipeList[i].getRecipeName()<< "{";
        outfile<< recipeList[i].getInstructions()<< "{";
        outfile<<recipeList[i].getServings()<< "{";

        // start printing ingredients
        for (int j; j < recipeList[i].ingredientList.size(); j++)
        {// holy fuck. The guy who has to write the deserialization part is fucked

            outfile<< recipeList[i].ingredientList[j].getName()<< "{";
            outfile<< recipeList[i].ingredientList[j].getMeasurementUnit()<< "{";
            outfile<< recipeList[i].ingredientList[j].getUsedAmount()<< "{";
            outfile<< recipeList[i].ingredientList[j].getPackagePrice()<< "{";
            outfile<< recipeList[i].ingredientList[j].getPackageAmount()<< "{";

        }
        // finished printing ingredients
        outfile<< "\n"; // if we have issues maybe because endl flushes? idk if we need that
    }
    // done?
    outfile.close();
    return;
}

// Load from dat file
void RecipeManager::loadFromFile()
{
    /*
     * embarrasingly inflexible. God forbid anyone decides to change anything.
     * really needs a rework please anyone
     * shitload of comments because this was challenging to write
     *   needs clean up too.
     * it will also overwrite any current recipe list so best have something to prevent
     *   loading a file once anything is already in the list or atleast have a warning
     *   in the driver program
     */

    // for recipe data
    vector<string> recipeVec;
    vector<string> ingredVec;


    // for file processing
    string line;
    vector<string> lineVec;
    ifstream infile;

    infile.open("recipeList.dat"); // if it was present then it would open.
                                   // if not it will make one

    if (is_empty(infile)) // if true then file empty
    {
        return;
    }
    else
    {
        // get all of the lines from the file and store in local vector
        while((getline (infile, line)))
        {
            lineVec.push_back(line);
        }
        infile.close();

        // time to process each line into a recipe object
        for (int i; i < lineVec.size(); i++)
        {
            // get individual line
            line = lineVec[i];

            /*          How i am going to do this.
             * find the position of the first occurence of {
             * everything until next { we store
             * delete { and the data until next {
             * start again.
             * after first 3 runs create a recipe with the data
             * then repeat process for ingredients
             */

            for (int j; j < 3; j++)
            {
                // add the inbetween data to the vector
                recipeVec.push_back(line.substr(0,line.find('{')));

                // delete everything including delimiter
                line.erase(0, line.find('{') + 1);
            }
            // create recipe from vector data
            addRecipe(recipeVec[0], recipeVec[1], stoi(recipeVec[2]));

            // next ingredients
            while (line[0] != '\n')
            {
                // add the inbetween data to the vector
                ingredVec.push_back(line.substr(0, line.find('{')));

                //erase
                line.erase(0,line.find('{')+1);
            }

            // got all the ingredients now we add them as to the recipe we have just made
            for (int k; k < ingredVec.size(); k = k+5)
            {
                recipeList[i].addFullIngredient(ingredVec[k], ingredVec[k+1],
                                                stof(ingredVec[k+2]), stof(ingredVec[k+3]),
                                                stof(ingredVec[k+4]));
            }

        }
        return;
    }
}

// utilities
int RecipeManager::findRecipe(string name)
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
