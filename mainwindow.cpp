#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animal.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDirIterator>
#include <QtWidgets>
#include <string>
using namespace std;

bool animalSelected = false;

MainWindow::animalNode nodes[30];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initAnimals();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initAnimals() {

    int i = 0;

    //Deletes all the widgets in the 2nd layout
    ui->scrollArea_2->takeWidget();
   QLayoutItem* item;
    while ( ( item = ui->verticalLayout_2->layout()->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }

    QDir dir(QDir::currentPath() + "/Animals/");
    QStringList files = dir.entryList(QStringList() << "*.txt", QDir::Files);
    foreach(QString filename, files) {

        QFile file(QDir::currentPath() + "/Animals/" + filename);
        if (file.open(QIODevice::ReadOnly)) {

            QTextStream in(&file);
            int count = 0;

            QString name = "";
            int age = 0;
            string breed = "";
            string type = "";
            int weight = 0;
            int furLength = 0;
            string climatePref = "";
            bool claws = false;
            bool sheds = false;
            string gender = "";
            string colour = "";

            while(!in.atEnd()) {
                if (count == 0)
                    name = in.readLine();
                else if (count == 1)
                    age = in.readLine().toInt();
                else if (count == 2)
                    breed = in.readLine().toStdString();
                else if (count == 3)
                     type = in.readLine().toStdString();
                else if (count == 4)
                      weight = in.readLine().toInt();
                else if (count == 5)
                      furLength = in.readLine().toInt();
                else if (count == 6)
                      climatePref = in.readLine().toStdString();
                else if (count == 7) {
                      if (in.readLine() == 'Y')
                        claws = true;
                      else
                          claws = false;
                 }
                else if (count == 8) {
                    if (in.readLine() == 'Y')
                      sheds = true;
                    else
                       sheds = false;
                }
                else if (count == 9)
                      gender = in.readLine().toStdString();
                else if (count == 10)
                      colour = in.readLine().toStdString();
                count++;
            }
            file.close();

            Animal *animal = new Animal(name.toStdString(), age, breed, type,
                                        weight, furLength, climatePref, claws, sheds,
                                        gender, colour);

            nodes[i].storedAnimal = animal;
            nodes[i].animalFileName = filename.toStdString();

            QPushButton *button = new QPushButton(name, this);
            button->setStyleSheet("height: 25px");
            connect(button, SIGNAL(clicked()), this, SLOT(showProfile()));
            ui->verticalLayout_2->addWidget(button);

            i++;
            arrTracker = i;

        }
        else {
            QString str = "Could not open " + filename + "!";
            switch( QMessageBox::question(
                            this,
                            tr("ERROR"),
                            str,

                            QMessageBox::Ok,

                            QMessageBox::Ok ) )
                {
                    case QMessageBox::Ok:
                        break;
                    default:
                        break;
                }
        }

        ui->scrollArea_2->setWidget(ui->verticalLayoutWidget_2);
        //QDir::setCurrent("/home/student/build-untitled-Desktop-Debug/untitled");
    }
}

void MainWindow::on_lockButton_clicked()
{
    //ui->textEdit->setEnabled(false);
    ui->textEdit->setReadOnly(true);
    ui->modeLabel->setText("READ ONLY");

}

void MainWindow::on_unlockButton_clicked()
{
    //ui->textEdit->setEnabled(true);
    ui->textEdit->setReadOnly(false);
     ui->modeLabel->setText("EDITING");
}

void MainWindow::on_saveButton_clicked()
{
    ui->saveButton->setEnabled(false);
        QString txt = ui->textEdit->toPlainText();
        bool confirm = false;


        QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Profile"), "",
            tr("Profile (*.txt);;All Files (*)"));

        if (!fileName.isEmpty()) {

            fileName = fileName + ".txt";
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }
            else {
                confirm = true;
                QTextStream stream(&file);
                stream << txt << endl;
            }
           }

        if (confirm) {
            ui->textEdit->setText("");
            switch( QMessageBox::question(
                                    this,
                                    tr("Application Name"),
                                    tr("Profile has been saved in the system!"),

                                    QMessageBox::Ok,

                                    QMessageBox::Ok ) )
                        {
                            case QMessageBox::Ok:
                                break;
                            default:
                                break;
                        }
        }
        /*switch( QMessageBox::question(
                        this,
                        tr("Application Name"),
                        tr("Are you sure you want to save?"),

                        QMessageBox::Cancel |
                        QMessageBox::Ok,

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
        QString filename = "TestDataForAndy.txt";
        QFile file(filename);
        file.open(QFile::WriteOnly|QFile::Truncate);
        file.close();

        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << txt << endl;

            switch( QMessageBox::question(
                            this,
                            tr("Message"),
                            tr("Save has completed successfully!!"),

                            QMessageBox::Ok,

                            QMessageBox::Ok ) )
                {
                    case QMessageBox::Ok:
                        break;
                    default:
                        break;
                }
        }
        else {
            switch( QMessageBox::question(
                            this,
                            tr("Message"),
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

        }*/




    ui->saveButton->setEnabled(true);
}

void MainWindow::on_loadButton_clicked()
{

}

void MainWindow::on_getAnimalsButton_clicked()
{
    int i = 0;

    ui->scrollArea_2->takeWidget();
    //Deletes all the widgets in the 2nd layout
   QLayoutItem* item;
    while ( ( item = ui->verticalLayout_2->layout()->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }

    QDir dir(QDir::currentPath());
    QStringList files = dir.entryList(QStringList() << "*.txt", QDir::Files);
    foreach(QString filename, files) {

        QFile file(filename);

        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);
            int count = 0;

            QString name = "";
            int age = 0;
            string breed = "";
            string type = "";

            while(!in.atEnd()) {

                if (count == 0)
                    name = in.readLine();
                else if (count == 1)
                    age = in.readLine().toInt();
                else if (count == 2)
                    breed = in.readLine().toStdString();
                else
                     type = in.readLine().toStdString();
                count++;
            }

            Animal *a = new Animal(name.toStdString(), age, breed, type);



            QPushButton *button = new QPushButton(name, this);
            button->setStyleSheet("height: 30px");
            connect(button, SIGNAL(clicked()), this, SLOT(showProfile()));
            ui->verticalLayout_2->addWidget(button);
        }
        else {
            QString str = "Could not open " + filename + "!";
            switch( QMessageBox::question(
                            this,
                            tr("ERROR"),
                            str,

                            QMessageBox::Ok,

                            QMessageBox::Ok ) )
                {
                    case QMessageBox::Ok:
                        break;
                    default:
                        break;
                }
        }

        ui->scrollArea_2->setWidget(ui->verticalLayoutWidget_2);

    }
}

void MainWindow::showProfile() {

    QMessageBox msg;
    msg.setWindowTitle("Profile Information");
    for(int i = 0; i < arrTracker; i++) {

        if (((QPushButton*)sender())->text().toStdString() == nodes[i].storedAnimal->getName()) {
            msg.setText(((QPushButton*)sender())->text());
            msg.exec();
        }
    }
}
