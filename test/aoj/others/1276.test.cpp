#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276"
#include "daylight/base.hpp"
#include "daylight/math/eratos.hpp"

int main() {
	int K;
	cin >> K;
	vb isPrime;
	eratos(1299710, isPrime);
	while(K != 0) {
		if(isPrime[K]) {
			cout << 0 << endl;
			cin >> K;
			continue;
		}
		int ans = 1;
		for(int i = K; !isPrime[i]; i++) {
			ans++;
		}
		for(int i = K - 1; !isPrime[i]; i--) {
			ans++;
		}
		cout << ans << endl;
		cin >> K;
	}
}