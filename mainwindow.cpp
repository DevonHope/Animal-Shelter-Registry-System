#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "viewanimalwindow.h"
#include "ui_viewanimalwindow.h"
#include "addanimalwindow.h"
#include "ui_addanimalwindow.h"
#include "viewclientwindow.h"
#include "ui_viewclientwindow.h"
#include "addclientwindow.h"
#include "ui_addclientwindow.h"

#include "animal.h"
#include "client.h"
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
    fm.startUp();

    ui->setupUi(this);
    initAnimals();
    initClients();

    currentUser = "Staff";
    ui->label_3->setText("Current User: Staff");

    ui->staffButton->setDisabled(true);

    ui->clientDropDown->setDisabled(false);
    ui->scrollArea_3->setDisabled(false);
    ui->addAnimalButton->setDisabled(false);
    ui->addClientButton->setDisabled(false);

    for(int i = 0; i < fm.getNumClients(); i++) {
        QString name = QString::fromStdString((fm.getClients()[i]).storedClient->getName());
        ui->clientDropDown->addItem(name);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Loads all animals from storage into the program
 */
void MainWindow::initAnimals() {


    //Deletes all the widgets (buttons containing the animal names) in the scrolling area layout
    ui->scrollArea_2->takeWidget();
   QLayoutItem* item;
    while ( ( item = ui->verticalLayout_2->layout()->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }

    for(int i = 0; i < fm.getNumAnimals(); i++) {
            QString name = QString::fromStdString((fm.getAnimals()[i]).storedAnimal->getName());
            QPushButton *button = new QPushButton(name, this);
            button->setStyleSheet("height: 25px");
            connect(button, SIGNAL(clicked()), this, SLOT(showAnimalProfile())); //Connect each button to view animal ui form
            ui->verticalLayout_2->addWidget(button); //Add button to the scrolling area layout
    }

        ui->scrollArea_2->setWidget(ui->verticalLayoutWidget_2);
}

/*
 * Loads all clients from storage into the program
 */
void MainWindow::initClients() {

    //Deletes all the widgets (buttons containing the client names) in the scrolling area layout
    ui->scrollArea_3->takeWidget();
   QLayoutItem* item;
    while ( ( item = ui->verticalLayout_4->layout()->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }

    for(int i = 0; i < fm.getNumClients(); i++) {
            QString name = QString::fromStdString((fm.getClients()[i]).storedClient->getName());
            QPushButton *button = new QPushButton(name, this);
            button->setObjectName(name);
            button->setStyleSheet("height: 25px");
            connect(button, SIGNAL(clicked()), this, SLOT(showClientProfile())); //Connect each button to view client ui form
            ui->verticalLayout_4->addWidget(button); //Add button to the scrolling area layout

        ui->scrollArea_3->setWidget(ui->verticalLayoutWidget_4);
    }

    /* Loading all clients again makes them not disabled, so this is to ensure that only the current client can view their own profile */
    if (currentUser != "Staff" && currentUser != "") {
        qDebug() << QString::fromStdString(currentUser);
        onlyViewLoggedInClient(currentUser);
    }
}

/*
 * Refreshes the list of animals, to be used
 * in the case of additions and deletions.
 */
void MainWindow::refreshAnimals() {
    fm.refreshAnimals();
    initAnimals();
}

/*
 * Refreshes the list of clients, to be used
 * in the case of additions and deletions.
 */
void MainWindow::refreshClients() {

    fm.refreshClients();
    initClients();
}

void MainWindow::onlyViewLoggedInClient(string name) {
    for(int i = 0; i < fm.getNumClients(); i++) {
        if (ui->verticalLayout_4->itemAt(i)->widget()->objectName() != QString::fromStdString(name))
            ui->verticalLayout_4->itemAt(i)->widget()->setDisabled(true);
        else
            ui->verticalLayout_4->itemAt(i)->widget()->setDisabled(false);
    }
}

/*
 * Opens up a new window that is used to view a specific
 * animal's information.
 */
void MainWindow::showAnimalProfile() {

    for(int i = 0; i < fm.getNumAnimals(); i++) {

        if (((QPushButton*)sender())->text().toStdString() == (fm.getAnimals()[i]).storedAnimal->getName()) {
            ViewAnimalWindow viewAnim;

            Animal a = *((fm.getAnimals()[i]).storedAnimal);
            viewAnim.fillProfileInfo(a);
            viewAnim.selectedFileName(QString::fromStdString((fm.getAnimals()[i]).animalFileName));

            if (currentUser != "Staff" && currentUser != "") //Clients cannot delete animals, so if current user is a client then disable the delete button when viewing an animal
                viewAnim.disableDeleteButton();

            viewAnim.setModal(true);
            viewAnim.exec();
        }
    }

}

/*
 * Opens up a new window that is used to view a specific
 * client's information.
 */
void MainWindow::showClientProfile() {

    for(int i = 0; i < fm.getNumClients(); i++) {

        if (((QPushButton*)sender())->text().toStdString() == (fm.getClients()[i]).storedClient->getName()) {
            ViewClientWindow viewCln;

            Client c = *((fm.getClients()[i]).storedClient);
            viewCln.fillProfileInfo(c);
            viewCln.selectedFileName(QString::fromStdString((fm.getClients()[i]).clientFileName));

            viewCln.setModal(true);
            viewCln.exec();
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
 * Opens up the addClientWindow which will
 * be used to add clients to the list.
 */
void MainWindow::on_addClientButton_clicked()
{
    AddClientWindow addCln;
    addCln.setModal(true);
    addCln.exec();
}

/*
 * Refreshes the list of animals.
 */
void MainWindow::on_refreshAnimalsButton_clicked()
{
    refreshAnimals();
}

/*
 * Refreshes the list of clients.
 */
void MainWindow::on_refreshClientsButton_clicked()
{
    refreshClients();
}

// Enables set user privelleges for being a staff
void MainWindow::on_staffButton_clicked()
{
    currentUser = "Staff";
    ui->label_3->setText("Current User: Staff");

    ui->staffButton->setDisabled(true);

    ui->scrollArea_3->setDisabled(false); //Enabled viewing detailed info of animals
    ui->addAnimalButton->setDisabled(false);
    ui->addClientButton->setDisabled(false);

    //Enables all the client buttons again
    for(int i = 0; i<fm.getNumClients(); i++)
         ui->verticalLayout_4->itemAt(i)->widget()->setDisabled(false);

}



void MainWindow::on_clientDropDown_activated(int index)
{
    currentUser = (fm.getClients()[index]).storedClient->getName();
    ui->label_3->setText("Current User: " + QString::fromStdString(currentUser));

    ui->addAnimalButton->setDisabled(true);
    ui->addClientButton->setDisabled(true);
    ui->scrollArea_3->setDisabled(false);

    ui->staffButton->setDisabled(false);

    onlyViewLoggedInClient(currentUser);
}
