#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "animal.h"
#include "client.h"
#include <QDialog>
#include <string>

/*
 * A struct to contain the animal class and its corresponding
 * file name where its information is stored.
 */
struct animalNode {
    Animal *storedAnimal;
    string animalFileName;
};

/*
 * A struct to contain the client class and its corresponding
 * file name where its information is stored.
 */
struct clientNode {
    Client *storedClient;
    string clientFileName;
};

class FileManager
{

public:
    FileManager(QWidget *parent = 0);
    void startUp();
    void initAnimals();
    void initClients();
    animalNode* getAnimals();
    clientNode* getClients();
    int getNumAnimals();
    int getNumClients();
    void refreshAnimals();
    void refreshClients();
    void saveAnimal(Animal a, QString fileName, QWidget *parent);
    void saveAnimalAs(Animal a, QWidget *parent);
    void saveClient(Client c, QString fileName, QWidget *parent);
    void saveClientAs(Client c, QWidget *parent);
    void deleteFile(QString fileName, QWidget *parent);

private:
    animalNode *listOfAnimals;
    clientNode *listOfClients;
    int animalTracker;
    int clientTracker;
    QWidget *par;
};

#endif // FILEMANAGER_H
