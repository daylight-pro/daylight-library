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
    document_title: "\u521D\u671F\u5316\u3002\u57FA\u5E95\u306E\u9078\u5B9A\u3092\u884C\
      \u3046"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"string/rolling_hash.hpp\"\
    \nstruct RollingHash {\nprivate:\n\tstatic const uint64_t mod = (1ull << 61ull)\
    \ - 1;\n\tusing uint128_t = __uint128_t;\n\tuint64_t base1, base2;\n\tvector<uint64_t>\
    \ pow1, pow2;\n\n\t// \u5FC5\u8981\u5206\u306Epow\u914D\u5217\u3092\u8FFD\u52A0\
    \u3067\u6C42\u3081\u308B\u3002\n\tinline void expand(int sz) {\n\t\tint pre_sz\
    \ = SZ(pow1);\n\t\tif(pre_sz < sz + 1) {\n\t\t\tfor(int i = pre_sz - 1; i < sz;\
    \ i++) {\n\t\t\t\tpow1.push_back(mul(pow1[i], base1));\n\t\t\t\tpow2.push_back(mul(pow2[i],\
    \ base2));\n\t\t\t}\n\t\t}\n\t}\n\tstatic inline uint64_t add(uint64_t a, uint64_t\
    \ b) {\n\t\tif((a += b) >= mod) a -= mod;\n\t\treturn a;\n\t}\n\n\tstatic inline\
    \ uint64_t mul(uint64_t a, uint64_t b) {\n\t\tuint128_t c = (uint128_t) a * b;\n\
    \t\treturn add(c >> 61, c & mod);\n\t}\n\npublic:\n\t/// @brief \u521D\u671F\u5316\
    \u3002\u57FA\u5E95\u306E\u9078\u5B9A\u3092\u884C\u3046\n\tRollingHash() {\n\t\t\
    mt19937_64 mt(chrono::steady_clock::now()\n\t\t\t\t\t\t  .time_since_epoch()\n\
    \t\t\t\t\t\t  .count());\n\t\tuniform_int_distribution<uint64_t> rand(\n\t\t\t\
    1e9, RollingHash::mod - 1);\n\t\tbase1 = rand(mt);\n\t\tbase2 = rand(mt);\n\t\t\
    pow1.push_back(1);\n\t\tpow2.push_back(1);\n\t}\n\n\t/// @brief \u4E0E\u3048\u3089\
    \u308C\u305F\u6587\u5B57\u5217\u306B\u3064\u3044\u3066,hash\u5024\u3092\u8A08\u7B97\
    \u3059\u308B\n\t/// @param s hash\u5024\u3092\u6C42\u3081\u308B\u6587\u5B57\u5217\
    \n\t/// @return \u8A08\u7B97\u3055\u308C\u305F2\u901A\u308A\u306Ehash\u5024\n\t\
    pair<vector<uint64_t>, vector<uint64_t>> build(\n\t\tconst string& s) {\n\t\t\
    expand(SZ(s) + 1);\n\t\tvector<uint64_t> hash1\n\t\t\t= vector<uint64_t>(SZ(s)\
    \ + 1);\n\t\tvector<uint64_t> hash2\n\t\t\t= vector<uint64_t>(SZ(s) + 1);\n\t\t\
    REP(i, SZ(s)) {\n\t\t\thash1[i + 1] = add(mul(hash1[i], base1), s[i]);\n\t\t\t\
    hash2[i + 1] = add(mul(hash2[i], base2), s[i]);\n\t\t}\n\t\treturn { hash1, hash2\
    \ };\n\t}\n\n\t/// @brief \u4E0E\u3048\u3089\u308C\u305Fvector\u306B\u3064\u3044\
    \u3066hash\u5024\u3092\u6C42\u3081\u308B\n\t/// @tparam T vector\u306E\u8981\u7D20\
    \u306E\u578B\n\t/// @param s hash\u5024\u3092\u6C42\u3081\u308Bvector\n\t/// @return\
    \ \u8A08\u7B97\u3055\u308C\u305F2\u901A\u308A\u306Ehash\u5024\n\ttemplate<typename\
    \ T>\n\tpair<vector<uint64_t>, vector<uint64_t>> build(\n\t\tconst vector<T>&\
    \ s) {\n\t\texpand(SZ(s) + 1);\n\t\tvector<uint64_t> hash1\n\t\t\t= vector<uint64_t>(SZ(s)\
    \ + 1);\n\t\tvector<uint64_t> hash2\n\t\t\t= vector<uint64_t>(SZ(s) + 1);\n\t\t\
    REP(i, SZ(s)) {\n\t\t\thash1[i + 1] = add(mul(hash1[i], base1), s[i]);\n\t\t\t\
    hash2[i + 1] = add(mul(hash2[i], base2), s[i]);\n\t\t}\n\t\treturn { hash1, hash2\
    \ };\n\t}\n\n\t/// @brief build\u95A2\u6570\u3067\u8A08\u7B97\u3055\u308C\u305F\
    hash\u5024\u3092\u3082\u3068\u306Bbegin\u6587\u5B57\u76EE\u304B\u3089length\u6587\
    \u5B57\u306Ehash\u5024\u3092\u6C42\u3081\u308B\n\t/// @param hash build\u95A2\u6570\
    \u306E\u7D50\u679C\n\t/// @param begin \u6587\u5B57\u5217\u306E\u521D\u671F\u4F4D\
    \u7F6E(0-indexed)\n\t/// @param length \u6587\u5B57\u5217\u306E\u9577\u3055\n\t\
    /// @return 2\u901A\u308A\u306Ehash\u5024\n\tpair<uint64_t, uint64_t> query(\n\
    \t\tconst pair<vector<uint64_t>, vector<uint64_t>>&\n\t\t\thash,\n\t\tint begin,\
    \ int length) {\n\t\tassert(begin + length <= SZ(hash.first));\n\t\tassert(begin\
    \ >= 0);\n\t\tassert(length > 0);\n\t\texpand(length);\n\t\treturn {\n\t\t\tadd(hash.first[begin\
    \ + length],\n\t\t\t\tmod - mul(hash.first[begin], pow1[length])),\n\t\t\tadd(hash.second[begin\
    \ + length],\n\t\t\t\tmod - mul(hash.second[begin], pow2[length]))\n\t\t};\n\t\
    }\n};\n"
  code: "#include \"../base.hpp\"\nstruct RollingHash {\nprivate:\n\tstatic const\
    \ uint64_t mod = (1ull << 61ull) - 1;\n\tusing uint128_t = __uint128_t;\n\tuint64_t\
    \ base1, base2;\n\tvector<uint64_t> pow1, pow2;\n\n\t// \u5FC5\u8981\u5206\u306E\
    pow\u914D\u5217\u3092\u8FFD\u52A0\u3067\u6C42\u3081\u308B\u3002\n\tinline void\
    \ expand(int sz) {\n\t\tint pre_sz = SZ(pow1);\n\t\tif(pre_sz < sz + 1) {\n\t\t\
    \tfor(int i = pre_sz - 1; i < sz; i++) {\n\t\t\t\tpow1.push_back(mul(pow1[i],\
    \ base1));\n\t\t\t\tpow2.push_back(mul(pow2[i], base2));\n\t\t\t}\n\t\t}\n\t}\n\
    \tstatic inline uint64_t add(uint64_t a, uint64_t b) {\n\t\tif((a += b) >= mod)\
    \ a -= mod;\n\t\treturn a;\n\t}\n\n\tstatic inline uint64_t mul(uint64_t a, uint64_t\
    \ b) {\n\t\tuint128_t c = (uint128_t) a * b;\n\t\treturn add(c >> 61, c & mod);\n\
    \t}\n\npublic:\n\t/// @brief \u521D\u671F\u5316\u3002\u57FA\u5E95\u306E\u9078\u5B9A\
    \u3092\u884C\u3046\n\tRollingHash() {\n\t\tmt19937_64 mt(chrono::steady_clock::now()\n\
    \t\t\t\t\t\t  .time_since_epoch()\n\t\t\t\t\t\t  .count());\n\t\tuniform_int_distribution<uint64_t>\
    \ rand(\n\t\t\t1e9, RollingHash::mod - 1);\n\t\tbase1 = rand(mt);\n\t\tbase2 =\
    \ rand(mt);\n\t\tpow1.push_back(1);\n\t\tpow2.push_back(1);\n\t}\n\n\t/// @brief\
    \ \u4E0E\u3048\u3089\u308C\u305F\u6587\u5B57\u5217\u306B\u3064\u3044\u3066,hash\u5024\
    \u3092\u8A08\u7B97\u3059\u308B\n\t/// @param s hash\u5024\u3092\u6C42\u3081\u308B\
    \u6587\u5B57\u5217\n\t/// @return \u8A08\u7B97\u3055\u308C\u305F2\u901A\u308A\u306E\
    hash\u5024\n\tpair<vector<uint64_t>, vector<uint64_t>> build(\n\t\tconst string&\
    \ s) {\n\t\texpand(SZ(s) + 1);\n\t\tvector<uint64_t> hash1\n\t\t\t= vector<uint64_t>(SZ(s)\
    \ + 1);\n\t\tvector<uint64_t> hash2\n\t\t\t= vector<uint64_t>(SZ(s) + 1);\n\t\t\
    REP(i, SZ(s)) {\n\t\t\thash1[i + 1] = add(mul(hash1[i], base1), s[i]);\n\t\t\t\
    hash2[i + 1] = add(mul(hash2[i], base2), s[i]);\n\t\t}\n\t\treturn { hash1, hash2\
    \ };\n\t}\n\n\t/// @brief \u4E0E\u3048\u3089\u308C\u305Fvector\u306B\u3064\u3044\
    \u3066hash\u5024\u3092\u6C42\u3081\u308B\n\t/// @tparam T vector\u306E\u8981\u7D20\
    \u306E\u578B\n\t/// @param s hash\u5024\u3092\u6C42\u3081\u308Bvector\n\t/// @return\
    \ \u8A08\u7B97\u3055\u308C\u305F2\u901A\u308A\u306Ehash\u5024\n\ttemplate<typename\
    \ T>\n\tpair<vector<uint64_t>, vector<uint64_t>> build(\n\t\tconst vector<T>&\
    \ s) {\n\t\texpand(SZ(s) + 1);\n\t\tvector<uint64_t> hash1\n\t\t\t= vector<uint64_t>(SZ(s)\
    \ + 1);\n\t\tvector<uint64_t> hash2\n\t\t\t= vector<uint64_t>(SZ(s) + 1);\n\t\t\
    REP(i, SZ(s)) {\n\t\t\thash1[i + 1] = add(mul(hash1[i], base1), s[i]);\n\t\t\t\
    hash2[i + 1] = add(mul(hash2[i], base2), s[i]);\n\t\t}\n\t\treturn { hash1, hash2\
    \ };\n\t}\n\n\t/// @brief build\u95A2\u6570\u3067\u8A08\u7B97\u3055\u308C\u305F\
    hash\u5024\u3092\u3082\u3068\u306Bbegin\u6587\u5B57\u76EE\u304B\u3089length\u6587\
    \u5B57\u306Ehash\u5024\u3092\u6C42\u3081\u308B\n\t/// @param hash build\u95A2\u6570\
    \u306E\u7D50\u679C\n\t/// @param begin \u6587\u5B57\u5217\u306E\u521D\u671F\u4F4D\
    \u7F6E(0-indexed)\n\t/// @param length \u6587\u5B57\u5217\u306E\u9577\u3055\n\t\
    /// @return 2\u901A\u308A\u306Ehash\u5024\n\tpair<uint64_t, uint64_t> query(\n\
    \t\tconst pair<vector<uint64_t>, vector<uint64_t>>&\n\t\t\thash,\n\t\tint begin,\
    \ int length) {\n\t\tassert(begin + length <= SZ(hash.first));\n\t\tassert(begin\
    \ >= 0);\n\t\tassert(length > 0);\n\t\texpand(length);\n\t\treturn {\n\t\t\tadd(hash.first[begin\
    \ + length],\n\t\t\t\tmod - mul(hash.first[begin], pow1[length])),\n\t\t\tadd(hash.second[begin\
    \ + length],\n\t\t\t\tmod - mul(hash.second[begin], pow2[length]))\n\t\t};\n\t\
    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: "\u521D\u671F\u5316\u3002\u57FA\u5E95\u306E\u9078\u5B9A\u3092\u884C\u3046"
---
