#include "filemanager.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

FileManager::FileManager()
{

}

void FileManager::saveAnimal(Animal a, QString fileName){
    if(!(fileName.isEmpty())){ //Check if a file name was entered
        if(!(fileName.endsWith(".txt"))){
            fileName += ".txt";
        }

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

void FileManager::saveAnimalAs(Animal a){
    //Get file name from user
    QString fileName = QFileDialog::getSaveFileName(this,
           tr("Save Text Document"), "",
           tr("Plain Text (*.txt);;All Files (*)"));

    saveAnimal(a, fileName);
}

void FileManager::saveClient(Client c, QString fileName){
    if(!(fileName.isEmpty())){ //Check if a file name was entered
        if(!(fileName.endsWith(".txt"))){
            fileName += ".txt";
        }

        QFile file(fileName);
        file.open(QFile::WriteOnly|QFile::Truncate); //Clear file contents
        file.close();
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            QString data = QString::fromStdString(c.toString()); //get client data in the form of a string
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

void FileManager::saveClientAs(Client c){
    //Get file name from user
    QString fileName = QFileDialog::getSaveFileName(this,
           tr("Save Text Document"), "",
           tr("Plain Text (*.txt);;All Files (*)"));

    saveClient(c, fileName);
}

void FileManager::deleteFile(QString fileName){
    bool confirm = false;
    switch( QMessageBox::question(
                this,
                tr("Application Name"),
                tr("Are you sure you want to delete this file? All data within it will be lost."),
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

    if (confirm == true) {
        QFile file(fileName);
        file.remove(); //Delete file
    }
}
