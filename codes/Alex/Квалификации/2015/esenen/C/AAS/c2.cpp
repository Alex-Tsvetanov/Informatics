#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, buhta, br;
    long long int chislo;
    int m=0;
    int d1, d2, d3;
    cin >> n >> d1 >> d2 >> d3;
    int n2=n;
    bool res;
    vector<int>a (n2+1, 0);
    vector<int>b (pow(10, n2)+1, 0);
    for(long long int blq=pow(10, n2-1); blq<pow(10, n2)-1; blq++)
    {
        chislo=blq;
        for(n=n2; chislo!=0; n--)
        {
            a.at(n) = chislo%10;
            chislo/=10;
        }
        res=1;
        if(res==1)
        {
            for(int j=1; j<n2; j++)
            {
                if(a.at(j)==0)
                {
                    res=0;
                    continue;
                }
                short int maikati = 10*a.at(j) + a.at(j+1);
                if(res==1)
                {
                    if((maikati%d1==0 || maikati%d2==0 || maikati%d3==0))
                    {
                        res = 1;
                    }
                    else res=0;
                }
            }
        }
        if(res==1) m++;
    }
    cout << m << endl;
    return 0;
}
