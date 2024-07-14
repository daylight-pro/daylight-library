#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "daylight/base.hpp"
#include "daylight/math/rho.hpp"

int main() {
	int Q;
	cin >> Q;
	while(Q--) {
		ll N;
		cin >> N;
		auto mp = factorize(N);
		vll ans;
		for(auto [k, v]: mp) {
			REP(_, v) ans.push_back(k);
		}
		cout << SZ(ans) << " " << ans << endl;
	}
}