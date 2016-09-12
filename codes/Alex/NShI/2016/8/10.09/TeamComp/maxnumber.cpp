#include<iostream>
#include<algorithm>

using namespace std;

struct num
{
    long long a,br;
};

num arr[100000];

bool cmp(num x, num y)
{
    if(x.a<y.a)return true;
    return false;
}

int main ()
{
    long long n,i;
    long long k,p=1,res=-1;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>k;

        p=1;

        while(k%2==0)
        {
            k/=2;

            p*=2;

            //cout<<k<<"-"<<p<<" "<<i<<endl;

            //cin.get();
        }

        arr[i].a=k;
        arr[i].br=p;
    }

    sort(arr,arr+n,cmp);

    for(i=0;i<n-1;i++)
    {
        if(arr[i].a==arr[i+1].a)
        {
            arr[i+1].br+=arr[i].br;
        }
        else
        {
            k=arr[i].a;
            //cout<<arr[i].a<<" "<<arr[i].br<<endl;


            while(arr[i].br>1)
            {
                arr[i].br/=2;
                k*=2;
                //cout<<k<<" "<<arr[i].br<<endl;
                //cout<<i<<" "<<arr[i].br<<" "<<k<<endl;
                //cin.get();
            }

            if(k>res)res=k;
            arr[i].a=-1;
        }
    }

    //cout<<"cool"<<endl;

    k=arr[n-1].a;
        //cout << arr [n - 1].br << "\n";

    while(arr[n-1].br>1)
    {
        arr[n-1].br/=2;
      //  cout << arr [n - 1].br << "\n";
        k*=2;
    }

    if(k>res)res=k;
    arr[n-1].a=-1;

    cout<<res<<endl;

    return 0;
}
