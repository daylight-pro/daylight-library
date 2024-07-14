#define PROBLEM "https://yukicoder.me/problems/no/1013"
#include "daylight/base.hpp"
#include "daylight/doubling.hpp"

int main() {
	int N, K;
	cin >> N >> K;
	vll P(N);
	cin >> P;
	vi A(N);
	REP(i, N) {
		A[i] = P[i] + i;
		A[i] %= N;
	}
	Doubling<ll> doubling(A);
	doubling.setMonoid(
		P,
		[](ll a, ll b) {
			return a + b;
		},
		[]() {
			return 0;
		});
	REP(i, N) {
		cout << doubling.prod(K, i) + i + 1 << endl;
	}
	return 0;
}