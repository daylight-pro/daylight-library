#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "daylight/graph/lca.hpp"
#include "daylight/base.hpp"
#include "daylight/graph/graph_builder.hpp"
int main() {
	int N, Q;
	cin >> N >> Q;
	auto G = TreeBuilder<>(N)
				 .setDirected(false)
				 .setIndex(0)
				 .build(cin);
	LCA lca(G);
	while(Q-- > 0) {
		int u, v;
		cin >> u >> v;
		cout << lca.query(u, v) << endl;
	}
}