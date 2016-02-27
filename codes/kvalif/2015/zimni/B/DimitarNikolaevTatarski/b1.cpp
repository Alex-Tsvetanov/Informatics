#include<iostream>
using namespace std;
int M,N,m,n,maxSum=-2147483647;
int table[1001][1001];
int findSumOf(int x,int y){
    int sum=0;
    for(int br1=x;br1<x+m;br1++){
        for(int br2=y;br2<y+n;br2++){
            sum+=table[br1][br2];
        }
    }
    return sum;
}
int main(){
    cin>>M>>N>>m>>n;
    for(int br1=0;br1<M;br1++){
        for(int br2=0;br2<N;br2++){
            cin>>table[br1][br2];
        }
    }
    for(int br1=0;br1<=M;br1++){
        for(int br2=0;br2<N;br2++){
            int curSum=findSumOf(br1,br2);
            if(curSum>maxSum){
                maxSum=curSum;
            }
        }
    }
    cout<<maxSum<<endl;
    return 0;
}
