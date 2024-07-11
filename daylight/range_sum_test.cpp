#define PROBLEM \
	"https://judge.yosupo.jp/problem/static_range_sum"
#include "daylight/base.hpp"

#include "daylight/range_sum.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vll A(N);
	cin >> A;
	RangeSum<ll> RS(A);
	while(Q-- > 0) {
		int L, R;
		cin >> L >> R;
		cout << RS.sum(L, R) << endl;
	}
}