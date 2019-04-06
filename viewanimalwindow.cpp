#include "viewanimalwindow.h"
#include "ui_viewanimalwindow.h"
#include "animal.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDirIterator>
#include <QtWidgets>

ViewAnimalWindow::ViewAnimalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewAnimalWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Profile Information");
}

/*
 * Sets the UI fields to the values contained within
 * the animal object.
 */
void ViewAnimalWindow::fillProfileInfo(Animal a) {

    //Set fields to read only so they cannot be modified by user
    ui->nameText->setReadOnly(true);
    ui->ageText->setReadOnly(true);
    ui->breedText->setReadOnly(true);
    ui->typeText->setReadOnly(true);
    ui->colourText->setReadOnly(true);
    ui->weightText->setReadOnly(true);
    ui->specialSkillText->setReadOnly(true);
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

    //Display specific animal information from the object
    ui->nameText->setPlainText(QString::fromStdString(a.getName()));
    ui->ageText->setPlainText(QString::number(a.getAge()));
    ui->breedText->setPlainText(QString::fromStdString(a.getBreed()));
    ui->typeText->setPlainText(QString::fromStdString(a.getType()));
    ui->colourText->setPlainText(QString::fromStdString(a.getColour()));
    ui->weightText->setPlainText(QString::number(a.getWeight()));
    ui->specialSkillText->setPlainText(QString::fromStdString(a.getSSkill()));
    ui->favFoodText->setPlainText(QString::fromStdString(a.getFF()));

    ui->intSlider->setValue(a.getIntell());
    ui->climateSlider->setValue(a.getClimatePref());
    ui->aggressivenessSlider->setValue(a.getAggro());
    ui->courageSlider->setValue(a.getCourage());
    ui->playfulSlider->setValue(a.getPlay());
    ui->strSlider->setValue(a.getStrength());
    ui->kidFriendlySlider->setValue(a.getKF());
    ui->commSlider->setValue(a.getCSkill());
    ui->houseTrainedSlider->setValue(a.getHTrained());
    ui->curiositySlider->setValue(a.getCuriosity());
    ui->trustSlider->setValue(a.getTrust());
    ui->furLenSlider->setValue(a.getFurLength());
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
}


ViewAnimalWindow::~ViewAnimalWindow()
{
    delete ui;
}

/*
 * Deletes the animal being viewed from the file system, it will
 * remain loaded in until the user refreshes the animal list.
 */
void ViewAnimalWindow::on_deleteButton_clicked()
{
    QString storagePath = QDir::currentPath() + "/Animals/";
    fm.deleteFile(storagePath + fName, this);
    this->destroy(); //Close window
}

void ViewAnimalWindow::selectedFileName(QString f) {
    fName = f;
}

void ViewAnimalWindow::disableDeleteButton() {
    ui->deleteButton->setEnabled(false);
}

void ViewAnimalWindow::disableEditButton() {
    ui->editButton->setEnabled(false);
}

void ViewAnimalWindow::on_cancelButton_clicked()
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

void ViewAnimalWindow::on_editButton_clicked()
{
    if(isEditing == false){
        isEditing = true;
        ui->label->setText("Editing Mode");
        ui->editButton->setText("Confirm");
        
        //Enable all UI elements to edit
        ui->nameText->setReadOnly(false);
        ui->ageText->setReadOnly(false);
        ui->breedText->setReadOnly(false);
        ui->typeText->setReadOnly(false);
        ui->colourText->setReadOnly(false);
        ui->weightText->setReadOnly(false);
        ui->specialSkillText->setReadOnly(false);
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
        
        ui->maleCheck->setEnabled(true);
        ui->femaleCheck->setEnabled(true);
        ui->furCheck->setEnabled(true);
        ui->clawsCheck->setEnabled(true);
        ui->shedsCheck->setEnabled(true);
        
    } else { //Save edits
        isEditing = false;
        ui->label->setText("Reading Mode");
        ui->editButton->setText("Edit");

        bool validAnimal = true;

        //Retrive data from UI
        QString name = ui->nameText->toPlainText();

        QString ageString = ui->ageText->toPlainText();
        int age = ageString.toInt();
        if(age == 0){ //toInt returns 0 if the string is not an integer number
            validAnimal = false; //Not a valid animal (does not save)
            switch( QMessageBox::question(this, tr("Error"), tr("Age is not valid, please enter a non-zero number"), QMessageBox::Ok, QMessageBox::Ok ) )
            {
                case QMessageBox::Ok:
                    break;
                default:
                    break;
            }
        }

        QString type = ui->typeText->toPlainText();
        QString breed = ui->breedText->toPlainText();

        QString weightString = ui->weightText->toPlainText();
        int weight = weightString.toInt();
        if(weight == 0){ //toInt returns 0 if the string is not an integer number
            validAnimal = false; //Not a valid animal (does not save)
            switch( QMessageBox::question(this, tr("Error"), tr("Weight is not valid, please enter a non-zero number"), QMessageBox::Ok, QMessageBox::Ok ) )
            {
                case QMessageBox::Ok:
                    break;
                default:
                    break;
            }
        }

        bool hasFur = ui->furCheck->isChecked();
        int climatePref = ui->climateSlider->sliderPosition();
        bool claws = ui->clawsCheck->isChecked();
        bool sheds = ui->shedsCheck->isChecked();

        QString gender;
        if(ui->maleCheck->isChecked()){
            gender = "Male";
        } else if (ui->femaleCheck->isChecked()){
            gender = "Female";
        } else{ //Neither is selected
            validAnimal = false; //Not a valid animal (does not save)
            switch( QMessageBox::question(this, tr("Error"), tr("Please check a gender"), QMessageBox::Ok, QMessageBox::Ok ) )
            {
                case QMessageBox::Ok:
                    break;
                default:
                    break;
            }
        }

        QString colour = ui->colourText->toPlainText();
        QString favFood = ui->favFoodText->toPlainText();
        QString specialSkill = ui->specialSkillText->toPlainText();

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

        if(validAnimal){ //Valid Animal
            Animal a(name.toStdString(), age, breed.toStdString(), type.toStdString(), weight, furLength,
                     climatePref, claws, sheds, hasFur, gender.toStdString(), colour.toStdString(),
                     favFood.toStdString(), intelligence, aggressiveness, courage, playfulness, strength,
                     specialSkill.toStdString(), kidFriendly, commSkills, houseTrained, curiosity, trust); //Construct animal
            QString storagePath = QDir::currentPath() + "/Animals/";
            fm.saveAnimal(a, storagePath + fName, this); //Save constructed animal

            //Disable all UI elements to edit
            ui->nameText->setReadOnly(true);
            ui->ageText->setReadOnly(true);
            ui->breedText->setReadOnly(true);
            ui->typeText->setReadOnly(true);
            ui->colourText->setReadOnly(true);
            ui->weightText->setReadOnly(true);
            ui->specialSkillText->setReadOnly(true);
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

            ui->maleCheck->setEnabled(false);
            ui->femaleCheck->setEnabled(false);
            ui->furCheck->setEnabled(false);
            ui->clawsCheck->setEnabled(false);
            ui->shedsCheck->setEnabled(false);
        }
    }
}
