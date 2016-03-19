#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long lld;

char seq[200002];
char value[200002][27];
int N, M, Q;

void Input()
{
    scanf("%s", seq);
    N = strlen(seq);

    do
    {
        scanf("%s", value[Q++]);
        if (M == 0) M = strlen(value[Q-1]);
    }
    while (value[Q-1][0] != '2');

    Q--;
}

char stk[200002];
int ssz;

char GetValue(char a1, char a2)
{
    if (a1 != a2 || (a1 == '0')) return '1';
    return '0';
}
bool IsNum(char c)
{
    return (c == '0' || c == '1');
}
int main ()
{
    //freopen("input.txt", "r", stdin);

    Input();
    for (int i=0; i<Q; i++)
    {
        ssz = 0;
        for (int j=0; j<N; j++)
        {
            if (seq[j] == '(')
            {
                stk[++ssz] = '(';
                continue;
            }
            if (seq[j] == ')')
            {
                /// v1(v2-)-
                stk[ssz-1] = stk[ssz];
                ssz--;
            }
            else stk[++ssz] = value[i][seq[j]-'a'];

            while (ssz>1 && IsNum(stk[ssz-1]) && IsNum(stk[ssz]))
            {
                stk[ssz-1] = GetValue(stk[ssz-1], stk[ssz]);
                ssz--;
            }
        }

        /*if (ssz != 1)
        {
            cout<<"Wrong! ssz!=1\nStack: ";
            for (int j=1; j<=ssz; j++)
            {
                cout<<stk[j]<<" ";
            }
            cout<<"\n";
            return 0;
        }*/
        printf("%c", stk[ssz]);
    }

    printf("\n");
}
