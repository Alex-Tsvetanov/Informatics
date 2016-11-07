#include <iostream>

using namespace std;

int main( ){

long long n;

cin>>n;

long long br=0,i=1,k=2;

while(k<n)
{

 if( ( (n-k)-6)%2==0)br++;

 i+=2;

 k+=i;

}

cout<<br<<endl;

return 0;
}
