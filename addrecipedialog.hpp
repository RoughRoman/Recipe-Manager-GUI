#ifndef ADDRECIPEDIALOG_HPP
#define ADDRECIPEDIALOG_HPP

#include <QDialog>

namespace Ui {
class addRecipeDialog;
}

class addRecipeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addRecipeDialog(QWidget *parent = nullptr);
    ~addRecipeDialog();

private:
    Ui::addRecipeDialog *ui;
};

#endif // ADDRECIPEDIALOG_HPP
