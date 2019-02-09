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

    //Retrive data from UI
    QString name = ui->nameText->toPlainText();

    QString ageString = ui->ageText->toPlainText();
    int age = ageString.toInt();
    if(age == 0){ //toInt returns 0 if the string is not an integer number
        validAnimal = false; //Not a valid animal (does not save)
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
    if(weight == 0){ //toInt returns 0 if the string is not an integer number
        validAnimal = false; //Not a valid animal (does not save)
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

    if(validAnimal){ //Valid Animal
        Animal a(name.toStdString(), age, breed.toStdString(), type.toStdString(), weight, hasFur,
                 climatePref.toStdString(), claws, sheds, gender.toStdString(), colour.toStdString());
        saveAs(a); //Save constructed animal
        this->destroy(); //Close Window
    }
}

/*
 * Will save the animal input in a text document by
 * utilizing the Animal's toString() function.
 */
void AddAnimalWIndow::saveAs(Animal a){
    //Get file name from user
    QString fileName = QFileDialog::getSaveFileName(this,
           tr("Save Text Document"), "",
           tr("Plain Text (*.txt);;All Files (*)"));

    if(!(fileName.endsWith(".txt"))){
        fileName += ".txt";
    }

    if(!(fileName.isEmpty())){ //Check if a file name was entered
        QFile file(fileName);
        file.open(QFile::WriteOnly|QFile::Truncate); //Clear file contents
        file.close();
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            QString data = QString::fromStdString(a.toString()); //get animal data in the form of a string
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
