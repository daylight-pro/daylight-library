#include "daylight/base.hpp"
#include "daylight/graph/base.hpp"
/// @brief Lowest Common Ancestor
struct LCA {
private:
	static constexpr int max_bit = 20;
	int K = 1;
	vector<array<int, max_bit>> parent;
	vi dis;
	vi simple_dis;
	void dfs(int cur, int pre, const Graph<>& G, int d,
			 int sd) {
		parent[cur][0] = pre;
		dis[cur] = d;
		simple_dis[cur] = sd;
		for(auto e: G[cur]) {
			if(e.to == pre) continue;
			dfs(e.to, cur, G, d + e.cost, sd + 1);
		}
	}

public:
	LCA(const Graph<>& G) {
		int N = SZ(G);
		while((1 << K) < N) K++;
		parent = vector<array<int,max_bit>>(N);
		REP(i, N){
			REP(j, max_bit){
				parent[i][j] = -1;
			}
		}
		dis = vi(N, -1);
		simple_dis = vi(N, -1);
		dfs(0, -1, G, 0, 0);
		REP(i, K - 1) {
			REP(j, N) {
				if(parent[j][i] < 0) {
					parent[j][i + 1] = -1;
				} else {
					parent[j][i + 1]
						= parent[parent[j][i]][i];
				}
			}
		}
	}
	/// @brief uとvの根をrootとした時のLCAを求める
	/// @param u クエリの頂点1
	/// @param v クエリの頂点2
	/// @param root クエリの根
	/// @return LCAの頂点番号
	int query(int u, int v, int root) {
		return query(u, v) ^ query(v, root)
			^ query(u, root);
	}
	/// @brief uとvの根を0とした時のLCAを求める
	/// @param u クエリの頂点1
	/// @param v クエリの頂点2
	/// @return LCAの頂点番号
	int query(int u, int v) {
		assert(u >= 0 && v >= 0 && u < SZ(simple_dis)
			   && v < SZ(simple_dis)
			   && "invalid vertex index");
		if(simple_dis[u] < simple_dis[v]) swap(u, v);
		REP(i, K) {
			if((simple_dis[u] - simple_dis[v]) >> i & 1) {
				u = parent[u][i];
			}
		}
		if(u == v) return u;
		REPR(i, K) {
			if(parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		return parent[u][0];
	}

	/// @brief 頂点fromから頂点toに向かってcnt回たどった位置にある頂点
	/// @param from 始点
	/// @param to 終点
	/// @param cnt たどる回数
	/// @return 頂点番号(存在しない場合は-1)
	int jump(int from, int to, int cnt) {
		if(cnt < 0 || get_simple_dis(from, to) < cnt) {
			return -1;
		}
		int l = query(from, to);
		if(cnt <= get_simple_dis(from, l)) {
			int cur = from;
			REP(i, K) {
				if(cnt >> i & 1) {
					cur = parent[cur][i];
				}
			}
			return cur;
		}
		cnt = get_simple_dis(from, to) - cnt;
		int cur = to;
		REP(i, K) {
			if(cnt >> i & 1) {
				cur = parent[cur][i];
			}
		}
		return cur;
	}

	/// @brief uとvの距離を求める
	/// @param u クエリの頂点1
	/// @param v クエリの頂点2
	/// @return 距離
	int get_dis(int u, int v) {
		assert(u >= 0 && v >= 0 && u < SZ(dis)
			   && v < SZ(dis) && "invalid vertex index");
		return dis[u] + dis[v] - 2 * dis[query(u, v)];
	}
	/// @brief 全ての辺のコストを1とした時のuとvの距離を求める
	/// @param u クエリの頂点1
	/// @param v クエリの頂点2
	/// @return 距離
	int get_simple_dis(int u, int v) {
		assert(u >= 0 && v >= 0 && u < SZ(simple_dis)
			   && v < SZ(simple_dis)
			   && "invalid vertex index");
		return simple_dis[u] + simple_dis[v]
			- 2 * simple_dis[query(u, v)];
	}
};