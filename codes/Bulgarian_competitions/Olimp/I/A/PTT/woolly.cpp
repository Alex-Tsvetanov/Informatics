#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct Pair{
string s1;
string s2;
Pair(string a,string b){s1=a;s2=b;}
char* calc(){
 for(int i=0;i<((s1.size())/2);i++){
    char a=s1[i];
    s1[i]=s1[s1.size()-(i+1)];
    s1[s1.size()-(i+1)]=a;
 }
 for(int i=0;i<((s2.size())/2);i++){
    char a=s2[i];
    s2[i]=s2[s2.size()-(i+1)];
    s2[s2.size()-(i+1)]=a;
 }
 int n;
 if(s1.size()<s2.size()){n=s2.size()+1;}else{n=s1.size();}
 char* res=(char*)malloc(n+2);
 res[n+1]='\0';
 for(int i=0;i<n+1;i++){
    if(res[i]!='1'&&res[i]!='?')res[i]='0';
    if(s1.size()>i){
        if(s1[i]=='?'){
            if(res[i]=='?'||res[i]=='1')res[i+1]='?';
            res[i]='?';
        }else{
            if(res[i]=='?'){
                if(s1[i]=='1')res[i+1]='?';
                res[i]='?';
            }else if(res[i]=='1'){
                if(s1[i]=='1'){res[i+1]='1';res[i]='0';}else{
                    res[i]='1';
                }
            }else res[i]=s1[i];
        }
    }
    if(s2.size()>i){
         if(s1[i]=='?'){
            if(res[i]=='?'||res[i]=='1')res[i+1]='?';
            res[i]='?';
        }else{
            if(res[i]=='?'){
                if(s2[i]=='1')res[i+1]='?';
                res[i]='?';
            }else if(res[i]=='1'){
                if(s2[i]=='1'){res[i+1]='1';res[i]='0';}else{
                    res[i]='1';
                }
            }else res[i]=s2[i];
        }
    }
 }
 while(res[n]=='0'){res[n]='\0';n--;}
 for(int i=0;i<((n+1)/2);i++){
    char a=res[i];
    res[i]=res[n-i];
    res[n-i]=a;
 }
 return res;
}
};
int main(){
string a,b;
cin>>a>>b;
struct Pair strs(a,b);
char* res=strs.calc();
cout<<res<<endl;
free(res);
return 0;
}
