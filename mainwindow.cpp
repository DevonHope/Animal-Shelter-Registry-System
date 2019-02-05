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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initAnimals();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initAnimals() {


    Animal *b1 = new Animal("Randi", 20, "Russian Terrier", "Dog");
    Animal *b2 = new Animal("Andy", 21, "Bulldog", "Dog");
    Animal *b3 = new Animal("Max", 21, "Great Dane", "Dog");

    QPushButton *button1 = new QPushButton(QString::fromStdString(b1->getName()), this);
    QPushButton *button2 = new QPushButton(QString::fromStdString(b2->getName()), this);
    QPushButton *button3 = new QPushButton(QString::fromStdString(b3->getName()), this);

    button1->setGeometry(QRect(QPoint(100, 100),
    QSize(200, 50)));

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
    //Deletes all the widgets in the 2nd layout
    QLayoutItem* item;
    while ( ( item = ui->formLayout->layout()->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }

    QDir dir("/home/student/build-untitled-Desktop-Debug/Files");
    QStringList files = dir.entryList(QStringList() << "*.txt", QDir::Files);
    foreach(QString filename, files) {

        QFile file(filename);
        QDir::setCurrent("/home/student/build-untitled-Desktop-Debug/Files");

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

            QPushButton *button = new QPushButton(name, this);
            //connect(button, &QPushButton::clicked, this, &MainWindow::viewProfile)
            ui->formLayout->addWidget(button);
            Animal *newAnimal = new Animal(name.toStdString(), age, breed, type);

            animalArr[i] = newAnimal;
            i++;
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
        QDir::setCurrent("/home/student/build-untitled-Desktop-Debug");

    }


}
