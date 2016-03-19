#include<iostream>

using namespace std;

int main(){

unsigned long long K;
int num = 0;
cin>>K;
int a[K];
int b[K];


        for(int z = 1; z<K; z++){
        for(int y = 1; y <K; y++){

            for(int sch = 1; sch<K; sch++){
                if(((2*y + 1)*z+y == K+sch && y!=0 && z != 0 && ((y<z && ((y == sch-1 && y>1)||( y == 1 && y == sch) )) ||(z<y && sch == 2*z) || (z == y && sch == z+y-1) ))){

                a[num] = z;
                b[num] = y;
                num++;
            }
            }
    }
        }
cout<<num<<endl;
for(int i =0; i<num; i++){
cout<<a[i]<<" "<<b[i]<<endl;
}





return 0;
}
