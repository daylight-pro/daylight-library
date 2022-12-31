#include "../base.hpp"

/// @brief GCDとLCM

/// @brief 最大公約数を求める
/// @param x 入力1
/// @param y 入力2
/// @return GCD(x,y)
ll gcd(ll x, ll y) {
	ll r = 0;
	if(x < y) swap(x, y);
	while(y > 0) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

/// @brief 最小公倍数を求める
/// @param a 入力1
/// @param b 入力2
/// @return LCM(a,b)
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}