#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "animal.h"
#include "client.h"
#include <QDialog>

class FileManager
{
public:
    FileManager();
    void saveAnimal(Animal a, QString fileName);
    void saveAnimalAs(Animal a);
    void saveClient(Client c, QString fileName);
    void saveClientAs(Client c);
    void deleteFile(QString fileName);
};

#endif // FILEMANAGER_H
