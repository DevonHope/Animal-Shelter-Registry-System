#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "viewanimalwindow.h"
#include "ui_viewanimalwindow.h"
#include "addanimalwindow.h"
#include "ui_addanimalwindow.h"

#include "animal.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDirIterator>
#include <QtWidgets>
#include <string>
using namespace std;

/*
 * A struct to contain the animal class and its corresponding
 * file name where its information is stored.
 */
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

/*
 * Loads all animals from storage into the program
 */
void MainWindow::initAnimals() {

    int i = 0; //Counter for how many animals were allocated for later accessing of current animals in the array

    //Deletes all the widgets (buttons containing the animal names) in the scrolling area layout
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
    foreach(QString filename, files) { //It generates a string list of the directory continaing all the text files, iterating through each of the files obtaining their filenames
        //QFile file(":/memstorage/AnimalClient Files/Animal/" + filename);
        QFile file(QDir::currentPath() + "/Animals/" + filename);
        if (file.open(QIODevice::ReadOnly)) {

            QTextStream in(&file);
            int count = 0; //Indicates what # the line is

            //Variables for constructing animal object with their traits
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

            //Reads each line of the animal file and each line corresponds to each respective physical trait of the animal, plus sets it to it's corresponding variable
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

                /*There is no readline calls for non-physical traits which are the other remaining lines. Therefore, this break statement is there in the else statement for the
                 * while loop to not infinitely loop */

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
            connect(button, SIGNAL(clicked()), this, SLOT(showProfile())); //Connect each button to view animal ui form
            ui->verticalLayout_2->addWidget(button); //Add button to the scrolling area layout

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

/*
 * Refreshes the list of animals, to be used
 * in the case of additions and deletions.
 */
void MainWindow::refreshAnimals() {
    delete [] nodes;

    nodes = new animalNode[30];
    arrTracker = 0;

    initAnimals();
}

/*
 * Opens up a new window that is used to view a specific
 * animal's information.
 */
void MainWindow::showProfile() {

    for(int i = 0; i < arrTracker; i++) {

        if (((QPushButton*)sender())->text().toStdString() == nodes[i].storedAnimal->getName()) {
            ViewAnimalWindow viewAnim;

            Animal a = *(nodes[i].storedAnimal);
            viewAnim.fillProfileInfo(a);
            viewAnim.selectedFileName(QString::fromStdString(nodes[i].animalFileName));

            viewAnim.setModal(true);
            viewAnim.exec();
        }
    }
}

/*
 * Opens up the addAnimalWIndow which will
 * be used to add animals to the list.
 */
void MainWindow::on_addAnimalButton_clicked()
{
    AddAnimalWIndow addAnim;
    addAnim.setModal(true);
    addAnim.exec();
}

/*
 * Refreshes the list of animals.
 */
void MainWindow::on_refreshAnimalsButton_clicked()
{
    refreshAnimals();
}
