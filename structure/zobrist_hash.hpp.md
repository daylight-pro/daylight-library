---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':warning:'
    path: atcoder/dsu.hpp
    title: atcoder/dsu.hpp
  - icon: ':warning:'
    path: atcoder/fenwicktree.hpp
    title: atcoder/fenwicktree.hpp
  - icon: ':warning:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':warning:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':warning:'
    path: atcoder/internal_queue.hpp
    title: atcoder/internal_queue.hpp
  - icon: ':warning:'
    path: atcoder/internal_scc.hpp
    title: atcoder/internal_scc.hpp
  - icon: ':warning:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':warning:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':warning:'
    path: atcoder/math.hpp
    title: atcoder/math.hpp
  - icon: ':warning:'
    path: atcoder/maxflow.hpp
    title: atcoder/maxflow.hpp
  - icon: ':warning:'
    path: atcoder/mincostflow.hpp
    title: atcoder/mincostflow.hpp
  - icon: ':warning:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':warning:'
    path: atcoder/scc.hpp
    title: atcoder/scc.hpp
  - icon: ':warning:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':warning:'
    path: atcoder/string.hpp
    title: atcoder/string.hpp
  - icon: ':warning:'
    path: atcoder/twosat.hpp
    title: atcoder/twosat.hpp
  - icon: ':warning:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Zobrist Hash
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 1 \"atcoder/all\"\n\
    #include <atcoder/convolution>\n#include <atcoder/dsu>\n#include <atcoder/fenwicktree>\n\
    #include <atcoder/lazysegtree>\n#include <atcoder/math>\n#include <atcoder/maxflow>\n\
    #include <atcoder/mincostflow>\n#include <atcoder/modint>\n#include <atcoder/scc>\n\
    #include <atcoder/segtree>\n#include <atcoder/string>\n#include <atcoder/twosat>\n\
    #line 3 \"structure/zobrist_hash.hpp\"\nusing namespace atcoder;\n/// @brief Zobrist\
    \ Hash\n\n/// @brief \u96C6\u5408\u3092\u30CF\u30C3\u30B7\u30E5\u3059\u308B\u69CB\
    \u9020\u4F53\n/// @tparam T \u914D\u5217\u306E\u8981\u7D20\u306E\u578B\ntemplate<typename\
    \ T>\nstruct ZobristHash {\nprivate:\n\tmap<T, uint64_t> M1;\n\tmap<T, uint64_t>\
    \ M2;\n\n\tvoid createRand(const vector<T>& t) {\n\t\tmt19937_64 mt(chrono::steady_clock::now()\n\
    \t\t\t\t\t\t  .time_since_epoch()\n\t\t\t\t\t\t  .count());\n\t\tuniform_int_distribution<uint64_t>\
    \ rand(1,\n\t\t\t\t\t\t\t\t\t\t\t\t1ll << 62);\n\t\tfor(auto s: t) {\n\t\t\tif(M1[s]\
    \ != 0) continue;\n\t\t\tM1[s] = rand(mt);\n\t\t\tM2[s] = rand(mt);\n\t\t}\n\t\
    }\n\npublic:\n\tZobristHash() {\n\t}\n\t/// @brief queries\u306E\u5404\u30AF\u30A8\
    \u30EA\u306B\u3064\u3044\u3066,t\u306E\u96C6\u5408\u306E\u30CF\u30C3\u30B7\u30E5\
    \u3092\u6C42\u3081\u308B\n\t/// @param t \u30CF\u30C3\u30B7\u30E5\u3092\u6C42\u3081\
    \u308B\u5BFE\u8C61\u306E\u914D\u5217\n\t/// @param queries \u30CF\u30C3\u30B7\u30E5\
    \u3092\u6C42\u3081\u308B\u7BC4\u56F2[l,r)\u306E\u30DA\u30A2\u914D\u5217\n\t///\
    \ @return 0<=u<SZ(queries)\u306B\u3064\u3044\u3066,ret[i]\u306F[first,second)\u306E\
    \u96C6\u5408\u3068\u3057\u3066\u306E\u30CF\u30C3\u30B7\u30E5\u304C\u5165\u308B\
    \n\tvector<pair<uint64_t, uint64_t>> get(\n\t\tvector<T> const& t,\n\t\tvector<pair<int,\
    \ int>> const& queries) {\n\t\tcreateRand(t);\n\t\tvector<pair<pair<int, int>,\
    \ int>> V;\n\t\tREP(i, SZ(queries)) {\n\t\t\tauto [l, r] = queries[i];\n\t\t\t\
    assert(0 <= l && l < r && r <= SZ(t));\n\t\t\tV.push_back({ { l, r }, i });\n\t\
    \t}\n\t\tso(V);\n\t\tint N = SZ(t);\n\t\tauto op = [](uint64_t a, uint64_t b)\
    \ -> uint64_t {\n\t\t\treturn a ^ b;\n\t\t};\n\t\tauto e = []() -> uint64_t {\n\
    \t\t\treturn 0;\n\t\t};\n\t\tvector<uint64_t> init1(N, e());\n\t\tvector<uint64_t>\
    \ init2(N, e());\n\t\tvi next(N, -1);\n\t\tmap<T, int> pre;\n\t\tREP(i, N) {\n\
    \t\t\tif(pre[t[i]] != 0) {\n\t\t\t\tnext[pre[t[i]] - 1] = i;\n\t\t\t} else {\n\
    \t\t\t\tinit1[i] = M1[t[i]];\n\t\t\t\tinit2[i] = M2[t[i]];\n\t\t\t}\n\t\t\tpre[t[i]]\
    \ = i + 1;\n\t\t}\n\t\tsegtree<uint64_t, op, e> seg1(init1);\n\t\tsegtree<uint64_t,\
    \ op, e> seg2(init2);\n\t\tint curL = 0;\n\t\tvector<pair<uint64_t, uint64_t>>\
    \ ret(SZ(queries));\n\t\tREP(i, SZ(V)) {\n\t\t\tauto [q, ind] = V[i];\n\t\t\t\
    auto [l, r] = q;\n\t\t\twhile(curL < l) {\n\t\t\t\tseg1.set(curL, e());\n\t\t\t\
    \tseg2.set(curL, e());\n\t\t\t\tif(next[curL] != -1) {\n\t\t\t\t\tseg1.set(next[curL],\
    \ M1[t[next[curL]]]);\n\t\t\t\t\tseg2.set(next[curL], M2[t[next[curL]]]);\n\t\t\
    \t\t}\n\t\t\t\tcurL++;\n\t\t\t}\n\t\t\tret[ind] = { seg1.prod(l, r), seg2.prod(l,\
    \ r) };\n\t\t}\n\t\treturn ret;\n\t}\n};\n"
  code: "#include \"../base.hpp\"\n#include \"atcoder/all\"\nusing namespace atcoder;\n\
    /// @brief Zobrist Hash\n\n/// @brief \u96C6\u5408\u3092\u30CF\u30C3\u30B7\u30E5\
    \u3059\u308B\u69CB\u9020\u4F53\n/// @tparam T \u914D\u5217\u306E\u8981\u7D20\u306E\
    \u578B\ntemplate<typename T>\nstruct ZobristHash {\nprivate:\n\tmap<T, uint64_t>\
    \ M1;\n\tmap<T, uint64_t> M2;\n\n\tvoid createRand(const vector<T>& t) {\n\t\t\
    mt19937_64 mt(chrono::steady_clock::now()\n\t\t\t\t\t\t  .time_since_epoch()\n\
    \t\t\t\t\t\t  .count());\n\t\tuniform_int_distribution<uint64_t> rand(1,\n\t\t\
    \t\t\t\t\t\t\t\t\t\t1ll << 62);\n\t\tfor(auto s: t) {\n\t\t\tif(M1[s] != 0) continue;\n\
    \t\t\tM1[s] = rand(mt);\n\t\t\tM2[s] = rand(mt);\n\t\t}\n\t}\n\npublic:\n\tZobristHash()\
    \ {\n\t}\n\t/// @brief queries\u306E\u5404\u30AF\u30A8\u30EA\u306B\u3064\u3044\
    \u3066,t\u306E\u96C6\u5408\u306E\u30CF\u30C3\u30B7\u30E5\u3092\u6C42\u3081\u308B\
    \n\t/// @param t \u30CF\u30C3\u30B7\u30E5\u3092\u6C42\u3081\u308B\u5BFE\u8C61\u306E\
    \u914D\u5217\n\t/// @param queries \u30CF\u30C3\u30B7\u30E5\u3092\u6C42\u3081\u308B\
    \u7BC4\u56F2[l,r)\u306E\u30DA\u30A2\u914D\u5217\n\t/// @return 0<=u<SZ(queries)\u306B\
    \u3064\u3044\u3066,ret[i]\u306F[first,second)\u306E\u96C6\u5408\u3068\u3057\u3066\
    \u306E\u30CF\u30C3\u30B7\u30E5\u304C\u5165\u308B\n\tvector<pair<uint64_t, uint64_t>>\
    \ get(\n\t\tvector<T> const& t,\n\t\tvector<pair<int, int>> const& queries) {\n\
    \t\tcreateRand(t);\n\t\tvector<pair<pair<int, int>, int>> V;\n\t\tREP(i, SZ(queries))\
    \ {\n\t\t\tauto [l, r] = queries[i];\n\t\t\tassert(0 <= l && l < r && r <= SZ(t));\n\
    \t\t\tV.push_back({ { l, r }, i });\n\t\t}\n\t\tso(V);\n\t\tint N = SZ(t);\n\t\
    \tauto op = [](uint64_t a, uint64_t b) -> uint64_t {\n\t\t\treturn a ^ b;\n\t\t\
    };\n\t\tauto e = []() -> uint64_t {\n\t\t\treturn 0;\n\t\t};\n\t\tvector<uint64_t>\
    \ init1(N, e());\n\t\tvector<uint64_t> init2(N, e());\n\t\tvi next(N, -1);\n\t\
    \tmap<T, int> pre;\n\t\tREP(i, N) {\n\t\t\tif(pre[t[i]] != 0) {\n\t\t\t\tnext[pre[t[i]]\
    \ - 1] = i;\n\t\t\t} else {\n\t\t\t\tinit1[i] = M1[t[i]];\n\t\t\t\tinit2[i] =\
    \ M2[t[i]];\n\t\t\t}\n\t\t\tpre[t[i]] = i + 1;\n\t\t}\n\t\tsegtree<uint64_t, op,\
    \ e> seg1(init1);\n\t\tsegtree<uint64_t, op, e> seg2(init2);\n\t\tint curL = 0;\n\
    \t\tvector<pair<uint64_t, uint64_t>> ret(SZ(queries));\n\t\tREP(i, SZ(V)) {\n\t\
    \t\tauto [q, ind] = V[i];\n\t\t\tauto [l, r] = q;\n\t\t\twhile(curL < l) {\n\t\
    \t\t\tseg1.set(curL, e());\n\t\t\t\tseg2.set(curL, e());\n\t\t\t\tif(next[curL]\
    \ != -1) {\n\t\t\t\t\tseg1.set(next[curL], M1[t[next[curL]]]);\n\t\t\t\t\tseg2.set(next[curL],\
    \ M2[t[next[curL]]]);\n\t\t\t\t}\n\t\t\t\tcurL++;\n\t\t\t}\n\t\t\tret[ind] = {\
    \ seg1.prod(l, r), seg2.prod(l, r) };\n\t\t}\n\t\treturn ret;\n\t}\n};"
  dependsOn:
  - base.hpp
  - atcoder/convolution.hpp
  - atcoder/internal_bit.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  - atcoder/dsu.hpp
  - atcoder/fenwicktree.hpp
  - atcoder/lazysegtree.hpp
  - atcoder/math.hpp
  - atcoder/maxflow.hpp
  - atcoder/internal_queue.hpp
  - atcoder/mincostflow.hpp
  - atcoder/scc.hpp
  - atcoder/internal_scc.hpp
  - atcoder/segtree.hpp
  - atcoder/string.hpp
  - atcoder/twosat.hpp
  isVerificationFile: false
  path: structure/zobrist_hash.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/zobrist_hash.hpp
layout: document
redirect_from:
- /library/structure/zobrist_hash.hpp
- /library/structure/zobrist_hash.hpp.html
title: Zobrist Hash
---
