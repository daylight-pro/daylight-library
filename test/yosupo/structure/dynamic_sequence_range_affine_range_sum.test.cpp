#define PROBLEM \
	"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "daylight/base.hpp"
#include "daylight/structure/treap.hpp"

#include <atcoder/all>
using namespace atcoder;

using mint = modint998244353;
mint op(mint a, mint b) {
	return a + b;
}

mint e() {
	return 0;
}
using F = pair<mint, mint>;

mint mapping(F f, mint x, int len) {
	return f.first * x + f.second * len;
}

F composition(F f, F g) {
	return { f.first * g.first,
			 f.first * g.second + f.second };
}

F id() {
	return { 1, 0 };
}

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<mint> A;
	REP(i, N) {
		ll a;
		cin >> a;
		A.push_back(a);
	}
	Treap<mint, op, e, F, mapping, composition, id> treap(
		A);
	while(Q--) {
		int t;
		cin >> t;
		if(t == 0) {
			int i, x;
			cin >> i >> x;
			if(i < SZ(treap))
				treap.insert(i, x);
			else
				treap.push_back(x);
		} else if(t == 1) {
			int i;
			cin >> i;
			treap.erase(i);
		} else if(t == 2) {
			int l, r;
			cin >> l >> r;
			treap.reverse(l, r);
		} else if(t == 3) {
			int l, r, b, c;
			cin >> l >> r >> b >> c;
			treap.apply(l, r, { b, c });
		} else {
			int l, r;
			cin >> l >> r;
			cout << treap.prod(l, r).val() << endl;
		}
	}
	return 0;
}