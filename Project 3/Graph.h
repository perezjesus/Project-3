
#include "Person.h"

class Graph
{
private:
	map<Person, set<Person>> graph;

public:
	 
	void insertEdge(Person from, Person to);

	set<Person> getAdjacent(Person vertex)
	{
		return graph[vertex];
	}

	int getLevel(Person x, Person src);
	
	vector<vector<pair<string, int>>> findFriendsBFS(Person source, string p, string m, string n)
	{
		set<Person> visited;
		queue<Person> q;
		visited.insert(source);
		q.push(source);

		string srcPers = p;
		string srcMusic = m;
		string srcNation = n;

		vector<pair<string, int>> friend1;
		vector<pair<string, int>> friend2;
		vector<pair<string, int>> friend3;
		vector<pair<string, int>> friendPM;
		vector<pair<string, int>> friendPN;
		vector<pair<string, int>> friendMN;
		vector<pair<string, int>> friendPMN;
		vector<vector<pair<string, int>>> final;

		int size = 1;
		int level = 0;

		while (!q.empty())
		{
			Person u = q.front();
			u.printInfo();
			q.pop();
			size--;
			set<Person> neighbors = graph[u];

			for (Person v : neighbors)
			{
				if (visited.count(v) == 0)
				{
					if (level != 1)
					{
						if (v.getPersonality() == srcPers)
						{
							friend1.push_back({ v.getName(), level + 1 });
							if (v.getMusic() == srcMusic)
							{
								friendPM.push_back({ v.getName(), level + 1 });
								if (v.getNationality() == srcNation)
									friendPMN.push_back({ v.getName(), level + 1 });
							}
							if (v.getNationality() == srcNation)
								friendPN.push_back({ v.getName(), level + 1 });

						}
						if (v.getMusic() == srcMusic)
						{
							friend2.push_back({ v.getName(), level + 1 });
							if (v.getNationality() == srcNation)
								friendMN.push_back({ v.getName(), level + 1 });
						}
						if (v.getNationality() == srcNation)
							friend3.push_back({ v.getName(), level + 1 });
					}
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

	vector<vector<pair<string, int>>> findFriendsDFS(Person source, string p, string m, string n)
	{
		set<Person> visited;
		stack<Person> s;
		visited.insert(source);
		s.push(source);

		string srcPers = p;
		string srcMusic = m;
		string srcNation = n;

		vector<pair<string, int>> friend1;
		vector<pair<string, int>> friend2;
		vector<pair<string, int>> friend3;
		vector<pair<string, int>> friendPM;
		vector<pair<string, int>> friendPN;
		vector<pair<string, int>> friendMN;
		vector<pair<string, int>> friendPMN;
		vector<vector<pair<string, int>>> final;


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
					int level = getLevel(v, source);
					if (getLevel(v, source) != 1)
					{
						if (v.getPersonality() == srcPers)
						{
							friend1.push_back({ v.getName(), level});
							if (v.getMusic() == srcMusic)
							{
								friendPM.push_back({ v.getName(), level});
								if (v.getNationality() == srcNation)
									friendPMN.push_back({ v.getName(), level});
							}
							if (v.getNationality() == srcNation)
								friendPN.push_back({ v.getName(), level});

						}
						if (v.getMusic() == srcMusic)
						{
							friend2.push_back({ v.getName(), level});
							if (v.getNationality() == srcNation)
								friendMN.push_back({ v.getName(), level});
						}
						if (v.getNationality() == srcNation)
							friend3.push_back({ v.getName(), level});
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


};


