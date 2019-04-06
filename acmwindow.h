#ifndef ACMWINDOW_H
#define ACMWINDOW_H

#include <QDialog>

namespace Ui {
class ACMWindow;
}

class ACMWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ACMWindow(QWidget *parent = 0);
    ~ACMWindow();

private slots:
    void on_cancelButton_clicked();

private:
    Ui::ACMWindow *ui;
};

#endif // ACMWINDOW_H
