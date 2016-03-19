#include<iostream>
using namespace std;
int maxE=0;
bool mixed;
struct Cus{
long long S,E;

};
int main() {

long long N;
int M,P;
cin>>N>>M>>P;
int Ekip=P/2;

Cus T[M];

for(int i=0;i<M;i++){
    cin>>T[i].S>>T[i].E;
    if(T[i].E>maxE){
        maxE=T[i].E;
    }

}
cout<<"OK"<<endl;

return 0;
}
