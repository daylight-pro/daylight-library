#define PROBLEM \
	"https://judge.yosupo.jp/problem/persistent_unionfind"
#include "daylight/base.hpp"
#include "daylight/structure/rollback_dsu.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	using T = tuple<int, int, int, int>;
	vector<T> queries(Q);
	map<int, vi> M;
	map<int, vi> G;
	REP(q, Q) {
		int t, k, u, v;
		cin >> t >> k >> u >> v;
		queries[q] = { t, k, u, v };
		if(t == 1)
			M[k].push_back(q);
		else
			G[k].push_back(q);
	}
	rollback_dsu dsu(N);
	vi ans(Q, -1);
	auto dfs = [&](auto f, int cur = -1) -> void {
		if(cur >= 0) {
			auto [t, k, u, v] = queries[cur];
			dsu.merge(u, v);
		}
		for(auto q: M[cur]) {
			ans[q] = dsu.same(get<2>(queries[q]),
							  get<3>(queries[q]));
		}
		for(auto to: G[cur]) {
			f(f, to);
		}
		if(cur >= 0) dsu.undo();
	};
	dfs(dfs);
	REP(i, Q) {
		if(ans[i] != -1) cout << ans[i] << endl;
	}
}