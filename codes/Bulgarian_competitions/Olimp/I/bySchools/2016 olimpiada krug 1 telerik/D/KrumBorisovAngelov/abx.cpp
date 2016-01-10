#include<iostream>
using namespace std;
int main() {
    string urawnenie;
    long long subiraemo=0,sbor=0,nachaloNaSbor=3;
    cin>>urawnenie;
    if(urawnenie[0]!='X') {
        for(long long a=0; urawnenie[a]!='+'; a++) {
            nachaloNaSbor++;
            subiraemo*=10;
            subiraemo+=(urawnenie[a]-'0');
        }
    } else {
        for(long long a=2; urawnenie[a]!='='; a++) {
            nachaloNaSbor++;
            subiraemo*=10;
            subiraemo+=(urawnenie[a]-'0');
        }
    }
    for(long long a=nachaloNaSbor; a<urawnenie.length(); a++) {
        sbor*=10;
        sbor+=(urawnenie[a]-'0');
    }
    cout<<sbor-subiraemo;
    return 0;
}
