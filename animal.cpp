#include "animal.h"
using namespace std;

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

