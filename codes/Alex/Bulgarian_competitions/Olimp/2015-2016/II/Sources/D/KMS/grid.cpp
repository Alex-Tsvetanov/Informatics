#include<iostream>
using namespace std;
long long M, N, num[40000], sum, target, Krisy=1;
bool progres=false;

void rekursia(int i)
{
    target=num[i];
    if((num[i+1]==0 || i==0) && num[i+1]!=-1){
        num[i+1]=Krisy;
        progres=true;
    }
    if((num[i-1]==0 || i==0) && i-1>0){
        num[i-1]=Krisy;
        progres=true;
    }
    if((num[i+M-1]==0 || i==0) && i+M-1>0){
        num[i+M-1]=Krisy;
        progres=true;
    }
    if((num[i-M]==0 || i==0)){
        num[i-M]=Krisy;
        progres=true;
    }
    if(progres==true){
        progres=false;
        rekursia(i+1);
    }
}

int main()
{
    cin>>M>>N;
    sum=M*N;
    for(int i=0; i<sum; i++)
    {
        cin>>num[i];
        if(num[i]==1) num[i]=-1;
    }
    num[0]=1;
    for(int i=0; i<sum; i++)
    {
        if(num[i]==0){
            Krisy++;
            rekursia(i);
        }
    }


    cout<<Krisy;

    cout<<endl;
    return 0;
}
/**
2 4 0 1 1 0 0 0 1 1

3 3
0 1 0
0 1 0
1 0 1

5 6
0 0 0 0 0
1 1 1 1 0
1 1 0 1 1
0 1 0 0 0
1 0 1 0 0
1 1 0 0 0

7 8
0 0 0 1 0 0 1
1 1 1 0 0 1 0
0 0 0 0 1 0 0
0 1 0 1 1 1 0
0 0 1 0 0 0 1
1 1 0 1 0 1 0
0 0 0 0 1 0 0
0 0 0 1 0 0 0
/*/
