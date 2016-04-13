#include <iostream>
using namespace std;
int main()
{
    long long a,b,c,d=1,br=0;
    cin>>a>>b>>c;
    do
    {
        if(a>0)
        {
            a--;
            br++;
            if(b>0)
            {
                b--;
                br++;
                if(c>0)
                {
                    c--;
                    br++;
                    if(b>0)
                    {
                        b--;
                        br++;
                    }
                    else break;
                }
                else break;
            }
            else break;
        }
        else break;
    }
    while (d==1);
    cout<<br<<endl;


    return 0;
}
