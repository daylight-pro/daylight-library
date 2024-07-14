#define PROBLEM "https://yukicoder.me/problems/no/1097"
#include "daylight/base.hpp"
#include "daylight/doubling.hpp"

int main() {
	int N;
	cin >> N;
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
	int Q;
	cin >> Q;
	while(Q--) {
		ll K;
		cin >> K;
		cout << doubling.prod(K, 0) << endl;
	}
	return 0;
}