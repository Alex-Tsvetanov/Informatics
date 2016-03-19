
#include<iostream>
#include<cstdio>
#include<cmath>
#include<utility>
using namespace std;
pair < int, int >  res[40016];
int main()
{
    int K,br = 0;
    cin>>K;
    double sq = sqrt(K);
    for(int i=1;i<sq;i++)
    {

            if((K+i)%(1+2*i)==0// and (K+i)/(1+2*i)>i
               )
            {
                //cout<<N<<endl;
                res[br] = make_pair(i,(K+i)/(1+2*i));
                br ++;
            }
            if((K+i-1)%(1+2*i)==0// and (K+i-1)/(1+2*i)<=i
               )
            {
                //cout<<N<<endl;
                res[br] = make_pair((K+i-1)/(1+2*i),i);
                br ++;
            }
    }
    //cout<<br<<endl;
    printf("%d",br);
    printf("\n");
    for(int i=0;i<br;i++)
    {
        printf("%d",res[i].first);
        printf(" ");
        printf("%d",res[i].second);
        printf("\n");
    }

    return 0;
}
