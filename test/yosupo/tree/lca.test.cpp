#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "daylight/graph/lca.hpp"
#include "daylight/base.hpp"
#include "daylight/graph/graph_builder.hpp"
int main() {
	int N, Q;
	cin >> N >> Q;
	auto G = GraphBuilder<>(N)
				 .undirected()
				 .setIndex(0)
				 .useTreeFormat()
				 .build(cin);
	LCA lca(G);
	while(Q--) {
		int u, v;
		cin >> u >> v;
		cout << lca.query(u, v) << endl;
	}
}