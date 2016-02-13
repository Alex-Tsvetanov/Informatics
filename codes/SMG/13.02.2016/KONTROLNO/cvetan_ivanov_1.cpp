#include<iostream>
using namespace std;
int n,dots[100][2],br,br1,k;
bool c=0;
int z(int x)
{
    if(x>0)
        return 1;
    if(x<0)
        return -1;
    if(x==0)
        return 0;
}
int main()
{
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>dots[i][0]>>dots[i][1];
    for(int i=0; i<n-2; i++)
    {
        for(int i1=i+1; i1<n-1; i1++)
        {
            for(int i2=i1+1; i2<n; i2++)
            {
                for(int h=0; h<n; h++)
                {
                    if(h!=i && h!=i1 && h!=i2)
                    {
                        if(z((dots[i][0]-dots[i1][0])*(dots[h][1]-dots[i1][1])-(dots[h][0]-dots[i1][0])*(dots[i][1]-dots[i1][1]))==z((dots[i][0]-dots[i2][0])*(dots[h][1]-dots[i2][1])-(dots[h][0]-dots[i2][0])*(dots[i][1]-dots[i2][1])) && z((dots[i][0]-dots[i1][0])*(dots[h][1]-dots[i1][1])-(dots[h][0]-dots[i1][0])*(dots[i][1]-dots[i1][1]))==z((dots[i2][0]-dots[i1][0])*(dots[h][1]-dots[i1][1])-(dots[h][0]-dots[i1][0])*(dots[i2][1]-dots[i1][1])))
                            br++;
                        br1++;
                        if(br1==k)
                        {
                            c=1;
                            break;
                        }
                    }
                }
                if(c)break;
            }
            if(c)break;
        }
        if(c)break;
    }
    cout<<br;
    return 0;
}
/**
7 4
1 1
2 1
3 3
4 0
0 6
3 2
1 3

6
*/
