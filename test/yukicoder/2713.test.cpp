#define PROBLEM "https://yukicoder.me/problems/no/2713"
#include "daylight/base.hpp"
#include "daylight/graph/project_selection.hpp"

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vll A(N), B(M);
	cin >> A >> B;
	// 0:used, 1: not used
	// 0:archived, 1: not archived
	ProjectSelection ps(vi(N + M, 2));
	REP(i, N) {
		ps.add_cost(i, vll { A[i], 0 });
	}
	using Condition = ProjectSelection::Condition;
	REP(i, M) {
		ps.add_cost(-B[i]);
		vector<tuple<int, int, Condition>> cond;
		int K;
		cin >> K;
		REP(j, K) {
			int C;
			cin >> C;
			C--;
			cond.emplace_back(
				C, 1,
				ProjectSelection::Condition::GREATER_EQUAL);
		}
		ps.add_cost(cond, B[i],
					ProjectSelection::Logic::OR);
	}
	cout << -ps.solve() << endl;
	return 0;
}
