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

    //Animal Preferences
    //Sets the fields to read only as the staff user can't add in any of the clients preferences
    ui->skillText->setDisabled(true);
    ui->typeText->setDisabled(true);
    ui->favFoodText->setDisabled(true);

    //Disables the sliders and checkboxes as the staff user can't add in any of the clients preferences
    ui->furLenSlider->setDisabled(true);
    ui->aggressivenessSlider->setDisabled(true);
    ui->playfulSlider->setDisabled(true);
    ui->kidFriendlySlider->setDisabled(true);
    ui->houseTrainedSlider->setDisabled(true);
    ui->curiositySlider->setDisabled(true);
    ui->intSlider->setDisabled(true);
    ui->courageSlider->setDisabled(true);
    ui->strSlider->setDisabled(true);
     ui->commSlider->setDisabled(true);
    ui->trustSlider->setDisabled(true);
    ui->climateSlider->setDisabled(true);

    ui->clawsCheck->setDisabled(true);
    ui->shedsCheck->setDisabled(true);
    ui->furCheck->setDisabled(true);
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
        Client c(name.toStdString(), age, gender.toStdString(), addr.toStdString(), pNumString.toStdString(), email.toStdString(),
                 "", "", "", false, false, false, 0, 0,
                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); //Construct Client
        fm.saveClientAs(c, this); //Save constructed client
        this->destroy(); //Close Window*/
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
