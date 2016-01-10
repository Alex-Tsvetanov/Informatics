#include<iostream>
using namespace std;
int rek(int a)
{
    if(a==1) return 3;
        return a+rek(a-1);
}
int main()
{
    int a, br, sb=0, k;
    cin>>a;
    if(a%2==1) a--;
    while(a>1)
    {
        k=2;
        br=0;
        for(int i=2; i<=a; i*=2)
        {
            br++;
            k*=2;
        }
        sb+=rek(br)+1;
        a-=k;
    }
    cout<<sb;
}
