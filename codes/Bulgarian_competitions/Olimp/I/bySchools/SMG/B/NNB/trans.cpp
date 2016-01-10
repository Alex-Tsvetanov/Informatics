#include<iostream>
#include<vector>
using namespace std;
long long p;
int a1 [50000001], a2[50000001], m , k , help1, help2 ,help;
vector <int> izh;
bool dis;
int main(){
cin >> p >>m;
for (int i = 0; i<m; i++){
    cin>>help1>>help2;
    if(help1%2) a2[help1 / 2] ++;
    else a1[help1 / 2] ++;
    if(help2%2) a2[help2 / 2] ++;
    else a1[help2 / 2] ++;
}
cin>>k;
for(int i = 1; i<=p; i++){
        if(i % 2){
            if (a2 [i / 2] >=k){
                izh.push_back (i);

            }

        }else {
            if(a1 [1 / 2] >=k){
                izh.push_back (i);
            }
        }
}
cout<<endl;
help = izh.size ();
cout << help;
for(int i = 0; i < help; i++ ){
    if(dis) cout <<" ";
    else cout << endl;
    dis=true;
    cout << izh [i];

}







return 0;
}
