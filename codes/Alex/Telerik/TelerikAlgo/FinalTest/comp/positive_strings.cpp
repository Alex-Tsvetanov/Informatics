#include <string>
#include <iostream>

using namespace std;

string null = "";
string GetMinimal(string first, string second)
{
	if (first.length () == 0 || first[0] == '0')
	{
		return null;
	}

	if (first.length () < second.length ())
	{
		return null;
	}

	bool already = first.length () > second.length ();
	bool* canBeBigger = nullptr;
	if (!already)
	{
		canBeBigger = new bool[first.length () + 1];
		bool can = false;
		for (size_t i = first.length () - 1; i >= 0; --i)
		{
			if (first[i] == '?')
			{
				if (second[i] != '9')
				{
					can = true;
				}
			}
			else
			{
				if (first[i] > second[i])
				{
					can = true;
				}
				else if (first[i] < second[i])
				{
					can = false;
				}
			}

			canBeBigger[i] = can;
		}

		if (!canBeBigger[0])
		{
			return null;
		}
	}

	string stringBuilder;
	for (size_t i = 0; i < first.length() ;++i)
	{
		if (first[i] == '?')
		{
			if (already)
			{
				if (i == 0)
				{
					stringBuilder += ('1');
				}
				else
				{
					stringBuilder += ('0');
				}
			}
			else
			{
				if (canBeBigger[i + 1])
				{
					stringBuilder += (second[i]);
				}
				else
				{
					already = true;
					stringBuilder += ((char)(second[i] + 1));
				}
			}
		}
		else
		{
			stringBuilder += first[i];
			if (!already)
			{
				if (first[i] > second[i])
				{
					already = true;
				}

				if (first[i] < second[i])
				{
					return null;
				}
			}
		}
	}

	return stringBuilder;
}

bool CanComplete(string _template)
{
	cout << "CanComplete" << std::endl;
	string* minEnd = new string [_template.length () + 1];
	minEnd [0] = null;
	cout << "CanComplete" << std::endl;
	for (size_t i = 0; i < _template.length (); ++i)
	{
		cout << "CanComplete: " << _template [i] << std::endl;
		if ((_template[i] == '?' || _template[i] == ',') && i > 0)
		{
			string best = null;
			for (int  j = i - 1; j >= 0; --j)
			{
				cout << "CanComplete: " << _template [i] << " " << _template [j] << std::endl;
				if (_template[j] == ',')
				{
					break;
				}

				if (minEnd[j] == null)
				{
					continue;
				}

				cout << "CanComplete: " << _template [i] << " " << _template [j] << std::endl;
				string cur = GetMinimal (_template.substr (j, i - j), minEnd[j]);
				cout << "CanComplete: " << cur << std::endl;
				if (cur != null)
				{
					if ((best == null || cur.length () < best.length () || cur.length () == best.length ()) and cur < best)
					{
						best = cur;
					}
				}
				cout << "CanComplete: " << best << std::endl;
			}

			minEnd[i + 1] = best;
		}
	}

	return minEnd[_template.length ()] != null;
}

string FindPositiveString (string _template)
{
	cout << "In FindPositiveString (): " << std::endl;
	_template += ",";
	cout << "_template: " << _template << std::endl;
	if (!CanComplete (_template))
	{
		return "invalid";
	}
	cout << "_template: " << _template << std::endl;
	
	for (size_t i = 0; i < _template.length (); ++i)
	{
		cout << "_template [" << i << "]: " << _template << std::endl;
		if (_template [i] == '?')
		{
			string y = ",0123456789";
			for (size_t j = 0 ; j < y.size () ; j ++)
			{
				auto& x = y [j];
				string current = _template.substr (0, i) + x + _template.substr (i + 1);
				if (CanComplete (current))
				{
					_template = current;
					break;
				}
			}
		}
	}

	return _template.substr (0, _template.length () - 1);
}

int main ()
{
	cout << "Input template" << std::endl;
	string _template;
	cout << "_template: " << _template << std::endl;
	cin >> _template;
	cout << _template << std::endl;
	string positiveString = FindPositiveString (_template);
	cout << positiveString << "\n";
}
