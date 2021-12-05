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
using namespace std;

class Person
{
private:
	int ID;
	string name;
	string personality;
	string music;
	string nationality;
	
public:

	int getID();
	string getName();
	string getPersonality();
	string getMusic();
	string getNationality();
	
	void printInfo();
	
	
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

