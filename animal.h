#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;
#include <string>

class Animal
{
    public:
        Animal(string="", int=0, string="", string="", int = 0, int = 0, string="", bool=false, bool=false, string="", string ="");
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
        ~Animal();

        //setters
        void setName(string);
        void setAge(int);
        void setBreed(string);
        void setType(string);
        void setWeight(int);
        void setFurLength(int);
        void setClimatePref(string);
        void setClaws(bool);
        void setSheds(bool);
        void setGender(string);
        void setColour(string);


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
