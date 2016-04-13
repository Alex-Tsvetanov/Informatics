#include <iostream>
using namespace std;
int mas[1000000];
int main ()
{
int N, M, P, S, E, mixed=0, sub=0, ned=0, imp=0, zaqvki=1;
cin>>N>>M>>P;
int r=P/2;
int t=M;
for (int off=1; off<=N; off++) mas[off]=r;
while (t)
{
    cin>>S>>E;
    if (imp!=1)
    {
       if (S>E)
    {
        int s=E;
        E=S;
        S=s;
    }
    while (S<=E)
    {
        if ((S+1)%7==0) sub=S;
        else if (S%7==0) sub=S;
        else if (mas[S]>0)
        {
            mas[S]--;
            zaqvki=0;
            break;
        }
        S++;
    }
    if (zaqvki==1)
    {
        if (sub!=0 && mas[sub]!=0)
        {
            mas[sub]--;
            zaqvki=0;
            mixed=1;
        }
        else if(ned!=0 && mas[ned]!=0)
        {
            mas[ned]--;
            zaqvki=0;
            mixed=1;
        }
    }
       if (zaqvki==1)
    {
        imp=1;
    }
    }
    zaqvki=1;
    sub=0;
    ned=0;
    t--;

}
if (imp!=0) cout<<"IMPOSSIBLE"<<endl;
else if (mixed!=0) cout<<"MIXED"<<endl;
else cout<<"OK"<<endl;
return 0;
}
