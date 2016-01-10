#include <iostream>
#include <stack>
using namespace std;
int main () {
stack <int> Binary;
int N;
cin>>N;
int numbers[100];
int stepeni[100];
int c=0;
int br=0;
int numbers_c;
while (N>0){
    Binary.push(N%2);
    N/=2;
}
while (!Binary.empty()){
    if(Binary.top()==1){
    numbers[c]=2;
    stepeni[c]=Binary.size()-1;
    c++;
    }
    Binary.pop();
}
numbers_c=c;
for (int i=0;i<numbers_c-1;){
    if (stepeni[i]>stepeni[i+1]){
        br++;
        numbers_c+=1;
        stepeni[i]--;
    }
if (stepeni[i]==stepeni[i+1]) i++;
}
c=numbers_c;
for (int i=0;i<c;i++){
while (stepeni[i])
}
cout<<br<<endl;
return 0;
}
