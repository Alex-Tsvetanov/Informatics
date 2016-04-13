#include<iostream>
#include<string>
using namespace std;
string a;
int m;

int palindrom (int x){
    int y, z;
    bool flag;
    for(int i=m-1; i>=x; i--){
        if(a[i]==a[x]){
            y=(x+i)/2;
            flag=1;
            if((i-x)%2==1){
                z=y+1;
                for(int j=0; j<=y-x && flag==1; j++){
                    if(a[y-j]!=a[z+j])flag=0;
                }
            }
            else{
                z=y;
                for(int j=0; j<=y-x && flag==1; j++){
                    if(a[y-j]!=a[z+j])flag=0;
                }
            }
            if(flag==1){
                return i;
            }
        }
    }
    return 1;
}

int main ()
{
    cin>>a;
    m=a.size();
    int s, i=0, br=0;
    do{
        s=palindrom(i);
        if(s!=m-1)br++;
        i+=s+1;
        //br++;
    }while(i<m);
    cout<<br<<endl;


    return 0;
}
