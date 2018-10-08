//Students.cpp
//Member functions of the Students class
//Programmer: Malcolm Milton
//Date: 3/24/15

#include <iostream>
#include "Students.h"
using namespace std;

Students::Students()
{
    cout << "Please enter student's first name: ";
    cin >> firstName; //Saves the user's input in the firstName member of the Students struct
    cout << "Please enter student's last name: ";
    cin >> lastName; //Saves the user's input in the lastName member of the Students struct
    cout << "Please enter student's ID number: ";
    cin >> idNumber; //Saves the user's input in the idNumber member of the Students struct
    cout << endl;
}

void Students::printStudent() //Function to print out the students information
{
    cout << "Student #" << idNumber << ": " << firstName << " " << lastName << endl << endl; //Prints out the information using the members of the struct
}

