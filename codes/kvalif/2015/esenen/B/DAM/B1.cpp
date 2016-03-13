#include <iostream>
#include <cmath>
using namespace std;
int c;
bool IsItFound;
int found_1;
int found_2;
int k=0;
int last_k=0;
int last_numb=0;
int max_S=0;
int main ()
{
    int M[1000],x[10000],y[10000];
    for (;;c++)
    {
        cin>>M[c];
        if (M[c]!=0)
        {
            for (k=0;k<M[c]; last_k++)
            {
                cin>>x[last_k]>>y[last_k];
                k++;
            }
        }
        else break;
    }
    int S[1000];
    for (int i=0; i<c; i++)
    {
        IsItFound=false;
        if (M[i]==3)
        {
            for (int j=i+1; j<3+i; j++)
            {
                if (x[i+last_numb]==x[j+last_numb] and j==i+2)
                {
                    S[i]=(abs(y[i+last_numb]-y[j+last_numb])*abs(x[i+last_numb]-x[i+1+last_numb]))/2;
                    break;
                }
                else
                {
                    if (y[i+last_numb]==y[j+last_numb] and j==i+2)
                    {
                        S[i]=(abs(x[i+last_numb]-x[j+last_numb])*abs(y[i+last_numb]-y[i+1+last_numb]))/2;
                        break;
                    }
                    else
                    {
                        if (y[i+last_numb]==y[j+last_numb] and j==i+1)
                        {
                            S[i]=(abs(x[i+last_numb]-x[j+last_numb])*abs(y[i+last_numb]-y[i+2+last_numb]))/2;
                            break;
                        }
                        else
                        {
                            if (x[i+last_numb]==x[j+last_numb] and j==i+1)
                            {
                                S[i]=(abs(y[i+last_numb]-y[j+last_numb])*abs(x[i+last_numb]-x[i+2+last_numb]))/2;
                                break;
                            }
                        }
                    }
                }
            }
            last_numb+=3;
        }
        if (M[i]==4)
        {
            for (int j=i+1; j<4+i; j++)
            {
                if (y[i+last_numb]==y[j+last_numb] and IsItFound==false)
                {
                    found_1=i;
                    found_2=j;
                    IsItFound=true;
                }
                if (x[i+last_numb]==x[j+last_numb] and IsItFound==true)
                {
                    S[i]=abs(y[i+last_numb]-y[j+last_numb])*abs(x[found_1+last_numb]-x[found_2]+last_numb);
                    break;
                }
                if (x[i+last_numb]==x[j+last_numb] and IsItFound==false)
                {
                    found_1=i;
                    found_2=j;
                    IsItFound=true;
                }
                if (y[i+last_numb]==y[j+last_numb] and IsItFound==true)
                {
                    S[i]=abs(x[i+last_numb]-x[j+last_numb])*abs(y[found_1+last_numb]-y[found_2+last_numb]);
                    break;
                }
            }
            last_numb+=4;
        }
    }
    for (int i=0; i<c; i++)
    {
        if (max_S<S[i]) max_S=S[i];
    }
for (int i=0;i<c;i++){
    if (max_S==S[i]) {cout<<i+1<<endl;break;}
}

    return 0;
}
