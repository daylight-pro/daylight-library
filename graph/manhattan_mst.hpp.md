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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3067MST"
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
    #line 4 \"graph/manhattan_mst.hpp\"\nusing namespace atcoder;\n\nPL op_for_manhattan_mst(PL\
    \ a, PL b) {\n\treturn min(a, b);\n}\nPL e_for_manhattan_mst() {\n\treturn { LINF,\
    \ -1 };\n}\n\n/// @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3067\
    MST\n/// @param V \u70B9\u306E\u96C6\u5408\n/// @return MST\nGraph<> manhattan_mst(vector<PL>&\
    \ V) {\n\tint N = SZ(V);\n\tGraph<> G(N);\n\tif(N == 1) {\n\t\treturn G;\n\t}\n\
    \tEdges<> EG;\n\tauto sweep = [&]() {\n\t\tvll y;\n\t\tREP(i, N) {\n\t\t\ty.push_back(V[i].second);\n\
    \t\t}\n\t\tso(y);\n\t\tuni(y);\n\t\tint y_len = SZ(y);\n\t\tmap<ll, int> y_ind;\n\
    \t\tREP(i, y_len) {\n\t\t\ty_ind[y[i]] = i;\n\t\t}\n\t\tsegtree<PL, op_for_manhattan_mst,\n\
    \t\t\t\te_for_manhattan_mst>\n\t\t\tseg(y_len);\n\t\tvi p(N);\n\t\tREP(i, N) {\n\
    \t\t\tp[i] = i;\n\t\t}\n\t\tsort(ALL(p), [=](auto const& l, auto const& r) {\n\
    \t\t\tauto [lx, ly] = V[l];\n\t\t\tauto [rx, ry] = V[r];\n\t\t\tif(ly - lx !=\
    \ ry - rx) return ly - lx < ry - rx;\n\t\t\tif(ly != ry) return ly > ry;\n\t\t\
    \treturn l < r;\n\t\t});\n\t\tREP(i, N) {\n\t\t\tint v = p[i];\n\t\t\tauto [x,\
    \ y] = V[v];\n\t\t\tPL d = seg.prod(y_ind[y], y_len);\n\t\t\tif(d != e_for_manhattan_mst())\
    \ {\n\t\t\t\tauto [nx, ny] = V[d.second];\n\t\t\t\tEG.eb(v, d.second,\n\t\t\t\t\
    \t  abs(x - nx) + abs(y - ny));\n\t\t\t}\n\t\t\tPL c = seg.get(y_ind[y]);\n\t\t\
    \tif(c.first > x + y) {\n\t\t\t\tseg.set(y_ind[y], { x + y, v });\n\t\t\t}\n\t\
    \t}\n\t};\n\tREP(i, 2) {\n\t\tREP(j, 2) {\n\t\t\tREP(k, 2) {\n\t\t\t\tsweep();\n\
    \t\t\t\tREP(l, N) {\n\t\t\t\t\tswap(V[l].first, V[l].second);\n\t\t\t\t}\n\t\t\
    \t}\n\t\t\tREP(l, N) {\n\t\t\t\tV[l].first *= -1;\n\t\t\t}\n\t\t}\n\t\tREP(l,\
    \ N) {\n\t\t\tV[l].second *= -1;\n\t\t}\n\t}\n\tdsu d(N);\n\tsort(ALL(EG), [](auto\
    \ const& lhs, auto const& rhs) {\n\t\tif(lhs.cost != rhs.cost)\n\t\t\treturn lhs.cost\
    \ < rhs.cost;\n\t\telse if(lhs.from != rhs.from)\n\t\t\treturn lhs.from < rhs.from;\n\
    \t\treturn lhs.to < rhs.to;\n\t});\n\tfor(auto e: EG) {\n\t\tif(d.same(e.from,\
    \ e.to)) continue;\n\t\td.merge(e.from, e.to);\n\t\tG[e.from].eb(e.from, e.to,\
    \ e.cost);\n\t\tG[e.to].eb(e.to, e.from, e.cost);\n\t}\n\tassert(d.size(0) ==\
    \ N);\n\treturn G;\n}\n"
  code: "#include \"../base.hpp\"\n#include \"./base.hpp\"\n#include \"atcoder/all\"\
    \nusing namespace atcoder;\n\nPL op_for_manhattan_mst(PL a, PL b) {\n\treturn\
    \ min(a, b);\n}\nPL e_for_manhattan_mst() {\n\treturn { LINF, -1 };\n}\n\n///\
    \ @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3067MST\n/// @param\
    \ V \u70B9\u306E\u96C6\u5408\n/// @return MST\nGraph<> manhattan_mst(vector<PL>&\
    \ V) {\n\tint N = SZ(V);\n\tGraph<> G(N);\n\tif(N == 1) {\n\t\treturn G;\n\t}\n\
    \tEdges<> EG;\n\tauto sweep = [&]() {\n\t\tvll y;\n\t\tREP(i, N) {\n\t\t\ty.push_back(V[i].second);\n\
    \t\t}\n\t\tso(y);\n\t\tuni(y);\n\t\tint y_len = SZ(y);\n\t\tmap<ll, int> y_ind;\n\
    \t\tREP(i, y_len) {\n\t\t\ty_ind[y[i]] = i;\n\t\t}\n\t\tsegtree<PL, op_for_manhattan_mst,\n\
    \t\t\t\te_for_manhattan_mst>\n\t\t\tseg(y_len);\n\t\tvi p(N);\n\t\tREP(i, N) {\n\
    \t\t\tp[i] = i;\n\t\t}\n\t\tsort(ALL(p), [=](auto const& l, auto const& r) {\n\
    \t\t\tauto [lx, ly] = V[l];\n\t\t\tauto [rx, ry] = V[r];\n\t\t\tif(ly - lx !=\
    \ ry - rx) return ly - lx < ry - rx;\n\t\t\tif(ly != ry) return ly > ry;\n\t\t\
    \treturn l < r;\n\t\t});\n\t\tREP(i, N) {\n\t\t\tint v = p[i];\n\t\t\tauto [x,\
    \ y] = V[v];\n\t\t\tPL d = seg.prod(y_ind[y], y_len);\n\t\t\tif(d != e_for_manhattan_mst())\
    \ {\n\t\t\t\tauto [nx, ny] = V[d.second];\n\t\t\t\tEG.eb(v, d.second,\n\t\t\t\t\
    \t  abs(x - nx) + abs(y - ny));\n\t\t\t}\n\t\t\tPL c = seg.get(y_ind[y]);\n\t\t\
    \tif(c.first > x + y) {\n\t\t\t\tseg.set(y_ind[y], { x + y, v });\n\t\t\t}\n\t\
    \t}\n\t};\n\tREP(i, 2) {\n\t\tREP(j, 2) {\n\t\t\tREP(k, 2) {\n\t\t\t\tsweep();\n\
    \t\t\t\tREP(l, N) {\n\t\t\t\t\tswap(V[l].first, V[l].second);\n\t\t\t\t}\n\t\t\
    \t}\n\t\t\tREP(l, N) {\n\t\t\t\tV[l].first *= -1;\n\t\t\t}\n\t\t}\n\t\tREP(l,\
    \ N) {\n\t\t\tV[l].second *= -1;\n\t\t}\n\t}\n\tdsu d(N);\n\tsort(ALL(EG), [](auto\
    \ const& lhs, auto const& rhs) {\n\t\tif(lhs.cost != rhs.cost)\n\t\t\treturn lhs.cost\
    \ < rhs.cost;\n\t\telse if(lhs.from != rhs.from)\n\t\t\treturn lhs.from < rhs.from;\n\
    \t\treturn lhs.to < rhs.to;\n\t});\n\tfor(auto e: EG) {\n\t\tif(d.same(e.from,\
    \ e.to)) continue;\n\t\td.merge(e.from, e.to);\n\t\tG[e.from].eb(e.from, e.to,\
    \ e.cost);\n\t\tG[e.to].eb(e.to, e.from, e.cost);\n\t}\n\tassert(d.size(0) ==\
    \ N);\n\treturn G;\n}"
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
  path: graph/manhattan_mst.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/manhattan_mst.hpp
layout: document
redirect_from:
- /library/graph/manhattan_mst.hpp
- /library/graph/manhattan_mst.hpp.html
title: "\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3067MST"
---
