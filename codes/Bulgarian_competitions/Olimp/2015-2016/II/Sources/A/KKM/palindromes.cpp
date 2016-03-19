#include <iostream>
using namespace std;

int dp[50][10000], dpMin, dpBr;

int main()
{
string n;
int palindrom[10000][2], palindromBr=0, len;
bool flag;
int flag1;

cin>>n;

for(int i=0; i<n.size(); i++)
{
    /*
    palindrom[palindromBr][0]=i;
    palindrom[palindromBr][1]=i;
    palindromBr++;
*/
    if(n[i]==n[i+1])
    {
        palindrom[palindromBr][0]=i;
        palindrom[palindromBr][1]=i+1;
        palindromBr++;
        len=0;
        flag=true;
        while(flag==true)
        {
            len++;
            //if(i-len<0){flag=false; break;}


            if(n[i-len]==n[i+len+1])
            {
                palindrom[palindromBr][0]=i-len;
                palindrom[palindromBr][1]=i+len+1;
                palindromBr++;
            }
            else
            {
            flag=false;
            }
        }
    }

    if(n[i-1]==n[i+1])
    {
        palindrom[palindromBr][0]=i-1;
        palindrom[palindromBr][1]=i+1;
        palindromBr++;
        len=0;
        flag=true;
        while(flag==true)
        {
            len++;
            //if(i-len-1<0){flag=false; break;}


            if(n[i-len-1]==n[i+len+1])
            {
                palindrom[palindromBr][0]=i-len-1;
                palindrom[palindromBr][1]=i+len+1;
                palindromBr++;
            }
            else
            {
            flag=false;
            }
        }
    }
}

dpMin=n.size();

for(int i=0; i<palindromBr; i++)
{
   // cout<<palindrom[i][0]<<" "<<palindrom[i][1]<<endl;

    flag1=1;
    dpBr=0;

    for(int j=palindrom[i][0]; j<=palindrom[i][1]; j++)
    {
            dp[i][j]=1;
            //cout<<dpBr<<endl;
    }


    for(int k=i+1; k<palindromBr; k++)
    {

        if(dp[i][palindrom[k][0]]==0 && dp[i][palindrom[k][1]]==0)
        {
            for(int j=palindrom[k][0]; j<=palindrom[k][1]; j++)
            {
            dp[i][j]=1;
            dpBr++;
            }
        }

        if(dpBr>=dpMin)
        {
            flag1=0;
            break;
        }

    }
    if(flag1!=0)
    {
        for(int j=0; j<n.size(); j++)
        {
        if(dp[i][j]==0)
        {
            dpBr++;
        }
        }

        if(dpBr<dpMin)dpMin=dpBr;

    }

}

cout<<dpMin<<endl;


return 0;
}
