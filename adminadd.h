#ifndef ADMINADD_H
#define ADMINADD_H

#include <QDialog>

namespace Ui {
class adminadd;
}

class adminadd : public QDialog
{
    Q_OBJECT

public:
    explicit adminadd(QWidget *parent = nullptr);
    ~adminadd();

private slots:
    void on_add_clicked();

    void on_reload_clicked();

    void on_exit_clicked();

private:
    Ui::adminadd *ui;
};

#endif // ADMINADD_H
