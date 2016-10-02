#include<iostream>
#include<cstring>
using namespace std;
long long x, y, startX, startY;
string vhod, vhod2;
char a='a';

int main()
{
    bool one=false, two=false, Hlettter=false;
    cin>>vhod>>vhod2;

    if(vhod[0]=='a') x=0;
    if(vhod[0]=='b') x=1;
    if(vhod[0]=='c') x=2;
    if(vhod[0]=='d') x=3;
    if(vhod[0]=='e') x=4;
    if(vhod[0]=='f') x=5;
    if(vhod[0]=='g') x=6;
    if(vhod[0]=='h') x=7;
    if(vhod[0]=='i') x=8;
    if(vhod[0]=='j') x=9;
    if(vhod[0]=='k') x=10;
    if(vhod[0]=='l') x=11;
    if(vhod[0]=='m') x=12;
    if(vhod[0]=='n') x=13;
    if(vhod[0]=='o') x=14;
    if(vhod[0]=='p') x=15;
    if(vhod[0]=='q') x=16;
    if(vhod[0]=='r') x=17;
    if(vhod[0]=='s') x=18;
    if(vhod[0]=='t') x=19;
    if(vhod[0]=='u') x=20;
    if(vhod[0]=='v') x=21;
    if(vhod[0]=='w') x=22;
    if(vhod[0]=='x') x=23;
    if(vhod[0]=='y') x=24;
    if(vhod[0]=='z') x=25;

    if(vhod2[0]=='a') startX=0;
    if(vhod2[0]=='b') startX=1;
    if(vhod2[0]=='c') startX=2;
    if(vhod2[0]=='d') startX=3;
    if(vhod2[0]=='e') startX=4;
    if(vhod2[0]=='f') startX=5;
    if(vhod2[0]=='g') startX=6;
    if(vhod2[0]=='h') startX=7;
    if(vhod2[0]=='i') startX=8;
    if(vhod2[0]=='j') startX=9;
    if(vhod2[0]=='k') startX=10;
    if(vhod2[0]=='l') startX=11;
    if(vhod2[0]=='m') startX=12;
    if(vhod2[0]=='n') startX=13;
    if(vhod2[0]=='o') startX=14;
    if(vhod2[0]=='p') startX=15;
    if(vhod2[0]=='q') startX=16;
    if(vhod2[0]=='r') startX=17;
    if(vhod2[0]=='s') startX=18;
    if(vhod2[0]=='t') startX=19;
    if(vhod2[0]=='u') startX=20;
    if(vhod2[0]=='v') startX=21;
    if(vhod2[0]=='w') startX=22;
    if(vhod2[0]=='x') startX=23;
    if(vhod2[0]=='y') startX=24;
    if(vhod2[0]=='z') startX=25;
    /****************************************************************************************************************/
    if(vhod2[1]=='1' and two==false)
    {
        if(vhod2[2]=='0')startY=9;
        if(vhod2[2]=='1')startY=10;
        if(vhod2[2]=='2')startY=11;
        if(vhod2[2]=='3')startY=12;
        if(vhod2[2]=='4')startY=13;
        if(vhod2[2]=='5')startY=14;
        if(vhod2[2]=='6')startY=15;
        if(vhod2[2]=='7')startY=16;
        if(vhod2[2]=='8')startY=17;
        if(vhod2[2]=='9')startY=18;
        two=true;
    }
    else if(vhod2[1]=='2' and two==false)
    {
        if(vhod2[2]=='0')startY=19;
        if(vhod2[2]=='1')startY=20;
        if(vhod2[2]=='2')startY=21;
        if(vhod2[2]=='3')startY=22;
        if(vhod2[2]=='4')startY=23;
        if(vhod2[2]=='5')startY=24;
        if(vhod2[2]=='6')startY=25;
    }
    else if(vhod2[1]=='1')
    {
        startY=0;
        two=true;
    }
    else if(vhod2[1]=='2')
    {
        startY=1;
        two=true;
    }
    else if(vhod2[1]=='3')
    {
        startY=2;
        two=true;
    }
    else if(vhod2[1]=='4')
    {
        startY=3;
        two=true;
    }
    else if(vhod2[1]=='5')
    {
        startY=4;
        two=true;
    }
    else if(vhod2[1]=='6')
    {
        startY=5;
        two=true;
    }
    else if(vhod2[1]=='7')
    {
        startY=6;
        two=true;
    }
    else if(vhod2[1]=='8')
    {
        startY=7;
        two=true;
    }
    else if(vhod2[1]=='9')
    {
        startY=8;
        two=true;
    }

    if(vhod[1]=='1' and one==false)
    {
        if(vhod[2]=='0')y=9;
        if(vhod[2]=='1')y=10;
        if(vhod[2]=='2')y=11;
        if(vhod[2]=='3')y=12;
        if(vhod[2]=='4')y=13;
        if(vhod[2]=='5')y=14;
        if(vhod[2]=='6')y=15;
        if(vhod[2]=='7')y=16;
        if(vhod[2]=='8')y=17;
        if(vhod[2]=='9')y=18;
        one=true;
    }
    else if(vhod[1]=='2' and one==false)
    {
        if(vhod[2]=='0')y=19;
        if(vhod[2]=='1')y=20;
        if(vhod[2]=='2')y=21;
        if(vhod[2]=='3')y=22;
        if(vhod[2]=='4')y=23;
        if(vhod[2]=='5')y=24;
        if(vhod[2]=='6')y=25;
        one=true;
    }
    else if(vhod[1]=='1')
    {
        y=0;
        one=true;
    }
    else if(vhod[1]=='2')
    {
        y=1;
        one=true;
    }
    else if(vhod[1]=='3')
    {
        y=2;
        one=true;
    }
    else if(vhod[1]=='4')
    {
        y=3;
        one=true;
    }
    else if(vhod[1]=='5')
    {
        y=4;
        one=true;
    }
    else if(vhod[1]=='6')
    {
        y=5;
        one=true;
    }
    else if(vhod[1]=='7')
    {
        y=6;
        one=true;
    }
    else if(vhod[1]=='8')
    {
        y=7;
        one=true;
    }
    else if(vhod[1]=='9')
    {
        y=8;
        one=true;
    }




    char pole[x][y], letter;
///cout<<x<<" "<<y<<" "<<startX<<" "<<startY;

    /********************************************************************/
    for(int j=0; j<=y; j++)
    {
        for(int i=0; i<=x; i++)
        {

            pole[i][j]='O';

        }
    }
    for(int j=0; j<=y; j++)
    {
        for(int i=0; i<=x; i++)
        {
            if(i==startX and j==startY and Hlettter==false)
            {
                pole[i][j]='H';
                pole[i+1][j-2]='X';
                pole[i+2][j-1]='X';
                pole[i+2][j+1]='X';
                pole[i+1][j+2]='X';
                pole[i-1][j+2]='X';
                pole[i-2][j+1]='X';
                pole[i-1][j-2]='X';
                pole[i-2][j-1]='X';
                Hlettter=true;
            }
            else if(!('H'==pole[i][j] or 'X'==pole[i][j]))
            {
                pole[i][j]='O';
            }
        }
    }
    cout<<"   ";
    for(int i=0; i<=x; i++)
    {
        cout<<a;
        a=a+1;
    }
    cout<<endl;
    for(int j=0; j<=y; j++)
    {
        //if(j!=0 or j!=1)
        if(j+1<10)
        {
            cout<<j+1<<"  ";
        }
        if(j+1>=10)
            cout<<j+1<<" ";
        for(int i=0; i<=x; i++)
        {
            cout<<pole[i][j];
        }
        cout<<endl;
    }


    return 0;
}
