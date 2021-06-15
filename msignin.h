#ifndef MSIGNIN_H
#define MSIGNIN_H

#include <QDialog>

namespace Ui {
class msignin;
}

class msignin : public QDialog
{
    Q_OBJECT

public:
    explicit msignin(QWidget *parent = nullptr);
    ~msignin();

private slots:
    void on_cancel_clicked();

    void on_save_clicked();

    void on_reload_clicked();

    void on_changepass_clicked();

private:
    Ui::msignin *ui;
};

#endif // MSIGNIN_H
