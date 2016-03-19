#include<iostream>
using namespace std;
int main()
{
    int mas[20000], n, max=-1, min=1000001, x, y, maxbr=0, maxw=2000001;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>mas[i];
        if(max<mas[i]) max=mas[i];
        if(min>mas[i]) min=mas[i];
    }
        for(int i=0; i<n; i++)
        {
            if(mas[i]==min||mas[i]==max)
            {
                for(int j=i+1; j<n; j++)
                {
                    if(mas[i]==min&&mas[j]==max&&j-i>maxbr)
                    {
                        maxbr=j-i;
                        x=i;
                        y=j;
                        j=n;
                    }
                    if(mas[i]==max&&mas[j]==min&&j-i>maxbr)
                    {
                        maxbr=j-i;
                        x=i;
                        y=j;
                        j=n;
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
        {
                for(int j=i+1; j<n; j++)
                {
                    if(mas[i]==min&&mas[j]==max&&j-i==maxbr&&maxw>j+i)
                    {
                        maxw=j+i;
                        maxbr=j-i;
                        x=i;
                        y=j;
                        j=n;
                    }
                    if(mas[i]==max&&mas[j]==min&&j-i==maxbr&&maxw>j+i)
                    {
                        maxw=j+i;
                        maxbr=j-i;
                        x=i;
                        y=j;
                        j=n;
                    }
                }
        }
        cout<<x+1<<y+1<<endl;
}

