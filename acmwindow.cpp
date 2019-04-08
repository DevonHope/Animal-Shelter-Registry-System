#include "acmwindow.h"
#include "ui_acmwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDirIterator>
#include <QtWidgets>
#include <string>

ACMWindow::ACMWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ACMWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ACM Results");
    ui->textBrowser->setReadOnly(true);

    listOfAnimals = new animalMatchNode[50];
    listOfClients = new clientMatchNode[50];
    scoresOfMatches = new scoreNode[50]; //List of potential animal matches with a single client

    fm.startUp(); //It collects the animals and clients objects from their respective files and inserts them into their respective lists

    for(int i = 0; i < fm.getNumAnimals(); i++) {
        listOfAnimals[i].a = fm.getAnimals()[i].storedAnimal;
    }

    for(int i = 0; i < fm.getNumClients(); i++) {
        listOfClients[i].c = fm.getClients()[i].storedClient;
    }



    // Loops through all clients, for each client does a mapping for every animal to find the best match
    for(int i = 0; i < fm.getNumClients(); i++) {
        int numPairings = 0;
        float maxScore = 0; //Used for finding max score through scores list (To find best match)
        string maxAnimal; //Used for finding the name of the best matched animal
        float score = 0; //Used for calculating the score of each pairing of one client to many animals
        Client curC = *(listOfClients[i].c); //Current Client in the algorithm search
        if (listOfClients[i].hasMatch == false) {
            for(int j = 0; j < fm.getNumAnimals(); j++) {
                Animal curA = *(listOfAnimals[j].a); //Current animal in the pairing of the current client
                if (listOfAnimals[j].hasMatch == false) {
                    if (curC.getType() == curA.getType() || curC.getType() == "NA") { //If client's preferred animal type is the same as the current animal's type
                            if (!profileQuestions(curC, curA)) {
                                score = curC.getFurRank()*(calculateResult(curC.getFurLen(), curA.getFurLength())) + curC.getIntRank()*(calculateResult(curC.getIntell(), curA.getIntell())) +
                                        curC.getAggroRank()*(calculateResult(curC.getAggro(), curA.getAggro())) + curC.getCourageRank()*(calculateResult(curC.getCourage(), curA.getCourage())) +
                                         curC.getPlayRank()*(calculateResult(curC.getPlay(), curA.getPlay())) + curC.getStrRank()*(calculateResult(curC.getStrength(), curA.getStrength())) +
                                        curC.getKFRank()*(calculateResult(curC.getKF(), curA.getKF())) + curC.getCSkillRank()*(calculateResult(curC.getCSkill(), curA.getCSkill())) +
                                        curC.getHTrainedRank()*(calculateResult(curC.getHTrained(), curA.getHTrained())) + curC.getTrustRank()*(calculateResult(curC.getTrust(), curA.getTrust())) +
                                        curC.getCuriosityRank()*(calculateResult(curC.getCuriosity(), curA.getCuriosity())) + curC.getClimateRank()*(calculateResult(curC.getClimate(), curA.getClimatePref())) +
                                        curC.getSkillRank()*(calculateResult(curC.getSSkill(), curA.getSSkill())); //Adds each weighting of each attribute to the produced result between the client's pref and animal's NP attribute
                                 score = score/91;
                            }
                    }
                    scoresOfMatches[numPairings].matchScore = score;
                    scoresOfMatches[numPairings].animalIndex = j; //Stores the index of the current animal, which tracks each client with an animal for each pairing
                    numPairings++;
                }
                else
                    continue;
            }
        }
        else
            continue;

        int maxAnimalTracker = 0; //Used for finding the index of the best matched animal
        if (numPairings > 0) {
            maxScore = scoresOfMatches[0].matchScore;
            maxAnimal = fm.getAnimals()[scoresOfMatches[0].animalIndex].storedAnimal->getName();
            maxAnimalTracker = scoresOfMatches[0].animalIndex;
            for(int i = 0; i < numPairings; i++) { //For finding the highest match score
                if (scoresOfMatches[i].matchScore > maxScore) {
                    maxScore = scoresOfMatches[i].matchScore;
                    maxAnimal = fm.getAnimals()[scoresOfMatches[i].animalIndex].storedAnimal->getName();
                    maxAnimalTracker = scoresOfMatches[i].animalIndex;
                }
            }
        }

        if (maxScore <= 0.50) { //If score is lower than 25%, it is deemed not a good match and thus, the client is matched with noone
            listOfClients[i].hasMatch = true;
            listOfClients[i].matchedWith = "NOONE";
        }
        else { //If score is higher than 25%, then that client and animal can't have any more matches and are out of the algorithm search
            listOfClients[i].hasMatch = true;
            listOfClients[i].matchedWith = maxAnimal;
            listOfAnimals[maxAnimalTracker].hasMatch = true;
        }

        //qDebug() << QString::number(maxScore);

        delete [] scoresOfMatches;
        scoresOfMatches = new scoreNode[50];
    }



    for(int i = 0; i < fm.getNumClients(); i++) {
        QString result;

        if (listOfClients[i].hasMatch == true && listOfClients[i].matchedWith != "NOONE") {
             QString clientName = QString::fromStdString(listOfClients[i].c->getName());
             QString animalName = QString::fromStdString(listOfClients[i].matchedWith);

             result = clientName + " [CLIENT]       MATCHED WITH ------>      " + animalName + " [ANIMAL]\n";
             ui->textBrowser->append(result);
        }

    }

}

//Calculates difference between the slider values from client pref and animal NP attribute
int ACMWindow::calculateResult(int c, int a) {
    int diff = 0;

    if (c == 0) //It means client does not have any preference
        return 1;

    else {
        diff = c-a;

        if (diff < 0)
            diff = diff * -1;

        if (diff > 1 && diff < 7)
            return 0.5;
        else if (diff >= 6)
            return 0;
         else
            return 1;
    }
}

//Checks if client's preferred special skill matches animal special skill
int ACMWindow::calculateResult(string c, string a) {
    if (c == a)
        return 2;
    return 1;
}

//Determines if the client has the neccessary enviornment and resources in taking care of the animal
bool ACMWindow::profileQuestions(Client client, Animal animal) {
    bool badMatch = false;

    if (animal.getPlay() >= 5) {
        if (client.getExerciseAccessibility() || client.getHouseSize() >= 5 || client.getYardSize() >= 5)
            badMatch = false;
        else
            badMatch = true;
    }
    else
        badMatch = false;

    return badMatch;
}


ACMWindow::~ACMWindow()
{
    delete [] listOfClients;
    delete [] listOfAnimals;
    delete ui;
}

void ACMWindow::on_cancelButton_clicked()
{
    this->destroy(); //Closes window
}
