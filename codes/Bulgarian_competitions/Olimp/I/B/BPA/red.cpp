#include <iostream>

using namespace std;

int main()
{
    int N;
    do{
    cin>>N;}
    while(N<=1 || N>20000);
    int a[N];
    int m[N];
    int mn, mx;
    int maxA;
    int maxAP;
    int pLength;
    bool f = true;
    for(int i = 0; i<N; ++i)
        {

        do{
        cin>>a[i];
        }
        while(a[i]<=0 || a[i]>1000000);


        if(f)
            {
            f = false;
            mn = a[i];
            mx = a[i];
            }
        else if(mn>a[i])
            {
                mn = a[i];
            }
        else if(mx<a[i])
            {
                mx = a[i];
            }
        }
    int maxLength = 0;
    int dif = mx - mn;
    mx = 0;
    mn = 0;

    for(int i = 0; i<N; ++i)
        {
            int length=0;
            for(int ii = i; ii<N; ++ii)
                {
                   ++length;
                   if((a[i]-a[ii] == dif || a[ii]-a[i] == dif) && length>=maxLength)
                    {
                        maxAP = maxA;
                        maxA = i+ii;
                        maxLength = length;



                        for(int j = 0; j<maxLength; j++){
                        m[j] = a[j+i];

                        }

                        if(pLength < maxLength)
                        {
                        mx = ii;
                        mn = i;
                        if(mx<mn){
                        swap(mx, mn);
                        }
                        }
                        else if(maxAP>maxA && pLength == maxLength)
                            {
                        mx = ii;
                        mn = i;
                        if(mx<mn){
                        swap(mx, mn);
                        }
                        }
                        pLength = maxLength;
                    }
                }


        }

    cout<<mn+1<<" "<<mx+1<<endl;

    return 0;
}

