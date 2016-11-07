#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>

using namespace std;


string str;

string split(string x){
     string segment;
     vector<string> seglist;
     cin.getline(x, segment, '(' );
     return segment;
}




void divide(string x){
          vector<string> Arr[1000];
          for(int i=0;i<1000;i++){
                  Arr[0][i]=split(x);
                  }
          for(int i=0;i<=1000;i++){
                  cout<<Arr[0][i]<<endl;
                  }
          }






int main(int argc, char *argv[])
{
    string a;
    cin>>a;
    divide(a);
  //  system("PAUSE");
    return 0;
}
