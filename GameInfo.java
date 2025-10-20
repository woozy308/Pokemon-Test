import java.util.Random;
import java.util.Scanner;
    
public class GameInfo {

    public String name;
    public String rivalName;
    public String gender;
    public String rivalGender;
    public int startID;
    public int rivalID;

    public GameInfo() {

    }

    public void Introduction() {
        Scanner keyboard = new Scanner(System.in);
        Random random = new Random();

        System.out.println("Ah, I see you're finally awake!");
        System.out.println("Welcome to the island of Hoenn, shared by humans and Pokemon!");
        System.out.println("My name is Professor Birch, and I'm so happy to meet you!");
        System.out.println("Please, what is your name?");
        name = keyboard.next();
        System.out.println("A pleasure to meet you, " + name + "!");
        System.out.println("Are you a boy or a girl? (please answer only 'boy' or 'girl')");
        gender = keyboard.next();

        if (gender.equals("boy")) {
            rivalGender = "girl"; // sets Rival to female default //
        } else if (gender.equals("girl")) {
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
        System.out.println("Make sure you pick wisely, you only get one and one chance to pick them!");
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
        System.out.println("Please note that this introduction is still under revision!");
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
        System.out.println("???: What's your name? Mine's " + rivalName +".");
        System.out.println(rivalName + ": Ah, your name is " + name + "!");
        System.out.println(rivalName + ": Well, I see you've got a new Pokemon. WELL, so do I! Let's BATTLE!!!");
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
