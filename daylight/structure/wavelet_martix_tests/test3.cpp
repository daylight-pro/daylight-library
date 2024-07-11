#define PROBLEM \
	"https://judge.yosupo.jp/problem/range_kth_smallest"
#include "daylight/base.hpp"
#include "daylight/structure/wavelet_matrix.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vll A(N);
	cin >> A;
	WaveletMatrix wm(A);
	REP(i, Q) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << wm.kthMin(l, r, k - 1) << endl;
	}
	return 0;
}