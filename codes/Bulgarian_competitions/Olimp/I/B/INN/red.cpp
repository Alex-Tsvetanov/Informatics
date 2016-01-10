#include <iostream>
using namespace std;

int n;
int mi=1000001,ma,c;
int index_max_end,index_max_start
   ,index_min_end,index_min_start;

int main (){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c;
        if(mi>c){
            mi = c;
            index_min_start = i;
        }
        if(mi==c){
            index_min_end = i;
        }
        if(ma<c){
            ma = c;
            index_max_start = i;
        }
        if(ma==c){
            index_max_end = i;
        }
    }
    index_max_end++;
    index_max_start++;
    index_min_end++;
    index_min_start++;

    if(index_max_end - index_min_start >
       index_min_end - index_max_start){

        cout<<index_min_start<<" "<<index_max_end<<endl;

    }else{
        if(index_max_end - index_min_start ==
           index_min_end - index_max_start){
            if(index_min_start<index_max_start){
                cout<<index_min_start<<" "<<index_max_end<<endl;
            }else{
                cout<<index_max_start<<" "<<index_min_end<<endl;
            }
        }else{
            cout<<index_max_start<<" "<<index_min_end<<endl;
        }
    }
    return 0;
}
