#include<iostream>
using namespace std;
int main()
{  long long int A,B,C,i;
   cin>>A>>B>>C;
   for (i=1;i>1;i++)
   {
    do
    {
        A-1;i++; B-1;i++; C-1;i++;
        B-1;i++; A-1;i++;
        B-1;i++; C-1;i++;

    }
    while (A>0&&B>0&&C>0);
   }
    if (A-1==0);
    if (B-1==0);
    if (C-1==0);
    cout<<i<<endl;
    return 0;
}


