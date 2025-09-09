import java.util.Random;
import java.util.Scanner;
    
public class GameInfo {

    public String name;
    public String rivalName;
    public String gender;
    public int startID;
    public int rivalID;

    public GameInfo() {

    }

    public void Introduction() {
        Scanner keyboard = new Scanner(System.in);
        Random random = new Random();

        System.out.println("Ah, I see you're finally awake!");
        System.out.println("Welcome to the Pokemon island of Hoenn!");
        System.out.println("My name is Professor Birch, and I'm so happy to meet you!");
        System.out.println("Please, what is your name?");
        name = keyboard.next();
        System.out.println("A pleasure to meet you, " + name + "!");
        System.out.println("Are you a boy or a girl? (please answer only 'boy' or 'girl')");
        gender = keyboard.next();
        boolean rivalIsBoy = true;

        if (gender.equals("boy")) {
            rivalIsBoy = false; // sets Rival to female default //
        } else if (!gender.equals("boy") || !gender.equals("girl")) {
            rivalIsBoy = false;
        }

        System.out.println("Now, what is the name of your rival?");
        rivalName = keyboard.next();

        if (rivalName.equals(name) && rivalIsBoy) {
            rivalName = "Brendan";
        } else if (rivalName.equals(name) && !rivalIsBoy) {
            rivalName = "May";
        }

        System.out.println("I see. Your rival is named " + rivalName + "!");
        System.out.println("Now, here's the fun part- you get to choose your very own first Pokemon!");
        System.out.println("Make sure you choose wisely!");
        System.out.println("1- Treecko (Grass)");
        System.out.println("2- Torchic (Fire)");
        System.out.println("3- Mudkip (Water)");

        startID = keyboard.nextInt();
        if (startID > 3 || startID < 1) {
            startID = random.nextInt(3) + 1; // randomizer for starter //
        }

        if (startID == 1) { // rivalID based off of the chosen starter //
            rivalID = 2;
        } else if (startID == 2) {
            rivalID = 3;
        } else {
            rivalID = 1;
        }
        System.out.println("So you have chosen your starter. Good! Now get out there, and have fun!");
        System.out.println("Please note that this introduction is still under revision!");
    }

    public void spacer() {      // this is formatting //
        System.out.println();
        System.out.println();
        System.out.println();
    }

    public int getRivalID() {
        return rivalID;
    }

    public int getStartID() {
        return startID;
    }

    public String getGender() {
        return gender;
    }

    public String getRivalName() {
        return rivalName;
    }

    public String getName() {
        return name;
    }
}
