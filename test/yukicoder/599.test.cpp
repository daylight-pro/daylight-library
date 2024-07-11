#define PROBLEM "https://yukicoder.me/problems/no/599"
#include "daylight/base.hpp"
#include "daylight/string/rolling_hash.hpp"

#include "atcoder/modint"
using namespace atcoder;
using mint = modint1000000007;

int main() {
	string S;
	cin >> S;
	int N = SZ(S);
	RollingHash rh(S);
	auto dp = vector<mint>(N + 1);
	dp[0] = 1;
	FOR(i, 1, N + 1) {
		if(i + i > N) break;
		REP(j, i) {
			if(rh.query(j, i - j)
			   == rh.query(N - j - (i - j), i - j)) {
				dp[i] += dp[j];
			}
		}
	}
	mint ans = 0;
	REP(i, N + 1) {
		ans += dp[i];
	}
	cout << ans.val() << endl;
}