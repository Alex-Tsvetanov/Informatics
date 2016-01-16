#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    bool haveAnsw=false;
    long long a;
    cin>>a;
    long long copye=a;
    for(int i=sqrt(a);i>=2;i--){
        int how=0;
        while(copye%i==0){
            copye=copye/i;
            how++;
        }
        if(how>=1 and copye==1){
          haveAnsw=true;
          cout<<i<<" "<<how<<endl;
        }
        copye=a;
    }
    if(!haveAnsw){
      cout<<0<<endl;
    }
    return 0;
}
