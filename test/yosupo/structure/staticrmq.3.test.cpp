#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "daylight/base.hpp"
#include "daylight/structure/dynamic_wavelet_matrix.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vll A(N);
	cin >> A;
	DynamicWaveletMatrix wm(A);
	REP(i, Q) {
		int l, r;
		cin >> l >> r;
		cout << wm.kthMin(l, r, 0) << endl;
	}
	return 0;
}