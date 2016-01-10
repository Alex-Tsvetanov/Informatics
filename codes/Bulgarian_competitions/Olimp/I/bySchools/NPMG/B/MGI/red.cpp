#include <iostream>
using namespace std;
long long n,a[20000],   minn,maxx   ,pf_x,pl_x,   pf_n,pl_n;

void exit(){
    if(pf_n<pf_x){
        if(pl_n<pf_x){
            cout<<pf_n+1<<" "<<pl_x+1;
        }
        else{
            if(pl_n<pl_x)cout<<pf_n+1<<" "<<pl_x+1;
            else{
                if(pl_x-pf_n>pl_n-pf_x)cout<<pf_n+1<<" "<<pl_x+1;
                else cout<<pf_x+1<<" "<<pl_n+1;
            }
        }
    }
    else{
        if(pl_x<pf_n){
            cout<<pf_x+1<<" "<<pl_n+1;
        }
        else{
            if(pl_x<pl_n)cout<<pf_x+1<<" "<<pl_n+1;
            else{
                if(pl_n-pf_x>pl_x-pf_n)cout<<pf_x+1<<" "<<pl_n+1;
                else cout<<pf_n+1<<" "<<pl_x+1;
            }
        }
    }

}

int main(){
cin>>n;
cin>>a[0];
minn=a[0];
maxx=a[0];
for(int i=1;i<n;i++){
    cin>>a[i];
    if(maxx<=a[i]){
        if(maxx<a[i]){
            maxx=a[i];
            pf_x=i;
        }
        else{
            pl_x=i;
        }
    }
    if(minn>=a[i]){
        if(minn<a[i]){
            minn=a[i];
            pf_n=i;
        }
        else{
            pl_n=i;
        }
    }
}
exit();
cout<<endl;
return 0;
}
