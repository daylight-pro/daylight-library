#define PROBLEM \
	"https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include <atcoder/fenwicktree>
#include "daylight/base.hpp"
#include "daylight/graph/hld.hpp"
using namespace atcoder;

int main() {
	int N, Q;
	cin >> N >> Q;
	vi A(N);
	cin >> A;
	HLdecomposition hld(N);
	FOR(i, 1, N) {
		int p;
		cin >> p;
		hld.add_edge(p, i);
	}
	hld.build();
	fenwick_tree<ll> fw(N);
	REP(i, N) fw.add(i, A[i]);
	while(Q--) {
		int k;
		cin >> k;
		if(k == 0) {
			int u, x;
			cin >> u >> x;
			fw.add(hld.index(u), x);
		} else {
			int u;
			cin >> u;
			auto [l, r] = hld.subtree_query(u);
			cout << fw.sum(l, r) << endl;
		}
	}
}