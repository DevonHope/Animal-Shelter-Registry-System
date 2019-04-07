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
    ui->skillText->setReadOnly(true);
    ui->typeText->setReadOnly(true);
    ui->favFoodText->setReadOnly(true);

    //Disables the sliders so they cannot be modified by the user
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
    ui->houseSlider->setDisabled(true);
    ui->yardSlider->setDisabled(true);

    //Disables the drop down menus so they cannot be modified by the user
    ui->furRank->setDisabled(true);
    ui->intRank->setDisabled(true);
    ui->aggroRank->setDisabled(true);
    ui->courageRank->setDisabled(true);
    ui->playRank->setDisabled(true);
    ui->strRank->setDisabled(true);
    ui->kidFriendlyRank->setDisabled(true);
    ui->commRank->setDisabled(true);
    ui->houseTrainRank->setDisabled(true);
    ui->trustRank->setDisabled(true);
    ui->curiosityRank->setDisabled(true);
    ui->skillRank->setDisabled(true);
    ui->climateRank->setDisabled(true);
    ui->exerciseAccessibility->setDisabled(true);

    //Display specific client information from the object
    ui->nameText->setPlainText(QString::fromStdString(c.getName()));
    ui->ageText->setPlainText(QString::number(c.getAge()));
    ui->emailText->setPlainText(QString::fromStdString(c.getMail()));
    ui->pNumText->setPlainText(QString::fromStdString(c.getPNum()));
    ui->addrText->setPlainText(QString::fromStdString(c.getAddress()));
    ui->skillText->setPlainText(QString::fromStdString(c.getSSkill()));
    ui->typeText->setPlainText(QString::fromStdString(c.getType()));
    ui->favFoodText->setPlainText(QString::fromStdString(c.getFavFood()));

    ui->furLenSlider->setValue(c.getFurLen());
    ui->aggressivenessSlider->setValue(c.getAggro());
    ui->playfulSlider->setValue(c.getPlay());
    ui->kidFriendlySlider->setValue(c.getKF());
    ui->houseTrainedSlider->setValue(c.getHTrained());
    ui->curiositySlider->setValue(c.getCuriosity());
    ui->intSlider->setValue(c.getIntell());
    ui->courageSlider->setValue(c.getCourage());
    ui->strSlider->setValue(c.getStrength());
     ui->commSlider->setValue(c.getCSkill());
    ui->trustSlider->setValue(c.getTrust());
    ui->climateSlider->setValue(c.getClimate());
    ui->houseSlider->setValue(c.getHouseSize());
    ui->yardSlider->setValue(c.getYardSize());

    ui->furRank->setCurrentIndex(c.getFurRank() - 1);
    ui->intRank->setCurrentIndex(c.getIntRank() - 1);
    ui->aggroRank->setCurrentIndex(c.getAggroRank() - 1);
    ui->courageRank->setCurrentIndex(c.getCourageRank() - 1);
    ui->playRank->setCurrentIndex(c.getPlayRank() - 1);
    ui->strRank->setCurrentIndex(c.getStrRank() - 1);
    ui->kidFriendlyRank->setCurrentIndex(c.getKFRank() - 1);
    ui->commRank->setCurrentIndex(c.getCSkillRank() - 1);
    ui->houseTrainRank->setCurrentIndex(c.getHTrainedRank() - 1);
    ui->trustRank->setCurrentIndex(c.getTrustRank() - 1);
    ui->curiosityRank->setCurrentIndex(c.getCuriosityRank() - 1);
    ui->skillRank->setCurrentIndex(c.getSkillRank() - 1);
    ui->climateRank->setCurrentIndex(c.getClimateRank() - 1);

    if (c.getExerciseAccessibility() == true)
        ui->exerciseAccessibility->setCurrentText("Yes");
    else
        ui->exerciseAccessibility->setCurrentText("No");


    //Set check box values and disable them from being changed->
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

    if (c.getHasFur() == true) {
            ui->furCheck->setChecked(true);
            ui->furCheck->setEnabled(false);
        }
        else {
            ui->furCheck->setChecked(false);
            ui->furCheck->setEnabled(false);
        }

        if (c.getClaws() == true) {
            ui->clawsCheck->setChecked(true);
            ui->clawsCheck->setEnabled(false);
        }
        else {
            ui->clawsCheck->setChecked(false);
            ui->clawsCheck->setEnabled(false);
        }

        if (c.getSheds() == true) {
            ui->shedsCheck->setChecked(true);
            ui->shedsCheck->setEnabled(false);
        }
        else {
            ui->shedsCheck->setChecked(false);
            ui->shedsCheck->setEnabled(false);
        }
}

ViewClientWindow::~ViewClientWindow()
{
    delete ui;
}

void ViewClientWindow::disableEditButton() {
    ui->editButton->setDisabled(true);
}

void ViewClientWindow::disableDeleteButton() {
    ui->deleteButton->setDisabled(true);
}

void ViewClientWindow::on_cancelButton_clicked()
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
        this->close(); //Close window
    }
}

/*
 * Deletes the client being viewed from the file system, it will
 * remain loaded in until the user refreshes the client list.
 */

void ViewClientWindow::on_deleteButton_clicked()
{
    QString storagePath = QDir::currentPath() + "/Clients/";
    fm.deleteFile(storagePath + fName, this);
    this->destroy(); //Close window
}

void ViewClientWindow::selectedFileName(QString f) {
    fName = f;
}

void ViewClientWindow::on_editButton_clicked()
{
    if(isEditing == false){
        isEditing = true;
        ui->label->setText("Editing Mode");
        ui->editButton->setText("Confirm");

        //Enable all UI elements to edit
        ui->nameText->setReadOnly(false);
        ui->ageText->setReadOnly(false);
        ui->maleCheck->setEnabled(true);
        ui->femaleCheck->setEnabled(true);
        ui->emailText->setReadOnly(false);
        ui->pNumText->setReadOnly(false);
        ui->addrText->setReadOnly(false);

        ui->typeText->setReadOnly(false);;
        ui->skillText->setReadOnly(false);
        ui->favFoodText->setReadOnly(false);

        ui->furLenSlider->setDisabled(false);
        ui->aggressivenessSlider->setDisabled(false);
        ui->playfulSlider->setDisabled(false);
        ui->kidFriendlySlider->setDisabled(false);
        ui->houseTrainedSlider->setDisabled(false);
        ui->curiositySlider->setDisabled(false);
        ui->intSlider->setDisabled(false);
        ui->courageSlider->setDisabled(false);
        ui->strSlider->setDisabled(false);
        ui->commSlider->setDisabled(false);
        ui->trustSlider->setDisabled(false);
        ui->climateSlider->setDisabled(false);
        ui->houseSlider->setDisabled(false);
        ui->yardSlider->setDisabled(false);

        ui->furCheck->setEnabled(true);
        ui->clawsCheck->setEnabled(true);
        ui->shedsCheck->setEnabled(true);

        ui->furRank->setDisabled(false);
        ui->intRank->setDisabled(false);
        ui->aggroRank->setDisabled(false);
        ui->courageRank->setDisabled(false);
        ui->playRank->setDisabled(false);
        ui->strRank->setDisabled(false);
        ui->kidFriendlyRank->setDisabled(false);
        ui->commRank->setDisabled(false);
        ui->houseTrainRank->setDisabled(false);
        ui->trustRank->setDisabled(false);
        ui->curiosityRank->setDisabled(false);
        ui->skillRank->setDisabled(false);
        ui->climateRank->setDisabled(false);
        ui->exerciseAccessibility->setDisabled(false);


    } else { //Save edits
        isEditing = false;
        ui->label->setText("Reading Mode");
        ui->editButton->setText("Edit");

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
        }
        else{ //Neither is selected
            validClient = false; //Not a valid client (does not save)
            switch( QMessageBox::question(this, tr("Error"), tr("Please check a gender"), QMessageBox::Ok, QMessageBox::Ok ) )
            {
                case QMessageBox::Ok:
                    break;
                default:
                    break;
            }
        }

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

        //Weighting of attributes
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


         //Complex attributes
         bool exerciseAccesibility;
         QString exerciseString = ui->exerciseAccessibility->currentText();
         if(exerciseString == "Yes"){
             exerciseAccesibility = true;
         }else{
             exerciseAccesibility = false;
         }
         int houseSize = ui->houseSlider->sliderPosition();
         int yardSize = ui->yardSlider->sliderPosition();


        QString pNumString = ui->pNumText->toPlainText();
        QString addr = ui->addrText->toPlainText();
        QString email = ui->emailText->toPlainText();

        //Animal Preferences
        QString type = ui->typeText->toPlainText();
        QString skill = ui->skillText->toPlainText();
        QString favFood = ui->favFoodText->toPlainText();

        bool hasFur = ui->furCheck->isChecked();
        bool claws = ui->clawsCheck->isChecked();
        bool sheds = ui->shedsCheck->isChecked();

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



        if(validClient){ //Valid Cleint
            Client edittedClient(name.toStdString(), age, gender.toStdString(), addr.toStdString(), pNumString.toStdString(), email.toStdString(),
                     type.toStdString(), skill.toStdString(), favFood.toStdString(), claws, sheds, hasFur, intelligence, aggressiveness,
                     courage, playfulness, strength, kidFriendly, commSkills, houseTrained, trust, curiosity, furLength, climate,
                     furRank, intRank, aggroRank, courageRank, playRank, strRank, kFRank, commRank, hTRank, trustRank, curiosityRank, skillRank, clRank,
                     exerciseAccesibility, houseSize, yardSize); //Construct Client
            QString storagePath = QDir::currentPath() + "/Clients/";
            fm.saveClient(edittedClient, storagePath + fName, this); //Save constructed client
        }

            //Disable all UI elements to edit
            ui->nameText->setReadOnly(true);
            ui->ageText->setReadOnly(true);
            ui->maleCheck->setEnabled(false);
            ui->femaleCheck->setEnabled(false);
            ui->emailText->setReadOnly(true);
            ui->pNumText->setReadOnly(true);
            ui->addrText->setReadOnly(true);

            ui->typeText->setReadOnly(true);
            ui->skillText->setReadOnly(true);
            ui->favFoodText->setReadOnly(true);

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
            ui->houseSlider->setDisabled(true);
            ui->yardSlider->setDisabled(true);

            ui->furCheck->setEnabled(false);
            ui->clawsCheck->setEnabled(false);
            ui->shedsCheck->setEnabled(false);

            ui->furRank->setDisabled(true);
            ui->intRank->setDisabled(true);
            ui->aggroRank->setDisabled(true);
            ui->courageRank->setDisabled(true);
            ui->playRank->setDisabled(true);
            ui->strRank->setDisabled(true);
            ui->kidFriendlyRank->setDisabled(true);
            ui->commRank->setDisabled(true);
            ui->houseTrainRank->setDisabled(true);
            ui->trustRank->setDisabled(true);
            ui->curiosityRank->setDisabled(true);
            ui->skillRank->setDisabled(true);
            ui->climateRank->setDisabled(true);
            ui->exerciseAccessibility->setDisabled(true);
    }
}

bool ViewClientWindow::checkRank()
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
            if(rankArr[i] == rankArr[j]){
                return false;
            }
        }
    }
    return true; //no values are the same
}

/*
 * Will save the animal input in a text document by
 * utilizing the Animal's toString() function.
 */
/*void ViewClientWindow::saveAs(Client c){
    //Get file name from user
    if(!(fName.isEmpty())){ //Check if a file name was entered
        if(!(fName.endsWith(".txt"))){
            fName = fName + ".txt";
        }

        QString storagePath = QDir::currentPath() + "/Clients/";

        QFile file(storagePath + fName);
        file.open(QFile::WriteOnly|QFile::Truncate); //Clear file contents
        file.close();
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            QString data = QString::fromStdString(c.toString()); //get animal data in the form of a string
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
}*/
