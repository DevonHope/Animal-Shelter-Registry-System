#ifndef VIEWCLIENTWINDOW_H
#define VIEWCLIENTWINDOW_H

#include <QDialog>
#include "client.h"
#include "filemanager.h"

namespace Ui {
class ViewClientWindow;
}

class ViewClientWindow : public QDialog
{
    Q_OBJECT

public:
    void fillProfileInfo(Client);
    void selectedFileName(QString);
    void disableEditButton();
    void disableDeleteButton();
    explicit ViewClientWindow(QWidget *parent = 0);
    ~ViewClientWindow();

private slots:
    void on_deleteButton_clicked();

    void on_editButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::ViewClientWindow *ui;
    QString fName;
    bool isEditing = false;
    FileManager fm;
    bool checkRank();
    //void saveAs(Animal a);
};

#endif // VIEWCLIENTWINDOW_H
