#include<iostream>
using namespace std;long A,B,C,flag=0,bonscount=0;
int main()
{
    
    cin>>A>>B>>C;
    while(flag!=1)
    {
        if((A==0) && (B!=0) && (C!=0))
        {
            bonscount=bonscount-(A+1);
            cout<<bonscount<<endl;
            flag=1;
        }
        else 
        {
            A--;
            bonscount++;
        }
        
        if((B==0) && (A!=0) && (C!=0))
        {
            bonscount=bonscount-(B+1);
            cout<<bonscount<<endl;
            flag=1;
        }
        else 
        {
            B--;
            bonscount++;
        }
        
        if((C==0) && (A!=0) && (B!=0))
        {
            bonscount=bonscount-(C+1);
            cout<<bonscount<<endl;
            flag=1;
        }
        else 
        {
            C--;
            bonscount++;
        }
        
        
    }
    return 0;
}
