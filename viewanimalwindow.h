#ifndef VIEWANIMALWINDOW_H
#define VIEWANIMALWINDOW_H

#include <QDialog>

namespace Ui {
class ViewAnimalWindow;
}

class ViewAnimalWindow:public QDialog
{
    Q_OBJECT

public:
     Ui::ViewAnimalWindow *ui;
    explicit ViewAnimalWindow(QWidget *parent = 0);
    ~ViewAnimalWindow();

private:

};

#endif // VIEWANIMALWINDOW_H
