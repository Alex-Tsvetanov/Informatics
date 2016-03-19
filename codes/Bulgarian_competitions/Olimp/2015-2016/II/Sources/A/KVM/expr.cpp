#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string inP;
bool info[26]= {0};

void correct() ///funkciq za korigirane na input stringa
{
    int temp=0,it=0 ,tempCur;
    int flag=0;

    for(int i=0; i<inP.length(); i++)
    {
        if(inP[i]>='a'&&inP[i]<='z')
        {
            int tempCur=(int)(inP[i]-'a');
            if(tempCur!=0) inP[i]='a';
            it=i;
            break;
        }
    }


    for(int i=it; i<inP.length(); i++)
    {
        if(inP[i]>='a'&&inP[i]<='z')
        {
            tempCur=(int)(inP[i]-'a');

            if(tempCur-temp>1||tempCur-temp<0&&tempCur!=0)
            {
                inP[i]=(char)(temp+1+'a');
                temp++;
            }
            else temp++;
            if(tempCur==0)
            {
                temp=0;
                continue;
            }
        }
        else flag++;
    }
    if(flag==0)
    {
        inP='('+inP;
        inP=inP+inP[inP.length()-1];
        inP[inP.length()-2]=')';
    }
    cout<<tempCur<<endl;
}



void solve()
{




}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>inP;
    correct();
    cout<<inP;
    return 0;
}




/*cout<<"--------------------------------------"<<endl;
             cout<<"TEMP current equals to: "<<tempCur<<endl;
             cout<<"Temp equals to: "<<temp<<endl;
             cout<<"--------------------------------------"<<endl;
             */
