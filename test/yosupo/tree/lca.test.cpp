#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "daylight/base.hpp"
#include "daylight/graph/base.hpp"
#include "daylight/graph/lca.hpp"
int main() {
	int N, Q;
	cin >> N >> Q;
	Graph<> G(N);
	FOR(i, 1, N) {
		int P;
		cin >> P;
		G[P].eb(P, i, 1);
		G[i].eb(i, P, 1);
	}
	LCA lca(G);
	while(Q-- > 0) {
		int u, v;
		cin >> u >> v;
		cout << lca.query(u, v) << endl;
	}
}