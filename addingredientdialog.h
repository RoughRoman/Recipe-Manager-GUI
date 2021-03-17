#ifndef ADDINGREDIENTDIALOG_H
#define ADDINGREDIENTDIALOG_H

#include <QDialog>

namespace Ui {
class addIngredientDialog;
}

class addIngredientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addIngredientDialog(QWidget *parent = nullptr);
    ~addIngredientDialog();

private:
    Ui::addIngredientDialog *ui;
};

#endif // ADDINGREDIENTDIALOG_H
