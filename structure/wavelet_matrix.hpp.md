---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Wavelet Matrix
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n#define SZ(x) (int) (x).size()\n#define REP(i, n) for(int i = 0; i < (n);\
    \ i++)\n#define FOR(i, a, b) for(auto i = (a); i < (b); i++)\n#define For(i, a,\
    \ b, c) \\\n\tfor(auto i = (a); i != (b); i += (c))\n#define REPR(i, n) for(auto\
    \ i = (n) -1; i >= 0; i--)\n#define ALL(s) (s).begin(), (s).end()\n#define so(V)\
    \ sort(ALL(V))\n#define rev(V) reverse(ALL(V))\n#define uni(v) v.erase(unique(ALL(v)),\
    \ (v).end())\n#define eb emplace_back\n\ntypedef long long unsigned int llu;\n\
    typedef long long ll;\ntypedef vector<int> vi;\ntypedef vector<ll> vll;\ntypedef\
    \ vector<bool> vb;\ntypedef vector<vi> vvi;\ntypedef vector<vll> vvll;\ntypedef\
    \ pair<int, int> PI;\ntypedef pair<ll, ll> PL;\nconst double EPS = 1e-9;\nconst\
    \ int MOD = 1e9 + 7;\nconst int INF = (1 << 30);\nconst ll LINF = 1e18;\nconst\
    \ double math_PI = acos(-1);\n\ntemplate<typename T>\nvector<T> make_v(size_t\
    \ a) {\n\treturn vector<T>(a);\n}\n\ntemplate<typename T, typename... Ts>\nauto\
    \ make_v(size_t a, Ts... ts) {\n\treturn vector<decltype(make_v<T>(ts...))>(\n\
    \t\ta, make_v<T>(ts...));\n}\n\ntemplate<typename T, typename V>\ntypename enable_if<is_class<T>::value\
    \ == 0>::type fill_v(\n\tT& t, const V& v) {\n\tt = v;\n}\n\ntemplate<typename\
    \ T, typename V>\ntypename enable_if<is_class<T>::value != 0>::type fill_v(\n\t\
    T& t, const V& v) {\n\tfor(auto& e: t) fill_v(e, v);\n}\n\ntemplate<class T>\n\
    bool chmax(T& a, const T& b) {\n\tif(a < b) {\n\t\ta = b;\n\t\treturn true;\n\t\
    }\n\treturn false;\n}\n\ntemplate<class T>\nbool chmin(T& a, const T& b) {\n\t\
    if(a > b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\ntemplate<typename\
    \ S, typename T>\nistream& operator>>(istream& is, pair<S, T>& p) {\n\tcin >>\
    \ p.first >> p.second;\n\treturn is;\n}\n\ntemplate<typename T>\nistream& operator>>(istream&\
    \ is, vector<T>& vec) {\n\tfor(T& x: vec) is >> x;\n\treturn is;\n}\n\ntemplate<typename\
    \ T>\nstring join(vector<T>& vec, string splitter) {\n\tstringstream ss;\n\tREP(i,\
    \ SZ(vec)) {\n\t\tif(i != 0) ss << splitter;\n\t\tss << vec[i];\n\t}\n\treturn\
    \ ss.str();\n}\n\ntemplate<typename T>\nostream& operator<<(ostream& os, vector<T>&\
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"structure/wavelet_matrix.hpp\"\
    \n/// @brief Wavelet Matrix\n\nstruct BitVector {\nprivate:\n\tvector<int> vec;\n\
    \tint len;\n\npublic:\n\tBitVector() {\n\t}\n\tBitVector(const vector<int>& v)\
    \ {\n\t\tlen = SZ(v);\n\t\tvec.resize(len + 1, 0);\n\t\tREP(i, len) {\n\t\t\t\
    vec[i + 1] += vec[i];\n\t\t\tvec[i + 1] += v[i];\n\t\t}\n\t}\n\t// i \u30D3\u30C3\
    \u30C8\u76EE\u3092\u53D6\u5F97\n\tint get(const unsigned int i) {\n\t\treturn\
    \ vec[i + 1] - vec[i];\n\t}\n\n\t// [0, i) \u30D3\u30C3\u30C8\u306E 1 \u306E\u6570\
    \n\tunsigned int rank1(const unsigned int i) const {\n\t\treturn vec[i];\n\t}\n\
    \t// [i, j) \u30D3\u30C3\u30C8\u306E 1 \u306E\u6570\n\tunsigned int rank1(const\
    \ unsigned int i,\n\t\t\t\t\t   const unsigned int j) const {\n\t\treturn rank1(j)\
    \ - rank1(i);\n\t}\n\t// [0, i) \u30D3\u30C3\u30C8\u306E 0 \u306E\u6570\n\tunsigned\
    \ int rank0(const unsigned int i) const {\n\t\treturn i - rank1(i);\n\t}\n\t//\
    \ [i, j) \u30D3\u30C3\u30C8\u306E 0 \u306E\u6570\n\tunsigned int rank0(const unsigned\
    \ int i,\n\t\t\t\t\t   const unsigned int j) const {\n\t\treturn rank0(j) - rank0(i);\n\
    \t}\n\n\t// [0, i) \u30D3\u30C3\u30C8\u306E b \u306E\u6570\n\tunsigned int rank(const\
    \ unsigned int b,\n\t\t\t\t\t  const unsigned int i) const {\n\t\tif(b == 0)\n\
    \t\t\treturn rank0(i);\n\t\telse\n\t\t\treturn rank1(i);\n\t}\n\n\t// k+1\u756A\
    \u76EE\u306Eb\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n\tunsigned int select(const\
    \ unsigned int b,\n\t\t\t\t\t\tconst unsigned int k) const {\n\t\tif(rank(b, len)\
    \ >= k) return -1;\n\t\tint ok = 0;\n\t\tint ng = len;\n\t\twhile(abs(ng - ok)\
    \ > 1) {\n\t\t\tint mid = (ng + ok) / 2;\n\t\t\tif(rank(b, mid) <= k)\n\t\t\t\t\
    ok = mid;\n\t\t\telse\n\t\t\t\tng = mid;\n\t\t}\n\t\treturn ok;\n\t}\n};\ntemplate<typename\
    \ T>\nstruct WaveletMatrix {\nprivate:\n\tvector<BitVector> B;  //\u30D3\u30C3\
    \u30C8\u30D9\u30AF\u30C8\u30EB\n\tvector<vector<T>> acc;\t//\u5404\u884C\u3067\
    \u306E\u7D2F\u7A4D\u548C\n\tvi start_one;  //\u30BD\u30FC\u30C8\u7D50\u679C\u306E\
    1\u306E\u958B\u59CB\u5730\u70B9\n\tmap<T, int> start_num;\t//\u6700\u7D42\u7D50\
    \u679C\u306E\u5404\u6570\u5B57\u306E\u958B\u59CB\u5730\u70B9\n\tint len, bit_len;\n\
    \npublic:\n\tWaveletMatrix(const vector<T>& vec,\n\t\t\t\t  bool use_acc = true)\
    \ {\n\t\tll max_el\n\t\t\t= vec.empty() ? 1 : *max_element(ALL(vec)) + 1;\n\t\t\
    bit_len = (max_el == 1)\n\t\t\t? 1\n\t\t\t: (64 - __builtin_clzll(max_el - 1));\n\
    \t\tlen = SZ(vec);\n\t\tif(use_acc)\n\t\t\tacc = vector(bit_len, vector<T>(len\
    \ + 1));\n\t\tstart_one = vi(bit_len);\n\t\tvector<T> v(vec);\n\t\tREP(b, bit_len)\
    \ {\n\t\t\tvector<T> cur;\n\t\t\tvi bi(len);\n\t\t\tREP(i, len) {\n\t\t\t\tll\
    \ bit = (v[i] >> T(bit_len - b - 1)) & 1;\n\t\t\t\tif(bit == 0) {\n\t\t\t\t\t\
    cur.push_back(v[i]);\n\t\t\t\t\tbi[i] = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t\tstart_one[b]\
    \ = SZ(cur);\n\t\t\tREP(i, len) {\n\t\t\t\tll bit = (v[i] >> T(bit_len - b - 1))\
    \ & 1;\n\t\t\t\tif(bit == 1) {\n\t\t\t\t\tcur.push_back(v[i]);\n\t\t\t\t\tbi[i]\
    \ = 1;\n\t\t\t\t}\n\t\t\t}\n\t\t\tB.push_back(BitVector(bi));\n\t\t\tif(use_acc)\
    \ {\n\t\t\t\tREP(i, len) {\n\t\t\t\t\tif(B[b].get(i) == 0)\n\t\t\t\t\t\tacc[b][i\
    \ + 1] = v[i];\n\t\t\t\t\tacc[b][i + 1] += acc[b][i];\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \tv = cur;\n\t\t}\n\n\t\tREPR(i, len) {\n\t\t\tstart_num[v[i]] = i;\n\t\t}\n\t\
    }\n\n\t/// @brief v[i]\u306B\u30A2\u30AF\u30BB\u30B9\u3059\u308B\n\t/// @param\
    \ i \u30A2\u30AF\u30BB\u30B9\u3059\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n\
    \t/// @return v[i]\u306E\u5024\n\tT access(int i) {\n\t\tassert(i < len);\n\n\t\
    \tT ret = 0;\n\t\tREP(j, bit_len) {\n\t\t\tint b = B[j].get(i);\n\t\t\tret <<=\
    \ 1;\n\t\t\tret |= b;\n\t\t\ti = B[j].rank(b, i);\n\t\t\tif(b == 1) {\n\t\t\t\t\
    i += start_one[j];\n\t\t\t}\n\t\t}\n\t\treturn ret;\n\t}\n\n\t/// @brief \u533A\
    \u9593[0,k)\u306E\u4E2D\u306B\u3001c\u304C\u3044\u304F\u3064\u542B\u307E\u308C\
    \u308B\u304B\u6C42\u3081\u308B\n\t/// @param c \u691C\u7D22\u5BFE\u8C61\u306E\u5024\
    \n\t/// @param k \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @return [0,k)\u3067\
    \u306Ec\u306E\u51FA\u73FE\u56DE\u6570\n\tint rank(T c, int k) {\n\t\tassert(k\
    \ <= len);\n\t\tassert(k >= 0);\n\t\tif(start_num.find(c) == start_num.end())\
    \ return 0;\n\t\tREP(i, bit_len) {\n\t\t\tll bit = (c >> T(bit_len - i - 1)) &\
    \ 1;\n\t\t\tk = B[i].rank(bit, k);\n\t\t\tif(bit == 1) {\n\t\t\t\tk += start_one[i];\n\
    \t\t\t}\n\t\t}\n\t\treturn k - start_num[c];\n\t}\n\n\t/// @brief \u533A\u9593\
    [left,right)\u3067k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u6C42\u3081\
    \u308B\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\
    \t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t///\
    \ @param k \u691C\u7D22\u5BFE\u8C61\u306E\u9806\u4F4D(0-indexed)\n\t/// @return\
    \ [left,right)\u3067k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\n\tT kthMin(int\
    \ left, int right, int k) {\n\t\tassert(right - left > k);\n\t\tassert(left <\
    \ right);\n\t\tll res = 0;\n\t\tREP(i, bit_len) {\n\t\t\tll left_rank = B[i].rank(0,\
    \ left);\n\t\t\tll right_rank = B[i].rank(0, right);\n\t\t\tll zero_in_range =\
    \ right_rank - left_rank;\n\t\t\tll bit = (k < zero_in_range) ? 0 : 1;\n\t\t\t\
    if(bit == 1) {\n\t\t\t\tk -= zero_in_range;\n\t\t\t\tleft += start_one[i] - left_rank;\n\
    \t\t\t\tright += start_one[i] - right_rank;\n\t\t\t} else {\n\t\t\t\tleft = left_rank;\n\
    \t\t\t\tright = right_rank;\n\t\t\t}\n\t\t\tres <<= 1;\n\t\t\tres |= bit;\n\t\t\
    }\n\t\treturn res;\n\t}\n\n\t/// @brief \u533A\u9593[left,right)\u3067k\u756A\u76EE\
    \u306B\u5927\u304D\u3044\u5024\u3092\u6C42\u3081\u308B\n\t/// @param left \u691C\
    \u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\
    \u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param k \u691C\u7D22\u5BFE\u8C61\
    \u306E\u9806\u4F4D(0-indexed)\n\t/// @return [left,right)\u3067k\u756A\u76EE\u306B\
    \u5927\u304D\u3044\u5024\n\tT kthMax(int left, int right, int k) {\n\t\tassert(right\
    \ - left > k);\n\t\tassert(left < right);\n\t\tint len = right - left;\n\t\tint\
    \ nk = len - k - 1;\n\t\treturn kthMin(left, right, nk);\n\t}\n\n\t/// @brief\
    \ [left,right)\u306E\u8981\u7D20\u3092\u6607\u9806\u306B\u4E26\u3079\u305F\u5148\
    \u982Dk\u8981\u7D20\u306E\u548C\u3092\u6C42\u3081\u308B\n\t/// @param left \u691C\
    \u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\
    \u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param k \u5148\u982D\u8981\u7D20\
    \u306E\u500B\u6570\n\t/// @return \u6607\u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\
    \n\tT kMinSum(int left, int right, int k) {\n\t\tassert(right - left >= k);\n\t\
    \tassert(left < right);\n\t\tll kth = 0;\n\t\tll ret = 0;\n\t\tREP(i, bit_len)\
    \ {\n\t\t\tll left_rank = B[i].rank(0, left);\n\t\t\tll right_rank = B[i].rank(0,\
    \ right);\n\t\t\tll zero_in_range = right_rank - left_rank;\n\t\t\tll bit = (k\
    \ < zero_in_range) ? 0 : 1;\n\t\t\tif(bit == 1) {\n\t\t\t\tret += acc[i][right]\
    \ - acc[i][left];\n\t\t\t\tk -= zero_in_range;\n\t\t\t\tleft += start_one[i] -\
    \ left_rank;\n\t\t\t\tright += start_one[i] - right_rank;\n\t\t\t} else {\n\t\t\
    \t\tleft = left_rank;\n\t\t\t\tright = right_rank;\n\t\t\t}\n\t\t\tkth <<= 1;\n\
    \t\t\tkth |= bit;\n\t\t}\n\t\tret += kth * k;\n\t\treturn ret;\n\t}\n\t/// @brief\
    \ [left,right)\u306E\u8981\u7D20\u3092\u964D\u9806\u306B\u4E26\u3079\u305F\u5148\
    \u982Dk\u8981\u7D20\u306E\u548C\u3092\u6C42\u3081\u308B\n\t/// @param left \u691C\
    \u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\
    \u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param k \u5148\u982D\u8981\u7D20\
    \u306E\u500B\u6570\n\t/// @return \u964D\u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\
    \n\tT kMaxSum(int left, int right, int k) {\n\t\tassert(right - left >= k);\n\t\
    \tassert(left < right);\n\t\treturn kMinSum(left, right, right - left)\n\t\t\t\
    - kMinSum(left, right, right - left - k);\n\t}\n\t/// @brief [l,r)\u3067upper\u672A\
    \u6E80\u306E\u5024\u306E\u6570\u3092\u6570\u3048\u308B\n\t/// @param left \u691C\
    \u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\
    \u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param upper \u691C\u7D22\u5BFE\
    \u8C61\u306E\u5024(exclusive)\n\t/// @return upper\u672A\u6E80\u306E\u6570\u306E\
    \u5024\n\tint lessCount(int left, int right, T upper) {\n\t\tassert(left <= right);\n\
    \t\tll ret = 0;\n\t\tif(left == right) {\n\t\t\treturn 0;\n\t\t}\n\t\tif(upper\
    \ >= T(T(1) << T(bit_len))) {\n\t\t\treturn right - left;\n\t\t}\n\t\tREP(i, bit_len)\
    \ {\n\t\t\tll left_rank = B[i].rank(0, left);\n\t\t\tll right_rank = B[i].rank(0,\
    \ right);\n\t\t\tll zero_in_range = right_rank - left_rank;\n\t\t\tll bit = (upper\
    \ >> T(bit_len - i - 1)) & 1;\n\t\t\tif(bit == 1) {\n\t\t\t\tret += zero_in_range;\n\
    \t\t\t\tleft += start_one[i] - left_rank;\n\t\t\t\tright += start_one[i] - right_rank;\n\
    \t\t\t} else {\n\t\t\t\tleft = left_rank;\n\t\t\t\tright = right_rank;\n\t\t\t\
    }\n\t\t}\n\t\treturn ret;\n\t}\n\t/// @brief [l,r)\u3067upper\u4EE5\u4E0B\u306E\
    \u5024\u306E\u6570\u3092\u6570\u3048\u308B\n\t/// @param left \u691C\u7D22\u5BFE\
    \u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\u8C61\
    \u306E\u53F3\u7AEF(exclusive)\n\t/// @param upper \u691C\u7D22\u5BFE\u8C61\u306E\
    \u5024(inclusive)\n\t/// @return upper\u4EE5\u4E0B\u306E\u6570\u306E\u5024\n\t\
    int lessEqualCount(int left, int right, T upper) {\n\t\tassert(left <= right);\n\
    \t\treturn lessCount(left, right, upper)\n\t\t\t+ rangeFreq(left, right, upper);\n\
    \t}\n\t/// @brief [l,r)\u3067lower\u8D85\u306E\u5024\u306E\u6570\u3092\u6570\u3048\
    \u308B\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\
    \t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t///\
    \ @param lower \u691C\u7D22\u5BFE\u8C61\u306E\u5024(exclusive)\n\t/// @return\
    \ lower\u8D85\u306E\u6570\u306E\u5024\n\tint greaterCount(int left, int right,\
    \ T lower) {\n\t\tassert(left <= right);\n\t\treturn right - left\n\t\t\t- lessEqualCount(left,\
    \ right, lower);\n\t}\n\t/// @brief [l,r)\u3067lower\u4EE5\u4E0A\u306E\u5024\u306E\
    \u6570\u3092\u6570\u3048\u308B\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\
    \u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\
    \u7AEF(exclusive)\n\t/// @param lower \u691C\u7D22\u5BFE\u8C61\u306E\u5024(inclusive)\n\
    \t/// @return lower\u4EE5\u4E0A\u306E\u6570\u306E\u5024\n\tint greaterEqualCount(int\
    \ left, int right, T lower) {\n\t\tassert(left <= right);\n\t\treturn right -\
    \ left - lessCount(left, right, lower);\n\t}\n\t/// @brief [left,right)\u306E\u7BC4\
    \u56F2\u3067,\u5024\u304Clower\u4EE5\u4E0A\u306E\u8981\u7D20\u306E\u4E2D\u3067\
    k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u8981\u7D20\u3092\u6C42\u3081\u308B.\n\t\
    /// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param\
    \ right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param lower\
    \ \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0B\u9650(inclusive)\n\t/// @param k\
    \ \u691C\u7D22\u5BFE\u8C61\u306E\u9806\u4F4D(0-indexed)\n\t/// @return k\u756A\
    \u76EE\u306E\u8981\u7D20\u306E\u5024\n\tT greaterEqualKthMin(int left, int right,\
    \ T lower,\n\t\t\t\t\t\t int k) {\n\t\tassert(left < right);\n\t\tint cnt = lessCount(left,\
    \ right, lower);\n\t\treturn kthMin(left, right, k + cnt);\n\t}\n\t/// @brief\
    \ [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304Clower\u8D85\u306E\u8981\u7D20\
    \u306E\u4E2D\u3067k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u8981\u7D20\u3092\u6C42\
    \u3081\u308B.\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\
    \t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t///\
    \ @param lower \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0B\u9650(exclusive)\n\t\
    /// @param k \u691C\u7D22\u5BFE\u8C61\u306E\u9806\u4F4D(0-indexed)\n\t/// @return\
    \ k\u756A\u76EE\u306E\u8981\u7D20\u306E\u5024\n\tT greaterKthMin(int left, int\
    \ right, T lower, int k) {\n\t\tassert(left < right);\n\t\tint cnt = lessEqualCount(left,\
    \ right, lower);\n\t\treturn kthMin(left, right, k + cnt);\n\t}\n\t/// @brief\
    \ [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304Cupper\u672A\u6E80\u306E\u8981\
    \u7D20\u306E\u4E2D\u3067k\u756A\u76EE\u306B\u5927\u304D\u3044\u8981\u7D20\u3092\
    \u6C42\u3081\u308B.\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF\
    (inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\
    \t/// @param upper \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0A\u9650(exclusive)\n\
    \t/// @param k \u691C\u7D22\u5BFE\u8C61\u306E\u9806\u4F4D(0-indexed)\n\t/// @return\
    \ k\u756A\u76EE\u306E\u8981\u7D20\u306E\u5024\n\tT lessKthMax(int left, int right,\
    \ T upper, int k) {\n\t\tassert(left < right);\n\t\tint cnt = lessCount(left,\
    \ right, upper);\n\t\treturn kthMin(left, right, cnt - k - 1);\n\t}\n\t/// @brief\
    \ [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304Cupper\u4EE5\u4E0B\u306E\u8981\
    \u7D20\u306E\u4E2D\u3067k\u756A\u76EE\u306B\u5927\u304D\u3044\u8981\u7D20\u3092\
    \u6C42\u3081\u308B.\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF\
    (inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\
    \t/// @param upper \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0A\u9650(inclusive)\n\
    \t/// @param k \u691C\u7D22\u5BFE\u8C61\u306E\u9806\u4F4D(0-indexed)\n\t/// @return\
    \ k\u756A\u76EE\u306E\u8981\u7D20\u306E\u5024\n\tT lessEqualKthMax(int left, int\
    \ right, T upper, int k) {\n\t\tassert(left < right);\n\t\tint cnt = lessEqualCount(left,\
    \ right, upper);\n\t\treturn kthMin(left, right, cnt - k - 1);\n\t}\n\t/// @brief\
    \ [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304Cupper\u672A\u6E80\u306E\u8981\
    \u7D20\u306E\u4E2D\u3067\u964D\u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\u3092\
    \u6C42\u3081\u308B.\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF\
    (inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\
    \t/// @param upper \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0A\u9650(exclusive)\n\
    \t/// @param k \u5148\u982D\u8981\u7D20\u306E\u500B\u6570\n\t/// @return \u964D\
    \u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\n\tT lessKMaxSum(int left, int right,\
    \ T upper, int k) {\n\t\tassert(left < right);\n\t\tint cnt = greaterEqualCount(left,\
    \ right, upper);\n\t\treturn kMaxSum(left, right, cnt + k)\n\t\t\t- kMaxSum(left,\
    \ right, cnt);\n\t}\n\t/// @brief [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304C\
    upper\u4EE5\u4E0B\u306E\u8981\u7D20\u306E\u4E2D\u3067\u964D\u9806\u5148\u982D\
    k\u8981\u7D20\u306E\u548C\u3092\u6C42\u3081\u308B.\n\t/// @param left \u691C\u7D22\
    \u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\
    \u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param upper \u691C\u7D22\u3059\u308B\
    \u5024\u306E\u4E0A\u9650(inclusive)\n\t/// @param k \u5148\u982D\u8981\u7D20\u306E\
    \u500B\u6570\n\t/// @return \u964D\u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\n\
    \tT lessEqualKMaxSum(int left, int right, T upper,\n\t\t\t\t\t   int k) {\n\t\t\
    assert(left < right);\n\t\tint cnt = greaterCount(left, right, upper);\n\t\treturn\
    \ kMaxSum(left, right, cnt + k)\n\t\t\t- kMaxSum(left, right, cnt);\n\t}\n\t///\
    \ @brief [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304Clower\u8D85\u306E\u8981\
    \u7D20\u306E\u4E2D\u3067\u6607\u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\u3092\
    \u6C42\u3081\u308B.\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF\
    (inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\
    \t/// @param lower \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0B\u9650(exclusive)\n\
    \t/// @param k \u5148\u982D\u8981\u7D20\u306E\u500B\u6570\n\t/// @return \u6607\
    \u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\n\tT greaterKMinSum(int left, int\
    \ right, T lower, int k) {\n\t\tassert(left < right);\n\t\tint cnt = lessEqualCount(left,\
    \ right, lower);\n\t\treturn kMinSum(left, right, cnt + k)\n\t\t\t- kMinSum(left,\
    \ right, cnt);\n\t}\n\t/// @brief [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304C\
    lower\u4EE5\u4E0A\u306E\u8981\u7D20\u306E\u4E2D\u3067\u6607\u9806\u5148\u982D\
    k\u8981\u7D20\u306E\u548C\u3092\u6C42\u3081\u308B.\n\t/// @param left \u691C\u7D22\
    \u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\
    \u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param lower \u691C\u7D22\u3059\u308B\
    \u5024\u306E\u4E0B\u9650(inclusive)\n\t/// @param k \u5148\u982D\u8981\u7D20\u306E\
    \u500B\u6570\n\t/// @return \u6607\u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\n\
    \tT greaterEqualKMinSum(int left, int right, T lower,\n\t\t\t\t\t\t  int k) {\n\
    \t\tassert(left < right);\n\t\tint cnt = lessCount(left, right, lower);\n\t\t\
    return kMinSum(left, right, cnt + k)\n\t\t\t- kMinSum(left, right, cnt);\n\t}\n\
    \t/// @brief [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304C[lower,upper)\u306E\
    \u7BC4\u56F2\u306B\u3042\u308B\u8981\u7D20\u306E\u6570\u3092\u6570\u3048\u308B\
    \n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t\
    /// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t///\
    \ @param lower \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0B\u9650(inclusive)\n\t\
    /// @param upper \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0A\u9650(exclusive)\n\
    \t/// @return \u8A72\u5F53\u3059\u308B\u8981\u7D20\u306E\u500B\u6570\n\tint valueRangeCount(int\
    \ left, int right, T lower,\n\t\t\t\t\t\tT upper) {\n\t\tassert(left <= right);\n\
    \t\treturn lessCount(left, right, upper)\n\t\t\t- lessCount(left, right, lower);\n\
    \t}\n\t/// @brief [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304C[lower,upper)\u306E\
    \u7BC4\u56F2\u306B\u3042\u308B\u8981\u7D20\u306E\u548C\u3092\u6C42\u3081\u308B\
    .\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t\
    /// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t///\
    \ @param lower \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0B\u9650(inclusive)\n\t\
    /// @param upper \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0A\u9650(exclusive)\n\
    \t/// @return \u691C\u7D22\u5BFE\u8C61\u306E\u548C\n\tT valueRangeSum(int left,\
    \ int right, T lower, T upper) {\n\t\tassert(left <= right);\n\t\tint less = lessCount(left,\
    \ right, lower);\n\t\tint greater = greaterEqualCount(left, right, upper);\n\t\
    \treturn kMaxSum(left, right, right - left)\n\t\t\t- kMaxSum(left, right, greater)\n\
    \t\t\t- kMinSum(left, right, less);\n\t}\n\t/// @brief \u533A\u9593[l,r)\u3067\
    v\u304C\u4F55\u56DE\u51FA\u73FE\u3059\u308B\u304B\u6C42\u3081\u308B\n\t/// @param\
    \ l \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param r \u691C\
    \u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param v \u691C\u7D22\u5BFE\
    \u8C61\u306E\u5024\n\t/// @return [l,r)\u3067\u306Ev\u306E\u51FA\u73FE\u56DE\u6570\
    \n\tint rangeFreq(int l, int r, T v) {\n\t\tassert(0 <= l && l <= r && r <= len);\n\
    \t\treturn rank(v, r) - rank(v, l);\n\t}\n};\n"
  code: "#include \"../base.hpp\"\n/// @brief Wavelet Matrix\n\nstruct BitVector {\n\
    private:\n\tvector<int> vec;\n\tint len;\n\npublic:\n\tBitVector() {\n\t}\n\t\
    BitVector(const vector<int>& v) {\n\t\tlen = SZ(v);\n\t\tvec.resize(len + 1, 0);\n\
    \t\tREP(i, len) {\n\t\t\tvec[i + 1] += vec[i];\n\t\t\tvec[i + 1] += v[i];\n\t\t\
    }\n\t}\n\t// i \u30D3\u30C3\u30C8\u76EE\u3092\u53D6\u5F97\n\tint get(const unsigned\
    \ int i) {\n\t\treturn vec[i + 1] - vec[i];\n\t}\n\n\t// [0, i) \u30D3\u30C3\u30C8\
    \u306E 1 \u306E\u6570\n\tunsigned int rank1(const unsigned int i) const {\n\t\t\
    return vec[i];\n\t}\n\t// [i, j) \u30D3\u30C3\u30C8\u306E 1 \u306E\u6570\n\tunsigned\
    \ int rank1(const unsigned int i,\n\t\t\t\t\t   const unsigned int j) const {\n\
    \t\treturn rank1(j) - rank1(i);\n\t}\n\t// [0, i) \u30D3\u30C3\u30C8\u306E 0 \u306E\
    \u6570\n\tunsigned int rank0(const unsigned int i) const {\n\t\treturn i - rank1(i);\n\
    \t}\n\t// [i, j) \u30D3\u30C3\u30C8\u306E 0 \u306E\u6570\n\tunsigned int rank0(const\
    \ unsigned int i,\n\t\t\t\t\t   const unsigned int j) const {\n\t\treturn rank0(j)\
    \ - rank0(i);\n\t}\n\n\t// [0, i) \u30D3\u30C3\u30C8\u306E b \u306E\u6570\n\t\
    unsigned int rank(const unsigned int b,\n\t\t\t\t\t  const unsigned int i) const\
    \ {\n\t\tif(b == 0)\n\t\t\treturn rank0(i);\n\t\telse\n\t\t\treturn rank1(i);\n\
    \t}\n\n\t// k+1\u756A\u76EE\u306Eb\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n\
    \tunsigned int select(const unsigned int b,\n\t\t\t\t\t\tconst unsigned int k)\
    \ const {\n\t\tif(rank(b, len) >= k) return -1;\n\t\tint ok = 0;\n\t\tint ng =\
    \ len;\n\t\twhile(abs(ng - ok) > 1) {\n\t\t\tint mid = (ng + ok) / 2;\n\t\t\t\
    if(rank(b, mid) <= k)\n\t\t\t\tok = mid;\n\t\t\telse\n\t\t\t\tng = mid;\n\t\t\
    }\n\t\treturn ok;\n\t}\n};\ntemplate<typename T>\nstruct WaveletMatrix {\nprivate:\n\
    \tvector<BitVector> B;  //\u30D3\u30C3\u30C8\u30D9\u30AF\u30C8\u30EB\n\tvector<vector<T>>\
    \ acc;\t//\u5404\u884C\u3067\u306E\u7D2F\u7A4D\u548C\n\tvi start_one;  //\u30BD\
    \u30FC\u30C8\u7D50\u679C\u306E1\u306E\u958B\u59CB\u5730\u70B9\n\tmap<T, int> start_num;\t\
    //\u6700\u7D42\u7D50\u679C\u306E\u5404\u6570\u5B57\u306E\u958B\u59CB\u5730\u70B9\
    \n\tint len, bit_len;\n\npublic:\n\tWaveletMatrix(const vector<T>& vec,\n\t\t\t\
    \t  bool use_acc = true) {\n\t\tll max_el\n\t\t\t= vec.empty() ? 1 : *max_element(ALL(vec))\
    \ + 1;\n\t\tbit_len = (max_el == 1)\n\t\t\t? 1\n\t\t\t: (64 - __builtin_clzll(max_el\
    \ - 1));\n\t\tlen = SZ(vec);\n\t\tif(use_acc)\n\t\t\tacc = vector(bit_len, vector<T>(len\
    \ + 1));\n\t\tstart_one = vi(bit_len);\n\t\tvector<T> v(vec);\n\t\tREP(b, bit_len)\
    \ {\n\t\t\tvector<T> cur;\n\t\t\tvi bi(len);\n\t\t\tREP(i, len) {\n\t\t\t\tll\
    \ bit = (v[i] >> T(bit_len - b - 1)) & 1;\n\t\t\t\tif(bit == 0) {\n\t\t\t\t\t\
    cur.push_back(v[i]);\n\t\t\t\t\tbi[i] = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t\tstart_one[b]\
    \ = SZ(cur);\n\t\t\tREP(i, len) {\n\t\t\t\tll bit = (v[i] >> T(bit_len - b - 1))\
    \ & 1;\n\t\t\t\tif(bit == 1) {\n\t\t\t\t\tcur.push_back(v[i]);\n\t\t\t\t\tbi[i]\
    \ = 1;\n\t\t\t\t}\n\t\t\t}\n\t\t\tB.push_back(BitVector(bi));\n\t\t\tif(use_acc)\
    \ {\n\t\t\t\tREP(i, len) {\n\t\t\t\t\tif(B[b].get(i) == 0)\n\t\t\t\t\t\tacc[b][i\
    \ + 1] = v[i];\n\t\t\t\t\tacc[b][i + 1] += acc[b][i];\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \tv = cur;\n\t\t}\n\n\t\tREPR(i, len) {\n\t\t\tstart_num[v[i]] = i;\n\t\t}\n\t\
    }\n\n\t/// @brief v[i]\u306B\u30A2\u30AF\u30BB\u30B9\u3059\u308B\n\t/// @param\
    \ i \u30A2\u30AF\u30BB\u30B9\u3059\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n\
    \t/// @return v[i]\u306E\u5024\n\tT access(int i) {\n\t\tassert(i < len);\n\n\t\
    \tT ret = 0;\n\t\tREP(j, bit_len) {\n\t\t\tint b = B[j].get(i);\n\t\t\tret <<=\
    \ 1;\n\t\t\tret |= b;\n\t\t\ti = B[j].rank(b, i);\n\t\t\tif(b == 1) {\n\t\t\t\t\
    i += start_one[j];\n\t\t\t}\n\t\t}\n\t\treturn ret;\n\t}\n\n\t/// @brief \u533A\
    \u9593[0,k)\u306E\u4E2D\u306B\u3001c\u304C\u3044\u304F\u3064\u542B\u307E\u308C\
    \u308B\u304B\u6C42\u3081\u308B\n\t/// @param c \u691C\u7D22\u5BFE\u8C61\u306E\u5024\
    \n\t/// @param k \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @return [0,k)\u3067\
    \u306Ec\u306E\u51FA\u73FE\u56DE\u6570\n\tint rank(T c, int k) {\n\t\tassert(k\
    \ <= len);\n\t\tassert(k >= 0);\n\t\tif(start_num.find(c) == start_num.end())\
    \ return 0;\n\t\tREP(i, bit_len) {\n\t\t\tll bit = (c >> T(bit_len - i - 1)) &\
    \ 1;\n\t\t\tk = B[i].rank(bit, k);\n\t\t\tif(bit == 1) {\n\t\t\t\tk += start_one[i];\n\
    \t\t\t}\n\t\t}\n\t\treturn k - start_num[c];\n\t}\n\n\t/// @brief \u533A\u9593\
    [left,right)\u3067k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u6C42\u3081\
    \u308B\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\
    \t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t///\
    \ @param k \u691C\u7D22\u5BFE\u8C61\u306E\u9806\u4F4D(0-indexed)\n\t/// @return\
    \ [left,right)\u3067k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\n\tT kthMin(int\
    \ left, int right, int k) {\n\t\tassert(right - left > k);\n\t\tassert(left <\
    \ right);\n\t\tll res = 0;\n\t\tREP(i, bit_len) {\n\t\t\tll left_rank = B[i].rank(0,\
    \ left);\n\t\t\tll right_rank = B[i].rank(0, right);\n\t\t\tll zero_in_range =\
    \ right_rank - left_rank;\n\t\t\tll bit = (k < zero_in_range) ? 0 : 1;\n\t\t\t\
    if(bit == 1) {\n\t\t\t\tk -= zero_in_range;\n\t\t\t\tleft += start_one[i] - left_rank;\n\
    \t\t\t\tright += start_one[i] - right_rank;\n\t\t\t} else {\n\t\t\t\tleft = left_rank;\n\
    \t\t\t\tright = right_rank;\n\t\t\t}\n\t\t\tres <<= 1;\n\t\t\tres |= bit;\n\t\t\
    }\n\t\treturn res;\n\t}\n\n\t/// @brief \u533A\u9593[left,right)\u3067k\u756A\u76EE\
    \u306B\u5927\u304D\u3044\u5024\u3092\u6C42\u3081\u308B\n\t/// @param left \u691C\
    \u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\
    \u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param k \u691C\u7D22\u5BFE\u8C61\
    \u306E\u9806\u4F4D(0-indexed)\n\t/// @return [left,right)\u3067k\u756A\u76EE\u306B\
    \u5927\u304D\u3044\u5024\n\tT kthMax(int left, int right, int k) {\n\t\tassert(right\
    \ - left > k);\n\t\tassert(left < right);\n\t\tint len = right - left;\n\t\tint\
    \ nk = len - k - 1;\n\t\treturn kthMin(left, right, nk);\n\t}\n\n\t/// @brief\
    \ [left,right)\u306E\u8981\u7D20\u3092\u6607\u9806\u306B\u4E26\u3079\u305F\u5148\
    \u982Dk\u8981\u7D20\u306E\u548C\u3092\u6C42\u3081\u308B\n\t/// @param left \u691C\
    \u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\
    \u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param k \u5148\u982D\u8981\u7D20\
    \u306E\u500B\u6570\n\t/// @return \u6607\u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\
    \n\tT kMinSum(int left, int right, int k) {\n\t\tassert(right - left >= k);\n\t\
    \tassert(left < right);\n\t\tll kth = 0;\n\t\tll ret = 0;\n\t\tREP(i, bit_len)\
    \ {\n\t\t\tll left_rank = B[i].rank(0, left);\n\t\t\tll right_rank = B[i].rank(0,\
    \ right);\n\t\t\tll zero_in_range = right_rank - left_rank;\n\t\t\tll bit = (k\
    \ < zero_in_range) ? 0 : 1;\n\t\t\tif(bit == 1) {\n\t\t\t\tret += acc[i][right]\
    \ - acc[i][left];\n\t\t\t\tk -= zero_in_range;\n\t\t\t\tleft += start_one[i] -\
    \ left_rank;\n\t\t\t\tright += start_one[i] - right_rank;\n\t\t\t} else {\n\t\t\
    \t\tleft = left_rank;\n\t\t\t\tright = right_rank;\n\t\t\t}\n\t\t\tkth <<= 1;\n\
    \t\t\tkth |= bit;\n\t\t}\n\t\tret += kth * k;\n\t\treturn ret;\n\t}\n\t/// @brief\
    \ [left,right)\u306E\u8981\u7D20\u3092\u964D\u9806\u306B\u4E26\u3079\u305F\u5148\
    \u982Dk\u8981\u7D20\u306E\u548C\u3092\u6C42\u3081\u308B\n\t/// @param left \u691C\
    \u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\
    \u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param k \u5148\u982D\u8981\u7D20\
    \u306E\u500B\u6570\n\t/// @return \u964D\u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\
    \n\tT kMaxSum(int left, int right, int k) {\n\t\tassert(right - left >= k);\n\t\
    \tassert(left < right);\n\t\treturn kMinSum(left, right, right - left)\n\t\t\t\
    - kMinSum(left, right, right - left - k);\n\t}\n\t/// @brief [l,r)\u3067upper\u672A\
    \u6E80\u306E\u5024\u306E\u6570\u3092\u6570\u3048\u308B\n\t/// @param left \u691C\
    \u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\
    \u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param upper \u691C\u7D22\u5BFE\
    \u8C61\u306E\u5024(exclusive)\n\t/// @return upper\u672A\u6E80\u306E\u6570\u306E\
    \u5024\n\tint lessCount(int left, int right, T upper) {\n\t\tassert(left <= right);\n\
    \t\tll ret = 0;\n\t\tif(left == right) {\n\t\t\treturn 0;\n\t\t}\n\t\tif(upper\
    \ >= T(T(1) << T(bit_len))) {\n\t\t\treturn right - left;\n\t\t}\n\t\tREP(i, bit_len)\
    \ {\n\t\t\tll left_rank = B[i].rank(0, left);\n\t\t\tll right_rank = B[i].rank(0,\
    \ right);\n\t\t\tll zero_in_range = right_rank - left_rank;\n\t\t\tll bit = (upper\
    \ >> T(bit_len - i - 1)) & 1;\n\t\t\tif(bit == 1) {\n\t\t\t\tret += zero_in_range;\n\
    \t\t\t\tleft += start_one[i] - left_rank;\n\t\t\t\tright += start_one[i] - right_rank;\n\
    \t\t\t} else {\n\t\t\t\tleft = left_rank;\n\t\t\t\tright = right_rank;\n\t\t\t\
    }\n\t\t}\n\t\treturn ret;\n\t}\n\t/// @brief [l,r)\u3067upper\u4EE5\u4E0B\u306E\
    \u5024\u306E\u6570\u3092\u6570\u3048\u308B\n\t/// @param left \u691C\u7D22\u5BFE\
    \u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\u8C61\
    \u306E\u53F3\u7AEF(exclusive)\n\t/// @param upper \u691C\u7D22\u5BFE\u8C61\u306E\
    \u5024(inclusive)\n\t/// @return upper\u4EE5\u4E0B\u306E\u6570\u306E\u5024\n\t\
    int lessEqualCount(int left, int right, T upper) {\n\t\tassert(left <= right);\n\
    \t\treturn lessCount(left, right, upper)\n\t\t\t+ rangeFreq(left, right, upper);\n\
    \t}\n\t/// @brief [l,r)\u3067lower\u8D85\u306E\u5024\u306E\u6570\u3092\u6570\u3048\
    \u308B\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\
    \t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t///\
    \ @param lower \u691C\u7D22\u5BFE\u8C61\u306E\u5024(exclusive)\n\t/// @return\
    \ lower\u8D85\u306E\u6570\u306E\u5024\n\tint greaterCount(int left, int right,\
    \ T lower) {\n\t\tassert(left <= right);\n\t\treturn right - left\n\t\t\t- lessEqualCount(left,\
    \ right, lower);\n\t}\n\t/// @brief [l,r)\u3067lower\u4EE5\u4E0A\u306E\u5024\u306E\
    \u6570\u3092\u6570\u3048\u308B\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\
    \u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\
    \u7AEF(exclusive)\n\t/// @param lower \u691C\u7D22\u5BFE\u8C61\u306E\u5024(inclusive)\n\
    \t/// @return lower\u4EE5\u4E0A\u306E\u6570\u306E\u5024\n\tint greaterEqualCount(int\
    \ left, int right, T lower) {\n\t\tassert(left <= right);\n\t\treturn right -\
    \ left - lessCount(left, right, lower);\n\t}\n\t/// @brief [left,right)\u306E\u7BC4\
    \u56F2\u3067,\u5024\u304Clower\u4EE5\u4E0A\u306E\u8981\u7D20\u306E\u4E2D\u3067\
    k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u8981\u7D20\u3092\u6C42\u3081\u308B.\n\t\
    /// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param\
    \ right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param lower\
    \ \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0B\u9650(inclusive)\n\t/// @param k\
    \ \u691C\u7D22\u5BFE\u8C61\u306E\u9806\u4F4D(0-indexed)\n\t/// @return k\u756A\
    \u76EE\u306E\u8981\u7D20\u306E\u5024\n\tT greaterEqualKthMin(int left, int right,\
    \ T lower,\n\t\t\t\t\t\t int k) {\n\t\tassert(left < right);\n\t\tint cnt = lessCount(left,\
    \ right, lower);\n\t\treturn kthMin(left, right, k + cnt);\n\t}\n\t/// @brief\
    \ [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304Clower\u8D85\u306E\u8981\u7D20\
    \u306E\u4E2D\u3067k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u8981\u7D20\u3092\u6C42\
    \u3081\u308B.\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\
    \t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t///\
    \ @param lower \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0B\u9650(exclusive)\n\t\
    /// @param k \u691C\u7D22\u5BFE\u8C61\u306E\u9806\u4F4D(0-indexed)\n\t/// @return\
    \ k\u756A\u76EE\u306E\u8981\u7D20\u306E\u5024\n\tT greaterKthMin(int left, int\
    \ right, T lower, int k) {\n\t\tassert(left < right);\n\t\tint cnt = lessEqualCount(left,\
    \ right, lower);\n\t\treturn kthMin(left, right, k + cnt);\n\t}\n\t/// @brief\
    \ [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304Cupper\u672A\u6E80\u306E\u8981\
    \u7D20\u306E\u4E2D\u3067k\u756A\u76EE\u306B\u5927\u304D\u3044\u8981\u7D20\u3092\
    \u6C42\u3081\u308B.\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF\
    (inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\
    \t/// @param upper \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0A\u9650(exclusive)\n\
    \t/// @param k \u691C\u7D22\u5BFE\u8C61\u306E\u9806\u4F4D(0-indexed)\n\t/// @return\
    \ k\u756A\u76EE\u306E\u8981\u7D20\u306E\u5024\n\tT lessKthMax(int left, int right,\
    \ T upper, int k) {\n\t\tassert(left < right);\n\t\tint cnt = lessCount(left,\
    \ right, upper);\n\t\treturn kthMin(left, right, cnt - k - 1);\n\t}\n\t/// @brief\
    \ [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304Cupper\u4EE5\u4E0B\u306E\u8981\
    \u7D20\u306E\u4E2D\u3067k\u756A\u76EE\u306B\u5927\u304D\u3044\u8981\u7D20\u3092\
    \u6C42\u3081\u308B.\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF\
    (inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\
    \t/// @param upper \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0A\u9650(inclusive)\n\
    \t/// @param k \u691C\u7D22\u5BFE\u8C61\u306E\u9806\u4F4D(0-indexed)\n\t/// @return\
    \ k\u756A\u76EE\u306E\u8981\u7D20\u306E\u5024\n\tT lessEqualKthMax(int left, int\
    \ right, T upper, int k) {\n\t\tassert(left < right);\n\t\tint cnt = lessEqualCount(left,\
    \ right, upper);\n\t\treturn kthMin(left, right, cnt - k - 1);\n\t}\n\t/// @brief\
    \ [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304Cupper\u672A\u6E80\u306E\u8981\
    \u7D20\u306E\u4E2D\u3067\u964D\u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\u3092\
    \u6C42\u3081\u308B.\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF\
    (inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\
    \t/// @param upper \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0A\u9650(exclusive)\n\
    \t/// @param k \u5148\u982D\u8981\u7D20\u306E\u500B\u6570\n\t/// @return \u964D\
    \u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\n\tT lessKMaxSum(int left, int right,\
    \ T upper, int k) {\n\t\tassert(left < right);\n\t\tint cnt = greaterEqualCount(left,\
    \ right, upper);\n\t\treturn kMaxSum(left, right, cnt + k)\n\t\t\t- kMaxSum(left,\
    \ right, cnt);\n\t}\n\t/// @brief [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304C\
    upper\u4EE5\u4E0B\u306E\u8981\u7D20\u306E\u4E2D\u3067\u964D\u9806\u5148\u982D\
    k\u8981\u7D20\u306E\u548C\u3092\u6C42\u3081\u308B.\n\t/// @param left \u691C\u7D22\
    \u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\
    \u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param upper \u691C\u7D22\u3059\u308B\
    \u5024\u306E\u4E0A\u9650(inclusive)\n\t/// @param k \u5148\u982D\u8981\u7D20\u306E\
    \u500B\u6570\n\t/// @return \u964D\u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\n\
    \tT lessEqualKMaxSum(int left, int right, T upper,\n\t\t\t\t\t   int k) {\n\t\t\
    assert(left < right);\n\t\tint cnt = greaterCount(left, right, upper);\n\t\treturn\
    \ kMaxSum(left, right, cnt + k)\n\t\t\t- kMaxSum(left, right, cnt);\n\t}\n\t///\
    \ @brief [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304Clower\u8D85\u306E\u8981\
    \u7D20\u306E\u4E2D\u3067\u6607\u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\u3092\
    \u6C42\u3081\u308B.\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF\
    (inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\
    \t/// @param lower \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0B\u9650(exclusive)\n\
    \t/// @param k \u5148\u982D\u8981\u7D20\u306E\u500B\u6570\n\t/// @return \u6607\
    \u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\n\tT greaterKMinSum(int left, int\
    \ right, T lower, int k) {\n\t\tassert(left < right);\n\t\tint cnt = lessEqualCount(left,\
    \ right, lower);\n\t\treturn kMinSum(left, right, cnt + k)\n\t\t\t- kMinSum(left,\
    \ right, cnt);\n\t}\n\t/// @brief [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304C\
    lower\u4EE5\u4E0A\u306E\u8981\u7D20\u306E\u4E2D\u3067\u6607\u9806\u5148\u982D\
    k\u8981\u7D20\u306E\u548C\u3092\u6C42\u3081\u308B.\n\t/// @param left \u691C\u7D22\
    \u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param right \u691C\u7D22\u5BFE\
    \u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param lower \u691C\u7D22\u3059\u308B\
    \u5024\u306E\u4E0B\u9650(inclusive)\n\t/// @param k \u5148\u982D\u8981\u7D20\u306E\
    \u500B\u6570\n\t/// @return \u6607\u9806\u5148\u982Dk\u8981\u7D20\u306E\u548C\n\
    \tT greaterEqualKMinSum(int left, int right, T lower,\n\t\t\t\t\t\t  int k) {\n\
    \t\tassert(left < right);\n\t\tint cnt = lessCount(left, right, lower);\n\t\t\
    return kMinSum(left, right, cnt + k)\n\t\t\t- kMinSum(left, right, cnt);\n\t}\n\
    \t/// @brief [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304C[lower,upper)\u306E\
    \u7BC4\u56F2\u306B\u3042\u308B\u8981\u7D20\u306E\u6570\u3092\u6570\u3048\u308B\
    \n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t\
    /// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t///\
    \ @param lower \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0B\u9650(inclusive)\n\t\
    /// @param upper \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0A\u9650(exclusive)\n\
    \t/// @return \u8A72\u5F53\u3059\u308B\u8981\u7D20\u306E\u500B\u6570\n\tint valueRangeCount(int\
    \ left, int right, T lower,\n\t\t\t\t\t\tT upper) {\n\t\tassert(left <= right);\n\
    \t\treturn lessCount(left, right, upper)\n\t\t\t- lessCount(left, right, lower);\n\
    \t}\n\t/// @brief [left,right)\u306E\u7BC4\u56F2\u3067,\u5024\u304C[lower,upper)\u306E\
    \u7BC4\u56F2\u306B\u3042\u308B\u8981\u7D20\u306E\u548C\u3092\u6C42\u3081\u308B\
    .\n\t/// @param left \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t\
    /// @param right \u691C\u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t///\
    \ @param lower \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0B\u9650(inclusive)\n\t\
    /// @param upper \u691C\u7D22\u3059\u308B\u5024\u306E\u4E0A\u9650(exclusive)\n\
    \t/// @return \u691C\u7D22\u5BFE\u8C61\u306E\u548C\n\tT valueRangeSum(int left,\
    \ int right, T lower, T upper) {\n\t\tassert(left <= right);\n\t\tint less = lessCount(left,\
    \ right, lower);\n\t\tint greater = greaterEqualCount(left, right, upper);\n\t\
    \treturn kMaxSum(left, right, right - left)\n\t\t\t- kMaxSum(left, right, greater)\n\
    \t\t\t- kMinSum(left, right, less);\n\t}\n\t/// @brief \u533A\u9593[l,r)\u3067\
    v\u304C\u4F55\u56DE\u51FA\u73FE\u3059\u308B\u304B\u6C42\u3081\u308B\n\t/// @param\
    \ l \u691C\u7D22\u5BFE\u8C61\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param r \u691C\
    \u7D22\u5BFE\u8C61\u306E\u53F3\u7AEF(exclusive)\n\t/// @param v \u691C\u7D22\u5BFE\
    \u8C61\u306E\u5024\n\t/// @return [l,r)\u3067\u306Ev\u306E\u51FA\u73FE\u56DE\u6570\
    \n\tint rangeFreq(int l, int r, T v) {\n\t\tassert(0 <= l && l <= r && r <= len);\n\
    \t\treturn rank(v, r) - rank(v, l);\n\t}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/structure/wavelet_matrix.hpp
- /library/structure/wavelet_matrix.hpp.html
title: Wavelet Matrix
---
