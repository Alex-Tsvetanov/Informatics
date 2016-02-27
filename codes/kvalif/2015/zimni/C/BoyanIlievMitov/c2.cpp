#include<iostream>
using namespace std;

int main(){
    long long m,n,m1,n1,da=1,db=1;
    cin>>m>>n;
    long long bra=m+n;
    long long nsa[bra];
    long long a[m][n];
    for(int i=0;i<bra;i++){
        nsa[i]=0;
    }
    for(int i=0;i<m;i++){
        nsa[i]=0;
        for (int j=0;j<n;j++){
            cin>>a[i][j];
            nsa[i]+=a[i][j];
            nsa[m+j]+=a[i][j];
        }
    }
    cin>>m1>>n1;
    long long brb=m1+n1;
    long long nsb[brb];
    long long b[m1][n1];
       for(int i=0;i<brb-m1;i++){
        nsb[i]=0;
    }
    for(int i=0;i<m1;i++){
        nsb[i]=0;
        for (int j=0;j<n1;j++){
            cin>>b[i][j];
            nsb[i]+=b[i][j];
            nsb[m1+j]+=b[i][j];
        }
    }

    bool stop=false;
    long long mi=10000001;
    bool ne=false;
    while(stop==false){
        mi=10000001;
        for(int i=0;i<bra;i++){
            if(i==bra-1&&nsa[i]<nsa[1]&&nsa[i]<mi){
                mi=nsa[i];
            }
            if(nsa[i]<nsa[i+1]&&nsa[i]<mi){
                mi=nsa[i];
            }
                      // if(nsa[i]==1){
           //     mi=1;
            //    break;
           // }
        }
        if(mi==10000001){
            da=nsa[0];
            stop=true;
        }
        for(int i=0;i<bra;i++){
            if(mi-nsa[i]!=0){
                nsa[i]=nsa[i]-mi;
            }
        }
        ne=false;
        for(int i=0;i<bra;i++){
            if(nsa[i]==nsa[i+1]){
                ne=true;
            }else{
                break;
            }
        }
        if(ne==true){
            da=nsa[0];
            stop=true;
        }
    }
    cout<<da<<" ";



    stop=false;
    ne=false;
    while(stop==false){
        mi=10000001;
        for(int i=0;i<brb;i++){
            if(i==bra-1&&nsb[i]<nsb[1]&&nsb[i]<mi){
                mi=nsb[i];
            }
            if(nsb[i]<nsb[i+1]&&nsb[i]<mi){
                mi=nsb[i];
            }
                      // if(nsa[i]==1){
           //     mi=1;
            //    break;
           // }
        }
        if(mi==10000001){
            db=nsb[0];
            stop=true;
        }
        for(int i=0;i<brb;i++){
            if(mi-nsb[i]!=0){
                nsb[i]=nsb[i]-mi;
            }
        }
        ne=false;
        for(int i=0;i<brb;i++){
            if(nsb[i]==nsb[i+1]){
                ne=true;
            }else{
                break;
            }
        }
        if(ne==true){
            db=nsb[0];
            stop=true;
        }
    }
    cout<<db<<endl;

    if(da%db==0||db%da==0){
        cout<<"Y"<<endl;
    }else{
        cout<<"N"<<endl;
    }




return 0;
}
