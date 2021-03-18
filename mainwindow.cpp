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

void MainWindow::on_recipeListWgt_currentRowChanged()
{
    // get index of row of currently selected row
    int pos = ui->recipeListWgt->currentRow();

    // display recipe details
    ui->nameLabel->setText(ReciperManager1.recipeList[pos].getRecipeName());
    ui->instructionsText->setText(ReciperManager1.recipeList[pos].getInstructions());

    // cost display
    float cost = ReciperManager1.recipeList[pos].getCalcRecipePrice(); // get calculated price
    QString str = QString::number(cost, 'g', 2); // convert to qstring with 2 decimal places
    ui->costLabel->setText(str);


    ui->servingsLabel->setText( QString::number( ReciperManager1.recipeList[pos].getServings()));
    ui->ingredientNumLabel->setText( QString::number( ReciperManager1.recipeList[pos].ingredientList.size()));

    int costper = cost/ReciperManager1.recipeList[pos].getServings();
    ui->costPerServingLabel->setText(QString::number(costper));

    for (int i; i < ReciperManager1.recipeList[pos].ingredientList.size(); i++)
    {
        ui->ingredientListWgt->addItem(ReciperManager1.recipeList[pos].ingredientList[i].getName());
    }




}

void MainWindow::on_loadRecipeAction_clicked()
{
    ReciperManager1.loadFromFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

