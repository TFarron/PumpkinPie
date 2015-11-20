#include"HashMap.h"
#include<string>
#include<cstddef>

int HashMap :: Hash(string key)
{
	int hash=0;
	int index;

	for (int i=0;i<key.length();i++)
	{
		hash = hash + (int)key[i];
	}

	index = hash % TABLE_SIZE;
	return index;
}

HashMap::HashMap()
{
	table = new LinkedHashEntry*[TABLE_SIZE];
	for (int i=0; i<TABLE_SIZE; i++)
	{
		table[i] = NULL;
	}
}

LinkedHashEntry** HashMap::getTable()
{
	return table;
}

int HashMap::find(string key)
{
	int hash = Hash(key);
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
			return 0;
		}
	}
}

User HashMap::retrieve(string key)
{
	string exception_string = "Error: File not found.\n";
	int successful = find(key);
	if (successful == 0)
	{
		int hash = Hash(key);
		LinkedHashEntry *entry = table[hash];
		while (entry != NULL && entry->getKey() != key)
			entry = entry->getNext();
		return entry->getValue();
	}
	else
		throw logic_error(exception_string);
}

void HashMap::add(User new_value)
{
	string key = new_value.username;
	int hash = Hash(key);
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

void HashMap::remove(string key)
{
	int hash = Hash(key);
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

/*
void HashMap::remove(int key)
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
*/
HashMap::~HashMap()
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