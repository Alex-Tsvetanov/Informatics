#include<iostream>
#include<cstring>
int main()
{
    std::string text;
    std::cin>>text;
    int res=0, i=0;
    while(i<text.size())
    {
        char a = text[i];
        bool col = false;
        if(i!=0)
        {
            a = text[i];
            if(a!=text[i-1])
            {
                ++i;
                res+=1*col;
                col=false;
            }
            else
            {
                text.erase(text.begin()+i); --i;
                text.erase(text.begin()+i);
                col=true;
            }
        }
        else
        {
            ++res;
            ++i;
        }
        a = text[i];
        if(i>=2&&a==text[i-2])
        {
            text.erase(text.begin()+i); --i;
            text.erase(text.begin()+i); --i;
            text.erase(text.begin()+i);
            col=true;
        }
    }
    std::cout<<res+text.size()-1<<'\0';
    return 0;
}
