#include "daylight/base.hpp"
/// @brief ワーシャルフロイド法
/// @param WF 隣接行列(out:最短経路長)
vector<vll> floyd(vector<vll> WF) {
	int n = SZ(WF);
	REP(i, n) WF[i][i] = 0;
	REP(k, n)
	REP(i, n) {
		if(WF[i][k] == LINF) continue;
		REP(j, n) {
			if(WF[k][j] == LINF) continue;
			chmin(WF[i][j], WF[i][k] + WF[k][j]);
		}
	}
	return WF;
}