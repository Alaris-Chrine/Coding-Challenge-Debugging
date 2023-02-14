#include <iostream>
#include <algorithm>
#include "redis.h"
using namespace std;

Redis::Redis()
{
    running = true;
    HashTable db = HashTable();
    database = &db; //(HashTable*)malloc(sizeof(HashTable));
    //*database = HashTable();
}

int Redis::run()
{
    do
    {
        cout << ">  Enter command" << endl << ">> ";
        string command;
        cin >> command;
        transform(command.begin(), command.end(), command.begin(), ::toupper);
        //cout << "\"" << command << "\"" << endl;
        
        if(command == "EXIT")
        {
            cout << "Goodbye!" << endl;
            running = false;
        }
        else if(command == "SET")
        {
            string key, value;
            cin >> key >> value;
            //cout << "\"" << command << " " << key << " " << value << "\"" << endl;
            set(key, value);
            //(*database).print("Printing: ", 1);
        }
        else if(command == "GET")
        {
            string key;
            cin >> key;
            get(key);
        }
        else
        {
            cout << "Error: invalid syntax" << endl;
        }
        //database.print("Printing: ", 1);

    } while(running);

    return 0;
}

void Redis::set(string key, string val)
{
    // set... time for hash table
    database->put(key, val);
    //database.print();
}

void Redis::get(string key)
{
    string value = database->get(key);
    cout << "\"" << value << "\"" << endl;
}

void Redis::del(string key)
{
}

