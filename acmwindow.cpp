#include "acmwindow.h"
#include "ui_acmwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDirIterator>
#include <QtWidgets>
#include <string>

ACMWindow::ACMWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ACMWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ACM Results");
    ui->textBrowser->setReadOnly(true);

    listOfAnimals = new animalMatchNode[50];
    listOfClients = new clientMatchNode[50];


}


ACMWindow::~ACMWindow()
{
    delete [] listOfClients;
    delete [] listOfAnimals;
    delete ui;
}

void ACMWindow::on_cancelButton_clicked()
{
    this->destroy(); //Closes window
}
