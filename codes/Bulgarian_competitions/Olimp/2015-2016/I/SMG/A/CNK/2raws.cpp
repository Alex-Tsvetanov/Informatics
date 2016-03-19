#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> r1,r2,r3;
vector<long long>r4,r5;
int n1,n2;
bool slivaema;
bool cmp(long long a,long long b) {return r1[a]>r1[b];}
bool cmp2(long long a,long long b) {return r2[a]>r2[b];}
int main()
{
    for(int i=0;i<5;i++){

    slivaema=1;
    cin>>n1;
    for(int input,i=0;i<n1;i++)
    {
        cin>>input;
        r1.push_back(input);
        r4.push_back(i);
    }
    cin>>n2;
    for(int input,i=0;i<n2;i++)
    {
        cin>>input;
        r2.push_back(input);
        r5.push_back(i);
    }
    sort(r4.begin(),r4.end(),cmp);
    sort(r5.begin(),r5.end(),cmp2);
    for(int i=0,j=0;i<n1||j<n2;)
    {
        if(i==n1){r5[j]=-1;j++;}else
        if(j==n2){r4[i]=-1;i++;}else
        {
            if(r1[r4[i]]==r2[r5[j]]){i++;j++;}else
            if(r1[r4[i]]>r2[r5[j]]){r4[i]=-1;i++;}else{r5[j]=-1;j++;}
        }
    }
    sort(r4.begin(),r4.end());
    sort(r5.begin(),r5.end());
    for(int i=0,j=0;i<n1&&j<n2;)
    {
        if(r5[j]==-1){j++;}else
        if(r4[i]==-1){i++;}else
        {
            if(r1[r4[i]]==r2[r5[j]]){i++;j++;}else{slivaema=0;break;}
        }
    }
    cout<<slivaema;

    /*for(int i=0;i<n1;i++)
    {
        cout<<r4[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n2;i++)
    {
        cout<<r5[i]<<" ";
    }
    cout<<"\n";*/

    r1.resize(0);
    r2.resize(0);
    r3.resize(0);
    r4.resize(0);
    r5.resize(0);

    }
    cout<<"\n";
    return 0;
}
/*
3 1 2 3
4 1 3 5 6
3 5 1 4
4 150 1 20 5
4 1 5 6 2
3 2 1 6
5 100 20 45 10 3
4 3 100 80 10
5 90 1 4 8 80
5 90 1 8 100 5
*/
