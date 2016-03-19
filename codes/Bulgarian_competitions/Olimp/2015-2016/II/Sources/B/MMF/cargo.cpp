#include<iostream>
#include<string>
using namespace std;
int main()
{
int days, requests, pilots;
cin>>days>>requests>>pilots;
int AllRequests[requests*2];
for(int i=0; i<requests*2; i++)
{
    cin>>AllRequests[i];

} //works

/*for(int i=0; i<requests*2; i++)
{
    cout<<AllRequests[i];

}
*/
if(requests > days && pilots/2 <2) { cout<<"IMPOSSIBLE"<<'\n'; return 0;}
/*
int teams = pilots/2;
string AllDays[days];

for(int i=0; i<days; i++)
{

    AllDays[i] = "0";
}//works
/*for(int i=0; i<days; i++)
{

    cout<<AllDays[i];
}*/
/*
for(int i=0; i<requests*2; i++)
{

   if(i%2 == 0){
    AllDays[AllRequests[i]-1]+="Start";

   }
   else{
    AllDays[AllRequests[i]-1]+="End";

   }
}

for(int i=0; i<days; i++)
{

    cout<<AllDays[i]<<" ";
}
*/
cout<<"MIXED"<<'\n';





    return 0;
}

