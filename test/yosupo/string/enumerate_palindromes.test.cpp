#define PROBLEM \
	"https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "daylight/base.hpp"
#include "daylight/string/manacher.hpp"

int main() {
	string S;
	cin >> S;
	auto ans = ext_manacher(S);
	REP(i, SZ(ans)) {
		if(i % 2 == 0) {
			ans[i] = ans[i] * 2 - 1;
		} else {
			ans[i] = ans[i] * 2;
		}
	}
	cout << ans << endl;
	return 0;
}