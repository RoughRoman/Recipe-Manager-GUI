#include "choicedialog.h"
#include "ui_choicedialog.h"

choiceDialog::choiceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choiceDialog)
{
    ui->setupUi(this);
}

void choiceDialog::setMessage(QString message)
{
    ui->messageLabel->setText(message);
}

void choiceDialog::on_continueBtn_clicked()
{
    accept();
}

void choiceDialog::on_cancelBtn_clicked()
{
    reject();
}

choiceDialog::~choiceDialog()
{
    delete ui;
}
