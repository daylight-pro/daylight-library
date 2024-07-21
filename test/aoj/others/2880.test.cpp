#define PROBLEM \
	"https://onlinejudge.u-aizu.ac.jp/problems/2880"

#include "daylight/base.hpp"
#include "daylight/range.hpp"
#include "daylight/structure/range_set.hpp"

int main() {
	int N, M, Q;
	cin >> N >> M >> Q;
	RangeSet<ll> rs;
	using T = tuple<int, int, int>;
	priority_queue<T> PQ;
	REP(i, M) {
		int D, A, B;
		cin >> D >> A >> B;
		PQ.push({ D, A, B });
	}
	using TT = tuple<int, int, int, int>;
	vector<TT> q;
	REP(i, Q) {
		int E, S, T;
		cin >> E >> S >> T;
		q.eb(E, S, T, i);
	}
	so(q);
	vb ans(Q);
	for(auto [e, s, t, i]: q) {
		while(!PQ.empty() && get<0>(PQ.top()) < e) {
			auto [d, a, b] = PQ.top();
			PQ.pop();
			rs.add(Range<>().left(a).right(b, true));
		}
		if(rs.same(s, t)) {
			ans[i] = true;
		}
		if(s >= t) {
			ans[i] = true;
		}
	}
	REP(i, Q) {
		cout << (ans[i] ? "Yes" : "No") << endl;
	}

	return 0;
}