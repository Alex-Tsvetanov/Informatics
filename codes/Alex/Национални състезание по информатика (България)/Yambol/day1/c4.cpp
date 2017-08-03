#include <iostream>
#include <map>
#include <vector>

using namespace std;

using Int = long long;

int getPriority (char s)
{
	switch(s)
	{
		case '+':
			return 2;
		case '-':
			return 2;
		case '*':
			return 3;
		case '/':
			return 3;
		case '(':
			return 4;
		case ')':
			return -4;
		default:
			return 1;
	}
}

bool isDigit (char c)
{
	return '0' <= c and c <= '9';
}

int getSplitPos (const string& expr, int from, int to)
{
	int pos = -1, optimal = 1e9, priority = 0;

	for (int i = from ; i < to ; i ++)
	{
		if (expr [i] == '(')
			priority += getPriority (expr [i]);
		else if (expr [i] == ')')
			priority += getPriority (expr [i]);
		else if (isDigit (expr [i]))
			continue;
		else if ((i != 0 and not isDigit (expr [i - 1]) and expr [i] == '-') or (i == 0 and expr [i] == '-')) // single minus
		{
			continue;
		}
		else if (priority + getPriority (expr [i]) < optimal)
		{
			optimal = priority + getPriority (expr [i]);
			pos = i;
		}
	}
	return pos;
}

Int parse (const string& expr, int from, int to)
{
	//cout << "parse(" << expr.substr (from, to - from) << ")" << endl;
	bool isNegative = false;
	if (expr [from] == '-')
	{
		from ++;
		isNegative = true;
	}
	Int number = 0;
	for (int i = from ; i < to ; i ++)
	{
		number = number * 10 + (expr [i] - '0');
	}
	if (isNegative)
		number = -number;
	return number;
}

map <char, Int(*)(Int, Int)> operation = {
	{'+', [](Int a, Int b) { return a + b; }},
	{'-', [](Int a, Int b) { return a - b; }},
	{'*', [](Int a, Int b) { return a * b; }},
	{'/', [](Int a, Int b) { return a / b; }},
};

Int calc (const string& expr, int from, int to)
{
	//cout << expr.substr (from, to - from) << endl;
	int split = getSplitPos (expr, from, to);

	if (split == -1)
		return parse (expr, from, to);

	return operation [expr [split]] (calc (expr, from, split), calc (expr, split + 1, to));
}

int main ()
{
	vector < int > invisible;
	string expr;
	cin >> expr;
	int operatorPos = -1;
	for (int i = 0 ; i < expr.size () ; i ++)
		if (expr [i] == '#')
			invisible.push_back (i);
		else if (operatorPos == -1 and i != 0 and not isDigit (expr [i]))
		{
			operatorPos = i;
		}
	bool print = false;
	int equalPos = expr.find ('=');
	for (char i = '9' ; i >= '0' ; i --)
	{
		for (auto& x : invisible)
			expr [x] = i;
		//Int left = operation [expr [operatorPos]] (atoll (expr.substr (0, operatorPos).c_str ()), atoll (expr.substr (operatorPos + 1, equalPos - operatorPos - 1).c_str ()));
		//Int right = atoll (expr.substr (equalPos + 1).c_str ());
		//string left = expr.substr (0, equalPos);
		//string right = expr.substr (equalPos + 1);
		//cout << left + " == " + right << endl;
		//cout << calc (expr, 0, equalPos) << " == " << calc (expr, equalPos + 1, expr.size ()) << endl;
		if (calc (expr, 0, equalPos) == calc (expr, equalPos + 1, expr.size ()))
		//if (left == right)
		{
			cout << i << " ";
			print = true;
		}
	}
	if (not print)
		cout << "wrong";
	cout << endl;
}
