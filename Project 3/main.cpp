#include "Graph.h"
#include <random>
#include <ctime>


class Random {
    static std::mt19937 random;
public:
    static int RandInt(int min, int max);
};
std::mt19937 Random::random(time(0));
int Random::RandInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(random);
}
void getStrings(vector<string>& strings, string filePath) {
    ifstream file(filePath);
    if (file.is_open()) {
        string current;
        while (getline(file, current)) {
            strings.push_back(current);
        }
    }
}
vector<Person> randomPersons(int size) {
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
    for (int i = 1; i < size; i++) {
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

int main()
{

    string name;
    string personality;
    string music;
    string nationality;
    int ID = 0;

    cout << "Enter Name: \n";  cin >> name; cout << "Enter Personality: \n";  cin >> name;
    
	vector<Person> people;
    people = randomPersons(100);
	Graph network;
    Random rand;

	for (int i = 0; i < people.size(); i++)
	{
		for (int u = 0; u < 2; u++)
		{
            int r = rand.RandInt(0, 99);

            if (r != i)
            {
                network.insertEdge(people.at(i), people.at(r));
            }
		}
	}

    vector<vector<pair<string, int>>> DFS = network.findFriendsDFS(people.at(0), personality, music, nationality);
    vector<vector<pair<string, int>>> BFS = network.findFriendsBFS(people.at(0), personality, music, nationality);

        vector<pair<string, int>> fPers = DFS.at(0);
        vector<pair<string, int>> fMusic = DFS.at(1);
        vector<pair<string, int>> fNation = DFS.at(2);

        vector<pair<string, int>> fPM = DFS.at(3);
        vector<pair<string, int>> fPN = DFS.at(4);
        vector<pair<string, int>> fMN = DFS.at(5);
        vector<pair<string, int>> fPMN = DFS.at(6);

        vector<pair<string, int>> fPers2 = BFS.at(0);

        cout << "Friends: ";
        for (int i = 0; i < fPers.size(); i++)
        {
            cout << fPers.at(i).first << ": " << fPers.at(i).second << " ";
        }
        cout << "\n\nBFS: \n";
        for (int i = 0; i < fPers2.size(); i++)
        {
            cout << fPers2.at(i).first << ": " << fPers2.at(i).second << " ";
        }
      

    


	return 0;
};