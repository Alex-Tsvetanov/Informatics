#include<iostream>
using namespace std;
long long virus1(long long a)
{
    long long result=1,step=3,counter=1;
    do{
        result+=step;
        step++;
        counter++;
    }while(result<a);
    return counter;
}
int main()
{
    long long n;
    cin>>n;
    int Arr[virus1(n)][n+1];
    for(int i=0;i<virus1(n);i++)
    {
        Arr[i][n]=n;cout<<i<<" "<<n<<endl;
    }
    cout<<virus1(n)<<endl;
    return 0;
}
