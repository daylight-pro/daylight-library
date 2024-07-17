#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "daylight/base.hpp"
#include "daylight/structure/sparse_table.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vll A(N);
	cin >> A;
	SparseTable<ll> st(A, [](ll a, ll b) -> ll {
		return min(a, b);
	});
	REP(i, Q) {
		int l, r;
		cin >> l >> r;
		cout << st.prod(l, r) << endl;
	}
	return 0;
}