#define PROBLEM \
	"https://judge.yosupo.jp/problem/point_set_range_frequency"
#include "daylight/base.hpp"
#include "daylight/structure/binary_trie.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	BinaryTrie<ull, 64> bt;
	vector<ull> a(N);
	cin >> a;
	REP(i, N) {
		bt.add(a[i] * N + i);
	}
	while(Q--) {
		int t;
		cin >> t;
		if(t == 0) {
			int k;
			ull v;
			cin >> k >> v;
			bt.erase(a[k] * N + k);
			a[k] = v;
			bt.add(a[k] * N + k);
		} else {
			int l, r;
			ull x;
			cin >> l >> r >> x;
			cout << bt.lower_bound_rank(x * N + r)
					- bt.lower_bound_rank(x * N + l)
				 << endl;
		}
	}
}