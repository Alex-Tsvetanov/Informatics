#include<iostream>
using namespace std;
int main(){
    int k=0;
    cin>>k;
    double w,h1,h2;
    int res=0;
    for(w=1.0;w<k/2;w++){
        h1=(k+w-1)/(2*w+1);
        h2=(k-w)/(2*w-1);
        if(h1-(double)((int) h1)==0 && w<=h1){
            //cout<<w<<" "<<h1<<endl;
            res++;
        }
        if(h2-(double)((int) h2)==0 && h2<w){
            //cout<<w<<" "<<h2<<endl;
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
