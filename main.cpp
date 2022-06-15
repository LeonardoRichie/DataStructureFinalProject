#include <chrono>
#include "./hashmap.hpp"
#include <string>
#include <list>
#include <iostream>
using namespace std::chrono;

using namespace std;

int main()
{
    HashTable Chess;
    int play;

    for (int x=1; x<65; x++){
        //create empty board
        Chess.insertItem(x,"000");
    }
    //inserting pieces
    Chess.insertItem(1, "WR1");
    Chess.insertItem(2, "WH1");
    Chess.insertItem(3, "WB1");
    Chess.insertItem(4, "WQU");
    Chess.insertItem(5, "WKI");
    Chess.insertItem(6, "WB2");
    Chess.insertItem(7, "WH2");
    Chess.insertItem(8, "WR2");
    Chess.insertItem(9, "WP1");
    Chess.insertItem(10, "WP2");
    Chess.insertItem(11, "WP3");
    Chess.insertItem(12, "WP4");
    Chess.insertItem(13, "WP5");
    Chess.insertItem(14, "WP6");
    Chess.insertItem(15, "WP7");
    Chess.insertItem(16, "WP8");

    Chess.insertItem(57, "BR1");
    Chess.insertItem(58, "BH1");
    Chess.insertItem(59, "BB1");
    Chess.insertItem(60, "BKI");
    Chess.insertItem(61, "BQU");
    Chess.insertItem(62, "BB2");
    Chess.insertItem(63, "BH2");
    Chess.insertItem(64, "BR2");
    Chess.insertItem(49, "BP1");
    Chess.insertItem(50, "BP2");
    Chess.insertItem(51, "BP3");
    Chess.insertItem(52, "BP4");
    Chess.insertItem(53, "BP5");
    Chess.insertItem(54, "BP6");
    Chess.insertItem(55, "BP7");
    Chess.insertItem(56, "BP8");
    Chess.printTable();
    cout<<endl;
    cout<<"board:"<<endl;
    Chess.printBoard(); //print board

    play = true;

    while(play == true){//while to keep the program running
    int x; //input key position
    cout<< "Enter key position you want to move: ";
    cin>>x;

    string y; //input value
    cout<< "Enter value from the key: ";
    cin>>y;

    int z; //input destination
    cout<< "Enter key position destination: ";
    cin>>z;

    auto start = high_resolution_clock::now(); //starting point
    Chess.insertItem(x, "000");
    Chess.insertItem(z,y);
    auto stop = high_resolution_clock::now(); //end point

    cout<<"board:"<<endl;
    Chess.printBoard();
    //duration cast method
    auto duration = duration_cast<microseconds>(stop - start); //get duration
    //giving output duration time
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    
    string boolplay;
    cout<< "Continue? (yes/no): ";
    cin>>boolplay;
    if (boolplay == "no"){
        break;
    }
    }
    return 0;
}