#include "Hash.h"
#include <cstddef>
#include <iostream>

using namespace std;


HashTable :: HashTable() : TableSize(30)
{
	const int TableSize = 30;
	Table = new HashTable*[TableSize];
	for (int i=0;i<TableSize;i++)
	{
		Table[i] = NULL;
	}
}

int HashTable :: Hash(string key)
{
	int hash=0;
	int index;

	for (int i=0;i<key.length();i++)
	{
		hash = hash + (int)key[i];
	}

	index = hash % TableSize;
	return index;
}

void HashTable::setItem(const User anItem)
{
	item = anItem;
}

void HashTable::setNext(HashTable* nextPtr)
{
	next = nextPtr;
}

User HashTable::getitem() const
{
	return item;
}

HashTable* HashTable::getNext() const
{
	return next;
}
/*

//Set data value for node
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

//Set pointer value for next node 
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
} 

//Get data value for node
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

//Return pointer value for next node 
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}
*/