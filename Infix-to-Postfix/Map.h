#ifndef _MAP
#define _MAP

#include"Users.h"
#include"HashEntry.h"
#include<string>

const int TABLE_SIZE = 29;

class HashMap
{

private:

	LinkedHashEntry **table;

public:

	HashMap()
	{
		table = new LinkedHashEntry*[TABLE_SIZE];
		for (int i=0; i<TABLE_SIZE; i++)
		{
			table[i] = NULL;
		}
	}

	int retrieve(int key)
	{
		int hash = (key%TABLE_SIZE);
		if (table[hash] == NULL)
			return -1;
		else
		{
			LinkedHashEntry *entry = table[hash];
			while (entry != NULL && entry->getKey() != key)
				entry = entry->getNext();
			if (entry == NULL)
				return -1;
			else
			{
				entry->getValue();
				return 0;
			}
		}
	}

	void add(int key, User new_value)
	{
		int hash = (key%TABLE_SIZE);
		if (table[hash] == NULL)
			table[hash] = new LinkedHashEntry(key, new_value);
		else
		{
			LinkedHashEntry * entry = table[hash];
			while (entry->getNext() != NULL)
				entry = entry->getNext();
			if (entry->getKey() == key)
				entry ->setValue(new_value);
			else
				entry->setNext(new LinkedHashEntry(key, new_value));
		}
	}

	void remove(int key)
	{
		int hash = (key%TABLE_SIZE);
		if (table[hash] != NULL)
		{
			LinkedHashEntry *prevEntry = NULL;
			LinkedHashEntry *entry = table[hash];
			while (entry->getNext() != NULL && entry->getKey() != key)
			{
				prevEntry = entry;
				entry = entry->getNext();
			}
			if (entry->getKey() == key)
			{
				if (prevEntry == NULL)
				{
					LinkedHashEntry *nextEntry = entry->getNext();
					delete entry;
					table[hash] = nextEntry;
				}
				else
				{
					LinkedHashEntry *next = entry->getNext();
					delete entry;
					prevEntry->setNext(next);
				}
			}
		}
	}

	~HashMap()
	{
		for (int i=0; i<TABLE_SIZE; i++)
		{
			if (table[i] != NULL)
			{
				LinkedHashEntry *prevEntry = NULL;
				LinkedHashEntry *entry = table[i];
				while(entry != NULL)
				{
					prevEntry = entry;
					entry = entry->getNext();
					delete prevEntry;
				}
			}
		}
	}
};
#endif