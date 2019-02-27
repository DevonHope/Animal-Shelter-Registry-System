#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;
#include <string>

class Animal
{
    public:
        Animal(string n, int a, string b, string t, int w, bool fl, string cp, bool c, bool sh, string g, string co, string n, int a, string b, string t, int w, int fl, string cp, bool c, bool sh, string g, string co, string ff, int in, int ag, int cour, int pl, int stren, string specs, int kf, int cs, int ht, int cu);
        ~Animal();

        string toString() const;
        string getName() const;
        int getAge() const;
        string getBreed() const;
        string getType() const;
        int getWeight() const;
        bool getHasFur() const;
        string getClimatePref() const;
        bool getClaws() const;
        bool getSheds() const;
        string getGender() const;
        string getColour() const;

        //setters
        void setName(string);
        void setAge(int);
        void setBreed(string);
        void setType(string);
        void setWeight(int);
        void setHasFur(int);
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
        bool hasFur;
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
