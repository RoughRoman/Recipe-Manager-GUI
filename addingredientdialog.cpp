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
    /* This function checks if ingredient name and measurment unit have been input and
     * displays an appropriate message warning the user and not allowing the dialog to accept
     * if the mandatory values are filled then it assigns the values to a stored object in
     * then it accepts and closes the dialog.*/

    bool validName, validUnit = false;

    if (ui->ingredNameEdit->text() == "")
    {
        validName = false;
        messageDialog mess;
        mess.setMessage("Ingredient name not specified.");
        mess.exec();
    }
    else
    {
        tempIngredient.setName(ui->ingredNameEdit->text());
        validName = true;
    }


    if (ui->measUnitEdit->text() == "")
    {
        validUnit = false;
        messageDialog mess;
        mess.setMessage("Measurment unit not specified.");
        mess.exec();
    }
    else
    {
        tempIngredient.setMeasurmentUnit(ui->measUnitEdit->text());
        validUnit = true;
    }

    if (ui->packAmountSpin->value() == 0 || ui->packPriceSpin->value() == 0)
    {
        ui->packAmountSpin->setValue(0.0);
        ui->packPriceSpin->setValue(0.0);
    }

    tempIngredient.setUsedAmount(ui->usedAmountSpin->value());
    tempIngredient.setPackageAmount(ui->packAmountSpin->value());
    tempIngredient.setPackagePrice(ui->packPriceSpin->value());

    if (validName == true && validUnit == true)
    {
        accept();
    }
    else
    {
        return;
    }


}

ingredient addIngredientDialog::getIngredient()
{
    // this function returns the ingredient built after the dialog accepts
    return tempIngredient;
}

void addIngredientDialog::on_ingredCancelBtn_clicked()
{
    // this function rejects the dialog should the user click cancel
    reject();
}

void addIngredientDialog::setName(QString name)
{
    ui->ingredNameEdit->setText(name);
}
void addIngredientDialog::setMeasurmentUnit(QString measUnit)
{
    ui->measUnitEdit->setText(measUnit);
}
void  addIngredientDialog::setUsedAmount(float used)
{
   ui->usedAmountSpin->setValue(used);
}
void  addIngredientDialog::setPackagePrice(float packprice)
{
    ui->packPriceSpin->setValue(packprice);
}
void  addIngredientDialog::setPackageAmount(float packamount)
{
    ui->packAmountSpin->setValue(packamount);
}

addIngredientDialog::~addIngredientDialog()
{
    delete ui;
}
