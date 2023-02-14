#ifndef REDIS_H
#define REDIS_H

#include <string>
#include "hash.h"
using namespace std;

class Redis
{
private:
    bool running;
    HashTable* database;

public:
    Redis();
    int run();
    void set(string key, string val);
    void get(string key);
    void del(string key);
};

#endif /* REDIS_H */

