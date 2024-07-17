#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja"
#include "daylight/base.hpp"
#include "daylight/math/extgcd.hpp"

int main() {
	ll a, b, x, y;
	cin >> a >> b;
	extgcd(a, b, x, y);
	cout << x << " " << y << endl;
	return 0;
}