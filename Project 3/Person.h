#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <fstream>
#include <random>

using namespace std;

class Person
{

private:

	int ID;
	string name;
	string personality;
	string music;
	string nationality;
	int level = -1;

public:

	int getID();
	string getName();
	string getPersonality();
	string getMusic();
	string getNationality();
	int getLevel();
	void setLevel(int l);
	
	void printInfo();
	Person() {

	}
	Person(string name, string personality, string music, string nationality, int id);

	friend bool operator== (const Person& p1, const Person& p2)
	{
		return (p1.ID == p2.ID);
	}
	friend bool operator!= (const Person& p1, const Person& p2)
	{
		return !(p1.ID == p2.ID);
	}
	friend bool operator> (const Person& p1, const Person& p2)
	{
		return (p1.ID > p2.ID);
	}
	friend bool operator< (const Person& p1, const Person& p2)
	{
		return (p1.ID < p2.ID);
	}
};



