import java.util.Random;
import java.util.Scanner;
    
public class GameInfo {

    Scanner keyboard = new Scanner(System.in);
    Random random = new Random();

    public String name;
    public String rivalName;
    public String gender;
    public String rivalGender;
    public int startID;
    public int rivalID;

    public GameInfo() {

    }

    public void Introduction() {
        System.out.println("Ah, I see you're finally awake!");
        System.out.println("Welcome to the island of Hoenn, shared by humans and Pokemon!");
        System.out.println("My name is Professor Birch, and I'm so happy to meet you!");
        System.out.println("Please, what is your name?");
        name = keyboard.next();
        System.out.println("A pleasure to meet you, " + name + "!");
        System.out.println("Are you a boy or a girl? (please answer only 'boy' or 'girl')");
        gender = keyboard.next();

        if (gender.equals("boy") || gender.equals("Boy")) {
            rivalGender = "girl"; // sets Rival to female default //
        } else if (gender.equals("girl") || gender.equals("Girl")) {
            rivalGender = "boy"; // sets Rival to male default //
        }

        System.out.println("Now, what is the name of your rival?");
        rivalName = keyboard.next();

        if ((rivalName.equals(name) || rivalName.isBlank()) && rivalGender.equals("boy")) {
            rivalName = "Brendan";
        } else if ((rivalName.equals(name) || rivalName.isBlank()) && rivalGender.equals("girl")) {
            rivalName = "May";
        }

        System.out.println("I see. Your rival is named " + rivalName + "!");
        System.out.println("Now, here's the fun part- you get to choose your very own first Pokemon!");
        System.out.println("Make sure you pick wisely, you only get one chance to pick whichever!");
        System.out.println("1- Treecko (Grass)");
        System.out.println("2- Torchic (Fire)");
        System.out.println("3- Mudkip (Water)");

        startID = keyboard.nextInt();
        if (startID > 3 || startID < 1) {
            startID = random.nextInt(3) + 1; // randomizer for starter //
        }

        if (startID == 1) { // rivalID based off of the chosen starter, mudkip default starter //
            rivalID = 2;
            System.out.println("So you have chosen Treecko, the Grass Pokemon. Wise choice!");
        } else if (startID == 2) {
            rivalID = 3;
            System.out.println("So you have chosen Torchic, the Fire Pokemon. Flaming choice!");
        } else {
            rivalID = 1;
            System.out.println("So you have chosen Mudkip, the Water Pokemon. Great choice!");
        }
        System.out.println("You received a PokeBall from Professor Birch!");
        System.out.println("Here's also another little gift. Be safe out there!");
        System.out.println("You were given a Potion by Professor Birch!");
        System.out.println("Good luck, and happy hunting! I hope to see you in the big leagues someday!");
    }

    // Spacer formatting //

    public void spacer() {
        System.out.println();
        System.out.println();
        System.out.println();
    }

    public void rivalIntro(String rivalName, String name) {
        System.out.println("???: Hey, you!");
        System.out.println("A strange, but bumbling " + rivalGender + " runs over to you.");
        System.out.println("???: You must be the new " + gender + " in town.");
        System.out.println("???: What's your name? My name is " + rivalName +".");
        System.out.println(rivalName + ": Ah, your name is " + name + "!");
        System.out.println(rivalName + ": Well, I see you've got a new Pokemon. WELL, so do I! Let's BATTLE!!!");
    }

    // Town Map interactions and the town utilities //

    public void townMap(String townName) {
        int action = 0;
        System.out.println("1- PokeMart");
        System.out.println("2- PokeCenter");
        System.out.println("3- " + townName + " Gym");
        System.out.println("4- Go back");
        action = keyboard.nextInt();

        switch (action) {
            case 1:
                PokeMart();
                break;
            case 2:
                PokeCenter();
                break;
            case 3:
                Gym(townName);
                break;
            case 4:
                goBack();
                break;
            default:
                break;
        }

        System.out.println("Under Work");
    }

    public void PokeMart() {
        System.out.println("You entered the PokeMart!");
        System.out.println("PokeMart Worker: Hello, and welcome to the PokeMart!");
        System.out.println("PokeMart Worker: How can I help you today?");
    }

    public void PokeCenter() {

    }

    public void Gym(String townName) {

    }

    public void goBack() {

    }

    // Getters and Setters //
    
    public int getRivalID() {
        return rivalID;
    }

    public int getStartID() {
        return startID;
    }

    public String getRivalName() {
        return rivalName;
    }

    public String getName() {
        return name;
    }
}
