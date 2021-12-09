#include "GraphEL.h"

class Random2
{

	static std::mt19937 random2;

public:

	static int RandInt(int min, int max);

};

std::mt19937 Random2::random2(time(0));
int Random2::RandInt(int min, int max)
{
	std::uniform_int_distribution<int> dist(min, max);
	return dist(random2);
}
void getStrings2(vector<string>& strings, string filePath)
{
	ifstream file(filePath);
	if (file.is_open()) {
		string current;
		while (getline(file, current)) {
			strings.push_back(current);
		}
	}
}
vector<Person> random2Persons(int size)
{
	vector<Person> persons;
	vector<string> namesList;
	vector<string> musicList;
	vector<string> personalityList;
	vector<string> nationalitiesList;
	getStrings2(namesList, "names.txt");
	getStrings2(musicList, "music.txt");
	getStrings2(personalityList, "personalities.txt");
	getStrings2(nationalitiesList, "nationalities.txt");
	Random2 rand;
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

void clear2(queue<Person>& q2)
{
	queue<Person> empty;
	swap(q2, empty);
}
void clear2S(stack<Person>& s2)
{
	stack<Person> empty;
	swap(s2, empty);
}


GraphEL::GraphEL(int size, int numFriends, Person source)
{
	vector<Person> people;
	Random2 rand;
	people = random2Persons(size);

	for (int i = 0; i < people.size(); i++)
	{
		for (int u = 0; u < numFriends; u++)
		{
			int r = rand.RandInt(0, size - 1);
			if (r != i)
			{
				insertEdge(people.at(i), people.at(r));
			}
		}

	}
	people.at(0) = source;
}
void GraphEL::insertEdge(Person from, Person to)
{
	graph.push_back({ from, to });
}

int GraphEL::getLevelEL(Person x, Person source)
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
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph.at(i).first == u && visited.count(graph.at(i).second) == 0)
			{
				Person v = graph.at(i).second;
				if (v == x)
					return level;
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

vector<vector<pair<Person, int>>> GraphEL::friendsBFS(Person source, string p, string m, string n)
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
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph.at(i).first == u && visited.count(graph.at(i).second) == 0)
			{
				Person v = graph.at(i).second;
				if (level != 0)
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
									clear2(q);
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

vector<vector<pair<Person, int>>> GraphEL::friendsDFS(Person source, string p, string m, string n)
{
	set<Person> visited;
	stack<Person> q;
	visited.insert(source);
	q.push(source);

	set<Person> adjacent;
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph.at(i).first == source)
			adjacent.insert(graph.at(i).second);
	}

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

	while (!q.empty())
	{
		Person u = q.top();
		q.pop();
		size--;
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph.at(i).first == u && visited.count(graph.at(i).second) == 0)
			{
				Person v = graph.at(i).second;
				int level = v.getLevel();
				if (adjacent.count(v) == 0)
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
									clear2S(q);
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
				q.push(v);

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

void GraphEL::printPath(Person source, Person dest)
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
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph.at(i).first == u && visited.count(graph.at(i).second) == 0)
			{
				Person v = graph.at(i).second;
				m[v] = u;
				if (v == dest)
				{
					clear2(q);
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
	for (int i = 1; i < print.size() - 1; i++)
	{
		cout << print.at(i) << " -> ";
	}
	cout << print.at(print.size() - 1);
}