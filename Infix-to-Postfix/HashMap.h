#ifndef _HASHMAP
#define _HASHMAP

#include"Users.h"
#include"HashEntry.h"
#include<string>

const int TABLE_SIZE = 29;

class HashMap
{

private:

	LinkedHashEntry **table;

public:

	HashMap();
	~HashMap();

	int Hash(string key);
	int find(string key);
	User retrieve(string key);
	void add(User new_value);
	void remove(string key);

};
#endif