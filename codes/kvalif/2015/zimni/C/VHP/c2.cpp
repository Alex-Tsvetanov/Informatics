#include<iostream>
#include<algorithm>
using namespace std;
int answer[3],sizeX,sizeY;
long long pole[101][101],rowSbor[101],columnSbor[101];
int findDelitel(int t) {
    long long minimum=1000000;
    for(int i=0; i<sizeX; i++) {
        if(minimum>abs(rowSbor[i])) {
            minimum=abs(rowSbor[i]);
        }
    }
    for(int i=0; i<sizeY; i++) {
        if(minimum>abs(columnSbor[i])) {
            minimum=abs(columnSbor[i]);
        }
    }
    int maxDel=1;
    for(int i=2; i<=minimum; i++) {
        bool acceptable=true;
        for(int j=0; j<sizeX; j++) {
            if(rowSbor[j]%i!=0) {

                acceptable=false;
            }
        }
        for(int j=0; j<sizeY; j++) {
            if(columnSbor[j]%i!=0) {

                acceptable=false;
            }
        }
        if(acceptable) {
            maxDel=i;
        }

    }
    return maxDel;

}

int main() {
    answer[0]=1;
    answer[1]=1;
    for(int times=0; times<2; times++) {
        for(int i=0; i<101; i++) {
            rowSbor[i]=0;
            columnSbor[i]=0;
        }
        cin>>sizeX>>sizeY;
        for(int x=0; x<sizeX; x++) {
            for(int y=0; y<sizeY; y++) {
                cin>>pole[x][y];
                rowSbor[x]+=pole[x][y];
            }
        }
        for(int y=0; y<sizeY; y++) {
            for(int x=0; x<sizeX; x++) {
                columnSbor[y]+=pole[x][y];
            }
        }
        int number=0;
        answer[times]=findDelitel(times);
    }

    /**
    3 3
    1 2 3
    4 5 6
    7 8 9
    2 2
    1 1
    1 1
    */

    cout<<answer[0]<<" "<<answer[1];
    cout<<endl;
    bool yes=false;
    if(answer[0]%answer[1]==0 || answer[1]%answer[0]==0) {
        yes=true;
    }
    if(yes) {
        cout<<"Y";
    } else {
        cout<<"N";
    }
    cout<<endl;
    return 0;
}
