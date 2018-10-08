//Students.h
//Declaration of the Students structure
//Programmer: Malcolm Milton
//Date: //////////////////////////////////////////////////////////

#ifndef STUDENTS_H
#define STUDENTS_H

struct Students
{
	char lastName[20]; //Student's last name
	char firstName[20]; //Students's first name
	int idNumber; //Student's ID number
	Students(); //Constructor
	void printStudent(); //Prints a student's information
};

#endif
