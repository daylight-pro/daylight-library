#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp"
#include "daylight/base.hpp"
#include "daylight/graph/builder.hpp"
#include "daylight/graph/dijkstra.hpp"

int main() {
	int V, E, r;
	cin >> V >> E >> r;
	auto G = GraphBuilder<>(V, E)
				 .weighted()
				 .directed()
				 .setIndex(0)
				 .build(cin);
	auto d = dijkstra(r, G);
	for(auto x: d) {
		if(x == LINF)
			cout << "INF" << endl;
		else
			cout << x << endl;
	}
}