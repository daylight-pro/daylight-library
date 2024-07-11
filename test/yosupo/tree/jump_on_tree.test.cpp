#define PROBLEM \
	"https://judge.yosupo.jp/problem/jump_on_tree"
#include "daylight/base.hpp"
#include "daylight/graph/base.hpp"
#include "daylight/graph/lca.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	Graph<> G(N);
	REP(i, N - 1) {
		int a, b;
		cin >> a >> b;
		G[a].eb(a, b, 1);
		G[b].eb(b, a, 1);
	}
	LCA lca(G);
	while(Q-- > 0) {
		int s, t, i;
		cin >> s >> t >> i;
		if(lca.get_dis(s, t) < i)
			cout << -1 << endl;
		else
			cout << lca.jump(s, t, i) << endl;
	}
	return 0;
}