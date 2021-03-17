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
    ;
}
void addRecipeDialog::on_recipeCancelBtn_clicked()
{
    reject();
}
void addRecipeDialog::on_addIngredBtn_clicked()
{
    ;
}
void addRecipeDialog::on_deleteIngredBtn_clicked()
{
    ;
}

addRecipeDialog::~addRecipeDialog()
{
    delete ui;
}
