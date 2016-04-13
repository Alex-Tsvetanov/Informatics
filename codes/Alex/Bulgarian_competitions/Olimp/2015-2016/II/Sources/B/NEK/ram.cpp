#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector <int> a[100000],brk,brr;
int br;
void pulnene(int xs,int ys){
    for(int i=0;i<xs;i++){
        a[i].clear();
    }
   // cout<<xs<<" "<<ys<<endl;;
    for(int i=0;i<xs;i++){
        for(int j=0;j<ys;j++){
            a[i].push_back(2);
            if(i==(xs-1)&&xs!=1)a[i][j]=1;
            if(j==(ys-1)&&xs!=1)a[i][j]=1;
            if(i==0||i==xs-1)a[i][j]+=1;
            if(j==0||j==ys-1)a[i][j]+=1;
            if(i==j)a[i][j]=1;
            if(i==0&&j==0)a[i][j]=3;
            if(i==xs-1&&j==0)a[i][j]=3;
            if(i==0&&j==ys-1)a[i][j]=3;
            if(i==xs-1&&j==ys-1)a[i][j]==1;
             if((j-i)==1)a[i][j]-=1;
        }
    }/*cout<<endl;
    for(int i=0;i<xs;i++){
        for(int j=0;j<ys;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/


}
void prov(int k,int p)
{
    int sbor=0;
    pulnene(p,1);
    for(int i=0;sbor<k;i++){
        for(int j=0;j<p;j++){
            for(int l=0;l<a[j].size();l++){
                sbor+=a[j][l];
            }
        }
      //  cout<<sbor<<endl;
        if(sbor==k){
                brk.push_back(p);
                brr.push_back(a[0].size());
                br++;
        }
        if(sbor>k);
        else {
            pulnene(p,a[0].size()+1);
            sbor=0;
        }
    }
}

int main()
{
    int k;
    scanf("%d",&k);
    for(int i=1; i<k/3; i++)
    {
        prov(k,i);
    }
    cout<<br<<endl;
    if(brk[0]==1)swap(brk[0],brr[0]);
    for(int i=0;i<brk.size();i++){
        for(int j=0;j<brk.size();j++){
            if(brr[i]<brr[j]){
                swap(brr[i],brr[j]);
                swap(brk[i],brk[j]);
            }
        }
    }
    for(int i=0;i<brk.size();i++){
        //if(brk[i]!=1)swap(brk[i],brr[i]);
        cout<<brr[i]<<" "<<brk[i]<<endl;
    }

    return 0;
}
