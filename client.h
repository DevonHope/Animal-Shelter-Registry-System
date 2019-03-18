#ifndef CLIENT_H
#define CLIENT_H

using namespace std;
#include <string>

class Client {

    public:
        Client(string n, int a, string g, string add, string pnum, string mail, int cl, string ty, string sskill, string food, bool clws, bool shd, bool HF, int intel, int ag, int cour, int pl, int stren, int kf, int cs, int ht, int tru, int cur, int furLen);
        ~Client();
        string toString() const;
        bool verifyAtt();


        //getters
        string getName() const;
        int getAge() const;
        string getAddress() const;
        string getPNum() const;
        string getMail() const;
        int getClimate() const;
        string getGender() const;


        string getType() const;
        bool getHasFur() const;
        bool getClaws() const;
        bool getSheds() const;
        string getColour() const;
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
        int getFurLen() const;

        //setters
        void setName(string);
        void setAge(int);
        void setAddress(string);
        void setPNum(string);
        void setMail(string);
        void setClimate(int);
        void setGender(string);

        void setType(string);
        void setHasFur(int);
        void setClaws(bool);
        void setSheds(bool);
        void setColour(string);
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
        void setFurLen(int);

    protected:
        string type;
        bool claws;
        bool sheds;
        bool hasFur;
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

    private:
        string name;
        int age;
        string gender;
        string address;
        int climate;
        string pNumber;
        string eMail;
};

#endif // CLIENT_H
