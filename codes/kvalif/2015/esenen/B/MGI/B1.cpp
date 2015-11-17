#include <iostream>
using namespace std;
int x[200000],y[200000],m[20000],s[20000],br=1;

int sortt(){
    bool nik=1;

    while(nik){
        nik=0;
        for(int i=m[br-1]+2;i<=m[br];i++){
            if(x[i-1]>x[i]){
                swap(x[i-1],x[i]);
                swap(y[i-1],y[i]);
                nik=1;
            }
        }
    }
}

double rekd(int last){
    if(m[br-1]+last+2>m[br])return 0;
    int maxy=y[m[br-1]+last];
    if(y[m[br-1]+last+1]>maxy)maxy=y[m[br-1]+last+1];
    if(y[m[br-1]+last+2]>maxy)maxy=y[m[br-1]+last+2];
    int miny=y[m[br-1]+last];
    if(y[m[br-1]+last+1]<miny)miny=y[m[br-1]+last+1];
    if(y[m[br-1]+last+2]<miny)miny=y[m[br-1]+last+2];
    int srdy=y[m[br-1]+last];
    if(srdy==maxy || srdy==miny)srdy=y[m[br-1]+last+1];
    if(srdy==maxy || srdy==miny)srdy=y[m[br-1]+last+2];

    double ss=(x[m[br-1]+last+2]-x[m[br-1]+last])*(maxy-miny);

    return ss+rekd(last+1);
}

int main(){

cin>>m[0];
for(int i=0;i<m[0];i++){
    cin>>x[i]>>y[i];
}
{
bool nik=1;

    while(nik){
        nik=0;
        for(int i=1;i<=m[0];i++){
            if(x[i-1]>x[i]){
                swap(x[i-1],x[i]);
                swap(y[i-1],y[i]);
                nik=1;
            }
        }
    }
}
s[0]=rekd(1);
for(;;){
    cin>>m[br];
    if(m[br]==0)break;

    for(int i=1;i<=m[br];i++){
        cin>>x[m[br-1]+i]>>y[m[br-1]+i];
    }
    m[br]+=m[br-1];
    sortt();
    s[br]=rekd(1);
    br++;
}
int minn=s[0],mini=0;
for(int i=0;i<br;i++){
    if(minn>s[i]){
        minn=s[i];
        mini=i;
    }
}
//cout<<s[0];
cout<<mini+1<<endl;

return 0;
}
