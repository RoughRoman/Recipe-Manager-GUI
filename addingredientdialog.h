#ifndef ADDINGREDIENTDIALOG_H
#define ADDINGREDIENTDIALOG_H

#include <QDialog>
#include <ingredient.hpp>
#include <messagedialog.h>


namespace Ui {
class addIngredientDialog;
}

class addIngredientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addIngredientDialog(QWidget *parent = nullptr);
    ~addIngredientDialog();
    ingredient getIngredient();

    //setters
    void setName(QString name);
    void setMeasurmentUnit(QString measUnit);
    void setUsedAmount(float used);
    void setPackagePrice(float packprice);
    void setPackageAmount(float packamount);

private:
    Ui::addIngredientDialog *ui;
    ingredient tempIngredient;

private slots:
    void on_ingredSubmitBtn_clicked();
    void on_ingredCancelBtn_clicked();

};

#endif // ADDINGREDIENTDIALOG_H
