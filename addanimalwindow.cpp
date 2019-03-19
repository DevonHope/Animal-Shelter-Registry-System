#include "addanimalwindow.h"
#include "ui_addanimalwindow.h"
#include "animal.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDirIterator>
#include <QtWidgets>
#include <string>

AddAnimalWIndow::AddAnimalWIndow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAnimalWIndow)
{
    ui->setupUi(this);
}

/* Collects all data from the field of the form and
 * creates an animal object from them. THat object
 * is then saved to a flat file
 * */
void AddAnimalWIndow::on_addButton_clicked()
{
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
    QString specialSkill = ui->skillText->toPlainText();

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
        fm.saveAnimalAs(a); //Save constructed animal to file
        this->destroy(); //Close Window
    }
}

/*
 * Returns the user back to the main window; does not save a new animal
 */
void AddAnimalWIndow::on_cancelButton_clicked()
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

/*
 * Used to prevent both male and female being checked at the same time.
 */
void AddAnimalWIndow::on_maleCheck_clicked()
{
    ui->femaleCheck->setChecked(false);
}

/*
 * Used to prevent both male and female being checked at the same time.
 */
void AddAnimalWIndow::on_femaleCheck_clicked()
{
    ui->maleCheck->setChecked(false);
}

AddAnimalWIndow::~AddAnimalWIndow()
{
    delete ui;
}
