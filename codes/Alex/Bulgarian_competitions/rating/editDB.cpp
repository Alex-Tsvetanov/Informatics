#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

struct data
{
	string city;
	string school;
	int grade;
	vector < int > points;
	int total;

	data (string _city = "", string _school = "", int _grade = -1, vector < int > _points = vector <int>(), int _total = 0) : city (_city), school (_school), grade (_grade), points (_points), total (_total)
	{}
};

map < string, data > currDB;

int main ()
{
	char GROUP;
	cin >> GROUP;
	string ouput = "./db";
	ouput += GROUP;
	cout << ouput << endl;
	ifstream readDB (ouput.c_str ());
	ifstream readAddingDB ("./additionDB");
	ofstream writeNewDB ("./newDB");
	
	int number_of_comps_res = 0;

	{
		if (!readDB.eof ())
		{
			int number_of_comps;
			readDB >> number_of_comps;
			cout << number_of_comps << endl;
			number_of_comps_res += number_of_comps;
			while (!readDB.eof ())
			{
				string name, city, school; 
				int grade;
				vector < int > points;
				int total;

				readDB >> name;
				if (name == "End") break;
				readDB >> city >> school >> grade;
				for (int i = 0 ; i < number_of_comps ; i ++)
				{
					int curr;
					readDB >> curr;
					points.push_back (curr);
				}

				readDB >> total;

				currDB [name] = data (city, school, grade, points, total);
			}
		}
	}
	{
		if (!readAddingDB.eof ())
		{
			int number_of_comps;
			readAddingDB >> number_of_comps;
			cout << number_of_comps << endl;
			number_of_comps_res += number_of_comps;
			while (!readAddingDB.eof ())
			{
				string name, city, school; 
				int grade;
				vector < int > points;
				int total;

				readAddingDB >> name;
				if (name == "End") break;
				readAddingDB >> city >> school >> grade;
				cout << name << " " << city << " " << school << " " << grade << "\n";
				for (int i = 0 ; i < number_of_comps ; i ++)
				{
					int curr;
					readAddingDB >> curr;
					points.push_back (curr);
				}

				readAddingDB >> total;

				cout << " " << total << "\n";

				for (auto& x : currDB [name].points)
					points.push_back (x);
				currDB [name] = data (city, school, grade, points, total + currDB [name].total);
				cout << "\tEnd" << endl;
			}
		}
	}

	writeNewDB << number_of_comps_res << endl;
	map <string, data>::iterator it;
	for (it = currDB.begin () ; it != prev (currDB.end ()) ; it ++)
	{
		auto& x = *it;
		writeNewDB << x.first << "\t" << x.second.city << "\t" << x.second.school << "\t" << x.second.grade << "\t";
		for (auto& X : x.second.points)
			writeNewDB << X << "\t";
		writeNewDB << x.second.total << endl;
	}
	{
		auto& x = *it;
		writeNewDB << x.first << "\t" << x.second.city << "\t" << x.second.school << "\t" << x.second.grade << "\t";
		for (auto& X : x.second.points)
			writeNewDB << X << "\t";
		writeNewDB << x.second.total;
	}

	string command = "mv newDB " + ouput;
	system (command.c_str ());
}
