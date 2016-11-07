#include<iostream>
using namespace std;
int k,b,br=1,a[99999999],j=0;
void Resh()
{
    int i;
    cin>>k;
    for(i=1;i<k;i++)
    {
        b=(k-1-i)/(2*i-1);
        if(i>b&&(k-1-i)%(2*i-1)==0&&b!=0)
        {
            j++;
            a[br]=i;
            a[br+1]=b;
            br+=2;
        }
         b=(k+i)/(2*i+1);
        if(i<b&&(k+i)%(2*i+1)==0&&b!=0)
        {
             j++;
            a[br]=i;
            a[br+1]=b;
            br+=2;
        }
    }
}
int main()
{
int i;
Resh();
cout<<j<<endl;
for(i=1;i<=j*2;i+=2)
{
    cout<<a[i]<<" "<<a[i+1]<<endl;;
}
return 0;
}
