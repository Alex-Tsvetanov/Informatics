#include<iostream>
using namespace std;
long long n,f;
int main() {
cin>>n;
int a[n];
for (int i=0;i<n;i++) {
    cin>>a[i];
}
for (int i=0;i<n-1;i++) {
    f=0;
    for (int j=i+1;j<n;j++) {
        if (a[i]<a[j]) {f=1;break;}
    }
    if (f==0) cout<<a[i]<<" ";
}

cout<<a[n-1]<<endl;


return 0;
}
