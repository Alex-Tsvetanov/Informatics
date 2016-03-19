#include<iostream>
#include<math.h>
using namespace std;

/*bool func(bool x, bool y){
    if(x & y){return false;}
    else{return true;}
}*/

char calc(char arr[], char ent[]){
    int checked=0;
    bool letishere;
    bool flag = true;
    for(int i=0;i<26;i++){
        letishere=false;
        for(int j=0;j<1000;j++)
        {
            if (arr[j]=='a'+i){arr[j]=ent[checked];letishere=true;}
        }
        if(letishere){checked++;}
    }

    for(int i=0;i<20;i++){
        //cout<<arr[i];
    }


    for(int i=0; i<20; i++){
        //cout<<endl<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<arr[4]<<arr[5]<<arr[6]<<arr[7]<<arr[8]<<arr[9]<<arr[10]<<arr[11]<<endl;
        flag=true;
        for(int j=0; j<1000; j++){
            //if(arr[j]=='('){flag=true;}
            if(arr[j+1]==')' && arr[j-1]=='('){
                for(int k=j+1;k<1000-j;k++){
                    arr[k]=arr[k+1];
                }
                for(int k=j-1;k<1000-j;k++){
                    arr[k]=arr[k+1];
                }
                flag=false;
                break;
            }
            if(arr[j]=='0' && arr[j+1]=='1' && flag)
            {arr[j]='1';
                for(int k=j+1;k<1000-j;k++){
                    arr[k]=arr[k+1];
                }
             flag=false;
             break;
            }
            if(arr[j]=='0' && arr[j+1]=='0' && flag)
            {arr[j]='1';
                for(int k=j+1;k<1000-j;k++){
                    arr[k]=arr[k+1];
                }
             flag=false;
             break;
            }
            if(arr[j]=='1' && arr[j+1]=='0' && flag)
            {arr[j]='1';
                for(int k=j+1;k<1000-j;k++){
                    arr[k]=arr[k+1];
                }
             flag=false;
            break;
            }
            if(arr[j]=='1' && arr[j+1]=='1' && flag)
            {arr[j]='0';
                for(int k=j+1;k<1000-j;k++){
                    arr[k]=arr[k+1];
                }
             flag=false;
             break;
            }
            else{}
        }
    }

    return arr[0];
}

int main(){
    char izraz[1000];
    char izrazclone[1000];
    for(int i=0; i<1000; i++)   //Define Array
    {
        izraz[i]=5;
    }

    cin>>izraz;
    for(int i=0; i<1000; i++)   //Define Array
    {
        izrazclone[i]=izraz[i];
    }

    int length;
    for(int i=0; i<1000; i++)
    {
        if(izraz[i]==5){length=i-1; break;}         //Fill Array
    }
    //char letters[26];
    bool lettershere[26];

    for (int i=0;i<26;i++)
    {
        lettershere[i]=false;
    }

    for(int i=0;i<1000;i++){            //Letter Check
        switch(izraz[i]){
            case 'a': lettershere[0]=true; break;
            case 'b': lettershere[1]=true; break;
            case 'c': lettershere[2]=true; break;
            case 'd': lettershere[3]=true; break;
            case 'e': lettershere[4]=true; break;
            case 'f': lettershere[5]=true; break;
            case 'g': lettershere[6]=true; break;
            case 'h': lettershere[7]=true; break;
            case 'i': lettershere[8]=true; break;
            case 'j': lettershere[9]=true; break;
            case 'k': lettershere[10]=true; break;
            case 'l': lettershere[11]=true; break;
            case 'm': lettershere[12]=true; break;
            case 'n': lettershere[13]=true; break;
            case 'o': lettershere[14]=true; break;
            case 'p': lettershere[15]=true; break;
            case 'q': lettershere[16]=true; break;
            case 'r': lettershere[17]=true; break;
            case 's': lettershere[18]=true; break;
            case 't': lettershere[19]=true; break;
            case 'u': lettershere[20]=true; break;
            case 'v': lettershere[21]=true; break;
            case 'w': lettershere[22]=true; break;
            case 'x': lettershere[23]=true; break;
            case 'y': lettershere[24]=true; break;
            case 'z': lettershere[25]=true; break;
        }
    }

    int check=27;
    for(int i=0; i<26; i++){
        if (!lettershere[i]){check=i;
            for(int j=check; j<26; j++){
                if(lettershere[j]){lettershere[check]=lettershere[j]; lettershere[j]=false; check++;}
            }

        }
    }

   /* for (int i=0; i<26; i++){
        cout<<lettershere[i];
    }*/

    int letterscount=0;
    for(int i=0; i<26; i++){
        if(lettershere[i]){letterscount++;}
    }

    const int enternumber = letterscount;
    char enter[enternumber];
    char result[200000];

    for(long int i=0; i<200001; i++){
        cin>>enter;
        if (enter[0]=='2'){break;}
        result[i]=calc(izrazclone,enter);
        for(int i=0; i<1000; i++)   //Define Array
        {
            izrazclone[i]=izraz[i];
        }



    }
    cout<<result;







}
