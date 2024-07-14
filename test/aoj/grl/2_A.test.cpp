#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include "daylight/base.hpp"
#include "daylight/graph/builder.hpp"
#include "daylight/graph/kruskal.hpp"

int main() {
	int V, E;
	cin >> V >> E;
	auto G = GraphBuilder<>(V, E)
				 .setIndex(0)
				 .weighted()
				 .buildEdgeList(cin);
	auto cost = kruskal(V, G);
	cout << cost << endl;
	return 0;
}