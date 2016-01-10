#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

std::vector<int> split(const std::string &s, char delim) {
	std::vector<int> elems;
	std::stringstream ss(s);
	std::string number;
	while (std::getline(ss, number, delim)) {
		elems.push_back(std::stoi(number));
	}
	return elems;
}

int main()
{
	string result = "";
	for (int i = 0; i < 5; i++)
	{
		string a1;
		string a2;

		std::getline(std::cin, a1);
		std::getline(std::cin, a2);

		vector<int> a1Elements = split(a1, ' ');
		vector<int> a2Elements = split(a2, ' ');

		bool isLess = false;
		bool hasMatch = false;

		if (a1Elements[0] <= a2Elements[0])
		{
			isLess = true;
		}

		for (size_t i = 1; i < a1Elements.size(); i++)
		{
			if (a1Elements[i] == i)
			{
				hasMatch = true;
				break;
			}
		}

		for (size_t i = 1; i < a2Elements.size(); i++)
		{
			if (a2Elements[i] == i)
			{
				hasMatch = true;
				break;
			}
		}

		if (isLess && hasMatch)
		{
			result += "1";
		}
		else
		{
			result += "0";
		}
	}

	cout << result << endl;

	return 0;
}