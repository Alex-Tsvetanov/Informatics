#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{

int A,B,C,i,f,j,k;
cin>>A>>B>>C;
for (i=1;i<=A;i--)
for (j=1;j<=B;j--)
for (k=1;k<=C;k--)
if (i<(i+1)||j<(j+1)||k<(k+1)) f++;
if (i==0||j==0||k==0)
cout<<f<<endl;
return 0;
}
