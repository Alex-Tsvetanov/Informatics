#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
struct palindreomes
{
    char value;
    int par_index;
};

int DevBr(int size,palindreomes pal[],int Start/*0*/,int End/*line.length-1*/,int OrigStart/*-1*/,int OrigEnd/*length-1*/,int &br)
{

    if((Start+1)>=size)
    {
        br++;
        return 0;
    }
    else if(Start==End||Start+1==End)
    {
        if(size<=2)
        {

            br++;
            return 0;
        }
        else
        {
            br++;
            DevBr(size,pal,OrigEnd+1,size-1,-1,size-1,br);
        }
    }
    else if(pal[Start].value==pal[End].value)
    {
        if(OrigStart==-1)
        {
            OrigStart=Start;
            OrigEnd=End;

            DevBr(size,pal,Start+1,End-1,OrigStart,OrigEnd,br);
        }

        else DevBr(size,pal,Start+1,End-1,OrigStart,OrigEnd,br);
    }
    else
    {
        DevBr(size,pal,Start,OrigEnd-1,OrigStart,OrigEnd-1,br);
    }
}
int main()
{
    int br=0;
    int Devisions=0;
    string line;
    cin>>line;
    int n=line.length();
    palindreomes pal[n];
    int size=line.length();
    for(int i=0;i<line.length();i++)
    {
        pal[i].value=line[i];
        pal[i].par_index=i-1;
    }
    DevBr(size,pal,0,size-1,-1,size-1,br);
    //recPal(pal,0,line.length(),-1,line.length(),br,line.length());
    cout<<br-1<<endl;
    //cout<<"k"<<endl;
}
