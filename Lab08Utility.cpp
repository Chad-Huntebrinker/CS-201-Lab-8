#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "Lab08Header.h"

using namespace std;

//This functions reads the input from the file and puts it into a function.  It first checks what type
//of data it is (DVD, TV, or MUSIC) and then puts it in the correct vector.
void checkForData(vector<double>& dvdVector, vector<double>& musicVector, vector<double>& tvVector) {
	string checkData;
	double temp;
	ifstream fin;

	fin.open("input.txt");

	while (fin >> checkData) {
		if (checkData == "DVD") {
			fin >> temp;
			dvdVector.push_back(temp);
		}
		else if (checkData == "TV") {
			fin >> temp;
			tvVector.push_back(temp);
		}
		else {
			fin >> temp;
			musicVector.push_back(temp);
		}
	}

	fin.close();

}

//This function sorts the vectors from least to greatest.  If there is nothing in the
//vector, then nothing happens to it.
void sortVectors(vector<double>& vector) {
	int i, j, error = 0;
	double temp;
	if (vector.size() > 0) {
		for (i = 1; i < vector.size(); ++i) {
			j = i;
			while (j > 0 && vector.at(j) < vector.at(j - 1)) {
				temp = vector.at(j);
				vector.at(j) = vector.at(j - 1);
				vector.at(j - 1) = temp;
				--j;
			}
		}
	}
}
//This function finds the total of the vectors.  If there is nothing in the vector, then
//it is given the number 0.
double findTotal(vector<double> vector) {
	int i;
	double total = 0, temp;
	string returnNumber;
	if (vector.size() != 0) {
		for (i = 0; i < vector.size(); ++i) {
			temp = vector.at(i);
			total = temp + total;
		}
	}
	else {
		total = 0;
	}

	return total;
}

//This function finds the mean of the vectors.  If there is nothing in the vector, then
//an error is thrown to the main function.
double findMean(vector<double> vector, double total) {
	if (total > 0) {
		int x;
		x = vector.size();

		return total / x;
	}
	else {
		throw runtime_error("Error with mean");
	}
}

//This function finds the median of the vectors by seing if the total number of elements in
//the vector is an even number or odd number. If it is odd, then it finds the middle number
//of the vector.  If it is even, then it finds the two middle numbers and takes the average of them.
//If there is nothing in the vector, then an error is thrown to the main function.
double findMedian(vector<double> vector) {
	int x;
	double value1, value2 = 0;
	x = vector.size();
	if (x > 0) {
		if (x % 2 == 0) {
			x = x / 2;
			value1 = vector.at(x);
			value2 = vector.at(x - 1);
			return (value1 + value2) / 2;
			
		}
		else {
			x = x / 2;
			value1 = vector.at(x);
			return value1;
		}
	}
	else {
		throw runtime_error("Error with Median");
	}
}
