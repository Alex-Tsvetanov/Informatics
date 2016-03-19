
#include<iostream>

using namespace std;

int main()

{
    
    long long n,key=0,key2=0,a[100000];
    long long b[100000],br=0,x;
    cin>>n;
    for(int i=0;i<n;i++)
    
    {
        cin>>a[n];
    }
    for(int i=0;i<n;i++)
    {
        x=a[i];
        
        for(int j=i+1;j<n;j++)
        {
            if(x<a[j]) key=1;
        }
        if(key==0) {b[br]=x;br++;cout<<x<<" ";}
        else {key=0;key2=1;}
    }
  
    cout<<endl;
    return 0;
}
