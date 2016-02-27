#include<iostream>
#include<string>
using namespace std;
string palindrom;
int main(){
   int n, pribavi=0, index, index1;
///VHOD
   cin>>n;
   cin>>palindrom;
///ALGORITHM
   n--;
   index1=n;
   bool Stana=0;
   for(int i=0;i<n;i++){
        index=i;
        while(palindrom[index]==palindrom[index1]){

            if(index1-index==0 or index1-index==1){
                Stana=1;
                break;
            }
            index++; index1--;
        }
        if(Stana==1){
            break;
        }else{
            pribavi++;
            index1=n;
        }
   }
///IZHOD
        cout<<pribavi<<endl;
        if(pribavi!=0){
            for(int i=pribavi-1;i>=0;i--){
                cout<<palindrom[i];
            }
        cout<<endl;
        }
return 0;
}
