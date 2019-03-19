#ifndef VIEWANIMALWINDOW_H
#define VIEWANIMALWINDOW_H

#include <QDialog>
#include "animal.h"
#include "filemanager.h"

namespace Ui {
class ViewAnimalWindow;
}

class ViewAnimalWindow:public QDialog
{
    Q_OBJECT

public:
    void fillProfileInfo(Animal);
    void selectedFileName(QString);
    void disableDeleteButton();
    explicit ViewAnimalWindow(QWidget *parent = 0);
    ~ViewAnimalWindow();

private slots:
    void on_deleteButton_clicked();

    void on_cancelButton_clicked();

    void on_editButton_clicked();

private:
    Ui::ViewAnimalWindow *ui;
   QString fName;
   bool isEditing = false;
   FileManager fm;
   //void saveAs(Animal a);
};

#endif // VIEWANIMALWINDOW_H
