#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

struct point
{
    int X,Y;
};

double dist(point a, point b)
{
    return (double)sqrt(abs(a.X-b.X)*abs(a.X-b.X)+abs(a.Y-b.Y)*abs(a.Y-b.Y));
}

struct mn
{
    vector<point> points;
    double S()
    {
        if(this->points.size()==3)
        {
            double a=(double)dist(this->points[0],this->points[1]),b=(double)dist(this->points[1],this->points[2]),c=(double)dist(this->points[0],this->points[2]);
            double p=(a+b+c)/2;
            double res=(double)sqrt((double)(p*(p-a)*(p-b)*(p-c)));
            return (double)res;
        }
        else
        {
            mn a,b;
            a.points.push_back(this->points[0]);
            a.points.push_back(this->points[1]);
            a.points.push_back(this->points[2]);
            for(int i=0;i<this->points.size();i++)
            {
                if(i!=1)b.points.push_back(this->points[i]);
            }
            return a.S() + b.S();
        }
    }
};

vector< mn > m;

int main()
{
    int a;
    do
    {
        cin>>a;
        mn mno;
        for(int i=0;i<a;i++)
        {
            point p;
            int b;
            cin>>b;
            p.X=b;
            cin>>b;
            p.Y=b;
            mno.points.push_back(p);
        }
        if(a!=0)m.push_back(mno);
    }while(a!=0);

    double NM=(double)m[0].S();
    int bp=m[0].points.size();
    int res=1;
    for(int i=1;i<m.size();i++)
    {
        if(m[i].S()<NM){NM=(double)m[i].S();res=i+1;bp=m[i].points.size();}
        if(m[i].S()==NM and bp>m[i].points.size()){NM=(double)m[i].S();res=i+1;bp=m[i].points.size();}
    }

    cout<<res;

    return 0;
}
