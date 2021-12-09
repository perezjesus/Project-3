
#include "Graph.h"
#include <ctime>
#include <chrono>

using namespace std::chrono;
typedef high_resolution_clock Clock;

// Overall function of the program:
// User inputs their own personality, music genre and nationality traits
// We create an directed and unweighted adjacency list or edge list, with randomly generated Person objects and random friend connections
// We then do a BFS or DFS search through the graph, using the users Person object as the source
// We look for either the user's own traits or, give them the option of creating new traits to recommend by
// We then use these traits to generate a list of friends that match them based on each trait individually,
// Or a combination of the traits, showing a path between the User and the recommended friend

// Usable example personalities for input:  Gracious, Tolerant, Elegant
// Usable example music genre for input: House, Pop, Indie Rock
// Usable example nationalities for input: American, French, British
// All usable input inside the text files in the project file

// Extra functions for consolodating the main

void matchPrintAL(Graph network, Person src, vector<pair<Person, int>> fPers, vector<pair<Person, int>> fMusic,
    vector<pair<Person, int>> fNation, vector<pair<Person, int>> fPM, vector<pair<Person, int>> fPN, vector<pair<Person, int>> fMN, vector<pair<Person, int>> fPMN);
void matchPrintEL(GraphEL network, Person src, vector<pair<Person, int>> fPers, vector<pair<Person, int>> fMusic,
    vector<pair<Person, int>> fNation, vector<pair<Person, int>> fPM, vector<pair<Person, int>> fPN, vector<pair<Person, int>> fMN, vector<pair<Person, int>> fPMN);
void getStrings3(vector<string>& strings, string filePath);
Person makeSource();
Person makeSource2();
bool checkValidP(string personality);
bool checkValidM(string music);
bool checkValidN(string nationality);

int main()
{

    bool cont1 = true;

    while (cont1)
    {

        string in;
        cout << "Choose graph representation:\n\n";  // First choose a graph representation
        cout << "1. Adjacency list\n" << "2. Edge list\n\n";

        getline(cin, in);

     
        if (in == "1") // Adjacency List
        {

            cout << "Welcome to the Friendship Recommender!\n" << "-------------------------------------\n\n";
            Person src = makeSource();  // Source creation using inputted name and traits

            cout << "Creating network...\n\n";

            Graph network(100000, 5, src); // Adjacency list creation with the source inserted 

            cout << "Matching friends...\n\n";

            vector<vector<pair<Person, int>>> BFS = network.findFriendsBFS(src, src.getPersonality(), src.getMusic(), src.getNationality());
            vector<vector<pair<Person, int>>> DFS = network.findFriendsDFS(src, src.getPersonality(), src.getMusic(), src.getNationality());
            
            // BFS and DFS are done to find the friends which matches the sources own traits 

            bool cont5 = true;

            while (cont5)
            {

                string searchInput;

                cout << "Choose search method:\n\n" << "1. BFS\n" << "2. DFS\n\n"; // Choose BFS or DFS

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
                vector<pair<Person, int>> fMusic = BFSAL1.at(1);  // These are the vectors with the Person objects of the matching persons
                vector<pair<Person, int>> fNation = BFSAL1.at(2); // And their respective level
                vector<pair<Person, int>> fPM = BFSAL1.at(3);
                vector<pair<Person, int>> fPN = BFSAL1.at(4);
                vector<pair<Person, int>> fMN = BFSAL1.at(5);
                vector<pair<Person, int>> fPMN = BFSAL1.at(6);

                bool cont = true;
                while (cont)
                {
                    cout << "Recommend by: \n\n" << "1. My traits\n" << "2. Chosen traits\n" << "\nOr...\n\n" << "3. Change to BFS/DFS\n" << "4. End program\n\n";
                    string input1;
                    getline(cin, input1);    // Choose whether to recommend by your traits, new ones, or change search algorithm

                    if (input1 == "1")
                    {
                        matchPrintAL(network, src, fPers, fMusic, fNation, fPM, fPN, fMN, fPMN);  // Prints recommended friends based on input
                    }
                    else if (input1 == "2") // Now we are using new traits, and using BFS or DFS again to recommend friendships
                    {
                        
                        Person target = makeSource2();

                        vector<vector<pair<Person, int>>> BFSAL2(7);  // Create new list of vectors with the inputted traits

                        cout << "Matching friends with new traits...\n\n";

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

                        matchPrintAL(network, src, fPers2, fMusic2, fNation2, fPM2, fPN2, fMN2, fPMN2);
                    }

                    else if (input1 == "3")
                        cont = false;
                    else if (input1 == "4")
                    {
                        cont = false;
                        cont5 = false;
                        cont1 = false;
                    }
                    else
                    {
                        cout << "Options are \"1\", \"2\", \"3\" and \"4\" \n\n";
                        continue;
                    }
                }
            }

        }

        else if (in == "2") // Edge list representation
        {
        cout << "Welcome to the Friendship Recommender!\n\n" << "-------------------------------------\n\n";

        Person src = makeSource();
        cout << "Creating network...\n\n";
        GraphEL network2(1000, 5, src);         // Smaller size as to not waste time in showing the code
        cout << "Matching friends...\n\n";   // Works at 100k vertices, takes about 4 minutes for BFS and DFS
                                                 // Same structure in the main as the adjacency list 

    
            vector<vector<pair<Person, int>>> BFS = network2.friendsBFS(src, src.getPersonality(), src.getMusic(), src.getNationality());
            
            vector<vector<pair<Person, int>>> DFS = network2.friendsDFS(src, src.getPersonality(), src.getMusic(), src.getNationality());
           
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
                    cout << "Recommend by: \n\n" << "1. My traits\n" << "2. Chosen traits\n" << "\nOr...\n\n" << "3. Change to BFS/DFS\n" << "4. End program\n\n";
                    string input1;
                    getline(cin, input1);

                    if (input1 == "1")
                    {
                        matchPrintEL(network2, src, fPers3, fMusic3, fNation3, fPM3, fPN3, fMN3, fPMN3);
                    }

                    else if (input1 == "2")
                    {
                        Person target = makeSource2();

                        vector<vector<pair<Person, int>>> BFSEL2;

                        cout << "Matching friends with new traits...\n\n";

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

                        matchPrintEL(network2, src, fPers4, fMusic4, fNation4, fPM4, fPN4, fMN4, fPMN4);
                    }

                    else if (input1 == "3")
                        cont = false;
                    else if (input1 == "4")
                    {
                        cont = false;
                        cont6 = false;
                        cont1 = false;
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




void matchPrintAL(Graph network, Person src, vector<pair<Person, int>> fPers, vector<pair<Person, int>> fMusic,
    vector<pair<Person, int>> fNation, vector<pair<Person, int>> fPM, vector<pair<Person, int>> fPN, vector<pair<Person, int>> fMN, vector<pair<Person, int>> fPMN)
{
   
        bool cont2 = true;
        while (cont2)
        {
            string input2;
            cout << "Recommend by: \n\n" << "1. Personality\n" << "2. Music\n" << "3. Nationality\n"
                << "4. Double match\n" << "5. Triple match\n" << "\n Or...\n\n" << "6. Change to my/chosen traits or BFS/DFS or End program\n\n";
            getline(cin, input2);
            if (input2 == "1")
            {
                cout << "Recommending by personality: \n" << "Your closest matches are... \n\n";
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
                cout << "Recommending by music genre: \n" << "Your closest matches are... \n\n";
                for (int i = 0; i < 3; i++)
                {
                    network.printPath(src, fMusic.at(i).first);
                    cout << "\n\n";
                }
            }
            else if (input2 == "3")
            {
                cout << "Recommending by nationality: \n" << "Your closest matches are... \n\n";
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
void matchPrintEL(GraphEL network, Person src, vector<pair<Person, int>> fPers, vector<pair<Person, int>> fMusic,
    vector<pair<Person, int>> fNation, vector<pair<Person, int>> fPM, vector<pair<Person, int>> fPN, vector<pair<Person, int>> fMN, vector<pair<Person, int>> fPMN)
{

    bool cont2 = true;
    while (cont2)
    {
        string input2;
        cout << "Recommend by: \n\n" << "1. Personality\n" << "2. Music\n" << "3. Nationality\n"
            << "4. Double match\n" << "5. Triple match\n" << "\nOr...\n\n" "6. Change to my/chosen traits or BFS/DFS or End program\n\n";
        getline(cin, input2);
        if (input2 == "1")
        {
            cout << "Recommending by personality: \n" << "Your closest matches are... \n\n";
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
            cout << "Recommending by music genre: \n" << "Your closest matches are... \n\n";
            for (int i = 0; i < 3; i++)
            {
                network.printPath(src, fMusic.at(i).first);
                cout << "\n\n";
            }
        }
        else if (input2 == "3")
        {
            cout << "Recommending by nationality: \n" << "Your closest matches are... \n\n";
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
            if (fPM.size() == 0)
                cout << "No matches\n\n";
            else {
                network.printPath(src, fPM.at(0).first);
                cout << "\n\n";
            }
            cout << "Personality + Nationality: ";
            if (fPN.size() == 0)
                cout << "No matches\n\n";
            else
            {
                network.printPath(src, fPN.at(0).first);
                cout << "\n\n";
            }
            cout << "Music + Nationality: ";
            if (fMN.size() == 0)
                cout << "No matches\n\n";
            else
            {
                network.printPath(src, fMN.at(0).first);
                cout << "\n\n";
            }
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