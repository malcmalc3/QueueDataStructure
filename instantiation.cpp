//instantiation.cpp
//File to link the templated .cpp files (project will not work without it)
//Programmer: Malcolm Milton
//Date: //////////////////////////////////////////////////////////////////////////////////////////

#include "Students.cpp"
#include "Lab5.cpp"
#include "Queue.cpp"

template class Queue<int>;
template class QueueNode<int>;

template class Queue<Students*>;
template class QueueNode<Students*>;
