/*
  Name: Yunus Shaikh
  Course: CISP 400 – Object Oriented Programming in C++
  Assignment: AD1 – Employee Salary
  File: Employee.cpp
  Purpose: Implementation of the Employee class for AD1. This file defines the behavior of Employee objects,
  including setting and retrieving names, managing salary values with validation, and applying salary adjustments.
*/


// Employee.cpp
// Employee member-function definitions. This file contains
// implementations of the member functions prototyped in Employee.h.
#include <iostream>
#include "Employee.h" // include definition of class Employee
using namespace std;

// constructor initializes firstName, lastName, and monthlySalary with string and int supplied as arguments
Employee::Employee(string firstName, string lastName, int monthlySalary)
	: firstName(firstName), lastName(lastName), monthlySalary(0)
{
	// call setMonthlySalary to ensure the salary is not negative
    setMonthlySalary(monthlySalary);
} 

// function to set the course name
void Employee::setFirstName(string first_name)
{
    firstName = first_name;
} 

// function to get the first name
string Employee::getFirstName() const
{
    return firstName;
}
// function to set the last name
void Employee::setLastName(string last_name)
{
    lastName = last_name;
}
// function to get the last name
string Employee::getLastName() const
{
    return lastName;
}
// function to set the salary, ensuring it is not negative
void Employee::setMonthlySalary(int salary)
{   
    if (salary > 0) {
        monthlySalary = salary;
    }
    else {
        monthlySalary = 1000;
        cout << " XX Employee: " << firstName << " " << lastName << "'s inputted monthly salary is " << salary << endl <<
            " ** The salary is set to $1000. **" << endl;
    }
}

// function to get the monthly salary
int Employee::getMonthlySalary() const
{
    return monthlySalary;
}
// function to increase the monthly salary by a given percentage
void Employee::increaseMonthlySalary(int percent)
{
    
    int original = monthlySalary;
    monthlySalary = original + (original * percent) / 100;

    if (percent > 0){
        cout << "+++  ";
    }
    else {
		cout << "---  ";
    }

    cout << "Employee: " << firstName << " " << lastName
        << " has a salary adjustment of " << percent << " %" << endl;
    cout << "The original monthly salary is $" << original << "." << endl;
    cout << "The new monthly salary is $" << monthlySalary << endl << endl;
}


