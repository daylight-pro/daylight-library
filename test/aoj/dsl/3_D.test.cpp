#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=jp"
#include "daylight/base.hpp"
#include "daylight/structure/swag.hpp"

int main() {
	int N, L;
	cin >> N >> L;
	SWAG<int> swag([](int a, int b) {
		return min(a, b);
	});
	vi ans;
	REP(i, N) {
		int A;
		cin >> A;
		swag.push(A);
		if(SZ(swag) > L) {
			swag.pop();
		}
		if(SZ(swag) == L) {
			ans.push_back(swag.fold());
		}
	}
	cout << ans << endl;
}