
#include "Graph.h"
#include <ctime>
#include <chrono>
using namespace std::chrono;
typedef high_resolution_clock Clock;


int main()
{
    string name;
    string personality;
    string music;
    string nationality;
    int ID = 0;

    name = "Jesus";
    personality = "Funny";
    music = "Pop";
    nationality = "American";

    string in;

    cout << "1. Adj List\n" << "2. Edge List\n\n";

    getline(cin, in);
    
    if (in == "1")
    {

        cout << "Welcome to the Friendship Recommender!\n\n";

        /*cout << "Please enter your name: \n";
        getline(cin, name);
        cout << "Enter one of your personality traits: \n";
        getline(cin, personality);
        cout << "Enter your favorite music genre: \n";
        getline(cin, music);
        cout << "Enter your nationality: \n";
        getline(cin, nationality);
        cout << "\n\n";*/

        Person src(name, personality, music, nationality, ID);

        Graph network(100000, 5, src);

        string searchInput;

        cout << "1. BFS\n" << "2. DFS\n\n";

        getline(cin, searchInput);

        vector<vector<pair<Person, int>>> BFSAL1;

        bool cont3 = true;

        
        if (searchInput == "1")
        {
            BFSAL1 = network.findFriendsBFS(src, personality, music, nationality);
        }
        else if (searchInput == "2")
        {
            network.findFriendsBFS(src, personality, music, nationality);
            BFSAL1 = network.findFriendsDFS(src, personality, music, nationality);
        }

       /* auto begin = Clock::now();
        auto end = Clock::now();
        auto time = (double)chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / (1000000000);
        cout << "Network AL: " << time << " seconds\n\n";


        begin = Clock::now();
        end = Clock::now();
        time = (double)chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / (1000000000);
        cout << "BFS AL: " << time << " seconds\n\n";*/

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
            cout << "Recommend by: \n" << "1. My traits\n" << "2. Chosen Traits\n" << "3. End Program\n\n";
            int input1;
            cin >> input1;

            if (input1 == 1)
            {
                bool cont2 = true;
                while (cont2)
                {
                    int input2;
                    cout << "Recommend by: \n" << "1. Personality\n" << "2. Music\n" << "3. Nationality\n"
                        << "4. Double Matches\n" << "5. Triple match\n" << "6. Change to my/chosen traits\n\n";
                    cin >> input2;
                    if (input2 == 1)
                    {
                        cout << "Recommending by Personality: \n" << "Your closest matches are... \n\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << fPers.at(i).first.getName() << ", " << fPers.at(i).second << " friends(s) away!\n" << "Path: ";
                            network.printPath(src, fPers.at(i).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 2)
                    {
                        cout << "Recommending by Music Genre: \n" << "Your closest matches are... \n\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << fMusic.at(i).first.getName() << ", " << fMusic.at(i).second << " friends(s) away!\n" << "Path: ";
                            network.printPath(src, fMusic.at(i).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 3)
                    {
                        cout << "Recommending by Nationality: \n" << "Your closest matches are... \n\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << fNation.at(i).first.getName() << ", " << fNation.at(i).second << " friends(s) away!\n" << "Path: ";
                            network.printPath(src, fNation.at(i).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 4)
                    {
                        cout << "Showing double matches: \n"
                            << "Personality + Music: " << fPM.at(0).first.getName()
                            << ", " << fPM.at(0).second << " friend(s) away!\n" << "Path: ";
                        network.printPath(src, fPM.at(0).first);
                        cout << "\n\n";
                        cout << "Personality + Nationality: " << fPN.at(0).first.getName()
                            << ", " << fPN.at(0).second << " friend(s) away!\n" << "Path: ";
                        network.printPath(src, fPN.at(0).first);
                        cout << "\n\n";
                        cout << "Music + Nationality: " << fMN.at(0).first.getName()
                            << ", " << fMN.at(0).second << " friend(s) away!\n" << "Path: ";
                        network.printPath(src, fMN.at(0).first);
                        cout << "\n\n";
                    }
                    if (input2 == 5)
                    {
                        cout << "Showing triple matches: \n";
                        int max = 3;
                        if (fPMN.size() < 3)
                            max = fPMN.size();
                        for (int i = 0; i < max; i++)
                        {
                            cout << fPMN.at(i).first.getName() << ", " << fPMN.at(i).second << " friend(s) away!\n" << "Path: ";
                            network.printPath(src, fPMN.at(i).first);
                            cout << "\n\n";
                        }
                        cout << endl;
                    }
                    if (input2 == 6)
                        cont2 = false;
                }
            }
            if (input1 == 2)
            {
                string personality2;
                string music2;
                string nationality2;

                cout << "Search new traits: \n\n";
                cout << "Enter a personality trait: \n";
                getline(cin, personality2);
                getline(cin, personality2);
                cout << "Enter a music genre: \n";
                getline(cin, music2);
                cout << "Enter a nationality: \n";
                getline(cin, nationality2);
                cout << "\n\n";
                cout << "Searching new traits...\n\n";

                auto begin = Clock::now();

                vector<vector<pair<Person, int>>> BFSAL2 = network.findFriendsBFS(src, personality2, music2, nationality2);

                auto end = Clock::now();
                auto time = (double)chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / (1000000000);

                cout << "BFS2 List: " << time << " seconds\n\n";

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
                    int input2;
                    cout << "Recommend by: \n" << "1. Personality\n" << "2. Music\n" << "3. Nationality\n"
                        << "4. Double Matches\n" << "5. Triple match\n" << "6. Change to my/chosen traits\n\n";
                    cin >> input2;
                    if (input2 == 1)
                    {
                        cout << "Recommending by Personality: \n" << "Your closest matches are... \n\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << fPers2.at(i).first.getName() << ", " << fPers2.at(i).second << " friends(s) away!\n" << "Path: ";
                            network.printPath(src, fPers2.at(i).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 2)
                    {
                        cout << "Recommending by Music Genre: \n" << "Your closest matches are... \n\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << fMusic2.at(i).first.getName() << ", " << fMusic2.at(i).second << " friends(s) away!\n" << "Path: ";
                            network.printPath(src, fMusic2.at(i).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 3)
                    {
                        cout << "Recommending by Nationality: \n" << "Your closest matches are... \n\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << fNation2.at(i).first.getName() << ", " << fNation2.at(i).second << " friends(s) away!\n" << "Path: ";
                            network.printPath(src, fNation2.at(i).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 4)
                    {
                        cout << "Showing double matches: \n"
                            << "Personality + Music: " << fPM2.at(0).first.getName()
                            << ", " << fPM2.at(0).second << " friend(s) away!\n" << "Path: ";
                        network.printPath(src, fPM2.at(0).first);
                        cout << "\n\n";
                        cout << "Personality + Nationality: " << fPN2.at(0).first.getName()
                            << ", " << fPN2.at(0).second << " friend(s) away!\n" << "Path: ";
                        network.printPath(src, fPN2.at(0).first);
                        cout << "\n\n";
                        cout << "Music + Nationality: " << fMN2.at(0).first.getName()
                            << ", " << fMN2.at(0).second << " friend(s) away!\n" << "Path: ";
                        network.printPath(src, fMN2.at(0).first);
                        cout << "\n\n";
                    }
                    if (input2 == 5)
                    {
                        cout << "Showing triple matches: \n";
                        int max = 3;
                        if (fPMN2.size() < 3)
                            max = fPMN2.size();
                        for (int i = 0; i < max; i++)
                        {
                            cout << fPMN2.at(i).first.getName() << ", " << fPMN2.at(i).second << " friend(s) away!\n" << "Path: ";
                            network.printPath(src, fPMN2.at(i).first);
                            cout << "\n\n";
                        }
                        cout << endl;
                    }
                    if (input2 == 6)
                        cont2 = false;
                }
            }

            if (input1 == 3)
                cont = false;


        }

    }

    if (in == "2")
    {
        cout << "Welcome to the Friendship Recommender!\n\n";

        cout << "Please enter your name: \n";
        getline(cin, name);
        getline(cin, name);
        cout << "Enter one of your personality traits: \n";
        getline(cin, personality);
        cout << "Enter your favorite music genre: \n";
        getline(cin, music);
        cout << "Enter your nationality: \n";
        getline(cin, nationality);
        cout << "\n\n";

        Person src(name, personality, music, nationality, ID);

        auto begin = Clock::now();
        GraphEL network2(100000, 5, src);
        auto end = Clock::now();
        auto time = (double)chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / (1000000000);
        cout << "Network EL: " << time << " seconds\n\n";

        vector<vector<pair<Person, int>>> BFSEL;

        string searchInput;

        cout << "1. BFS\n" << "2. DFS\n\n";

        getline(cin, searchInput);

       

        if (searchInput == "1")
        {
            BFSEL = network2.friendsBFS(src, personality, music, nationality);
        }
        else if (searchInput == "2")
        {
            BFSEL = network2.friendsBFS(src, personality, music, nationality);
            BFSEL = network2.friendsDFS(src, personality, music, nationality);
        }

        begin = Clock::now();
        end = Clock::now();
        time = (double)chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / (1000000000);
        cout << "BFS EL: " << time << " seconds\n\n";

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
            cout << "Recommend by: \n" << "1. My traits\n" << "2. Chosen Traits\n" << "3. End Program\n\n";
            int input1;
            cin >> input1;

            if (input1 == 1)
            {
                bool cont2 = true;
                while (cont2)
                {
                    int input2;
                    cout << "Recommend by: \n" << "1. Personality\n" << "2. Music\n" << "3. Nationality\n"
                        << "4. Double Matches\n" << "5. Triple match\n" << "6. Change to my/chosen traits\n\n";
                    cin >> input2;
                    if (input2 == 1)
                    {
                        cout << "Recommending by Personality: \n" << "Your closest matches are... \n\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << fPers3.at(i).first.getName() << ", " << fPers3.at(i).second << " friends(s) away!\n" << "Path: ";
                            network2.printPath(src, fPers3.at(i).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 2)
                    {
                        cout << "Recommending by Music Genre: \n" << "Your closest matches are... \n\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << fMusic3.at(i).first.getName() << ", " << fMusic3.at(i).second << " friends(s) away!\n" << "Path: ";
                            network2.printPath(src, fMusic3.at(i).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 3)
                    {
                        cout << "Recommending by Nationality: \n" << "Your closest matches are... \n\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << fNation3.at(i).first.getName() << ", " << fNation3.at(i).second << " friends(s) away!\n" << "Path: ";
                            network2.printPath(src, fNation3.at(i).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 4)
                    {

                        cout << "Showing double matches: \n"
                            << "Personality + Music: ";
                        if (fPM3.empty())
                            cout << "No matches\n\n";
                        else {
                            cout << fPM3.at(0).first.getName()
                                << ", " << fPM3.at(0).second << " friend(s) away!\n" << "Path: ";
                            network2.printPath(src, fPM3.at(0).first);
                            cout << "\n\n";
                        }
                        cout << "Personality + Nationality: ";
                        if (fPN3.empty())
                            cout << "No Matches\n\n";
                        else
                        {
                            cout << fPN3.at(0).first.getName()
                                << ", " << fPN3.at(0).second << " friend(s) away!\n" << "Path: ";
                            network2.printPath(src, fPN3.at(0).first);
                            cout << "\n\n";
                        }
                        cout << "Music + Nationality: ";
                        if (fMN3.empty())
                            cout << "No matches\n\n";
                        else
                        {
                            cout << fMN3.at(0).first.getName()
                                << ", " << fMN3.at(0).second << " friend(s) away!\n" << "Path: ";
                            network2.printPath(src, fMN3.at(0).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 5)
                    {
                        cout << "Showing triple matches: \n";
                        if (fPMN3.empty())
                            cout << "No matches\n\n";
                        else
                        {
                            int max = 3;
                            if (fPMN3.size() < 3)
                                max = fPMN3.size();
                            for (int i = 0; i < max; i++)
                            {
                                cout << fPMN3.at(i).first.getName() << ", " << fPMN3.at(i).second << " friend(s) away!\n" << "Path: ";
                                network2.printPath(src, fPMN3.at(i).first);
                                cout << "\n\n";
                            }
                            cout << endl;
                        }
                    }
                    if (input2 == 6)
                        cont2 = false;
                }
            }
            if (input1 == 2)
            {
                string personality2;
                string music2;
                string nationality2;

                cout << "Search new traits: \n\n";
                cout << "Enter a personality trait: \n";
                getline(cin, personality2);
                getline(cin, personality2);
                cout << "Enter a music genre: \n";
                getline(cin, music2);
                cout << "Enter a nationality: \n";
                getline(cin, nationality2);
                cout << "\n\n";
                cout << "Searching new traits...\n\n";

                auto begin = Clock::now();

                vector<vector<pair<Person, int>>> BFSEL2 = network2.friendsBFS(src, personality2, music2, nationality2);

                auto end = Clock::now();
                auto time = (double)chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / (1000000000);

                cout << "BFS2 List: " << time << " seconds\n\n";

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
                    int input2;
                    cout << "Recommend by: \n" << "1. Personality\n" << "2. Music\n" << "3. Nationality\n"
                        << "4. Double Matches\n" << "5. Triple match\n" << "6. Change to my/chosen traits\n\n";
                    cin >> input2;
                    if (input2 == 1)
                    {
                        cout << "Recommending by Personality: \n" << "Your closest matches are... \n\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << fPers4.at(i).first.getName() << ", " << fPers4.at(i).second << " friends(s) away!\n" << "Path: ";
                            network2.printPath(src, fPers4.at(i).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 2)
                    {
                        cout << "Recommending by Music Genre: \n" << "Your closest matches are... \n\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << fMusic4.at(i).first.getName() << ", " << fMusic4.at(i).second << " friends(s) away!\n" << "Path: ";
                            network2.printPath(src, fMusic4.at(i).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 3)
                    {
                        cout << "Recommending by Nationality: \n" << "Your closest matches are... \n\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << fNation4.at(i).first.getName() << ", " << fNation4.at(i).second << " friends(s) away!\n" << "Path: ";
                            network2.printPath(src, fNation4.at(i).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 4)
                    {
                        cout << "Showing double matches: \n"
                            << "Personality + Music: ";
                        if (fPM4.empty())
                            cout << "No matches\n\n";
                        else {
                            cout << fPM4.at(0).first.getName()
                                << ", " << fPM4.at(0).second << " friend(s) away!\n" << "Path: ";
                            network2.printPath(src, fPM4.at(0).first);
                            cout << "\n\n";
                        }
                        cout << "Personality + Nationality: ";
                        if (fPN4.empty())
                            cout << "No Matches\n\n";
                        else
                        {
                            cout << fPN4.at(0).first.getName()
                                << ", " << fPN4.at(0).second << " friend(s) away!\n" << "Path: ";
                            network2.printPath(src, fPN4.at(0).first);
                            cout << "\n\n";
                        }
                        cout << "Music + Nationality: ";
                        if (fMN4.empty())
                            cout << "No matches\n\n";
                        else
                        {
                            cout << fMN4.at(0).first.getName()
                                << ", " << fMN4.at(0).second << " friend(s) away!\n" << "Path: ";
                            network2.printPath(src, fMN4.at(0).first);
                            cout << "\n\n";
                        }
                    }
                    if (input2 == 5)
                    {
                        cout << "Showing triple matches: \n";
                        if (fPMN4.empty())
                            cout << "No matches\n\n";
                        else
                        {
                            int max = 3;
                            if (fPMN4.size() < 3)
                                max = fPMN4.size();
                            for (int i = 0; i < max; i++)
                            {
                                cout << fPMN4.at(i).first.getName() << ", " << fPMN4.at(i).second << " friend(s) away!\n" << "Path: ";
                                network2.printPath(src, fPMN4.at(i).first);
                                cout << "\n\n";
                            }
                            cout << endl;
                        }
                    }
                    if (input2 == 6)
                        cont2 = false;
                }
            }

            if (input1 == 3)
                cont = false;

        }
    }

 
  
	return 0;
};