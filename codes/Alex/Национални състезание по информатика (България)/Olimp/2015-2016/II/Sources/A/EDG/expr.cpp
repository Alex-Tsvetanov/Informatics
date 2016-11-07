#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
int st[1024];
string s;
map<char,int>m1;
map<int,bool>m;
int bam(int l,int mb){
    string s1;
    int da;
    int ans;
    int i=l;
    if(mb==1){
        cout<<1<<endl;
        while(s[i]!=')'){
            s1+=s[i];
        }
        for(i=0;i<s1.size();i++){
            if(s1[i]=='('){
                    da=bam(l+i,1);
                    while(s1[i]!=')')i++;
                    i++;
            }
            else da=m[m1[s[i]]];
            if(ans==1&&da==1)ans=0;
            else ans=1;
        }
        return ans;
    }
    for(i=0;i<s.size();i++){
        if(s1[i]=='('){
                    da=bam(l+i,1);
                    while(s1[i]!=')')i++;
                    i++;
            }
        else da=m[m1[s[i]]];
        if(ans==1&&da==1)ans=0;
            else ans=1;
    }
        return ans;
}
int main(){
    int cnt=0;
    int i,r;
    cin>>s;int n=s.size();
    for(i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z')
            if(!m1[s[i]]){
                m1[s[i]]=cnt;
                cnt++;
            }
    }
    int ans;
    char c;
    bool boo;
    for(i=0;i<cnt;i++){
            cin>>boo;
            c-='0';
            m[i]=c;
    }
    cout<<bam(0,0);
    while(1){
        for(i=1;i<cnt;i++){
            cin>>c;
            c-='0';
            if(c==2)return 0;
            m[i]=c;
        }
        cout<<bam(0,0);
    }
    return 0;
}
/**
a(a)(ab(ca)bb)c
**/
