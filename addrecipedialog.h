#ifndef ADDRECIPEDIALOG_H
#define ADDRECIPEDIALOG_H

#include <QDialog>
#include <addingredientdialog.h>
#include <recipe.hpp>

namespace Ui {
class addRecipeDialog;
}

class addRecipeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addRecipeDialog(QWidget *parent = nullptr);
    ~addRecipeDialog();
    recipe getRecipe();

private:
    Ui::addRecipeDialog *ui;
    recipe tempRecipe;

private slots:
    void on_recipeSubmitBtn_clicked();
    void on_recipeCancelBtn_clicked();
    void on_addIngredBtn_clicked();
    void on_deleteIngredBtn_clicked();

};

#endif // ADDRECIPEDIALOG_H
