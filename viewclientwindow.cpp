#include "viewclientwindow.h"
#include "ui_viewclientwindow.h"
//#include "client.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDirIterator>
#include <QtWidgets>

ViewClientWindow::ViewClientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewClientWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Profile Information");
}
/*
 * Sets the UI fields to the values contained within
 * the client object.
 */

/*
void ViewClientWindow::fillProfileInfo(Animal a) {

    //Set fields to read only so they cannot be modified by user
    ui->nameText->setReadOnly(true);
    ui->ageText->setReadOnly(true);
    ui->breedText->setReadOnly(true);
    ui->typeText->setReadOnly(true);
    ui->climateText->setReadOnly(true);
    ui->colourText->setReadOnly(true);
    ui->weightText->setReadOnly(true);

    //Display specific animal information from the object
    ui->nameText->setPlainText(QString::fromStdString(a.getName()));
    ui->ageText->setPlainText(QString::number(a.getAge()));
    ui->breedText->setPlainText(QString::fromStdString(a.getBreed()));
    ui->typeText->setPlainText(QString::fromStdString(a.getType()));
    ui->climateText->setPlainText(QString::fromStdString(a.getClimatePref()));
    ui->colourText->setPlainText(QString::fromStdString(a.getColour()));
    ui->weightText->setPlainText(QString::number(a.getWeight()));

    //Set check box values and disable them from being changed.
    if (a.getGender() == "Male") {
        ui->maleCheck->setChecked(true);
        ui->maleCheck->setEnabled(false);
        ui->femaleCheck->setEnabled(false);
    }
    else {
        ui->femaleCheck->setChecked(true);
        ui->femaleCheck->setEnabled(false);
        ui->maleCheck->setEnabled(false);
    }

    if (a.getHasFur() == true) {
        ui->furCheck->setChecked(true);
        ui->furCheck->setEnabled(false);
    }
    else {
        ui->furCheck->setChecked(false);
        ui->furCheck->setEnabled(false);
    }

    if (a.getClaws() == true) {
        ui->clawsCheck->setChecked(true);
        ui->clawsCheck->setEnabled(false);
    }
    else {
        ui->clawsCheck->setChecked(false);
        ui->clawsCheck->setEnabled(false);
    }

    if (a.getSheds() == true) {
        ui->shedsCheck->setChecked(true);
        ui->shedsCheck->setEnabled(false);
    }
    else {
        ui->shedsCheck->setChecked(false);
        ui->shedsCheck->setEnabled(false);
    }
}*/

ViewClientWindow::~ViewClientWindow()
{
    delete ui;
}

/*
 * Deletes the client being viewed from the file system, it will
 * remain loaded in until the user refreshes the animal list.
 */

/*
void ViewClientWindow::on_deleteButton_clicked()
{
    bool confirm = false;
    QString fileName = fName; //File name is retrieved from the client node struct

        switch( QMessageBox::question(
                    this,
                    tr("Application Name"),
                    tr("Are you sure you want to delete this file? All data within it will be lost."),
                    QMessageBox::Cancel | QMessageBox::Ok,
                    QMessageBox::Ok ) )
        {
            case QMessageBox::Ok:
                confirm = true;
                break;
            case QMessageBox::Cancel:
                break;
            default:
                break;
        }

    if (confirm == true) {
        QFile file(QDir::currentPath() + "/Animals/" + fileName);
        file.remove(); //Delete file
    }
    this->destroy(); //Close window
}*/

void ViewClientWindow::selectedFileName(QString f) {
    fName = f;
}