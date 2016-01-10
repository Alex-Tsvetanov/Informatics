#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

std::vector<int> split(string s) {
	std::vector<int> elems;

	for (size_t i = 0; i < s.size(); i++)
	{
		elems.push_back(s[i] - '0');
	}

	return elems;
}

int main()
{
	string a;
	string b;
	int carry = 0;

	std::getline(std::cin, a);
	std::getline(std::cin, b);

	vector<int> aBits = split(a);
	vector<int> bBits = split(b);
	vector<int> result;

	int length = fmax(aBits.size(), bBits.size());

	for (int i = 0; i < length; i++)
	{
		int currentBitA;
		int currentBitB;

		if (aBits.size() <= i)
		{
			currentBitA = 0;
		}
		else
		{
			currentBitA = aBits[i];
		}

		if (bBits.size() <= i)
		{
			currentBitB = 0;
		}
		else
		{
			currentBitB = bBits[i];
		}

		if (currentBitA + currentBitB + carry == 3)
		{
			result.push_back(1);
			carry = 1;
		}
		if (currentBitA + currentBitB + carry == 2)
		{
			result.push_back(0);
			carry = 1;
		}
		if (currentBitA + currentBitB + carry == 1)
		{
			result.push_back(1);
			carry = 0;
		}
		if (currentBitA + currentBitB + carry == 0)
		{
			result.push_back(0);
			carry = 0;
		}
	}

	if (carry != 0)
	{
		result.push_back(carry);
	}

	for (int i = result.size() - 1; i >= 0; i--)
	{
		cout << result[i];
	}

	cout << "" << endl;

	return 0;
}