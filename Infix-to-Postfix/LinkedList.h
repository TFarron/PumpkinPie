#ifndef _LINKEDLIST
#define _LINKEDLIST
//#include "BagInterface.h"
#include "Node.h"
#include <vector>

using namespace std;

template<class ItemType>
class LinkedList //: public BagInterface<ItemType>
{
    template<class Itemtype> friend class Stack;
private:
	Node<ItemType>* headPtr;
    Node<ItemType>* tailPtr;
	int itemCount;
	Node<ItemType>* getPointerTo(const ItemType& target) const;
     //Node<ItemType>* posToNode(int pos) const;
public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
     virtual ~LinkedList();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
     bool insert(int newPos, const ItemType& newEntry);
	//bool remove(const ItemType& anEntry);
    void printList();
	Node<ItemType>* posToNode(int pos) const;
     bool remove(int position);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	vector<ItemType> toVector() const;
};
#endif