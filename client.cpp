#include "client.h"

using namespace std;
#include <sstream>
#include <iostream>

Client::Client(string n, int a, string g, string add, string pnum, string mail, string ty, string sskill, string food, bool clws, bool shd, bool HF, int intel, int ag, int cour, int pl, int stren, int kf, int cs, int ht, int tru, int cur, int furLen, int cl, int fR, int iR, int aR, int cR, int pR, int sR,
               int kFR, int commR, int hR, int tR, int cuR, int skR, int clR, bool eA, int hSize, int ySize)
{
    name = n;
    age = a;
    gender = g;
    address = add;
    climate = cl;
    pNumber = pnum;
    eMail = mail;
    type = ty;
    favFood = food;
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

/*
Client::Client()
{
    name = "";
    age = 0;
    gender = "";
    address = "";
    climate = 0;
    pNumber = "";
    eMail = "";
    type = "";
    favFood = "";
    claws = false;
    sheds = false;
    intell = 0;
    aggro = 0;
    courage = 0;
    play = 0;
    strength = 0;
    specialSkill = "";
    kidFriendly = 0;
    commSkills = 0;
    houseTrained = 0;
    trust = 0;
    curiosity = 0;
    furLength = 0;
    hasFur = false;
    furRank = 0;
    intRank = 0;
    aggroRank = 0;
    courageRank = 0;
    playRank = 0;
    strRank = 0;
    kidFriendlyRank = 0;
    commRank = 0;
    houseRank = 0;
    trustRank = 0;
    curiosityRank = 0;
    skillRank = 0;
    climateRank = 0;
    exerciseAccessibility = false;
    houseSize = 0;
    yardSize = 0;
}*/

Client::~Client(){}

string Client::getName() const {return name;}
int Client::getAge() const {return age;}
string Client::getAddress() const {return address;}
string Client::getPNum() const {return pNumber;}
int Client::getClimate() const{ return climate;}
string Client::getGender() const{return gender;}
string Client::getMail() const {return eMail;}

string Client::getType() const {return type;}
string Client::getFavFood() const {return favFood;}
bool Client::getHasFur() const{return hasFur;}
bool Client::getClaws() const{return claws;}
bool Client::getSheds() const{ return sheds;}
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
void Client::setType(string s){type = s;}
void Client::setFavFood(string f){favFood = f;}
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
void Client::setIntRank(int i){intRank = i;}
void Client::setAggroRank(int i){aggroRank = i;}
void Client::setCourageRank(int i){courageRank = i;}
void Client::setPlayRank(int i){playRank = i;}
void Client::setStrRank(int i){strRank = i;}
void Client::setKFRank(int i){kidFriendlyRank = i;} //kid friendly
void Client::setCSkillRank(int i){commRank = i;} //commskills
void Client::setHTrainedRank(int i){houseRank = i;} //house trained
void Client::setTrustRank(int i){trustRank = i;}
void Client::setCuriosityRank(int i){curiosityRank = i;}
void Client::setSkillRank(int i){skillRank = i;}
void Client::setClimateRank(int i){climateRank = i;}

void Client::setExerciseAccessibility(bool b){exerciseAccessibility = b;}
void Client::setHouseSize(int i){houseSize = i;}
void Client::setYardSize(int i){yardSize = i;}

string Client::toString() const{
    ostringstream out;

    out << getName() << "\n";
    out << getAge() << "\n";
    out << getAddress() << "\n";
    out << getPNum() << "\n";
    out << getMail() << "\n";
    out << getGender() << "\n";
    out << getType() << "\n";
    out <<getFavFood() << "\n";
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
    out << getClimate() << "\n";
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
