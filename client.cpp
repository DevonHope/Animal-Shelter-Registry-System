#include "client.h"

using namespace std;
#include <sstream>
#include <iostream>

Client:: Client(string n, int a, string g, string add, string pnum, string mail, int cl, string ty, string sskill, string food,
                bool clws, bool shd, bool HF, int intel, int ag, int cour, int pl, int stren, int kf, int cs, int ht, int tru,
                int cur, int furLen, int fR, int iR, int aR, int cR, int pR, int sR, int kFR, int commR, int hR, int tR, int cuR,
                int skR, int clR, bool eA, int hSize, int ySize)
{
    name = n;
    age = a;
    gender = g;
    address = add;
    climate = cl;
    pNumber = pnum;
    eMail = mail;
    type = ty;
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
    furLength = furLen;
    hasFur = HF;
    furRank = fR;
    intRank = iR;
    aggroRank = aR;
    courageRank = cR;
    playRank = pR;
    strRank = sR;
    kidFriendlyRank = kFR;
    commRank = commR;
    houseRank = hR;
    trustRank = tR;
    curiosityRank = cuR;
    skillRank = skR;
    climateRank = clR;
    exerciseAccessibility = eA;
    houseSize = hSize;
    yardSize = ySize;
}

Client::~Client(){}

string Client::getName() const {return name;}
int Client::getAge() const {return age;}
string Client::getAddress() const {return address;}
string Client::getPNum() const {return pNumber;}
int Client::getClimate() const{ return climate;}
string Client::getGender() const{return gender;}
string Client::getMail() const {return eMail;}

string Client::getType() const {return type;}
bool Client::getHasFur() const{return hasFur;}
bool Client::getClaws() const{return claws;}
bool Client::getSheds() const{ return sheds;}
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
int Client::getFurLen() const{return furLength;}

int Client::getFurRank() const {return furRank;}
int Client::getIntRank() const {return intRank;}
int Client::getAggroRank() const {return aggroRank;}
int Client::getCourageRank() const {return courageRank;}
int Client::getPlayRank() const {return playRank;}
int Client::getStrRank() const {return strRank;}
int Client::getKFRank() const {return kidFriendlyRank;} //kid friendly
int Client::getCSkillRank() const {return commRank;} //commskills
int Client::getHTrainedRank() const {return houseRank;} //house trained
int Client::getTrustRank() const {return trustRank;}
int Client::getCuriosityRank() const {return curiosityRank;}
int Client::getSkillRank() const {return skillRank;}
int Client::getClimateRank() const {return climateRank;}

bool Client::getExerciseAccessibility() const {return exerciseAccessibility;}
int Client::getHouseSize() const {return houseSize;}
int Client::getYardSize() const {return yardSize;}

//setters
void Client::setName(string s){name = s;}
void Client::setAge(int d){age = d;}
void Client::setAddress(string add) {address = add;}
void Client::setPNum(string d) {pNumber = d;}
void Client::setClimate(int s){  climate = s;}
void Client::setGender(string s){gender = s;}
void Client::setMail(string m){eMail = m;}
void Client::setHasFur(int s){ hasFur = s;}
void Client::setClaws(bool b){ claws = b;}
void Client::setSheds(bool b){ sheds = b;}
void Client::setBreed(string s){breed = s;}
void Client::setType(string s){type = s;}
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
void Client::setFurLen(int len){furLength = len;}

void Client::setFurRank(int i){furRank = i;}
void Client::getIntRank(int i){intRank = i;}
void Client::getAggroRank(int i){aggroRank = i;}
void Client::getCourageRank(int i){courageRank = i;}
void Client::getPlayRank(int i){playRank = i;}
void Client::getStrRank(int i){strRank = i;}
void Client::getKFRank(int i){kidFriendlyRank = i;} //kid friendly
void Client::getCSkillRank(int i){commRank = i;} //commskills
void Client::getHTrainedRank(int i){houseRank = i;} //house trained
void Client::getTrustRank(int i){trustRank = i;}
void Client::getCuriosityRank(int i){curiosityRank = i;}
void Client::getSkillRank(int i){skillRank = i;}
void Client::getClimateRank(int i){climateRank = i;}

void Client::getExerciseAccessibility(bool b){exerciseAccessibility = b;}
void Client::getHouseSize(int i){houseSize = i;}
void Client::getYardSize(int i){yardSize = i;}

string Client::toString() const{
    ostringstream out;

    out << getName() << "\n";
    out << getAge() << "\n";
    out << getAddress() << "\n";
    out << getPNum() << "\n";
    out << getMail() << "\n";
    out << getClimate() << "\n";
    out << getGender() << "\n";
    out << getType() << "\n";
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
    out << getFurLen() << "\n";
    out << getFurRank() << "\n";
    out << getIntRank() << "\n";
    out << getAggroRank() << "\n";
    out << getCourageRank() << "\n";
    out << getPlayRank() << "\n";
    out << getStrRank() << "\n";
    out << getKFRank() << "\n"; //kid friendly
    out << getCSkillRank() << "\n"; //commskills
    out << getHTrainedRank() << "\n"; //house trained
    out << getTrustRank() << "\n";
    out << getCuriosityRank() << "\n";
    out << getSkillRank() << "\n";
    out << getClimateRank() << "\n";
    out << getExerciseAccessibility() << "\n";
    out << getHouseSize() << "\n";
    out << getYardSize() << "\n";

    return out.str();
}
