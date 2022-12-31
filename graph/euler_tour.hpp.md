---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base.hpp
    title: base.hpp
  - icon: ':warning:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
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
    template<class T = ll>\nusing Graph = vector<Edges<T>>;\n#line 3 \"graph/euler_tour.hpp\"\
    \n/// @brief \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\n\n/// @brief \u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC\u3092\u6C42\u3081\u307E\u3059\n/// @param G \u30B0\
    \u30E9\u30D5\n/// @param root \u6728\u306E\u6839\n/// @return \u5404\u9802\u70B9\
    \u306B\u5272\u308A\u5F53\u3066\u3089\u308C\u305F\u9589\u533A\u9593\nvector<pair<int,\
    \ int>> eulerTour(Graph<> &G, int root = 0) {\n\tint N = SZ(G);\n\tvector<pair<int,\
    \ int>> ret(N);\n\tint turn = 0;\n\tauto dfs = [&](auto f, int cur, int pre) ->\
    \ void {\n\t\tret[cur].first = turn++;\n\t\tfor(Edge e: G[cur]) {\n\t\t\tif(e.to\
    \ == pre) continue;\n\t\t\tf(f, e.to, cur);\n\t\t}\n\t\tret[cur].second = turn++;\n\
    \t};\n\tdfs(dfs, root, -1);\n\treturn ret;\n}\n"
  code: "#include \"../base.hpp\"\n#include \"./base.hpp\"\n/// @brief \u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC\n\n/// @brief \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\
    \u30FC\u3092\u6C42\u3081\u307E\u3059\n/// @param G \u30B0\u30E9\u30D5\n/// @param\
    \ root \u6728\u306E\u6839\n/// @return \u5404\u9802\u70B9\u306B\u5272\u308A\u5F53\
    \u3066\u3089\u308C\u305F\u9589\u533A\u9593\nvector<pair<int, int>> eulerTour(Graph<>\
    \ &G, int root = 0) {\n\tint N = SZ(G);\n\tvector<pair<int, int>> ret(N);\n\t\
    int turn = 0;\n\tauto dfs = [&](auto f, int cur, int pre) -> void {\n\t\tret[cur].first\
    \ = turn++;\n\t\tfor(Edge e: G[cur]) {\n\t\t\tif(e.to == pre) continue;\n\t\t\t\
    f(f, e.to, cur);\n\t\t}\n\t\tret[cur].second = turn++;\n\t};\n\tdfs(dfs, root,\
    \ -1);\n\treturn ret;\n}"
  dependsOn:
  - base.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/euler_tour.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/euler_tour.hpp
layout: document
redirect_from:
- /library/graph/euler_tour.hpp
- /library/graph/euler_tour.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
---
