#include <iostream>
#include <cmath>
#include <vector>
//#include <cstdio>
using namespace std;

int triugalnici(int a, int b, int c)
{
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

// struct strani{
//     double a,b,c;
// };


int main()
{
   // cout<<"Here"<<endl;
    int m;
    cin>>m;
    vector <int>lica[100];
    // vector <strani> stranii[10000];
    int a[100][100],br=0,b[100][100];
    for(int i=0; m!=0; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[br][j]>>b[br][j];
        }

        if(m==3)
        {
            lica[br].push_back(triugalnici(sqrt((a[br][0]-a[br][1])*(a[br][0]-a[br][1])+(b[br][0]-a[br][1])*(a[br][0]-a[br][1])),sqrt((a[br][1]-a[br][2])*(a[br][1]-a[br][2])+(b[br][1]-a[br][2])*(a[br][1]-a[br][2])),sqrt((a[br][0]-a[br][2])*(a[br][0]-a[br][2])+(b[br][0]-a[br][2])*(a[br][0]-a[br][2]))));
        }
        if(m%2==0&&m>3)
        {
            for(int j=0; i<m/2-1; i++)
            {
                lica[br].push_back(triugalnici(sqrt((a[br][0+j]-a[br][1+j])*(a[br][0+j]-a[br][1+j])+(b[br][0+j]-a[br][1+j])*(a[br][0+j]-a[br][1+j])),sqrt((a[br][1+j]-a[br][2+j])*(a[br][1+j]-a[br][2+j])+(b[br][1+j]-a[br][2+j])*(a[br][1+j]-a[br][2+j])),sqrt((a[br][0+j]-a[br][2+j])*(a[br][0+j]-a[br][2+j])+(b[br][0+j]-a[br][2+j])*(a[br][0+j]-a[br][2+j]))));
            }
        }
        if(m%2!=0&&m>3)
        {
            for(int j=0; i<m/2; i++)
            {
                lica[br].push_back(triugalnici(sqrt((a[br][0+j]-a[br][1+j])*(a[br][0+j]-a[br][1+j])+(b[br][0+j]-a[br][1+j])*(a[br][0+j]-a[br][1+j])),sqrt((a[br][1+j]-a[br][2+j])*(a[br][1+j]-a[br][2+j])+(b[br][1+j]-a[br][2+j])*(a[br][1+j]-a[br][2+j])),sqrt((a[br][0+j]-a[br][2+j])*(a[br][0+j]-a[br][2+j])+(b[br][0+j]-a[br][2+j])*(a[br][0+j]-a[br][2+j]))));
            }
        }

        cin>>m;
        br++;

    }
    for(int i=0; i<10000; i++)
    {
        double summ=0;
        if(!lica[i].empty())
        {
            if(lica[i].size()>1)
            {
                for(int j=0; j<lica[i].size(); j++)
                {
                    summ+=lica[i][j];
                }
                cout<<summ;
            }
            else cout<<lica[i][0];
        }
        else break;

    }




    return 0;
}
