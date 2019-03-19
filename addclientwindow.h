#ifndef ADDCLIENTWINDOW_H
#define ADDCLIENTWINDOW_H

#include <QDialog>
#include "client.h"
#include "filemanager.h"

namespace Ui {
class AddClientWindow;
}

class AddClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddClientWindow(QWidget *parent = 0);
    ~AddClientWindow();

private slots:
    void on_maleCheck_clicked();

    void on_femaleCheck_clicked();

    void on_addButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AddClientWindow *ui;
    FileManager fm;
    //void saveAs(Client c);
};

#endif // ADDCLIENTWINDOW_H
