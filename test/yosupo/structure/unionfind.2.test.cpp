#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "daylight/base.hpp"
#include "daylight/structure/rollback_dsu.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	rollback_dsu dsu(N);
	while(Q--) {
		int t, u, v;
		cin >> t >> u >> v;
		if(t == 0) {
			dsu.merge(u, v);
		} else {
			cout << dsu.same(u, v) << endl;
		}
	}
}