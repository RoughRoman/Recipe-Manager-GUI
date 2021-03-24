#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QDialog>

namespace Ui {
class messageDialog;
}

class messageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit messageDialog(QWidget *parent = nullptr);
    ~messageDialog();

    void setMessage(QString message, QString type = "Warning");

private:
    Ui::messageDialog *ui;

private slots:
    void on_okBtn_clicked();
};

#endif // MESSAGEDIALOG_H
