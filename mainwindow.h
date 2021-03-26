#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <RecipeManager.hpp>
#include <addrecipedialog.h>
#include <addingredientdialog.h>
#include <messagedialog.h>
#include <choicedialog.h>
#include <QDebug>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void update();


    void log(QString msg);

private:
    Ui::MainWindow *ui;

    RecipeManager  ReciperManager1;


private slots:
    void debug();
    // buttons
    void on_addRecipeBtn_clicked();
    void on_deleteRecipeBtn_clicked();
    void on_editRecipeBtn_clicked();
    void on_printRecipeBtn_clicked();

    // actions
    void on_loadRecipeAction_triggered();
    void on_saveRecipeListAction_triggered();
    void on_exitAction_triggered();
    void on_deleteRecipeListAction_triggered();


    // list widget
    void on_recipeListWgt_itemClicked();

};
#endif // MAINWINDOW_H
