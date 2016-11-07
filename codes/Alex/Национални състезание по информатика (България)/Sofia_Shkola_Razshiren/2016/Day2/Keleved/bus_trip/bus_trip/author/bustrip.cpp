#include <cstdio>
#include <cinttypes>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

const int32_t INF = 1e9;

class Vertex;

class Edge {
public:
	Vertex *to;
	int32_t depart, arrive;
	int32_t travel;

	static bool startCompare(const Edge &e1, const Edge &e2) {
		return e1.depart < e2.depart;
	}
};

const int32_t MAX_V = 50000;

class Vertex {
public:
	std::vector<Edge> edges;
	std::vector<int32_t> arrT;

	int64_t maxTravel;

	int32_t nextA;
	int32_t nextE;

	Vertex(): maxTravel(0), nextA(0), nextE(0) {}
};

Vertex graph[MAX_V];
int32_t vertCnt;
int32_t targT;
Vertex *targV;

void input() {
	int32_t eCnt;
	int32_t targInd;
	scanf("%" SCNi32 "%" SCNi32 "%" SCNi32 "%" SCNi32,
			&vertCnt, &eCnt, &targInd, &targT);
	targV = &graph[targInd - 1];

	for (int32_t i = 0;i < eCnt;i++) {
		int32_t from, to;
		int32_t departLate, arriveEarly;
		Edge e;

		scanf("%" SCNi32 "%" SCNi32, &from, &to);
		scanf("%" SCNi32 "%" SCNi32, &e.depart, &departLate);
		scanf("%" SCNi32 "%" SCNi32, &arriveEarly, &e.arrive);

		e.travel = arriveEarly - departLate;
		e.to = &graph[to - 1];

		graph[from - 1].edges.push_back(e);
	}
}

void precompute() {
	for (int32_t i = 0;i < vertCnt;i++) {
		for (Edge &e : graph[i].edges) {
			e.to->arrT.push_back(e.arrive);
		}
	}
	for (int32_t i = 0;i < vertCnt;i++) {
	    std::sort(graph[i].edges.begin(), graph[i].edges.end(), Edge::startCompare);
	    std::sort(graph[i].arrT.begin(), graph[i].arrT.end());
	}
}

class Arrival {
public:
	Vertex *v;
	int64_t travel;
	int64_t time;

	Arrival(Vertex *pV = nullptr, int64_t pTr = 0, int64_t pT = 0):
		v(pV), travel(pTr), time(pT) {}

};
bool operator< (const Arrival &a1, const Arrival &a2) {
	return a1.time > a2.time;
}

int32_t solve() {
	std::priority_queue<Arrival> nextArr;

	Vertex *v = &graph[0];
	while ((v->nextE < v->edges.size()) &&
			((v->nextA >= v->arrT.size()) ||
			 (v->arrT[v->nextA] > v->edges[v->nextE].depart))) {

		const Edge &e = v->edges[v->nextE];
		nextArr.push(Arrival(e.to, e.travel, e.arrive));
		v->nextE++;
	}

	int64_t maxTravel = -2 * targT;
	if (&graph[0] == targV) {
		maxTravel = 0;
	}
	while (not nextArr.empty()) {
		Arrival cur = nextArr.top();
		Vertex *v = cur.v;
		nextArr.pop();


		if (cur.time > targT) {
			break;
		}
		if (v == targV) {
			maxTravel = std::max(maxTravel, cur.travel);
		}

		v->maxTravel = std::max(cur.travel, v->maxTravel);
		v->nextA++;

		while ((v->nextE < v->edges.size()) &&
				(v->edges[v->nextE].depart < cur.time)) {
			const Edge &e = v->edges[v->nextE];
			nextArr.push(Arrival(e.to, - 2 * targT, e.arrive));
			v->nextE++;
		}

		while ((v->nextE < v->edges.size()) &&
				((v->nextA >= v->arrT.size()) ||
				 (v->arrT[v->nextA] > v->edges[v->nextE].depart))) {

			const Edge &e = v->edges[v->nextE];

			nextArr.push(Arrival(e.to, v->maxTravel + e.travel, e.arrive));
			v->nextE++;
		}
	}
	return (maxTravel >= 0) ? targT - maxTravel : -1;
}

int main() {
	input();
	precompute();
	printf("%i\n", solve());
	return 0;
}
