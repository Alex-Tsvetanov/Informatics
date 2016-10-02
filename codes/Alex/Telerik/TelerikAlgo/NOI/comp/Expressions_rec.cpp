#include <iostream>
#include <stack>
#include <cmath>
#include <string>

using namespace std;

int priority (char x)
{
	switch (x)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		case '<':
		case '>':
			return 4;
		case '~':
			return 5;
		case '(':
		case '{':
			return 6;
		case ')':
		case '}':
			return -6;
		default:
			return 0;
	}
}

bool greater_then (char a, char b)
{
	if (a == '^' and b == '^')
		return true;
	return priority (a) < priority (b);
}

int solve (string expr)
{
	detect_brackets_in_ends:
	{
		stack < int > pos_brackets;
		for (int i = 0 ; i < expr.size () ; i ++)
		{
			if (expr
		}
	}
	devide:
	{
		int ind = -1, priority_min = 100;
		int bonux = 0;
		for (int i = 0 ; i < expr.size () ; i ++)
		{
			if((expr [i] == '(') or
			   (expr [i] == ')') or
			   (expr [i] == '{') or
			   (expr [i] == '}'))
				bonux += priority (expr [i]);
			else
			{
				int priority_curr = priority (expr [i]) + bonux;
				if (priority_min > priority_curr)
				{
					ind = i;
					priority_min = priority_curr;
				}
			}
		}
	}
}

string editing (string expr)
{
	for (int i = 0 ; i < expr.size () ; i ++)

}

int Solve (string expr)
{
	return solve (editing (expr));
}

int main ()
{
	string expr;
	cin >> expr;
	cout << Solve (expr);
}
