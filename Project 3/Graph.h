
#include "GraphEL.h"
#include "Person.h"


class Graph
{

private:

	map<Person, set<Person>> graph;
	int _size;
	int _numFriends;

public:
	 
	Graph(int size, int numFriends, Person source);

	void insertEdge(Person from, Person to);
	set<Person> getAdjacent(Person vertex);
	int getLevel(Person x, Person src);
	vector<vector<pair<Person, int>>> findFriendsBFS(Person source, string p, string m, string n);
	vector<vector<pair<string, int>>> findFriendsDFS(Person source, string p, string m, string n);
	void printPath(Person source, Person dest);

};


