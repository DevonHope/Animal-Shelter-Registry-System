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

    //Animal Preferences
    QString type = ui->typeText->toPlainText();
    QString skill = ui->skillText->toPlainText();
    QString favFood = ui->favFoodText->toPlainText();

    int furLength = ui->furLenSlider->sliderPosition();
    int aggressiveness = ui->aggressivenessSlider->sliderPosition();
    int playfulness = ui->playfulSlider->sliderPosition();
    int kidFriendly = ui->kidFriendlySlider->sliderPosition();
    int houseTrained = ui->houseTrainedSlider->sliderPosition();
    int curiosity = ui->curiositySlider->sliderPosition();
    int intelligence = ui->intSlider->sliderPosition();
    int courage = ui->courageSlider->sliderPosition();
    int strength = ui->strSlider->sliderPosition();
    int commSkills = ui->commSlider->sliderPosition();
    int trust = ui->trustSlider->sliderPosition();
    int climate = ui->climateSlider->sliderPosition();

    bool claws = ui->clawsCheck->isChecked();
    bool sheds = ui->shedsCheck->isChecked();
    bool fur = ui->furCheck->isChecked();

    if(validClient){ //Valid Cleint
        Client c(name.toStdString(), age, gender.toStdString(), addr.toStdString(), pNumString.toStdString(), email.toStdString(),
                 type.toStdString(), skill.toStdString(), favFood.toStdString(), claws, sheds, fur, intelligence, aggressiveness,
                 courage, playfulness, strength, kidFriendly, commSkills, houseTrained, trust, curiosity, furLength, climate); //Construct Client
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
