//Task: fence
//Author: Kinka Kirilova-Lupanova

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkPossibility(int n, long long k, long long mid,
                      const vector <long long>& wishes) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		long long cur = min(k - sum, max(wishes[i] - sum, mid));
		if (cur < mid)
			return false;
	   	sum += cur;
	}

	return true;
}

int main() {
    int n;
    long long k;
    vector <long long> wishes;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
    	long long w;
    	cin >> w;
    	wishes.push_back(w);
    }
   	sort(wishes.begin(), wishes.end());

   	long long lb = 0, rb = wishes[0];
   	while (lb < rb) {
   		long long mid = (lb + rb + 1) / 2;
   		if (checkPossibility(n, k, mid, wishes)) {
   			lb = mid;
   		} else {
   			rb = mid - 1;
   		}
   	}

   	cout << lb << endl;
    return 0;
}
