#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276"
#include "daylight/base.hpp"
#include "daylight/math/primality_test.hpp"

int main() {
	int K;
	cin >> K;
	while(K != 0) {
		if(is_prime(K)) {
			cout << 0 << endl;
			cin >> K;
			continue;
		}
		int ans = 1;
		for(int i = K; !is_prime(i); i++) {
			ans++;
		}
		for(int i = K - 1; !is_prime(i); i--) {
			ans++;
		}
		cout << ans << endl;
		cin >> K;
	}
}