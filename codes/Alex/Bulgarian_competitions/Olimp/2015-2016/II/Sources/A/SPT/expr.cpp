#include<iostream>
#include<string>
using namespace std;
char a[1001],b[26];
string answer="";
int length=0,i=0;
bool x,var[26];

void skip()
{
    int counter=1;
    if(a[i]>='a'&&a[i]<='z')
    {
        counter=0;
    }
    ++i;
    while(counter)
    {
        if(a[i]=='(')
        {
            ++counter;
        }
        if(a[i]==')')
        {
            --counter;
        }
        //cout<<"|||i:"<<i<<";counter:"<<counter<<";\n";
        ++i;
        if(i>30){return;}
    }
    //cout<<"skipped to: "<<i<<"; ";
    return;
}


bool calc()
{
    //cout<<i<<' ';
    bool value;
    if(a[i]>='a'&&a[i]<='z')
    {
        value=var[a[i]-'a'];
        ++i;
    }
    else
    {
        ++i;
        value=calc();
    }
    //cout<<i<<": set initial value: "<<value<<" ---- ";
    while(a[i]!=')')
    {
        if(!value)
        {
            //cout<<" "<<i<<": value=1;\n";
            value=1;
            skip();
        }
        else
        {
            value=!calc();
            //cout<<" "<<i<<": calcvalue="<<value<<";\n";
        }
        //cout<<i<<' ';
        if(i>30){return 0;}
    }
    //cout<<" :"<<value<<": ";
    return value;
}











int main()
{
    cin>>a;
    while(a[length]!='\0')
    {
        ++length;
    }
    a[length]=')';
    a[length+1]='\0';
    cin>>b;
    for(int asdf=0;b[0]!='2';++asdf)
    {
        i=0;
        for(int j=0;b[j]!='\0';++j)
        {
            var[j]=b[j]-'0';
            //cout<<var[j]<<" ";
        }
        //cout<<"\n";
        x=calc();
        //cout<<x<<'\n';
        if(x)
        {
            answer+="1";
        }
        else
        {
            answer+="0";
        }
        cin>>b;
    }
    answer+="\n";
    cout<<answer;
    return 0;
}
