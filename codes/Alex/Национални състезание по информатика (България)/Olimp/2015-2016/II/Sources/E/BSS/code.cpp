#include<iostream>
#include<string>
int n,br=0,i;
using namespace std;
int main ()
{
    string t;
    getline(cin,t,'.');
    n=t.size();
    for(i=0; i<=n; i++)
    {
        if(t[i]==t[i-1])
        {
            br++;
            continue;
        }
        br++;
        if(br>1 && br<11)n=n-br+2;
        else if(br>10 && br<101)n=n-br+3;
        else if(br>100 && br<1001)n=n-br+4;
        else if(br>1000 && br<10001)n=n-br+5;
        else if(br>10000 && br<100001)n=n-br+6;
        else if(br>100000 && br<1000001)n=n-br+7;
        br=0;
    }
    cout<<t.size()-n<<endl;
    return 0;
}
