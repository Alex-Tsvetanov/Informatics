#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
};

bool onSegment (Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) and q.x >= min(p.x, r.x) and
        q.y <= max(p.y, r.y) and q.y >= min(p.y, r.y))
       return true;

    return false;
}

int orientation (Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;

    return (val > 0) ? 1 : 2;
}

bool doIntersect (Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation (p1, q1, p2);
    int o2 = orientation (p1, q1, q2);
    int o3 = orientation (p2, q2, p1);
    int o4 = orientation (p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 and onSegment (p1, p2, q1)) return true;

    if (o2 == 0 and onSegment (p1, q2, q1)) return true;

    if (o3 == 0 and onSegment (p2, p1, q2)) return true;

    if (o4 == 0 and onSegment (p2, q1, q2)) return true;

    return false;
}

int main ()
{
    int n;
    cin >> n;

    Point* arr1 = new Point [n];
    Point* arr2 = new Point [n];
    for (int i = 0 ; i < n ; i ++)
        cin >> arr1 [i].x >> arr1 [i].y
            >> arr2 [i].x >> arr2 [i].y;
    int ans = 0;
    for (int i = 0 ; i < n ; i ++)
        for (int j = i + 1 ; j < n ; j ++)
            ans += doIntersect(arr1 [i], arr2 [i], arr1 [j], arr2 [j]);

    cout << ans << "\n";

    delete[] arr1;
    delete[] arr2;
}
