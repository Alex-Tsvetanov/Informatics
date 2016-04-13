#include<iostream>
#include<string.h>
using namespace std;
int Check(char A[100])
{

    int i, length;
    int flag = 1;
    length = strlen(A);

    for(i=0;i < length ;i++){
        if(A[i] != A[length-i-1]){
            flag = 0;
            break;
	   }
	}
    return flag;
}

void Move(char A[100],char B[100],int i)
{
    for(int p=0;p<i;p++)
    {
        A[p]=B[p];
    }
}
void Push(char A[100],int br,int spc)
{
    char B[100];
    int a=0;
    for(int i=br-1;i>=0;i--)
    {
        a++;
        Move(A,B,i);
        if(Check(B)==1)
        {
        spc++;
        i=br-a;
        }


    }
}
int main()
{
    char A[100];
    char B[100];
    cin>>A;
    int spc=0;
    int br=strlen(A);
    if(Check (A)==1)cout<<spc;
    else Push(A,br,spc);
    cout<<spc;
    return 0;
}
