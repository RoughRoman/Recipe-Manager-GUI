#include "addrecipedialog.hpp"
#include "ui_addrecipedialog.h"

addRecipeDialog::addRecipeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addRecipeDialog)
{
    ui->setupUi(this);
}

addRecipeDialog::~addRecipeDialog()
{
    delete ui;
}
