#include<iostream>
using namespace std;
int main() {
long long masivOtChisla[25], n, tyrsenoChislo, i;
cin>>masivOtChisla[0]>>masivOtChisla[1]>>masivOtChisla[2]>>n;
tyrsenoChislo=masivOtChisla[n];
for(i=0;i<25;i++){
    if(i>2){
        masivOtChisla[i]=masivOtChisla[i-1]+masivOtChisla[i-2]+masivOtChisla[i-3];
    }
}
tyrsenoChislo=masivOtChisla[n-1];
cout<<tyrsenoChislo<<endl;
return 0;
}
/*
1
2
3
6
11
20
37






*/
