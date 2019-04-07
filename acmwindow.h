#ifndef ACMWINDOW_H
#define ACMWINDOW_H

#include <QDialog>
#include "filemanager.h"

struct clientMatchNode {
    Client *c;
    bool hasMatch = false;
    string matchedWith;
};

struct animalMatchNode {
      Animal *a;
      bool hasMatch = false;
};

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
    clientMatchNode *listOfClients;
    animalMatchNode *listOfAnimals;
    FileManager fm;
};

#endif // ACMWINDOW_H
