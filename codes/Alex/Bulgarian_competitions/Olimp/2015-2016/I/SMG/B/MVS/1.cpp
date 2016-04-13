#include<iostream>

using namespace std;

struct red
{
    int start, fin;
    red()
    {
        start = -1;
        fin = -1;
    }
};

int n;
long a[20000];

int main()
{
    cin>>n;
    long maxx = -1;
    long minn = 1000001;
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>maxx)
        {
            maxx = a[i];
        }
        if(a[i]<minn)
        {
            minn = a[i];
        }
    }
    red nadolu, nagore;
    for(int i = 0; i<n; i++)
    {
        if(a[i]==minn && nagore.start == -1)
        {
            nagore.start = i;
        }
        if(a[i]==maxx && nadolu.start == -1)
        {
            nadolu.start = i;
        }
        if(a[i] == minn && nadolu.start != -1)
        {
            nadolu.fin = i;
        }
        if(a[i] == maxx && nagore.start != -1)
        {
            nagore.fin = i;
        }
    }
    nagore.start++;nagore.fin++;nadolu.start++;nadolu.fin++;
    if(nagore.fin-nagore.start > nadolu.fin - nadolu.start)
    {
        cout<<nagore.start<<" "<<nagore.fin;
    }
    else
    {
        if(nagore.fin-nagore.start < nadolu.fin - nadolu.start)
        {
            cout<<nadolu.start<<" "<<nadolu.fin;
        }
        else
        {
            if(nagore.fin+nagore.start < nadolu.fin+nadolu.start)
            {
                cout<<nagore.start<<" "<<nagore.fin;
            }
            else
            {
                cout<<nadolu.start<<" "<<nadolu.fin;
            }
        }
    }
    return 0;
}
