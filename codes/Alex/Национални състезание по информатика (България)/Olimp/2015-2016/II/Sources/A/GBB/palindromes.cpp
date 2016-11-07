#include<iostream>
#include<string>
using namespace std;
int pi[100005];
void prefix_function(string s)
{
	int i, j=0, sz=s.size();
	for(i=1;i<sz;i++)
    {
		while(j>0 && s[i]!=s[j])
        {
            j=pi[j-1];
        }
		if(s[i]==s[j])
        {
            j++;
        }
		pi[i]=j;
	}
}
int main()
{
    int i, sz;
    bool l=1;
    string s;
    cin>>s;
    sz=s.size();
    for(i=0;i<sz/2;i++)
    {
        if(s[i]!=s[sz-i-1])
        {
            l=0;
            break;
        }
    }
    if(l)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<1<<endl;
    }
    return 0;
}
