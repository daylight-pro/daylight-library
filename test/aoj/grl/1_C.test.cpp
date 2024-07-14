#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp"
#include "daylight/base.hpp"
#include "daylight/graph/builder.hpp"
#include "daylight/graph/floyd.hpp"

int main() {
	int V, E;
	cin >> V >> E;
	auto G = GraphBuilder<>(V, E)
				 .weighted()
				 .directed()
				 .setIndex(0)
				 .buildMatrix(cin);
	auto d = floyd(G);
	REP(i, V) {
		if(d[i][i] < 0) {
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	REP(i, V) {
		REP(j, V) {
			if(j != 0) cout << " ";
			if(d[i][j] == LINF)
				cout << "INF";
			else
				cout << d[i][j];
		}
		cout << endl;
	}
}