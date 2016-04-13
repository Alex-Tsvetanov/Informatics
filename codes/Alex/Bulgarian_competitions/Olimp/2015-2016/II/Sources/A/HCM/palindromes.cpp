#include<iostream>

using namespace std;

bool isp(string s){
    int len = s.size();
    int n = len/2;
    for(int i=0;i<n;i++){
        if(s[i]!=s[len-i-1])return false;
    }
    return true;
}

int main(){

    string s;
    cin >> s;

    if(isp(s)){
        cout << 0 << endl;
        return 0;
    }

    int slen = s.size();
    for(int i=1;i<slen;i++){
        if(isp(s.substr(0, i)) && isp(s.substr(i, slen))){
            cout << 1 << endl;
            return 0;
        }
    }

    for(int i=1;i<slen;i++){
        for(int j=i;j<slen;j++){
            if(isp(s.substr(0, i)) && isp(s.substr(i, j-i)) && isp(s.substr(j, slen))){
                cout << 2 << endl;
                return 0;
            }
        }
    }

    for(int k=1;k<slen;k++){
        for(int i=k;i<slen;i++){
            for(int j=i;j<slen;j++){
                if(isp(s.substr(0, k)) && isp(s.substr(k, i-k)) && isp(s.substr(i, j-i)) && isp(s.substr(j, slen))){
                    cout << 3 << endl;
                    return 0;
                }
            }
        }
    }

    for(int k=1;k<slen;k++){
        for(int i=k;i<slen;i++){
            for(int j=i;j<slen;j++){
                for(int p=j;p<slen;p++)
                if(isp(s.substr(0, k)) && isp(s.substr(k, i-k)) && isp(s.substr(i, j-i)) && isp(s.substr(j, p-j)) && isp(s.substr(p,slen))){
                    cout << 4 << endl;
                    return 0;
                }
            }
        }
    }

    for(int k=1;k<slen;k++){
        for(int i=k;i<slen;i++){
            for(int j=i;j<slen;j++){
                for(int p=j;p<slen;p++)
                for(int t=p;t<slen;t++)
                if(isp(s.substr(0, k)) && isp(s.substr(k, i-k)) && isp(s.substr(i, j-i)) && isp(s.substr(j, p-j))
                   && isp(s.substr(p,t-p))&&isp(s.substr(t,slen))){
                    cout << 5 << endl;
                    return 0;
                }
            }
        }
    }

    for(int k=1;k<slen;k++){
        for(int i=k;i<slen;i++){
            for(int j=i;j<slen;j++){
                for(int p=j;p<slen;p++)
                for(int t=p;t<slen;t++)
                for(int o=t;o<slen;o++)
                if(isp(s.substr(0, k)) && isp(s.substr(k, i-k)) && isp(s.substr(i, j-i)) && isp(s.substr(j, p-j))
                   && isp(s.substr(p,t-p))&&isp(s.substr(t,o-t))&&isp(s.substr(o,slen))){
                    cout << 6 << endl;
                    return 0;
                }
            }
        }
    }

    for(int k=1;k<slen;k++){
        for(int i=k;i<slen;i++){
            for(int j=i;j<slen;j++){
                for(int p=j;p<slen;p++)
                for(int t=p;t<slen;t++)
                for(int o=t;o<slen;o++)
                for(int y=o;y<slen;y++)
                if(isp(s.substr(0, k)) && isp(s.substr(k, i-k)) && isp(s.substr(i, j-i)) && isp(s.substr(j, p-j))
                   && isp(s.substr(p,t-p))&&isp(s.substr(t,o-t))&&isp(s.substr(o,y-o))&&isp(s.substr(y,slen))){
                    cout << 7 << endl;
                    return 0;
                }
            }
        }
    }

    for(int k=1;k<slen;k++){
        for(int i=k;i<slen;i++){
            for(int j=i;j<slen;j++){
                for(int p=j;p<slen;p++)
                for(int t=p;t<slen;t++)
                for(int o=t;o<slen;o++)
                for(int y=o;y<slen;y++)
                for(int e=y;e<slen;e++)
                if(isp(s.substr(0, k)) && isp(s.substr(k, i-k)) && isp(s.substr(i, j-i)) && isp(s.substr(j, p-j))
                   && isp(s.substr(p,t-p))&&isp(s.substr(t,o-t))&&isp(s.substr(o,y-o))&&isp(s.substr(y,e-y))
                   &&isp(s.substr(e,slen))){
                    cout << 8 << endl;
                    return 0;
                }
            }
        }
    }

    for(int k=1;k<slen;k++){
        for(int i=k;i<slen;i++){
            for(int j=i;j<slen;j++){
                for(int p=j;p<slen;p++)
                for(int t=p;t<slen;t++)
                for(int o=t;o<slen;o++)
                for(int y=o;y<slen;y++)
                for(int e=y;e<slen;e++)
                for(int w=e;w<slen;w++)
                if(isp(s.substr(0, k)) && isp(s.substr(k, i-k)) && isp(s.substr(i, j-i)) && isp(s.substr(j, p-j))
                   && isp(s.substr(p,t-p))&&isp(s.substr(t,o-t))&&isp(s.substr(o,y-o))&&isp(s.substr(y,e-y))
                   &&isp(s.substr(e,w-e))&&isp(s.substr(w,slen))){
                    cout << 9 << endl;
                    return 0;
                }
            }
        }
    }

    for(int k=1;k<slen;k++){
        for(int i=k;i<slen;i++){
            for(int j=i;j<slen;j++){
                for(int p=j;p<slen;p++)
                for(int t=p;t<slen;t++)
                for(int o=t;o<slen;o++)
                for(int y=o;y<slen;y++)
                for(int e=y;e<slen;e++)
                for(int w=e;w<slen;w++)
                for(int q=w;q<slen;q++)
                if(isp(s.substr(0, k)) && isp(s.substr(k, i-k)) && isp(s.substr(i, j-i)) && isp(s.substr(j, p-j))
                   && isp(s.substr(p,t-p))&&isp(s.substr(t,o-t))&&isp(s.substr(o,y-o))&&isp(s.substr(y,e-y))
                   &&isp(s.substr(e,w-e))&&isp(s.substr(w,q-w))&&isp(s.substr(q,slen))){
                    cout << 10 << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
/*

*/
