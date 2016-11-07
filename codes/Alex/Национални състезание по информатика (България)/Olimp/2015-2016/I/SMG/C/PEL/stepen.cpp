#include<iostream>
using namespace std;
int main(){
        long long X,stepen,pokazatel,osnova,predstavqniq;
        cin>>X;
        predstavqniq=0;
        for(osnova=X;osnova>1;osnova--){
                pokazatel=0;
                stepen=1;
                while(stepen<X){
                        stepen=stepen*osnova;
                        if (stepen==X){
                            predstavqniq++;
                        }
                }
        }
        predstavqniq--;
        cout<<predstavqniq<<"\n";
        for(osnova=X;osnova>1;osnova--){
                pokazatel=0;
                stepen=1;
                while(stepen<X){
                        stepen=stepen*osnova;
                        pokazatel++;
                        if (stepen==X and pokazatel!=1){
                            cout<<osnova<<" "<<pokazatel<<"\n";
                        }
                }
        }
return 0;
}
