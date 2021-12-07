#include "Person.h"

Person::Person(string name, string personality, string music, string nationality, int ID) 
{
    this->name = name;
    this->personality = personality;
    this->music = music;
    this->nationality = nationality;
    this->ID = ID;
}
int Person::getID()
{
    return ID;
}
string Person::getName()
{
    return name;
}
string Person::getPersonality()
{
    return personality;
}
string Person::getMusic()
{
    return music;
}
string Person::getNationality()
{
    return nationality;
}
int Person::getLevel()
{
    return level;
}
void Person::setLevel(int l)
{
    level = l;
}
void Person::printInfo() 
{
    cout << name << "\t" << personality << "\t" << music << "\t" << nationality << "\t" << ID << endl;
}
