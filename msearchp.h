#ifndef MSEARCHP_H
#define MSEARCHP_H

#include <QDialog>

namespace Ui {
class msearchp;
}

class msearchp : public QDialog
{
    Q_OBJECT

public:
    explicit msearchp(QWidget *parent = nullptr);
    ~msearchp();

private slots:
    void on_cancel_clicked();

    void on_enter_clicked();

private:
    Ui::msearchp *ui;
};

#endif // MSEARCHP_H
