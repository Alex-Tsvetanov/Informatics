#include<iostream>
using namespace std;
long br=0;
long maxx=0;
int position = 0;
int maxposition = 0;


int main(){
int N,M;
int jump[200];
int box [200000]= {0,};
cin>>N>>M;
for(int i=0;i<M;i++){
    cin>>jump[i];
}
for(int i=0;i<N+1;i++){
    cin>>box[i];
}


br=0;
maxx=0;

for(int i=5;i>0;i++){

    for(int q=0;q<M;q++){
            if(position + jump[q] <= N ){
                if(box[position] + box[jump[q]+position] > maxx){
                maxx = box[position] + box[jump[q]+position];
                maxposition = jump[q]+position;
            }
        }
        if(position + jump[q] <= N  and q==M-1){
           position = maxposition;
    br= br + maxx;
    maxx=0;
    maxposition=0;

        }
        if(position + jump[q] > N and q==M-1){
            cout<<br<<" ";
            cout<<position<<endl;
            return 0;
        }
    }



}





return 0;
}
