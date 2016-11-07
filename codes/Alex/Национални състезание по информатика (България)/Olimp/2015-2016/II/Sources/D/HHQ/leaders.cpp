#include<iostream>
using namespace std;
int a[1000002],b[1000001];
int n;
int main()
{
 cin>>n;
 int d;
 for(int i=0; i<n; i++)
  {
   cin>>d;
   a[i]=d;
  }
 int br=0,k=0;
 for(int i=0; i<n; i++)
  {
   for(int j=i+1; j<n; j++)
    {if(a[i]>=a[j]) br++;
     cout<<a[i]<<" "<<a[j]<<" "<<br<<endl;
    }

   if(br==n-1-i)
    {
     b[k]=a[i];
     k++;
    }
   br=0;
  }
 for(int i=0; i<k; i++)
  cout<<b[i]<<" ";
 cout<<endl;
 return 0;
}
