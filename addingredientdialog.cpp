#include "addingredientdialog.h"
#include "ui_addingredientdialog.h"

addIngredientDialog::addIngredientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addIngredientDialog)
{
    ui->setupUi(this);
}
void addIngredientDialog::on_ingredSubmitBtn_clicked()
{
    tempIngredient.setName(ui->ingredNameEdit->text());
    tempIngredient.setMeasurmentUnit(ui->measUnitEdit->text());
    tempIngredient.setUsedAmount(ui->usedAmountSpin->value());
    tempIngredient.setPackageAmount(ui->packAmountSpin->value());
    tempIngredient.setPackagePrice(ui->packPriceSpin->value());
    accept();
}

ingredient addIngredientDialog::getIngredient()
{
    return tempIngredient;
}

void addIngredientDialog::on_ingredCancelBtn_clicked()
{
    reject();
}

addIngredientDialog::~addIngredientDialog()
{
    delete ui;
}
