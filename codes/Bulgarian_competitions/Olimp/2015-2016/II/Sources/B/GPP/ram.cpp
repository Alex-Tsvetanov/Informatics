#include<iostream>
using namespace std;

int main()
{
    int n=15;
    int a[n][n];
    int i,f,y=2,l=1;
    int broi=0;
    int N[n],M[n],d;
    for(i=1;i<n;i++)
    {
        for(f=1;f<n;f++)
        {
            a[i][f]=2*i*f + f + i;
        }
    }
  /*  for(i=1;i<n;i++)
    {
        for(f=1;f<n;f++)
        {
            cout<<a[i][f]<<" ";
        }
        cout<<"\n";
    }*/
    int k;
    cin>>k;
    for(i=1;i<k/3;i++)
    {

       // if(i%2!=0)
        {
          //  y++;
            for(f=1;k+y>=a[i][f];f++)
            {

                if(a[i][f]==k+y)
                {
                    M[broi]=f;
                    N[broi]=i;
                    broi++;
                }
            }
            y=y+2;
        }
      //  else
        {
           // y++;
            for(f=1;k+l>=a[f][i];f++)
            {
                //cout<<" f="<<f<<" i="<<i<<" k+i="<<k+y<<" afi="<<a[f][i]<<endl;
                if(a[f][i]==k+l)
                {

                    M[broi]=i;
                    N[broi]=f;
                    broi++;
                }
            }
            l=l+2;
        }
    }
    cout<<broi<<"\n";
    for(i=0;i<broi;i++)
    {
        cout<<N[i]<<" "<<M[i]<<endl;
    }
    return 0;
}
