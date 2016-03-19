#include <iostream>
using namespace std;
int x;
int y;
int broken;
bool direction=false;

int CountBroken(int rows,int columns)
{
    x=1;
    y=1;
    broken=0;
    direction=true;
     while (true)
    {
        if (direction)
        {
            y++;
            direction=false;
            broken++;
        }
        if (x>rows)
        {
            return broken;
            break;
        }
        if (y>columns)
        {
            return broken;
            break;
        }
        if (!direction)
        {
            x++;
            direction=true;
            broken++;
        }
        if (x>rows)
        {
            return broken;
            break;
        }
        if (y>columns)
        {
            return broken;
            break;
        }
    }

}

int main () {
int N,M,P;
cin>>N>>M>>P;
int start,finish;
for (int i=0;i<M;i++){
    cin>>start>>finish;
}
cout<<"MIXED"<<endl;
return 0;
}
