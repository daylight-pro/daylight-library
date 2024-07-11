#include "daylight/base.hpp"
#include "daylight/string/rolling_hash.hpp"

int main() {
	string S;
	cin >> S;
	map<uint64_t, ll> mp;
	RollingHash rh(S);
	int N = SZ(S);
	REP(i, N) {
		REP(j, min(10, N - i))
		mp[rh.query(i, j + 1)]++;
	}
	int M;
	cin >> M;
	ll ans = 0;
	REP(i, M) {
		string C;
		cin >> C;
		RollingHash rh2(C);
		ans += mp[rh2.query(0, SZ(C))];
	}
	cout << ans << endl;
}