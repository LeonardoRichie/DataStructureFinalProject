#include <list>
#include <string>
#include <iostream>
using namespace std;

class HashTable
{
    static const int hashBuckets = 65; //hashmap size
    list<pair<int, string>> table[hashBuckets]; //create linear data structure

public:
    //list of function
    int hashFunction(int key);
    void insertItem(int key, string value);
    void printBoard();
    void swapItem(int x, string y, int z);
};

int HashTable::hashFunction(int key)
{
    //get key
    return key;
}
void HashTable::swapItem(int x, string y, int z){
    insertItem(x, "000");
    insertItem(z, y);
}

void HashTable::insertItem(int key, string value){
    //inserting value and replace the old value
    int hashValue = hashFunction(key); //get key
    auto &cell = table[hashValue]; // We grab the cell of the HashMap
    auto i = begin(cell);   // We make an iterator at the first element of sequence
    bool keyfound = false; //false have not found same key
    for (; i != end(cell); i++){ //add i until the end of the sequence
        // if key is the same
        if (i->first == key){
            keyfound = true; //if key is found replace into a new one
            i->second = value;
            break;
        }
    }

    if (!keyfound){
        //directly insert object without calling constructor
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::printBoard(){
    for (int i = 0; i < hashBuckets; i++){
        auto ptr = table[i].begin();//create pointer at the begining
        for (; ptr != table[i].end(); ptr++)// until pointer reach the end
        {// until pointer reach the end
            cout << ptr->second<< " "; //print values
        }
        if (i%8==0){//divide into 8 rows
            cout<<endl;
        }
    }
    return;
}