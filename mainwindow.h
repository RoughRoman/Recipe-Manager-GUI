#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <RecipeManager.hpp>
#include <addrecipedialog.h>
#include <addingredientdialog.h> // just about to connect recipe add ingredient to this dialog.


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    RecipeManager  ReciperManager1;


private slots:
    void on_addRecipeBtn_clicked();
    void on_loadRecipeAction_clicked();

};
#endif // MAINWINDOW_H