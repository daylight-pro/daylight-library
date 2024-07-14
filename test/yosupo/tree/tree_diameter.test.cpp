#define PROBLEM \
	"https://judge.yosupo.jp/problem/tree_diameter"
#include "daylight/base.hpp"
#include "daylight/graph/builder.hpp"
#include "daylight/graph/diameter.hpp"
#include "daylight/graph/lca.hpp"

int main() {
	int N;
	cin >> N;
	auto G = GraphBuilder<>(N).setIndex(0).weighted().build(
		cin);
	auto [d, p] = get_diameter(G);
	auto [u, v] = p;
	LCA lca(G);
	vi path;
	REP(i, lca.get_simple_dis(u, v) + 1) {
		path.push_back(lca.jump(u, v, i));
	}
	cout << d << " " << SZ(path) << endl;
	cout << path << endl;
}
