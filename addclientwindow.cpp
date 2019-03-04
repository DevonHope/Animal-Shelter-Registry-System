#include "addclientwindow.h"
#include "ui_addclientwindow.h"
#include "client.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDirIterator>
#include <QtWidgets>
#include <string>

AddClientWindow::AddClientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClientWindow)
{
    ui->setupUi(this);
}

AddClientWindow::~AddClientWindow()
{
    delete ui;
}

/*
 * Used to prevent both male and female being checked at the same time.
 */
void AddClientWindow::on_maleCheck_clicked()
{
    ui->femaleCheck->setChecked(false);
}

/*
 * Used to prevent both male and female being checked at the same time.
 */
void AddClientWindow::on_femaleCheck_clicked()
{
    ui->maleCheck->setChecked(false);
}

/*
 * Collects all data from the field of the form and
 * creates an client object from them. That object
 * is then saved to a flat file.
 */
void AddClientWindow::on_addButton_clicked()
{
    bool validClient = true;
    //Retrive data from UI
    QString name = ui->nameText->toPlainText();

    QString ageString = ui->ageText->toPlainText();
    int age = ageString.toInt();
    if(age == 0){ //toInt returns 0 if the string is not an integer number
        validClient = false; //Not a valid client (does not save)
        switch( QMessageBox::question(this, tr("Error"), tr("Age is not valid, please enter a non-zero number"), QMessageBox::Ok, QMessageBox::Ok ) )
        {
            case QMessageBox::Ok:
                break;
            default:
                break;
        }
    }

    QString gender;
    if(ui->maleCheck->isChecked()){
        gender = "Male";
    } else if (ui->femaleCheck->isChecked()){
        gender = "Female";
    } else{ //Neither is selected
        validClient = false; //Not a valid client (does not save)
        switch( QMessageBox::question(this, tr("Error"), tr("Please check a gender"), QMessageBox::Ok, QMessageBox::Ok ) )
        {
            case QMessageBox::Ok:
                break;
            default:
                break;
        }
    }

    QString pNumString = ui->pNumText->toPlainText();

    QString addr = ui->addrText->toPlainText();
    QString email = ui->emailText->toPlainText();

    if(validClient){ //Valid Cleint
        Client c(name.toStdString(), age, gender.toStdString(), addr.toStdString(), pNumString.toStdString(), email.toStdString()); //Construct Client
        saveAs(c); //Save constructed client
        this->destroy(); //Close Window*/
    }
}

/*
 * Will save the client input in a text document by
 * utilizing the Client's toString() function.
 */
void AddClientWindow::saveAs(Client c)
{
    //Get file name from user
    QString fileName = QFileDialog::getSaveFileName(this,
           tr("Save Text Document"), "",
           tr("Plain Text (*.txt);;All Files (*)"));

    if(!(fileName.isEmpty())){ //Check if a file name was entered
        if(!(fileName.endsWith(".txt"))){
            fileName += ".txt";
        }

        QFile file(fileName);
        file.open(QFile::WriteOnly|QFile::Truncate); //Clear file contents
        file.close();
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            QString data = QString::fromStdString(c.toString()); //get client data in the form of a string
            stream << data << endl; //output data to file
            switch( QMessageBox::question(
                        this,
                        tr("Application Name"),
                        tr("Save was successful."),
                        QMessageBox::Ok,
                        QMessageBox::Ok ) )
            {
                case QMessageBox::Ok:
                    break;
                default:
                    break;
            }
        } else { //Save error
            switch( QMessageBox::question(
                        this,
                        tr("Application Name"),
                        tr("Save may have failed!"),
                        QMessageBox::Ok,
                        QMessageBox::Ok ) )
            {
                case QMessageBox::Ok:
                    break;
                default:
                    break;
            }
        }
    }
}

/*
 * Returns the user back to the main window; does not save a new client
 */
void AddClientWindow::on_cancelButton_clicked()
{
    bool confirm = false;
    switch( QMessageBox::question(
                this,
                tr("Application Name"),
                tr("Are you sure you want to cancel? Any unsaved data may be lost."),
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

    if(confirm){
        this->destroy(); //Close window
    }
}
