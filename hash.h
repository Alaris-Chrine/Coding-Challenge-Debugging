#ifndef HASH_H
#define HASH_H

#include <string>
#include <vector>
using namespace std;

/**
 * The Data class
 */
class Data
{
public:
    // Data fields
    string key;
    string value;
    Data* next;

    // Methods
    Data();
    Data(string k, string v);
    void print();
};

class HashTable
{
private: // Data fields
    int size;// = 10;
    //vector<vector<Data>>* dataList;
    Data** dataList = (Data**)malloc(sizeof(Data*)*10);
    //vector<string> keys;

public: // Public methods
    HashTable();
    void put(string key, string val);
    string get(string key);
    void print(string msg, int i);

private: // Private mathods
    int hash(string key);
    void resize();
};

#endif /* HASH_H */

