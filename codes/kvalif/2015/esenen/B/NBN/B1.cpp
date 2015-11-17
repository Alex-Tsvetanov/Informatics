#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct point
{
    int x,y;
    point(){}
    point(int ex,int ey)
    {
        x=ex;
        y=ey;
    }
};
struct figure
{
    vector<point> points;
};
vector<figure> figures;
float calc_triangle_area(point a,point b,point c)
{
    float ab,bc,ac,p;
    ab = sqrt(pow(a.x - b.x,2) + pow(a.y-b.y,2));
    bc = sqrt(pow(c.x - b.x,2) + pow(c.y-b.y,2));
    ac = sqrt(pow(a.x - c.x,2) + pow(a.y-c.y,2));
    p = (ab + bc + ac)/2;
    return sqrt(p*(p - ab)*(p - bc)*(p - ac));
}
float calc_fig_area(figure fig)
{
    float area;
    for(int i = 2;i < fig.points.size();i++)
        area+=calc_triangle_area(fig.points[0],fig.points[i - 1],fig.points[i]);
    return area;
}
int main()
{
    int size;
    int px,py;
    while(true)
    {
        cin>>size;
        if(size != 0)
        {
            figure fig;
            for(int i = 0;i < size;i++)
            {
                cin>>px>>py;
                fig.points.push_back(point(px,py));
            }
            figures.push_back(fig);
        }
        else
            break;
    }
    int indexMin = 0;
    float areaMin = calc_fig_area(figures[0]);
    float current;
    for(int i = 1;i < figures.size();i++)
    {
        current = calc_fig_area(figures[i]);
        if(current == areaMin && figures[i].points.size() < figures[indexMin].points.size())
        {
            indexMin = i;
            continue;
        }
        if(current<areaMin)
        {
            indexMin = i;
            areaMin = current;
        }
    }
    cout<<indexMin+1;
    return 0;
}
