---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/all.hpp
    title: graph/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"graph/floyd.hpp\"\
    \n/// @brief \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\n\n\
    /// @brief \u5168\u70B9\u5BFE\u6700\u77ED\u7D4C\u8DEF\u9577\u554F\u984C\u3092\u89E3\
    \u304F\n/// @param n \u9802\u70B9\u6570\n/// @param WF \u96A3\u63A5\u884C\u5217\
    (out:\u6700\u77ED\u7D4C\u8DEF\u9577)\nvoid floyd(int n, vector<vll>& WF) {\n\t\
    REP(k, n)\n\tREP(i, n) {\n\t\tif(WF[i][k] == LINF) continue;\n\t\tREP(j, n) {\n\
    \t\t\tif(WF[k][j] == LINF) continue;\n\t\t\tchmin(WF[i][j], WF[i][k] + WF[k][j]);\n\
    \t\t}\n\t}\n}\n"
  code: "#include \"../base.hpp\"\n/// @brief \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\
    \u30ED\u30A4\u30C9\u6CD5\n\n/// @brief \u5168\u70B9\u5BFE\u6700\u77ED\u7D4C\u8DEF\
    \u9577\u554F\u984C\u3092\u89E3\u304F\n/// @param n \u9802\u70B9\u6570\n/// @param\
    \ WF \u96A3\u63A5\u884C\u5217(out:\u6700\u77ED\u7D4C\u8DEF\u9577)\nvoid floyd(int\
    \ n, vector<vll>& WF) {\n\tREP(k, n)\n\tREP(i, n) {\n\t\tif(WF[i][k] == LINF)\
    \ continue;\n\t\tREP(j, n) {\n\t\t\tif(WF[k][j] == LINF) continue;\n\t\t\tchmin(WF[i][j],\
    \ WF[i][k] + WF[k][j]);\n\t\t}\n\t}\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/floyd.hpp
  requiredBy:
  - graph/all.hpp
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/floyd.hpp
layout: document
redirect_from:
- /library/graph/floyd.hpp
- /library/graph/floyd.hpp.html
title: "\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5"
---
