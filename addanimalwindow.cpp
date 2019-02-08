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

void AddAnimalWIndow::on_addButton_clicked()
{
    bool validAnimal = true;
    QString name = ui->nameText->toPlainText();

    QString ageString = ui->ageText->toPlainText();
    int age = ageString.toInt();
    if(age == 0){
        validAnimal = false;
        switch( QMessageBox::question(this, tr("Error"), tr("Age is not valid"), QMessageBox::Ok, QMessageBox::Ok ) )
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
    if(weight == 0){
        validAnimal = false;
        switch( QMessageBox::question(this, tr("Error"), tr("Weight is not valid"), QMessageBox::Ok, QMessageBox::Ok ) )
        {
            case QMessageBox::Ok:
                break;
            default:
                break;
        }
    }

    bool hasFur = ui->furCheck->isChecked();
    QString climatePref = ui->climateText->toPlainText();
    bool claws = ui->clawsCheck->isChecked();
    bool sheds = ui->shedsCheck->isChecked();

    QString gender;
    if(ui->maleCheck->isChecked()){
        gender = "Male";
    } else if (ui->femaleCheck->isChecked()){
        gender = "Female";
    } else{
        validAnimal = false;
        switch( QMessageBox::question(this, tr("Error"), tr("Please check a gender"), QMessageBox::Ok, QMessageBox::Ok ) )
        {
            case QMessageBox::Ok:
                break;
            default:
                break;
        }
    }

    QString colour = ui->colourText->toPlainText();

    if(validAnimal){
        Animal a(name.toStdString(), age, breed.toStdString(), type.toStdString(), weight, hasFur,
                 climatePref.toStdString(), claws, sheds, gender.toStdString(), colour.toStdString());
        saveAs(a);
        this->destroy();
    }
}

void AddAnimalWIndow::saveAs(Animal a){
    QString fileName = QFileDialog::getSaveFileName(this,
           tr("Save Text Document"), "",
           tr("Plain Text (*.txt);;All Files (*)"));

    if(!(fileName.endsWith(".txt"))){
        fileName += ".txt";
    }

    if(!(fileName.isEmpty())){
        QFile file(fileName);
        file.open(QFile::WriteOnly|QFile::Truncate);
        file.close();
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            QString data = QString::fromStdString(a.toString());
            stream << data << endl;
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
        } else {
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
        this->destroy();
    }
}

void AddAnimalWIndow::on_maleCheck_clicked()
{
    ui->femaleCheck->setChecked(false);
}

void AddAnimalWIndow::on_femaleCheck_clicked()
{
    ui->maleCheck->setChecked(false);
}

AddAnimalWIndow::~AddAnimalWIndow()
{
    delete ui;
}
