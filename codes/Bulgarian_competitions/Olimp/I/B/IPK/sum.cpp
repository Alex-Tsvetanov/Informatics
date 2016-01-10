#include<iostream>
#include<queue>
using namespace std;

queue<int> q;

int main(){
    int n;
    cin >> n;
    int ans = 1;
    int i = 1;
    while(n > 1){
        ans++;
        q.push(i);
        i++;
        n-=2;
    }

    while(!q.empty()){
        int a = q.front();
        q.pop();
        i = 1;
        while(a > 1){
            ans++;
            q.push(i);
            i++;
            a -= 2;
        }
    }
    cout << ans << "\n";
	return 0;
}
