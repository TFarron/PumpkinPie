#include "Node.h"
#include <cstddef>

using namespace std;

//Default constructor 
template<class ItemType>
Node<ItemType> :: Node() : next(nullptr)
{
}

//Constructor
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
} 

//Constructor
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodeptr)
{
}

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