#ifndef MEMBERR_H
#define MEMBERR_H

#include <QDialog>

namespace Ui {
class memberr;
}

class memberr : public QDialog
{
    Q_OBJECT

public:
    explicit memberr(QWidget *parent = nullptr);
    ~memberr();

private slots:
    void on_showp_clicked();

    void on_buy_clicked();

private:
    Ui::memberr *ui;
};

#endif // MEMBERR_H
