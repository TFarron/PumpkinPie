#ifndef _HASHENTRY
#define _HASHENTRY

#include"Users.h"
#include<string>
#include<iostream>

class LinkedHashEntry 
{
private:
	string key;
	User value;
	LinkedHashEntry *next;
public:
	LinkedHashEntry(string new_key, User new_value)
	{
		key = new_key;
		value = new_value;
		next = nullptr;
	}

	string getKey()
	{
		return key;
	}

	User getValue()
	{
		return value;
	}

	void setValue(User new_value)
	{
		value = new_value;
	}

	LinkedHashEntry *getNext()
	{
		return next;
	}

	void setNext(LinkedHashEntry *new_next)
	{
		next = new_next;
	}
};

#endif