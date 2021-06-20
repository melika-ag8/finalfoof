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

    void on_searchline_textChanged(const QString &arg1);

    void on_cancel_clicked();

private:
    Ui::msearchp *ui;
};

#endif // MSEARCHP_H
