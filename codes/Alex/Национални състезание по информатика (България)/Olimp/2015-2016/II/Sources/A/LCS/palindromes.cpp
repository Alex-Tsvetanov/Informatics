#include<iostream>
#include<string>
using namespace std;

string s;
int from = 0;
int to = 0;
int counter = 0;
int savepoint = 0;

void output(){
     cout<<counter<<endl;
     }

bool check(bool vinkel, int from, int to) {
     int medium = (to - from + to%2)/2 ;
      if(to >= medium ) {
             if(s[from] == s[to])
              {
                    from += 1;
                    to -= 1;
                    if(from+1 != to && from!= to) {

                    return check(vinkel, from, to);
                    }
                    else {
                         vinkel = true;
                         savepoint = to + medium;
                         }
                     }

             else {

                 return  false;
                  }
               }


          }

void input(int from, int to) {
     if(to >= (s.length() + s.length()%2 )/2 ) {

     bool vinkel = check(vinkel, from, to);

     if(vinkel == false) {
               to -= 1;
      }

     else {
               from = savepoint + 1;
               to = s.length() - 1;
               counter+=1;
     }
     input(from, to);

     }

}


int main() {
    cin>>s;


    to = s.length() - 1;
    input(from, to);
    output();


    return 0;
}



