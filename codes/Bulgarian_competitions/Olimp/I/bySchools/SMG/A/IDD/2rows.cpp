#include <iostream>
#include <map>
using namespace std;
map<int, int> pos;
int n,a,lp,p;
bool flag;
int main(){
    for (int j=0; j<5; ++j){
        pos.clear();
        flag = true;
        cin>>n;
        for (int i=0;i<n;++i){
            cin>>a;
            pos[a]=i+1;
        }
        cin>>n;lp=0;
        for (int i=0;i<n;++i){
            cin>>a;
            p=pos[a];
            if (p!=0){
                if (p<lp){
                    flag=false;
                }
                lp = p;
            }
        }
        cout<<flag;
    }
    cout<<endl;
    return 0;
}
