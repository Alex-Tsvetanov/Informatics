#include<iostream>
#include<vector>
#include<string>
using namespace std;
string num1,num2;
vector<char> st1,st2,st3;
char naum='0';
int br=0,brv=0;
using namespace std;
int main()
{
    cin>>num1>>num2;
    for(int i=0;i<num1.size();i++)
    {
        st1.push_back(num1[i]);
    }
    for(int i=0;i<num2.size();i++)
    {
        st2.push_back(num2[i]);
    }
    for(int i=0;i<st1.size()||i<st2.size();i++)
    {
        //cout<<naum<<"<-naum\n";
        br=brv=0;
        if(i>st1.size()-1){}else{if(st1[st1.size()-1-i]=='?'){brv++;}else{br+=st1[st1.size()-1-i]-'0';}}
        if(i>st2.size()-1){}else{if(st2[st2.size()-1-i]=='?'){brv++;}else{br+=st2[st2.size()-1-i]-'0';}}
        if(naum=='?'){brv++;}else{br+=naum-'0';}
        if(brv>=2){naum='?';st3.push_back('?');}else
        if(brv==1){if(br==0){naum='0';st3.push_back('?');}if(br==1){naum='?';st3.push_back('?');}if(br==2){naum='1';st3.push_back('?');}}else
        {
            naum=br/2+'0';
            st3.push_back(br%2+'0');
        }
        //cout<<br<<"<-br\n";
        //cout<<st1[st1.size()-1-i]<<"<-st1[st1.size()-1-i]\n";
        //if(br<0){break;}
    }
    if(naum=='1'||naum=='?'){st3.push_back(naum);}
    for(int i=0;i<st3.size();i++)
    {
        cout<<st3[st3.size()-1-i];
    }
    cout<<'\n';
    return 0;
}
/*
101??001
1?01101
*/
