#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

int main ()
{
	string a, b;
	cin >> a >> b;
	int aH = 0, aM = 0, aS = 0;
	int bH = 0, bM = 0, bS = 0;
	{
		if (b.find ("::") != string::npos)
		{
			string hours = b.substr (0, b.find ("::"));
			b.erase (0, b.find ("::") + 2);
			bH = atoi (hours.c_str ()); 
		}
		if (a.find ("::") != string::npos)
		{
			string hours = a.substr (0, a.find ("::"));
			a.erase (0, a.find ("::") + 2);
			aH = atoi (hours.c_str ()); 
		}
	}

	{
		if (b.find (":") != string::npos)
		{
			string minutes = b.substr (0, b.find (":"));
			b.erase (0, b.find (":") + 1);
			bM = atoi (minutes.c_str ()); 
		}
		if (a.find (":") != string::npos)
		{
			string minutes = a.substr (0, a.find (":"));
			a.erase (0, a.find (":") + 1);
			aM = atoi (minutes.c_str ()); 
		}
	}

	{
		{
			string seconds = b;
			bS = atoi (seconds.c_str ()); 
		}
		{
			string seconds = a;
			aS = atoi (seconds.c_str ()); 
		}
	}


	//cout << aH << ":" << aM << ":" << aS << " +\n";
	//cout << bH << ":" << bM << ":" << bS << " =\n";
	aS += bS;
	aM += bM;
	aH += bH;

	//cout << aH << ":" << aM << ":" << aS << " =\n";

	aM += aS / 60;
	aS %= 60;
	aH += aM / 24;
	aM %= 24;
	//cout << aH << ":" << aM << ":" << aS << " =\n";

	if (aH == 0)
		cout << aM << ":" << setw (2) << setfill ('0') << aS << endl;
	else
		cout << aH << "::" << aM << ":" << setw (2) << setfill ('0') << aS << endl;
}
