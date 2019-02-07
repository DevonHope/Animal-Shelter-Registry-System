#include "animal.h"
using namespace std;
#include <sstream>
#include <iostream>

Animal::Animal(string n, int a, string b, string t, int w, int fL, string cP, bool cl, bool sh, string g, string col)
{
    name = n;
    age = a;
    breed = b;
    type = t;
    weight = w;
    furLength = fL;
    climatePref = cP;
    claws = cl;
    sheds = sh;
    gender = g;
    colour = col;
}

Animal::~Animal(){

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

int Animal::getFurLength() const{
    return furLength;
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

void Animal::setFurLength(int s){
    furLength = s;
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
    out << getAge() << "\n";
    out << getBreed() << "\n";
    out << getType() << "\n";

    return out.str();

}


