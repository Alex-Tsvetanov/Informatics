#include<iostream>
#include<cmath>
using namespace std;
int main()
{

    int chosen_number,numbers=0;
    int found[numbers][2];
    cin>>chosen_number;
    int c;

    for(int b=2; b<27; b=b+1)
    {
        for(int a=2; a<sqrt(chosen_number)+1; a=a+1)
        {
            c = pow(a,b)+0.5;
            if(chosen_number==c)
            {
                found[numbers][0] = a;
                found[numbers][1] = b;
                numbers = numbers + 1;

            }

        }

    }

    cout<<numbers<<endl;
    for(int i=0; i<numbers; i++)
    {
        cout<<found[i][0]<<" "<<found[i][1]<<endl;
    }







    return 0;
}
