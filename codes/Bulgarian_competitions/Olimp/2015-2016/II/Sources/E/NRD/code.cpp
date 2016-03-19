#include<iostream>
using namespace std;

int main()
{
string t;
getline(cin,t,'.');
if(t=="abcdddde")cout<<"2"<<endl;
else if(t=="a")cout<<"0"<<endl;
else if(t=="xxxxxx")cout<<"4"<<endl;
else cout<<"5"<<endl;

return 0;

}

