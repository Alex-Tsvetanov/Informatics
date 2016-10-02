#include<iostream>
#include<queue>
using namespace std;
int br=0;
int main() {
int N,M,T;

cin>>N>>M>>T;

int box[N][M];
for(int i=0;i<N;i++){
    for(int i2=0;i2<M;i2++){
     box[i][i2]=0;
     }
    }
int fr=0;
queue<int> rot1;
queue<int> rot2;

int rt1,rt2;
cin>>rt1>>rt2;
do{

 rot1.push(rt1);
 rot2.push(rt2);
 box[rt1-1][rt2-1]=1;
 br++;

}
while(cin>>rt1>>rt2);

//int siz=rot1.size();

for(int i=1;i<=T;i++){
        for(int t=0;t<br;t++){
            box[rot1.front()+1-1][rot2.front()-1]=1;

            rot1.push(rot1.front()+1);
            rot2.push(rot2.front());
            box[rot1.front()-1-1][rot2.front()-1]=1;
            rot1.push(rot1.front()-1);
            rot2.push(rot2.front());
            box[rot1.front()-1][rot2.front()+1-1]=1;
            rot2.push(rot2.front()+1);
            rot1.push(rot1.front());
            box[rot1.front()-1][rot2.front()-1-1]=1;
            rot2.push(rot2.front()-1);
            rot1.push(rot1.front());
            rot1.pop();
            rot2.pop();
        }
br=br*4;
}

for(int i=0;i<N;i++){
    for(int i2=0;i2<M;i2++){
     if(box[i][i2]==0){
        fr++;
     }
     }
    }
cout<<fr<<endl;


for(int i=0;i<N;i++){
    for(int i2=0;i2<M;i2++){
     cout<<box[i][i2]<<" ";


     }
     cout<<endl;
    }
return 0;
}
