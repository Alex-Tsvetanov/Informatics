#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string str;
char* expressionToParse = &str [0];

char peek()
{
    return *expressionToParse;
}

char get()
{
    return *expressionToParse++;
}

int expression();

int number()
{
    int result = get() - '0';
    while (peek() >= '0' && peek() <= '9')
    {
        result = 10*result + get() - '0';
    }
    return result;
}

int factor()
{
    if (peek() >= '0' && peek() <= '9')
        return number();
    else if (peek() == '(')
    {
        get(); // '('
        int result = expression();
        get(); // ')'
        return result;
    }
    else if (peek() == '|')
    {
        get(); // '|'
        int result = expression();
        get(); // '|'
        return abs (result);
    }
    else if (peek() == '~')
    {
        get();
        return ~factor();
    }
    else if (peek() == '-')
    {
        get();
        return -factor();
    }
    return 0; // error
}
int powering (int start)
{
    int result = start;
	if (peek () == '^')
	{
		get (); // '^'
		int operand = powering (factor ());
		result = pow (result, operand);
	}
    return result;
}
int term()
{
	int result;
	if (peek() == '*' || peek() == '/')
	{
		result = factor();
		while (peek() == '*' || peek() == '/')
			if (get() == '*')
				result *= powering(factor ());
			else
				result /= powering(factor ());
	}
	else
		result = powering (factor());
    return result;
}

int expression()
{
    int result;
    if (peek() == '+' || peek() == '-')
	{
		result = term ();
		while (peek() == '+' || peek() == '-')
			if (get() == '+')
				result += term();
			else
				result -= term();
	}
	else
		result = term ();
    return result;
}

int main ()
{
	cin >> str;
    int result = expression();
	cout << result << endl;
    return 0;
}
