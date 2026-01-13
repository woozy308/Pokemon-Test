#include <iostream>
#include <string>
#include <cstdlib>

#include "GameInfo.cpp"
#include "Pokemon.cpp"

using namespace std;

int main()
{
    bool playing = true;
    int startID;
    int rivalID;
    string name;
    string rivalName;

    int random = rand();

    while (playing) 
    {
        GameInfo game = GameInfo();
        game.Introduction();
        startID = game.getStartID();
        rivalID = game.getRivalID();
        name = game.getName();
        rivalName = game.getRivalName();
        game.spacer();

        Pokemon starter = Pokemon(25, 3, startID);
        starter.print();

        game.spacer();
        game.rivalIntro(rivalName, name);

        Pokemon rivalpkmn = Pokemon(25, 3, rivalID);

        cout << endl;
        cout << "----------- ! RIVAL BATTLE ! -----------" << endl;
        cout << endl;

        bool defeated = false;
        int moveChoice;
        int damage;
        
        cout << "Rival " << rivalName << " would like to battle!" << endl;
        cout << "Rival " << rivalName << " sent out " << rivalpkmn.getName() << "!" << endl;
        cout << starter.getName() << "! I choose you! Go!" << endl;
        while (!defeated) 
        {
            cout << "What move should " << starter.getName() << " use?" << endl;
            cout << "1- Tackle (35 damage, 90 accuracy)" << endl;
            cout << "2- Pound (50 damage, 80 accuracy)" << endl;
            cin >> moveChoice;
            if (moveChoice == 1) 
            {
                cout << starter.getName() << " used TACKLE!" << endl;
                int hitChance = rand() % 10;
                int critChance = rand() % 24;
                if (hitChance == 5) 
                {
                    cout << starter.getName() << "'s attack missed!" << endl;
                }
                else if (critChance == 6) 
                {
                    damage = (((((2 * starter.getLevel()) / 5) + 2) * 35) / 50) * 2;
                    cout << "A critical hit!" << endl;
                    rivalpkmn.setCurrenthp(rivalpkmn.getCurrenthp() - damage);
                }
                else 
                {
                    damage = ((((2 * starter.getLevel()) / 5) + 2) * 35) / 50;
                    cout << "Thwack! (Neutral damage!)" << endl;
                    rivalpkmn.setCurrenthp(rivalpkmn.getCurrenthp() - damage);
                }
            }
            else {
                cout << starter.getName() << " used POUND!" << endl;
                int hitChance = rand() % 10;
                int critChance = rand() % 24;
                if (hitChance == 5 || hitChance == 6) 
                {
                    cout << starter.getName() << "'s attack missed!" << endl;
                }
                else if (critChance == 6) 
                {
                    damage = (((((2 * starter.getLevel()) / 5) + 2) * 50) / 50) * 2;
                    cout << "A critical hit!" << endl;
                    rivalpkmn.setCurrenthp(rivalpkmn.getCurrenthp() - damage);
                }
                else 
                {
                    damage = ((((2 * starter.getLevel()) / 5) + 2) * 50) / 50;
                    cout << "Thwack! (Neutral damage!)" << endl;
                    rivalpkmn.setCurrenthp(rivalpkmn.getCurrenthp() - damage);
                }
            }

            if (rivalpkmn.getCurrenthp() < 0) 
            {
                rivalpkmn.setCurrenthp(0);
            }

            rivalpkmn.status();
            cout << endl;

            int enemyMoveChance = rand() % 2;
            int enemyHitChance = rand() % 24;
            int enemyCritChance = rand() % 24;
            if (enemyMoveChance == 0) {
                cout << "Foe " << rivalpkmn.getName() << " used TACKLE!" << endl;
                if (enemyHitChance == 5 || enemyHitChance == 6) 
                {
                    cout << rivalpkmn.getName() << "'s attack missed!" << endl;
                }
                else if (enemyCritChance == 6) 
                {
                    damage = (((((2 * rivalpkmn.getLevel()) / 5) + 2) * 35) / 50) * 2;
                    cout << "A critical hit!" << endl;
                    starter.setCurrenthp(starter.getCurrenthp() - damage);
                }
                else 
                {
                    damage = ((((2 * rivalpkmn.getLevel()) / 5) + 2) * 35) / 50;
                    cout << "Thwack! (Neutral damage!)" << endl;
                    starter.setCurrenthp(starter.getCurrenthp() - damage);
                }
            }
            else 
            {
                cout << "Foe " << rivalpkmn.getName() << " used POUND!" << endl;
                int hitChance = rand() % 10;
                int critChance = rand() % 24;
                if (hitChance == 5 || hitChance == 6) 
                {
                    cout << rivalpkmn.getName() << "'s attack missed!" << endl;
                }
                else if (critChance == 6) 
                {
                    damage = (((((2 * starter.getLevel()) / 5) + 2) * 50) / 50) * 2;
                    cout << "A critical hit!" << endl;
                    starter.setCurrenthp(starter.getCurrenthp() - damage);
                }
                else {
                    damage = ((((2 * rivalpkmn.getLevel()) / 5) + 2) * 50) / 50;
                    cout << "Thwack!(Neutral damage!)" << endl;
                    starter.setCurrenthp(starter.getCurrenthp() - damage);
                }
            }

            if (starter.getCurrenthp() < 0) 
            {
                starter.setCurrenthp(0);
            }

            starter.status();
            cout << endl;

            if (rivalpkmn.getCurrenthp() <= 0) 
            {
                cout << "Foe " << rivalpkmn.getName() << " fainted!" << endl;
                cout << rivalName << ": WHAT?! How did I lose?!" << endl;
                cout << name << " received $500 for winning!" << endl;
                cout << endl;
                cout << rivalName + ": This isn't the last you've heard of me, " << name << "! I'll win against you someday!" << endl;
                defeated = true;
            }
            else if (starter.getCurrenthp() <= 0) 
            {
                cout << starter.getName() << " fainted!" << endl;
                cout << rivalName << ": HAH! I guess I WON!" << endl;
                cout << rivalName << " received $500 for winning!" << endl;
                cout << name << " whited out!" << endl;
                cout << endl;
                cout << name << ", thinking quickly, scooped up " << starter.getName() << " and brought " << starter.getName() << " to the Pokemon Center!" << endl;
                defeated = true;
            }
        } // end of Rival battle #1

        defeated = false;

        cout << starter.getName() << " leveled up to level " << (starter.getLevel() + 1) << "!" << endl;
        starter.setNewHP(30);
        string STABMove1;

        if (starter.getTyping() == "Grass")
        {
            STABMove1 = "Absorb";
        }
        else if (starter.getTyping() == "Fire")
        {
            STABMove1 = "Ember";
        }
        else {
            STABMove1 = "Water Gun"; // water //
        }
        cout << starter.getName() << " learned the move " << STABMove1 << "!" << endl;

        // petalburg walking //
        bool travelWild = true;
        cout << endl;

        cout << "Now, it's time for " << name << "'s journey to begin!" << endl;
        cout << name << " entered the Petalburg Woods!" << endl;

        int totalMoves = 20; // this represents 20 steps to get out //
        int movesMade = 0;

        while (travelWild) {

            int wildCounter = rand() % 4; // this is about 25% //

            if (wildCounter == 1) 
            {
                cout << "The bush behind " << name << " began to shake!!!" << endl;
                cout << endl;
                Pokemon randomEncounter = new Pokemon(28, 4, rand()); // simplified temporarily //
                System.out.println("A wild " + randomEncounter.getName() + " appeared!");
                // this has to be outside, or else loop continues! (bug fix: 10/20/2025) //
                while (!defeated) {
                    System.out.println("What move should " + starter.getName() + " use?");
                    System.out.println("1- Tackle (35 damage, 90 accuracy)");
                    System.out.println("2- Pound (50 damage, 80 accuracy)");
                    System.out.println("3- " + STABMove1 + " (35 damage, 100 accuracy)");
                    moveChoice = keyboard.nextInt();

                    int hitChance = random.nextInt(10);
                    int critChance = random.nextInt(24);

                    if (moveChoice == 1) {
                        System.out.println(starter.getName() + " used TACKLE!");
                        if (hitChance == 5) {
                            System.out.println(starter.getName() + "'s attack missed!");
                        }
                        else if (critChance == 6) {
                            damage = (((((2 * starter.getLevel()) / 5) + 2) * 35) / 50) * 2;
                            System.out.println("A critical hit!");
                            randomEncounter.setCurrenthp(randomEncounter.getCurrenthp() - damage);
                        }
                        else {
                            damage = ((((2 * starter.getLevel()) / 5) + 2) * 35) / 50;
                            randomEncounter.setCurrenthp(randomEncounter.getCurrenthp() - damage);
                        }
                    }
                    else if (moveChoice == 2) {
                        System.out.println(starter.getName() + " used POUND!");

                        if (hitChance == 5 || hitChance == 6) {
                            System.out.println(starter.getName() + "'s attack missed!");
                        }
                        else if (critChance == 6) {
                            damage = (((((2 * starter.getLevel()) / 5) + 2) * 50) / 50) * 2;
                            System.out.println("A critical hit!");
                            randomEncounter.setCurrenthp(randomEncounter.getCurrenthp() - damage);
                        }
                        else {
                            damage = ((((2 * starter.getLevel()) / 5) + 2) * 50) / 50;
                            System.out.println("Thwack! (Neutral damage!)");
                            randomEncounter.setCurrenthp(randomEncounter.getCurrenthp() - damage);
                        }
                    }
                    else {
                        System.out.println(starter.getName() + " used " + STABMove1 + "!");

                        if (critChance == 6) {
                            damage = (((((2 * starter.getLevel()) / 5) + 2) * 35) / 50) * 2;
                            System.out.println("A critical hit!");
                            randomEncounter.setCurrenthp(randomEncounter.getCurrenthp() - damage);
                        }
                        else {
                            if (randomEncounter.isSuperEffective(starter.getIndex(), randomEncounter.getIndex())) {
                                damage = (((((2 * starter.getLevel()) / 5) + 2) * 35) / 50) * 2; // super effective //
                                System.out.println("It's super effective!");
                                randomEncounter.setCurrenthp(randomEncounter.getCurrenthp() - damage);
                            }
                            else if (randomEncounter.isNotEffective(starter.getIndex(), randomEncounter.getIndex())) {
                                damage = (((((2 * starter.getLevel()) / 5) + 2) * 35) / 50) / 2; // not effective //
                                System.out.println("It's not very effective...");
                                randomEncounter.setCurrenthp(randomEncounter.getCurrenthp() - damage);
                            }
                            else {
                                damage = (((((2 * starter.getLevel()) / 5) + 2) * 35) / 50); // neutral //
                                System.out.println("Thwack! (Neutral damage!)");
                                randomEncounter.setCurrenthp(randomEncounter.getCurrenthp() - damage);
                            }
                        }
                    }

                    if (randomEncounter.getCurrenthp() < 0) {
                        randomEncounter.setCurrenthp(0);
                    }

                    randomEncounter.status();
                    System.out.println();

                    int enemyMoveChance = random.nextInt(2);
                    int enemyHitChance = random.nextInt(10);
                    int enemyCritChance = random.nextInt(24);
                    if (enemyMoveChance == 0) {
                        System.out.println("Wild " + randomEncounter.getName() + " used TACKLE!");
                        if (enemyHitChance == 5 || enemyHitChance == 6) {
                            System.out.println(randomEncounter.getName() + "'s attack missed!");
                        }
                        else if (enemyCritChance == 6) {
                            damage = (((((2 * randomEncounter.getLevel()) / 5) + 2) * 35) / 50) * 2;
                            System.out.println("A critical hit!");
                            starter.setCurrenthp(starter.getCurrenthp() - damage);
                        }
                        else {
                            damage = ((((2 * randomEncounter.getLevel()) / 5) + 2) * 35) / 50;
                            System.out.println("Thwack! (Neutral damage!)");
                            starter.setCurrenthp(starter.getCurrenthp() - damage);
                        }
                    }
                    else {
                        System.out.println("Wild " + randomEncounter.getName() + " used POUND!");
                        if (enemyHitChance == 5 || enemyHitChance == 6) 
                        {
                            System.out.println(randomEncounter.getName() + "'s attack missed!");
                        }
                        else if (enemyCritChance == 6) 
                        {
                            damage = (((((2 * starter.getLevel()) / 5) + 2) * 50) / 50) * 2;
                            System.out.println("A critical hit!");
                            starter.setCurrenthp(starter.getCurrenthp() - damage);
                        }
                        else 
                        {
                            damage = ((((2 * randomEncounter.getLevel()) / 5) + 2) * 50) / 50;
                            System.out.println("Thwack! (Neutral damage!)");
                            starter.setCurrenthp(starter.getCurrenthp() - damage);
                        }
                    }

                    if (starter.getCurrenthp() < 0) 
                    {
                        starter.setCurrenthp(0);
                    }

                    starter.status();
                    System.out.println();

                    if (randomEncounter.getCurrenthp() <= 0) 
                    {
                        System.out.println("Wild " + randomEncounter.getName() + " fainted!");
                        System.out.println(starter.getName() + " gained " + random.nextInt(50 + 1) + " EXP!");
                        defeated = true;
                    }
                    else if (starter.getCurrenthp() <= 0) 
                    {
                        System.out.println(starter.getName() + " fainted!");
                        System.out.println(name + " has no more usable Pokemon!");
                        System.out.println(name + " whited out!");
                        defeated = true;
                    }
                } // defeat end string //
                starter.setCurrenthp(30); // heals for free after battle //
                defeated = false; // allows for reoccurring fights! //
            }
            else 
            {
                movesMade++; // 20 moves = out //
                cout << name << " took another step through the Petalburg Woods! Total steps made: " << movesMade << " / 20." << endl;
            }
            // ends the walk if 20 = 20 //
            if (movesMade == totalMoves) 
            {
                travelWild = false;
            }
        }
        cout << name << " made it to Petalburg City!" << endl;
        cout << "Where will " << name << " go?" << endl;
        game.townMap("Petalburg");

        cout << "End of DEMO!" << endl;
        playing = false;

        return 0;

    }
}