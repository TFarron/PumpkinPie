#include "LinkedList.h"
#include <cstddef>

;
using namespace std;

//Default constructor 
template<class ItemType>
LinkedList<ItemType> ::LinkedList() : headPtr(nullptr), itemCount(0), tailPtr(nullptr)
{
}

//Copy constructor
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
    itemCount = aList.itemCount;
    Node<ItemType>* origChainPtr = aList.headPtr;

    if (origChainPtr == nullptr)
        headPtr = nullptr;

    else
    {
        //Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        //Copy the remaining nodes
        Node<ItemType>* newChainPtr = headPtr;
        while (origChainPtr != nullptr)
        {
            // Advance pointer
            origChainPtr = origChainPtr->getNext();

            //Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            //Create new node containing next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            //Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);

            //Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }
}

//Get size of list 
template<class ItemType>
int LinkedList<ItemType>::getCurrentSize() const
{
    return itemCount;
}

//Checking if list is empty
template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

//Adding to list
template<class ItemType>
bool LinkedList<ItemType>::add(const ItemType& newEntry)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>();
    newNodePtr->setItem(newEntry);
    newNodePtr->setNext(headPtr);
    headPtr = newNodePtr;
    itemCount++;
    return true;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPos, const ItemType& newEntry)
{
    Node<ItemType>* prevNodePtr = new Node<ItemType>();
    Node<ItemType>* currNodePtr =  new Node<ItemType>();
    Node<ItemType>* newNodePtr =  new Node<ItemType>();
    //cout << "count: " << itemCount << endl;
    if (newPos == 0)
    {
        add(newEntry);
        return true;
    }
    else if (newPos > 0 && newPos <= itemCount)
    {
        newNodePtr->setItem(newEntry);
        currNodePtr = headPtr;
        int pos = 0;
        for (; (pos <= newPos && currNodePtr->getNext() != NULL); pos++)
        {
            prevNodePtr = currNodePtr;
            currNodePtr = currNodePtr->getNext();
        }
        
        if (itemCount == newPos)
        {
            currNodePtr->setNext(newNodePtr);
            cout << "adding at tail" << endl;
            
        }
        else
        {
            prevNodePtr->setNext(newNodePtr);
            newNodePtr->setNext(currNodePtr);
            //cout << "Node added at position: " << newPos << endl;
        }
        itemCount++;
        return true;
    }
    return false;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int pos)
{
    Node<ItemType>* entryNodePtr = posToNode(pos);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemoveItem)
    {
        //Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());

        //Delete first node
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        //Return node's memory to system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        itemCount--;
    }
    return canRemoveItem;
}



/*Remove
template<class ItemType>
bool LinkedList<ItemType>::remove(const ItemType& anEntry)
{
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemoveItem)
    {
        //Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());

        //Delete first node
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        //Return node's memory to system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        itemCount--;
    }
    return canRemoveItem;
}
*/
//Clear list
template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (headPtr != nullptr)
    {
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        //Return node's memory to system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
    }
    //nodeToDeletePtr = nullptr;
    itemCount = 0;
}

//Destructor
template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}

//Search
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getPointerTo(const ItemType& target) const
{
    bool found = false;
    Node<ItemType>* curPtr = headPtr;
    while (!found && (curPtr != nullptr))
    {
        if (target == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    }
    return curPtr;
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::posToNode(int pos) const
{
    Node<ItemType>* curPtr = headPtr;

    int i = 0;
    for (; (i < itemCount); i++)
    {
        if (i == pos)
        {
            return curPtr;
        }
        curPtr = curPtr->getNext();
    }

    return nullptr;
}

//Contains
template<class ItemType>
bool LinkedList<ItemType>::contains(const ItemType& anEntry) const
{
    if (getPointerTo(anEntry) == nullptr)
        return false;
    else
        return true;
    //return (getPointerTo(anEntry) != nullptr);
}



//Get frequency of value in list
template<class ItemType>
int LinkedList<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int counter = 0;
    Node<ItemType>* curPtr = headPtr;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        if (anEntry == curPtr->getItem())
        {
            frequency++;
        }
        counter++;
        curPtr = curPtr->getNext();
    }
    return frequency;
}

//To vector
template<class ItemType>
vector<ItemType> LinkedList<ItemType>::toVector() const
{
    vector<ItemType> listContents;
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        listContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    }
    return listContents;
}

template<class ItemType>
void LinkedList<ItemType>::printList()
{
    if (itemCount == 0)
    {
        return; 
    }
    Node<ItemType>* nodePtr = posToNode(0);
    cout << nodePtr->getItem() << endl;
    for (int i = 1; i < itemCount; i++)
    {
        nodePtr = nodePtr->getNext();
        cout << nodePtr->getItem() << endl;
        
    }
}

