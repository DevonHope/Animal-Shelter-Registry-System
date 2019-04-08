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

/* A struct for getting the pair score with the paired animal*/
struct scoreNode {
    int animalIndex;
    float matchScore;
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
    scoreNode *scoresOfMatches;
    FileManager fm;
    bool profileQuestions(Client, Animal);
    int calculateResult(int, int);
    int calculateResult(string, string);
};

#endif // ACMWINDOW_H
