/**
* Zdraveite,
*
* Bih jelal da napravq obru6tenie kum avtora na tazi zada4a: Za6to po dqvolite
* si pomislihte, 4e da se vuvejda do krai na vhoda e dobra ideq ? V koi vek 
* jiveem - 19-ti ? Az 6te se opravq nqkaksi (nadqvam se) dori i da e po ne 
* osobeno civilizovan na4in. Problemut e, 4e ima sustezateli (nqma da gi nari4am 
* "deca", kolkoto i da mi se iska, za6toto nqkoi sa po-vuzrastni ot men), koito 
* znaqt kak da re6at zada4ata, no nqma da uspeqt da si napravqt vhoda. Tova li e 
* celta na tazi olimpiada - kolko dobre se znaqt trikovete na suotvetniq ezik ? 
* Vsi4ko e napraveno zna4itelno po-lo6o ot fakta, 4e nqma sistema, koqto da kaje 
* dali haka za 4etene do krai na vhoda raboti na testva6tata ma6ina (za6toto 
* tezi, koito ne znaqt "civilizovaniq" na4in za 4etene do krai na vhoda (kato 
* men), 6te polzvat nqkakva forma na hak, za da si podkarat zada4ata). Molq,
* ne pravete pove4e zada4i, v koito e po-trudno da se napravi vhoda, ot kolkoto
* da se re6i zada4ata.
* Molq.
*
* Blagodarq za otedelenoto vreme
*  - Alexander "Per4ema" Crustev
*/

#include <cstdio>
#include <vector>
#include <utility>
#include <deque>

const int MAX_N = 200000 + 42 + 69;

struct Vertex;

struct Edge {
	Vertex *to;
	int cost;
	
	Edge() {}
	Edge(Vertex *pTo, int pCost) {
		to = pTo;
		cost = pCost;
	}
};

struct Vertex {
	std::vector<Edge> edges;
	
	int minDist;
	
	Vertex() {
		minDist = -42;
	}
};
Vertex graph[MAX_N];
int vertCnt;
Vertex *start, *dest;

void input() {
	int s, d;
	scanf("%i %i %i", &vertCnt, &s, &d);
	
	start = &graph[s];
	dest = &graph[d];
	
	while (scanf("%i %i", &s, &d) > 0) {
		graph[s].edges.push_back(Edge(&graph[d], 0));
		graph[d].edges.push_back(Edge(&graph[s], 1));
	}
}

void djikstra() {
	std::deque<std::pair<int, Vertex*> > next;
	next.push_front(std::make_pair(0, start));
	start->minDist = 0;
	
	while (not next.empty()) {
		Vertex *cur = next.front().second;
		int qDist = next.front().first;
		next.pop_front();
		
		if (cur->minDist != qDist) {
			continue;
		}
		
		for (int i = 0;i < cur->edges.size();i++) {
			Edge &e = cur->edges[i];
			if ((e.to->minDist < 0) || (e.to->minDist > 
					cur->minDist + e.cost)) {
				e.to->minDist = cur->minDist + e.cost;
				std::pair<int, Vertex*> c(e.to->minDist, e.to);
				
				if (e.cost == 0) {
					next.push_front(c);
				} else {
					next.push_back(c);
				}
			}
		}
	}
}

int main() {
	input();
	djikstra();
	if (dest->minDist < 0) {
		printf("X\n");
	} else {
		printf("%i\n", dest->minDist);
	}
}
