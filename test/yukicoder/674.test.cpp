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
		auto r = Range<>().left(A).right(B + 1, false);
		chmax(ans,
			  rs.add(r).value_or(0).countIntegerPoint());
		cout << ans << endl;
	}
	return 0;
}