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

    bool claws = ui->clawsCheck->isChecked();
    bool sheds = ui->shedsCheck->isChecked();
    bool fur = ui->furCheck->isChecked();

    bool rankCheck = checkRank();
    if(!rankCheck){
        validClient = false;
        switch( QMessageBox::question(this, tr("Error"), tr("Please ensure that no ranks are equal."), QMessageBox::Ok, QMessageBox::Ok ) )
        {
            case QMessageBox::Ok:
                break;
            default:
                break;
        }
    }

    int furRank = ui->furRank->currentText().toInt();
    int intRank = ui->intRank->currentText().toInt();
    int aggroRank = ui->aggroRank->currentText().toInt();
    int courageRank = ui->courageRank->currentText().toInt();
    int playRank = ui->playRank->currentText().toInt();
    int strRank = ui->strRank->currentText().toInt();
    int kFRank = ui->kidFriendlyRank->currentText().toInt();
    int commRank = ui->commRank->currentText().toInt();
    int hTRank = ui->houseTrainRank->currentText().toInt();
    int trustRank = ui->trustRank->currentText().toInt();
    int curiosityRank = ui->curiosityRank->currentText().toInt();
    int skillRank = ui->skillRank->currentText().toInt();
    int clRank = ui->climateRank->currentText().toInt();

    bool exerciseAccesibility;
    QString exerciseString = ui->exerciseAccessibility->currentText();
    if(exerciseString == "Yes"){
        exerciseAccesibility = true;
    }else{
        exerciseAccesibility = false;
    }
    int houseSize = ui->houseSlider->sliderPosition();
    int yardSize = ui->yardSlider->sliderPosition();

    if(validClient){ //Valid Cleint
        Client c(name.toStdString(), age, gender.toStdString(), addr.toStdString(), pNumString.toStdString(), email.toStdString(),
                 type.toStdString(), skill.toStdString(), favFood.toStdString(), claws, sheds, fur, intelligence, aggressiveness,
                 courage, playfulness, strength, kidFriendly, commSkills, houseTrained, trust, curiosity, furLength, furRank,
                 intRank, aggroRank, courageRank, playRank, strRank, kFRank, commRank, hTRank, trustRank, curiosityRank, skillRank,
                 clRank, exerciseAccesibility, houseSize, yardSize); //Construct Client
        fm.saveClientAs(c); //Save constructed client
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

bool AddClientWindow::checkRank()
{
    int rankArr[13];
    rankArr[0] = ui->furRank->currentText().toInt();
    rankArr[1] = ui->intRank->currentText().toInt();
    rankArr[2] = ui->aggroRank->currentText().toInt();
    rankArr[3] = ui->courageRank->currentText().toInt();
    rankArr[4] = ui->playRank->currentText().toInt();
    rankArr[5] = ui->strRank->currentText().toInt();
    rankArr[6] = ui->kidFriendlyRank->currentText().toInt();
    rankArr[7] = ui->commRank->currentText().toInt();
    rankArr[8] = ui->houseTrainRank->currentText().toInt();
    rankArr[9] = ui->trustRank->currentText().toInt();
    rankArr[10] = ui->curiosityRank->currentText().toInt();
    rankArr[11] = ui->climateRank->currentText().toInt();
    rankArr[12] = ui->skillRank->currentText().toInt();

    for(int i = 0; i < 13; i++){
        for(int j = i+1; j < 13; j++){
            if(rankArr[i] = rankArr[j]){
                return false;
            }
        }
    }
    return true; //no values are the same
}
