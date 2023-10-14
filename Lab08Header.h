#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

void checkForData(vector<double>& dvdVector, vector<double>& musicVector, vector<double>& tvVector);

void sortVectors(vector<double>& vector);

double findTotal(vector<double> vector);

double findMean(vector<double> vector, double total);

double findMedian(vector<double> vector);
