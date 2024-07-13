#define PROBLEM \
	"https://judge.yosupo.jp/problem/static_range_sum"
#include "daylight/base.hpp"
#include "daylight/structure/treap.hpp"
ll op(ll a, ll b) {
	return a + b;
}
ll e() {
	return 0;
}
ll mapping(ll f, ll x, int len) {
	return x;
}
ll composition(ll f, ll g) {
	if(f == -1) return g;
	return f;
}
ll id() {
	return -1;
}

int main() {
	int N, Q;
	cin >> N >> Q;
	vll A(N);
	cin >> A;
	Treap<ll, op, e, ll, mapping, composition, id> treap(A);
	while(Q--) {
		int l, r;
		cin >> l >> r;
		cout << treap.prod(l, r) << endl;
	}
	return 0;
}