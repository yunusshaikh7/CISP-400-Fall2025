/*
  Name: Yunus Shaikh
  Course: CISP 400 – Object Oriented Programming in C++
  Assignment: A2 – Encryption
  File: Encrypt.cpp
  Purpose: Implementation of the Encrypt class. Includes constructor logic, storage of original digits,
           encryption, and display functions.
*/


#include <iostream>
#include "Encrypt.h" // include definition of class Encrypt
using namespace std;

// constructor initializes firstName, lastName, and monthlySalary with string and int supplied as arguments
Encrypt::Encrypt(int value)
{
    cout << endl <<"** The default constructor is called" << endl;
    cout << "   and the passed in number is " << value << ".**" << endl << endl;

    if (value <= 0) {

        cout << "XXX The inputed number is less than or equal to 0" << endl;
        value = 9436;
        cout << "    The number is reset to " << value << ". XXX" << endl;
    }

    storeData(value);

    displayOriginalData();
    displayEncryptedData();

}

// Store the last four digits of value 
void Encrypt::storeData(int value)
{
    if (value <= 0) value = 9436;

	// Make n only the last four digits of value
    int n = value % 10000;

    // Store the original data 
    digits[0] = (n / 1000) % 10;
    digits[1] = (n / 100) % 10;
    digits[2] = (n / 10) % 10;
    digits[3] = (n / 1) % 10;

	// Encrypt the data according to the assignment rules
    digits[6] = (digits[0] + 7) % 10;
    digits[7] = (digits[1] + 7) % 10;
    digits[4] = (digits[2] + 7) % 10;
    digits[5] = (digits[3] + 7) % 10;

}

// displays the first four elements of the private data member
void Encrypt::displayOriginalData()
{
    cout << endl<< "    The original data is "
        << digits[0] << " "
        << digits[1] << " "
        << digits[2] << " "
        << digits[3] << " " << "."
        << endl;
}


/// Display the encrypted four digits (elements 4..7).
void Encrypt::displayEncryptedData()
{
    cout << "    The encrypted data is "
        << digits[4] << " "
        << digits[5] << " "
        << digits[6] << " "
        << digits[7] << " " << "."
        << endl;
}