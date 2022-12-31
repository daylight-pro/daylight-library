---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base.hpp
    title: base.hpp
  - icon: ':warning:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/all.hpp
    title: graph/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5"
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
    template<class T = ll>\nusing Graph = vector<Edges<T>>;\n#line 3 \"graph/bellman_ford.hpp\"\
    \n/// @brief \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\n\n/// @brief\
    \ \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\u3067\u5358\u4E00\u59CB\
    \u70B9\u6700\u77ED\u7D4C\u8DEF\u9577\u554F\u984C\u3092\u89E3\u304F\n/// @param\
    \ V \u9802\u70B9\u6570\n/// @param EG \u8FBA\u306E\u30EA\u30B9\u30C8\n/// @param\
    \ s \u59CB\u70B9\n/// @param D out:\u6700\u77ED\u7D4C\u8DEF\u9577\u304C\u5165\u308B\
    \u914D\u5217\n/// @return \u8CA0\u9589\u8DEF\u3092\u542B\u3080\u304B\u3069\u3046\
    \u304B\nbool shortest_path(int V, Edges<ll>& EG, int s, vll& D) {\n\tD = vll(V,\
    \ LINF);\n\tD[s] = 0;\n\tint cnt = 0;\n\twhile(true) {\n\t\tbool update = false;\
    \  //\u3053\u306E\u30EB\u30FC\u30D7\u3067\u66F4\u65B0\u304C\u8D77\u3053\u3063\u305F\
    \u304B\n\t\tfor(auto e: EG) {\n\t\t\tif(D[e.from] == LINF) continue;\n\t\t\tif(chmin(D[e.to],\
    \ D[e.from] + e.cost)) {\n\t\t\t\t//\u3053\u306EEdge\u3092\u901A\u308B\u3068\u66AB\
    \u5B9A\u3088\u308A\u4F4E\u30B3\u30B9\u30C8\u3067e.to\u306B\u884C\u3051\u308B\u5834\
    \u5408\n\t\t\t\tD[e.to] = D[e.from] + e.cost;  //\u5024\u3092\u66F4\u65B0\n\t\t\
    \t\tupdate = true;\n\t\t\t}\n\t\t}\n\t\tif(!update) return false;  //\u6700\u77ED\
    \u8DDD\u96E2\u306E\u66F4\u65B0\u304C\u7D42\u4E86\n\t\tcnt++;\n\t\tif(cnt == V)\
    \ return true;\n\t}\n}\n"
  code: "#include \"../base.hpp\"\n#include \"./base.hpp\"\n/// @brief \u30D9\u30EB\
    \u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\n\n/// @brief \u30D9\u30EB\u30DE\u30F3\
    \u30D5\u30A9\u30FC\u30C9\u6CD5\u3067\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\
    \u8DEF\u9577\u554F\u984C\u3092\u89E3\u304F\n/// @param V \u9802\u70B9\u6570\n\
    /// @param EG \u8FBA\u306E\u30EA\u30B9\u30C8\n/// @param s \u59CB\u70B9\n/// @param\
    \ D out:\u6700\u77ED\u7D4C\u8DEF\u9577\u304C\u5165\u308B\u914D\u5217\n/// @return\
    \ \u8CA0\u9589\u8DEF\u3092\u542B\u3080\u304B\u3069\u3046\u304B\nbool shortest_path(int\
    \ V, Edges<ll>& EG, int s, vll& D) {\n\tD = vll(V, LINF);\n\tD[s] = 0;\n\tint\
    \ cnt = 0;\n\twhile(true) {\n\t\tbool update = false;  //\u3053\u306E\u30EB\u30FC\
    \u30D7\u3067\u66F4\u65B0\u304C\u8D77\u3053\u3063\u305F\u304B\n\t\tfor(auto e:\
    \ EG) {\n\t\t\tif(D[e.from] == LINF) continue;\n\t\t\tif(chmin(D[e.to], D[e.from]\
    \ + e.cost)) {\n\t\t\t\t//\u3053\u306EEdge\u3092\u901A\u308B\u3068\u66AB\u5B9A\
    \u3088\u308A\u4F4E\u30B3\u30B9\u30C8\u3067e.to\u306B\u884C\u3051\u308B\u5834\u5408\
    \n\t\t\t\tD[e.to] = D[e.from] + e.cost;  //\u5024\u3092\u66F4\u65B0\n\t\t\t\t\
    update = true;\n\t\t\t}\n\t\t}\n\t\tif(!update) return false;  //\u6700\u77ED\u8DDD\
    \u96E2\u306E\u66F4\u65B0\u304C\u7D42\u4E86\n\t\tcnt++;\n\t\tif(cnt == V) return\
    \ true;\n\t}\n}"
  dependsOn:
  - base.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/bellman_ford.hpp
  requiredBy:
  - graph/all.hpp
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/graph/bellman_ford.hpp
- /library/graph/bellman_ford.hpp.html
title: "\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5"
---
