#ifndef _HASH
#define _HASH

#include"Users.h"
#include<string>

using namespace std;

class HashTable
{
private:

	const int TableSize;
	int key;

	User item;

	HashTable* next;
	HashTable** Table;
	
public:

	HashTable();
	~HashTable();

	void setItem(const User item);
	void setNext(HashTable* nextPtr);

	User getitem() const;
	HashTable* getNext() const;

	int Hash(string key);

};

#endif