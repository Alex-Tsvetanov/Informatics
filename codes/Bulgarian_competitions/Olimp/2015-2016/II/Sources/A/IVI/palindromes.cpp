#include <iostream>
#include <string>
using namespace std;
string s;
int br;

bool ispalindrome ()
{
    int l=0,r=s.size()-1;
    while(l<r)
    {
        if (s[l]!=s[r]) return false;
        l++; r--;
    }
    return true;
}


void findlongest (string a)
{
    int n=a.size();
    n=2*n+1;
    int l[n];
    l[0]=0;l[1]=1;
    int c=1,r=2,i=0,ii,maxlen=0,maxpos=0,start=-1,endd=-1,diff=-1;
    for (i=2;i<n;i++)
    {
        ii=2*c-i;
        l[i]=0;
        diff=r-i;
        if (diff>0) l[i]=min(l[ii], diff);

        while ( ( (i+l[i])<n && (i-l[i])>0 &&
                 (((i+l[i]+1)%2==0)||(a[(i+l[i]+1)/2]==a[(i-l[i]-1)/2]) )))
               {
                   l[i]++;
               }
        if (l[i]>maxlen)
            {
                maxlen=l[i];
                maxpos=i;
            }
        if (i+l[i]>r)
        {
            c=i;
            r=i+l[i];
        }
    }
    start=(maxpos-maxlen)/2;
    endd=start+maxlen-1;


    /*
    for (i=start;i<=endd;i++) cout<<s[i];
    cout<<endl;
    cout<<s<<endl;
    */

    int sz=a.size();
    if (sz>1) a.erase (start, endd-start+1);
    else {br++;return;}
    br++;
    if (!a.empty()) findlongest(a);

}
int main()
{
    cin>>s;
    if (ispalindrome()) {cout<<0<<endl;return 0;}
    else findlongest(s);
    cout<<br-1<<endl;
    return 0;
}
