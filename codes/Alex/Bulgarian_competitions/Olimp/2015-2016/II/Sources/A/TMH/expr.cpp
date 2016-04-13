#include <stdio.h> ///Todor Milenov Hristov
#include <stack>

using namespace std;

char string1[1024];
char string[1024];
int size;
stack<char> st1;
stack<char> st2;
char input[30];
char conv[1024];
int pconv;
char ans[1024];
int pans;

stack<int> use;

int Yes(char c1, char c2)
{
    if(c1>='a' && c1<='z' && c2>='a' && c2<='z') return 1;
    if(c1=='(' && c2>='a' && c2<='z') return 1;
    if(c1>='a' && c1<='z' && c2==')') return 1;
    if(c1=='(' && c2==')') return 1;
    return 0;
}

int Do(int a,int b)
{
    if(a==1 && b==1) return 0;
    return 1;
}

int main()
{
    int a;
    int b;

    scanf("%s", &string1);

    string[0]=string1[0];
    for(a=1,b=1;string1[a]!=0;a++,b++)
    {
        if(Yes(string1[a],string1[a-1]))
        {
            string[b]='.';
            b++;
        }
        string[b]=string1[a];
    }

    for(a=0;a<10002;a++)
    {
        if(string[a]==0)
        {
            size=a;
            break;
        }
    }

    for(a=0;a<size;a++)
    {
        if(string[a]>='a' && string[a]<='z') st2.push(string[a]);
        if(string[a]=='.') st1.push(string[a]);
        else if(string[a]=='(')
        {
            if(st1.size()) while(st1.top()!='(')
            {
                st2.push(st1.top());
                st1.pop();
                if(!st1.size()) break;
            }
            st1.push(string[a]);
        }
        else if(string[a]==')')
        {
            while(st1.top()!='(')
            {
                st2.push(st1.top());
                st1.pop();
                if(!st1.size()) break;
            }
            if(st1.size()) st1.pop();
        }
    }
    while(st1.size())
    {
        st2.push(st1.top());
        st1.pop();
    }

    while(st2.size())
    {
        conv[pconv]=st2.top();
        pconv++;
        st2.pop();
    }
    int flag=0;
    for(a=0;conv[a]!=0;a++)
    {
        if(conv[a]=='.') flag++;
        else if(conv[a]>='a' && conv[a]<='z')
        {
            ans[pans]=conv[a];
            pans++;
            if(!(conv[a+1]>='a' && conv[a+1]<='z'))
            {
                for(b=0;b<flag;b++)
                {
                    ans[pans]='.';
                    pans++;
                }
                flag=0;
            }
        }
    }

    ///printf("%s", ans);

    ///-----------------------------------------------------------------------------------------------------------------
    int result;
    while(true)
    {
        scanf("%s", &input);
        if(input[0]=='2') return 0;
        for(a=0;a<pans;a++)
        {
            if(ans[a]>='a' && ans[a]<='z') use.push(input[ans[a]-'a']-'0');
            else
            {
                result=use.top();
                use.pop();
                result=Do(result,use.top());
                use.pop();
                use.push(result);
            }
        }
        printf("%d",use.top());
        while(use.size()){use.pop();}
    }

    printf("\n");


    return 0;
}
