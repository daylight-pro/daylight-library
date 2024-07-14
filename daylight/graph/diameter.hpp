#include "daylight/base.hpp"
#include "daylight/graph/base.hpp"

/// @brief 木の直径を求める

namespace inner_diameter {
pair<ll, int> dfs(int cur, int pre, Graph<> &G) {
	pair<ll, int> p { 0, cur };
	for(Edge e: G[cur]) {
		if(e.to == pre) continue;
		auto [dis, v] = dfs(e.to, cur, G);
		chmax(p, { dis + e.cost, v });
	}
	return p;
}
}

pair<ll, pair<int, int>> get_diameter(Graph<> &G) {
	auto [dis, v] = inner_diameter::dfs(0, -1, G);
	auto [dis2, v2] = inner_diameter::dfs(v, -1, G);
	return { dis2, { v, v2 } };
}