#include<iostream>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int N[n];
 for(int br=0;br<n;br++){cin>>N[br];}
 bool fx=false;
 for(int br=0;br<n;br++)
    {
        bool x=true;
        for(int brr=br;brr<n;brr++)
        {
            if(N[br]<N[brr])
            {
                x=false;
                break;
            }
        }
        if((fx)&&(x))cout<<" ";
        if(x)
        {
            cout<<N[br];
            fx=true;
        }
    }
    cout<<endl;
    return 0;
}
