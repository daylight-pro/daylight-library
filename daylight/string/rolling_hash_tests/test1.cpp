#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "daylight/base.hpp"
#include "daylight/string/rolling_hash.hpp"

int main() {
	string S;
	cin >> S;
	RollingHash rh(S);
	int N = SZ(S);
	vi ans(N);
	REP(i, N) {
		int len = N - i;
		int ok = 0;
		int ng = len + 1;
		while(ng - ok > 1) {
			int mid = (ok + ng) / 2;
			if(rh.query(0, mid) == rh.query(i, mid)) {
				ok = mid;
			} else {
				ng = mid;
			}
		}
		ans[i] = ok;
	}
	cout << ans << endl;
}