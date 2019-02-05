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

string Animal::toString() const {
    ostringstream out;

    out << getName() << "\n";
    out << getAge() << "\n";
    out << getBreed() << "\n";
    out << getType() << "\n";

    return out.str();

}


