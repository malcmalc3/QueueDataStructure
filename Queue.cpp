//Queue.cpp
//Member functions of Queue class
//Programmer: Malcolm Milton
//Date: 3/24/15

#include <iostream>
#include "Queue.h"
using namespace std;

template <class DataType> //Declares that this function is part of a template class
Queue<DataType>::Queue(int x) //Class constructor. Parameter x is the number of nodes allowed in the queue, default is 10
{
    front = back; //Points the front to the back since there are no nodes in the queue yet
    back = NULL; //Points the back of the node to NULL since there are no nodes in the queue yet
    queueSize = x; //Sets the maximum size of the queue equal to x, the parameter
    queueCnt = 0; //Sets the number of nodes currently in the new queue to zero
}

template <class DataType>
Queue<DataType>::~Queue() //Class destructor, deletes all the nodes in the queue
{
    while(!isEmpty()) //Stops when there are no more nodes in the queue
        deQueue(); //Calls the function to delete the front node

    cout << "Queue deleted" << endl;
}

template <class DataType>
void Queue<DataType>::enQueue(const DataType x) //Function to add a node to the back of the queue. Parameter x is the new node of any type
{
    QueueNode<DataType> *newNode = new QueueNode<DataType>; //Creates a pointer that will point to the new type to be added, the parameter
    newNode->data = x; //Points the data portion of the QueueNode to the parameter of any type

    if(!isEmpty()) //If there are already nodes in the list
    {
        back->next = newNode; //Makes the previous last node point to the new node
        back = newNode; //Points the back pointer to the new last node in the queue
    }
    else //If there are no nodes in the queue
    {
        front = newNode; //Makes the new node the front of the queue
        back = newNode; //Makes the new node the back of the queue
    }
    queueCnt++; //Increments the number of nodes in the queue
}

template <class DataType>
DataType Queue<DataType>::deQueue() //Functiom to delete the front node from the queue. No parameter or return type
{
    QueueNode<DataType> *tempNode1 = new QueueNode<DataType>; //Creates a temporary pointer to the front node
    tempNode1->data = front->data; //Makes the data part of the temporary node struct the front's data to return
    QueueNode<DataType> *tempNode2 = front->next; //Creates a temporary pointer to the second node in the queue
    delete front; //Deletes the first node in the queue
    front = tempNode2; //Sets the front of the queue to the previous second node in the queue
    queueCnt--; //Decrements the number of nodes in the queue
    return tempNode1->data; //Returns the node that was removed from the front
}

template <class DataType>
DataType Queue<DataType>::topQueue() const //Function to return the data of the front node. Constant so no other function can make changes to this
{
    return front->data; //Uses the pointer of the front node to return its data
}

template <class DataType>
bool Queue<DataType>::isEmpty() const //Function that tells if the queue is empty, has zero nodes
{
    return queueCnt == 0 ? true : false; //Returns true if there are no nodes in the queue, false if otherwise. queueCnt is a private member
}

template <class DataType>
bool Queue<DataType>::isFull() const //Function that tells if the queue has no more space, has the max amount of nodes
{
    return queueCnt == queueSize ? true : false; //Returns true if amount of nodes in queue equal the max amount, false if otherwise. queueCnt and queueSize are private members
}

