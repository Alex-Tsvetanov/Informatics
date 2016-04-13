#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

const unsigned char NOT_CALCULATED = (unsigned char)(-1);
int LETTS;

char** rel;
string s;
unsigned char*** table;
unsigned char** split;

unsigned char can(unsigned char i, unsigned char j, unsigned char ch)
{
    unsigned char c1, c2, pos;
    if (table[i][j][ch] != NOT_CALCULATED)
        return table[i][j][ch];
    if (i == j)
        return(s[i] == ch + 'a');
    for (c1 = 0; c1 < LETTS; c1++)
        for (c2 = 0; c2 < LETTS; c2++)
            if (rel[c1][c2] == ch + 'a')
                for (pos = i; pos <= j-1; pos++)
                    if (can(i, pos, c1))
                        if (can(pos + 1, j, c2))
                        {
                            table[i][j][ch] = 1;
                            split[i][j] = pos;
                            return 1;
                        }
    table[i][j][ch] = 0;
    return 0;
}
void putBrackets(unsigned char i, unsigned char j)
{
    if (i == j)
        printf("%c", s[i]);
    else
    {
        printf("(");
        putBrackets(i, split[i][j]);
        printf("*");
        putBrackets(split[i][j] + 1, j);
        printf(")");
    }
}
int main()
{
    cin >> LETTS;
    rel = new char* [LETTS];
    for (int i = 0 ; i < LETTS ; i ++)
    {
	rel [i] = new char [LETTS];
	for (int j = 0 ; j < LETTS ; j ++)
	    cin >> rel [i][j];
    }
    cin >> s;
    unsigned char len = s.size ();
    for (int i = 0 ; i < 1; i ++)
	{
    	table = new unsigned char** [len];
		split = new unsigned char*  [len];
    	for (int j = 0 ; j < len; j ++)
		{
			table [j] = new unsigned char* [len];
			split [j] = new unsigned char [len];
    		for (int k = 0 ; k < len; k ++)
    		{
    			table [j][k] = new unsigned char [LETTS];
				for (int l = 0 ; l < LETTS ; l ++)
					table [j][k][l] = NOT_CALCULATED;
    		}
    	}
    }
    if (can(0, len-1, 0))
        putBrackets(0, len-1);
    else
        printf("Няма решение");
    return 0;
}
