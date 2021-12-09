
#include "Graph.h"
#include <ctime>
#include <chrono>
using namespace std::chrono;
typedef high_resolution_clock Clock;

void getStrings3(vector<string>& strings, string filePath);
Person makeSource();
Person makeSource2();
bool checkValidP(string personality);
bool checkValidM(string music);
bool checkValidN(string nationality);

int main()
{

    bool cont7 = true;

    while (cont7)
    {

        string in;
        cout << "Choose Graph Representation:\n\n";
        cout << "1. Adj List\n" << "2. Edge List\n\n";

        getline(cin, in);

     
        if (in == "1")
        {

            cout << "Welcome to the Friendship Recommender!\n\n";

            Person src = makeSource();

            Graph network(10000, 5, src);

            vector<vector<pair<Person, int>>> BFS = network.findFriendsBFS(src, src.getPersonality(), src.getMusic(), src.getNationality());
            vector<vector<pair<Person, int>>> DFS = network.findFriendsDFS(src, src.getPersonality(), src.getMusic(), src.getNationality());

            bool cont5 = true;

            while (cont5)
            {

                string searchInput;

                cout << "Choose search method:\n\n" << "1. BFS\n" << "2. DFS\n\n";

                getline(cin, searchInput);

                vector<vector<pair<Person, int>>> BFSAL1;

                if (searchInput == "1")
                {
                    BFSAL1 = BFS;
                }
                else if (searchInput == "2")
                {
                    BFSAL1 = DFS;
                }
                else
                {
                    cout << "Options are \"1\" and \"2\" \n\n";
                    continue;
                }

                vector<pair<Person, int>> fPers = BFSAL1.at(0);
                vector<pair<Person, int>> fMusic = BFSAL1.at(1);
                vector<pair<Person, int>> fNation = BFSAL1.at(2);
                vector<pair<Person, int>> fPM = BFSAL1.at(3);
                vector<pair<Person, int>> fPN = BFSAL1.at(4);
                vector<pair<Person, int>> fMN = BFSAL1.at(5);
                vector<pair<Person, int>> fPMN = BFSAL1.at(6);

                bool cont = true;
                while (cont)
                {
                    cout << "Recommend by: \n" << "1. My traits\n" << "2. Chosen Traits\n" << "3. Change to BFS/DFS\n" << "4. End Program\n\n";
                    string input1;
                    getline(cin, input1);

                    if (input1 == "1")
                    {
                        bool cont2 = true;
                        while (cont2)
                        {
                            string input2;
                            cout << "Recommend by: \n" << "1. Personality\n" << "2. Music\n" << "3. Nationality\n"
                                << "4. Double Matches\n" << "5. Triple match\n" << "6. Change to my/chosen traits or BFS/DFS\n\n";
                            getline(cin, input2);
                            if (input2 == "1")
                            {
                                cout << "Recommending by Personality: \n" << "Your closest matches are... \n\n";
                                if (fPers.size() == 0)
                                    cout << "No matches\n\n";
                                else

                                {
                                    for (int i = 0; i < 3; i++)
                                    {
                                        network.printPath(src, fPers.at(i).first);
                                        cout << "\n\n";
                                    }
                                }
                            
                            }
                            else if (input2 == "2")
                            {
                                cout << "Recommending by Music Genre: \n" << "Your closest matches are... \n\n";
                                for (int i = 0; i < 3; i++)
                                {
                                    network.printPath(src, fMusic.at(i).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "3")
                            {
                                cout << "Recommending by Nationality: \n" << "Your closest matches are... \n\n";
                                for (int i = 0; i < 3; i++)
                                {
                                    network.printPath(src, fNation.at(i).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "4")
                            {
                                cout << "Showing double matches: \n"
                                    << "Personality + Music: ";
                                network.printPath(src, fPM.at(0).first);
                                cout << "\n\n";
                                cout << "Personality + Nationality: ";
                                network.printPath(src, fPN.at(0).first);
                                cout << "\n\n";
                                cout << "Music + Nationality: ";
                                network.printPath(src, fMN.at(0).first);
                                cout << "\n\n";
                            }
                            else if (input2 == "5")
                            {
                                cout << "Showing triple matches: \n";
                                int max = 3;
                                if (fPMN.size() == 0)
                                    cout << "No matches\n\n";
                                if (fPMN.size() < 3)
                                    max = fPMN.size();
                                for (int i = 0; i < max; i++)
                                {
                                    network.printPath(src, fPMN.at(i).first);
                                    cout << "\n\n";
                                }
                                cout << endl;
                            }
                            else if (input2 == "6")
                            {
                                cont2 = false;
                                continue;
                            }
                            else
                            {
                                cout << "Options are \"1\", \"2\", \"3\", \"4\", \"5\", and \"6\"\n\n";
                                continue;
                            }

                        }
                    }
                    else if (input1 == "2")
                    {
                        
                        Person target = makeSource2();

                        vector<vector<pair<Person, int>>> BFSAL2(7);

                        if (searchInput == "1")
                            BFSAL2 = network.findFriendsBFS(src, target.getPersonality(), target.getMusic(), target.getNationality());
                        else if (searchInput == "2")
                            BFSAL2 = network.findFriendsDFS(src, target.getPersonality(), target.getMusic(), target.getNationality());

                        vector<pair<Person, int>> fPers2 = BFSAL2.at(0);
                        vector<pair<Person, int>> fMusic2 = BFSAL2.at(1);
                        vector<pair<Person, int>> fNation2 = BFSAL2.at(2);
                        vector<pair<Person, int>> fPM2 = BFSAL2.at(3);
                        vector<pair<Person, int>> fPN2 = BFSAL2.at(4);
                        vector<pair<Person, int>> fMN2 = BFSAL2.at(5);
                        vector<pair<Person, int>> fPMN2 = BFSAL2.at(6);

                        bool cont2 = true;
                        while (cont2)
                        {
                            string input2;
                            cout << "Recommend by: \n" << "1. Personality\n" << "2. Music\n" << "3. Nationality\n"
                                << "4. Double Matches\n" << "5. Triple match\n" << "6. Change to my/chosen traits or BFS/DFS\n\n";
                            getline(cin, input2);
                            if (input2 == "1")
                            {
                                cout << "Recommending by Personality: \n" << "Your closest matches are... \n\n";
                                for (int i = 0; i < 3; i++)
                                {
                                    network.printPath(src, fPers2.at(i).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "2")
                            {
                                cout << "Recommending by Music Genre: \n" << "Your closest matches are... \n\n";
                                for (int i = 0; i < 3; i++)
                                {
                                    network.printPath(src, fMusic2.at(i).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "3")
                            {
                                cout << "Recommending by Nationality: \n" << "Your closest matches are... \n\n";
                                for (int i = 0; i < 3; i++)
                                {
                                    network.printPath(src, fNation2.at(i).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "4")
                            {
                                cout << "Showing double matches: \n"
                                    << "Personality + Music: ";
                                network.printPath(src, fPM2.at(0).first);
                                cout << "\n\n";
                                cout << "Personality + Nationality: ";
                                network.printPath(src, fPN2.at(0).first);
                                cout << "\n\n";
                                cout << "Music + Nationality: ";
                                network.printPath(src, fMN2.at(0).first);
                                cout << "\n\n";
                            }
                            else if (input2 == "5")
                            {
                                cout << "Showing triple matches: \n";
                                int max = 3;
                                if (fPMN2.size() == 0)
                                    cout << "No matches\n\n";
                                if (fPMN2.size() < 3)
                                    max = fPMN2.size();
                                for (int i = 0; i < max; i++)
                                {
                                    network.printPath(src, fPMN2.at(i).first);
                                    cout << "\n\n";
                                }
                                cout << endl;
                            }
                            else if (input2 == "6")
                                cont2 = false;
                            else
                            {
                                cout << "Options are \"1\", \"2\", \"3\", \"4\", \"5\", and \"6\"\n\n";
                                continue;
                            }
                        }
                    }

                    else if (input1 == "3")
                        cont = false;
                    else if (input1 == "4")
                    {
                        cont = false;
                        cont5 = false;
                        cont7 = false;
                    }
                    else
                    {
                        cout << "Options are \"1\", \"2\", \"3\" and \"4\" \n\n";
                        continue;
                    }


                }
            }

        }

        else if (in == "2")
        {
        cout << "Welcome to the Friendship Recommender!\n\n";

        Person src = makeSource();

            auto begin = Clock::now();

            GraphEL network2(10000, 5, src);
            auto end = Clock::now();
            auto time = (double)chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / (1000000000);
            cout << "Network EL: " << time << " seconds\n\n";

            begin = Clock::now();
            vector<vector<pair<Person, int>>> BFS = network2.friendsBFS(src, src.getPersonality(), src.getMusic(), src.getNationality());
            end = Clock::now();
            time = (double)chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / (1000000000);
            cout << "BFS EL: " << time << " seconds\n\n";
            begin = Clock::now();
            vector<vector<pair<Person, int>>> DFS = network2.friendsDFS(src, src.getPersonality(), src.getMusic(), src.getNationality());
            end = Clock::now();
            time = (double)chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / (1000000000);
            cout << "DFS EL: " << time << " seconds\n\n";
            bool cont6 = true;

            while (cont6)
            {

                vector<vector<pair<Person, int>>> BFSEL;

                string searchInput;

                cout << "1. BFS\n" << "2. DFS\n\n";

                getline(cin, searchInput);



                if (searchInput == "1")
                {
                    BFSEL = BFS;
                }
                else if (searchInput == "2")
                {
                    BFSEL = DFS;
                }
                else
                {
                    cout << "Options are \"1\" and \"2\" \n\n";
                    continue;
                }

                vector<pair<Person, int>> fPers3 = BFSEL.at(0);
                vector<pair<Person, int>> fMusic3 = BFSEL.at(1);
                vector<pair<Person, int>> fNation3 = BFSEL.at(2);
                vector<pair<Person, int>> fPM3 = BFSEL.at(3);
                vector<pair<Person, int>> fPN3 = BFSEL.at(4);
                vector<pair<Person, int>> fMN3 = BFSEL.at(5);
                vector<pair<Person, int>> fPMN3 = BFSEL.at(6);

                bool cont = true;
                while (cont)
                {
                    cout << "Recommend by: \n" << "1. My traits\n" << "2. Chosen Traits\n" << "3. Change to BFS/DFS\n" << "4. End program\n\n";
                    string input1;
                    getline(cin, input1);

                    if (input1 == "1")
                    {
                        bool cont2 = true;
                        while (cont2)
                        {
                            string input2;
                            cout << "Recommend by: \n" << "1. Personality\n" << "2. Music\n" << "3. Nationality\n"
                                << "4. Double Matches\n" << "5. Triple match\n" << "6. Change to my/chosen traits or BFS/DFS\n\n";
                            getline(cin, input2);
                            if (input2 == "1")
                            {
                                cout << "Recommending by Personality: \n" << "Your closest matches are... \n\n";
                                for (int i = 0; i < 3; i++)
                                {
                                    network2.printPath(src, fPers3.at(i).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "2")
                            {
                                cout << "Recommending by Music Genre: \n" << "Your closest matches are... \n\n";
                                for (int i = 0; i < 3; i++)
                                {
                                    network2.printPath(src, fMusic3.at(i).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "3")
                            {
                                cout << "Recommending by Nationality: \n" << "Your closest matches are... \n\n";
                                for (int i = 0; i < 3; i++)
                                {
                                    network2.printPath(src, fNation3.at(i).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "4")
                            {
                                cout << "Showing double matches: \n"
                                    << "Personality + Music: ";
                                if (fPM3.size() == 0)
                                    cout << "No matches\n\n";
                                else {
                                    network2.printPath(src, fPM3.at(0).first);
                                    cout << "\n\n";
                                }
                                cout << "Personality + Nationality: ";
                                if (fPN3.size() == 0)
                                    cout << "No matches\n\n";
                                else
                                {
                                    network2.printPath(src, fPN3.at(0).first);
                                    cout << "\n\n";
                                }
                                cout << "Music + Nationality: ";
                                if (fMN3.size() == 0)
                                    cout << "No matches\n\n";
                                else
                                {
                                    network2.printPath(src, fMN3.at(0).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "5")
                            {
                                cout << "Showing triple matches: \n";
                                int max = 3;
                                if (fPMN3.size() == 0)
                                    cout << "No matches\n\n";
                                if (fPMN3.size() < 3)
                                    max = fPMN3.size();
                                for (int i = 0; i < max; i++)
                                {
                                    network2.printPath(src, fPMN3.at(i).first);
                                    cout << "\n\n";
                                }
                                cout << endl;
                            }
                            else if (input2 == "6")
                                cont2 = false;
                            else
                            {
                                cout << "Options are \"1\", \"2\", \"3\", \"4\", \"5\", and \"6\"\n\n";
                                continue;
                            }
                        }
                    }

                    else if (input1 == "2")
                    {
                        Person target = makeSource2();

                        vector<vector<pair<Person, int>>> BFSEL2;

                        if (searchInput == "1")
                            BFSEL2 = network2.friendsBFS(src, target.getPersonality(), target.getMusic(), target.getNationality());
                        if (searchInput == "2")
                            BFSEL2 = network2.friendsDFS(src, target.getPersonality(), target.getMusic(), target.getNationality());

                        vector<pair<Person, int>> fPers4 = BFSEL2.at(0);
                        vector<pair<Person, int>> fMusic4 = BFSEL2.at(1);
                        vector<pair<Person, int>> fNation4 = BFSEL2.at(2);
                        vector<pair<Person, int>> fPM4 = BFSEL2.at(3);
                        vector<pair<Person, int>> fPN4 = BFSEL2.at(4);
                        vector<pair<Person, int>> fMN4 = BFSEL2.at(5);
                        vector<pair<Person, int>> fPMN4 = BFSEL2.at(6);

                        bool cont2 = true;
                        while (cont2)
                        {
                            string input2;
                            cout << "Recommend by: \n" << "1. Personality\n" << "2. Music\n" << "3. Nationality\n"
                                << "4. Double Matches\n" << "5. Triple match\n" << "6. Change to my/chosen traits or BFS/DFS\n\n";
                            getline(cin, input2);
                            if (input2 == "1")
                            {
                                cout << "Recommending by Personality: \n" << "Your closest matches are... \n\n";
                                for (int i = 0; i < 3; i++)
                                {
                                    network2.printPath(src, fPers4.at(i).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "2")
                            {
                                cout << "Recommending by Music Genre: \n" << "Your closest matches are... \n\n";
                                for (int i = 0; i < 3; i++)
                                {
                                    network2.printPath(src, fMusic4.at(i).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "3")
                            {
                                cout << "Recommending by Nationality: \n" << "Your closest matches are... \n\n";
                                for (int i = 0; i < 3; i++)
                                {
                                    network2.printPath(src, fNation4.at(i).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "4")
                            {
                                cout << "Showing double matches: \n"
                                    << "Personality + Music: ";
                                if (fPM4.size() == 0)
                                    cout << "No matches\n\n";
                                else {
                                    network2.printPath(src, fPM4.at(0).first);
                                    cout << "\n\n";
                                }
                                cout << "Personality + Nationality: ";
                                if (fPN4.size() == 0)
                                    cout << "No matches\n\n";
                                else
                                {
                                    network2.printPath(src, fPN4.at(0).first);
                                    cout << "\n\n";
                                }
                                cout << "Music + Nationality: ";
                                if (fMN4.size() == 0)
                                    cout << "No matches\n\n";
                                else
                                {
                                    network2.printPath(src, fMN4.at(0).first);
                                    cout << "\n\n";
                                }
                            }
                            else if (input2 == "5")
                            {
                                cout << "Showing triple matches: \n";
                                int max = 3;
                                if (fPMN4.size() == 0)
                                    cout << "No matches\n\n";
                                if (fPMN4.size() < 3)
                                    max = fPMN4.size();
                                for (int i = 0; i < max; i++)
                                {
                                    network2.printPath(src, fPMN4.at(i).first);
                                    cout << "\n\n";
                                }
                                cout << endl;
                            }
                            else if (input2 == "6")
                                cont2 = false;
                            else
                            {
                                cout << "Options are \"1\", \"2\", \"3\", \"4\", \"5\", and \"6\"\n\n";
                                continue;
                            }
                        }
                    }

                    else if (input1 == "3")
                        cont = false;
                    else if (input1 == "4")
                    {
                        cont = false;
                        cont6 = false;
                        cont7 = false;
                    }
                    else
                    {
                    cout << "Options are \"1\", \"2\", \"3\" and \"4\" \n\n";
                    continue;
                    }

                }
            }

        }
        else
        {
            cout << "Options are \"1\" and \"2\"\n\n";
        }
    }
	return 0;
};

void getStrings3(vector<string>& strings, string filePath)
{
    ifstream file(filePath);
    if (file.is_open()) {
        string current;
        while (getline(file, current)) {
            strings.push_back(current);
        }
    }
}

Person makeSource()
{
    string name;
    string personality;
    string music;
    string nationality;
    int ID = 0;

    cout << "Please enter your name: \n";
    getline(cin, name);
    cout << "Enter one of your personality traits: \n";
    do
    {

        getline(cin, personality);
    } while (!checkValidP(personality));

    cout << "Enter your favorite music genre: \n";
    do
    {

        getline(cin, music);
    } while (!checkValidM(music));
    cout << "Enter your nationality: \n";
    do
    {

        getline(cin, nationality);
    } while (!checkValidN(nationality));
    cout << "\n\n";

    Person src(name, personality, music, nationality, ID);

    return src;
}

Person makeSource2()
{
    string name;
    string personality;
    string music;
    string nationality;
    int ID = 0;

    cout << "Enter a personality trait: \n";
    do
    {

        getline(cin, personality);
    } while (!checkValidP(personality));

    cout << "Enter a music genre: \n";
    do
    {

        getline(cin, music);
    } while (!checkValidM(music));
    cout << "Enter a nationality: \n";
    do
    {

        getline(cin, nationality);
    } while (!checkValidN(nationality));
    cout << "\n\n";

    Person src(name, personality, music, nationality, ID);

    return src;
}

bool checkValidP(string personality)
{
    vector<string> personalityList;
    getStrings3(personalityList, "personalities.txt");

    if (find(personalityList.begin(), personalityList.end(), personality) != personalityList.end())
        return true;
    cout << "Enter a valid personality trait\n";
    return false;
}
bool checkValidM(string music)
{
    vector<string> musicList;
    getStrings3(musicList, "music.txt");

    if (find(musicList.begin(), musicList.end(), music) != musicList.end())
        return true;
    cout << "Enter a valid music genre\n";
    return false;
}
bool checkValidN(string nationality)
{
    vector<string> nationalityList;
    getStrings3(nationalityList, "nationalities.txt");

    if (find(nationalityList.begin(), nationalityList.end(), nationality) != nationalityList.end())
        return true;
    cout << "Enter a valid nationality\n";
    return false;
}