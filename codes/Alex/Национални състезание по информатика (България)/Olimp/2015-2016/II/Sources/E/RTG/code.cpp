#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char a1[1000001];
    int b=0,c=0,e=0,g=0;
    cin>>a1;
    b=strlen(a1);
    for(int i=0;i<=b;i++)
    {
        if(e>0)
        {
            if(a1[i]==a1[i+1])e++;
            else
            {
                if(e>9&&e<100)g=2;
                else
                {
                    if(e>99&&e<1000)g=3;
                    else
                    {
                        if(e>999&&e<10000)g=4;
                        else
                        {
                            if(e>9999&&e<100000)g=5;
                            else
                            {
                                if(e>99999&&e<1000000)g=6;
                                else
                                {
                                    if(e==1000000)g=7;
                                    else g=1;
                                }
                            }
                        }
                    }
                }
                c=c+1+g;
            }
          }
            if(a1[i]==a1[i+1])e=1;
            c++;
        }
        cout<<b-c<<endl;
        return 0;
    }