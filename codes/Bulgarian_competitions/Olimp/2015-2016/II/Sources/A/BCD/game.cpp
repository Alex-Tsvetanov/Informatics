#include<iostream>
#include<cmath>

using namespace std;

int main(){

    int N;
    int M;
    int Q;
    cin>>N>>M>>Q;
    long long circles[N][3];
    long long playerCircles[M][2];
    long long hits[Q];
    for(int i = 0; i < N; i++){
        cin>>circles[i][0]>>circles[i][1]>>circles[i][2];
    }
    for(int i = 0; i < M; i++){
        cin>>playerCircles[i][0]>>playerCircles[i][1];
    }
    for(int i = 0; i < Q; i++){
        cin>>hits[i];
    }
    double distance;
    long long points = 0;
    int counter = 0;
    int multiply = 1;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < Q; j++){
            counter = 0;
            for(int k = 0; k < N; k++){
                distance = hypot(abs(playerCircles[i][0] - circles[k][0]), abs(playerCircles[i][1] - circles[k][1]));
                if((hits[j] * multiply) - circles[k][2] >= distance){
                    counter++;
                }
            }
            multiply = counter % 2 == 0 ? 2 : 1;
            points += counter;
        }
    }
    cout<<points<<endl;
    return 0;
}
