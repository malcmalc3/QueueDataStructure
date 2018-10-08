//Queue.h
//Declarationn of the template class struct QueNode and the template class Queue
//Programmer: Malcolm Milton
//Date: ////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef QUEUE_H
#define QUEUE_H

template <class DataType>
struct QueueNode
{
	DataType data; //Data that can be of any type
	QueueNode<DataType> *next; //Pointer to the next node in the queue
};

template <class DataType>
class Queue
{
	private:
		QueueNode<DataType> *front; //Pointer to the front node in the queue
		QueueNode<DataType> *back; //Pointer to the back node in the queue
		int queueSize; //Size of a Queue
		int queueCnt; //Element count in a queue
	public:
		Queue(int = 4); //Class constructor - initializes variables
		~Queue(); //Class destructor  - remove all memory spaces used by queue elements
		void enQueue(const DataType); //Add an item to the back of the queue
		DataType deQueue(); //Remover the first item from the queue and returns its value
		DataType topQueue() const; //Returns the value of the first item in the queue
		bool isEmpty() const; //Returns true if there are no elements in the queue
		bool isFull() const; //Returns true if there is no system memory for a new queue node
};

#endif
