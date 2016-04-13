#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <stdint.h>

using namespace std;

//#define DEBUG 1
#undef DEBUG

#ifdef DEBUG
#   define DEBUG_PRINTF(fmt, ...) printf(fmt, __VA_ARGS__)
#else
#   define DEBUG_PRINTF(fmt, ...) do {} while(0)
#endif


struct Point
{
    int x;
    int y;

    Point(int x_, int y_)
    {
        this->x = x_;
        this->y = y_;
    }

    float distance(Point &other)
    {
       return sqrt(
            pow((float)abs(this->x - other.x), 2)
            + pow((float)abs(this->y - other.y), 2)
        );
    }
};


struct Circle
{
    Point center;
    int r;

    Circle(int x_, int y_, int r_) : center(x_, y_)
    {
        this->r = r_;
    }

    Circle(Point center_, int r_) : center(center_)
    {
        this->r = r_;
    }

    bool is_inside(Circle &other)
    {
        return (float)other.r >= (this->center.distance(other.center) + this->r);
    }
};


vector<Circle> circles;
vector<Point> points;


int do_turn(int prev_points, int i, int force)
{
    int hits = 0;

    if(i>0 && (prev_points % 2 == 0))
    {
        force = 2*force;
    }

    for(int i = 0; i < points.size(); i++)
    {
        Circle hit(points[i], force);

        for(int j = 0; j < circles.size(); j++)
        {
            if(circles[i].is_inside(hit)) {
                hits++;
            }
        }
    }

    return hits;
}


int main()
{
    int N, M, Q;

    cin >> N >> M >> Q;

    circles.reserve(N);
    points.reserve(M);

    for(int i = 0; i < N; i++)
    {
        int x;
        int y;
        int r;

        cin >> x >> y >> r;

        circles.push_back(Circle(x,y,r));
    }

    for(int i = 0; i < M; i++)
    {
        int x;
        int y;

        cin >> x >> y;

        points.push_back(Point(x,y));
    }

    int total_points = 0;

    for(int i = 0; i < Q; i++)
    {
        int previous_points = 0;
        int force;

        cin >> force;

        int this_turn = do_turn(previous_points, i, force);
        previous_points = this_turn;
        total_points += this_turn;
    }

    cout << total_points;

    return 0;
}

