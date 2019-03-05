#include "viewclientwindow.h"
#include "ui_viewclientwindow.h"
#include "client.h"
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


void ViewClientWindow::fillProfileInfo(Client c) {

    //Set fields to read only so they cannot be modified by user
    ui->nameText->setReadOnly(true);
    ui->ageText->setReadOnly(true);
    ui->emailText->setReadOnly(true);
    ui->pNumText->setReadOnly(true);
    ui->addrText->setReadOnly(true);

    //Display specific client information from the object
    ui->nameText->setPlainText(QString::fromStdString(c.getName()));
    ui->ageText->setPlainText(QString::number(c.getAge()));
    ui->emailText->setPlainText(QString::fromStdString(c.getMail()));
    ui->pNumText->setPlainText(QString::fromStdString(c.getPNum()));
    ui->addrText->setPlainText(QString::fromStdString(c.getAddress()));

    //Set check box values and disable them from being changed.
    if (c.getGender() == "Male") {
        ui->maleCheck->setChecked(true);
        ui->maleCheck->setEnabled(false);
        ui->femaleCheck->setEnabled(false);
    }
    else {
        ui->femaleCheck->setChecked(true);
        ui->femaleCheck->setEnabled(false);
        ui->maleCheck->setEnabled(false);
    }
}

ViewClientWindow::~ViewClientWindow()
{
    delete ui;
}

/*
 * Deletes the client being viewed from the file system, it will
 * remain loaded in until the user refreshes the client list.
 */


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
        QFile file(QDir::currentPath() + "/Clients/" + fileName);
        file.remove(); //Delete file
    }
    this->destroy(); //Close window
}

void ViewClientWindow::selectedFileName(QString f) {
    fName = f;
}
