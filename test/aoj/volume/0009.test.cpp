#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009&lang=jp"
#include "daylight/base.hpp"
#include "daylight/math/eratos.hpp"
int main() {
	vb isPrime;
	eratos(1000000, isPrime);
	int N;
	while(cin >> N) {
		int ans = 0;
		REP(i, N + 1) {
			if(isPrime[i]) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}