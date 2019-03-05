#ifndef VIEWANIMALWINDOW_H
#define VIEWANIMALWINDOW_H

#include <QDialog>
#include "animal.h"

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

private:
    Ui::ViewAnimalWindow *ui;
   QString fName;
};

#endif // VIEWANIMALWINDOW_H
