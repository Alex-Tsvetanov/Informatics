#include<iostream>

using namespace std;

struct Point{
    int x, y;
    Point(int x = 0, int y = 0){
        this -> x = x;
        this -> y = y;
    }
};

double area(Point A, Point B, Point C){
    double ans, AB, BC, CA;
    AB = (A.x + B.x) * (A.y - B.y);
    BC = (B.x + C.x) * (B.y - C.y);
    CA = (C.x + A.x) * (C.y - A.y);
    ans = (AB + BC + CA)/2;
    return ans;
}

int main(){

    int m;
    Point A, B, C;
    double currentNumber = 1, currentArea;
    double minNumber = 0, minArea = 2 << 20, minVertex = 0;;

    cin >> m;
    while(m != 0){

        cin >> A.x >> A.y >> B.x >> B.y;
        for(int i = 0; i < m - 2; i ++){
            cin >> C.x >> C.y;
            currentArea += area(A, B, C);
            B = C;
        }

        if(currentArea < 0){currentArea *= -1;}
        if(currentArea < minArea){
            minArea = currentArea;
            minVertex = m;
            minNumber = currentNumber;
        }
        if(currentArea == minArea && m < minVertex){
            minVertex = m;
            minNumber = currentNumber;
        }

        currentArea = 0;
        currentNumber++;
        cin >> m;
    }

    cout << minNumber << "\n";
    return 0;
}
