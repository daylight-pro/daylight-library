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
  - icon: ':warning:'
    path: graph/bellman_ford.hpp
    title: "\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\u3067\u5358\u4E00\
      \u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u9577\u554F\u984C\u3092\u89E3\u304F"
  - icon: ':warning:'
    path: graph/cycle_detection.hpp
    title: graph/cycle_detection.hpp
  - icon: ':warning:'
    path: graph/diameter.hpp
    title: graph/diameter.hpp
  - icon: ':warning:'
    path: graph/dijkstra.hpp
    title: "\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u9577\u554F\u984C\u3092\
      \u89E3\u304F"
  - icon: ':warning:'
    path: graph/euler_tour.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u3092\u6C42\u3081\u307E\u3059"
  - icon: ':warning:'
    path: graph/kruskal.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\u3092\u6C42\u3081\
      \u308B"
  - icon: ':warning:'
    path: graph/lca.hpp
    title: graph/lca.hpp
  - icon: ':warning:'
    path: graph/manhattan_mst.hpp
    title: graph/manhattan_mst.hpp
  - icon: ':warning:'
    path: rerooting.hpp
    title: "\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 3 \"graph/base.hpp\"\
    \ntemplate<class T = ll>\nstruct Edge {\npublic:\n\tint from, to;\n\tT cost;\n\
    \tEdge() {\n\t}\n\tEdge(int _from, int _to, T _cost) {\n\t\tfrom = _from;\n\t\t\
    to = _to;\n\t\tcost = _cost;\n\t}\n};\ntemplate<class T = ll>\nusing Edges = vector<Edge<T>>;\n\
    template<class T = ll>\nusing Graph = vector<Edges<T>>;\n"
  code: "#pragma once\n#include \"../base.hpp\"\ntemplate<class T = ll>\nstruct Edge\
    \ {\npublic:\n\tint from, to;\n\tT cost;\n\tEdge() {\n\t}\n\tEdge(int _from, int\
    \ _to, T _cost) {\n\t\tfrom = _from;\n\t\tto = _to;\n\t\tcost = _cost;\n\t}\n\
    };\ntemplate<class T = ll>\nusing Edges = vector<Edge<T>>;\ntemplate<class T =\
    \ ll>\nusing Graph = vector<Edges<T>>;"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/base.hpp
  requiredBy:
  - rerooting.hpp
  - graph/cycle_detection.hpp
  - graph/lca.hpp
  - graph/diameter.hpp
  - graph/dijkstra.hpp
  - graph/kruskal.hpp
  - graph/all.hpp
  - graph/manhattan_mst.hpp
  - graph/bellman_ford.hpp
  - graph/euler_tour.hpp
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/base.hpp
layout: document
redirect_from:
- /library/graph/base.hpp
- /library/graph/base.hpp.html
title: graph/base.hpp
---
