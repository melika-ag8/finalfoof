#ifndef ASIGNIN_H
#define ASIGNIN_H

#include <QDialog>

namespace Ui {
class asignin;
}

class asignin : public QDialog
{
    Q_OBJECT

public:
    explicit asignin(QWidget *parent = nullptr);
    ~asignin();

private slots:
    void on_cancel_clicked();

    void on_reload_clicked();

    void on_save_clicked();

    void on_changepass_clicked();

private:
    Ui::asignin *ui;
};

#endif // ASIGNIN_H
