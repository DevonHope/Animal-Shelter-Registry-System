#ifndef CLIENT_H
#define CLIENT_H

using namespace std;
#include <string>

class Client {

	public:
		Client(string n, int a, string g, string add, string cl, int pnum, string ty, string bre, bool clws, bool shd, int intel, int ag, int cour, int pl, int stren, string sskill, int kf, int cs, int ht, int tru, int cur, int clen, bool HF);
		~Client();
		string toString() const;
		bool verifyAtt();

		//getters
		string getName() const;
        int getAge() const;
        string getAddress() const;
        int getPNum() const;
        string getBreed() const;
        string getType() const;
        bool getHasFur() const;
        string getClimate() const;
        bool getClaws() const;
        bool getSheds() const;
        string getGender() const;
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

		//setters
		void setName(string);
        void setAge(int);
        void setAddress(string);
        void setPNum(int);
        void setBreed(string);
        void setType(string);
        void setHasFur(int);
        void setClimate(string);
        void setClaws(bool);
        void setSheds(bool);
        void setGender(string);
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

	protected:
		string type;
		string breed;
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
		int clean;
		bool hasFur;

	private:
		string name;
		int age;
		string gender;
		string address;
		string climate;
		int pNumber;
};

#endif // CLIENT_H