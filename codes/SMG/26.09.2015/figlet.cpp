#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream letters [52];
string ans [6];
int main ()
{
	/*for (unsigned char a = 'A' ; a <= 'Z' ; a ++)
	{
		a -= 'A';
		a += 'a';
		string b = "figlet ";
		b += a;
		b += " > ";
		b += a;
		b += "+.txt";
		system (b.c_str ());
		a -= 'a';
		a += 'A'
	}
	
	for (unsigned char a = 'a' ; a <= 'a' ; a ++)
	{
		string b = "figlet ";
		b += a;
		b += " > ";
		b += a;
		b += ".txt";
		system (b.c_str ());
	}
	return 0;*/
	/*
	string a;
	getline (cin, a);
	a = "figlet_" + a;
	string b;
	for (int i = 0 ; i < (int)a.size () ; i ++)
	{
		if (a [i] == '_')
			b += " ";
		else if (a [i] == ' ')
			b += "\\ ";
		else
			b += a [i];
	}
	system (b.c_str ());
	*/
	string a;
	getline (cin, a);

	for (int i = 0 ; i < 26 ; i ++)
	{
		string text;
		text = ((char)('a' + i));
		text += ".txt";
		letters [i] = ifstream (text.c_str ());
		text = ((char)('A' + i));
		text += ".txt";
		letters [i + 26] = ifstream (text.c_str ());
	}
	
	for (int line = 0 ; line < 6; line ++)
	{
		string lineText;
		for (int i = 0 ; i < (int)a.size () ; i ++)
		{
			string readed;
			int ind;
			if (a [i] <= 'z') ind = a [i] - 'a';
			if (a [i] <= 'Z') ind = a [i] - 'A' + 26;
			getline (letters [ind], readed);
			lineText += readed;
		}
		lineText += ' ';
		string endText;
		for (int i = 0; i < (int)lineText.size () ; i ++)
			if (lineText [i] == '\\' and lineText [i + 1] == '|')
			{	endText += "\\"; i ++;}
			else if (lineText [i] == '|' and lineText [i + 1] == '/')
			{	endText += '/'; i ++;}
			else
				endText += lineText [i];
		ans [line] = endText;
	}

	cout << ans [0] << "\n";
	cout << ans [1] << "\n";
	cout << ans [2] << "\n";
	cout << ans [3] << "\n";
	cout << ans [4] << "\n";
	cout << ans [5] << "\n";

}
