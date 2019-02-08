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
    explicit ViewAnimalWindow(QWidget *parent = 0);
    ~ViewAnimalWindow();

private:
    Ui::ViewAnimalWindow *ui;
};

#endif // VIEWANIMALWINDOW_H
