#define PROBLEM \
	"https://judge.yosupo.jp/problem/point_add_range_sum"
#include "daylight/base.hpp"
#include "daylight/structure/dynamic_wavelet_matrix.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vll A(N);
	cin >> A;
	DynamicWaveletMatrix wm(A);
	REP(i, Q) {
		int t;
		cin >> t;
		if(t == 0) {
			int p;
			ll x;
			cin >> p >> x;
			wm.update(p, wm[p] + x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << wm.kMaxSum(l, r, r - l) << endl;
		}
	}
	return 0;
}