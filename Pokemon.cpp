#include <iostream>
#include <string>

using namespace std;

class Pokemon
{
	public:
        string name;
        int hp = 0;
        int currenthp = 0;
        int level = 0;
        int index = 0;
        string typing;

        Pokemon(int hp, int level, int index)
        {
            this->hp = hp;
            currenthp = hp;
            this->level = level;
            this->index = index;

            if (index == 1) 
            {
                name = "Treecko";
                typing = "Grass";
            }
            else if (index == 2) 
            {
                name = "Torchic";
                typing = "Fire";
            }
            else if (index == 3) 
            {
                name = "Mudkip";
                typing = "Water";
            }
            else { // wild encounters! //
                
                switch (index) 
                {
                case 4:
                    name = "Weedle";
                    typing = "Bug";
                    break;
                case 5:
                    name = "Pidgey";
                    typing = "Flying";
                    break;
                case 6:
                    name = "Sentret";
                    typing = "Normal";
                    break;
                case 7:
                    name = "Sunflora";
                    typing = "Grass";
                    break;
                case 8:
                    name = "Marill";
                    typing = "Water";
                    break;
                case 9:
                    name = "Slugma";
                    typing = "Fire";
                    break;
                default:
                    name = "Skarmory";
                    typing = "Steel";
                    break;
                }
            }
        }

        bool isSuperEffective(int index, int rivalIndex) 
        {
            if (index == 1 && (rivalIndex == 3)) 
            {
                return true;
            }
            else if (index == 2 && rivalIndex == 1) 
            {
                return true;
            }
            else if (index == 3 && rivalIndex == 2) 
            {
                return true;
            }
            else 
            {
                return false;
            }
        }

        bool isNotEffective(int index, int rivalIndex) 
        {
            if (index == 1 && rivalIndex == 1) 
            { // grass v grass //
                return true;
            }
            else if (index == 1 && rivalIndex == 2) 
            { // grass v fire //
                return true;
            }
            else if (index == 2 && rivalIndex == 2) 
            { // fire v fire //
                return true;
            }
            else if (index == 2 && rivalIndex == 3) 
            { // fire v water //
                return true;
            }
            else if (index == 3 && rivalIndex == 3) 
            { // water v water //
                return true;
            }
            else if (index == 3 && rivalIndex == 1) 
            { // water v grass //
                return true;
            }
            else 
            {
                return false;
            }
        }

        void print() 
        {
            cout << name << ", Type: " << typing << ", HP: " << currenthp << "/" << hp << endl;
        }

        void status() 
        {
            cout << name << ", HP: " << currenthp << "/" << hp << endl;
        }

        string getName() 
        {
            return name;
        }

        // setters/getters //
        int getCurrenthp() 
        {
            return currenthp;
        }

        void setCurrenthp(int currenthp) 
        {
            this->currenthp = currenthp;
        }

        void setNewHP(int newHp) 
        {
            this->hp = newHp;
            this->currenthp = newHp;
        }

        int getLevel() 
        {
            return level;
        }

        string getTyping() 
        {
            return typing;
        }

        int getIndex() 
        {
            return index;
        }

};