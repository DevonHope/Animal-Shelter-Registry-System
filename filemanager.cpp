#include "filemanager.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QObject>
#include <QString>
#include <QDirIterator>
#include <QObject>
#include <QtWidgets>
#include <string>


FileManager::FileManager(QWidget *parent)
{
    par = parent;
}

void FileManager::startUp() {

    listOfAnimals = new animalNode[50];
    animalTracker = 0;

    listOfClients = new clientNode[50];
    clientTracker = 0;

    QString storagePath = QDir::currentPath() + "/Animals/";

    //If project was executed for the first time, create a folder containing 25 animals from persistent storage in the build folder
    //and set their permissions to Read-Write for future use.
    if (!QDir(storagePath).exists()) {
        QDir().mkdir("Animals");

        QFile::copy(":/memstorage/AnimalClient Files/Animal/A-Brain.txt", storagePath + "A-Brain.txt");
        QFile(storagePath + "A-Brain.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/A-Gary.txt", storagePath + "A-Gary.txt");
        QFile(storagePath + "A-Gary.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/A-Stitch.txt", storagePath + "A-Stitch.txt");
        QFile(storagePath + "A-Stitch.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/A-Pikachu.txt", storagePath + "A-Pikachu.txt");
        QFile(storagePath + "A-Pikachu.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Garfield.txt", storagePath + "Garfield.txt");
        QFile(storagePath + "Garfield.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Astro.txt", storagePath + "Astro.txt");
        QFile(storagePath + "Astro.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Beethoven.txt", storagePath + "Beethoven.txt");
        QFile(storagePath + "Beethoven.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Black_Beauty.txt", storagePath + "Black_Beauty.txt");
        QFile(storagePath + "Black_Beauty.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Clifford.txt", storagePath + "Clifford.txt");
        QFile(storagePath + "Clifford.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Courage.txt", storagePath + "Courage.txt");
        QFile(storagePath + "Courage.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Dino.txt", storagePath + "Dino.txt");
        QFile(storagePath + "Dino.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Ein.txt", storagePath + "Ein.txt");
        QFile(storagePath + "Ein.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Hobbes.txt", storagePath + "Hobbes.txt");
        QFile(storagePath + "Hobbes.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Marcel.txt", storagePath + "Marcel.txt");
        QFile(storagePath + "Marcel.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Marmaduke.txt", storagePath + "Marmaduke.txt");
        QFile(storagePath + "Marmaduke.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Nibbler.txt", storagePath + "Nibbler.txt");
        QFile(storagePath + "Nibbler.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Perry.txt", storagePath + "Perry.txt");
        QFile(storagePath + "Perry.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Rocky.txt", storagePath + "Rocky.txt");
        QFile(storagePath + "Rocky.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/RubyBunny.txt", storagePath + "RubyBunny.txt");
        QFile(storagePath + "RubyBunny.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Scooby.txt", storagePath + "Scooby.txt");
        QFile(storagePath + "Scooby.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Seymour.txt", storagePath + "Seymour.txt");
        QFile(storagePath + "Seymour.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Snellie.txt", storagePath + "Snellie.txt");
        QFile(storagePath + "Snellie.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Snoopy.txt", storagePath + "Snoopy.txt");
        QFile(storagePath + "Snoopy.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Stuart.txt", storagePath + "Stuart.txt");
        QFile(storagePath + "Stuart.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Animal/Zoboomafoo.txt", storagePath + "Zoboomafoo.txt");
        QFile(storagePath + "Zoboomafoo.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
    }

    QString storagePath2 = QDir::currentPath() + "/Clients/";

    //If project was executed for the first time, create a folder containing 20 clients from persistent storage in the build folder
    if (!QDir(storagePath2).exists()) {
        QDir().mkdir("Clients");

        QFile::copy(":/memstorage/AnimalClient Files/Client/Andy.txt", storagePath2 + "Andy.txt");
        QFile(storagePath2 + "Andy.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Client/Andrew.txt", storagePath2 + "Andrew.txt");
        QFile(storagePath2 + "Andrew.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Client/Devon.txt", storagePath2 + "Devon.txt");
        QFile(storagePath2 + "Devon.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Client/Hamza.txt", storagePath2 + "Hamza.txt");
        QFile(storagePath2 + "Hamza.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Client/Robert.txt", storagePath2 + "Robert.txt");
        QFile(storagePath2 + "Robert.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Client/Craig.txt", storagePath2 + "Craig.txt");
        QFile(storagePath2 + "Craig.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Client/Dean.txt", storagePath2 + "Dean.txt");
        QFile(storagePath2 + "Dean.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Client/Ashley.txt", storagePath2 + "Ashley.txt");
        QFile(storagePath2 + "Ashley.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

        QFile::copy(":/memstorage/AnimalClient Files/Client/Bev.txt", storagePath2 + "Bev.txt");
        QFile(storagePath2 + "Bev.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

        QFile::copy(":/memstorage/AnimalClient Files/Client/DDuck.txt", storagePath2 + "DDuck.txt");
        QFile(storagePath2 + "DDuck.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

        QFile::copy(":/memstorage/AnimalClient Files/Client/George.txt", storagePath2 + "George.txt");
        QFile(storagePath2 + "George.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

        QFile::copy(":/memstorage/AnimalClient Files/Client/Flora.txt", storagePath2 + "Flora.txt");
        QFile(storagePath2 + "Flora.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

        QFile::copy(":/memstorage/AnimalClient Files/Client/Jason.txt", storagePath2 + "Jason.txt");
        QFile(storagePath2 + "Jason.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

        QFile::copy(":/memstorage/AnimalClient Files/Client/Lou.txt", storagePath2 + "Lou.txt");
        QFile(storagePath2 + "Lou.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

        QFile::copy(":/memstorage/AnimalClient Files/Client/Shania.txt", storagePath2 + "Shania.txt");
        QFile(storagePath2 + "Shania.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

        QFile::copy(":/memstorage/AnimalClient Files/Client/Skittle.txt", storagePath2 + "Skittle.txt");
        QFile(storagePath2 + "Skittle.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

        QFile::copy(":/memstorage/AnimalClient Files/Client/Spottagus.txt", storagePath2 + "Spottagus.txt");
        QFile(storagePath2 + "Spottagus.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

        QFile::copy(":/memstorage/AnimalClient Files/Client/Steven.txt", storagePath2 + "Steven.txt");
        QFile(storagePath2 + "Steven.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

        QFile::copy(":/memstorage/AnimalClient Files/Client/Thor.txt", storagePath2 + "Thor.txt");
        QFile(storagePath2 + "Thor.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        QFile::copy(":/memstorage/AnimalClient Files/Client/Vent.txt", storagePath2 + "Vent.txt");
        QFile(storagePath2 + "Vent.txt").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
    }

    initAnimals();
    initClients();
}

animalNode* FileManager::getAnimals() {
    return listOfAnimals;
}

clientNode* FileManager::getClients() {
    return listOfClients;
}

int FileManager::getNumAnimals() {
    return animalTracker;
}

int FileManager::getNumClients() {
    return clientTracker;
}


/*
 * Loads all animals from storage into the program
 */
void FileManager::initAnimals() {

    int i = 0; //Counter for how many animals were allocated for later accessing of current animals in the array

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
            int climatePref = 0;
            bool claws = false;
            bool sheds = false;
            string gender = "";
            string colour = "";
            string favFood = "";
            int intell = 0;
            int aggro = 0;
            int courage = 0;
            int play = 0;
            int strength = 0;
            string specSkill = "";
            int kidFriendly = 0;
            int commSkill = 0;
            int houseTrained = 0;
            int trust = 0;
            int curiosity = 0;
            int furLength = 0;

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
                      climatePref = in.readLine().toInt();
                else if (count == 8) {
                        QString c = in.readLine();
                          if (c == 'Y' || c == '1')
                            claws = true;
                          else
                              claws = false;

                }
                else if (count == 9) {
                    QString s = in.readLine();
                          if (s == 'Y' || s == '1')
                            sheds = true;
                          else
                             sheds = false;
                }
                else if (count == 10) {
                    QString f = in.readLine();
                    if (f == 'Y' || f == '1')
                      hasFur = true;
                    else
                      hasFur = false;
                }
                else if (count == 11)
                    favFood = in.readLine().toStdString();
                else if (count == 12)
                    intell = in.readLine().toInt();
                else if (count == 13)
                    aggro = in.readLine().toInt();
                else if (count == 14)
                    courage = in.readLine().toInt();
                else if (count == 15)
                    play = in.readLine().toInt();
                else if (count == 16)
                    strength = in.readLine().toInt();
                else if (count == 17)
                    specSkill = in.readLine().toStdString();
                else if (count == 18)
                    kidFriendly = in.readLine().toInt();
                else if (count == 19)
                    commSkill = in.readLine().toInt();
                else if (count == 20)
                    houseTrained = in.readLine().toInt();
                else if (count == 21)
                    trust = in.readLine().toInt();
                else if (count == 22)
                    curiosity = in.readLine().toInt();
                else if (count == 23)
                    furLength = in.readLine().toInt();
                else
                    break;

                /*It supposedly reaches the end of the file, but this break statement is there to ensure the
                 * while loop does not infinitely loop */

                count++;
            }
            file.close();

            Animal *animal = new Animal(name.toStdString(), age, breed, type,
                                        weight, furLength, climatePref, claws, sheds, hasFur,
                                        gender, colour, favFood, intell, aggro, courage, play,
                                        strength, specSkill, kidFriendly, commSkill, houseTrained, curiosity, trust);

            listOfAnimals[i].storedAnimal = animal;
            listOfAnimals[i].animalFileName = filename.toStdString();

            i++;
            animalTracker = i;

        }
        else {
            QString str = "Could not open " + filename + "!";
            switch( QMessageBox::question(
                            par,
                            QObject::tr("ERROR"),
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

    }
}

/*
 * Loads all clients from storage into the program
 */
void FileManager::initClients() {

    int i = 0; //Counter for how many clients were allocated for later accessing of current clients in the array

    QDir dir(QDir::currentPath() + "/Clients/");
    QStringList files = dir.entryList(QStringList() << "*.txt", QDir::Files);
    foreach(QString filename, files) { //It generates a string list of the directory continaing all the text files, iterating through each of the files obtaining their filenames
        QFile file(QDir::currentPath() + "/Clients/" + filename);

        if (file.open(QIODevice::ReadOnly)) {

            QTextStream in(&file);
            int count = 0; //Indicates what # the line is

            //Variables for constructing client object with their basic info
            QString name = "";
            int age = 0;
            string address = "";
            string pNum = "";
            string email = "";
            string gender = "";
            string type = "";
            bool claws = false;
            bool sheds = false;
            bool hasFur = false;
            int intell = 0;
            int aggro = 0;
            int cour = 0;
            int play = 0;
            int stren = 0;
            string favFood = "";
            string specSkill = "";
            int kidFriendly = 0;
            int commSkills = 0;
            int houseTrained = 0;
            int trust = 0;
            int curiosity = 0;
            int furLen = 0;
            int climate = 0;
            int furRank = 0;
            int intRank = 0;
            int aggroRank = 0;
            int courageRank = 0;
            int playRank = 0;
            int strRank = 0;
            int kidFriendlyRank = 0;
            int commRank = 0;
            int houseRank = 0;
            int trustRank = 0;
            int curiosityRank = 0;
            int skillRank = 0;
            int climateRank = 0;
            bool exerciseAccessibility = false;
            int houseSize = 0;
            int yardSize = 0;



            //Reads each line of the client file and each line corresponds to each respective basic info of the client, plus sets it to it's corresponding variable
            while(!in.atEnd()) {
                if (count == 0)
                    name = in.readLine();
                else if (count == 1)
                    age = in.readLine().toInt();
                else if (count == 2)
                    address = in.readLine().toStdString();
                else if (count == 3)
                    pNum = in.readLine().toStdString();
                else if (count == 4)
                    email = in.readLine().toStdString();
                else if (count == 5)
                     gender = in.readLine().toStdString();
                else if (count == 6)
                      type = in.readLine().toStdString();
                else if (count == 7) {
                        QString c = in.readLine();
                          if (c == 'Y' || c == '1')
                            claws = true;
                          else
                              claws = false;

                }
                else if (count == 8) {
                    QString s = in.readLine();
                          if (s == 'Y' || s == '1')
                            sheds = true;
                          else
                             sheds = false;
                }
                else if (count == 9) {
                    QString f = in.readLine();
                    if (f == 'Y' || f == '1')
                      hasFur = true;
                    else
                      hasFur = false;
                }
                else if (count == 10)
                    favFood = in.readLine().toStdString();
                else if (count == 11)
                    intell = in.readLine().toInt();
                else if (count == 12)
                    aggro = in.readLine().toInt();
                else if (count == 13)
                    cour = in.readLine().toInt();
                else if (count == 14)
                    play = in.readLine().toInt();
                else if (count == 15)
                    stren = in.readLine().toInt();
                else if (count == 16)
                    specSkill = in.readLine().toStdString();
                else if (count == 17)
                    kidFriendly = in.readLine().toInt();
                else if (count == 18)
                    commSkills = in.readLine().toInt();
                else if (count == 19)
                    houseTrained = in.readLine().toInt();
                else if (count == 20)
                    trust = in.readLine().toInt();
                else if (count == 21)
                    curiosity = in.readLine().toInt();
                else if (count == 22)
                    furLen = in.readLine().toInt();
                else if (count == 23)
                    climate = in.readLine().toInt();
                else if (count == 24)
                    furRank = in.readLine().toInt();
                else if (count == 25)
                    intRank = in.readLine().toInt();
                else if (count == 26)
                    aggroRank = in.readLine().toInt();
                else if (count == 27)
                    courageRank = in.readLine().toInt();
                else if (count == 28)
                    playRank = in.readLine().toInt();
                else if (count == 29)
                    strRank = in.readLine().toInt();
                else if (count == 30)
                    kidFriendlyRank = in.readLine().toInt();
                else if (count == 31)
                    commRank = in.readLine().toInt();
                else if (count == 32)
                    houseRank = in.readLine().toInt();
                else if (count == 33)
                    trustRank = in.readLine().toInt();
                else if (count == 34)
                    curiosityRank = in.readLine().toInt();
                else if (count == 35)
                    climateRank = in.readLine().toInt();
                else if (count == 36)
                    skillRank = in.readLine().toInt();
                else if (count == 37) {
                        QString eA = in.readLine();
                          if (eA == 'Y' || eA == '1')
                            exerciseAccessibility = true;
                          else
                            exerciseAccessibility = false;
                }
                else if (count == 38)
                    houseSize = in.readLine().toInt();
                else if (count == 39)
                    yardSize = in.readLine().toInt();
                else
                    break;

                /*It supposedly reaches the end of the file, but this break statement is there to ensure the
                 * while loop does not infinitely loop */

                count++;
            }
            file.close();

            Client *client = new Client(name.toStdString(), age, gender, address, pNum, email, type, specSkill, favFood, claws, sheds, hasFur, intell, aggro,
                                        cour, play, stren, kidFriendly, commSkills, houseTrained, trust, curiosity, furLen, climate, furRank, intRank, aggroRank,
                                        courageRank, playRank, strRank, kidFriendlyRank, commRank, houseRank, trustRank, curiosityRank, climateRank, skillRank,
                                        exerciseAccessibility, houseSize, yardSize);

            listOfClients[i].storedClient = client;
            listOfClients[i].clientFileName = filename.toStdString();

            i++;
            clientTracker = i;
        }
        else {
            QString str = "Could not open " + filename + "!";
            switch( QMessageBox::question(
                            par,
                            QObject::tr("ERROR"),
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

    }
}


void FileManager::saveAnimal(Animal a, QString fileName, QWidget *parent){
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
                        parent,
                        QObject::tr("Application Name"),
                        QObject::tr("Save was successful."),
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
                        parent,
                        QObject::tr("Application Name"),
                        QObject::tr("Save may have failed!"),
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

void FileManager::saveAnimalAs(Animal a, QWidget *parent){
    //Get file name from user
    QString fileName = QFileDialog::getSaveFileName(parent,
           QObject::tr("Save Text Document"), "",
           QObject::tr("Plain Text (*.txt);;All Files (*)"));

    saveAnimal(a, fileName, parent);
}

void FileManager::saveClient(Client c, QString fileName, QWidget *parent){
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
                        parent,
                        QObject::tr("Application Name"),
                        QObject::tr("Save was successful."),
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
                        parent,
                        QObject::tr("Application Name"),
                        QObject::tr("Save may have failed!"),
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

void FileManager::saveClientAs(Client c, QWidget *parent){
    //Get file name from user
    QString fileName = QFileDialog::getSaveFileName(parent,
           QObject::tr("Save Text Document"), "",
           QObject::tr("Plain Text (*.txt);;All Files (*)"));

    saveClient(c, fileName, parent);
}

void FileManager::deleteFile(QString fileName, QWidget *parent){
    bool confirm = false;
    switch( QMessageBox::question(
                parent,
                QObject::tr("Application Name"),
                QObject::tr("Are you sure you want to delete this file? All data within it will be lost."),
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

/*
 * Refreshes the physical list of animals from storage, to be used
 * in the case of additions and deletions.
 */
void FileManager::refreshAnimals() {
    delete [] listOfAnimals;

    listOfAnimals = new animalNode[50];
    animalTracker = 0;

    initAnimals();
}

/*
 * Refreshes the physical list of clients from storage, to be used
 * in the case of additions and deletions.
 */
void FileManager::refreshClients() {
    delete [] listOfClients;

    listOfClients = new clientNode[50];
    clientTracker = 0;

    initClients();
}
