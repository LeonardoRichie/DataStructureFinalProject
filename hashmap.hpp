#include <list>
#include <string>
#include <iostream>
using namespace std;

class HashTable
{
    static const int hashBuckets = 65; //hashmap size
    list<pair<int, string>> table[hashBuckets]; //create linear data structure

public:

    int hashFunction(int key);
    void insertItem(int key, string value);
    void printTable();
    void printBoard();
};

int HashTable::hashFunction(int key)
{
    //get key
    return key % hashBuckets;
}

void HashTable::insertItem(int key, string value)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue]; // We grab the cell of the HashMap
    auto i = begin(cell);   // We make an iterator
    bool keyExists = false;
    for (; i != end(cell); i++)
    {
        // COLLISION
        if (i->first == key)
        {
            keyExists = true;
            i->second = value;
            break;
        }
    }

    if (!keyExists){
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::printTable()
{
    for (int i = 0; i < hashBuckets; i++)
    {
        if (table[i].size() == 0) continue;
        auto ptr = table[i].begin();
        for (; ptr != table[i].end(); ptr++){
            cout << "Key: " << ptr->first << " Value: " << ptr->second << endl;
        }
    }
    return;
}

void HashTable::printBoard(){
    for (int i = 0; i < hashBuckets; i++){
        if (table[i].size() == 0) continue; //[[],[],[{100,"A+"}],[],[]]
        auto ptr = table[i].begin();
        for (; ptr != table[i].end(); ptr++)
        {
            cout << ptr->second<< " ";
        }
        if (i%8==0){
            cout<<endl;
        }
    }
    return;
}