#define PROBLEM \
	"https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "daylight/base.hpp"
#include "daylight/graph/hld.hpp"

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
using P = pair<mint, mint>;
P op(P a, P b) {
	return { a.first * b.first,
			 a.second * b.first + b.second };
}
P op2(P a, P b) {
	return { a.first * b.first,
			 a.first * b.second + a.second };
}

P e() {
	return { 1, 0 };
}

int main() {
	int N, Q;
	cin >> N >> Q;
	HLdecomposition hld(N);
	vi a(N), b(N);
	REP(i, N) {
		cin >> a[i] >> b[i];
	}
	REP(i, N - 1) {
		int u, v;
		cin >> u >> v;
		hld.add_edge(u, v);
	}
	hld.build();
	segtree<P, op, e> seg(N);
	segtree<P, op2, e> seg2(N);
	REP(i, N) {
		seg.set(hld.index(i), { a[i], b[i] });
		seg2.set(hld.index(i), { a[i], b[i] });
	}
	while(Q-- > 0) {
		int k;
		cin >> k;
		if(k == 0) {
			int p, c, d;
			cin >> p >> c >> d;
			seg.set(hld.index(p), { c, d });
			seg2.set(hld.index(p), { c, d });
		} else {
			int u, v;
			cin >> u >> v;
			int y;
			cin >> y;
			mint x(y);
			for(auto [l, r, rev]: hld.path_query(u, v)) {
				if(rev) {
					auto [c, d] = seg2.prod(l, r);
					x = c * x + d;
				} else {
					auto [c, d] = seg.prod(l, r);
					x = c * x + d;
				}
			}
			cout << x.val() << endl;
		}
	}
}