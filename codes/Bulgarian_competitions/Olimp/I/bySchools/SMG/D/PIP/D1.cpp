#include<iostream>
using namespace std;
int main ()
{
    char a='2',z;
    int br[27],b,g=0,c=0,j=0;
    for(int d=0; d<27; d++)
    {
        br[d]=0;
    }
    while(a!='#')
    {
        cin>>a;
        if(a>=65 and a<=90)
        {
            b=a-64;
        }
        if(a>=97 and a<=122)
        {
            b=a-96;
        }
        if(b<=27 and b>=1)
        {
            br[b]=br[b]+1;
        }
    }
    //Naj-golqmo
    for(int f=1; f<=26; f++)
    {
        if(br[f]>=g)
        {
            g=br[f];
        }
    }
    for(int f=26; f>1 and c==0; f--)
    {
        if(br[f]==g)
        {
            br[f]--;
            g--;
            c++;
        }
    }
    for(int q=0; q<6; q++)
    {
        for(int f=1; f<=26 and j==0; f++)
        {
            if(br[f]==g and q<6)
            {
                z=f+64;
                cout<<z;
                q++;
                br[f]=0;
                j++;
            }
            for(int f=1; f<=26; f++)
                {
                    if(br[f]>=g)
                    {
                        g=br[f];
                    }
                }
        }
        g--;
        j=0;
    }
    return 0;
}
