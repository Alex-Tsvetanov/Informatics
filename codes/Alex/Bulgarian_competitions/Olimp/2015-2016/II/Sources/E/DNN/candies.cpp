#include <iostream>
using namespace std;

int main()
{
    int a,b,c,br=0;
    cin>>a>>b>>c;
    for (int i=0;i<a+b+c;i++)
    {
        if (i%2==0)
        {
            if(a>0)
            {
                a--;
                br++;
            }
            else break;
            if (b>0)
            {
                b--;
                br++;
            } 
            else break;
            if (c>0)
            {
                c--;
                br++;
            }
            else break;
        }
        else 
        {
            if (c>0)
            {
                c--;
                br++;
            }
            else break;
            if (b>0)
            {
                b--;
                br++;
            } 
            else break;
            if(a>0)
            {
                a--;
                br++;
            }
            else break;
        }
    }
    cout<<br<<endl;
    return 0;
}

