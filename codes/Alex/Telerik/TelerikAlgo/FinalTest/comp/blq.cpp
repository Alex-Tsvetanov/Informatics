#include <string>
#include <iostream>

using namespace std;

const string null = string ();
string FindPositiveString(string _template);
bool CanComplete(string _template);
string GetMinimal(string first, string second);

int main ()
{
	string _template;
	cin >> _template;
	auto positiveString = FindPositiveString(_template);
	cout << (positiveString) << std::endl;
}

string FindPositiveString(string _template)
{
	_template += ",";
	if (!CanComplete(_template))
	{
		return "invalid";
	}
	
	for (int i = 0; i < (int)_template.length (); ++i)
	{
		if (_template[i] == '?')
		{
			for (auto& ch : (string)(",0123456789"))
			{
				auto current = _template.substr (0, i) + ch + _template.substr (i + 1);
				if (CanComplete(current))
				{
					_template = current;
					break;
				}
			}
		}
	}

	return _template.substr(0, _template.length () - 1);
}

bool CanComplete(string _template)
{
	string* minEnd = new string[_template.length () + 1];
	minEnd[0] = string ();
	for (auto i = 0; i < (int)_template.length (); ++i)
	{
		if ((_template[i] == '?' || _template[i] == ',') && i > 0)
		{
			string best = null;
			for (auto j = i - 1; j >= 0; --j)
			{
				if (_template[j] == ',')
				{
					break;
				}

				if (minEnd[j] == null)
				{
					continue;
				}

				string cur = GetMinimal(_template.substr(j, i - j), minEnd[j]);
				if (cur != null)
				{
					if (best == null || cur.length () < best.length () || cur.length () == best.length () && cur < best)
					{
						best = cur;
					}
				}
			}

			minEnd[i + 1] = best;
		}
	}

	return minEnd[_template.length ()] != null;
}

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

	auto already = first.length () > second.length ();
	bool* canBeBigger = nullptr;
	if (!already)
	{
		canBeBigger = new bool[first.length () + 1];
		auto can = false;
		for (auto i = first.length () - 1; i >= 0; --i)
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

	auto stringBuilder = string();
	for (int i = 0; i < (int)first.length (); ++i)
	{
		if (first[i] == '?')
		{
			if (already)
			{
				if (i == 0)
				{
					stringBuilder+=('1');
				}
				else
				{
					stringBuilder+=('0');
				}
			}
			else
			{
				if (canBeBigger[i + 1])
				{
					stringBuilder+=(second[i]);
				}
				else
				{
					already = true;
					stringBuilder+=((char)(second[i] + 1));
				}
			}
		}
		else
		{
			stringBuilder+=(first[i]);
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
