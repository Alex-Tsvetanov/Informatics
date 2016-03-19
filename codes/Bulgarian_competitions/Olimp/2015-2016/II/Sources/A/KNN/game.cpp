#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Circle
{
    int x, y, r;
};

Circle circles[10001];
int n;

class Point
{
    public:

    double minR[10001];

    void GetMinRs(int x, int y)
    {
        for(int i = 0; i < n; i++)
        {
            Circle& c = circles[i];

            double dx = x - c.x;
            double dy = y - c.y;

            minR[i] = sqrt(dx*dx + dy*dy) + c.r;
        }
        sort(minR, minR+n);
        /*for(int i = 0; i < n; i++) cout<<minR[i]<<" ";
        cout<<endl;*/
    }

    int GetNumber(int r)
    {
        return binSearch(r);
    }

    private:

    int binSearch(int k)
    {
        if(k < minR[0]) return 0;
        if(k > minR[n-1]) return n;

        int low = 0;
        int high = n - 1;

        while(low < high)
        {
            int mid = (low+high)/2;

            //cout<<high<<" "<<low<<" "<<mid<<" -> ";

            if(minR[mid] < k) low = mid+1;
            else if(minR[mid] > k) high = mid-1;
            else return mid+1;

            //cout<<high<<" "<<low<<endl;
        }

        return minR[low] <= k ? low+1 : low;
    }
};

Point points[10];
int m;

int main()
{
    int q;
    cin>>n>>m>>q;
    for(int i = 0; i < n; i++)
    {
        cin>>circles[i].x>>circles[i].y>>circles[i].r;
    }

    int x,y;

    for(int i = 0; i < m; i++)
    {
        cin>>x>>y;
        points[i].GetMinRs(x,y);
    }

    int score = 0;
    int lastScore = -1;
    int force = 0;

    for(int i = 0; i < q; i++)
    {
        cin>>force;
        if(lastScore%2 == 0) force*=2;

        lastScore = 0;
        for(int j = 0; j < m; j++) lastScore += points[j].GetNumber(force);
        score+=lastScore;
        cout<<"round "<<i<<": "<<lastScore<<endl;
    }

    cout<<score;
}
