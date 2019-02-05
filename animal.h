#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;
#include <string>

class Animal
{
    public:
        Animal(string="", int=0, string="", string="");
        string getName() const;
        int getAge() const;
        string getBreed() const;
        string getType() const;
        string toString() const;

    private:
        string name;
        int age;
        string breed;
        string type;
};



#endif // ANIMAL_H
