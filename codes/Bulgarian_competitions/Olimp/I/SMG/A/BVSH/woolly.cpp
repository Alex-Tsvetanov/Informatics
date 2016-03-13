#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>

using namespace std;

char res[61];
string a,b;


void rec(int aInd, int bInd, int resInd, int prenos)
{
    if(aInd<0&&bInd<0)return;
    if(a[aInd]!='?'&&b[bInd]!='?')
    {
        int local = a[aInd]-'0'+b[bInd]-'0' + prenos;
        switch(local%2)
        {
        case 0:
            res[resInd] = '0';
            break;
        case 1:
            res[resInd] = '1';
            break;
        }
        local -= local%2*2;
        rec(aInd-1,bInd-1,resInd-1,local);
    }
    else if(a[aInd]=='?')
    {
    }
}

int resInd = 60;
void cc()
{
    if(a.size()<b.size())
    {
        swap(a,b);
    }

    int r = a.size()- b.size();
    bool prenos = false;

    for(int i = a.size()-1; i>=0; i--,resInd--)
    {
        if(i-r>=0)
            switch(a[i])
            {
            case '0':
                switch(b[i-r])
                {
                case '0':
                    if(prenos==false)
                    {
                        res[resInd] = '0';
                    }
                    else
                    {
                        prenos=false;
                        res[resInd] = '1';
                    }
                    break;
                case '1':
                    if(prenos == false)
                    {
                        res[resInd] = '1';
                    }
                    else
                    {
                        prenos = true;
                        res[resInd] = '0';
                    }
                    break;
                }
                break;
            case '1':
                switch(b[i-r])
                {
                case '0':
                    if(prenos == false)
                    {
                        res[resInd] = '1';
                    }
                    else
                    {
                        prenos = true;
                        res[resInd] = '0';
                    }
                    break;
                case '1':
                    if(prenos == false)
                    {
                        prenos = true;
                        res[resInd] = '0';
                    }
                    else
                    {
                        prenos = true;
                        res[resInd] = '1';
                    }
                    break;
                }
                break;

            }
        else
        {
            switch(a[i])
            {
            case '0':
                if(prenos == false)
                {
                    res[resInd] = '0';
                }
                else
                {
                    prenos = false;
                    res[resInd] = '1';
                }
                break;
            case '1':
                if(prenos == false)
                {
                    prenos = true;
                    res[resInd] = '1';
                }
                else
                {
                    prenos = true;
                    res[resInd] = '0';
                }
                break;
            }
        }
    }
    if(prenos==true)
    {
        res[resInd] = '1';
    }
}
bool hasVuprr()
{
    bool hasVupr = false;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]=='?')
        {
            hasVupr = true;
            break;
        }
    }
    if(!hasVupr)
    {
        for(int i=0; i<b.size(); i++)
        {
            if(b[i]=='?')
            {
                hasVupr = true;
                break;
            }
        }
    }
    return hasVupr;
}
void bezVupr()
{
    cc();
    for(int i = resInd; i<61; i++)
    {
        if(res[i] == '\0')break;
        cout<<res[i];
    }
}

int main()
{
    cin>>a>>b;
    if(!hasVuprr())bezVupr();
    else{
        int local = max(a.size(),b.size());
        for(int i=0;i<local;i++)
        {
            cout<<"?";
        }
    }
    cout<<endl;

    return 0;
}
