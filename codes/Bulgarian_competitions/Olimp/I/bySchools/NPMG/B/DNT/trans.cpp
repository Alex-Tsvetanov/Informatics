#include<iostream>
#include<vector>
using namespace std;
int P,M,K,answer;
int nVruzki[100005];
vector<int> answerP;
int main(){
    cin>>P>>M;
    for(int br1=1;br1<=M;br1++){
        int townA,townB;
        cin>>townA>>townB;
        nVruzki[townA]++;
        nVruzki[townB]++;
    }
    cin>>K;

    for(int br1=P;br1>=1;br1--){
        if(nVruzki[br1]>=K){
            answer++;
            answerP.push_back(br1);
        }
    }
    if(answer>0){
        cout<<answer<<endl;
        for(;!answerP.empty();answerP.pop_back()){
            cout<<answerP.back()<<" ";
        }
    }else{
        cout<<0;
    }
    cout<<endl;
    return 0;
}
