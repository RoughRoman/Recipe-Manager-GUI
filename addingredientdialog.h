#ifndef ADDINGREDIENTDIALOG_H
#define ADDINGREDIENTDIALOG_H

#include <QDialog>
#include <ingredient.hpp>


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

private:
    Ui::addIngredientDialog *ui;
    ingredient tempIngredient;

private slots:
    void on_ingredSubmitBtn_clicked();
    void on_ingredCancelBtn_clicked();

};

#endif // ADDINGREDIENTDIALOG_H
