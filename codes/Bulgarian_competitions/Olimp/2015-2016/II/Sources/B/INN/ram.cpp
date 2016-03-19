#include <iostream>
#include <queue>
using namespace std;

int k,x,y;
queue<int> q1;
queue<int> q2;

inline int f(int m,int n){
    if(m>n){
        return n*2 - 1;
    }else{
        return m*2 ;
    }
}

inline int s(int m,int n){
    return (m+1)*n + (n+1)*m;
}

inline int find_n(int k, int m){
    return (k-m)/(2*m+1);
}

int main (){
    cin>>k;
    for(int i=1;i<k;i++){
        y = ((i+1)/2);
        x = find_n(k+i,y);
        if(i == f(x,y) and s(x,y) == k + i){
            q1.push(x);
            q2.push(y);
        }
        if(i == f(y,x) and s(y,x) == k + i){
            q1.push(y);
            q2.push(x);
        }
    }
    cout<<q1.size()<<endl;
    while(!q1.empty()){
        cout<<q1.front()<<" "<<q2.front()<<endl;
        q1.pop();
        q2.pop();
    }
    return 0;
}
