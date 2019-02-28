#include "client.h"
using namespace std;
#include <sstream>
#include <iostream>

Client::Client(string n, int a, string g, string add, string cl, int pnum, string ty, string bre, bool clws, bool shd, int intel, int ag, int cour, int pl, int stren, string sskill, int kf, int cs, int ht, int tru, int cur, int clen, bool HF){

	name = n;
	age = a;
	gender = g; 
	address = add;
	climate = cl;
	pNumber = pnum;
	type = ty;
	breed = bre;
	claws = clws;
	sheds = shd;
	intell = intel;
	aggro = ag;
	courage = cour;
	play = pl; 
	strength = stren;
	specialSkill = sskill;
	kidFriendly = kf;
	commSkills = cs;
	houseTrained = ht;
	trust = tru;
	curiosity = cur;
	clean = clen;
	hasFur = HF;
}

Client::~Client(){}

string Client::getName() const {return name;}
int Client::getAge() const {return age;}
string Client::getAddress() const {return address;}
int Client::getPNum() const {return pNumber;}
string Client::getBreed() const {return breed;}
string Client::getType() const {return type;}
bool Client::getHasFur() const{return hasFur;}
string Client::getClimate() const{ return climate;}
bool Client::getClaws() const{return claws;}
bool Client::getSheds() const{ return sheds;}
string Client::getGender() const{return gender;}
string Client::getColour() const{return colour;}
int Client::getIntell() const{return intell;}
int Client::getAggro() const{return aggro;}
int Client::getCourage() const{ return courage;}
int Client::getPlay() const{return play;}
int Client::getStrength() const{ return strength;}
string Client::getSSkill() const{ return specialSkill;}
// kidfriendly
int Client::getKF() const { return kidFriendly;}
//commskills
int Client::getCSkill() const {return commSkills;}
// house trained
int Client::getHTrained() const {return houseTrained;}
int Client::getTrust() const{ return trust;} 
int Client::getCuriosity() const{  return curiosity;}

//setters
void Client::setName(string s){name = s;}
void Client::setAge(int d){age = d;}
void Client::setAddress(string add) {address = add;}
void Client::setPNum(int d) {pNumber = d;}
void Client::setHasFur(int s){ hasFur = s;}
void Client::setClimate(string s){  climate = s;}
void Client::setClaws(bool b){ claws = b;}
void Client::setSheds(bool b){ sheds = b;}
void Client::setBreed(string s){breed = s;}
void Client::setType(string s){type = s;}
void Client::setGender(string s){gender = s;}
void Client::setColour(string s){colour = s;}
void Client::setIntell(int intel){intell = intel;}
void Client::setAggro(int ag){aggro = ag;}
void Client::setCourage(int cou){courage = cou;}
void Client::setPlay(int pl){play = pl;}
void Client::setStrength(int stre){strength = stre;}
void Client::setspecSkill(string sskill){specialSkill = sskill;}
void Client::setkidFriendly(int kf) {kidFriendly = kf;}
void Client::setcommSkill(int cs){commSkills = cs;}
void Client::sethouseTrained(int ht){houseTrained = ht;}
void Client::setTrust(int tru){trust = tru;}
void Client::setCuriosity(int cur){curiosity = cur;}

string Client::toString() const{
	ostringstream out;

    out << getName() << "\n";
    out << getAge() << "\n";
    out << getAddress() << "\n";
    out << getPNum() << "\n";
    out << getType() << "\n";
    out << getBreed() << "\n";
    out << getGender() << "\n";
    out << getColour() << "\n";
    out << getClimate() << "\n";
    out << getClaws() << "\n";
    out << getSheds() << "\n";
    out << getHasFur() << "\n";
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
