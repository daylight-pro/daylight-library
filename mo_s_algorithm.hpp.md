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
    document_title: "\u533A\u9593\u30AF\u30A8\u30EA\u306B\u9AD8\u901F\u306B\u3053\u305F\
      \u3048\u308B"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"mo_s_algorithm.hpp\"\
    \n/// @brief \u533A\u9593\u30AF\u30A8\u30EA\u306B\u9AD8\u901F\u306B\u3053\u305F\
    \u3048\u308B\n/// @tparam T \u30AF\u30A8\u30EA\u306E\u7B54\u3048\u306E\u578B\n\
    /// @param N \u533A\u9593\u306E\u6700\u5927\u9577\n/// @param queries \u30AF\u30A8\
    \u30EA\u306E\u914D\u5217\n/// @param get (\u30AF\u30A8\u30EA\u756A\u53F7)->\u73FE\
    \u5728\u306E\u533A\u9593\u306E\u7B54\u3048\n/// @param add (\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9,\u5DE6\u304B\u3089\u306E\u64CD\u4F5C\u304B\u3069\u3046\u304B\
    )\n/// @param del (\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9,\u5DE6\u304B\u3089\u306E\
    \u64CD\u4F5C\u304B\u3069\u3046\u304B)\n/// @return \u30AF\u30A8\u30EA\u306E\u7B54\
    \u3048\u306E\u914D\u5217\ntemplate<typename T, typename F1, typename F2>\ninline\
    \ vector<T> Mo_s_algorithm(\n\tint N, vector<pair<int, int>>& queries, F1 get,\
    \ F2 add,\n\tF2 del) {\n\tint Q = SZ(queries);\n\tif(Q == 0) return vector<T>(0);\n\
    \tint curL = 0;\n\tint curR = 0;\n\tvi Qi(Q);\n\tiota(ALL(Qi), 0);\n\tsort(ALL(Qi),\
    \ [&](int i, int j) {\n\t\tint bi\n\t\t\t= queries[i].first / max(1, int(N / sqrt(Q)));\n\
    \t\tint bj\n\t\t\t= queries[j].first / max(1, int(N / sqrt(Q)));\n\t\tif(bi !=\
    \ bj) return bi < bj;\n\t\treturn queries[i].second < queries[j].second;\n\t});\n\
    \tvector<T> ret(Q, T(0));\n\tfor(auto i: Qi) {\n\t\tauto [l, r] = queries[i];\n\
    \t\twhile(curR < r) {\n\t\t\tadd(curR, false);\n\t\t\tcurR++;\n\t\t}\n\t\twhile(curL\
    \ < l) {\n\t\t\tdel(curL, true);\n\t\t\tcurL++;\n\t\t}\n\t\twhile(r < curR) {\n\
    \t\t\tcurR--;\n\t\t\tdel(curR, false);\n\t\t}\n\t\twhile(l < curL) {\n\t\t\tcurL--;\n\
    \t\t\tadd(curL, true);\n\t\t}\n\t\tret[i] = get(i);\n\t}\n\treturn ret;\n}\n"
  code: "#include \"./base.hpp\"\n/// @brief \u533A\u9593\u30AF\u30A8\u30EA\u306B\u9AD8\
    \u901F\u306B\u3053\u305F\u3048\u308B\n/// @tparam T \u30AF\u30A8\u30EA\u306E\u7B54\
    \u3048\u306E\u578B\n/// @param N \u533A\u9593\u306E\u6700\u5927\u9577\n/// @param\
    \ queries \u30AF\u30A8\u30EA\u306E\u914D\u5217\n/// @param get (\u30AF\u30A8\u30EA\
    \u756A\u53F7)->\u73FE\u5728\u306E\u533A\u9593\u306E\u7B54\u3048\n/// @param add\
    \ (\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9,\u5DE6\u304B\u3089\u306E\u64CD\u4F5C\u304B\
    \u3069\u3046\u304B)\n/// @param del (\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9,\u5DE6\
    \u304B\u3089\u306E\u64CD\u4F5C\u304B\u3069\u3046\u304B)\n/// @return \u30AF\u30A8\
    \u30EA\u306E\u7B54\u3048\u306E\u914D\u5217\ntemplate<typename T, typename F1,\
    \ typename F2>\ninline vector<T> Mo_s_algorithm(\n\tint N, vector<pair<int, int>>&\
    \ queries, F1 get, F2 add,\n\tF2 del) {\n\tint Q = SZ(queries);\n\tif(Q == 0)\
    \ return vector<T>(0);\n\tint curL = 0;\n\tint curR = 0;\n\tvi Qi(Q);\n\tiota(ALL(Qi),\
    \ 0);\n\tsort(ALL(Qi), [&](int i, int j) {\n\t\tint bi\n\t\t\t= queries[i].first\
    \ / max(1, int(N / sqrt(Q)));\n\t\tint bj\n\t\t\t= queries[j].first / max(1, int(N\
    \ / sqrt(Q)));\n\t\tif(bi != bj) return bi < bj;\n\t\treturn queries[i].second\
    \ < queries[j].second;\n\t});\n\tvector<T> ret(Q, T(0));\n\tfor(auto i: Qi) {\n\
    \t\tauto [l, r] = queries[i];\n\t\twhile(curR < r) {\n\t\t\tadd(curR, false);\n\
    \t\t\tcurR++;\n\t\t}\n\t\twhile(curL < l) {\n\t\t\tdel(curL, true);\n\t\t\tcurL++;\n\
    \t\t}\n\t\twhile(r < curR) {\n\t\t\tcurR--;\n\t\t\tdel(curR, false);\n\t\t}\n\t\
    \twhile(l < curL) {\n\t\t\tcurL--;\n\t\t\tadd(curL, true);\n\t\t}\n\t\tret[i]\
    \ = get(i);\n\t}\n\treturn ret;\n}\n"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: mo_s_algorithm.hpp
  requiredBy: []
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mo_s_algorithm.hpp
layout: document
redirect_from:
- /library/mo_s_algorithm.hpp
- /library/mo_s_algorithm.hpp.html
title: "\u533A\u9593\u30AF\u30A8\u30EA\u306B\u9AD8\u901F\u306B\u3053\u305F\u3048\u308B"
---
