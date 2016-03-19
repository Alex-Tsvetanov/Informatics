#include <iostream>
using namespace std;

int main()
{int N;
cin>>N;
int A,B,br=0,A1,B1,brA1,brB1,A2,B2,A3,B3,A4,B4,A5,B5,brA12,brA13,brA14,brA15,brB12,brB13,brB14,brB15;
cin>>A>>B;
A1=A;
B1=B;
if(B>1)brA1=B/2+B%2;
if(A>1)brB1=A-1;
if(2*A+2*B+brA1*A1+brB1*B1==N)br++;
while(2*A+2*B+brA1*A1+brB1*B1!=N)
{
    A2=A/2;B2=B/2;A1=A2;B1=B2;brA12=B2/2+B2%2;brB12=A2-1;
    if(2*A2/2+2*B2/2+brA12*A1+brB12*B1==N)br+=1;
}
while(2*A+2*B+brA1*A1+brB1*B1!=N)
{
    A3=A*2;B3=B*2;A1=A3;B1=B3;brA13=B3/2+B3%2;brB13=A3-1;
    if(2*A3*2+2*B3*2+brA13*A1+brB13*B1==N)br=br+1;
}
while(2*A+2*B+brA1*A1+brB1*B1!=N)
{
    int c;
    cin>>c;
    A4=A+c;B4=B+c;A1=A4;B1=B4;brA14=B4/2+B4%2;brB14=A4-1;
    if(2*A4+2*B4+brA14*A1+brB14*B1==N)br+=br;
}
while(2*A+2*B+brA1*A1+brB1*B1!=N)
{
    int b;
    cin>>b;
    A5=A-b;B5=B-b;A1=A5;B1=B5;brA15=B5/2+B5%2;brB15=A5-1;
    if(2*A5+2*B5+brA15*A1+brB15*B1==N)br++;
}
if(br==0)cout<<"0";
else cout<<br;
 return 0;
}