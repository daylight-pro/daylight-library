#include "daylight/base.hpp"
struct RollingHash {
private:
	static const uint64_t mod = (1ull << 61ull) - 1;
	using uint128_t = __uint128_t;
	static inline uint64_t base = 0;
	static inline vector<uint64_t> pow;
	vector<uint64_t> hash;

	// 必要分のpow配列を追加で求める。
	inline void expand(int sz) {
		int pre_sz = SZ(pow);
		if(pre_sz < sz + 1) {
			for(int i = pre_sz - 1; i < sz; i++) {
				pow.push_back(mul(pow[i], base));
			}
		}
	}
	static inline uint64_t add(uint64_t a, uint64_t b) {
		if((a += b) >= mod) a -= mod;
		return a;
	}

	static inline uint64_t mul(uint64_t a, uint64_t b) {
		uint128_t c = (uint128_t) a * b;
		return add(c >> 61, c & mod);
	}

public:
	/// @brief 指定した文字列に対して,ハッシュを前計算する
	/// @param s ハッシュを取る文字列
	RollingHash(const string& s)
		: RollingHash(vector<char>(s.begin(), s.end())) {
	}

	/// @brief 指定した配列に対して,ハッシュを前計算する
	/// @param s ハッシュを取る配列
	template<typename T>
	RollingHash(const vector<T>& s) {
		if(base == 0) {
			mt19937_64 mt(chrono::steady_clock::now()
							  .time_since_epoch()
							  .count());
			uniform_int_distribution<uint64_t> rand(
				1e9, RollingHash::mod - 1);
			base = rand(mt);
		}
		pow.push_back(1);
		expand(SZ(s) + 1);
		hash = vector<uint64_t>(SZ(s) + 1);
		REP(i, SZ(s)) {
			hash[i + 1] = add(mul(hash[i], base), s[i]);
		}
	}

	/// @brief build関数で計算されたhash値をもとにbegin文字目からlength文字のhash値を求める
	/// @param begin 文字列の初期位置(0-indexed)
	/// @param length 文字列の長さ
	/// @return 2通りのhash値
	uint64_t query(int begin, int length) {
		assert(begin + length <= SZ(hash));
		assert(begin >= 0);
		assert(length > 0);
		expand(length);
		auto ret = add(hash[begin + length],
					   mod - mul(hash[begin], pow[length]));
		return ret;
	}
};