#include <string>
#include <chrono>
#include <iostream>
using namespace std::chrono;
using namespace std;

class FENChess
{
    string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";

    public:
    void moveTo(string pc, int to);
    void printBoard();
    int getPosition(string pc);
};

int FENChess::getPosition(string pc)
{
    int y, count = 0;
    string i = to_string(fen[y]);
    while (i != pc)
    {
        if (stoi(i) % 1 == 0)
            count += stoi(i);
        y++;
        i = to_string(fen[y]);
    }
    count += y--;

    return count;
}

void FENChess::moveTo(string pc, int to)
{
    int from  = getPosition(pc);
    for (int i; i < fen.length(); i++)
    {
        if (stoi(to_string(fen[i])) % 1 == 0)
        {
            from -= stoi(to_string(fen[i]));
            to -= stoi(to_string(fen[i]));
        }

    }
        if (stoi(to_string(fen[to+1])) % 1 == 0)
            fen[to+1] = stoi(to_string(fen[to+1]))-1;
        else if (stoi(to_string(fen[to-1])) % 1 == 0)
            fen[to-1] = stoi(to_string(fen[to+1]))-1;
    fen[to] = fen[from];
        if (stoi(to_string(fen[from+1])) % 1 == 0)
            fen[from+1] = stoi(to_string(fen[to+1]))-1;
        else if (stoi(to_string(fen[from-1])) % 1 == 0)
            fen[from-1] = stoi(to_string(fen[to+1]))-1;
        else
            fen[from] = '1';
}

void FENChess::printBoard()
{
    for (int i; i < fen.length(); i++)
    {
        if (fen[i] == 'r')
            cout << "BR ";
            else if (fen[i] == 'n')
                cout << "BH ";
                else if (fen[i] == 'b')
                    cout << "BB ";
                        else if (fen[i] == 'q')
                        cout << "BQ ";
                            else if (fen[i] == 'k')
                            cout << "BK ";
                                else if (fen[i] == 'p')
                                cout << "BP ";

        else if (fen[i] == '/')
        cout << "\n";

        else if (fen[i] == 'R')
            cout << "WR ";
            else if (fen[i] == 'N')
                cout << "WH ";
                else if (fen[i] == 'B')
                    cout << "WB ";
                        else if (fen[i] == 'Q')
                        cout << "WQ ";
                            else if (fen[i] == 'K')
                            cout << "WK ";
                                else if (fen[i] == 'P')
                                cout << "WP ";

        else
            for (int y; y < stoi(to_string(fen[i])); y++)
                cout << string(stoi(to_string(fen[i])), '00 ');
    }
}

int main() 
{
    int to;
    string pc;
    FENChess Chess;

    cout<< "Enter the chess piece you want to move: ";
    cin >> pc;
    cout<< "Enter the chess piece position destination: ";
    cin >> to;

    auto start = high_resolution_clock::now();
    Chess.moveTo(pc, to);
    auto stop = high_resolution_clock::now();

    Chess.printBoard();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
