#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[200005];
vector<int> output;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int p, m, k;
    cin>>p>>m;
    m*=2;
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    cin>>k;
    sort(a, a+m);
    int crnt=0;
    for(int i=1;i<m;i++){
        if(a[i]!=a[i-1]){
            if(i-crnt>=k) output.push_back(a[crnt]);
            crnt=i;
        }
    }
    if(m-crnt>=k) output.push_back(a[crnt]);
    sort(output.begin(), output.end());
    cout<<output.size()<<"\n";
    if(output.size()>0){
        cout<<output[0];
        for(int i=1;i<output.size();i++){
            cout<<" "<<output[i];
        }
        cout<<"\n";
    }
    return 0;
}
