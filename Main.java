package CS143.jtnguyen5;

import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        boolean playing = true;
        int startID;
        int rivalID;
        String name;
        String rivalName;

        Scanner keyboard = new Scanner(System.in);
        Random random = new Random();

        while (playing) {

            System.out.println("Please insert your name.");
            name = keyboard.next();

            System.out.println("Please insert your rival's name.");
            rivalName = keyboard.next();

            if (rivalName.equals(name)) {
                rivalName = "Johanna";
            }

            System.out.println();
            System.out.println();
            System.out.println();

            System.out.println("Pick your starter!");
            System.out.println("1- Treecko (Grass)");
            System.out.println("2- Torchic (Fire)");
            System.out.println("3- Mudkip (Water)");
            startID = keyboard.nextInt();
            if (startID > 3 || startID < 1) {
                startID = random.nextInt(3) + 1; // randomizer for starter //

            }
            Pokemon starter = new Pokemon(25, 3,startID);
            starter.print();

            System.out.println();
            System.out.println();
            System.out.println();

            System.out.println(rivalName + ": HEY!");
            System.out.println("It's your rival, " + rivalName + ".");
            System.out.println(rivalName + ": I see you got your first Pokemon, " + name + ". Come on, let's BATTLE!");
            if (startID == 1) {
                rivalID = 2;
            }
            else if (startID == 2) {
                rivalID = 3;
            }
            else if (startID == 3) {
                rivalID = 1;
            }
            else {
                rivalID = 2;
            }
            Pokemon rivalpkmn = new Pokemon(25, 3, rivalID);

            System.out.println();
            System.out.println("----------- ! RIVAL BATTLE ! -----------");
            System.out.println();

            boolean defeated = false;
            int moveChoice;
            int damage;

            System.out.println("POKEMON Trainer " + rivalName + " would like to battle!");
            System.out.println("POKEMON Trainer " + rivalName + " sent out " + rivalpkmn.getName() + "!");
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

            starter.setNewHP(32);

            System.out.println(starter.getName() + " leveled up to level " + (starter.getLevel() + 1) + "!!!");

            String STABMove1;

            if (starter.getTyping().equals("Grass")) {
               STABMove1 = "Leaf Blade";
            }
            else if (starter.getTyping().equals("Fire")) {
                STABMove1 = "Inferno";
            }
            else {
                STABMove1 = "Water Gun";
            }

            System.out.println(starter.getName() + " learned the move " + STABMove1 + "!");

            System.out.println();
            System.out.println("This area is under demo, please tread with caution for bugs!");
            System.out.println(name + "entered the Petalburg Woods!");
            System.out.println("The bush behind " + name + " began to shake!!!");
            System.out.println();

            // TESTING TESTING //

            Pokemon randomEncounter = new Pokemon(36, 5, random.nextInt(3 + 1));

            System.out.println("A wild " + randomEncounter.getName() + " APPEARED!");
            while (!defeated) {
                System.out.println("What move should " + starter.getName() + " use?");
                System.out.println("1- Tackle (35 damage, 90 accuracy)");
                System.out.println("2- Pound (50 damage, 80 accuracy)");
                System.out.println("3- " + STABMove1 + " (80 damage, 100 accuracy");
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
                        randomEncounter.setCurrenthp(randomEncounter.getCurrenthp() - damage);
                    }
                }
                else {
                    System.out.println(starter.getName() + " used " + STABMove1 + "!");

                    if (critChance == 6) {
                        damage = (((((2 * starter.getLevel()) / 5) + 2) * 80) / 50) * 2;
                        System.out.println("A critical hit!");
                        randomEncounter.setCurrenthp(randomEncounter.getCurrenthp() - damage);
                    }
                    else {
                        if (randomEncounter.isSuperEffective(starter.getIndex(), randomEncounter.getIndex())) {
                            damage = (((((2 * starter.getLevel()) / 5) + 2) * 80) / 50) * 2; // super effective //
                            System.out.println("It's super effective!");
                            randomEncounter.setCurrenthp(randomEncounter.getCurrenthp() - damage);
                        }
                        else if (randomEncounter.isNotEffective(starter.getIndex(), randomEncounter.getIndex())){
                            damage = (((((2 * starter.getLevel()) / 5) + 2) * 80) / 50) / 2; // not effective //
                            System.out.println("It's not very effective...");
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
            } // wild encounter //

        }

        // game ends "!playing" //

    }
}