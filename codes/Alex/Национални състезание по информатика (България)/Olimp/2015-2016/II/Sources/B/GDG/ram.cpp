#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k,f,f1,br=0;
    cin>>k;
    f1=1;
    vector<pair<int,int> >v;
    for(int m = 1; ; m++){
        int n=1;

        f=f1+3;
        f1=f;

        if(f-(2*n-1) == k){
            v.push_back(make_pair(m,n));
            br++;
        }
        if(f-(2*n-1) > k)break;


        for(int n = 2;; n++){
            f=f+2*m+1;
            int broken;
            if(m<n){
                broken = 2*m;
            }else{
                broken = 2*n -1;
            }
            if(f-broken == k){
                    v.push_back(make_pair(m,n));
                    br++;
            }
            if(f-broken > k)break;
            //cout<<f<<" ";

        }
        //cout<<endl;
    }

    cout<<br<<endl;
    for(int i = 0; i < v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }


    return 0;

}
