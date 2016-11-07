#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

bool ispal(string s){
    int d=s.size();
    bool fl=1;

    for(int i=0;i<=(d-1)/2;i++){
            if(s[i]!=s[d-1-i]){fl=0; break;}
    }
return fl;
}

map < char , vector < int > > m,m2;
string s;
long long ans1=0, ans2=0;
int main(){
cin>>s;

        for(int i=0;i<s.size();i++){
            m[s[i]].push_back(i);
        }

        for(int i=s.size()-1;i>=0;i--){
            m2[s[i]].push_back(i);
        }

        for(int i=0;i<s.size();i++){
             for(int j=m[s[i]].size()-1;j>=0;j--){
                if(i<=m[s[i]][j]){
                  if(ispal(s.substr(i,m[s[i]][j]-i+1))==1){
                   ans1++;
                   i=m[s[i]][j];
                   break;
                  }
                }
             }
        }



        for(int i=s.size()-1;i>=0;i--){
            for(int j=m2[s[i]].size()-1;j>=0;j--){
                if(m2[s[i]][j]<=i){
                    if(ispal(s.substr(m2[s[i]][j],i-m2[s[i]][j]+1))==1){
                    ans2++;
                    i=m2[s[i]][j];
                    }

                }
            }

        }
    cout<<min(ans1,ans2)-1<<endl;

return 0;
}
/*



*/
