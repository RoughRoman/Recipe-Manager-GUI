#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


void MainWindow::on_addRecipeBtn_clicked()
{
    addRecipeDialog recipeDialog;

    if ( recipeDialog.exec() == QDialog::Accepted)
    {
        recipe r1 = recipeDialog.getRecipe();
        ReciperManager1.addRecipe(r1);
        ui->recipeListWgt->addItem(r1.getRecipeName());
    }
}

void MainWindow::on_recipeListWgt_itemClicked()
{
    /* This function should manage what recipe is shown on the main window.
     * If there is nothing selected or if the list is empty it will show default values.
     * If will also make sure troublesome values display correctly. E.g. cost calulation issues. */

    if (ReciperManager1.recipeList.size() == 0)
    {
        ui->nameLabel->setText(" ");
        ui->instructionsText->setText(" ");
        ui->costLabel->setText(" ");
        ui->servingsLabel->setText(" ");
        ui->ingredientNumLabel->setText(" ");
        ui->costPerServingLabel->setText(" ");
        ui->ingredientListWgt->clear();
        return;
    }
    else
    {
        // get index of row of currently selected row
        int pos = ui->recipeListWgt->currentRow();

        // display recipe details
        ui->nameLabel->setText(ReciperManager1.recipeList[pos].getRecipeName());
        ui->instructionsText->setText(ReciperManager1.recipeList[pos].getInstructions());

        // cost display
        double cost = ReciperManager1.recipeList[pos].getCalcRecipePrice(); // get calculated price
        QString str = QString::number(cost,'g',3); // convert to qstring with 2 decimal places
        ui->costLabel->setText(str);


        ui->servingsLabel->setText( QString::number( ReciperManager1.recipeList[pos].getServings()));
        ui->ingredientNumLabel->setText( QString::number( ReciperManager1.recipeList[pos].ingredientList.size()));

        double costper = 0.0;
        if (cost == 0.0){
            costper = 0.0;
        }
        else{
            costper = cost/ReciperManager1.recipeList[pos].getServings();
        }

        ui->costPerServingLabel->setText(QString::number(costper,'g',3));

        ui->ingredientListWgt->clear();
        for (int i = 0; i < ReciperManager1.recipeList[pos].ingredientList.size(); i++)
        {
            ui->ingredientListWgt->addItem(ReciperManager1.recipeList[pos].ingredientList[i].getName());
        }
        return;
    }
}

void MainWindow::on_deleteRecipeBtn_clicked()
{
    // delete from widget
    ReciperManager1.deleteRecipe(ui->recipeListWgt->currentRow());
    ui->recipeListWgt->takeItem(ui->recipeListWgt->currentRow());
}

void MainWindow::on_editRecipeBtn_clicked()
{
    // get the position of the selected recipe
    int recipePos = ui->recipeListWgt->currentRow();

    // create addrecipe dialog
    addRecipeDialog recipeDialog;

    // load current recipe details into dialog
    recipeDialog.setName(ReciperManager1.recipeList[recipePos].getRecipeName());
    recipeDialog.setInstructions(ReciperManager1.recipeList[recipePos].getInstructions());
    recipeDialog.setServings(ReciperManager1.recipeList[recipePos].getServings());
    recipeDialog.setIngredients(ReciperManager1.recipeList[recipePos].ingredientList);

    // on accept signal replace old data with new
    if ( recipeDialog.exec() == QDialog::Accepted)
    {
        recipe r1 = recipeDialog.getRecipe();
        ReciperManager1.replaceRecipe(r1, recipePos);

        on_deleteRecipeBtn_clicked();

        // update display
        ui->recipeListWgt->addItem(r1.getRecipeName());
    }
}

void MainWindow::on_loadRecipeAction_triggered()
{
   ReciperManager1.loadFromFile();
}

void MainWindow::on_saveRecipeListAction_triggered()
{
    ReciperManager1.saveToFile();
}

void MainWindow::on_exitAction_triggered()
{
    QApplication::quit();
}

void MainWindow::on_deleteRecipeListAction_triggered()
{
    // warn user
    choiceDialog choiceD1;
    choiceD1.setMessage("You are about to delete all recipes. This is permanent and can not be undone.");

    // check user selection
    if (choiceD1.exec() == QDialog::Accepted)
    {
        ReciperManager1.deleteAllRecipes();
        ui->recipeListWgt->clear();
    }
    else
    {
        return;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}




