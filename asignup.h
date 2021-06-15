#ifndef ASIGNUP_H
#define ASIGNUP_H

#include <QDialog>

namespace Ui {
class asignup;
}

class asignup : public QDialog
{
    Q_OBJECT

public:
    explicit asignup(QWidget *parent = nullptr);
    ~asignup();

private slots:

    void on_save_clicked();

    void on_cancel_clicked();

    void on_reload_clicked();

private:
    Ui::asignup *ui;
};

#endif // ASIGNUP_H
