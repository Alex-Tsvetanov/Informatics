#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

std::vector<int> split(const std::string &s, char delim) {
	std::vector<int> elems;
	std::stringstream stream(s);
	std::string number;
	while (std::getline(stream, number, delim)) {
		elems.push_back(std::stoi(number));
	}

	return elems;
}

int main()
{
	string line;

	std::getline(std::cin, line);

	vector<int> splittedLine = split(line, ' ');

	double a = (double)splittedLine[0];
	double b = (double)splittedLine[1];

	double area = a * b;
	double restArea = (((1.0 / 3.0) * a) * ((1.0 / 3.0) * a)) / 2.0;

	double result = area + (restArea * 4);

	result = round(result * 1000.0) / 1000.0;

	cout << result << endl;

	return 0;
}