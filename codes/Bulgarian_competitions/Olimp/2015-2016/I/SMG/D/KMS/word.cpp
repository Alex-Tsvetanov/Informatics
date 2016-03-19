#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
long long votes[10000][10000], poreden=0, nis=0;

int main(){
char Kali[10000], next;
for(int i=0;i<10000;i++)
{
cin>>Kali[i];
if(Kali[i]=='#') break;
}
sort(Kali, Kali + strlen(Kali));
for(int i=0;i<strlen(Kali);i++){
    if(Kali[i]==Kali[i+1] and Kali[i]!=next){
        nis++;
        votes[poreden][i]=nis;
    }
    if(Kali[i]!=Kali[i+1])
    {
        votes[poreden][i-nis]=nis+1;
        nis=0;
    }
}
for(int i=0;i<poreden;i++){
    //cout<<Kali[votes[i][i]];
}
cout<<"A";
return 0;
}
