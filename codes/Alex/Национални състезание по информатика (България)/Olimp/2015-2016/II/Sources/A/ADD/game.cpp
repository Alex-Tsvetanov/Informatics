#include <iostream>
#include <stdio.h>
#include<math.h>
#include <algorithm>
#define MAXN 10000
#define MAXM 10
using namespace std;
int n,m,q,x,y,s[MAXN],last = 0,sum,br;
double d;
struct circle{
    int x,y,r;
};
struct center{
    int x,y;
};
int main(){
    circle c[MAXN];
    center cent[MAXM];
    scanf("%i %i %i", &n, &m, &q);
    for(int i = 0; i < n; i++){
        scanf("%i %i %i",&c[i].x ,&c[i].y ,&c[i].r);
    }
    for(int i = 0; i < m; i++){
        cin>>cent[i].x>>cent[i].y;
    }
    for(int i = 0; i < q; i++){
        scanf("%i", &s[i]);
    }
    for(int k = 0; k < m; k++){
        for(int i = 0; i < q; i++){
            for(int j = 0; j < n; j++){
                if(c[j].r <= s[i]*(last+1)){
                    if(c[j].r == s[i]*(last+1)){
                        if(c[j].x == cent[k].x && c[j].y == cent[k].y){
                            br++;
                            sum++;
                        }
                    }else{
                        d = sqrt(pow((cent[k].x-c[j].x),2)+pow((cent[k].y-c[j].y),2));
                        if(s[i]*(last+1) - c[j].r >= d){
                            br++;
                            sum++;
                        }
                    }
                }
            }
            if(br % 2 == 0){
                last = 1;
                br = 0;
            }else{
                last = 0;
                br = 0;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
