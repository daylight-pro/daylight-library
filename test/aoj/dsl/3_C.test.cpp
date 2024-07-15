#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C&lang=jp"
#include "daylight/base.hpp"
#include "daylight/double_pointer.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vll A(N);
	cin >> A;
	while(Q--) {
		ll X;
		cin >> X;
		ll sum = 0;
		ll ans = 0;
		auto check = [&]() -> bool {
			return sum <= X;
		};
		auto add = [&](int i, bool left) {
			sum += A[i];
		};
		auto del = [&](int i, bool left) {
			sum -= A[i];
		};
		auto update = [&](int l, int r) {
			ans += r - l;
		};
		doublePointerMaxRight(0, N, check, add, del,
							  update);
		cout << ans << endl;
	}
}