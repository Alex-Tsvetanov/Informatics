#include<iostream>
//#include<vector>
#include<algorithm>
#define MAXK 1000000000
#define MAXNUM 500000000
using namespace std;
long long kk;
bool flag=0;
int cnt=0,glpos=0;
struct info{

long long n,m;
}vec[1000000];
bool order(info x,info y)
{
    return x.n<y.n;
}
//vector<long long>vec;
void withm()///if m<=n
{//cout<<"inside  m  "<<endl;
    long long i=1,conj=MAXNUM;
    long long k=kk-1;
    //conj=0;
    long long j=1;
    while(/*(i<MAXNUM)||*/(((2*i*j)+i-j)<k))
    {//cout<<"BEFORE "<<((2*i*j)+i-j)<<endl;
    //j=1;

    //((2*i*j)+i-j)>k

      while((j<conj)&&(j<=i))
      {//cout<<"testing "<<i<<" "<<j<<endl;
          if(((2*i*j)+i-j)==k)
          {//cout<<"state1"<<endl;
              //cout<<i<<" "<<j<<endl;
              /*vec.push_back(i);
              vec.push_back(j);*/
              vec[glpos].n=i;
              vec[glpos].m=j;
              glpos++;
              cnt++;
              flag=1;
              j=1;
              conj=j;
              break;
          }
          else if(((2*i*j)+i-j)>k)
          {//cout<<"state2"<<((2*i*j)+i-j)<<endl;
              conj=j;
              //flag=1;
            j=1;
              break;
          }
           // if(flag==0)
           /*else if(j>=i)
           {
               break;
           }*/
            else{
                    //cout<<"state3"<<endl;
                j++;
            }

      }
      //cout<<"testing answer final"<<((2*i*j)+i-j)<<endl;
      j=1;
      i++;
    }
}


void withn()///if m>n
{//cout<<"inside n"<<endl;
    {
    long long i=1,conj=MAXNUM;
    long long k=kk;
    //conj=0;
    long long j=1;
    while(i<MAXNUM&&((2*i*j)+i-j)<=k)
    {
      while(j<conj&&j<=i)
      {//cout<<"testing "<<i<<" "<<j<<endl;
          if(((2*i*j)+i-j)==k)
          {
             // cout<<j<<" "<<i<<endl;
             /* vec.push_back(j);
              vec.push_back(i);*/
              vec[glpos].n=j;
              vec[glpos].m=i;
              glpos++;
              flag=1;
              conj=j;
              j=1;
cnt++;
              break;
          }
          else if(((2*i*j)+i-j)>k)
          {
              conj=j;
              j=1;
              break;
          }

        //if(flag==0)
           else {
                j++;
            }
      }
      //cout<<"testing answer"<<((2*i*j)+i-j)<<endl;
      j=1;
      i++;
    }
}
}
void path_finder()
{
withm();

withn();
/*for(int p=0;p<vec.size();p++)
{
    cout
}*/

cout<<cnt<<endl;
int p=0;
if(flag==1)
{sort(vec,vec+glpos,order);
    while(p<glpos)
{
    cout<<vec[p].n<<" "<<vec[p].m<<endl;
    p++;
}

}
}
void read()
{
cin>>kk;
path_finder();
}
int main ()
{
read();
return 0;
}
