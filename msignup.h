#ifndef MSIGNUP_H
#define MSIGNUP_H

#include <QDialog>

namespace Ui {
class msignup;
}

class msignup : public QDialog
{
    Q_OBJECT

public:
    explicit msignup(QWidget *parent = nullptr);
    ~msignup();

private slots:
    void on_cancel_clicked();

    void on_save_clicked();

    void on_reload_clicked();

private:
    Ui::msignup *ui;
};

#endif // MSIGNUP_H
