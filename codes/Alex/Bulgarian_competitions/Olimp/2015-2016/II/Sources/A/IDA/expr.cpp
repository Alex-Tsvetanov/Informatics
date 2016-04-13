#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

map < char, int > m;

int fff(int a, int b){
    if(a+b==2)return 0;
    else
    return 1;
}

int chch(int a, char b){
    if(a+m[b]==2)return 0;
    else
    return 1;
}

int rec(string s){
int pos1,pos2,ans;


    for(int i=0;i<s.size();i++){
        if(i==0)ans=m[s[0]];
        else
        if(s[i]!='(' && s[i]!=')'){
            ans=chch(ans,s[i]);
        }
        else
        if(s[i]=='('){
            i++;
            pos1=i;

            for(int br=1;;i++){
                if(s[i]=='(')br++;
                else
                if(s[i]==')')br--;

                if(br==0){
                    pos2=i-1;
                    break;
                }
            }

            ans=fff(ans,rec(s.substr(pos1,pos2-pos1+1)));
        }
    }
return ans;
}


string s;
long long br=0,ans,brsk=0,pos;
char a[1024];
int main(){
cin>>s;
    m['(']=5;
    m[')']=5;

    for(int i=0;i<s.size();i++){
        if(m[s[i]]!=5){
            m[s[i]]=5;
            br++;
        }
    }

    for(;;){
        for(int i=1;i<=br;i++){
           cin>>a[i];
            if(a[1]=='2')break;

            m[char(i+96)]=int(a[i]-48);
        }

        if(a[1]=='2')break;



        cout<<rec(s);
    }
    cout<<endl;
return 0;
}
/*

*/
