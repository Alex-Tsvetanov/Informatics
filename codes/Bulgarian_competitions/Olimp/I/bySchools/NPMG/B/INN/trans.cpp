 #include <iostream>
 #include <queue>
 using namespace std;
 int p,m,a,b,k;
 int arr[10002];
 queue<int> ans;
 int main(){
    cin>>p>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        arr[a]++;
        arr[b]++;
    }
    cin>>k;
    for(int i=0;i<p;i++){
        if(arr[i]>=k){
            ans.push(i);
        }
    }
    if(ans.empty()){
        cout<<"0\n";
    }else{
        cout<<ans.size()<<endl;
        while(!ans.empty()){
            cout<<ans.front()<<" ";
            ans.pop();
        }
        cout<<endl;
    }
    return 0;
 }
