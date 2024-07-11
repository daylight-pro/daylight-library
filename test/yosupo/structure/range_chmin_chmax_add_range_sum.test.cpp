#define PROBLEM \
	"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "daylight/base.hpp"
#include "daylight/structure/ch_segtree.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vll A(N);
	cin >> A;
	SegmentTreeBeats ST(A);
	while(Q-- > 0) {
		int k;
		cin >> k;
		if(k == 0) {
			int l, r;
			ll b;
			cin >> l >> r >> b;
			ST.apply_chmin(l, r, b);
		} else if(k == 1) {
			int l, r;
			ll b;
			cin >> l >> r >> b;
			ST.apply_chmax(l, r, b);
		} else if(k == 2) {
			int l, r;
			ll b;
			cin >> l >> r >> b;
			ST.apply_add(l, r, b);
		} else {
			int l, r;
			cin >> l >> r;
			cout << ST.prod_sum(l, r) << endl;
		}
	}
}