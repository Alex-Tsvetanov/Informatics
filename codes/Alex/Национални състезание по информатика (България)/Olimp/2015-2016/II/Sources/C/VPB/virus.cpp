#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int st;
long long N;
vector <vector <int > > bx;
bool ys[9];

void ste ()
{
    for (long long i=1; i<N; i=i*2)
    {
        st++;
    }
}

void binary (int b)
{
    int b1=b;
    int tr=pow (2,st-1);
    for (int i=0; i<st; i++)
    {
        if (b1/tr==1)
        {
            b1=b1-tr;
            bx[i].push_back(b+1);
        }
        tr=tr/2;
    }
}

int main ()
{
    cin>>N;
    ste();
    cout<<st<<endl;
    if (N<=500)
    {
        bx.resize(st);
        for (int i=0; i<N; i++)
        {
            binary(i);
        }

        for (int i=0; i<st; i++)
        {
            cout<<bx[i].size();
            for (int j=0; j<bx[i].size(); j++)
            {
                cout<<" "<<bx[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}
