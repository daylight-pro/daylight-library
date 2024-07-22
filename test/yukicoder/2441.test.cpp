#define PROBLEM "https://yukicoder.me/problems/no/2441"
#include "daylight/base.hpp"
#include "daylight/math/matrix.hpp"

int main() {
	vvi M(2, vi(2));
	cin >> M;
	auto ans = powMatrix(M, 3);
	REP(i, 2) {
		cout << ans[i] << endl;
	}
}