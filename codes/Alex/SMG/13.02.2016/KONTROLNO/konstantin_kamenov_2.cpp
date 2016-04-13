#include<iostream>
using namespace std ;
bool nums[1000];
int main (  ) {
    int n;
    unsigned long long k;
    cin>>n>>k;
    k--;
    unsigned long long a=1;
    for(int i=0;i<n-1;i++){
    a*=(26-i);
    }
    for(int i=0;i<n-1;i++){
        int index=k/a;
        int tots=0;
        for(int j=0;j<=index;j++){
            index+=nums[j];
            if(nums[j]==true){
                tots++;
            }
        }
        nums[index]=true;
        k=k-((index-tots)*a);
        a=a/(26-i);
        cout<<(char)('A'+index);
    }
    int cn=0;
    for(int i=0;i<26;i++){
        if(nums[i]==0){
            if(cn==k){
                cout<<(char)('A'+i);
            }
            cn++;
        }
    }
    cout<<endl;
    return 0 ;
}
