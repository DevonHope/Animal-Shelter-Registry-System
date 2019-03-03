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
    ui->climateText->setReadOnly(true);
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

    bool confirm = false;
    QString fileName = fName; //File name is retrieved from the animal node struct

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

}

void ViewAnimalWindow::selectedFileName(QString f) {
    fName = f;
}

void ViewAnimalWindow::disableDeleteButton() {
    ui->deleteButton->setEnabled(false);
}
