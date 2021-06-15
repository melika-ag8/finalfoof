#ifndef ASEARCHP_H
#define ASEARCHP_H

#include <QDialog>

namespace Ui {
class asearchp;
}

class asearchp : public QDialog
{
    Q_OBJECT

public:
    explicit asearchp(QWidget *parent = nullptr);
    ~asearchp();

private slots:

    void on_cancel_clicked();

    void on_searchline_textChanged(const QString &arg1);


private:
    Ui::asearchp *ui;
};

#endif // ASEARCHP_H
