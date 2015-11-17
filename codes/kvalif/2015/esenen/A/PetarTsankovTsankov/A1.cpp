#include<stdio.h>
int N,M;
int twn[10000][10000];
int search_(int cur){
    if(cur==N-1){
        return 65001;
    }
    printf("%d{",cur+1);
    int i;
    int max_=0;
    for(i=0;i<N;i++){
        if(twn[cur][i]!=0||twn[i][cur]!=0){
            int x;
            int r;
            if(twn[cur][i]!=0){
                r=twn[cur][i];
                twn[cur][i]=0;
            }else{
                r=twn[i][cur];
                twn[i][cur]=0;
            }
            x=search_(i);
            twn[cur][i]=r;
            if(x>r){
                x=r;
            }
            if(x>max_){
                max_=x;
            }
        }
    }
    return max_;

}
int main(){
    scanf("%d%d",&N,&M);
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            twn[i][j]=0;
        }
    }
    for(i=0;i<M;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        twn[a-1][b-1]=c;
    }
    printf("%d",search_(0));
    return 0;
}
