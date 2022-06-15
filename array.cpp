#include <array>
#include <string>
#include <chrono>
#include <iostream>
using namespace std::chrono;
using namespace std;

class arrChess
{
    array<int, 64> arr = 
    {-1, -2, -3, -4, -5, -3, -2, -1,
     -6, -6, -6, -6, -6, -6, -6, -6,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      6,  6,  6,  6,  6,  6,  6,  6,
      1,  2,  3,  4,  5,  3,  2,  1};

    public:
    void moveTo(int from, int to);
    void printBoard();
};

void arrChess::moveTo(int from, int to)
{
    arr[to] = arr[from];
    arr[from] = 0;
}

void arrChess::printBoard()
{
    int y = 0;
    for (int i : arr)
    {
        if (y % 8 == 0)
        cout << "\n";
        switch(i) {
            case -1:
            cout << "BR ";
            case -2:
            cout << "BH ";
            case -3:
            cout << "BB ";
            case -4:
            cout << "BK ";
            case -5:
            cout << "BQ ";
            case -6:
            cout << "BP ";
            case 0:
            cout << "00 ";
            case 1:
            cout << "WR ";
            case 2:
            cout << "WH ";
            case 3:
            cout << "WB ";
            case 4:
            cout << "WK ";
            case 5:
            cout << "WQ ";
            case 6:
            cout << "WP ";
        }
        y++;
    }
}


int main() 
{
    int from, to;
    arrChess Chess;

    cout<< "Enter the chess piece position you want to move: ";
    cin >> from;
    cout<< "Enter the chess piece position destination: ";
    cin >> to;

    auto start = high_resolution_clock::now();
    Chess.moveTo(from, to);
    auto stop = high_resolution_clock::now();

    Chess.printBoard();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
