// Chad Huntebrinker 
// crh92d@umsystem.edu
// 10/155/200
// CS201L Lab 01

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "Lab08Header.h"
using namespace std;

int main() {
	vector<double> dvdVector;
	vector<double> musicVector;
	vector<double> tvVector;
	double dvdTotal, tvTotal, musicTotal, dvdMean, tvMean, musicMean, dvdMedian, tvMedian, musicMedian;
	const string errorMessage = "nan";
	ofstream fout;
	fout.open("output.txt");

	//This function reads in the data from the input file.
	checkForData(dvdVector, musicVector, tvVector);

	//These functions sort the different vectors from least to greatest.
	//If the vector is empty, then nothing happens to it.
	sortVectors(dvdVector);
	sortVectors(tvVector);
	sortVectors(musicVector);
	
	//These functions find the total of the different vectors.
	//If there is nothing in the vector, then the total is 0.
	dvdTotal = findTotal(dvdVector);
	tvTotal = findTotal(tvVector);
	musicTotal = findTotal(musicVector);

	//The following below are functions that find the mean of the vectors.
	//If there is nothing in the vector, an error is thrown inside the function which is
	//caught outside the function.  If there is an error thrown, then the mean is 0.
	try {
		dvdMean = findMean(dvdVector, dvdTotal);
	}
	catch (runtime_error error) {
		dvdMean = 0;
	}
	try {
		tvMean = findMean(tvVector, tvTotal);
	}
	catch (runtime_error error) {
		tvTotal = 0;
	}
	try {
		musicMean = findMean(musicVector, musicTotal);
	}
	catch (runtime_error error) {
		musicMean = 0;
	}

	//The following below are functions that find the median of the vectors.
	//If there is nothing in the vector, an error is thrown inside the function which is
	//caught outside the function.  If there is an error thrown, then the median is 0.
	try {
		dvdMedian = findMedian(dvdVector);
	}
	catch (runtime_error error) {
		dvdMedian = 0;
	}
	try {
		tvMedian = findMedian(tvVector);
	}
	catch (runtime_error error) {
		tvMedian = 0;
	}
	try {
		musicMedian = findMedian(musicVector);
	}
	catch (runtime_error error) {
		musicMedian = 0;
	}

	//The following outputs the information recieved into the file "output.txt".
	//If the total of any type is 0, then the message "nan" is outputted to the file.
	fout << "Key      Total      Mean    Median" << endl;
	fout << setfill('-') << setw(34) << "" << endl;
	fout << setfill(' ');

	fout << "DVD " << setw(10) << dvdTotal << "  ";
	if (dvdTotal == 0) {
		fout << setw(8) << errorMessage << " " << setw(8) << errorMessage << endl;
	}
	else {
		fout << setw(8) << dvdMedian << " " << setw(8) << dvdMean << endl;
	}
		
	fout << "TV " << setw(11) << tvTotal << "  ";
	if (tvTotal == 0) {
		fout << setw(8) << errorMessage << " " << setw(8) << errorMessage << endl;
	}
	else {
		fout << setw(8) << tvMedian << " " << setw(8) << tvMean << endl;
	}

	fout << "MUSIC " << setw(8) << musicTotal << "  ";
	if (musicTotal == 0) {
		fout << setw(8) << errorMessage << " " << setw(8) << errorMessage << endl;
	}
	else {
		fout << setw(8) << musicMedian << " " << setw(8) << musicMean << endl;
	}


	fout.close();

	return 0;
}

