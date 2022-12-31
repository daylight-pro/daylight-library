#include "../base.hpp"

/// @brief エラトステネスの篩
/// @param n 整数の上限
/// @param isprime 結果を格納する配列
void eratos(int n, vb& isprime) {
	isprime = vb(n + 1, true);
	isprime[0] = false;
	isprime[1] = false;
	int last = ((int) sqrt(n)) + 1;
	FOR(i, 2, last) {
		if(isprime[i]) {
			int j = i + i;
			while(j <= n) {
				isprime[j] = false;
				j += i;
			}
		}
	}
}