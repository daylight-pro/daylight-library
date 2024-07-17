#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=ja"
#include "daylight/base.hpp"
#include "daylight/math/diviser.hpp"

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int ans = 0;
	auto divs = get_divisers(C);
	for(auto div: divs) {
		if(A <= div && div <= B) ans++;
	}
	cout << ans << endl;
	return 0;
}