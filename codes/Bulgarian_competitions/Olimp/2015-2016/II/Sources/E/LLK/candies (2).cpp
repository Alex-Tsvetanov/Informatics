#include<iostream>
using namespace std;
int main()
{
    long long a,b,c,br=0,br2=0,d,f=0;
    cin>>a>>b>>c;
    d=a+b+c;
    while(f<d)
    {
        if(br==0 && a==0){break;}
        if((br==1 || br==3) && b==0){break;}
        if(br==2 && c==0){break;}
        if(br==0){a--;br2++;}
        else if(br==1 || br==3){b--;br2++;}
        else if(br==2 ){c--;br2++;}
        br++;
        if(br==4){br=0;}
        if(br==0 && a==0){break;}
        else if((br==1 || br==3) && b==0){break;}
        else if(br==2 && c==0){break;}
        f++;
    }
    cout<<br2<<endl;
    return 0;
}

