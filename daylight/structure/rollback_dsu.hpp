#include "daylight/base.hpp"
/// @brief スナップショットを撮って，その時点までロールバックできるDSU
class rollback_dsu {
public:
	int N;
	vi p;
	stack<PI> history;
	rollback_dsu() {
	}
	rollback_dsu(int size): N(size) {
		p.resize(N, -1);
	}

	//同じ木に属しているか判定
	bool same(int x, int y) {
		return leader(x) == leader(y);
	}
	//xとyが属している木をつなぐ
	void merge(int x, int y) {
		link(leader(x), leader(y));
	}
	//木と木を繋ぐ処理をする。
	void link(int x, int y) {
		history.push({ x, p[x] });
		history.push({ y, p[y] });
		if(x == y) return;
		if(p[x] > p[y]) swap(x, y);
		if(p[x] == p[y]) {
			p[x]--;
		}
		p[y] = x;
	}
	//xが属している木の根を探る
	int leader(int x) {
		if(p[x] < 0)
			return x;
		else
			return leader(p[x]);
	}

	void undo() {
		p[history.top().first] = history.top().second;
		history.pop();
		p[history.top().first] = history.top().second;
		history.pop();
	}

	void snapshot() {
		while(!history.empty()) history.pop();
	}

	void rollback() {
		while(!history.empty()) {
			auto [i, v] = history.top();
			history.pop();
			p[i] = v;
		}
	}
};