#include<iostream>
using namespace std;
int main()
{
    long long a,b,c,br=0,i;
    cin>>a>>b>>c;
    for(i=1;;i++)
    {
        if(i>3)i=1;
        if(i==1)
        {if(a!=0){a--;br++;}
        else break;}
        else if(i==2)
        {
            if(b>2){br=br+2;b=b-2;}
            else if(b!=0){if(b==1){br=br+2;break;}else if(b==2){br=br+3;break;}}
            else if(b==0)break;
            
        }
        else if(i==3)
        {
        if(c!=0){c--;br++;}
        else break;}
    }
    cout<<br<<endl;
    return 0;
}
