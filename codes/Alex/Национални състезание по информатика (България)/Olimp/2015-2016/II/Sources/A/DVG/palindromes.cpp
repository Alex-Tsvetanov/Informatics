#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    cin>>a;
    int b = 0;
    int broi = -1;
    int maxPali;
    int stillInLastOne=0;
    int lastBigOne = 0;
    for(int i=0;i<a.size();i++){
        b = a[i];
        maxPali=0;
        //cout<<"-----Begin-------"<<(char)b<<"    "<<(char)a[i+1]<<endl;
        for(int j = i+1;j<a.size();j++){
            //cout<<"-----what you see is what you get-------"<<(j-i+1)%2<<"   "<<(j-i+1)<<"  "<<j<<" "<<i<<endl;
            if((j-i+1)%2!=0){


                //cout<<"-----it is uneven-------"<<"   "<<b<<"  "<<(maxPali<j-i+1)<<endl;

                b = b xor (a[j]);
                if((char)b == a[(j-i+1)/2] && maxPali<j-i+1 && a[i]==a[j]){
                    maxPali=j-i+1;
                }
            }else{
                b = b xor (a[j]);
                //cout<<"-----it is even-------"<<"   "<<b<<"  "<<(maxPali<j-i+1)<<endl;
                if(b == 0 && maxPali<j-i+1 && a[i]==a[j]){
                    maxPali = j-i+1;
                    //cout<<"broke it"<<endl;
                    //break;
                }
            }
            //cout<<j<<"    "<<(char)b<<endl;
        }
        if(maxPali>0){
            //cout<<"found one with size  "<<maxPali<<"   index from old one  "<<stillInLastOne<<endl;
            stillInLastOne--;
            if(stillInLastOne>0){
                if(maxPali>lastBigOne){
                    lastBigOne=maxPali;
                    stillInLastOne = maxPali;
                    //cout<<"found one with size  "<<maxPali<<endl;
                    //i+=maxPali-1;
                    broi++;
                }

            }else {
                lastBigOne=maxPali;
                stillInLastOne = maxPali;
                broi++;
            }
        }else{
            stillInLastOne--;
            if(stillInLastOne<=0){
                //cout<<"no palindromes with this one   "<<a[i]<<endl;
                broi++;
            }
        }

        //cout<<endl<<b<<endl;
    }
    cout<<broi;
}
