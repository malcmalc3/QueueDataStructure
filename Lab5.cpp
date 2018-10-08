//Lab5.cpp
//For testing queue
//Programmer: Malcolm Milton
//Date: 3/24/15

#include "Queue.h"
#include "Students.h"
#include <iostream>
using namespace std;

int typeMenu(); //Function to ask which queue the user wants to use, or quit program. Returns the number of the user's choice. No Parameters.
int queueMenu(); //Function to ask user what to do with the current queue. Returns the user's choice. No Parameters.
void iqueueMenu(); //Function to carry out the user's choice with the int queue. Returns nothing, no parameters.
void squeueMenu(); //Function to carry out the user's choice with the Students queue. Returns nothing, no parameters.

int main()
{
	int choice = 0; //Variable that saves user's choice of which queue to use, or quit
        while(choice != 3) //Stops when the user wants to quit the program
	{
		choice = typeMenu(); //Saves the user's choice of which queue to use, quits when it returns 3

		if(choice == 1) //If the user wants to use the Students queue
			squeueMenu(); //Calls the function for the user to use the Students queue until they want to stop using it
		else if(choice == 2) //If the user wants to use the int queue
			iqueueMenu(); //Calls the function for the user to use the int queue until they want to stop using it
	}
	cout << "Thank you for using this program!" << endl << endl;
}

int typeMenu() //Function to ask which queue the user wants to use, or quit program. Returns the number of the user's choice. No Parameters.
{
	int choice; //Variable to save the user's choice of which queue to use, or quit the program

	cout << "Please choose an option:" << endl;
	cout << "1) Students Queue \n2) Integer Queue \n3) Quit" << endl;
	cin >> choice; //Saves the user's choice of which queue to use, quits the program if 3
	
	while (choice < 1 || choice > 3) //Loop to make sure the user chooses 1, 2, or 3
	{
		cout << "Please enter a valid choice: ";
		cin >> choice; //Saves the user's choice
	}
	cout << endl;

	return choice;
}

void iqueueMenu() //Function to carry out the user's choice with the int queue. Returns nothing, no parameters.
{
	int choice = 0; //Variable to save what the user wants to do with the queue. Also used to add an int to the queue and print out the top int before deleting
	static Queue<int> iqueue; //Declares a new queue of type int. Static so it stays in memory if the user goes away from it and comes back to the queue

	while(choice != 4) //Stops when the user selects the choice to quit
	{
		choice = queueMenu(); //Function asks user what to do with the queue, and saves the answer

		if(choice == 1) //If the user wants to add an int to the queue
		{
			if(!iqueue.isFull()) //If the queue has space to add an int
			{
				cout << "Please enter an integer to add to the queue: ";
				cin >> choice; //Saves the choice of what int to add to the queue
				iqueue.enQueue(choice); //Calls the function to add the choice to the int queue
				cout << "Integer added" << endl << endl;

				if(choice == 4) //If the user chose to add 4 to the queue then the program will quit without this
					choice = 0; //Changes to a value other than 4 to contimue the program
			}
			else //If there is no more space in the queue
				cout << "The queue is full" << endl << endl;
		}
		else if(choice == 2) //If the user wants to remove the front int
		{
			if(!iqueue.isEmpty()) //If the queue actualy has an int to remove
			{
				choice = iqueue.deQueue(); //Calls the function to delete the front int and saves the value of the in that was removed in choice
				cout << endl << "Integer being removed: " << choice << endl << endl; //Prints out the int that was removed

				if(choice == 4) //If the int that was removed is 4 then the program would quit without this
					choice = 0; //Changes choice to a value other than 4 to continue with the program
			}
			else //If the queue does not have an int to remove
				cout << "The queue is empty" << endl << endl;
		}
		else if(choice == 3) //If the user wants to print out the front int
		{
			if(!iqueue.isEmpty()) //If the queue actualy has an int to print out
				cout << "Top integer: " << iqueue.topQueue() << endl << endl; //Calls function that returns the int that's on top queue and prints it out
			else //If the queue does not have an int to print out
				cout << "The queue is empty" << endl << endl;
		}
	}
}

void squeueMenu() //Function to carry out the user's choice with the Students queue. Returns nothing, no parameters.
{
	int choice = 0; //Variable to save what the user wants to do with the queue
	static Queue<Students*> squeue; //Declares a new queue of type Students. Static so that it stays the same if user goes away and comes back to the queue

	while(choice != 4) //Loop stops when the user selects the option to quit
	{
		choice = queueMenu(); //Calls the funtion to ask what the user wants to do with the queue and saves it in choice

		if(choice == 1) //If the user wants to add a student to theb queue
		{
			if(!squeue.isFull()) //If there is space in the queue
			{
				Students *newStudent = new Students; //Creates a new student and points to it
				squeue.enQueue(newStudent); //Calls the function to add the new student to the queue
				cout << "Student added to list" << endl << endl;
			}
			else //If there are no students in the queue to remove
				cout << "The queue is full" << endl << endl;
		}
		else if(choice == 2) //If the user wants to remove the front student from the queue
		{
			if(!squeue.isEmpty()) //If the queue actualy has a student to remove
			{
				Students *removeStudent = squeue.deQueue(); //Creates a pointer to point to the student being removed that the function returns
				cout << endl << "Student removed:" << endl;
				removeStudent->printStudent(); //Prints the information of the student being removed
			}
			else //If the queue has no students to remove
				cout << "The queue is empty" << endl << endl;
		}
		else if(choice ==3) //If the user wants to print the information of the first student
		{
			if(!squeue.isEmpty()) //If the queue actualy has a student at the front to print
			{
				cout << "Top student:" << endl;
				squeue.topQueue()->printStudent(); //Calls the function to print the information of the front student
			}
			else //If the queue has no students in it to print
				cout << "The queue is empty" << endl << endl;
		}
	}
}

int queueMenu() //Function to ask user what to do with the current queue. Returns the user's choice. No Parameters.
{
	int choice; //Variable to save the user's choice of what to do with the queue

	cout << "Please choose an option:" << endl;
	cout << "1) enQueue() \n2) deQueue() \n3) topQueue() \n4) stop using this queue" << endl;
	cin >> choice; //Saves the user's answer of what to do with the queue

	while(choice < 1 || choice > 4) //Makes sure the user selects 1, 2, 3, or 4
	{
		cout << "Please choose a valid option: ";
		cin >> choice; //Saves the user's choice
	}

	return choice;
}
