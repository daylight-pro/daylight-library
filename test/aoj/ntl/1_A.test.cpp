#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja"
#include "daylight/base.hpp"
#include "daylight/math/prime_factor.hpp"

int main() {
	int N;
	cin >> N;
	cout << N << ":";
	for(auto [k, v]: prime_factor(N)) {
		REP(_, v) {
			cout << " " << k;
		}
	}
	cout << endl;
	return 0;
}