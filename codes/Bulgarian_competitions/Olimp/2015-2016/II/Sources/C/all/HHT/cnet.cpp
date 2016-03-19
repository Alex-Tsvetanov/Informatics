#include<iostream>
using namespace std;
long long susedi[3000][3000],m,n,d,e;
long long brsusedi[3000];
bool b[3000];
long long c=0,bigc=0,smallc=100000,smallcn[300],q=0;
void meh(long long a){
    b[a]=true;
    for(int i=0;i<brsusedi[a];i++){
        if(b[susedi[a][i]]==false){
            c++;
            b[susedi[a][i]]=true;
            meh(susedi[a][i]);
            if(c>bigc){
                bigc=c;
            }
            c--;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>d>>e;
        susedi[d][brsusedi[d]]=e;
        brsusedi[d]++;
    }
    for(int r=0;r<n;r++){
        bigc=0;
        for(int z=0;z<n;z++){
            b[z]=false;
        }
        meh(r);
        for(int z=0;z<n;z++){
            if(b[z]==false){
                bigc=10000;
            }
        }
        if(bigc<smallc){
            smallc=bigc;
            smallcn[q]=r;
            q=0;
        }
        if(bigc==smallc){
            smallc=bigc;
            smallcn[q]=r;
            q++;
        }
    }
    cout<<q<<endl<<smallcn[0];
    for(int i=1;i<q;i++){
        cout<<" "<<smallcn[i];
    }
    cout<<endl;
return 0;
}
