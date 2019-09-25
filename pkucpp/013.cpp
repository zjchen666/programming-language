#include <iostream>
#include <string>
#include <iomanip>
#include <unordered_map>

using namespace std;

string red_seq[5] = {"iceman", "lion", "wolf", "ninja", "dragon"};
string blue_seq[5] = {"lion", "dragon", "ninja", "iceman", "wolf"};
string input_list[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};

class CArmy {
    public:
        int m;
        int index;
        int id;
        int time;
        bool stopped;
        unordered_map<string, int> count_map;
        string name;

    CArmy(int total_life, bool red) {
        m = total_life;
        if (red) { 
            name = "red"; 
        } else { 
            name = "blue";
        }
        stopped = false;
        time = 0;
        id = 1;
        index = 0;
        for (int i = 0; i < 5; ++i) {
            count_map[input_list[i]] = 0;
        }
    }

    bool CreateWarriors(unordered_map<string, int> & life_table, string* seq) {
        int number = 0;
        int strength;

        if (stopped) {
            cout << setfill('0') << setw(3) << time << " " << name << " headquarter stops making warriors" << endl;
            stopped = false;
            return false;
        }

        while (number < 5) {
            strength = life_table[seq[index]];
            if (m >= strength) {
                m -= strength;
                count_map[seq[index]]++; 
                cout << setfill('0') << setw(3) << time << " " << name << " " << seq[index] << " " << id << " born with strength " << strength << "," <<
                      count_map[seq[index]] << " " << seq[index] << " in " << name << " headquarter" << endl;
                time++;
                id++;
                index = (index + 1) % 5;
                break;       
            }
            index = (index + 1) % 5;
            number++;
        }

        if (5 == number) { stopped = true; }
        int i = 0;
        while (i < 5) {
            if (m >= life_table[seq[i]])
                break;
            i++;
        }
        if (i == 5) {stopped = true;}

        return true;
    }
};

int main() {
    int loop = 0;
    int m = 0;
    int i = 1;
    bool red_can_create = true;
    bool blue_can_create = true;

    cin >> loop;
    unordered_map<string, int> life_value_table;

    while (i <= loop) {
        cout << "Case:" << i << endl;
        cin >> m;
        CArmy* red_army = new CArmy(m, true);
        CArmy* blue_army = new CArmy(m, false);

        for (int j = 0; j < 5; ++j) {
            cin >> life_value_table[input_list[j]];
        }

        while (red_can_create || blue_can_create) {
            if (red_can_create) red_can_create = red_army->CreateWarriors(life_value_table, red_seq);
            if (blue_can_create) blue_can_create = blue_army->CreateWarriors(life_value_table, blue_seq);
        }

        delete red_army;
        delete blue_army;
        red_can_create = true;
        blue_can_create = true;
        life_value_table.clear();
        i++;
    }
    return 0;
}