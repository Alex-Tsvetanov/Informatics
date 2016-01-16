#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    string urav;
    long long a=0, b=0, x=0;
    bool before=true, firstCon=false;
    cin>>urav;
    for(int i=0; i<urav.length(); i++)
    {


        if(urav[i]=='=')
        {
            before=false;
            firstCon=false;
        }
        else if(before==true)
        {
            if(firstCon==true)
            {
                if(urav[i]>='1' and urav[i]<='9')
                {
                    //cout<<endl<<a<<endl;
                    a=a*10;
                    a=a+(urav[i]-48);
                }
                else if(urav[i]=='0')
                {
                    a=a*10;
                }
            }
            if(firstCon==false)
            {
                if(urav[i]>='1' and urav[i]<='9')
                {
                    a=urav[i]-48;
                    firstCon=true;
                }
            }

        }
        else if(before==false)
        {
            if(firstCon==true)
            {
                if(urav[i]>='1' and urav[i]<='9')
                {
                    //cout<<endl<<a<<endl;
                    b=b*10;
                    b=b+(urav[i]-48);
                }
                else if(urav[i]=='0')
                {
                    b=b*10;
                }
            }
            if(firstCon==false)
            {
                if(urav[i]>='1' and urav[i]<='9')
                {
                    b=urav[i]-48;
                    firstCon=true;
                }
            }
        }

    }
    /*urav[1]=123;
    cout<<urav[1]<<endl;*/
    //cout<<a<<" "<<b<<endl;
    x=b-a;
    cout<<x;
    return 0;
}

/**
    12+X=30
    X+12=3
    A+X=B
**/
