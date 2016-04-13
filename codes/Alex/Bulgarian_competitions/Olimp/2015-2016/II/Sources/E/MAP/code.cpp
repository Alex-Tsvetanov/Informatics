#include<iostream>
#include<cctype>
using namespace std;
int main ()
{
int n,br=1;
char x[1000];
int arr[1000];
cin>>x;
while(x[br]!='.')
{
if(x[br]==x[br+1])
{
 arr[br]++;
}
br++;

}
cout<<arr[0];
return 0;
}
