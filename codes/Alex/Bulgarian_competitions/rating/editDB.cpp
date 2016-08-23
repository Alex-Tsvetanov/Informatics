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
	string grade;
	int total;

	data (string _city = "", string _school = "", string _grade = "", int _total = 0) : city (_city), school (_school), grade (_grade), total (_total)
	{}
	static pair <string, data> Split (string parse = "", string by = "\t")
	{
		parse += by [0];
		vector < string > things;
		int s = 0;
		for (int i = 0 ; i < (int)parse.size () ; i ++)
		{
			if (by.find (parse [i]) != string::npos)
			{
				things.push_back (parse.substr (s, i - s));
				s = i + 1;
			}
		}
		data Return;
		string name;
		name = things [0];
		Return.city = things [1];
		Return.school = things [2];
		Return.grade = things [3];
		Return.total = atoi (things [4].c_str ());
//		cout << name << "\n";
		return {name, Return};
	}
};

map < string, data > curDB;
map < string, data > addDB;
map < string, data > merge;

void read (string in, map < string, data >& db)
{
	ifstream fin (in.c_str ()); 
	while (!fin.eof ())
	{
		string to_parse;
		getline (fin, to_parse);
//		cout << "to_parse: " << to_parse << "\n";
		if (to_parse == "")
			break;
		db.insert (data::Split (to_parse, "\t"));
	}
}

void Merge ()
{
	for (auto x : addDB)
	{
		if (curDB.find (x.first) != curDB.end ())
		{
			x.second.total += curDB [x.first].total;
			merge.insert (x);
		}
		else
			merge.insert (x);
	}
}
void output ()
{
//	for (auto& x : curDB)
//	{
//		printf ("%s\t%s\t%s\t%s\t%d\n", x.first.c_str (), x.second.city.c_str (), x.second.school.c_str (), x.second.grade.c_str (), x.second.total);
//	}
//	cout << "-----------------------\n";
//	for (auto& x : addDB)
//	{
//		printf ("%s\t%s\t%s\t%s\t%d\n", x.first.c_str (), x.second.city.c_str (), x.second.school.c_str (), x.second.grade.c_str (), x.second.total);
//	}
//	cout << "-----------------------\n";
	for (auto& x : merge)
	{
		printf ("%s\t%s\t%s\t%s\t%d\n", x.first.c_str (), x.second.city.c_str (), x.second.school.c_str (), x.second.grade.c_str (), x.second.total);
	}
}

int main ()
{
	char GROUP;
	cin >> GROUP;
	string read_from = string ("db") + GROUP;
	string add_read = string ("addDB");
	read (read_from, curDB);
	read (add_read, addDB);
	Merge ();
	output ();
}

