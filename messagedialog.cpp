#include "messagedialog.h"
#include "ui_messagedialog.h"

messageDialog::messageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::messageDialog)
{
    ui->setupUi(this);
}

void messageDialog::setMessage(QString message, QString type)
{
    ui->messageLabel->setText(message);
    ui->typeLabel->setText(type);
}

void messageDialog::on_okBtn_clicked()
{
    accept();
}

messageDialog::~messageDialog()
{
    delete ui;
}
