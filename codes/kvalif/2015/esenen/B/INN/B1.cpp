#include <iostream>
#include <stack>
using namespace std;

struct point{
    int x,y;
    point(){
        x=0;
        y=0;
    }
    point(const point &sec){
        x=sec.x;
        y=sec.y;
    }
    int in(){
        cin>>x>>y;
    }
    int print(){
        cout<<"("<<x<<" "<<y<<")";
    }
    int dot_prod(point sec){
        return x*sec.y - y*sec.x;
    }
};

int                 n;
long long  ans,d,h,ds;
point      input,curr;
stack<point>        s;

int main (){
    ds = 4611686018427387904;
    cin>>n;
    for(int i=0;n;i++){
        for(int k=0;k<n;k++){
            input.in();
            s.push(input);
        }
        while(s.size()>1){
            curr = s.top();
            s.pop();
            d += curr.dot_prod(s.top());
        }
        d+=s.top().dot_prod(input);
        s.pop();
        if(ds>d){
            ds = d;
            h = n;
            ans = i;
        }
        if(ds==d and h>n){
            h = n;
            ans = i;
        }
        d=0;
        cin>>n;
    }
    cout<<ans+1<<endl;
    return 0;
}
