#include<iostream>
#include<algorithm>

using namespace std;

template<class t>
class sorting
{
	public:
		sorting (t *list, int size)
		{
			make_heap (list,list+size);
			sort_heap (list,list+size);
		}
};

int main() {

	int* idata;
	int n;
	cin >> n;
	idata = new int [n];
	for (int i = 0 ; i < n ; i ++)
		cin >> idata [i];
	sorting <int> (idata, n);
	for(int i = 0; i < n ; i ++)
		cout << idata[i] << " ";
	cout << "\b\n";
}
