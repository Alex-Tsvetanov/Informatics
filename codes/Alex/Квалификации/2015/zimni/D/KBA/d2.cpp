#include<iostream>
using namespace std;
int main() {
    long long pokazatel1,pokazatel2;
    bool n=true;
    string duma,duma2;
    long long duljinaNaDumata;
    cin>>duljinaNaDumata>>duma;
    for(int a=0; a<duljinaNaDumata; a++) {
        duma2[a]=duma[duljinaNaDumata-a-1];
    }
    for(int a=0; a<duljinaNaDumata; a++) {
        if(duma[a]!=duma2[a]) {
            n=false;
        }
    }
    if(n==true) {
        cout<<0;
    }
    for(int a=duljinaNaDumata/2; a<duljinaNaDumata && !n; a++) {
        pokazatel1=a-1;
        pokazatel2=a+1;
        if(a+1<duljinaNaDumata && duma[a+1]==duma[a]) {
            if(a+2==duljinaNaDumata) {
                cout<<pokazatel2-1<<endl;
                for(int a=pokazatel2-1; a>0; a--) {
                    cout<<duma[a-1];
                }
                n=true;
                break;
            } else {
                pokazatel2++;
            }
        }
        while(duma[pokazatel1]==duma[pokazatel2]) {
            if(pokazatel2+1==duljinaNaDumata) {
                cout<<pokazatel1;
                if(pokazatel1>0) {
                    cout<<endl;
                    for(int a=pokazatel1; a>0; a--) {
                        cout<<duma[a-1];
                    }
                }
                n=true;
                break;
            }
            pokazatel1--;
            pokazatel2++;
        }
        pokazatel2--;
    }
    if(!n) {
        cout<<duljinaNaDumata-1<<endl;
        for(int a=duljinaNaDumata-2; a>=0; a--) {
            cout<<duma[a];
        }
    }
    return 0;
}
