#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=jp"
#include "daylight/base.hpp"
#include "daylight/structure/swag.hpp"

int main() {
	int N, L;
	cin >> N >> L;
	FoldableQueue<int> Q(
		[](int a, int b) {
			return min(a, b);
		},
		INF);
	vi ans;
	REP(i, N) {
		int A;
		cin >> A;
		Q.push(A);
		if(SZ(Q) > L) {
			Q.pop();
		}
		if(SZ(Q) == L) {
			ans.push_back(Q.fold());
		}
	}
	cout << ans << endl;
}