#include "Graph.h"

class Random
{

	static std::mt19937 random;

public:

	static int RandInt(int min, int max);

};

std::mt19937 Random::random(time(0));
int Random::RandInt(int min, int max)
{
	std::uniform_int_distribution<int> dist(min, max);
	return dist(random);
}
void getStrings(vector<string>& strings, string filePath)
{
	ifstream file(filePath);
	if (file.is_open()) {
		string current;
		while (getline(file, current)) {
			strings.push_back(current);
		}
	}
}
vector<Person> randomPersons(int size)
{
	vector<Person> persons;
	vector<string> namesList;
	vector<string> musicList;
	vector<string> personalityList;
	vector<string> nationalitiesList;
	getStrings(namesList, "names.txt");
	getStrings(musicList, "music.txt");
	getStrings(personalityList, "personalities.txt");
	getStrings(nationalitiesList, "nationalities.txt");
	Random rand;
	for (int i = 0; i < size; i++) {
		int ni = rand.RandInt(0, namesList.size() - 1);
		string n = namesList[ni];
		int pi = rand.RandInt(0, personalityList.size() - 1);
		string p = personalityList[pi];
		int mi = rand.RandInt(0, musicList.size() - 1);
		string m = musicList[mi];
		int nai = rand.RandInt(0, nationalitiesList.size() - 1);
		string na = nationalitiesList[nai];
		persons.push_back(Person(n, p, m, na, i));
	}
	return persons;
}

void clear(queue<Person>& q2)
{
	queue<Person> empty;
	swap(q2, empty);
}
void clearS(stack<Person>& s2)
{
	stack<Person> empty;
	swap(s2, empty);
}

Graph::Graph(int size, int numFriends, Person source)
{
	vector<Person> people;
	Random rand;
	people = randomPersons(size);

	for (int i = 0; i < people.size(); i++)
	{
		for (int u = 0; u < numFriends; u++)
		{
			int r = rand.RandInt(0, size-1);
			if (r != i)
			{
				insertEdge(people.at(i), people.at(r));
			}
		}

	}
	people.at(0) = source;
}

void Graph::insertEdge(Person from, Person to)
{
	graph[from].insert(to);
}

set<Person> Graph::getAdjacent(Person vertex)
{
	return graph[vertex];
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
				return level;
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

vector<vector<pair<Person, int>>> Graph::findFriendsBFS(Person source, string p, string m, string n)
{
	set<Person> visited;
	queue<Person> q;
	visited.insert(source);
	q.push(source);

	string srcPers = p;
	string srcMusic = m;
	string srcNation = n;

	vector<pair<Person, int>> friend1;
	vector<pair<Person, int>> friend2;
	vector<pair<Person, int>> friend3;
	vector<pair<Person, int>> friendPM;
	vector<pair<Person, int>> friendPN;
	vector<pair<Person, int>> friendMN;
	vector<pair<Person, int>> friendPMN;
	vector<vector<pair<Person, int>>> final;

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
			if (visited.count(v) == 0)
			{
				if (level != 0)
				{
					if (v.getPersonality() == srcPers)
					{
						friend1.push_back({ v, level});
						if (v.getMusic() == srcMusic)
						{
							friendPM.push_back({ v, level});
							if (v.getNationality() == srcNation)
							{
								friendPMN.push_back({ v, level });
								if (friendPMN.size() == 3)
								{
									clear(q);
									break;
								}

							}
						}
						if (v.getNationality() == srcNation)
							friendPN.push_back({ v, level});

					}
					if (v.getMusic() == srcMusic)
					{
						friend2.push_back({ v, level});
						if (v.getNationality() == srcNation)
							friendMN.push_back({ v, level});
					}
					if (v.getNationality() == srcNation)
						friend3.push_back({ v, level});
				}
				v.setLevel(level);
				visited.insert(v);
				q.push(v);

			}
		}

		if (size == 0)
		{
			level++;
			size = q.size();
		}

	}
	final.push_back(friend1);
	final.push_back(friend2);
	final.push_back(friend3);
	final.push_back(friendPM);
	final.push_back(friendPN);
	final.push_back(friendMN);
	final.push_back(friendPMN);

	return final;
}

void Graph::fullBFS(Person source, string p, string m, string n)
{
	set<Person> visited;
	queue<Person> q;
	visited.insert(source);
	q.push(source);

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
			if (visited.count(v) == 0)
			{
				v.setLevel(level);
				visited.insert(v);
				q.push(v);

			}
		}

		if (size == 0)
		{
			level++;
			size = q.size();
		}

	}

}

vector<vector<pair<Person, int>>> Graph::findFriendsDFS(Person source, string p, string m, string n)
{
	set<Person> visited;
	stack<Person> s;
	visited.insert(source);
	s.push(source);

	string srcPers = p;
	string srcMusic = m;
	string srcNation = n;

	vector<pair<Person, int>> friend1;
	vector<pair<Person, int>> friend2;
	vector<pair<Person, int>> friend3;
	vector<pair<Person, int>> friendPM;
	vector<pair<Person, int>> friendPN;
	vector<pair<Person, int>> friendMN;
	vector<pair<Person, int>> friendPMN;
	vector<vector<pair<Person, int>>> final;


	int size = 1;


	while (!s.empty())
	{
		Person u = s.top();

		s.pop();

		set<Person> neighbors = graph[u];

		for (Person v : neighbors)
		{
			if (visited.count(v) == 0)
			{
				int level = v.getLevel();
				if (graph[source].count(v) == 0)
				{
					if (v.getPersonality() == srcPers)
					{
						friend1.push_back({ v, level });
						if (v.getMusic() == srcMusic)
						{
							friendPM.push_back({ v, level });
							if (v.getNationality() == srcNation)
							{
								friendPMN.push_back({ v, level });
								if (friendPMN.size() == 3)
								{
									clearS(s);
									break;
								}
							}
						}
						if (v.getNationality() == srcNation)
							friendPN.push_back({ v, level });

					}
					if (v.getMusic() == srcMusic)
					{
						friend2.push_back({ v, level });
						if (v.getNationality() == srcNation)
							friendMN.push_back({ v, level });
					}
					if (v.getNationality() == srcNation)
						friend3.push_back({ v, level });
				}
				
				visited.insert(v);

				s.push(v);

			}
		}

	}
	final.push_back(friend1);
	final.push_back(friend2);
	final.push_back(friend3);
	final.push_back(friendPM);
	final.push_back(friendPN);
	final.push_back(friendMN);
	final.push_back(friendPMN);

	return final;
}

void Graph::printPath(Person source, Person dest)
{
	set<Person> visited;
	queue<Person> q;
	visited.insert(source);
	q.push(source);
	
	map<Person, Person> m;

	while (!q.empty())
	{
		Person u = q.front();
		q.pop();
		set<Person> neighbors = graph[u];
		for (Person v : neighbors)
		{
			if (visited.count(v) == 0)
			{
				
				m[v] = u;
				if (v == dest)
				{
					clear(q);
					break;
				}

				visited.insert(v);
				q.push(v);
			}
			
		}

	}

	Person p = dest;
	
	vector<string> print;
	while (p != source)
	{
		print.push_back(p.getName());
		p = m[p];
		
	}
	print.push_back(p.getName());
	reverse(print.begin(), print.end());
	cout << dest.getName() << ", " << print.size() - 2 << " levels away!\n";
	cout << "Path: You -> ";
	for (int i = 1; i < print.size()-1; i++)
	{
		cout << print.at(i) << " -> ";
	}
	cout << print.at(print.size() - 1);

}