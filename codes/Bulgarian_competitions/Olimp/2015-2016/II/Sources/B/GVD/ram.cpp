#include<iostream>
using namespace std;
int k=1;



int ram(int M,int N)
{
if(M==0)return k;
if(N==0)return k;
 k++;
 k++;
ram(M-1,N-1);
}


int main()
{
	int br=0,K,i,j;
cin>>K;


for(i=1;i<=100;i++)
for(j=1;j<=100;j++)
{
	if(i==j)
if((((i+1)*i+(i+1)*i)-ram(i,j-1))==K)	
	{
	cout<<i<<";"<<j<<endl;
	br++;
    }
    
    k=1;
    
	if(i!=j)
if((((i+1)*i+(j+1)*j)-ram(i,j-1))==K)	
	{
	cout<<i<<";"<<j<<endl;
	br++;
    }
    
    k=1;
    
	if(i==1)
if(((j*3+1)-ram(i,j-1))==K)	
	{
	cout<<i<<";"<<j<<endl;
	br++;
    }
    k=1;
    
	if(j==1)
if(((i*3+1)-ram(i,j-1))==K)	
	{
	cout<<i<<";"<<j<<endl;
	br++;
    }
    
    
    
    
    k=1;
}

cout<<endl<<br;

	return 0;
}	
