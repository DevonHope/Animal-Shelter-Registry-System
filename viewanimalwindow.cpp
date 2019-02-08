#include "viewanimalwindow.h"
#include "ui_viewanimalwindow.h"
#include "animal.h"

ViewAnimalWindow::ViewAnimalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewAnimalWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Profile Information");
}

void ViewAnimalWindow::fillProfileInfo(Animal a) {

    ui->nameText->setReadOnly(true);
    ui->ageText->setReadOnly(true);
    ui->breedText->setReadOnly(true);
    ui->typeText->setReadOnly(true);
    ui->climateText->setReadOnly(true);
    ui->colourText->setReadOnly(true);
    ui->weightText->setReadOnly(true);

    ui->nameText->setPlainText(QString::fromStdString(a.getName()));
    ui->ageText->setPlainText(QString::number(a.getAge()));
    ui->breedText->setPlainText(QString::fromStdString(a.getBreed()));
    ui->typeText->setPlainText(QString::fromStdString(a.getType()));
    ui->climateText->setPlainText(QString::fromStdString(a.getClimatePref()));
    ui->colourText->setPlainText(QString::fromStdString(a.getClimatePref()));
    ui->weightText->setPlainText(QString::number(a.getWeight()));

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