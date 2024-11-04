#include <atcoder/all>
#include "daylight/base.hpp"
using namespace atcoder;

struct ProjectSelection {
	struct Edge {
		int from, to;
		ll cap;
	};
	enum Condition { LESS_THAN, GREATER_THAN, LESS_EQUAL, GREATER_EQUAL };
	enum Logic { OR, AND, NOR, NAND };
	static constexpr ll inf = numeric_limits<ll>::max();
	int N;
	vi start;
	vvll cost;
	vi choices;
	long long ans;
	mf_graph<ll> G;
	vector<Edge> edges;

	int s, t, next;

private:
	void add(ll &x, ll c) {
		if(x == inf)
			return;
		else if(c == inf)
			x = c;
		else
			x += c;
	}

public:
	ProjectSelection(vi choices): choices(choices) {
		N = SZ(choices);
		start = vi(N + 1);
		start[0] = 0;
		REP(i, N) {
			assert(choices[i] >= 2);
			start[i + 1] = start[i] + choices[i] - 1;
		}
		cost = vvll(N);
		REP(i, N) cost[i] = vll(choices[i], 0);
		s = start[N];
		t = s + 1;
		next = s + 2;
		ans = 0;
	}

	ll get_inf() {
		return inf;
	}

	/// @brief 単純にコストcを加算する
	/// @param c コスト
	void add_cost(ll c) {
		assert(c < inf && "value out of bound");
		ans += c;
	}

	/// @brief 各選択肢を選んだ時の損失を
	/// @param i 対象の選択番号
	/// @param c c[j]:選択番号iでj個目の選択肢を選んだ時の損失
	void add_cost(int i, vll c) {
		assert(0 <= i && i < N && "index out of bound");
		assert(choices[i] == SZ(c));
		REP(j, choices[i]) {
			add(cost[i][j], c[j]);
		}
	}

	void add_cost(int a, int b, vvll c) {
		assert(0 <= a && a < N && "index out of bound");
		assert(0 <= b && b < N && "index out of bound");
		assert(a != b);
		assert((SZ(c) == choices[a]));
		REP(i, choices[a]) {
			assert(SZ(c[i]) == choices[b]);
		}
		assert(false && "not implemented");
	}

	/// @brief 複数の条件を満たすときcostの損失
	/// @param V [k,v,cond]:
	/// k番目の選択でvの選択肢とcondによってあらわされる選択肢を選ぶという条件
	/// @param cost 条件をすべて満たすときに発生する損失
	/// @param logic 複数の条件をまとめる論理式
	void add_cost(vector<tuple<int, int, Condition>> V, ll cost, Logic logic) {
		if(logic == NOR) {
			ans += cost;
			cost = -cost;
			logic = OR;
		}
		if(logic == AND) {
			ans += cost;
			cost = -cost;
			logic = NAND;
		}
		if(logic == NAND) {
			for(auto &&[k, v, cond]: V) {
				if(cond == LESS_THAN) {
					cond = GREATER_EQUAL;
				} else if(cond == GREATER_THAN) {
					cond = LESS_EQUAL;
				} else if(cond == LESS_EQUAL) {
					cond = GREATER_THAN;
				} else if(cond == GREATER_EQUAL) {
					cond = LESS_THAN;
				}
			}
		}
		if(cost < 0) {
			ans += cost;
			cost = -cost;
			for(auto &&[k, v, cond]: V) {
				if(cond == LESS_THAN) {
					cond = GREATER_EQUAL;
				} else if(cond == GREATER_THAN) {
					cond = LESS_EQUAL;
				} else if(cond == LESS_EQUAL) {
					cond = GREATER_THAN;
				} else if(cond == GREATER_EQUAL) {
					cond = LESS_THAN;
				}
			}
		}
		for(auto &&[k, v, cond]: V) {
			assert(0 <= k && k < N && "index out of bound");
			assert(0 <= v && v < choices[k] && "index out of bound");
			if(cond == LESS_THAN) {
				v--;
				cond = LESS_EQUAL;
			}
			if(cond == GREATER_THAN) {
				v++;
				cond = GREATER_EQUAL;
			}
			if(cond == GREATER_EQUAL && v <= 0) {
				return;
			}
			if(cond == LESS_EQUAL && v >= choices[k] - 1) {
				return;
			}
		}
		vi left, right;
		for(auto &&[k, v, cond]: V) {
			if(cond == GREATER_EQUAL) {
				if(v >= choices[k]) continue;
				left.push_back(start[k] + v - 1);
			} else if(cond == LESS_EQUAL) {
				if(v < 0) continue;
				right.push_back(start[k] + v);
			}
		}
		if(left.empty() && right.empty())
			return;
		else if(left.empty()) {
			int sv = next++;
			for(auto &&r: right) {
				edges.emplace_back(sv, r, inf);
			}
			edges.emplace_back(s, sv, cost);
		} else if(right.empty()) {
			int tv = next++;
			for(auto &&l: left) {
				edges.emplace_back(l, tv, inf);
			}
			edges.emplace_back(tv, t, cost);
		} else {
			int sv = next++;
			int tv = next++;
			for(auto &&r: right) {
				edges.emplace_back(sv, r, inf);
			}
			for(auto &&l: left) {
				edges.emplace_back(l, tv, inf);
			}
			edges.emplace_back(tv, sv, cost);
			edges.emplace_back(sv, tv, inf);
		}
	}

	ll solve() {
		G = mf_graph<ll>(next);
		REP(i, N) {
			REP(j, choices[i] - 2) {
				G.add_edge(start[i] + j + 1, start[i] + j, inf);
			}
			ll mc = inf;
			REP(j, choices[i]) {
				chmin(mc, cost[i][j]);
			}
			if(mc == inf) return inf;
			add_cost(mc);
			REP(j, choices[i]) {
				add(cost[i][j], -mc);
			}
			REP(j, choices[i]) {
				if(cost[i][j] == 0) continue;
				if(j == 0)
					G.add_edge(s, start[i] + j, cost[i][j]);
				else if(j == choices[i] - 1)
					G.add_edge(start[i] + j - 1, t, cost[i][j]);
				else
					G.add_edge(start[i] + j - 1, start[i] + j, cost[i][j]);
			}
		}
		for(auto &e: edges) {
			G.add_edge(e.from, e.to, e.cap);
		}
		ll flow = G.flow(s, t, inf);
		if(flow == inf) return inf;
		return ans + flow;
	}
};
