#include<iostream>
using namespace std;

void defniz(char n[],char no[],int nc){
    for(int i=0;i<nc;i++){
        n[i]=no[i];
    }
}

void defzin(char n[],char no[], int nc){
    for(int i=nc;i>=0;i--){
        n[nc-i-1]=no[i];
        //cout<<n[i]<<endl;
    }
}

int main(){
    char nizorig[10000];
    for(int i=0;i<10000;i++){
        nizorig[i]='1';
    }
    cin>>nizorig;
    int nizcount=0;
    for(int i=0;i<10000;i++){
        if(nizorig[i]!='1'){nizcount++;}
    }
    nizcount--;
    //cout<<nizcount;
    const int nizcnt=nizcount;
    char niz[nizcnt];
    defniz(niz,nizorig, nizcnt);
    char zin[nizcnt];
    defzin(zin,nizorig, nizcnt);

   /// int razcount=0;
    ///int nizcountdyn=nizcount;
    bool pal=true;
    int palpos;
   /// int startpos=nizcount;

    ///int dyn=0;

    int palcount=0;

   /* for(int i=0;i<nizcount;i++)
        for(int j=startpos;j<nizcount;j++){
            for(int k=0;k<nizcountdyn;k++){
                if(niz[k]!=zin[]){pal=false;break;}
            }
            if(pal){palpos=k+1;break;}

        }
     startpos=palpos;
    }*/



    /*for(j=){
        for(int k=j;k<nizcount-startpos-dyn;k++){
            if(niz[k]!=zin[k+dyn]){pal=false;break;}
        }
        if(pal){palpos=k+1;break;}
        if(!pal){dyn++;}
    }*/

    for(int i=0;i<nizcount;i++)
    {
        //cout<<zin[i];
        //cout<<niz[i];
    }

    for (int i=0;i<nizcount;i++){
        int k=i;
        for(int l=0;l<nizcount-k;l++){
            int k=i; pal=true;
            for(int j=0;j<nizcount-i-l;j++)
            {
                //cout<<niz[k]<<" "<<zin[j+l]<<endl;
                if(niz[k]!=zin[j+l]){pal=false;break;}
                //cout<<k;
                k++;
            }
            if(pal){palcount++;palpos = k+1;i=k-1;break;}
            //if(palpos>nizcount){palcount=0;break;}
        }
    }

    cout<<palcount-1;


}
