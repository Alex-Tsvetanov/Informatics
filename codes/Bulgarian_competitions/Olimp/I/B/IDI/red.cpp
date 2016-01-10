#include<iostream>
using namespace std;
int memory[1000001];
int main(){
        cin.tie(NULL);
        ios::sync_with_stdio(false);
        int number,minimum=1<<30,maximum=0,current;
        int maximumLength=0,begin=0,end=0,maximumabs=0;
        cin>>number;
        for(int i=0;i<number;i++)
        {
                cin>>current;
                memory[current]=i;
                minimum=min(minimum,current);
                maximum=max(maximum,current);
                int length;
                if(current-minimum>=maximumabs)
                {
                        if(current-minimum>maximumabs)
                        {
                                maximumLength=0;
                        }
                        maximumabs=current-minimum;
                        length=i-memory[minimum];
                        if(length>maximumLength)
                        {
                                maximumLength=length;
                                end=i;
                                begin=memory[minimum];
                        }
                }
                if(maximum-current>=maximumabs)
                {
                        if(maximum-current>maximumabs)
                        {
                                maximumLength=0;
                        }
                        maximumabs=maximum-current;
                        length=i-memory[maximum];
                        if(length>maximumLength)
                        {
                                maximumLength=length;
                                end=i;
                                begin=memory[maximum];
                        }
                }
        }
        cout<<begin+1<<" "<<end+1<<"\n";
        return 0;
}