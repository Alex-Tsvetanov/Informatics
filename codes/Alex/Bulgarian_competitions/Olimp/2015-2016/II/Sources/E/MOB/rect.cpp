#include<iostream>
using namespace std;
int main()
{long long n,b=0,br=0;
cin>>n;
for(int i=1;i*i<n/2;i++)
{while(1)
{b++;
if((((b-1)*i)+((i-1)*b)+(b+i)*2)>=n){break;}
}
if((((b-1)*i)+((i-1)*b)+(b+i)*2)==n)br++;
b=0;


}
cout<<br<<endl;





return 0;
}
