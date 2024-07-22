#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D"
#include "daylight/base.hpp"
#include "daylight/math/matrix.hpp"

int main() {
	int n, m, l;
	cin >> n >> m >> l;
	vvll A(n, vll(m)), B(m, vll(l));
	cin >> A >> B;
	auto C = multiMatrix(A, B);
	REP(i, n) {
		cout << C[i] << endl;
	}
}