#include<iostream>
using namespace std;
int main()
{
    int cp1, cp2, cp3, bon=0;
    cin>>cp1>>cp2>>cp3;
    do
    {
        cp1=cp1-1;
        cp2=cp2-1;
        cp3=cp3-2;
        bon=cp1+cp2+cp3+6;
    }
    while(cp2!=1);
    cout<<"May e izqla"<<" "<<bon<<endl;
    return 0;
}