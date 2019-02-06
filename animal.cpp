#include "animal.h"
using namespace std;
#include <sstream>
#include <iostream>

Animal::Animal(string n, int a, string b, string t)
{
    name = n;
    age = a;
    breed = b;
    type = t;
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

string Animal::getBreed() const{
    return breed;
}

//setters
int Animal::setWeight(int s){
    weight = s;
}

int Animal::setFurLength(int s){
    furLength = s;
}

string Animal::setClimatePref(string s){
    climatePref = s;
}

bool Animal::setClaws(bool b){
    claws = b;
}

bool Animal::setSheds(bool b){
    sheds = b;
}

string Animal::setName(string s){
    name = s;
}

int Animal::setAge(int d){
    age = d;
}

string Animal::setBreed(string s){
    breed = s;
}

string Animal::setType(string s){
    type = s;
}

string Animal::setGender(string s){
    gender = s;
}

string Animal::setColour(string s){
    colour = s;
}

string Animal::setBreed(string s){
    breed = s;
}

string Animal::toString() const {
    ostringstream out;

    out << getName() << "\n";
    out << getAge() << "\n";
    out << getBreed() << "\n";
    out << getType() << "\n";

    return out.str();

}


