#include "Graph.h"

void Graph::insertEdge(Person from, Person to)
{
	graph[from].insert(to);
	
}

int Graph::getLevel(Person x, Person src)
{
	set<Person> visited;
	queue<Person> q;
	visited.insert(src);
	q.push(src);

	int size = 1;
	int level = 0;

	while (!q.empty())
	{
		Person u = q.front();
		q.pop();
		size--;
		set<Person> neighbors = graph[u];

		for (Person v : neighbors)
		{
			if (v == x)
				return level+1;
			visited.insert(v);
			q.push(v);
		}
		if (size == 0)
		{
			level++;
			size = q.size();
		}
	}
}