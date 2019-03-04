#include "animal.h"
using namespace std;
#include <sstream>
#include <iostream>

Animal::Animal(string n, int a, string b, string t, int w, int fl, string cp, bool c, bool sh, string g, string co, string ff, int in, int ag, int cour, int pl, int stren, string specs, int kf, int cs, int ht, int cu)
{
    name = n;
    age = a;
    breed = b;
    type = t;
    weight = w;
    hasFur = fl;
    climatePref = cp;
    claws = c;
    sheds = sh;
    gender = g;
    colour = co;
    favFood = ff;
    intell = in; 
    aggro = ag;
    courage = cour; 
    play = pl; 
    strength = stren;
    specialSkill = specs;
    kidFriendly = kf;
    commSkills = cs;
    houseTrained = ht; 
    curiosity = cu;
}

Animal::~Animal(){}

string Animal::getName() const {return name;}

int Animal::getAge() const {return age;}

string Animal::getBreed() const {return breed;}

string Animal::getType() const {return type;}

int Animal::getWeight() const{return weight;}

bool Animal::getHasFur() const{return hasFur;}

string Animal::getClimatePref() const{ return climatePref;}

bool Animal::getClaws() const{return claws;}

bool Animal::getSheds() const{ return sheds;}

string Animal::getGender() const{return gender;}

string Animal::getColour() const{return colour;}

//favfood
string Animal::getFF() const {return favFood;}

int Animal::getIntell() const{return intell;}

int Animal::getAggro() const{return aggro;}

int Animal::getCourage() const{ return courage;}

int Animal::getPlay() const{return play;}

int Animal::getStrength() const{ return strength;}

string Animal::getSSkill() const{ return specialSkill;}

// kidfriendly
int Animal::getKF() const { return kidFriendly;}

//commskills
int Animal::getCSkill() const {return commSkills;}

// house trained
int Animal::getHTrained() const {return houseTrained;}

int Animal::getTrust() const{ return trust;} 

int Animal::getCuriosity() const{  return curiosity;}

//setters
void Animal::setWeight(int s){weight = s;}
void Animal::setHasFur(int s){ hasFur = s;}
void Animal::setClimatePref(string s){  climatePref = s;}
void Animal::setClaws(bool b){ claws = b;}
void Animal::setSheds(bool b){ sheds = b;}
void Animal::setName(string s){name = s;}
void Animal::setAge(int d){age = d;}
void Animal::setBreed(string s){breed = s;}
void Animal::setType(string s){type = s;}
void Animal::setGender(string s){gender = s;}
void Animal::setColour(string s){colour = s;}
void Animal::setfavFood(string ff){favFood = ff;}
void Animal::setIntell(int intel){intell = intel;}
void Animal::setAggro(int ag){aggro = ag;}
void Animal::setCourage(int cou){courage = cou;}
void Animal::setPlay(int pl){play = pl;}
void Animal::setStrength(int stre){strength = stre;}
void Animal::setspecSkill(string sskill){specialSkill = sskill;}
void Animal::setkidFriendly(int kf) {kidFriendly = kf;}
void Animal::setcommSkill(int cs){commSkills = cs;}
void Animal::sethouseTrained(int ht){houseTrained = ht;}
void Animal::setTrust(int tru){trust = tru;}
void Animal::setCuriosity(int cur){curiosity = cur;}

string Animal::toString() const {
    ostringstream out;

    out << getName() << "\n";
    out << getType() << "\n";
    out << getBreed() << "\n";
    out << getGender() << "\n";
    out << getAge() << "\n";
    out << getColour() << "\n";
    out << getWeight() << "\n";
    out << getClimatePref() << "\n";
    out << getClaws() << "\n";
    out << getSheds() << "\n";
    out << getHasFur() << "\n";
    out << getFF() << "\n";
    out << getIntell() << "\n";
    out << getAggro() << "\n";
    out << getCourage() << "\n";
    out << getPlay() << "\n";
    out << getStrength() << "\n";
    out << getSSkill() << "\n";
    out << getKF() << "\n";
    out << getCSkill() << "\n";
    out << getHTrained() << "\n";
    out << getTrust() << "\n";
    out << getCuriosity() << "\n";

    return out.str();

}
