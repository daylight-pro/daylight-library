#define PROBLEM \
	"https://judge.yosupo.jp/problem/static_range_frequency"
#include "daylight/base.hpp"
#include "daylight/structure/wavelet_matrix.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vll A(N);
	cin >> A;
	WaveletMatrix wm(A);
	REP(i, Q) {
		int l, r, x;
		cin >> l >> r >> x;
		cout << wm.rangeFreq(l, r, x) << endl;
	}
	return 0;
}