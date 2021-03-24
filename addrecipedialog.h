#ifndef ADDRECIPEDIALOG_H
#define ADDRECIPEDIALOG_H

#include <QDialog>
#include <addingredientdialog.h>
#include <recipe.hpp>
#include <messagedialog.h>

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
    void setName(QString name);
    void setInstructions(QString instruc);
    void setServings(int servs);

    void setIngredients(vector<ingredient> ingredientVec);

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
