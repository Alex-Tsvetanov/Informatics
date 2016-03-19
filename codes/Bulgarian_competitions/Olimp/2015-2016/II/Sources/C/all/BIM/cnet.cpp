#include<iostream>
#include<vector>
using namespace std;

int main (){
     int n;
     long long m;
     cin>>n>>m;
     int vryzki[m][2];
     int broi=0;
     long long lastbr=0;
     long long br=0;
     long long newbr=0;
     int lastdel[m];
     int del[m];
     int newdel[m];
     for(long long i=0;i<m;i++){
        cin>>vryzki[i][0];
        cin>>vryzki[i][1];

     }
     bool con[n];
     bool yes[n];
     long time[n];
     for (int i=0;i<n;i++){
        con[i]=false;
        yes[i]=true;
        time[i]=0;
     }
     long long mint=10000000;
    bool full =true;
    bool stop =false;
     for(int i=0;i<n;i++){
        full =true;
        stop=false;
        lastdel[0]=i;
        del[0]=i;
        br=1;
        newbr=0;
        for(long long k=0;k<m;k++,time[i]++){

            for(long long k=0;k<m;k++){

                for(int f=0;f<br;f++){
                    if(vryzki[k][0]==del[f]){
                        con[vryzki[k][1]]=true;
                        newdel[newbr-1]=vryzki[k][1];
                        newbr++;

                    }
                }
            }

                if(time[i]>mint){
                    break;
                }


                for (int j=0;j<n;j++){
                    if(con[j]==false){
                        stop=true;
                    }
                }
             if(newbr==lastbr){
                    stop=false;

                        if(newdel[0]!=lastdel[0]){
                            stop=true;

                            break;
                        }
                        lastdel[0]=del[0];

                }
                for(int h=0;h<br;h++){
                    lastdel[h]=del[h];
                }
                if(newbr==0){
                    break;
                }
                lastbr=br;
                br=newbr;

                newbr=0;
                for(int l=0;l<newbr;l++){
                    del[l]=newdel[l];
                }
                if(stop==false){
                    break;
                }



        }
        for (int j=0;j<n;j++){
            if(con[j]==false){
                full=false;
            }
            con[j]=false;
        }
        if(full==false){
            time[i]=0;
            yes[i]=false;
        }else if(time[i]<mint){
            mint=time[i];
            broi++;
        }

     }

    cout<<broi<<endl;
     for(int i=0;i<n;i++){
        if(yes[i]==true&&time[i]==mint){
            cout<<i<<" ";
        }
     }



return 0;
}

