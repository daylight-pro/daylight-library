#define PROBLEM \
	"https://judge.yosupo.jp/problem/primality_test"
#include "daylight/math/primality_test.hpp"
#include "daylight/base.hpp"

int main() {
	int Q;
	cin >> Q;
	while(Q--) {
		ll N;
		cin >> N;
		if(is_prime(N)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}