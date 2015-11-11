#ifndef _NODE
#define _NODE

using namespace std;

template<class ItemType>
class Node
{
private:
	ItemType item; // data item
	Node<ItemType>* next; // pointer to next node in chain
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
};
#endif