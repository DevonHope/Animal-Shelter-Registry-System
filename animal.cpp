#include "animal.h"
using namespace std;
#include <sstream>
#include <iostream>

Animal::Animal(string n, int a, string b, string t, int w, bool fl, string cp, bool c, bool sh, string g, string co)
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
}

/*
Animal::Animal(string n, int a, string b, string t, int w, int fl, string cp, bool c, bool sh, string g, string co, string ff, int in, int ag, int cour, int pl, int stren, string specs, int kf, int cs, int ht, int cu){

}

  */
Animal::~Animal()
{
    name = "";
    age = 0;
    breed = "";
    type = "";
    weight = 0;
    hasFur = false;
    climatePref = "";
    claws = false;
    sheds = false;
    gender = "";
    colour = "";
}

string Animal::getName() const {
    return name;
}

int Animal::getAge() const {
    return age;
}

string Animal::getBreed() const {
    return breed;
}

string Animal::getType() const {
    return type;
}

int Animal::getWeight() const{
    return weight;
}

bool Animal::getHasFur() const{
    return hasFur;
}

string Animal::getClimatePref() const{
    return climatePref;
}

bool Animal::getClaws() const{
    return claws;
}

bool Animal::getSheds() const{
    return sheds;
}

string Animal::getGender() const{
    return gender;
}

string Animal::getColour() const{
    return colour;
}

//setters
void Animal::setWeight(int s){
    weight = s;
}

void Animal::setHasFur(int s){
    hasFur = s;
}

void Animal::setClimatePref(string s){
    climatePref = s;
}

void Animal::setClaws(bool b){
    claws = b;
}

void Animal::setSheds(bool b){
    sheds = b;
}

void Animal::setName(string s){
    name = s;
}

void Animal::setAge(int d){
    age = d;
}

void Animal::setBreed(string s){
    breed = s;
}

void Animal::setType(string s){
    type = s;
}

void Animal::setGender(string s){
    gender = s;
}

void Animal::setColour(string s){
    colour = s;
}

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

    return out.str();

}


