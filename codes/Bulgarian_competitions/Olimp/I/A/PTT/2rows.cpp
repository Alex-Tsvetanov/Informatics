#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    int res[5];
    for(int i=0;i<5;i++){
        res[i]=1;
        int n;
        cin>>n;
        int* a=(int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){cin>>a[j];}
        int n1;
        cin>>n1;
        int* b=(int*)malloc(n*sizeof(int));
        for(int j=0;j<n1;j++){cin>>b[j];}
        int a1=0;
        int b1=0;
        int prev=0;
        for(int j=0;j<(n+n1);j++){
            if(a1<n&&a[a1]<b[b1]&&prev<=a[a1]){
                prev=a[a1];
                a1++;
            }else if(b1<n1&&prev<=b[b1]){
                prev=b[b1];
                b1++;
            }else{
                res[i]=0;
                break;
            }
        }
        free(a);
        free(b);
    }
    cout<<res[0]<<res[1]<<res[2]<<res[3]<<res[4]<<endl;
return 0;
}

