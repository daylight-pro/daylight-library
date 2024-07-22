#include "daylight/base.hpp"
#include "daylight/structure/binary_trie.hpp"

///@brief 動的Wavelet Matrix

namespace InnerWaveletMatrix {
ll op(ll a, ll b) {
	return a + b;
}
ll e() {
	return 0;
}

int opI(int a, int b) {
	return a + b;
}

int eI() {
	return 0;
}

template<class S, S (*op)(S, S), S (*e)()>
struct Treap {
private:
	mt19937_64 mt;
	uniform_int_distribution<uint64_t> rand;
	vector<S> value, acc;
	vll priority;
	vi cnt;
	vi lch, rch;
	int new_node(S v, ll p) {
		value.push_back(v);
		acc.push_back(e());
		priority.push_back(p);
		cnt.push_back(0);
		lch.push_back(-1);
		rch.push_back(-1);
		return SZ(value) - 1;
	}

	int root = -1;
	int get_cnt(int t) {
		return t == -1 ? 0 : cnt[t];
	}
	S get_acc(int t) {
		return t == -1 ? e() : acc[t];
	}
	int update(int t) {
		if(t == -1) return t;
		cnt[t] = 1 + get_cnt(lch[t]) + get_cnt(rch[t]);
		acc[t] = op(get_acc(lch[t]),
					op(value[t], get_acc(rch[t])));
		return t;
	}
	int push(int t) {
		if(t == -1) return t;
		return update(t);
	}
	int merge(int l, int r) {
		push(l);
		push(r);
		if(l == -1) return r;
		if(r == -1) return l;
		if(priority[l] > priority[r]) {
			rch[l] = merge(rch[l], r);
			return update(l);
		} else {
			lch[r] = merge(l, lch[r]);
			return update(r);
		}
	}
	PI split(int t, int k) {
		if(t == -1) return make_pair(-1, -1);
		push(t);
		int implicit_key = get_cnt(lch[t]) + 1;
		if(k < implicit_key) {
			PI s = split(lch[t], k);
			lch[t] = s.second;
			return make_pair(s.first, update(t));
		} else {
			PI s = split(rch[t], k - implicit_key);
			rch[t] = s.first;
			return make_pair(update(t), s.second);
		}
	}
	int insert(int t, int k, int n) {
		auto s = split(t, k);
		return merge(merge(s.first, n), s.second);
	}
	int _erase(int t, int k) {
		auto [tt, t3] = split(t, k + 1);
		auto [t1, t2] = split(tt, k);
		return merge(t1, t3);
	}
	int erase_range(int t, int l, int r) {
		auto [tt, t3] = split(t, r);
		auto [t1, t2] = split(tt, l);
		return merge(t1, t3);
	}
	pair<S, int> query(int t, int l, int r) {
		auto [t1, tt] = split(t, l);
		auto [t2, t3] = split(tt, r - l);
		S ret = acc[t2];
		return make_pair(ret, merge(merge(t1, t2), t3));
	}
	int set(int t, int k, S v) {
		auto [tt, t3] = split(t, k + 1);
		auto [t1, t2] = split(tt, k);
		push(t2);
		value[t2] = v;
		update(t2);
		return merge(merge(t1, t2), t3);
	}
	int _find(int t, S x, int offset, bool left = true) {
		if(op(get_acc(t), x) == x) {
			return -1;
		} else {
			if(left) {
				if(lch[t] != -1
				   && op(acc[lch[t]], x) != x) {
					return find(lch[t], x, offset, left);
				} else {
					return (op(value[t], x) != x)
						? offset + get_cnt(lch[t])
						: find(rch[t], x,
							   offset + get_cnt(lch[t]) + 1,
							   left);
				}
			} else {
				if(rch[t] != -1
				   && op(acc[rch[t]], x) != x) {
					return find(
						rch[t], x,
						offset + get_cnt(lch[t]) + 1, left);
				} else {
					return (op(value[t], x) != x)
						? offset + get_cnt(lch[t])
						: find(lch[t], x, offset, left);
				}
			}
		}
	}
	int lower_search(int t, S x) {
		int ret = 0;
		while(t != -1) {
			if(x <= value[t]) {
				t = lch[t];
			} else {
				ret += get_cnt(lch[t]) + 1;
				t = rch[t];
			}
		}
		return ret;
	}
	int upper_search(int t, S x) {
		int ret = 0;
		while(t != -1) {
			if(x < value[t]) {
				t = lch[t];
			} else {
				ret += get_cnt(lch[t]) + 1;
				t = rch[t];
			}
		}
		return ret;
	}

public:
	Treap(): Treap(0) {
	}
	Treap(int N): Treap(vector<S>(N, e())) {
	}
	Treap(vector<S> V) {
		mt = mt19937_64(chrono::steady_clock::now()
							.time_since_epoch()
							.count());
		rand = uniform_int_distribution<uint64_t>(1, 1e18);
		for(auto v: V) {
			push_back(v);
		}
	}
	/// @brief treapに追加された要素数を求める
	/// @return treapに追加された要素数
	size_t size() {
		return size_t(get_cnt(root));
	}
	/// @brief インデックスがindになるように要素xを追加する
	/// @param ind 追加先のインデックス
	/// @param x 追加する要素
	void insert(int ind, S x) {
		root = insert(root, ind, new_node(x, rand(mt)));
	}
	/// @brief 末尾に要素xを追加する
	/// @param x 追加する要素
	void push_back(S x) {
		root = insert(root, int(size()),
					  new_node(x, rand(mt)));
	}

	/// @brief インデックスindの要素を削除する
	/// @param ind 削除する要素のインデックス
	void erase(int ind) {
		root = _erase(root, ind);
	}
	/// @brief インデックスkの要素にvを代入する
	/// @param k 更新する要素k
	/// @param v 更新後の要素v
	void set(int k, S v) {
		root = set(root, k, v);
	}
	/// @brief Monoid::op(value[k],x)!=xになるような[l,r)内のkで最左/最右を求める.
	/// @param l 探索範囲の左端(inclusive)
	/// @param r 探索範囲の右端(exclusive)
	/// @param x 探索対象の要素x
	/// @param left 最左/最右を指定
	/// @return 条件を満たすk
	int find(int l, int r, S x, bool left = true) {
		auto [t1, tt] = split(root, l);
		auto [t2, t3] = split(tt, r - l);
		int ret = _find(t2, x, l, left);
		if(ret == -1) ret = r;
		root = merge(merge(t1, t2), t3);
		return ret;
	}
	/// @brief Monoid::op(value[l,r))を求める
	/// @param l 範囲の左端(inclusive)
	/// @param r 範囲の右端(exclusive)
	/// @return 範囲の演算結果を求める
	S prod(int l, int r) {
		if(l == r) return S(0);
		auto [t, rt] = query(root, l, r);
		root = rt;
		return t;
	}
	/// @brief value[ind]を求める
	/// @param ind 取得するindex
	/// @return value[ind]
	S operator[](int ind) {
		auto [tt, t3] = split(root, ind + 1);
		auto [t1, t2] = split(tt, ind);
		S ret = acc[t2];
		root = merge(merge(t1, t2), t3);
		return ret;
	}
};
};

struct DynamicBitVector {
private:
	InnerWaveletMatrix::Treap<int, InnerWaveletMatrix::opI,
							  InnerWaveletMatrix::eI>
		treap;
	int len;

public:
	DynamicBitVector() {
	}
	DynamicBitVector(const vi &v) {
		len = SZ(v);
		treap = InnerWaveletMatrix::Treap<
			int, InnerWaveletMatrix::opI,
			InnerWaveletMatrix::eI>(v);
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
	vector<InnerWaveletMatrix::Treap<
		ll, InnerWaveletMatrix::op, InnerWaveletMatrix::e>>
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
				ret |= 1ll << (bit_size - i - 1);
			}
		}
		return ret;
	}

public:
	DynamicWaveletMatrix(vector<ll> vec,
						 bool use_acc = true)
		: use_acc(use_acc) {
		len = SZ(vec);
		start_one = vi(bit_size);
		vector<ll> v(vec);
		REP(b, bit_size) {
			vector<ll> cur;
			vi bi(len);
			REP(i, len) {
				int bit = (v[i] >> (bit_size - b - 1)) & 1;
				if(bit == 0) {
					cur.push_back(v[i]);
					bi[i] = 0;
				}
			}
			start_one[b] = SZ(cur);
			REP(i, len) {
				int bit = (v[i] >> (bit_size - b - 1)) & 1;
				if(bit == 1) {
					cur.push_back(v[i]);
					bi[i] = 1;
				}
			}
			B.push_back(DynamicBitVector(bi));
			if(use_acc) {
				vll a(len);
				REP(i, len) {
					if(bi[i] == 0) {
						a[i] = v[i];
					}
				}
				auto treap = InnerWaveletMatrix::Treap<
					ll, InnerWaveletMatrix::op,
					InnerWaveletMatrix::e>(a);
				acc.push_back(treap);
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
			int bit = (v >> (bit_size - i - 1)) & 1;
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
			int bit = B[i].get(pos);
			int next_pos = B[i].rank(bit, pos);
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
			int bit = (c >> (bit_size - i - 1)) & 1;
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
			int left_rank = B[i].rank(0, left);
			int right_rank = B[i].rank(0, right);
			int zero_in_range = right_rank - left_rank;
			int bit = (k < zero_in_range) ? 0 : 1;

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
			int left_rank = B[i].rank(0, left);
			int right_rank = B[i].rank(0, right);
			int zero_in_range = right_rank - left_rank;
			int bit = (k < zero_in_range) ? 0 : 1;
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
			int left_rank = B[i].rank(0, left);
			int right_rank = B[i].rank(0, right);
			int zero_in_range = right_rank - left_rank;
			int bit = (upper >> (bit_size - i - 1)) & 1;
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