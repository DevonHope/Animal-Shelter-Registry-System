#ifndef CLIENT_H
#define CLIENT_H

using namespace std;
#include <string>

class Client {

    public:
        Client(string n, int a, string g, string add, string pnum, string mail, int cl, string ty, string sskill, string food,
               bool clws, bool shd, bool HF, int intel, int ag, int cour, int pl, int stren, int kf, int cs, int ht, int tru,
               int cur, int furLen, int fR, int iR, int aR, int cR, int pR, int sR, int kFR, int commR, int hR, int tR, int cuR,
               int skR, int clR, bool eA, int hSize, int ySize);
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

        int getFurRank() const;
        int getIntRank() const;
        int getAggroRank() const;
        int getCourageRank() const;
        int getPlayRank() const;
        int getStrRank() const;
        int getKFRank() const; //kid friendly
        int getCSkillRank() const; //commskills
        int getHTrainedRank() const; //house trained
        int getTrustRank() const;
        int getCuriosityRank() const;
        int getSkillRank() const;
        int getClimateRank() const;

        bool getExerciseAccessibility() const;
        int getHouseSize() const;
        int getYardSize() const;

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

        void setFurRank(int);
        void setIntRank(int);
        void setAggroRank(int);
        void setCourageRank(int);
        void setPlayRank(int);
        void setStrRank(int);
        void setKFRank(int); //kid friendly
        void setCSkillRank(int); //commskills
        void setHTrainedRank(int); //house trained
        void setTrustRank(int);
        void setCuriosityRank(int);
        void setClimateRank(int);

        void setExerciseAccessibility(bool);
        void setHouseSize(int);
        void setYardSize(int);

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

        //ranks
        int furRank;
        int intRank;
        int aggroRank;
        int courageRank;
        int playRank;
        int strRank;
        int kidFriendlyRank;
        int commRank;
        int houseRank;
        int trustRank;
        int curiosityRank;
        int skillRank;
        int climateRank;

        //profile question answers
        bool exerciseAccessibility;
        int houseSize;
        int yardSize;

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
