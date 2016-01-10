#include<iostream>
#include<cmath>
#include<set>
#include<vector>
using namespace std;
set< vector<int> >combinations;
vector<int> combineTwoElementsOfVector(vector<int> vect,int a,int b){

    vector<int> ans,buff;
    while(!vect.empty()){
        buff.push_back(vect.back());
        vect.pop_back();
    }
    while(!buff.empty()){
        if(buff.size()==b){
            int added=buff[buff.size()-1]+buff[buff.size()-2];
            if(added==0){
                added=1;
            }
            ans.push_back(added);
            buff.pop_back();
            buff.pop_back();
        }else{
            ans.push_back(buff.back());
            buff.pop_back();
        }
    }
    return ans;
}
int firstToMerge(vector<int> vect){
    while(!vect.empty()){
        if(vect[vect.size()-1]==vect[vect.size()-2]){
            return vect.size()-1;
        }
        vect.pop_back();
    }
    return -1;
}
void combineStr(vector<int> current){
    combinations.insert(current);
    for(int br1=0;br1<current.size();br1++){
        vector<int> recursor;
        recursor=combineTwoElementsOfVector(current,firstToMerge(current)-1,firstToMerge(current));
        if(firstToMerge(current)==-1){
            return;
        }
        combineStr(recursor);
    }
    return;
}
int main(){
    int N;
    cin>>N;
    vector<int> test;
    for(int br1=0;br1<N;br1++){
        test.push_back(0);
    }
    combineStr(test);
    cout<<combinations.size()<<endl;
    return 0;
}
