#include <bits/stdc++.h>
using namespace std;
long long i, brl;
string code, coded;
main()
{
    getline(cin, code, '.');
    for(i=0; i<code.size(); i++)
    {
        if(code[i]==code[i+1])brl++;
        if(code[i]!=code[i+1] && code[i-1]==code[i])
        {
            coded=coded+(char)(brl+'1')+code[i];
            brl=0;
        }
        else if(code[i-1]!=code[i] && code[i]!=code[i+1])coded=coded+code[i];
    }
    cout << code.size()-coded.size() << endl;
}
