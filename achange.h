#ifndef ACHANGE_H
#define ACHANGE_H

#include <QDialog>

namespace Ui {
class achange;
}

class achange : public QDialog
{
    Q_OBJECT

public:
    explicit achange(QWidget *parent = nullptr);
    ~achange();

private slots:
    void on_change_clicked();

    void on_exit_clicked();

private:
    Ui::achange *ui;
};

#endif // ACHANGE_H
