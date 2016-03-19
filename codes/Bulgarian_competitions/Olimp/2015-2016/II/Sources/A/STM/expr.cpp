#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string a;
int n;
vector<bool>v;
map<char, bool>m;

bool calc(string b){
    bool t=0;

    if(b.size()==1){
        t=v[(int)(b[0]-'a')];
        return t;
    }
    //---------------------------------------------------

    int k, h, j=1, s=0;
    string x;


    vector<bool>ans;
    if(b[0]!='('){
        ans.push_back(v[(int)(b[0]-'a')]);
    }
    else{
        k=1, h=0;
        while(k!=h){
            if(b[j]=='(')k++;
            if(b[j]==')')h++;
            if(k!=h)x+=b[j];
            j++;
        }
        ans.push_back(calc(x));
        x.clear();

    }
    //--------------------------------------------------------------------
    int i=j;
    s=1;
    while(i<b.size()){
        if(b[i]!=')' && b[i]!='('){
            ans.push_back(v[(int)(b[i]-'a')]);
            i++;
            s++;
        }
        else if(b[i]=='('){
            j=i+1;
            k=1, h=0;
            while(k!=h){
                if(b[j]==')')h++;
                if(b[j]=='(')k++;
                if(k!=h)x+=b[j];
                j++;
            }
            ans.push_back(calc(x));
            x.clear();
            s++;
            i=j;
        }else i++;
    }

    s=ans.size();
    for(int i=1; i<s; i++){
        if(ans[i]==1 && ans[i-1]==1)ans[i]=0;
        else ans[i]=1;
    }

    return ans[s-1];
}

int main ()
{
    cin>>a;
    int i=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]!='(' && a[i]!=')')m[a[i]]=1;
    }
    n=m.size();
    v.resize(n+1);
    string y;
    do{
        cin>>y;
        if(y[0]!='2'){
            for(int i=0; i<n; i++){
                if(y[i]=='1')v[i]=1;
                else v[i]=0;
            }
            cout<<calc(a);

        }
    }while(y[0]!='2');
    cout<<endl;

    return 0;
}

/*
a(a)(ab(ca)bb)c
011
100
010
111
001
*/

