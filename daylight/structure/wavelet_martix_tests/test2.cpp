#define PROBLEM \
	"https://judge.yosupo.jp/problem/static_range_sum"
#include "daylight/base.hpp"
#include "daylight/structure/wavelet_matrix.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vll A(N);
	cin >> A;
	WaveletMatrix wm(A);
	REP(i, Q) {
		int l, r;
		cin >> l >> r;
		cout << wm.kMaxSum(l, r, r - l) << endl;
	}
	return 0;
}