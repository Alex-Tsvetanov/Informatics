#include<iostream>
using namespace std;
long long n,m,p=1,f=0;
int main() {
cin>>m>>n;
int a[m*n];
for (int i=0;i<m*n;i++) {
    cin>>a[i];
}
while (1) {
    if (a[0]==0 && a[1]==p) {
        a[0]=p;
    }
    for (int i=1;i<m*n;i++) {
        if (a[i]==0 && (a[i-1]==p || a[i+1]==p)) {
            a[i]=-1;
        }
    }
    for (int i=0;i<m*n;i++) {
        if (a[i]==-1) {
            a[i]=p;
        }
    }
    p++;
    f=0;
    for (int i=0;i<m*n;i++) {
        if (a[i]==0) {f=1;a[i]=p;break;}
    }
    if (f==0) {
        break;
    }
}
cout<<p-1<<endl;
return 0;
}
