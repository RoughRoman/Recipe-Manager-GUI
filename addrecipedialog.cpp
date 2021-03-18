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
    tempRecipe.setRecipeName(ui->recipeNameEdit->text());
    tempRecipe.setInstructions(ui->recipeInstrucEdit->toPlainText());
    tempRecipe.setServings(ui->recipeServingsSpin->value());
    accept();

}
void addRecipeDialog::on_recipeCancelBtn_clicked()
{
    reject();
}

void addRecipeDialog::on_addIngredBtn_clicked()
{
    // launch ingredient dialog
    addIngredientDialog ingredientDialog;
    if ( ingredientDialog.exec() == QDialog::Accepted)
    {
        // create ingredient and add to recipe ingredient vector
        ingredient ing = ingredientDialog.getIngredient();
        tempRecipe.ingredientList.push_back(ing);
        ui->recipeIngredList->addItem(ing.getName());
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

addRecipeDialog::~addRecipeDialog()
{
    delete ui;
}
