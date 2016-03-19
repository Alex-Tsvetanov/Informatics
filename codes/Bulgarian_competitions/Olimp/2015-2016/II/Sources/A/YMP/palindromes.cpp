#include <iostream>
#include<string>
using namespace std;
string s;
void read()
{
    cin>>s;
}
int main()
{
    read();
    int i,j,sz,l,r,mid,br=0,adr=0,k;
    sz=s.size();
    for(i=0;i<sz;i++)
    {
        for(j=i+1;j<sz;j++)
        {
            k=0;
            l=i;r=j;
            if((l+r)%2==0)
            {
                mid=(l+r)/2;
                while(l<mid&&mid<r)
                {
                    if(s[l]!=s[r]){k=1;break;}
                    l++;r--;
                }

            }
            else
            {
                while(l<r)
                {
                    if(s[l]!=s[r]){k=1;break;}
                    l++;r--;
                }
            }
            if(k==0)
            {
                if(j!=sz-1)br++;
                if(i==0&&j==sz-1)br=0;
                i=j;
                break;
            }
            if(k==1&&j==sz-1)
            {
                br++;break;
            }
        }
    }
    cout<<br<<endl;
    return 0;
}
