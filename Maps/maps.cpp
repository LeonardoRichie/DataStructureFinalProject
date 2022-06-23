#include <iostream>
#include <iterator>
#include <map>
#include <chrono>
using namespace std::chrono;
using namespace std;


 
int main()
{
 
    // empty map container
    map<int, string> ChessBoard;
    int count;
    count = 0;

    for (int x=1; x<65; x++){
        //create empty board
       ChessBoard.insert(pair<int, string>(x,"000"));
    }

    map<int, string>::iterator itr;
    ChessBoard[1]="WR1";
    ChessBoard[2]="WH1";
    ChessBoard[3]="WB1";
    ChessBoard[4]="WQU";
    ChessBoard[5]="WKI";
    ChessBoard[6]="WB2";
    ChessBoard[7]="WH2";
    ChessBoard[8]="WR2";
    ChessBoard[9]="WP1";
    ChessBoard[10]="WP2";
    ChessBoard[11]="WP3";
    ChessBoard[12]="WP4";
    ChessBoard[13]="WP5";
    ChessBoard[14]="WP6";
    ChessBoard[15]="WP7";
    ChessBoard[16]="WP8";

    ChessBoard[57]="BR1";
    ChessBoard[58]="BH1";
    ChessBoard[59]="BB1";
    ChessBoard[60]="BQU";
    ChessBoard[61]="BKI";
    ChessBoard[62]="BB2";
    ChessBoard[63]="BH2";
    ChessBoard[64]="BR2";
    ChessBoard[49]="BP1";
    ChessBoard[50]="BP2";
    ChessBoard[51]="BP3";
    ChessBoard[52]="BP4";
    ChessBoard[53]="BP5";
    ChessBoard[54]="BP6";
    ChessBoard[55]="BP7";
    ChessBoard[56]="BP8";
    
    
    cout << "\nChess Board : \n";
    for (itr = ChessBoard.begin(); itr != ChessBoard.end(); ++itr) {
        cout << itr->second<< " ";
        count += 1;
        if (count % 8==0){
            cout<<endl;
        };
    }

    while(true){
    int pos; //input key position
    cout<< "Enter key position you want to move: ";
    cin>>pos;

    string val; //input value
    cout<< "Enter value from the key: ";
    cin>>val;

    int des; //input destination
    cout<< "Enter key position destination: ";
    cin>>des;

    auto start = high_resolution_clock::now(); //starting point
    ChessBoard[pos]= "000";
    ChessBoard[des]= val;

    cout << "\nChess Board : \n";
    for (itr = ChessBoard.begin(); itr != ChessBoard.end(); ++itr) {
        cout << itr->second<< " ";
        count += 1;
        if (count % 8==0){
            cout<<endl;
        };
    }
    auto stop = high_resolution_clock::now(); //end point
    //duration cast method
    auto duration = duration_cast<microseconds>(stop - start); //get duration
    //giving output duration time
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
        
    cout << endl;
    string boolplay;
    cout<< "Continue? (yes/no): ";
    cin>>boolplay;
    if (boolplay == "no"){
        break;
        }
    }
    return 0;
}