#include<iostream>
#include<cmath>
using namespace std;
long long n,chisla[1000],br,otg,koren,del;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    for(br=0;br<n;br++){
        cin>>chisla[br];
    }
    for(br=0;br<n;br++){
        koren=sqrt(chisla[br]);
        otg=0;
        for(del=1;del<=koren;del++){
            if(chisla[br]%del==0){
                otg++;
                if(chisla[br]/del!=del)
                    otg++;
            }
        }
        cout<<otg;
        if(br+1<n)
            cout<<" ";
    }
    cout<<"\n";
    return 0;
}
