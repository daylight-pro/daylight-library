#pragma once
#include "daylight/base.hpp"
/// @brief 繰り返し2乗法でa^p mod mを求める
ll pow_mod(ll a, ll p, ll m) {
	using i128 = __int128_t;
	i128 ret = 1;
	i128 mul = a;
	for(; p > 0; p >>= 1) {
		if(p & 1) ret = (ret * mul) % m;
		mul = (mul * mul) % m;
	}
	return ll(ret);
}