
#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;

int res = 0;

struct p
{
    int f,t;
};

bool com(p a, p b)
{
    if(a.f!=b.f)return a.f<b.f;
    return a.t<b.t;
}

p arr[1000016];
queue < p > q;
queue < p > q2;
int main()
{
    int N,M,P,br = 0;
    cin>>N>>M>>P;
    P/=2;
    for(int i=0;i<M;i++)
    {
        int a, b;
        cin>>a>>b;
        p A;
        A.f = a;
        A.t = b;
        arr[i] = A;
        q.push(A);
        q2.push(A);
    }
    sort(arr,arr+M, com);

//    for(int i=0;i<M;i++)
//    {
//        cout<<arr[i].f<<" "<<arr[i].t<<"\n";
//    }
    int last = 0;
//    int dos = 0;
//    int pov = 0;
//    int ERR = 0;
    int day = 1;
    while(!q.empty())
    {

        int i=0;
        if(day>q.front().t){break;}
        if(day < q.front().f)day = q.front().f;
        while(day%7==0 or day%7==6)day++;
        while(q.front().f<=day and q.front().t>=day and i<P){q.pop();i++;}

        day++;

//        if(pov + arr[i].f > arr[i].t ) {cout << "IMPOSSIBLE\n";return 0;}
//        arr[i].f+= pov;
//        while(arr[i].f%7 ==0 or arr[i].f% 7 == 6)arr[i].f++;
//        if(arr[i].f > arr[i].t and ){break;}
    }
    if(q.empty()){cout<<"OK\n";return 0;}
    day = 0;
    while(!q2.empty())
    {
        int i=0;
        if(day>q2.front().t){cout<<"IMPOSSIBLE\n";return 0;}
        if(day < q.front().f)day = q2.front().f;
        //while(day%7==0 or day%7==6)day++;
        while(q2.front().f<=day and q2.front().t>=day and i<P){q2.pop();i++;}
        //cout<<day<<" "<<i<<endl;
        day++;

//        if(pov + arr[i].f > arr[i].t ) {cout << "IMPOSSIBLE\n";return 0;}
//        arr[i].f+= pov;
//        while(arr[i].f%7 ==0 or arr[i].f% 7 == 6)arr[i].f++;
//        if(arr[i].f > arr[i].t and ){break;}
    }
    cout<<"MIXED\n";

    return 0;
}
