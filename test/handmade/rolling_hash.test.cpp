#define STANDALONE
#include "daylight/string/rolling_hash.hpp"
#include "daylight/base.hpp"

/// @brief Test for PR#1

int main() {
	string S = "abcd";
	string T = "abcdefg";
	string U = "xxxabcdefg";
	RollingHash hs(S), ht(T), hu(U);
	assert(ht.query(0, 7) == hu.query(3, 7));
	return 0;
}