#include<iostream>
#include<string>
using namespace std;
long long a,b,br=0,d,r=0,d1,j,v,brvs,brb;
int main()
{
string s,ss,m;
cin>>s;
s='.'+s;
d=s.size();
for(int i=1;i<d;i++){

    if(s[i]==s[i-1]){
        br++;


    }
    else{
        if(br>1){

         while(br>9){
            v++;
            br=br/10;
         }
         v++;
         brvs=brvs+v+1;

        }
        else brvs=brvs+1;
        br=1;
        v=0;

    }

}

int r=d-2;
int k=(brvs-brb)-1;
cout<<r-k<<endl;
return 0;

}
