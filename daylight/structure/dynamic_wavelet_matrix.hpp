#include "daylight/base.hpp"
#include "daylight/structure/binary_trie.hpp"
#include "daylight/structure/treap.hpp"

///@brief 動的Wavelet Matrix

namespace InnerWaveletMatrix {
ll op(ll a, ll b) {
	return a + b;
}
ll e() {
	return 0;
}

ll mapping(ll f, ll s, int sz) {
	return s;
}
ll composition(ll f, ll g) {
	return 0;
}
ll id() {
	return 0;
}
};

struct DynamicBitVector {
private:
	Treap<ll, InnerWaveletMatrix::op, InnerWaveletMatrix::e,
		  ll, InnerWaveletMatrix::mapping,
		  InnerWaveletMatrix::composition,
		  InnerWaveletMatrix::id>
		treap;
	int len;

public:
	DynamicBitVector() {
	}
	DynamicBitVector(const vll &v) {
		len = SZ(v);
		treap = Treap<ll, InnerWaveletMatrix::op,
					  InnerWaveletMatrix::e, ll,
					  InnerWaveletMatrix::mapping,
					  InnerWaveletMatrix::composition,
					  InnerWaveletMatrix::id>(v);
	}
	// i ビット目を取得
	int get(const unsigned int i) {
		return treap[i];
	}

	// [0, i) ビットの 1 の数
	unsigned int rank1(const unsigned int i) {
		return treap.prod(0, i);
	}
	// [i, j) ビットの 1 の数
	unsigned int rank1(const unsigned int i,
					   const unsigned int j) {
		return rank1(j) - rank1(i);
	}
	// [0, i) ビットの 0 の数
	unsigned int rank0(const unsigned int i) {
		return i - rank1(i);
	}
	// [i, j) ビットの 0 の数
	unsigned int rank0(const unsigned int i,
					   const unsigned int j) {
		return rank0(j) - rank0(i);
	}

	// [0, i) ビットの b の数
	unsigned int rank(const unsigned int b,
					  const unsigned int i) {
		if(b == 0)
			return rank0(i);
		else
			return rank1(i);
	}

	// k+1番目のbのインデックス
	unsigned int select(const unsigned int b,
						const unsigned int k) {
		if(rank(b, len) >= k) return -1;
		int ok = 0;
		int ng = len;
		while(abs(ng - ok) > 1) {
			int mid = (ng + ok) / 2;
			if(rank(b, mid) <= k)
				ok = mid;
			else
				ng = mid;
		}
		return ok;
	}

	void insert(const unsigned int pos,
				const unsigned int b) {
		treap.insert(pos, b);
	}

	void erase(const unsigned int pos) {
		treap.erase(pos);
	}
};

struct DynamicWaveletMatrix {
private:
	vector<DynamicBitVector> B;
	vector<Treap<ll, InnerWaveletMatrix::op,
				 InnerWaveletMatrix::e, ll,
				 InnerWaveletMatrix::mapping,
				 InnerWaveletMatrix::composition,
				 InnerWaveletMatrix::id>>
		acc;
	vi start_one;
	const int bit_size = 63;
	BinaryTrie<ll, 63> nums;
	int len;
	bool use_acc;
	ll getId(ll x) {
		ll ret = 0;
		REP(i, bit_size) {
			if(x >> i & 1) {
				ret |= x << (bit_size - i - 1);
			}
		}
		return ret;
	}

public:
	DynamicWaveletMatrix(vector<ll> vec,
						 bool use_acc = true)
		: use_acc(use_acc) {
		len = SZ(vec);
		if(use_acc) {
			REP(i, bit_size) {
				auto treap
					= Treap<ll, InnerWaveletMatrix::op,
							InnerWaveletMatrix::e, ll,
							InnerWaveletMatrix::mapping,
							InnerWaveletMatrix::composition,
							InnerWaveletMatrix::id>(len);
				acc.push_back(treap);
			}
		}
		start_one = vi(bit_size);
		vector<ll> v(vec);
		REP(b, bit_size) {
			vector<ll> cur;
			vll bi(len);
			REP(i, len) {
				ll bit = (v[i] >> (bit_size - b - 1)) & 1;
				if(bit == 0) {
					cur.push_back(v[i]);
					bi[i] = 0;
				}
			}
			start_one[b] = SZ(cur);
			REP(i, len) {
				ll bit = (v[i] >> (bit_size - b - 1)) & 1;
				if(bit == 1) {
					cur.push_back(v[i]);
					bi[i] = 1;
				}
			}
			B.push_back(DynamicBitVector(bi));
			if(use_acc) {
				REP(i, len) {
					if(B[b].get(i) == 0) {
						acc[b].set(i, v[i]);
					} else {
						acc[b].set(i, 0);
					}
				}
			}
			v = cur;
		}
		REP(i, len) {
			nums.add(getId(v[i]));
		}
	}

	ll access(int i) {
		assert(i < len);
		ll ret = 0;
		REP(j, bit_size) {
			int b = B[j].get(i);
			ret <<= 1;
			ret |= b;
			i = B[j].rank(b, i);
			if(b == 1) {
				i += start_one[j];
			}
		}
		return ret;
	}

	void insert(int pos, ll v) {
		REP(i, bit_size) {
			ll bit = (v >> (bit_size - i - 1)) & 1;
			B[i].insert(pos, bit);
			if(use_acc) {
				if(bit == 0)
					acc[i].insert(pos, v);
				else
					acc[i].insert(pos, 0);
			}
			pos = B[i].rank(bit, pos);
			if(bit) {
				pos += start_one[i];
			} else {
				start_one[i]++;
			}
		}
		nums.add(getId(v));
	}

	void erase(int pos) {
		ll v = access(pos);
		REP(i, bit_size) {
			ll bit = B[i].get(pos);
			ll next_pos = B[i].rank(bit, pos);
			B[i].erase(pos);
			if(use_acc) {
				acc[i].erase(pos);
			}
			if(bit) {
				next_pos += start_one[i];
			} else {
				start_one[i]--;
			}
			pos = next_pos;
		}
		nums.erase(getId(v));
	}

	void update(int pos, ll v) {
		erase(pos);
		insert(pos, v);
	}

	int rank(ll c, int k) {
		assert(k <= len);
		assert(k >= 0);
		if(nums.count(getId(c)) == 0) return 0;
		REP(i, bit_size) {
			ll bit = (c >> (bit_size - i - 1)) & 1;
			k = B[i].rank(bit, k);
			if(bit == 1) {
				k += start_one[i];
			}
		}
		return k - nums.lower_bound_rank(getId(c));
	}

	ll kthMin(int left, int right, int k) {
		assert(right - left > k);
		assert(left < right);
		assert(0 <= left);
		assert(right <= len);
		ll res = 0;
		REP(i, bit_size) {
			ll left_rank = B[i].rank(0, left);
			ll right_rank = B[i].rank(0, right);
			ll zero_in_range = right_rank - left_rank;
			ll bit = (k < zero_in_range) ? 0 : 1;

			if(bit == 1) {
				k -= zero_in_range;
				left += start_one[i] - left_rank;
				right += start_one[i] - right_rank;
			} else {
				left = left_rank;
				right = right_rank;
			}
			res <<= 1;
			res |= bit;
		}
		return res;
	}

	ll kthMax(int left, int right, int k) {
		assert(right - left > k);
		assert(left < right);
		int len = right - left;
		int nk = len - k - 1;
		return kthMin(left, right, nk);
	}

	ll kMinSum(int left, int right, int k) {
		assert(right - left >= k);
		if(k == 0) return 0;
		assert(left < right);
		ll kth = 0;
		ll ret = 0;
		REP(i, bit_size) {
			ll left_rank = B[i].rank(0, left);
			ll right_rank = B[i].rank(0, right);
			ll zero_in_range = right_rank - left_rank;
			ll bit = (k < zero_in_range) ? 0 : 1;
			if(bit == 1) {
				ret += acc[i].prod(left, right);
				k -= zero_in_range;
				left += start_one[i] - left_rank;
				right += start_one[i] - right_rank;
			} else {
				left = left_rank;
				right = right_rank;
			}
			kth <<= 1;
			kth |= bit;
		}
		ret += kth * k;
		return ret;
	}

	ll kMaxSum(int left, int right, int k) {
		assert(right - left >= k);
		if(k == 0) return 0;
		assert(left < right);
		return kMinSum(left, right, right - left)
			- kMinSum(left, right, right - left - k);
	}

	int lessCount(int left, int right, ll upper) {
		assert(left <= right);
		ll ret = 0;
		if(left == right) {
			return 0;
		}
		if(upper >= (1ll << bit_size)) {
			return right - left;
		}
		REP(i, bit_size) {
			ll left_rank = B[i].rank(0, left);
			ll right_rank = B[i].rank(0, right);
			ll zero_in_range = right_rank - left_rank;
			ll bit = (upper >> (bit_size - i - 1)) & 1;
			if(bit == 1) {
				ret += zero_in_range;
				left += start_one[i] - left_rank;
				right += start_one[i] - right_rank;
			} else {
				left = left_rank;
				right = right_rank;
			}
		}
		return ret;
	}

	int lessEqualCount(int left, int right, ll upper) {
		assert(left <= right);
		return lessCount(left, right, upper)
			+ rangeFreq(left, right, upper);
	}

	int greaterCount(int left, int right, ll lower) {
		assert(left <= right);
		return right - left
			- lessEqualCount(left, right, lower);
	}

	int greaterEqualCount(int left, int right, ll lower) {
		assert(left <= right);
		return right - left - lessCount(left, right, lower);
	}

	ll greaterEqualKthMin(int left, int right, ll lower,
						  int k) {
		assert(left < right);
		int cnt = lessCount(left, right, lower);
		return kthMin(left, right, k + cnt);
	}

	ll greaterKthMin(int left, int right, ll lower, int k) {
		assert(left < right);
		int cnt = lessEqualCount(left, right, lower);
		return kthMin(left, right, k + cnt);
	}

	ll lessKthMax(int left, int right, ll upper, int k) {
		assert(left < right);
		int cnt = lessCount(left, right, upper);
		return kthMin(left, right, cnt - k - 1);
	}

	ll lessEqualKthMax(int left, int right, ll upper,
					   int k) {
		assert(left < right);
		int cnt = lessEqualCount(left, right, upper);
		return kthMin(left, right, cnt - k - 1);
	}

	ll lessKMaxSum(int left, int right, ll upper, int k) {
		assert(left < right);
		int cnt = greaterEqualCount(left, right, upper);
		return kMaxSum(left, right, cnt + k)
			- kMaxSum(left, right, cnt);
	}

	ll lessEqualKMaxSum(int left, int right, ll upper,
						int k) {
		assert(left < right);
		int cnt = greaterCount(left, right, upper);
		return kMaxSum(left, right, cnt + k)
			- kMaxSum(left, right, cnt);
	}

	ll greaterKMinSum(int left, int right, ll lower,
					  int k) {
		assert(left < right);
		int cnt = lessEqualCount(left, right, lower);
		return kMinSum(left, right, cnt + k)
			- kMinSum(left, right, cnt);
	}

	ll greaterEqualKMinSum(int left, int right, ll lower,
						   int k) {
		assert(left < right);
		int cnt = lessCount(left, right, lower);
		return kMinSum(left, right, cnt + k)
			- kMinSum(left, right, cnt);
	}

	int valueRangeCount(int left, int right, ll lower,
						ll upper) {
		assert(left <= right);
		return lessCount(left, right, upper)
			- lessCount(left, right, lower);
	}

	ll valueRangeSum(int left, int right, ll lower,
					 ll upper) {
		assert(left <= right);
		int less = lessCount(left, right, lower);
		int greater = greaterEqualCount(left, right, upper);
		return kMaxSum(left, right, right - left)
			- kMaxSum(left, right, greater)
			- kMinSum(left, right, less);
	}

	int rangeFreq(int l, int r, ll v) {
		assert(0 <= l && l <= r && r <= len);
		return rank(v, r) - rank(v, l);
	}

	ll operator[](int ind) {
		return access(ind);
	}
};