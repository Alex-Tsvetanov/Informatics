#include <iostream>

using namespace std;

int main()
{
    int m,n;
    int b=0;
    int chb=1;
    cin>>m>>n;
    int tab[m*n];
    for (int c=0;c<m*n;c++)
    {
        cin>>tab[c];
        if (tab[c]==0)
        {
            b++;
        }
    }
    int beli[b];
    int ch[b];
    ch[0]=chb;
    int d=0;
    for (int c=0;c<m*n;c++)
    {
        if(tab[c]==0)
        {
            beli[d]=c;
            d++;
        }
    }
    int ads=0;
    for (int c=0;c<d;c++)
    {
      for (int h=0;h<d;h++)
      {
       if(beli[c]-beli[h]==1||beli[c]-(beli[h]%2+1)==1)
       {
         ch[h]=ch[c];
         ads++;
       }
      }
    if(ads==0)
    {
        chb++;
    }
    ads=0;
    }
    cout<<chb;
}
