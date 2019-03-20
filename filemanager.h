#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "animal.h"
#include "client.h"
#include <QDialog>

class FileManager
{

public:
    FileManager();
    void saveAnimal(Animal a, QString fileName, QWidget *parent);
    void saveAnimalAs(Animal a, QWidget *parent);
    void saveClient(Client c, QString fileName, QWidget *parent);
    void saveClientAs(Client c, QWidget *parent);
    void deleteFile(QString fileName, QWidget *parent);
};

#endif // FILEMANAGER_H
