#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string uravnenie;
    cin>>uravnenie;
    int a=0;
    if(uravnenie[0]!='X')
    {
        for(int i=0; uravnenie[i]!='+'; i++)
        {
            if(uravnenie.find('+')-i==1)
            {
                a+=uravnenie[i]-'0';
            }
            if(uravnenie.find('+')-i==2)
            {
                a+=(uravnenie[i]-'0')*10;
            }
            if(uravnenie.find('+')-i==3)
            {
                a+=(uravnenie[i]-'0')*10*10;
            }
            if(uravnenie.find('+')-i==4)
            {
                a+=(uravnenie[i]-'0')*10*10*10;
            }
        }
    }
    else
    {
        for(int i=2; uravnenie[i]!='='; i++)
        {
            if(uravnenie.find('=')-i==1)
            {
                a+=uravnenie[i]-'0';
            }
            if(uravnenie.find('=')-i==2)
            {
                a+=(uravnenie[i]-'0')*10;
            }
            if(uravnenie.find('=')-i==3)
            {
                a+=(uravnenie[i]-'0')*10*10;
            }
            if(uravnenie.find('=')-i==4)
            {
                a+=(uravnenie[i]-'0')*10*10*10;
            }
        }
    }

    int b=0;
    for(int i=uravnenie.find('=')+1; i<uravnenie.size(); i++)
    {
        if(uravnenie.size()-i==1)
        {
            b+=uravnenie[i]-'0';
        }
        if(uravnenie.size()-i==2)
        {
            b+=(uravnenie[i]-'0')*10;
        }
        if(uravnenie.size()-i==3)
        {
            b+=(uravnenie[i]-'0')*10*10;
        }
        if(uravnenie.size()-i==4)
        {
            b+=(uravnenie[i]-'0')*10*10*10;
        }
    }
    int x=b-a;
    cout<<x;
}
