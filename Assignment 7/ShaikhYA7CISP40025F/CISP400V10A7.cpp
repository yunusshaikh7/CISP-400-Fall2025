/*
  Name: Yunus Shaikh
  Course: CISP 400 	6 Object Oriented Programming in C++
  Assignment: A7
  File: CISP400V10A7.cpp
  Purposse: This program implements the quicksort algorithm to sort vectors of random integers. 
  It generates 10 vectors of random lengths (0-20) filled with random integers (0-100), sorts each 
  vector using quicksort, and prints the initial and sorted vectors to the console.
*/

// CISP400V10A7.cpp

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// Function to print the contents of a vector
void printVector(const vector<int>& v) {
	// Loop through the vector and print each element
	for (size_t i = 0; i < v.size(); ++i) {

		cout << v[i] << "  ";
	}
	cout << endl;
}

// Function to partition the vector for quicksort
int partitionVector(vector<int>& vector, int start, int end) {
	
	int pivot = vector[start]; // choose the first element as the pivot
	int left = start + 1; // left pointer starts just after the pivot
	int right = end; // right pointer starts at the end of the vector

	// loop until the two pointers meet
	while (left <= right) {

		// move right backward until we find something < pivot
		while (left <= right && vector[right] > pivot) {
			right--; // check next element to the left
		}

		// move left forward until we find something >= pivot
		while (left <= right && vector[left] <= pivot) {
			left++; // check next element to the right
		}

		// swap the left and right elements if left is less than right
		// then continue with the next number on each side
		if (left < right) {
			swap(vector[left], vector[right]);
			// move both pointers inward
			left++;
			right--;
		}
	}
	
	// finally, swap the pivot with the element at right pointer
	swap(vector[start], vector[right]);
	
	// return the pivot index
	return right;
}

void quickSortHelper(vector<int>& vector, int start, int end) {
	if (start >= end) return;
	// Partition the vector and get the pivot index
	int pivotIndex = partitionVector(vector, start, end); // gives us the center number which is in the right place
	quickSortHelper(vector, start, pivotIndex - 1); // sort the left sub-vector
	quickSortHelper(vector, pivotIndex + 1, end); // sort the left sub-vector
}


int main()
{
	srand(std::time(0));
	vector<int> testZero;
	// Create 10 vectors of random length (0-20) with random numbers (0-100)
	vector<vector<int>> randomVectors;
	for (int i = 0; i < 10; ++i) {
		int randomLength = rand() % 21; // Random length 0-20
		vector<int> tempVector;
		for (int j = 0; j < randomLength; ++j) {
			tempVector.push_back(rand() % 101); // Random number 0-100
		}
		randomVectors.push_back(tempVector); // Add the generated vector to the list
	}
	
	// Sort and print each vector

	// Handle the first three vectors separately for specific output formatting
	cout << "The 1st set of data(" << randomVectors[0].size() << "):" << endl;
	// Handle empty vector case
	if (randomVectors[0].size() == 0) {
		cout << " The vector is empty " << endl << endl;
		cout << " The sorted vector is empty" << endl << endl;
	}
	else {
		cout << " Initial vector values are: " << endl << "  ";
		printVector(randomVectors[0]); // Print initial vector
		cout << " The sorted vector values are:" << endl << "  ";
		quickSortHelper(randomVectors[0], 0, randomVectors[0].size() - 1); // Sort the vector
		printVector(randomVectors[0]); // Print sorted vector
		cout << endl;
	}

	// Repeat for the second vector
	cout << "The 2nd set of data(" << randomVectors[1].size() << "):" << endl;
	if (randomVectors[1].size() == 0) {
		cout << " The vector is empty " << endl << endl;
		cout << " The sorted vector is empty" << endl << endl;
	}
	else {
		cout << " Initial vector values are: " << endl << "  ";
		printVector(randomVectors[1]);
		cout << " The sorted vector values are:" << endl << "  ";
		quickSortHelper(randomVectors[1], 0, randomVectors[1].size() - 1);
		printVector(randomVectors[1]);
		cout << endl;
	}

	// Repeat for the third vector
	cout << "The 3rd set of data(" << randomVectors[2].size() << "):" << endl;
	if (randomVectors[2].size() == 0) {
		cout << " The vector is empty " << endl << endl;
		cout << " The sorted vector is empty" << endl << endl;
	}
	else {
		cout << " Initial vector values are: " << endl << "  ";
		printVector(randomVectors[2]);
		cout << " The sorted vector values are:" << endl << "  ";
		quickSortHelper(randomVectors[2], 0, randomVectors[2].size() - 1);
		printVector(randomVectors[2]);
		cout << endl;
	}

	// Handle the remaining vectors in a loop
	for (int i = 3; i < 10; ++i) {
		cout << "The " << (i + 1) << "th set of data(" << randomVectors[i].size() << "):" << endl;
		if (randomVectors[i].size() == 0) {
			cout << " The vector is empty " << endl << endl;
			cout << " The sorted vector is empty" << endl << endl;
		}
		else {
			cout << " Initial vector values are: " << endl << "  ";
			printVector(randomVectors[i]);
			cout << " The sorted vector values are:" << endl << "  ";
			quickSortHelper(randomVectors[i], 0, randomVectors[i].size() - 1);
			printVector(randomVectors[i]);
			cout << endl;
		}
	}

	// Pause the system before exiting
	system("PAUSE");
	return 0;
}
