#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;
#include <string>

class Animal
{
    public:
        Animal(string n, int a, string b, string t, int w, int fl, int cp, bool c, bool sh, bool hs, string g, string co, string ff, int in, int ag, int cour, int pl, int stren, string specs, int kf, int cs, int ht, int cu, int tst);
        ~Animal();
        string toString() const;

        //getters

        string getName() const;
        int getAge() const;
        string getBreed() const;
        string getType() const;
        int getWeight() const;
        bool getHasFur() const;
        int getClimatePref() const;
        bool getClaws() const;
        bool getSheds() const;
        string getGender() const;
        string getColour() const;
        string getFF() const; //favfood
        int getIntell() const;
        int getAggro() const;
        int getCourage() const;
        int getPlay() const;
        int getStrength() const;
        string getSSkill() const;
        int getKF() const; // kidfriendly
        int getCSkill() const; //commskills
        int getHTrained() const; // house trained
        int getTrust() const;
        int getCuriosity() const;
        int getFurLength() const;

        //setters
        void setName(string);
        void setAge(int);
        void setBreed(string);
        void setType(string);
        void setWeight(int);
        void setHasFur(bool);
        void setClimatePref(int);
        void setClaws(bool);
        void setSheds(bool);
        void setGender(string);
        void setColour(string);
        void setfavFood(string);
        void setIntell(int);
        void setAggro(int);
        void setCourage(int);
        void setPlay(int);
        void setStrength(int);
        void setspecSkill(string);
        void setkidFriendly(int);
        void setcommSkill(int);
        void sethouseTrained(int);
        void setTrust(int);
        void setCuriosity(int);
        void setFurLength(int);


    private:
        string name;
        int age;
        int weight;
        string type;
        string gender;
        string colour;
        string breed;
        bool hasFur;
        int climatePref;
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
        int furLength;

};


#endif // ANIMAL_H
