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
    document_title: "a^n=b(mod m)\u3068\u306A\u308B\u6700\u5C0F\u306En\u3092\u6C42\
      \u3081\u308B"
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
    #line 3 \"math/modlog.hpp\"\nusing namespace atcoder;\n\n/// @brief a^n=b(mod\
    \ m)\u3068\u306A\u308B\u6700\u5C0F\u306En\u3092\u6C42\u3081\u308B\n/// @param\
    \ a \u30D1\u30E9\u30E1\u30FC\u30BF\n/// @param b \u30D1\u30E9\u30E1\u30FC\u30BF\
    \n/// @param m \u9664\u6570\n/// @return n\u304C\u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408-1,\u5B58\u5728\u3059\u308B\u5834\u5408n\nll modlog(ll a, ll b, ll\
    \ m) {\n\ta %= m;\n\tb %= m;\n\tif(a == 0) {\n\t\tif(b == 1)\n\t\t\treturn 0;\n\
    \t\telse if(b == 0)\n\t\t\treturn 1;\n\t\telse\n\t\t\treturn -1;\n\t}\n\tif(b\
    \ == 1) {\n\t\treturn 0;\n\t}\n\tll sq = 1;\n\twhile(sq * sq < m) sq++;\n\tmap<ll,\
    \ ll> A;\n\tll cur = a;\n\tFOR(r, 1, sq) {\n\t\tif(!A.count(cur)) A[cur] = r;\n\
    \t\tcur *= a;\n\t\tcur %= m;\n\t}\n\tusing mint = modint;\n\tmint::set_mod(m);\n\
    \tll a_powM = mint(a).inv().pow(sq).val();\n\tcur = b;\n\tREP(q, sq) {\n\t\tif(cur\
    \ == 1 && q > 0) return q * sq;\n\t\tif(A.count(cur)) return q * sq + A[cur];\n\
    \t\tcur *= a_powM;\n\t\tcur %= m;\n\t}\n\treturn -1;\n}\n"
  code: "#include \"../base.hpp\"\n#include \"atcoder/all\"\nusing namespace atcoder;\n\
    \n/// @brief a^n=b(mod m)\u3068\u306A\u308B\u6700\u5C0F\u306En\u3092\u6C42\u3081\
    \u308B\n/// @param a \u30D1\u30E9\u30E1\u30FC\u30BF\n/// @param b \u30D1\u30E9\
    \u30E1\u30FC\u30BF\n/// @param m \u9664\u6570\n/// @return n\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u5834\u5408-1,\u5B58\u5728\u3059\u308B\u5834\u5408n\nll modlog(ll\
    \ a, ll b, ll m) {\n\ta %= m;\n\tb %= m;\n\tif(a == 0) {\n\t\tif(b == 1)\n\t\t\
    \treturn 0;\n\t\telse if(b == 0)\n\t\t\treturn 1;\n\t\telse\n\t\t\treturn -1;\n\
    \t}\n\tif(b == 1) {\n\t\treturn 0;\n\t}\n\tll sq = 1;\n\twhile(sq * sq < m) sq++;\n\
    \tmap<ll, ll> A;\n\tll cur = a;\n\tFOR(r, 1, sq) {\n\t\tif(!A.count(cur)) A[cur]\
    \ = r;\n\t\tcur *= a;\n\t\tcur %= m;\n\t}\n\tusing mint = modint;\n\tmint::set_mod(m);\n\
    \tll a_powM = mint(a).inv().pow(sq).val();\n\tcur = b;\n\tREP(q, sq) {\n\t\tif(cur\
    \ == 1 && q > 0) return q * sq;\n\t\tif(A.count(cur)) return q * sq + A[cur];\n\
    \t\tcur *= a_powM;\n\t\tcur %= m;\n\t}\n\treturn -1;\n}"
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
  path: math/modlog.hpp
  requiredBy: []
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modlog.hpp
layout: document
redirect_from:
- /library/math/modlog.hpp
- /library/math/modlog.hpp.html
title: "a^n=b(mod m)\u3068\u306A\u308B\u6700\u5C0F\u306En\u3092\u6C42\u3081\u308B"
---
