
#include "Person.h"

class GraphEL
{
private:

	vector<pair<Person, Person>> graph;
	int _size;
	int _numFriends;

public:
	
	GraphEL(int size, int numFriends, Person source);
	void insertEdge(Person from, Person to);
	int getLevelEL(Person x, Person source);
	vector<vector<pair<string, int>>> friendsBFS(Person source, string p, string m, string n);
	vector<vector<pair<string, int>>> friendsDFS(Person source, string p, string m, string n);
	void printPath(Person source, Person dest);
};
