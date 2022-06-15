#include <string>
#include <chrono>
#include <map>
#include <array>
#include <iostream>
using namespace std::chrono;
using namespace std;

class mapChess 
{
    // typedef map<string, int> table;
    // table x;

    // table.insert(pair<string, int>("BR", 0));

    public:
    void moveTo(map<string, int> &table, string pc, int to);
    void printBoard(map<string, int> &table);
};

void mapChess::moveTo(map<string, int> &table, string pc, int to)
{
    for (auto& i : table) {
 
        if (i.second == to) {
            // cout << "Value ", to, " already exist in ", i.first;
            table.erase(i.first);
            break;
        }
    }
    table["pc"] = to;
}

void mapChess::printBoard(map<string, int> &table)
{
    array<string, 64> arr;
    for (int i; i < 64; i++) {
         arr[i] = "000";
    }

    for (auto& i : table) {
        arr[i.second] = i.first;
    }

    for (int i = 0; i < arr.size(); i++) 
    {
        if (i + 1 % 8 == 0)
        {
            cout << "\n";
        }
        cout << arr[i], " ";
    }
}

int main()
{
    map<string, int> table;

    table["BR1"] = 0;
    table["BH1"] = 1;
    table["BB1"] = 2;
    table["BKG"] = 3;
    table["BQN"] = 4;
    table["BB2"] = 5;
    table["BH2"] = 6;
    table["BR2"] = 7;
    table["BP1"] = 8;
    table["BP2"] = 9;
    table["BP3"] = 10;
    table["BP4"] = 11;
    table["BP5"] = 12;
    table["BP6"] = 13;
    table["BP7"] = 14;
    table["BP8"] = 15;

    table["WR1"] = 56;
    table["WH1"] = 57;
    table["WB1"] = 58;
    table["WKG"] = 59;
    table["WQN"] = 60;
    table["WB2"] = 61;
    table["WH2"] = 62;
    table["WR2"] = 63;
    table["WP1"] = 48;
    table["WP2"] = 49;
    table["WP3"] = 50;
    table["WP4"] = 51;
    table["WP5"] = 52;
    table["WP6"] = 53;
    table["WP7"] = 54;
    table["WP8"] = 55;

    int to;
    string pc;
    mapChess Chess;

    cout<< "Enter the chess piece you want to move: ";
    cin >> pc;
    cout<< "Enter the chess piece position destination: ";
    cin >> to;

    auto start = high_resolution_clock::now();
    Chess.moveTo(table, pc, to);
    auto stop = high_resolution_clock::now();

    Chess.printBoard(table);
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}