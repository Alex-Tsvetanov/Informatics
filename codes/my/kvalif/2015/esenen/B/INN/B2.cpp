#include <iostream>
using namespace std;

int                     n,m;
long long  p, answ, answPos;
int              jumps[205];
int          apples[201005];
long long maxApples[201005];

int main (){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>jumps[i];
    }
    for(int i=0;i<=n;i++){
        cin>>apples[i];
    }
    maxApples[0] = apples[0];
    for(int i=0;i<=n;i++){
        if(maxApples[i]>0){
            for(int x=0;x<m;x++){
                p = maxApples[i] + apples[i+jumps[x]];
                if(maxApples[i+jumps[x]] < p){
                    maxApples[i+jumps[x]] = p;
                }
            }
        }
        if(maxApples[i]>answ){
            answ = maxApples[i];
            answPos = i;
        }
    }
    cout<<answ<<" "<<answPos<<endl;
    return 0;
}
