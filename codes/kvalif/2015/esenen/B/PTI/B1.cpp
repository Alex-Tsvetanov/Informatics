#include<iostream>
using namespace std;
int main()
{
    int m,n,o,p,q,a[m],b[n],c[o],d[p],e[q],M,N,O,P,Q;
    cin>>M;
    m=2*M;
    for (int i;i<m;i++) cin>>a[i];
    cin>>N;
    if(N!=0)
    {
        n=2*N;
        for (int j;j<n;j++) cin>>b[j];
        cin>>O;
        if(O!=0)
        {
            o=2*o;
            for (int k;k<o;k++) cin>>c[k];
            cin>>P;
            if(P!=0)
            {
                p=2*P;
                for (int l;l<p;l++) cin>>d[l];
                cin>>Q;
                if(Q!=0)
                {
                    q=2*Q;
                    for (int h;h<q;h++) cin>>e[h];
                    cout<<"4"<<endl;
                }
                else cout<<"3"<<endl;
            }
            else cout<<"1"<<endl;
        }
        else cout<<"2"<<endl;
    }
    else cout<<"1"<<endl;
    return 0;


}
