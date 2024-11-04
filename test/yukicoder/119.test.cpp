#define PROBLEM "https://yukicoder.me/problems/no/119"
#include "daylight/base.hpp"
#include "daylight/graph/project_selection.hpp"

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<PI> V(N);
	cin >> V;
	// 0:not participate, 1: not go, 2: participate
	ProjectSelection ps(vi(N, 3));
	REP(i, N) {
		ps.add_cost(i, { -V[i].second, 0, -V[i].first });
	}
	int M;
	cin >> M;
	using condition = ProjectSelection::Condition;
	auto inf = ProjectSelection::inf;
	REP(i, M) {
		int D, E;
		cin >> D >> E;
		vector<tuple<int, int, condition>> cond;
		cond.emplace_back(D, 2, ProjectSelection::GREATER_EQUAL);
		cond.emplace_back(E, 0, ProjectSelection::LESS_EQUAL);
		ps.add_cost(cond, inf, ProjectSelection::AND);
	}
	cout << -ps.solve() << endl;
	return 0;
}
