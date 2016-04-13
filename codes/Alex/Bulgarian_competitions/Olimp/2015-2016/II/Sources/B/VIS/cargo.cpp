#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int period[2][1000000];

int main()
{
    int n, m, p;
    cin>>n>>m>>p;

    for (int i = 0; i < m; i++)
    {
        cin>>period[0][i]>>period[1][i];
    }


    for(int i=m-1;i>=0; i--)
    {
        int max = 0;
        int position = 0;
        for(int j=i;j>=0;j--)
        {
            if(max<period[0][j])
            {
                max=period[0][j];
                position = j;
            }
        }

        int temp1 = period[0][i];
        int temp2 = period[1][i];
        period[0][i] = period[0][position];
        period[1][i] = period[1][position];
        period[0][position] = temp1;
        period[1][position] = temp2;
    }

    for(int i = m-2; i>=0;i--)
    {
        for (int j = i; j>=0; j--)
        if (period[1][i] > period[1][i+1] && period[1][i] != period[1][i+1])
        {
            swap(period[1][i],period[1][i+1]);
        }

    }

    bool possible = true;
    int transportPerDay = p/2;
    int day =period[0][0];
    for (int i=0; i< m; i++)
    {
        if (day < period[0][i])
        {
            day = period[0][i];
        }

        if(day>period[1][i])
        {
            cout<<"IMPOSSIBLE";
            possible = false;
            return 0;
        }

        if(transportPerDay==0)
        {
            transportPerDay = p/2;
            day++;
        }
        transportPerDay--;
    }

    bool mixed = false;
    transportPerDay = p/2;
    day =period[0][0];
    for (int i=0; i< m; i++)
    {
        if (day%7==0)
        {
            day++;
            transportPerDay = p/2;
        }

        if(day%7==6);
        {
            day+=2;
            transportPerDay = p/2;
        }

        if (day < period[0][i])
        {
            day = period[0][i];
        }

        if(day>period[1][i])
        {
            mixed = true;
            break;
        }

        transportPerDay--;

        if(transportPerDay==0)
        {
            transportPerDay = p/2;
            day++;
        }
    }

    if (possible && !mixed)
    {
        cout<<"OK";
    }
    if(possible && mixed)
    {
        cout<<"MIXED";
    }
    cout<<endl;
    return 0;
}
