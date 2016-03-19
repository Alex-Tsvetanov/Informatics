#include<iostream>
using namespace std;

int log2(long long a)
{   long long b=1,br=0;
    while(b<a){br++;b=b<<1;}
    return br;
}

int main()
{   long long n;
    cin>>n;
    /*for(int i=1;i<=3;i++)
        for(int j=0;j<=3-i;j++)
            cout<<i<<" "<<i+j+1<<endl;*/
    cout<<log2(n)<<endl;
    if(n==2)
    {   cout<<"1 1"<<endl;
    }
    if(n==3||n==4)
    {   cout<<"2 1 3"<<endl;
        cout<<"2 2 3"<<endl;
    }
    if(n==5)
    {   cout<<"4 1 2 4 5"<<endl;
        cout<<"3 1 2 3"<<endl;
        cout<<"3 1 3 4"<<endl;
    }
    if(n==6)
    {   cout<<"4 1 2 4 5"<<endl;
        cout<<"4 1 2 3 6"<<endl;
        cout<<"3 1 3 4"<<endl;
    }
    if(n==7||n==8)
    {   cout<<"4 1 2 4 5"<<endl;
        cout<<"4 1 2 3 6"<<endl;
        cout<<"4 1 3 4 7"<<endl;
    }
    if(n==9)
    {   cout<<"4 1 2 5 6"<<endl;
        cout<<"4 1 2 3 7"<<endl;
        cout<<"4 1 4 3 8"<<endl;
        cout<<"4 1 4 5 9"<<endl;
    }
    if(n==10)
    {   cout<<"5 1 2 5 6 10"<<endl;
        cout<<"5 1 2 3 7 10"<<endl;
        cout<<"5 1 4 3 8 10"<<endl;
        cout<<"4 1 4 5 9"<<endl;
    }
    if(n==11)
    {   cout<<"5 1 2 5 6 10"<<endl;
        cout<<"6 1 2 3 7 10 11"<<endl;
        cout<<"6 1 4 3 8 10 11"<<endl;
        cout<<"5 1 4 5 9 11"<<endl;
    }
    if(n==12)
    {   cout<<"6 1 2 5 6 10 12"<<endl;
        cout<<"6 1 2 3 7 10 11"<<endl;
        cout<<"7 1 4 3 8 10 11 12"<<endl;
        cout<<"6 1 4 5 9 11 12"<<endl;
    }
    if(n==13)
    {   cout<<"7 1 2 5 6 10 12 13"<<endl;
        cout<<"7 1 2 3 7 10 11 13"<<endl;
        cout<<"7 1 4 3 8 10 11 12"<<endl;
        cout<<"7 1 4 5 9 11 12 13"<<endl;
    }
    if(n==14)
    {   cout<<"8 1 2 5 6 10 12 13 14"<<endl;
        cout<<"7 1 2 3 7 10 11 13"<<endl;
        cout<<"8 1 4 3 8 10 11 12 14"<<endl;
        cout<<"7 1 4 5 9 11 12 13"<<endl;
    }
    if(n==15||n==16)
    {   cout<<"8 1 2 5 6 10 12 13 14"<<endl;
        cout<<"8 1 2 3 7 10 11 13 15"<<endl;
        cout<<"8 1 4 3 8 10 11 12 14"<<endl;
        cout<<"8 1 4 5 9 11 12 13 15"<<endl;
    }

    return 0;
}

