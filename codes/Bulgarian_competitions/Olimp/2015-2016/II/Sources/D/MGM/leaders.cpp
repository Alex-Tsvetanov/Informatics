#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ch[n];
    int lead[n];
    for(int a=0;a<n;a++)
    {
        cin>>ch[a];
    }
    for(int a=0;a<n;a++)
    {
        lead[a]=0;
    }
    for (int a=0;a<n;a++)
    {
        for(int b=a+1;b<n;b++)
        {
            if(ch[a]<ch[b])
            {
                break;
            }
            else if(b == n-1)
            {
                lead[a] = ch[a];
                cout<<lead[a]<<" ";
            }
        }
    }
    cout<<ch[n-1];
}
