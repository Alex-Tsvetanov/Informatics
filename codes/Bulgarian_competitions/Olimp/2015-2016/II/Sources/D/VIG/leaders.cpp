#include<iostream>
using namespace std;

int vhod[1000000], n;
void proverqvamIIzvejdam(int koePoRed){
  int i;
  if(koePoRed==n-1){
    cout<<vhod[koePoRed]<<" ";
    return;
  }
  for(i=koePoRed+1;i<n;i++){
    if(vhod[koePoRed]<vhod[i])return;
  }
  cout<<vhod[koePoRed]<<" ";
}

int main(){
  int i, j;
  cin>>n;
  for(i=0;i<n;i++)cin>>vhod[i];
  for(i=0;i<n;i++)proverqvamIIzvejdam(i);
  cout<<endl;
  return 0;
}
