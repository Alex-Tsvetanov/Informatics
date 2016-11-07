/*
* Podvejda6ti ograni4eniq - n < 10^6 navejda na misulta za O(N), a ne O(NlogN).
* Ina4e hubava, leko opleteno sortirane, ne e ne6to nestandartno.
* 5 / 8
*/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>

//#define DEBUG

const int MAX_N = 1000000 + 42 + 69;

std::pair<int, int> req[MAX_N];
int reqCnt;
int crewCnt;

void input() {
	int dayCnt;
	scanf("%i %i %i", &dayCnt, &reqCnt, &crewCnt);
	crewCnt >>= 1;
	
	for (int32_t i = 0;i < reqCnt;i++) {
		scanf("%i %i", &req[i].first, &req[i].second);
		req[i].first--;
		req[i].second--;
	}
	std::sort(req, req + reqCnt);
}

bool handle_queue(std::priority_queue<int> &q, int from, int to) {
	int curDay = 0;
	while ((from < to) && (not q.empty())) {
		if (-q.top() >= from) {
			curDay++;
#ifdef DEBUG
			printf("Fitted until %i at %i\n", -q.top(), from);
#endif
			if (curDay == crewCnt) {
				from++;
				curDay = 0;
			}
		} else {
#ifdef DEBUG
			printf("Fucked up %i at %i\n", -q.top(), from);
#endif
			return false;
		}
		q.pop();
	}
	
	return true;
}
bool is_possib() {
	std::priority_queue<int> ending;
	int curT = 0;
	for (int i = 0;i < reqCnt;i++) {
#ifdef DEBUC
		printf("Queries before %i (curT %i)\n", req[i].first, curT);
#endif
		if (not handle_queue(ending, curT, req[i].first)) {
			return false;
		}
		ending.push(-req[i].second);
		curT = req[i].first;
	}
	return handle_queue(ending, curT, 2000000000);
}

inline int get_norm_date(int d) {
	return d / 7 + d % 7 - (d % 7 == 6);
}
void compress_date() {
	for (int32_t i = 0;i < reqCnt;i++) {
		int d = req[i].first;
		req[i].first =  (d / 7) * 5 + d % 7 + (d % 7 >= 6);
		d = req[i].second;
		req[i].second = (d / 7) * 5 + d % 7 - (d % 7 >= 5) * (d % 7 - 4);
#ifdef DEBUG
		printf("(%i %i)\n", req[i].first, req[i].second);
#endif
	}
}

int main() {
	input();
	bool allDay = is_possib();
	compress_date();
	bool workDay = is_possib();
	if (workDay) {
		printf("OK\n");
	} else if (allDay) {
		printf("MIXED\n");
	} else {
		printf("IMPOSSIBLE\n");
	}
}
