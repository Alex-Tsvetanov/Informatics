#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
struct point{
    int x,y;
};
struct circle{
    point p;
    int r;
    bool used;

};

vector <circle> circles;
vector <point> points;
int lastPoints = 0;
int M,N,Q;
vector<float> distances;
//sqrt((x1-x2)+(y1-y2));
int check(int strength){
    int i=0;
    //cout<<endl<<endl<<strength<<endl;
    while(distances[i]<strength && i<distances.size()){
        i++;
        //cout<<i<<"  "<<distances[i]<<endl;
    }
    //cout<<"OTGOVOR  "<<i<<endl;
    return i;
}
void sumpersgs(){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            distances.push_back(sqrt((points[i].x - circles[j].p.x)*(points[i].x - circles[j].p.x) + (points[i].y - circles[j].p.y)*(points[i].y - circles[j].p.y))+circles[j].r);
            //cout<<sqrt((points[i].x - circles[j].p.x)*(points[i].x - circles[j].p.x) + (points[i].y - circles[j].p.y)*(points[i].y - circles[j].p.y))+circles[j].r<<endl;
        }
    }
    sort(distances.begin(), distances.end());
    //cout<<"------------"<<endl;

}
int main(){
    int score = 0;
    cin>>N>>M>>Q;
    //cout<<endl<<"entering N circles"<<endl;
    for(int i=0;i<N;i++){
        circle temp;
        cin>>temp.p.x>>temp.p.y>>temp.r;
        temp.used=0;
        circles.push_back(temp);
    }
    //cout<<endl<<"entering M points"<<endl;
    for(int i=0;i<M;i++){
        point temp;
        cin>>temp.x>>temp.y;
        points.push_back(temp);
    }
    //cout<<endl<<"entering Q hits"<<endl;
    sumpersgs();
    for(int i=0;i<Q;i++){
        int a;
        cin>>a;
        //cout<<lastPoints<<endl;
        if(lastPoints == 0){
            lastPoints = check(a);
        }else if(lastPoints%2==0){
            lastPoints = check(a*2);
        }else{
            lastPoints = check(a);
        }
        score+=lastPoints;
    }
    cout<<score;
}
