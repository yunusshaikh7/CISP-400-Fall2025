/*
  Name: Yunus Shaikh
  Course: CISP 400 – Object Oriented Programming in C++
  Assignment: A2 – Encryption
  File: Encrypt.h
  Purpose: Declaration of the Encrypt class. Defines the interface for storing a 4-digit integer,
           encrypting it according to the assignment rules, and displaying both original and encrypted data.
*/


class Encrypt
{
public:
    // Constructor: takes any integer, stores last 4 digits,
    // encrypts them, displays constructor info, original data, encrypted data.
    explicit Encrypt(int value); 
    void displayOriginalData(); // displays the first four elements of the private data member
    void storeData(int value); // Store the last four digits of value 
    void displayEncryptedData(); // Display the encrypted four digits (elements 4..7).
private:
    int digits[8]; // [0–3] original, [4–7] encrypted
};