#include <iostream>
using namespace std;

int main()
{int A,B,C;
cin>>A>>B>>C;
int br=0;
for(int i=1;i>0;i--)
    {
    A=A-1;if(A>=0)br++;
    B=B-1;if(B>=0)br+=1;
    C=C-1;if(C>=0)br=br+1;
    }
while(A>0&&B>0&&C>0)
{
        B=B-1;if(B>=0)br++;
        A=A-1;if(A>=0)br+=1;
        B=B-1;if(B>=0)br=br+1;
        if(B>0)C=C-1;if(C>=0)br++;
}
cout<<br<<endl;
 return 0;
}