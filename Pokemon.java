
public class Pokemon {

    public String name;
    public int hp;
    public int currenthp;
    public int level;
    public int index;
    public String typing;
    public int hpNew;

    public Pokemon() {

    }

    public Pokemon(int hp, int level, int index) {
        this.hp = hp;
        currenthp = hp;
        this.level = level;
        this.index = index;

        if (index == 1) {
            name = "Treecko";
            typing = "Grass";
        }
        else if (index == 2) {
            name = "Torchic";
            typing = "Fire";
        }
        else if (index == 3) {
            name = "Mudkip";
            typing = "Water";
        }
        else {
            name = "Skarmory";
            typing = "Steel";
        }
    }

    public boolean isSuperEffective(int index, int rivalIndex) {
        if (index == 1 && rivalIndex == 3) {
            return true;
        }
        else if (index == 2 && rivalIndex == 1) {
            return true;
        }
        else if (index == 3 && rivalIndex == 2) {
            return true;
        }
        else {
            return false;
        }
    }

    public boolean isNotEffective(int index, int rivalIndex) {
        if (index == 1 && rivalIndex == 1) { // grass v grass //
            return true;
        }
        else if (index == 1 && rivalIndex == 2) { // grass v fire //
            return true;
        }
        else if (index == 2 && rivalIndex == 2) { // fire v fire //
            return true;
        }
        else if (index == 2 && rivalIndex == 3) { // fire v water //
            return true;
        }
        else if (index == 3 && rivalIndex == 3) { // water v water //
            return true;
        }
        else if (index == 3 && rivalIndex == 1) { // water v grass //
            return true;
        }
        else {
            return false;
        }
    }

    public void print() {
        System.out.println(name + ", Type: " + typing + ", HP: " + currenthp + "/" + hp);
    }

    public void status() {
        System.out.println(name + ", HP: " + currenthp + "/" + hp);
    }

    public String getName() {
        return name;
    }

    public int getCurrenthp() {
        return currenthp;
    }

    public void setCurrenthp(int currenthp) {
        this.currenthp = currenthp;
    }

    public void setNewHP(int newHp) {
        this.hp = newHp;
        this.currenthp = newHp;
    }

    public int getLevel() {
        return level;
    }

    public String getTyping() {
        return typing;
    }

    public int getIndex() {
        return index;
    }

}

