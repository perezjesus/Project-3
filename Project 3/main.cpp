
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

    /*name = "Jesus";
    personality = "Funny";
    music = "Pop";
    nationality = "American";*/

    string in;

    cout << "1. Adj List\n" << "2. Edge List\n\n";

    getline(cin, in);
    
    if (in == "1")
    {

        cout << "Welcome to the Friendship Recommender!\n\n";

        cout << "Please enter your name: \n";
        getline(cin, name);
        cout << "Enter one of your personality traits: \n";
        getline(cin, personality);
        cout << "Enter your favorite music genre: \n";
        getline(cin, music);
        cout << "Enter your nationality: \n";
        getline(cin, nationality);
        cout << "\n\n";

        Person src(name, personality, music, nationality, ID);

        Graph network(10000, 5, src);

        bool cont5 = true;

        while (cont5)
        {

            string searchInput;

            cout << "1. BFS\n" << "2. DFS\n\n";

            getline(cin, searchInput);

            vector<vector<pair<Person, int>>> BFSAL1;

            if (searchInput == "1")
            {
                BFSAL1 = network.findFriendsBFS(src, personality, music, nationality);
            }
            else if (searchInput == "2")
            {
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
                            << "4. Double Matches\n" << "5. Triple match\n" << "6. Change to my/chosen traits\n\n";
                        getline(cin, input2);
                        if (input2 == "1")
                        {
                            cout << "Recommending by Personality: \n" << "Your closest matches are... \n\n";
                            for (int i = 0; i < 3; i++)
                            {
                                network.printPath(src, fPers.at(i).first);
                                cout << "\n\n";
                            }
                        }
                        if (input2 == "2")
                        {
                            cout << "Recommending by Music Genre: \n" << "Your closest matches are... \n\n";
                            for (int i = 0; i < 3; i++)
                            {
                                network.printPath(src, fMusic.at(i).first);
                                cout << "\n\n";
                            }
                        }
                        if (input2 == "3")
                        {
                            cout << "Recommending by Nationality: \n" << "Your closest matches are... \n\n";
                            for (int i = 0; i < 3; i++)
                            {
                                network.printPath(src, fNation.at(i).first);
                                cout << "\n\n";
                            }
                        }
                        if (input2 == "4")
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
                        if (input2 == "5")
                        {
                            cout << "Showing triple matches: \n";
                            int max = 3;
                            if (fPMN.size() == 0)
                                cout << "No matches";
                            if (fPMN.size() < 3)
                                max = fPMN.size();
                            for (int i = 0; i < max; i++)
                            {
                                network.printPath(src, fPMN.at(i).first);
                                cout << "\n\n";
                            }
                            cout << endl;
                        }
                        if (input2 == "6")
                            cont2 = false;
                    }
                }
                if (input1 == "2")
                {
                    string personality2;
                    string music2;
                    string nationality2;

                    cout << "Search new traits: \n\n";
                    cout << "Enter a personality trait: \n";
                    getline(cin, personality2);

                    cout << "Enter a music genre: \n";
                    getline(cin, music2);

                    cout << "Enter a nationality: \n";
                    getline(cin, nationality2);

                    cout << "\n\n";
                    cout << "Searching new traits...\n\n";


                    vector<vector<pair<Person, int>>> BFSAL2(7);

                    if (searchInput == "1")
                        BFSAL2 = network.findFriendsBFS(src, personality2, music2, nationality2);
                    else if (searchInput == "2")
                        BFSAL2 = network.findFriendsDFS(src, personality2, music2, nationality2);

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
                            << "4. Double Matches\n" << "5. Triple match\n" << "6. Change to my/chosen traits\n\n";
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
                        if (input2 == "2")
                        {
                            cout << "Recommending by Music Genre: \n" << "Your closest matches are... \n\n";
                            for (int i = 0; i < 3; i++)
                            {
                                network.printPath(src, fMusic2.at(i).first);
                                cout << "\n\n";
                            }
                        }
                        if (input2 == "3")
                        {
                            cout << "Recommending by Nationality: \n" << "Your closest matches are... \n\n";
                            for (int i = 0; i < 3; i++)
                            {
                                network.printPath(src, fNation2.at(i).first);
                                cout << "\n\n";
                            }
                        }
                        if (input2 == "4")
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
                        if (input2 == "5")
                        {
                            cout << "Showing triple matches: \n";
                            int max = 3;
                            if (fPMN2.size() < 3)
                                max = fPMN2.size();
                            for (int i = 0; i < max; i++)
                            {
                                network.printPath(src, fPMN2.at(i).first);
                                cout << "\n\n";
                            }
                            cout << endl;
                        }
                        if (input2 == "6")
                            cont2 = false;
                    }
                }

                if (input1 == "3")
                    cont = false;
                if (input1 == "4")
                {
                    cont = false;
                    cont5 = false;
                }


            }
        }

    }

    if (in == "2")
    {
        cout << "Welcome to the Friendship Recommender!\n\n";

        cout << "Please enter your name: \n";
        getline(cin, name);
        cout << "Enter one of your personality traits: \n";
        getline(cin, personality);
        cout << "Enter your favorite music genre: \n";
        getline(cin, music);
        cout << "Enter your nationality: \n";
        getline(cin, nationality);
        cout << "\n\n";

        Person src(name, personality, music, nationality, ID);

        /*auto begin = Clock::now();*/
        GraphEL network2(1000, 5, src);
        /*auto end = Clock::now();
        auto time = (double)chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / (1000000000);
        cout << "Network EL: " << time << " seconds\n\n";*/

        bool cont6 = true;

        while (cont6)
        {

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
                BFSEL = network2.friendsDFS(src, personality, music, nationality);
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
                            << "4. Double Matches\n" << "5. Triple match\n" << "6. Change to my/chosen traits\n\n";
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
                        if (input2 == "2")
                        {
                            cout << "Recommending by Music Genre: \n" << "Your closest matches are... \n\n";
                            for (int i = 0; i < 3; i++)
                            {
                                network2.printPath(src, fMusic3.at(i).first);
                                cout << "\n\n";
                            }
                        }
                        if (input2 == "3")
                        {
                            cout << "Recommending by Nationality: \n" << "Your closest matches are... \n\n";
                            for (int i = 0; i < 3; i++)
                            {
                                network2.printPath(src, fNation3.at(i).first);
                                cout << "\n\n";
                            }
                        }
                        if (input2 == "4")
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
                        if (input2 == "5")
                        {
                            cout << "Showing triple matches: \n";
                            int max = 3;
                            if (fPMN3.size() == 0)
                                cout << "No matches\n";
                            if (fPMN3.size() < 3)
                                max = fPMN3.size();
                            for (int i = 0; i < max; i++)
                            {
                                network2.printPath(src, fPMN3.at(i).first);
                                cout << "\n\n";
                            }
                            cout << endl;
                        }
                        if (input2 == "6")
                            cont2 = false;
                    }
                }

                if (input1 == "2")
                {
                    string personality2;
                    string music2;
                    string nationality2;

                    cout << "Search new traits: \n\n";
                    cout << "Enter a personality trait: \n";
                    getline(cin, personality2);
                    cout << "Enter a music genre: \n";
                    getline(cin, music2);
                    cout << "Enter a nationality: \n";
                    getline(cin, nationality2);
                    cout << "\n\n";
                    cout << "Searching new traits...\n\n";

                    vector<vector<pair<Person, int>>> BFSEL2;

                    if (searchInput == "1")
                        BFSEL2 = network2.friendsBFS(src, personality2, music2, nationality2);
                    if (searchInput == "2")
                        BFSEL2 = network2.friendsDFS(src, personality2, music2, nationality2);

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
                            << "4. Double Matches\n" << "5. Triple match\n" << "6. Change to my/chosen traits\n\n";
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
                        if (input2 == "2")
                        {
                            cout << "Recommending by Music Genre: \n" << "Your closest matches are... \n\n";
                            for (int i = 0; i < 3; i++)
                            {
                                network2.printPath(src, fMusic4.at(i).first);
                                cout << "\n\n";
                            }
                        }
                        if (input2 == "3")
                        {
                            cout << "Recommending by Nationality: \n" << "Your closest matches are... \n\n";
                            for (int i = 0; i < 3; i++)
                            {
                                network2.printPath(src, fNation4.at(i).first);
                                cout << "\n\n";
                            }
                        }
                        if (input2 == "4")
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
                        if (input2 == "5")
                        {
                            cout << "Showing triple matches: \n";
                            int max = 3;
                            if (fPMN4.size() == 0)
                                cout << "No matches\n";
                            if (fPMN4.size() < 3)
                                max = fPMN4.size();
                            for (int i = 0; i < max; i++)
                            {
                                network2.printPath(src, fPMN4.at(i).first);
                                cout << "\n\n";
                            }
                            cout << endl;
                        }
                        if (input2 == "6")
                            cont2 = false;
                    }
                }

                if (input1 == "3")
                    cont = false;
                if (input1 == "4")
                {
                    cont = false;
                    cont6 = false;
                }

            }
        }

    }
  
	return 0;
};