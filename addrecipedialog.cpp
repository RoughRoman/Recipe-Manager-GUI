#include "addrecipedialog.h"
#include "ui_addrecipedialog.h"

addRecipeDialog::addRecipeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addRecipeDialog)
{
    ui->setupUi(this);
}

void addRecipeDialog::on_recipeSubmitBtn_clicked()
{
    /* This function checks if recipe name has been input and displays an appropriate
     * message warning the user and not allowing the dialog to accept
     * if the mandatory values are filled in then it assigns the values to a stored object and
     * accepts and closes the dialog.*/

    bool validName = false;
    QString name = ui->recipeNameEdit->text();

    // input validation
    if (name == "" )
    {
       messageDialog messageD1;
       messageD1.setMessage("Recipe name not specified.", "Warning.");
       messageD1.exec();
       validName = false;
    }
    else
    {
        tempRecipe.setRecipeName(ui->recipeNameEdit->text());
        validName = true;
    }

    tempRecipe.setServings(ui->recipeServingsSpin->value());
    tempRecipe.setInstructions(ui->recipeInstrucEdit->toPlainText());

    if (validName == true)
    {
       accept();
    }


}
void addRecipeDialog::on_recipeCancelBtn_clicked()
{
    // this function rejects the dialog should the user click cancel
    reject();
}

void addRecipeDialog::on_addIngredBtn_clicked()
{
    /* This function creates an ingredient dialog for user input and checks if it was accepted.
     * if accepted the ingredient object is then fetched from the ingredient dialog and stored
     * in the recipe object held by this dialog. */


    addIngredientDialog ingredientDialog;

    if ( ingredientDialog.exec() == QDialog::Accepted)
    {
        // create ingredient and add to recipe ingredient vector
        ingredient ing = ingredientDialog.getIngredient();

        tempRecipe.ingredientList.push_back(ing); // vector

        ui->recipeIngredList->addItem(ing.getName()); // ingredient list
    }

}

void addRecipeDialog::on_deleteIngredBtn_clicked()
{
    // get position of selected item
    int pos = ui->recipeIngredList->currentRow();

    // delete from item list
    ui->recipeIngredList->takeItem(pos);

    // delete from ingredient vector
    tempRecipe.ingredientList.erase(tempRecipe.ingredientList.begin() + pos);

    return;
}
recipe addRecipeDialog::getRecipe()
{
    return tempRecipe;
}

void addRecipeDialog::setName(QString name)
{
   ui->recipeNameEdit->setText(name);
}

void addRecipeDialog::setInstructions(QString instruc)
{
    ui->recipeInstrucEdit->setText(instruc);
}

void addRecipeDialog::setServings(int servs)
{
    ui->recipeServingsSpin->setValue(servs);
}

void addRecipeDialog::setIngredients(vector<ingredient> ingredientVec)
{
    if (ingredientVec.size() == 0){
        return;
    }

    for (int i = 0 ; i < ingredientVec.size(); i++)
    {
        ui->recipeIngredList->addItem(ingredientVec[i].getName());
    }
}

addRecipeDialog::~addRecipeDialog()
{
    delete ui;
}
