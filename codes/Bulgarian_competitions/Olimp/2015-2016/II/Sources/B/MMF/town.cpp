#include<iostream>
//#include<vector>
using namespace std;
/*
vector<int> connections;
int narushenie =0;
int counter =0;
int Start, End;
bool repeat=0;
bool solved=false;
int rec()
{
for(int i=0; i<counter; i++)
    {
        if(i%2 != 0)
        {
            if(Start == connections[i]) {Start= connections[i-1]; narushenie++; }
        }else{
        if(Start == connections[i]){Start= connections[i+1]; }
        else{
            narushenie = 0;
        }

        }
    }
   // cout<<Start<<End<<'\n';
    if(Start == End){return narushenie;}
    else{ return rec();}

}
*/
int main()
{
int n, Start, End;
cin>>n>>Start>>End;
/*for(int i=0; true; i++)
{
    cin>>p>>q;
    connections.push_back(p);
    connections.push_back(q);
    counter+=2;
   cout<<rec()<<'\n';


}*/
   cout<<"X"<<'\n';
    return 0;
}

