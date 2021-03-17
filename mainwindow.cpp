#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


void MainWindow::on_addRecipeBtn_clicked()
{
    addRecipeDialog recipeDialog;
    recipeDialog.exec();
}

void MainWindow::on_loadRecipeAction_clicked()
{
    ReciperManager1.loadFromFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

