#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main () {
    int min_el=1000001;
    int max_el=0;
    int min_pos[20001];
    int max_pos[20001];
    int a[20001];
    int N;
    int min_index=0;
    int max_index=0;
    cin>>N;
    int case1;
    int case2;
    for (int i=0;i<N;i++){
        cin>>a[i];
    }
    for (int i=0;i<N;i++){
        if (a[i]<min_el) min_el=a[i];
        if (a[i]>max_el) max_el=a[i];
    }
for (int i=0;i<N;i++){
    if (a[i]==min_el) {min_pos[min_index]=i+1;min_index++;}
    if (a[i]==max_el) {max_pos[max_index]=i+1;max_index++;}
}
case1=abs(min_pos[0]-max_pos[max_index-1]);
case2=abs(min_pos[min_index-1]-max_pos[0]);
if (case1>case2) cout<<min_pos[0]<<" "<<max_pos[max_index-1]<<endl;
if (case2>case1) cout<<max_pos[0]<<" "<<min_pos[min_index-1]<<endl;
if (case1==case2){
    if (min_pos[0]+max_pos[max_index-1]>min_pos[min_index-1]+max_pos[0]) cout<<min_pos[min_index-1]<<" "<<max_pos[0]<<endl;
    else cout<<min_pos[0]<<" "<<max_pos[max_index-1]<<endl;
}
return 0;
}
