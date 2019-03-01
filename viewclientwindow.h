#ifndef VIEWCLIENTWINDOW_H
#define VIEWCLIENTWINDOW_H

#include <QDialog>
#include "client.h"

namespace Ui {
class ViewClientWindow;
}

class ViewClientWindow : public QDialog
{
    Q_OBJECT

public:
    void fillProfileInfo(Client);
    void selectedFileName(QString);
    explicit ViewClientWindow(QWidget *parent = 0);
    ~ViewClientWindow();

private slots:
    void on_deleteButton_clicked();

private:
    Ui::ViewClientWindow *ui;
    QString fName;
};

#endif // VIEWCLIENTWINDOW_H
