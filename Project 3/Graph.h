
#include "GraphEL.h"
#include "Person.h"

class Graph
{
	// Adjacency list representation
private:

	map<Person, set<Person>> graph; // Map of Person objects as keys, and the list
	int _size;						// of adjacent vertices as a set of Person objects
	int _numFriends;

public:
	 
	Graph();
	Graph(int size, int numFriends, Person source);
	void fullBFS(Person source, string p, string m, string n);
	void insertEdge(Person from, Person to);
	set<Person> getAdjacent(Person vertex);
	int getLevel(Person x, Person src);
	vector<vector<pair<Person, int>>> findFriendsBFS(Person source, string p, string m, string n);	// BFS search
	vector<vector<pair<Person, int>>> findFriendsDFS(Person source, string p, string m, string n);	// DFS search
	void printPath(Person source, Person dest); // Used for printing the path from source to a specified Person vertex
	
};


