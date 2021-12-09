
#include "Person.h"

class GraphEL
{
	// Edge list representation

private:

	vector<pair<Person, Person>> graph;
	int _size;
	int _numFriends;

public:
	
	GraphEL();
	GraphEL(int size, int numFriends, Person source); // Constructor for creating the graph
	void insertEdge(Person from, Person to);
	int getLevelEL(Person x, Person source);
	vector<vector<pair<Person, int>>> friendsBFS(Person source, string p, string m, string n); // BFS
	vector<vector<pair<Person, int>>> friendsDFS(Person source, string p, string m, string n); // DFS
	void printPath(Person source, Person dest);
	
};

