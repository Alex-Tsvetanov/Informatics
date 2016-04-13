#include<iostream>
using namespace std;
int n,m,vhod[501][2],result=0,listOfFriends[501][500],reached[500],lastMemory=1,indexOfMissed[501],numberOfMissed=0;
bool alreadyChecked[501];
bool checkANDaddToTheGroup(int x){
    bool returnTrue=false;
    for(int i=0;i<reached[x];i++){
        if(!alreadyChecked[listOfFriends[x][i]]){
        alreadyChecked[listOfFriends[x][i]]=true;
        returnTrue=true;
        }
    }
    return returnTrue;
}

int main(){

    for(int y=0;y<n;y++){
        indexOfMissed[y]=-1;
    }

reached[1]=0;
cin>>n>>m;
for(int i=0;i<m;i++){
    cin>>vhod[i][0]>>vhod[i][1];
    if(i==0){alreadyChecked[vhod[i][0]]=true;}

    if(lastMemory!=vhod[i][0]){
        lastMemory=vhod[i][0];
        reached[lastMemory]=0;
    }
    if(lastMemory==vhod[i][0]){
        listOfFriends[lastMemory][reached[lastMemory]]=vhod[i][1];
        reached[lastMemory]++;

    }

}
bool skipOnce=true;
bool breakAll=false;
do{
result++;
if(skipOnce){
    skipOnce=false;
}else{
    if(indexOfMissed[0]>=0){
    alreadyChecked[indexOfMissed[0]]=true;
    checkANDaddToTheGroup(indexOfMissed[numberOfMissed]);
    }
}

for(int y=0;y<numberOfMissed;y++){
    indexOfMissed[y]=-1;

}
numberOfMissed=0;
/*
6 4
1 3
1 4
2 5
4 6
*/

for(int i=1;i<=n;i++){
    if(!alreadyChecked[i]){
        indexOfMissed[numberOfMissed]=i;
        numberOfMissed++;
    }

}
for(int i=1;i<=n;i++){
    if(alreadyChecked[i]){
        if(checkANDaddToTheGroup(i)){
            i=1;

        }
    }else{

    }

}
}while(numberOfMissed!=0);
int memory=result;
if(result%2!=0){
result+=1;
}
result=result/2;
cout<<result<<endl;
return 0;
}
