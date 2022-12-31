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
    document_title: "\u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\u3092\u6C42\
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 3 \"graph/base.hpp\"\
    \ntemplate<class T = ll>\nstruct Edge {\npublic:\n\tint from, to;\n\tT cost;\n\
    \tEdge() {\n\t}\n\tEdge(int _from, int _to, T _cost) {\n\t\tfrom = _from;\n\t\t\
    to = _to;\n\t\tcost = _cost;\n\t}\n};\ntemplate<class T = ll>\nusing Edges = vector<Edge<T>>;\n\
    template<class T = ll>\nusing Graph = vector<Edges<T>>;\n#line 1 \"atcoder/all\"\
    \n#include <atcoder/convolution>\n#include <atcoder/dsu>\n#include <atcoder/fenwicktree>\n\
    #include <atcoder/lazysegtree>\n#include <atcoder/math>\n#include <atcoder/maxflow>\n\
    #include <atcoder/mincostflow>\n#include <atcoder/modint>\n#include <atcoder/scc>\n\
    #include <atcoder/segtree>\n#include <atcoder/string>\n#include <atcoder/twosat>\n\
    #line 4 \"graph/kruskal.hpp\"\nusing namespace atcoder;\n/// @brief \u6700\u5C0F\
    \u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\u3092\u6C42\u3081\u308B\n/// @param\
    \ V \u9802\u70B9\u6570\n/// @param ES \u8FBA\u96C6\u5408\n/// @return \u30B0\u30E9\
    \u30D5\u304C\u9023\u7D50\u3067\u306A\u3051\u308C\u3070LINF,\u9023\u7D50\u306A\u3089\
    \u3070\u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\nll kruskal(int V,\
    \ Edges<>& ES) {\n\tsort(ALL(ES), [](Edge<> const& a, Edge<> const& b) {\n\t\t\
    if(a.cost != b.cost) return a.cost < b.cost;\n\t\tif(a.from != b.from) return\
    \ a.from < b.from;\n\t\treturn a.to < b.to;\n\t});\n\tll ret = 0;\n\tdsu d(V);\n\
    \tREP(i, SZ(ES)) {\n\t\tEdge e = ES[i];\n\t\tif(!d.same(e.from, e.to)) {\n\t\t\
    \tret += e.cost;\n\t\t\td.merge(e.from, e.to);\n\t\t}\n\t}\n\tif(d.size(0) !=\
    \ V) {\n\t\treturn LINF;\n\t}\n\treturn ret;\n}\n"
  code: "#include \"../base.hpp\"\n#include \"./base.hpp\"\n#include \"atcoder/all\"\
    \nusing namespace atcoder;\n/// @brief \u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\
    \u30B9\u30C8\u3092\u6C42\u3081\u308B\n/// @param V \u9802\u70B9\u6570\n/// @param\
    \ ES \u8FBA\u96C6\u5408\n/// @return \u30B0\u30E9\u30D5\u304C\u9023\u7D50\u3067\
    \u306A\u3051\u308C\u3070LINF,\u9023\u7D50\u306A\u3089\u3070\u6700\u5C0F\u5168\u57DF\
    \u6728\u306E\u30B3\u30B9\u30C8\nll kruskal(int V, Edges<>& ES) {\n\tsort(ALL(ES),\
    \ [](Edge<> const& a, Edge<> const& b) {\n\t\tif(a.cost != b.cost) return a.cost\
    \ < b.cost;\n\t\tif(a.from != b.from) return a.from < b.from;\n\t\treturn a.to\
    \ < b.to;\n\t});\n\tll ret = 0;\n\tdsu d(V);\n\tREP(i, SZ(ES)) {\n\t\tEdge e =\
    \ ES[i];\n\t\tif(!d.same(e.from, e.to)) {\n\t\t\tret += e.cost;\n\t\t\td.merge(e.from,\
    \ e.to);\n\t\t}\n\t}\n\tif(d.size(0) != V) {\n\t\treturn LINF;\n\t}\n\treturn\
    \ ret;\n}"
  dependsOn:
  - base.hpp
  - graph/base.hpp
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
  path: graph/kruskal.hpp
  requiredBy:
  - graph/all.hpp
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/kruskal.hpp
layout: document
redirect_from:
- /library/graph/kruskal.hpp
- /library/graph/kruskal.hpp.html
title: "\u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\u3092\u6C42\u3081\u308B"
---
