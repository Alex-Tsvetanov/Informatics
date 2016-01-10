#include <iostream>
#include <cstdlib>
using namespace std;

long long int p,k,m,a[100000],b[100000],d[200000];;

int compare_ints(const void* a,const void* b)
{
    int* arg1=(int*)a;
    int* arg2=(int*)b;

    if(*arg1<*arg2)
    {
        return -1;
    }else   if(*arg1==*arg2)
            {
                return 0;
            }else   return 1;
}

int main()
{
    long long int size=m;

    cin>>p>>m;

    for(int i=0;i<m;i++)
    {
        cin>>a[i]>>b[i];
    }

    cin>>k;

    std::qsort(a,size,sizeof(int),compare_ints);
    std::qsort(b,size,sizeof(int),compare_ints);

    long long int c[p],n=1;

    for(int i=0;i<p;i++)
    {
        c[i]=n;
        n++;
    }

    for(int i=0;i<2*m;i++)
    {
        int j=0;

        while(i<m)
        {
            d[i]=a[i];
            i++;
        }

        while((i>=m)and(i<2*m))
        {
            d[i]=b[j];
            i++;
            j++;
        }
    }

    long long int temp=0,temp2=0,temp3[100000],size_temp3=0,z,x=0;

    for(int i=0;i<p;i++)
    {
        for(int j=0;j<2*m;j++)
        {
            if(c[i]==d[j])
            {
                temp++;

                if(temp>=k)
                {
                    z=j;
                }
            }
        }

        if(temp>=k)
        {
            temp2++;
            temp3[x]=d[z];
            size_temp3++;
            x++;
        }

        temp=0;
    }

    cout<<temp2<<endl;

    for(int i=0;i<size_temp3;i++)
    {
        cout<<temp3[i]<<" ";
    }

    cout<<endl;

    return 0;
}

