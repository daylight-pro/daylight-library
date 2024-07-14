#define PROBLEM \
	"https://judge.yosupo.jp/problem/set_xor_min"
#include "daylight/base.hpp"
#include "daylight/structure/binary_trie.hpp"

int main() {
	int Q;
	cin >> Q;
	BinaryTrie<ll> trie;
	while(Q--) {
		int t;
		cin >> t;
		if(t == 0) {
			int x;
			cin >> x;
			if(trie.count(x) > 0) continue;
			trie.add(x);
		} else if(t == 1) {
			int x;
			cin >> x;
			if(trie.count(x) == 0) continue;
			trie.erase(x);
		} else {
			int x;
			cin >> x;
			cout << (trie.min_element(x) ^ x) << endl;
		}
	}
}