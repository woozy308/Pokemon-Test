#include <iostream>
#include <string>

using namespace std;

class GameInfo
{
    public:

    GameInfo()
    {}

    string name;
    string rivalName;
    string gender;
    string rivalGender;
    int startID = 0;
    int rivalID = 0;

    void Introduction() 
    {
        int random = rand();

        cout << "Ah, I see you're finally awake!" << endl;
        cout << "Welcome to the island of Hoenn, shared by humans and Pokemon!" << endl;
        cout << "My name is Professor Birch, and I'm so happy to meet you!" << endl;
        cout << "Please, what is your name?" << endl;
        cin >> name;
        cout << "A pleasure to meet you, " << name << "!" << endl;
        cout << "Are you a boy or a girl? (please answer only 'boy' or 'girl')" << endl;
        cin >> gender;

        if (gender == "boy")
        {
            rivalGender = "girl"; // sets Rival to female default //
        }
        else if (gender == "girl") {
            rivalGender = "boy"; // sets Rival to male default //
        }

        cout << "Now, what is the name of your rival?" << endl;
        cin >> rivalName;

        if ((rivalName == name || rivalName == "") && rivalGender == "boy") 
        {
            rivalName = "Brendan";
        }
        else if ((rivalName == name || rivalName == "") && rivalGender == "girl") 
        {
            rivalName = "May";
        }

        cout << "I see. Your rival is named " + rivalName + "!" << endl;
        cout << "Now, here's the fun part- you get to choose your very own first Pokemon!" << endl;
        cout << "Make sure you pick wisely, you only get one chance to pick whichever!" << endl;
        cout << "1- Treecko (Grass)" << endl;
        cout << "2- Torchic (Fire)" << endl;
        cout << "3- Mudkip (Water)" << endl;

        cin >> startID;
        if (startID > 3 || startID < 1) {
            startID = rand() % (3 - 1 + 1) + 1; // randomizer for starter //
        }

        if (startID == 1) { // rivalID based off of the chosen starter, mudkip default starter //
            rivalID = 2;
            cout << "So you have chosen Treecko, the Grass Pokemon. Wise choice!" << endl;
        }
        else if (startID == 2) {
            rivalID = 3;
            cout << "So you have chosen Torchic, the Fire Pokemon. Flaming choice!" << endl;
        }
        else {
            rivalID = 1;
            cout << "So you have chosen Mudkip, the Water Pokemon. Great choice!" << endl;
        }
        cout << "You received a PokeBall from Professor Birch!" << endl;
        cout << "Here's also another little gift. Be safe out there!" << endl;
        cout << "You were given a Potion by Professor Birch!" << endl;
        cout << "Good luck, and happy hunting! I hope to see you in the big leagues someday!" << endl;
    }

    // Spacer formatting //

    void spacer() {
        cout << endl;
        cout << endl;
        cout << endl;
    }

    void rivalIntro(string rivalName, string name) {
        cout << "???: Hey, you!" << endl;
        cout << "A strange, but bumbling " << rivalGender << " runs over to you." << endl;
        cout << "???: You must be the new " << gender << " in town." << endl;
        cout << "???: What's your name? Mine's " << rivalName << "." << endl;
        cout << rivalName << ": Ah, your name is " << name << "!" << endl;
        cout << rivalName << ": Well, I see you've got a new Pokemon. WELL, so do I! Let's BATTLE!!!" << endl;
    }

    void townMap(string townName) {
        cout << "1- PokeMart" << endl;
        cout << "2- PokeCenter" << endl;
        cout << "3- " + townName + " Gym" << endl;
        cout << "4- Go back" << endl;
        
        cout << "Under C++ demo!" << endl;
    }

    // Getters and Setters //

    int getRivalID() 
    {
        return rivalID;
    }

    int getStartID() 
    {
        return startID;
    }

    string getRivalName()
    {
        return rivalName;
    }

    string getName()
    {
        return name;
    }
};