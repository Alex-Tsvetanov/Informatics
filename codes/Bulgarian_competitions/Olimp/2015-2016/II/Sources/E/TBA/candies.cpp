#include<iostream>
using namespace std;
int main (){
    long long a,b,c,x=0,g=0;
    cin>>a>>b>>c;
    for(long long n=0;n<=2000000000;n++){
                    if(a==1 and g>=1){
            x++;
            cout<<x;
            return 0;
        }
                if(b==1 and g>=1){
            x++;
            cout<<x;
            return 0;
        }
        c--;
        x++;
        g++;
        if(c==0){
            cout<<x;
            return 0;
        }
        b--;
        x++;
        if(b==0){
            cout<<x;
            return 0;
        }
        a--;
        x++;
        if(a==0){
            cout<<x;
            return 0;
        }
    }

    return 0;
}
