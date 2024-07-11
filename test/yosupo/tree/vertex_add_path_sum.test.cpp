#define PROBLEM \
	"https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "daylight/base.hpp"
#include "daylight/graph/hld.hpp"

#include <atcoder/all>
using namespace atcoder;

int main() {
	int N, Q;
	cin >> N >> Q;
	vi A(N);
	cin >> A;
	HLdecomposition hld(N);
	REP(i, N - 1) {
		int u, v;
		cin >> u >> v;
		hld.add_edge(u, v);
	}
	hld.build();
	fenwick_tree<ll> fw(N);
	REP(i, N) {
		fw.add(hld.index(i), A[i]);
	}
	while(Q-- > 0) {
		int k;
		cin >> k;
		if(k == 0) {
			int p, x;
			cin >> p >> x;
			fw.add(hld.index(p), x);
		} else {
			int u, v;
			cin >> u >> v;
			ll ans = 0;
			for(auto [l, r, rev]: hld.path_query(u, v)) {
				ans += fw.sum(l, r);
			}
			cout << ans << endl;
		}
	}
}