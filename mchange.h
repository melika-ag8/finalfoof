#ifndef MCHANGE_H
#define MCHANGE_H

#include <QDialog>

namespace Ui {
class mchange;
}

class mchange : public QDialog
{
    Q_OBJECT

public:
    explicit mchange(QWidget *parent = nullptr);
    ~mchange();

private slots:
    void on_change_clicked();

    void on_exit_clicked();

private:
    Ui::mchange *ui;
};

#endif // MCHANGE_H
