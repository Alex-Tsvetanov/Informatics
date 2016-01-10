#include<iostream>
#include<stack>
using namespace std;
stack<char>st;
string str="";
long long pow(int a)
{
    long long otg=10;
    for(int i=1;i<a;i++)
        otg*=10;
    return otg;
}
long long otg;
int main(){
int n;
cin>>n;
if(n==1)
{
    cout<<1<<endl;
    return 0;
}
while(n>0)
{
    st.push(n%2+'0');
    n/=2;
}
while(!st.empty())
{
    str+=st.top();
    st.pop();
}
for(int i=0;i<str.size();i++)
{
    long long chislo, curr=1;
    if(str[i]=='1')
    {

        chislo=pow(str.size()-i)/10;
      //  cout<<chislo<<endl;
    }
    if(chislo>1)
    {
        while(chislo>0)
        {
            curr*=2;
            chislo/=10;
        }
        //cout<<"curr: "<<curr/2<<endl;
        otg+=curr/2;
    }
}
cout<<otg<<endl;
return 0;
}

