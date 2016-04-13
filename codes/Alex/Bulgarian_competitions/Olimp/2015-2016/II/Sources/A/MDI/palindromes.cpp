#include<iostream>
using namespace std;

string in;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int br = 0;

    cin>>in;
    int l = in.size();

    for(int i=0; i<=l/2; i++)
    {
        if(in[i]!=in[l-i-1]) br++;
    }

    if(br) br--;
    cout<<br<<endl;
}
