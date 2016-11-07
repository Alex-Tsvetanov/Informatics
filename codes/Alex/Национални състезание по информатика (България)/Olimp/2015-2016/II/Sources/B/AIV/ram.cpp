#include<iostream>
using namespace std;

int main(){
    int k;
    cin>>k;

    int br=0;
    int broken;

    for(int m=1;m<10000;m++){
        for(int n=1;n<10000;n++){
            broken=m+n+2*m*n-k;
            if(broken%2==1 and m==broken/2+1 and broken<m+n){
                br++;
                //cout<<broken<<" "<<m<<" "<<n<<endl;
                break;
            }
            if(broken%2==0 and n==broken/2 and broken<m+n){
                br++;
                //cout<<broken<<" "<<m<<" "<<n<<endl;
                break;
            }
        }
    }
    //cout<<br;
    int a[br];
    int b[br];
    int counter=0;

    for(int m=1;m<10000;m++){
        for(int n=1;n<10000;n++){
            broken=m+n+2*m*n-k;
            if(broken%2==1 and m==broken/2+1 and broken<m+n){
                a[counter]=n;
                b[counter]=m;
                counter++;
                //cout<<broken<<" "<<m<<" "<<n<<endl;
                break;
            }
            if(broken%2==0 and n==broken/2 and broken<m+n){
                a[counter]=n;
                b[counter]=m;
                counter++;
                //cout<<broken<<" "<<m<<" "<<n<<endl;
                break;
            }
        }
    }
    int x;
    for(int k=0;k<br;k++){
    for(int i=0;i<br;i++){
        if(a[i]>a[i+1]){
            x=a[i];
            a[i]=a[i+1];
            a[i+1]=x;

            x=b[i];
            b[i]=b[i+1];
            b[i+1]=x;
        }
    }
    }

    cout<<br<<endl;
    for(int i=0;i<br;i++){
        cout<<a[i]<<" "<<b[i]<<endl;
    }

    return 0;
}
