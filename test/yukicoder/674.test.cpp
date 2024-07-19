#define PROBLEM "https://yukicoder.me/problems/no/674"
#include "daylight/base.hpp"
#include "daylight/range.hpp"
#include "daylight/structure/range_set.hpp"

int main() {
	ll D, Q;
	cin >> D >> Q;
	ll ans = 0;
	RangeSet<ll> rs;
	while(Q--) {
		ll A, B;
		cin >> A >> B;
		auto r = Range<>().left(A).right(B);
		chmax(ans, rs.add(r).countIntegerPoint());
		cout << ans << endl;
	}
	return 0;
}