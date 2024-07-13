#define PROBLEM \
	"https://judge.yosupo.jp/problem/jump_on_tree"
#include "daylight/base.hpp"
#include "daylight/graph/graph_builder.hpp"
#include "daylight/graph/lca.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	auto G
		= GraphBuilder<>(N).undirected().setIndex(0).build(
			cin);
	LCA lca(G);
	while(Q--) {
		int s, t, i;
		cin >> s >> t >> i;
		if(lca.get_dis(s, t) < i)
			cout << -1 << endl;
		else
			cout << lca.jump(s, t, i) << endl;
	}
	return 0;
}