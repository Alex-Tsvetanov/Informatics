/* fopen example */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

fstream fs;
long long N, N1, br, br1;
vector <int> v[501];

int main (int argc, char *argv[])
{
int i,j,i1,j1;	
// вход автор
//  fs.open ("virus.06.in", fstream::in | fstream::out | fstream::app);
  fs.open (argv[1], fstream::in | fstream::out | fstream::app);
  if (fs.is_open())
  {
    fs >>N;
    fs.close();
  }
  else
  {
    cout << "Error opening file 1\n";
  }
// изход автор
//  fs.open ("virus.06.sol", fstream::in | fstream::out | fstream::app);
  fs.open (argv[2], fstream::in | fstream::out | fstream::app);
  if (fs.is_open())
  {
     	fs>>br;
    fs.close();
  }
  else
  {
    cout << "Error opening file 2\n";
  }
// *.sol на ученика
//  fs.open ("virus.sol", fstream::in | fstream::out | fstream::app);
  fs.open (argv[3], fstream::in | fstream::out | fstream::app);
  if (fs.is_open())
  {
   		fs>>br1;
   		if (br!=br1) {
   			cout<<0<<endl;
   			cout<<"Ne sywpada K !"<<endl;
   			return 0;
		   }
     	if (N<=500) {
			for (i=1; i<=br; i++) {
				int b,c;
				fs>>b;
				for (j=1; j<=b; j++) {
					fs>>c;
					if (c<1 || c>N) {
						cout<<0<<endl;
						cout<<"Izwyn granici !"<<endl;
						return 0;
					}
					v[c].push_back(i);
				}
			}     		
			for (i=1; i<=N-1; i++)
				for (i1=i+1; i1<=N; i1++) {
					if (v[i].size()==v[i1].size()){
						int broj=0;
						for (j1=0; j1<v[i1].size();j1++) {
							if (j1<=v[i].size()){
								for (j=0; j<v[i].size(); j++) {
									if (v[i][j]==v[i1][j1]) {
										broj++;
										break;
									}
								}
							}
							else
							break;
						}
						if (broj>0)
							if (broj==v[i].size()) {
								cout<<0<<endl;
								cout<<"Sywpada dwojka !"<<endl;
								return 0;
							}
						
					}
				} 
			
		 }
    fs.close();
  }
  else
  {
    cout << "Error opening file 3\n";
  }

	
	cout<<1<<endl;
  return 0;
}
