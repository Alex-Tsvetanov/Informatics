#include<iostream>
#include<vector>

using namespace std;

long long p;
int a1[5000001],a2[5000001],m,k,y,x,pomosht;
vector <int> izh;
bool dis;

int main(){
    int i=0;
    cin>>p>>m;
    for(i=0;i<m;i++){
        cin>>y>>x;
        if(y%2){
            a2[y/2]++;
    }else{
    a1[y/2]++;
    }
        if(x%2){
            a2[x/2]++;
        }else{
        a1[x/2]++;
        }
    }
    cin>>k;
    for(i=1;i<=p;i++){
        if(i%2){
            if(a2[i/2]>=k){
                izh.push_back(i);

            }

        }else{
        if(a1[i/2]>=k){
            izh.push_back(i);
        }
        }
    }
    cout<<endl;
    pomosht=izh.size();
    cout<<pomosht;
    for(i=0;i<pomosht;i++){
        if(dis){
            cout<<" ";
        }else cout<<endl;
        dis=true;
        cout<<izh[i];

    }
        cout<<endl;


return 0;
}
