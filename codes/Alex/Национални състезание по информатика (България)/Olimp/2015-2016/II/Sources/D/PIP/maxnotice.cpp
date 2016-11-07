#include<iostream>
using namespace std;
int d[16][16];
int main ()
{
    int l,h,n,a[16][4];
    cin>>l>>h>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
    }
    for(int i=0; i<n; i++)
    {
        int h=a[i][0],g=a[i][1],j=a[i][0]+a[i][2]-1,f=a[i][1]+a[i][3]-1;
        for(int i1=h; i1<=j; i1++)
        {
            for(int i2=g; i2<=f; i2++)
            {
                d[i1][i2]=1;
            }
        }
    }
    int maxpro=0,r=0,t=0,p,o;
    for(int y=0;y<=l;y++){
        for(int x=0;x<=h;x++){
            int e=y,q=x;
            while(e<l and d[e][q]==0){
                e++;r++;
            }
            while(q<h and d[q][e]==0){
                q++;t++;
            }
            if(t*q>maxpro){
                maxpro=t*q;
                p=y;o=x;
            }
            r=0;t=0;
        }

    }
    cout<<maxpro<<endl;
    return 0;
}
