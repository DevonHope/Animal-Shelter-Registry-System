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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->scrollArea_2->setWidget(ui->scrollAreaWidgetContents_2);
    //initAnimals();

}

MainWindow::~MainWindow()
{
    delete ui;
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

            arr[i] = a;
            i++;


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

     //qDebug() << ((QPushButton*)sender())->text();

    QMessageBox msg;
    msg.setWindowTitle("Profile Information");
    for(int i = 0; i < 9; i++) {

        if (((QPushButton*)sender())->text().toStdString() == arr[i]->getName()) {
            msg.setText(((QPushButton*)sender())->text());
            msg.exec();
        }
    }
}
