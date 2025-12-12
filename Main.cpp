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

    while (playing) {

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

        /*
        System.out.println();
        System.out.println("----------- ! RIVAL BATTLE ! -----------");
        System.out.println();

        boolean defeated = false;
        int moveChoice;
        int damage;
        
        System.out.println("Rival " + rivalName + " would like to battle!");
        System.out.println("Rival " + rivalName + " sent out " + rivalpkmn.getName() + "!");
        System.out.println(starter.getName() + "! I choose you! Go!");
        while (!defeated) {
            System.out.println("What move should " + starter.getName() + " use?");
            System.out.println("1- Tackle (35 damage, 90 accuracy)");
            System.out.println("2- Pound (50 damage, 80 accuracy)");
            moveChoice = keyboard.nextInt();
            if (moveChoice == 1) {
                System.out.println(starter.getName() + " used TACKLE!");
                int hitChance = random.nextInt(10);
                int critChance = random.nextInt(24);
                if (hitChance == 5) {
                    System.out.println(starter.getName() + "'s attack missed!");
                }
                else if (critChance == 6) {
                    damage = (((((2 * starter.getLevel()) / 5) + 2) * 35) / 50) * 2;
                    System.out.println("A critical hit!");
                    rivalpkmn.setCurrenthp(rivalpkmn.getCurrenthp() - damage);
                }
                else {
                    damage = ((((2 * starter.getLevel()) / 5) + 2) * 35) / 50;
                    System.out.println("Thwack! (Neutral damage!)");
                    rivalpkmn.setCurrenthp(rivalpkmn.getCurrenthp() - damage);
                }
            }
            else {
                System.out.println(starter.getName() + " used POUND!");
                int hitChance = random.nextInt(10);
                int critChance = random.nextInt(24);
                if (hitChance == 5 || hitChance == 6) {
                    System.out.println(starter.getName() + "'s attack missed!");
                }
                else if (critChance == 6) {
                    damage = (((((2 * starter.getLevel()) / 5) + 2) * 50) / 50) * 2;
                    System.out.println("A critical hit!");
                    rivalpkmn.setCurrenthp(rivalpkmn.getCurrenthp() - damage);
                }
                else {
                    damage = ((((2 * starter.getLevel()) / 5) + 2) * 50) / 50;
                    System.out.println("Thwack! (Neutral damage!)");
                    rivalpkmn.setCurrenthp(rivalpkmn.getCurrenthp() - damage);
                }
            }

            if (rivalpkmn.getCurrenthp() < 0) {
                rivalpkmn.setCurrenthp(0);
            }

            rivalpkmn.status();
            System.out.println();

            int enemyMoveChance = random.nextInt(2);
            int enemyHitChance = random.nextInt(10);
            int enemyCritChance = random.nextInt(24);
            if (enemyMoveChance == 0) {
                System.out.println("Foe " + rivalpkmn.getName() + " used TACKLE!");
                if (enemyHitChance == 5 || enemyHitChance == 6) {
                    System.out.println(rivalpkmn.getName() + "'s attack missed!");
                }
                else if (enemyCritChance == 6) {
                    damage = (((((2 * rivalpkmn.getLevel()) / 5) + 2) * 35) / 50) * 2;
                    System.out.println("A critical hit!");
                    starter.setCurrenthp(starter.getCurrenthp() - damage);
                }
                else {
                    damage = ((((2 * rivalpkmn.getLevel()) / 5) + 2) * 35) / 50;
                    System.out.println("Thwack! (Neutral damage!)");
                    starter.setCurrenthp(starter.getCurrenthp() - damage);
                }
            }
            else {
                System.out.println("Foe " + rivalpkmn.getName() + " used POUND!");
                int hitChance = random.nextInt(10);
                int critChance = random.nextInt(24);
                if (hitChance == 5 || hitChance == 6) {
                    System.out.println(rivalpkmn.getName() + "'s attack missed!");
                }
                else if (critChance == 6) {
                    damage = (((((2 * starter.getLevel()) / 5) + 2) * 50) / 50) * 2;
                    System.out.println("A critical hit!");
                    starter.setCurrenthp(starter.getCurrenthp() - damage);
                }
                else {
                    damage = ((((2 * rivalpkmn.getLevel()) / 5) + 2) * 50) / 50;
                    System.out.println("Thwack! (Neutral damage!)");
                    starter.setCurrenthp(starter.getCurrenthp() - damage);
                }
            }

            if (starter.getCurrenthp() < 0) {
                starter.setCurrenthp(0);
            }

            starter.status();
            System.out.println();

            if (rivalpkmn.getCurrenthp() <= 0) {
                System.out.println("Foe " + rivalpkmn.getName() + " fainted!");
                System.out.println(rivalName + ": WHAT?! How did I lose?!");
                System.out.println(name + " received $500 for winning!");
                System.out.println();
                System.out.println(rivalName + ": This isn't the last you've heard of me, " + name + "! I'll win against you someday!");
                defeated = true;
            }
            else if (starter.getCurrenthp() <= 0) {
                System.out.println(starter.getName() + " fainted!");
                System.out.println(rivalName + ": HAH! I guess I WON!");
                System.out.println(rivalName + " received $500 for winning!");
                System.out.println(name + " whited out!");
                System.out.println();
                System.out.println(name + ", thinking quickly, scooped up " + starter.getName() + " and brought " + starter.getName() + " to the Pokemon Center!");
                defeated = true;
            }
        } // end of Rival battle #1

        defeated = false;

        System.out.println(starter.getName() + " leveled up to level " + (starter.getLevel() + 1) + "!");
        starter.setNewHP(30);
        String STABMove1;

        if (starter.getTyping().equals("Grass")) {
            STABMove1 = "Absorb";
        }
        else if (starter.getTyping().equals("Fire")) {
            STABMove1 = "Ember";
        }
        else {
            STABMove1 = "Water Gun";
        }
        System.out.println(starter.getName() + " learned the move " + STABMove1 + "!");

        // petalburg walking //
        boolean travelWild = true;
        System.out.println();
        System.out.println("This area is under demo, please tread with caution for bugs!");
        System.out.println(name + " entered the Petalburg Woods!");

        int totalMoves = 20; // this represents 20 steps to get out //
        int movesMade = 0;

        while (travelWild) {

            int wildCounter = random.nextInt(5) + 1;

            if (wildCounter == 1) {
                System.out.println("The bush behind " + name + " began to shake!!!");
                System.out.println();
                Pokemon randomEncounter = new Pokemon(random.nextInt(16, 28), random.nextInt(2, 7), random.nextInt(3, 9));
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
                        if (enemyHitChance == 5 || enemyHitChance == 6) {
                            System.out.println(randomEncounter.getName() + "'s attack missed!");
                        }
                        else if (enemyCritChance == 6) {
                            damage = (((((2 * starter.getLevel()) / 5) + 2) * 50) / 50) * 2;
                            System.out.println("A critical hit!");
                            starter.setCurrenthp(starter.getCurrenthp() - damage);
                        }
                        else {
                            damage = ((((2 * randomEncounter.getLevel()) / 5) + 2) * 50) / 50;
                            System.out.println("Thwack! (Neutral damage!)");
                            starter.setCurrenthp(starter.getCurrenthp() - damage);
                        }
                    }

                    if (starter.getCurrenthp() < 0) {
                        starter.setCurrenthp(0);
                    }

                    starter.status();
                    System.out.println();

                    if (randomEncounter.getCurrenthp() <= 0) {
                        System.out.println("Wild " + randomEncounter.getName() + " fainted!");
                        System.out.println(starter.getName() + " gained " + random.nextInt(50 + 1) + " EXP!");
                        defeated = true;
                    }
                    else if (starter.getCurrenthp() <= 0) {
                        System.out.println(starter.getName() + " fainted!");
                        System.out.println(name + " has no more usable Pokemon!");
                        System.out.println(name + " whited out!");
                        defeated = true;
                    }
                } // defeat end string //
                starter.setCurrenthp(30); // heals for free after battle //
                defeated = false; // allows for reoccurring fights! //
            }
            else {
                movesMade++; // 20 moves = out //
                System.out.println(name + " took another step through the Petalburg Woods! Total steps made: " + movesMade + " / 20.");
            }
            // ends the walk if 20 = 20 //
            if (movesMade == totalMoves) {
                travelWild = false;
            }
        }
        System.out.println(name + " made it to Petalburg City!");
        System.out.println("Where will " + name + " go?");
        start.townMap("Petalburg");

        System.out.println("End of DEMO!");
        playing = false;

        return 0;

    } */
    }
}
