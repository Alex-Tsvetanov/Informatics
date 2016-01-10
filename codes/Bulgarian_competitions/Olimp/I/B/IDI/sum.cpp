#include<iostream>
using namespace std;
long long mem[3001][13];
long long getrekt(int num,int last)
{
        if(num==0)
        {
                return 1;
        }
        if(mem[num][last])
        {
                return mem[num][last];
        }
        int pom=last;
        for(int i=(1<<last);i!=0;i>>=1)
        {
                if(num>=i)
                {
                        mem[num][last]+=getrekt(num-i,pom);
                }
                pom--;
        }
        return mem[num][last];
}
int main(){
        cin.tie(NULL);
        ios::sync_with_stdio(false);
        int n;
        cin>>n;
        int last=0;
        while((1<<last)<=n)
        {
                last++;
        }
        cout<<getrekt(n,last)<<"\n";
        return 0;
}
