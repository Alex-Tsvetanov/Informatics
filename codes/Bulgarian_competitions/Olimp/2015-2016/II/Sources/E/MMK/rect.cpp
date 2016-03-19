#include<iostream>
using namespace std;

long long n, i, p=4, q=3, br=0, k=4;

int main () {
    cin>>n;
    do {
        if (n==p)br++;
        else if ((n-p)%q==0 && n>p)br++;
        else if (n%p==0)br++;
        p+=3;
        q+=2;
    }
    while (n-p>q);
    cout<<br<<endl;
    return 0;
}
