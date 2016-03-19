#include <iostream>

using namespace std;
long long n,i,s[1000000],max1;
int main()
{
   cin>>n;
   for(i=0;i<n;i++)
        cin>>s[i];

   for(i=0;i<n;i++)
     if(s[i]>=s[i+1]){max1=s[i];
    cout<<max1<<" ";}

        return 0;
}
