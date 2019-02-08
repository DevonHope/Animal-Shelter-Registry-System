#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "viewanimalwindow.h"
#include "ui_viewanimalwindow.h"

#include "animal.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDirIterator>
#include <QtWidgets>
#include <string>
using namespace std;

struct animalNode {
    Animal *storedAnimal;
    string animalFileName;
};

animalNode *nodes = new animalNode[30];
int arrTracker = 0;

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

    //QDir dir(":/memstorage/AnimalClient Files/Animal/");
    QDir dir(QDir::currentPath() + "/Animals/");
    QStringList files = dir.entryList(QStringList() << "*.txt", QDir::Files);
    foreach(QString filename, files) {
        //QFile file(":/memstorage/AnimalClient Files/Animal/" + filename);
        QFile file(QDir::currentPath() + "/Animals/" + filename);
        if (file.open(QIODevice::ReadOnly)) {

            QTextStream in(&file);
            int count = 0;

            QString name = "";
            int age = 0;
            string breed = "";
            string type = "";
            int weight = 0;
            bool hasFur = false;
            string climatePref = "";
            bool claws = false;
            bool sheds = false;
            string gender = "";
            string colour = "";

            while(!in.atEnd()) {
                if (count == 0)
                    name = in.readLine();
                else if (count == 1)
                    type = in.readLine().toStdString();
                else if (count == 2)
                    breed = in.readLine().toStdString();
                else if (count == 3)
                     gender = in.readLine().toStdString();
                else if (count == 4)
                    age = in.readLine().toInt();         
                else if (count == 5)
                      colour = in.readLine().toStdString();
                else if (count == 6)
                      weight = in.readLine().toInt();
                else if (count == 7)
                      climatePref = in.readLine().toStdString();
                else if (count == 8) {
                          if (in.readLine() == 'Y')
                            claws = true;
                          else
                              claws = false;

                }
                else if (count == 9) {
                          if (in.readLine() == 'Y')
                            sheds = true;
                          else
                             sheds = false;
                }
                else if (count == 10) {
                    if (in.readLine() == 'Y')
                      hasFur = true;
                    else
                      hasFur = false;
                }
                else
                    break;

                count++;
            }
            file.close();

            Animal *animal = new Animal(name.toStdString(), age, breed, type,
                                        weight, hasFur, climatePref, claws, sheds,
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
    }
}

void MainWindow::refreshAnimals() {
    delete [] nodes;

    nodes = new animalNode[30];
    arrTracker = 0;

    initAnimals();
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
    bool confirm = false;
       QString fileName;
       QString text;

       switch( QMessageBox::question(
                   this,
                   tr("Application Name"),
                   tr("Are you sure you want to load? Any unsaved data may be lost."),
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

       fileName = QFileDialog::getOpenFileName(this,
              tr("Load Text Document"), "",
              tr("Plain Text (*.txt);;All Files (*)"));

       if(confirm == true){
           QFile file(fileName);
           if (file.open(QIODevice::ReadWrite)) {
               QTextStream stream(&file);
               text = stream.readAll();     //For project we will be using readLine()
               ui->textEdit->setText(text);
               switch( QMessageBox::question(
                           this,
                           tr("Application Name"),
                           tr("Load was successful."),
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


void MainWindow::showProfile() {

    for(int i = 0; i < arrTracker; i++) {

        if (((QPushButton*)sender())->text().toStdString() == nodes[i].storedAnimal->getName()) {
            ViewAnimalWindow viewAnim;

            Animal a = *(nodes[i].storedAnimal);
            viewAnim.fillProfileInfo(a);

            viewAnim.setModal(true);
            viewAnim.exec();


        }
    }
}
