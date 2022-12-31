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
    document_title: LCA
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
    template<class T = ll>\nusing Graph = vector<Edges<T>>;\n#line 3 \"graph/lca.hpp\"\
    \n/// @brief LCA\nstruct LCA {\nprivate:\n\tvvi parent;\n\tvi dis;\n\tvoid dfs(int\
    \ cur, int pre, const Graph<>& G, int d) {\n\t\tparent[0][cur] = pre;\n\t\tdis[cur]\
    \ = d;\n\t\tfor(auto e: G[cur]) {\n\t\t\tif(e.to == pre) continue;\n\t\t\tdfs(e.to,\
    \ cur, G, d + e.cost);\n\t\t}\n\t}\n\npublic:\n\tLCA(const Graph<>& G) {\n\t\t\
    int N = SZ(G);\n\t\tint K = 1;\n\t\twhile((1 << K) < N) K++;\n\t\tparent = vvi(K,\
    \ vi(N, -1));\n\t\tdis = vi(N, -1);\n\t\tdfs(0, -1, G, 0);\n\t\tREP(i, K - 1)\
    \ {\n\t\t\tREP(j, N) {\n\t\t\t\tif(parent[i][j] < 0) {\n\t\t\t\t\tparent[i + 1][j]\
    \ = -1;\n\t\t\t\t} else {\n\t\t\t\t\tparent[i + 1][j]\n\t\t\t\t\t\t= parent[i][parent[i][j]];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tint query(int u, int v, int root) {\n\t\treturn\
    \ query(u, v) ^ query(v, root)\n\t\t\t^ query(u, root);\n\t}\n\tint query(int\
    \ u, int v) {\n\t\tassert(u >= 0 && v >= 0 && u < SZ(dis)\n\t\t\t   && v < SZ(dis)\
    \ && \"invalid vertex index\");\n\t\tif(dis[u] < dis[v]) swap(u, v);\n\t\tint\
    \ K = SZ(parent);\n\t\tREP(i, K) {\n\t\t\tif((dis[u] - dis[v]) >> i & 1) {\n\t\
    \t\t\tu = parent[i][u];\n\t\t\t}\n\t\t}\n\t\tif(u == v) return u;\n\t\tREPR(i,\
    \ K) {\n\t\t\tif(parent[i][u] != parent[i][v]) {\n\t\t\t\tu = parent[i][u];\n\t\
    \t\t\tv = parent[i][v];\n\t\t\t}\n\t\t}\n\t\treturn parent[0][u];\n\t}\n\n\tint\
    \ get_dis(int u, int v) {\n\t\tassert(u >= 0 && v >= 0 && u < SZ(dis)\n\t\t\t\
    \   && v < SZ(dis) && \"invalid vertex index\");\n\t\treturn dis[u] + dis[v] -\
    \ 2 * dis[query(u, v)];\n\t}\n};\n"
  code: "#include \"../base.hpp\"\n#include \"./base.hpp\"\n/// @brief LCA\nstruct\
    \ LCA {\nprivate:\n\tvvi parent;\n\tvi dis;\n\tvoid dfs(int cur, int pre, const\
    \ Graph<>& G, int d) {\n\t\tparent[0][cur] = pre;\n\t\tdis[cur] = d;\n\t\tfor(auto\
    \ e: G[cur]) {\n\t\t\tif(e.to == pre) continue;\n\t\t\tdfs(e.to, cur, G, d + e.cost);\n\
    \t\t}\n\t}\n\npublic:\n\tLCA(const Graph<>& G) {\n\t\tint N = SZ(G);\n\t\tint\
    \ K = 1;\n\t\twhile((1 << K) < N) K++;\n\t\tparent = vvi(K, vi(N, -1));\n\t\t\
    dis = vi(N, -1);\n\t\tdfs(0, -1, G, 0);\n\t\tREP(i, K - 1) {\n\t\t\tREP(j, N)\
    \ {\n\t\t\t\tif(parent[i][j] < 0) {\n\t\t\t\t\tparent[i + 1][j] = -1;\n\t\t\t\t\
    } else {\n\t\t\t\t\tparent[i + 1][j]\n\t\t\t\t\t\t= parent[i][parent[i][j]];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tint query(int u, int v, int root) {\n\t\treturn\
    \ query(u, v) ^ query(v, root)\n\t\t\t^ query(u, root);\n\t}\n\tint query(int\
    \ u, int v) {\n\t\tassert(u >= 0 && v >= 0 && u < SZ(dis)\n\t\t\t   && v < SZ(dis)\
    \ && \"invalid vertex index\");\n\t\tif(dis[u] < dis[v]) swap(u, v);\n\t\tint\
    \ K = SZ(parent);\n\t\tREP(i, K) {\n\t\t\tif((dis[u] - dis[v]) >> i & 1) {\n\t\
    \t\t\tu = parent[i][u];\n\t\t\t}\n\t\t}\n\t\tif(u == v) return u;\n\t\tREPR(i,\
    \ K) {\n\t\t\tif(parent[i][u] != parent[i][v]) {\n\t\t\t\tu = parent[i][u];\n\t\
    \t\t\tv = parent[i][v];\n\t\t\t}\n\t\t}\n\t\treturn parent[0][u];\n\t}\n\n\tint\
    \ get_dis(int u, int v) {\n\t\tassert(u >= 0 && v >= 0 && u < SZ(dis)\n\t\t\t\
    \   && v < SZ(dis) && \"invalid vertex index\");\n\t\treturn dis[u] + dis[v] -\
    \ 2 * dis[query(u, v)];\n\t}\n};"
  dependsOn:
  - base.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/lca.hpp
  requiredBy:
  - graph/all.hpp
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lca.hpp
layout: document
redirect_from:
- /library/graph/lca.hpp
- /library/graph/lca.hpp.html
title: LCA
---
