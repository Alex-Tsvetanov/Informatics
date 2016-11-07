#include <iostream>

using namespace std;

int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   int k = 0;
   int ch = 1;
   a += c;
   while(b > 0)
   {
       a -= 1;
       b -= 1;
       k += 2;
   }
   cout<<k + 1<<endl;
    return 0;
}