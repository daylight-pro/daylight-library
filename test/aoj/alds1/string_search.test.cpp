#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include "daylight/base.hpp"
#include "daylight/string/rolling_hash.hpp"

int main() {
	string P, T;
	cin >> P >> T;
	RollingHash hP(P), hT(T);
	int N = SZ(T);
	REP(i, SZ(P) - SZ(T) + 1) {
		if(hP.query(i, N) == hT.query(0, N)) {
			cout << i << endl;
		}
	}
}