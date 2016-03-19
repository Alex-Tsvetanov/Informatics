#include<iostream>
using namespace std;
int main()
{
long long a,b,c,br=4,br1=4,br2=4,ar=br;
cin>>a>>b>>c;
for(a; a>0; a--)
{
a--;
br++;
//cout<<a<<" ";
}
for(b; b>0; b--)
{
b=b-2;
br1++;
//cout<<b<<" ";
}for(c; c>0; c--)
{
c--;
br2++;
//cout<<c<<" ";
}
if(br>=br1 && br>=br2)
{
cout<<br+4;
}
else if(br1>=br && br1>=br2)
{
cout<<br1+3;
}
else if(br2>=br1 && br2>=br)
{
    cout<<br2+3;
}
return 0;
}
