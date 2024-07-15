#define PROBLEM \
	"https://judge.yosupo.jp/problem/deque_operate_all_composite"
#include <atcoder/all>
#include "daylight/base.hpp"
#include "daylight/structure/swag.hpp"
using namespace atcoder;

using mint = modint998244353;

int main() {
	int Q;
	cin >> Q;
	using P = pair<mint, mint>;
	FoldableDeque<P> D(
		[](P a, P b) -> P {
			return { a.first * b.first,
					 a.second * b.first + b.second };
		},
		{ 1, 0 });
	while(Q--) {
		int t;
		cin >> t;
		if(t == 0) {
			int a, b;
			cin >> a >> b;
			D.push_front({ a, b });
		} else if(t == 1) {
			int a, b;
			cin >> a >> b;
			D.push_back({ a, b });
		} else if(t == 2) {
			D.pop_front();
		} else if(t == 3) {
			D.pop_back();
		} else {
			int x;
			cin >> x;
			cout << (D.fold().first * x + D.fold().second)
						.val()
				 << endl;
		}
	}
}