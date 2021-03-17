#include "addingredientdialog.h"
#include "ui_addingredientdialog.h"

addIngredientDialog::addIngredientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addIngredientDialog)
{
    ui->setupUi(this);
}

addIngredientDialog::~addIngredientDialog()
{
    delete ui;
}
