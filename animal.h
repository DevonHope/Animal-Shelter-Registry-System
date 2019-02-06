#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;
#include <string>

class Animal
{
    public:
        Animal(string="", int=0, string="", string="");
        string toString() const;
        string getName() const;
        int getAge() const;
        string getBreed() const;
        string getType() const;
        int getWeight() const;
        int getFurLength() const;
        string getClimatePref() const;
        bool getClaws() const;
        bool getSheds() const;
        string getGender() const;
        string getColour() const;
        string getBreed() const;

        //setters
        string setName(string);
        int setAge(int);
        string setBreed(string);
        string setType(string);
        int setWeight(int);
        int setFurLength(int);
        string setClimatePref(string);
        bool setClaws(bool);
        bool setSheds(bool);
        string setGender(string);
        string setColour(string);
        string setBreed(string);


    private:
        string name;
        int age;
        int weight;
        string type;
        string gender;
        string colour;
        string breed;
        int furLength;
        string climatePref;
        bool claws;
        bool sheds;

    protected:
        string favFood;
        int intell;
        int aggro;
        int courage;
        int play;
        int strength;
        string specialSkill;
        int kidFriendly;
        int commSkills;
        int houseTrained;
        int trust;
        int curiosity;

};



#endif // ANIMAL_H
