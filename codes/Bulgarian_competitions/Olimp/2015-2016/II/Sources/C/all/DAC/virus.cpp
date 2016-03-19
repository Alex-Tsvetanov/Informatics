#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define MAXN 15
vector<int> vec[MAXN];
long long n;
long long pow2(long long u){
    long long p=1, i=0;
    do{
        if(p-1<u&&u<=p*2-1){
            return i+1;
        }
        i++;
        p*=2;
    }
    while(p<=u);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if(n>500){
        cout<<pow2(n)<<endl;
    }
    else{
        long long k=1;
        long long p=pow2(n);
        for(long long j=1;j<=p;j++){
            for(long long i1=0;i1<p;i1++){
                if(j>1){
                for(long long i2=i1+1;i2<p;i2++){

                    if(j>2){

                    for(long long i3=i2+1;i3<p;i3++){

                        if(j>3){
                        for(long long i4=i3+1;i4<p;i4++){

                            if(j>4){
                            for(long long i5=i4+1;i5<p;i5++){

                                if(j>5){
                                for(long long i6=i5+1;i6<p;i6++){

                                    if(j>6){
                                    for(long long i7=i6+1;i7<p;i7++){

                                        if(j>7){
                                        for(long long i8=i7+1;i8<p;i8++){

                                            if(j>8){
                                            for(long long i9=i8+1;i9<p;i9++){

                                                if(j>9){
                                                for(long long i10=i9+1;i10<p;i10++){

                                                    if(i1!=i2&&i1!=i3&&i1!=i4&&i1!=i5&&i1!=i6&&i1!=i7&&i1!=i8&&i1!=i9&&i1!=i10&&j==10&&k!=n+1){

                                                        vec[i1].push_back(k);
                                                        vec[i2].push_back(k);
                                                        vec[i3].push_back(k);
                                                        vec[i4].push_back(k);
                                                        vec[i5].push_back(k);
                                                        vec[i6].push_back(k);
                                                        vec[i7].push_back(k);
                                                        vec[i8].push_back(k);
                                                        vec[i9].push_back(k);
                                                        vec[i10].push_back(k);
                                                        k++;

                                                    }
                                                }
                                                }
                                                if(i1!=i2&&i1!=i3&&i1!=i4&&i1!=i5&&i1!=i6&&i1!=i7&&i1!=i8&&i1!=i9&&j==9&&k!=n+1){

                                                        vec[i1].push_back(k);
                                                        vec[i2].push_back(k);
                                                        vec[i3].push_back(k);
                                                        vec[i4].push_back(k);
                                                        vec[i5].push_back(k);
                                                        vec[i6].push_back(k);
                                                        vec[i7].push_back(k);
                                                        vec[i8].push_back(k);
                                                        vec[i9].push_back(k);
                                                        k++;

                                                    }

                                            }
                                            }
                                            if(i1!=i2&&i1!=i3&&i1!=i4&&i1!=i5&&i1!=i6&&i1!=i7&&i1!=i8&&j==8&&k!=n+1){

                                                        vec[i1].push_back(k);
                                                        vec[i2].push_back(k);
                                                        vec[i3].push_back(k);
                                                        vec[i4].push_back(k);
                                                        vec[i5].push_back(k);
                                                        vec[i6].push_back(k);
                                                        vec[i7].push_back(k);
                                                        vec[i8].push_back(k);
                                                        k++;

                                                    }
                                        }
                                        }
                                        if(i1!=i2&&i1!=i3&&i1!=i4&&i1!=i5&&i1!=i6&&i1!=i7&&j==7&&k!=n+1){

                                                        vec[i1].push_back(k);
                                                        vec[i2].push_back(k);
                                                        vec[i3].push_back(k);
                                                        vec[i4].push_back(k);
                                                        vec[i5].push_back(k);
                                                        vec[i6].push_back(k);
                                                        vec[i7].push_back(k);
                                                        k++;

                                                    }
                                    }
                                    }
                                    if(i1!=i2&&i1!=i3&&i1!=i4&&i1!=i5&&i1!=i6&&j==6&&k!=n+1){

                                                        vec[i1].push_back(k);
                                                        vec[i2].push_back(k);
                                                        vec[i3].push_back(k);
                                                        vec[i4].push_back(k);
                                                        vec[i5].push_back(k);
                                                        vec[i6].push_back(k);
                                                        k++;

                                                    }
                                }
                                }
                                if(i1!=i2&&i1!=i3&&i1!=i4&&i1!=i5&&j==5&&k!=n+1){

                                                        vec[i1].push_back(k);
                                                        vec[i2].push_back(k);
                                                        vec[i3].push_back(k);
                                                        vec[i4].push_back(k);
                                                        vec[i5].push_back(k);
                                                        k++;

                                                    }
                            }
                            }
                            if(i1!=i2&&i1!=i3&&i1!=i4&&i2!=i3&&i4!=i3&&i2!=i4&&j==4&&k!=n+1){

                                                        vec[i1].push_back(k);
                                                        vec[i2].push_back(k);
                                                        vec[i3].push_back(k);
                                                        vec[i4].push_back(k);
                                                        k++;

                                                    }
                        }
                        }
                        if(i1!=i2&&i1!=i3&&i2!=i3&&j==3&&k!=n+1){

                                                        vec[i1].push_back(k);
                                                        vec[i2].push_back(k);
                                                        vec[i3].push_back(k);
                                                        k++;

                                                    }
                    }
                    }

                    if(i1!=i2&&j==2&&k!=n+1){

                        vec[i1].push_back(k);
                        vec[i2].push_back(k);

                        k++;

                    }
                }
                }
                if(j==1&&k!=n+1){

                vec[i1].push_back(k);
                k++;

                }
            }

        }
        cout<<p<<endl;
            for(long long j=0;j<p;j++){
                cout<<vec[j].size()<<" ";
                for(long long i=0;i<vec[j].size();i++){
                    cout<<vec[j][i];
                    if(i==vec[j].size()-1) cout<<"\n";
                    else cout<<" ";
                }
            }

    }
return 0;
}
