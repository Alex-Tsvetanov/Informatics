#include <iostream>

using namespace std;

int priority (char x)
{
	switch (x)
	{
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '^': return 3;
		case '<': return 4;
		case '>': return 4;
		case '~': return 5;
		case '(': return 6;
		default:  return 0;
	}
}

void divide (string expr)
{
	int pos_of_min_priority = -1;
	int bonus = 0;
	for (int i = 0 ; i < expr.size () ; i ++)
	{
		if (expr [i] == '(')
		{

		}
		else
		{
			int curr_priority = priority (expr [i]);
		}

	}
}

int main ()
{

}
