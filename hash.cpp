#include <iostream>
#include <vector>
#include "hash.h"
using namespace std;

Data::Data()
{
    key = "";
    value = "";
    next = NULL;
}

Data::Data(string k, string v)
{
    key = k;
    value = v;
    next = NULL;
}

void Data::print()
{
    cout << "in print" << endl;
    cout << this->key << ", " << this->value << endl;
}

HashTable::HashTable()
{
    cout << "HashTable()" << endl;
    //dataList[10] = (Data*)malloc(sizeof(Data) * 10);
    size = 10;// sizeof(dataList)/sizeof(dataList[0]);
    //dataList = (Data**)malloc(sizeof(Data*) * size);
    cout << "for..." << endl;
    for(int i = 0; i<size; i++)//Data& d : dataList)
    {
        //d = Data();
        //d.print();
        Data d = Data();
        dataList[i] = &d;
    }
    for(int i = 0; i<size; i++)
    {
        dataList[i]->print();
    }
}

void HashTable::put(string key, string val)
{
    cout << size << endl;
    //cout << "Hello? " << endl;
    //vector<Data>& data = dataList;
    //cout << "Putting: " << key << ", " << val << endl;
    int h = hash(key);
    cout << "Putting: " << key << ", " << val << " (at " << h << ")" << endl;
    //Data d = Data(key, val);
    
    //d.next = &(dataList[h]);
    //vector<vector<Data>> data = *dataList;
    //(*dataList)[h].push_back(d);

    //dataList[h] = d;
    //dataList = data;
    
    //keys.push_back(key);

    Data*** data = &dataList;
    for(int i = 0; i<10; i++)
    {
        cout << i << ": " << endl;
        Data* d = (*data)[i];
        //cout << "hi?" << endl;
        cout << d->key << endl;// << ", " << dataList[i].value << endl;
    }

    //Data& dh = dataList[h];
    //dataList[h].print();
    //cout << "between" << endl;
    //dataList[h] = d;

    //print("Setting: ", h);
}

string HashTable::get(string key)
{
    //cout << (*dataList)[0].size() << endl;
    for(int i = 0; i<10; i++)
    {
        //cout << (*dataList)[i].size() << endl;
        //if(dataList[i][0])
        //dataList[i][0].print();
    }

    /*vector<Data>& data = dataList;
    int h = hash(key);
    cout << "get1" << typeid(data[0]).name() << endl;
    Data temp = dataList.at(h);
    cout << "get2" << endl;*/

    //print("Getting: ", h);
    /*while(d != NULL)
    {
        cout << "key: " << d->key << endl;
        if(d->key == key)
        {
            cout << "value: " << d->value << endl;
            return d->value;
        }
        d = d->next;
    }*/
    return "";
}

void HashTable::print(string msg, int i)
{
    cout << "HashTable print" << endl;
    cout << msg;
    dataList[i]->print();
}

// Private methods

int HashTable::hash(string key)
{
    int h = 0;
    for(char c : key)
    {
        //size = (sizeof(dataList)/sizeof(dataList[0]));
        cout << size << endl;
        //cout << (int)c << " ";
        h = (13 * h + (int)c) % 10;
        //h += 13;
        //cout << h << endl;
    }
    cout << h << endl;
    //if(h>=size)
    {
        cout << h << endl;
    }
    return h;
}

