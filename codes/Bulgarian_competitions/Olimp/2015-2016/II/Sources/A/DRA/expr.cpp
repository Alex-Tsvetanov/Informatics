#include<iostream>
#include<cstring>
using namespace std;
char a[1024];
char v[32];
int s[2048],n;
bool cs[2048];
int main()
{
    int i,j=0,k;a[0]='(';
    cin>>(a+1);
    for(i=0;i<strlen(a);++i)
    {
        if(a[i]=='('){++i;s[j]=a[i]-'a';++j;}
        else if(a[i]==')'){s[j]=-1;++j;}
             else{s[j]=a[i]-'a';++j;s[j]=-1;++j;}
    }
    n=j;
    //for(i=0;i<n;++i){cout<<s[i]<<" ";}
    for(i=0;;++i)
    {
        cin>>v;if(v[0]=='2'){cout<<endl;return 0;}
        k=0;for(j=0;j<n;++j){if(s[j]!=-1){cs[k]=v[s[j]]-'0';++k;}else{--k;cs[k-1]=!(cs[k-1]&&cs[k]);}}cout<<cs[0];
    }
}
