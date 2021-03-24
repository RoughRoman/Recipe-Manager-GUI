#ifndef CHOICEDIALOG_H
#define CHOICEDIALOG_H

#include <QDialog>

namespace Ui {
class choiceDialog;
}

class choiceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit choiceDialog(QWidget *parent = nullptr);
    ~choiceDialog();

    void setMessage(QString message);

private:
    Ui::choiceDialog *ui;

private slots:
    void on_continueBtn_clicked();
    void on_cancelBtn_clicked();
};

#endif // CHOICEDIALOG_H
