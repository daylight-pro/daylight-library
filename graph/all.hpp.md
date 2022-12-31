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
  - icon: ':warning:'
    path: graph/bellman_ford.hpp
    title: "\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5"
  - icon: ':warning:'
    path: graph/cycle_detection.hpp
    title: "\u9589\u8DEF\u691C\u51FA"
  - icon: ':warning:'
    path: graph/diameter.hpp
    title: "\u6728\u306E\u76F4\u5F84"
  - icon: ':warning:'
    path: graph/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  - icon: ':warning:'
    path: graph/floyd.hpp
    title: "\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5"
  - icon: ':warning:'
    path: graph/kruskal.hpp
    title: "\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5"
  - icon: ':warning:'
    path: graph/lca.hpp
    title: LCA
  _extendedRequiredBy: []
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
    \ return true;\n\t}\n}\n#line 3 \"graph/cycle_detection.hpp\"\n/// @brief \u9589\
    \u8DEF\u691C\u51FA\n\nvi cycle_detection(Graph<>& G) {\n\tint N = SZ(G);\n\tvi\
    \ cycle;\n\tvb visited(N);\n\tvb seen(N);\n\tauto dfs = [&](auto f, int cur, int\
    \ pre = -1) -> int {\n\t\tif(seen[cur]) {\n\t\t\treturn cur;\n\t\t}\n\t\tseen[cur]\
    \ = true;\n\t\tfor(Edge e: G[cur]) {\n\t\t\tif(e.to == pre) continue;\n\t\t\t\
    if(visited[e.to]) continue;\n\t\t\tint begin = f(f, e.to, cur);\n\t\t\tif(begin\
    \ == -2) {\n\t\t\t\tvisited[cur] = true;\n\t\t\t\treturn -2;\n\t\t\t}\n\t\t\t\
    if(begin == -1) continue;\n\t\t\tif(begin == cur) {\n\t\t\t\tcycle.push_back(cur);\n\
    \t\t\t\tvisited[cur] = true;\n\t\t\t\treturn -2;\n\t\t\t}\n\t\t\tcycle.push_back(cur);\n\
    \t\t\tvisited[cur] = true;\n\t\t\treturn begin;\n\t\t}\n\t\tvisited[cur] = true;\n\
    \t\treturn -1;\n\t};\n\tREP(i, N) {\n\t\tif(!cycle.empty()) break;\n\t\tif(visited[i])\
    \ continue;\n\t\tdfs(dfs, i);\n\t}\n\tif(cycle.empty()) {\n\t\treturn vi();\n\t\
    }\n\trev(cycle);\n\tvi C(N, -1);\n\tREP(i, SZ(cycle)) {\n\t\tC[cycle[i]] = i;\n\
    \t}\n\tint ind = 0;\n\tvi ret;\n\tusing P = pair<int, int>;\n\tset<P> S;\n\twhile(ind\
    \ != -1) {\n\t\tint v = cycle[ind];\n\t\tret.push_back(v);\n\t\tS.insert({ ind,\
    \ SZ(ret) - 1 });\n\t\tint next = -1;\n\t\tint pre = -1;\n\t\tfor(Edge e: G[v])\
    \ {\n\t\t\tint n = C[e.to];\n\t\t\tif(n == -1) continue;\n\t\t\tif(n < ind) {\n\
    \t\t\t\tauto [a, b] = *S.lower_bound({ n, 0 });\n\t\t\t\tif(a != n) continue;\n\
    \t\t\t\tchmax(pre, b);\n\t\t\t}\n\t\t\tchmax(next, n);\n\t\t}\n\t\tif(pre != -1)\
    \ {\n\t\t\tvi new_ret;\n\t\t\tFOR(i, pre, SZ(ret)) {\n\t\t\t\tnew_ret.push_back(ret[i]);\n\
    \t\t\t}\n\t\t\tret = new_ret;\n\t\t\treturn ret;\n\t\t}\n\t\tind = next;\n\t}\n\
    \treturn ret;\n}\n#line 3 \"graph/diameter.hpp\"\n/// @brief \u6728\u306E\u76F4\
    \u5F84\n\nnamespace inner_diameter {\nusing P = pair<int, int>;\nP dfs(int cur,\
    \ int pre, Graph<> &G) {\n\tP p({ 0, cur });\n\tfor(Edge e: G[cur]) {\n\t\tif(e.to\
    \ == pre) continue;\n\t\tauto [dis, v] = dfs(e.to, cur, G);\n\t\tchmax(p, P(dis\
    \ + 1, v));\n\t}\n\treturn p;\n}\n}\n\nint get_diameter(Graph<> &G) {\n\tauto\
    \ [dis, v] = inner_diameter::dfs(0, -1, G);\n\tauto [dis2, v2] = inner_diameter::dfs(v,\
    \ -1, G);\n\treturn dis2;\n}\n#line 3 \"graph/dijkstra.hpp\"\n/// @brief \u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n\n/// @brief \u5358\u4E00\u59CB\u70B9\u6700\
    \u77ED\u7D4C\u8DEF\u9577\u554F\u984C\u3092\u89E3\u304F\n/// @param s \u59CB\u70B9\
    \n/// @param G \u30B0\u30E9\u30D5\n/// @return ret[i]:s\u304B\u3089i\u3078\u306E\
    \u6700\u77ED\u7D4C\u8DEF\u9577\nvll dijkstra(int s, Graph<ll>& G) {\n\tusing P\
    \ = pair<ll, int>;\n\tpriority_queue<P, vector<P>, greater<>> que;\n\tvll D(SZ(G),\
    \ LINF);\n\tD[s] = 0;\n\tque.push(P(0, s));\n\twhile(!que.empty()) {\n\t\tP p\
    \ = que.top();\n\t\tque.pop();\n\t\tint v = p.second;\n\t\tif(D[v] < p.first)\
    \ continue;\n\t\tfor(Edge e: G[v]) {\n\t\t\tif(D[e.to] > D[v] + e.cost) {\n\t\t\
    \t\tD[e.to] = D[v] + e.cost;\n\t\t\t\tque.push(P(D[e.to], e.to));\n\t\t\t}\n\t\
    \t}\n\t}\n\treturn D;\n}\n#line 2 \"graph/floyd.hpp\"\n/// @brief \u30EF\u30FC\
    \u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\n\n/// @brief \u5168\u70B9\u5BFE\
    \u6700\u77ED\u7D4C\u8DEF\u9577\u554F\u984C\u3092\u89E3\u304F\n/// @param n \u9802\
    \u70B9\u6570\n/// @param WF \u96A3\u63A5\u884C\u5217(out:\u6700\u77ED\u7D4C\u8DEF\
    \u9577)\nvoid floyd(int n, vector<vll>& WF) {\n\tREP(k, n)\n\tREP(i, n) {\n\t\t\
    if(WF[i][k] == LINF) continue;\n\t\tREP(j, n) {\n\t\t\tif(WF[k][j] == LINF) continue;\n\
    \t\t\tchmin(WF[i][j], WF[i][k] + WF[k][j]);\n\t\t}\n\t}\n}\n#line 1 \"atcoder/all\"\
    \n#include <atcoder/convolution>\n#include <atcoder/dsu>\n#include <atcoder/fenwicktree>\n\
    #include <atcoder/lazysegtree>\n#include <atcoder/math>\n#include <atcoder/maxflow>\n\
    #include <atcoder/mincostflow>\n#include <atcoder/modint>\n#include <atcoder/scc>\n\
    #include <atcoder/segtree>\n#include <atcoder/string>\n#include <atcoder/twosat>\n\
    #line 4 \"graph/kruskal.hpp\"\nusing namespace atcoder;\n/// @brief \u30AF\u30E9\
    \u30B9\u30AB\u30EB\u6CD5\n\n/// @brief \u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\
    \u30B9\u30C8\u3092\u6C42\u3081\u308B\n/// @param V \u9802\u70B9\u6570\n/// @param\
    \ ES \u8FBA\u96C6\u5408\n/// @return \u30B0\u30E9\u30D5\u304C\u9023\u7D50\u3067\
    \u306A\u3051\u308C\u3070LINF,\u9023\u7D50\u306A\u3089\u3070\u6700\u5C0F\u5168\u57DF\
    \u6728\u306E\u30B3\u30B9\u30C8\nll kruskal(int V, Edges<>& ES) {\n\tsort(ALL(ES),\
    \ [](Edge<> const& a, Edge<> const& b) {\n\t\tif(a.cost != b.cost) return a.cost\
    \ < b.cost;\n\t\tif(a.from != b.from) return a.from < b.from;\n\t\treturn a.to\
    \ < b.to;\n\t});\n\tll ret = 0;\n\tdsu d(V);\n\tREP(i, SZ(ES)) {\n\t\tEdge e =\
    \ ES[i];\n\t\tif(!d.same(e.from, e.to)) {\n\t\t\tret += e.cost;\n\t\t\td.merge(e.from,\
    \ e.to);\n\t\t}\n\t}\n\tif(d.size(0) != V) {\n\t\treturn LINF;\n\t}\n\treturn\
    \ ret;\n}\n#line 3 \"graph/lca.hpp\"\n/// @brief LCA\nstruct LCA {\nprivate:\n\
    \tvvi parent;\n\tvi dis;\n\tvoid dfs(int cur, int pre, const Graph<>& G, int d)\
    \ {\n\t\tparent[0][cur] = pre;\n\t\tdis[cur] = d;\n\t\tfor(auto e: G[cur]) {\n\
    \t\t\tif(e.to == pre) continue;\n\t\t\tdfs(e.to, cur, G, d + e.cost);\n\t\t}\n\
    \t}\n\npublic:\n\tLCA(const Graph<>& G) {\n\t\tint N = SZ(G);\n\t\tint K = 1;\n\
    \t\twhile((1 << K) < N) K++;\n\t\tparent = vvi(K, vi(N, -1));\n\t\tdis = vi(N,\
    \ -1);\n\t\tdfs(0, -1, G, 0);\n\t\tREP(i, K - 1) {\n\t\t\tREP(j, N) {\n\t\t\t\t\
    if(parent[i][j] < 0) {\n\t\t\t\t\tparent[i + 1][j] = -1;\n\t\t\t\t} else {\n\t\
    \t\t\t\tparent[i + 1][j]\n\t\t\t\t\t\t= parent[i][parent[i][j]];\n\t\t\t\t}\n\t\
    \t\t}\n\t\t}\n\t}\n\tint query(int u, int v, int root) {\n\t\treturn query(u,\
    \ v) ^ query(v, root)\n\t\t\t^ query(u, root);\n\t}\n\tint query(int u, int v)\
    \ {\n\t\tassert(u >= 0 && v >= 0 && u < SZ(dis)\n\t\t\t   && v < SZ(dis) && \"\
    invalid vertex index\");\n\t\tif(dis[u] < dis[v]) swap(u, v);\n\t\tint K = SZ(parent);\n\
    \t\tREP(i, K) {\n\t\t\tif((dis[u] - dis[v]) >> i & 1) {\n\t\t\t\tu = parent[i][u];\n\
    \t\t\t}\n\t\t}\n\t\tif(u == v) return u;\n\t\tREPR(i, K) {\n\t\t\tif(parent[i][u]\
    \ != parent[i][v]) {\n\t\t\t\tu = parent[i][u];\n\t\t\t\tv = parent[i][v];\n\t\
    \t\t}\n\t\t}\n\t\treturn parent[0][u];\n\t}\n\n\tint get_dis(int u, int v) {\n\
    \t\tassert(u >= 0 && v >= 0 && u < SZ(dis)\n\t\t\t   && v < SZ(dis) && \"invalid\
    \ vertex index\");\n\t\treturn dis[u] + dis[v] - 2 * dis[query(u, v)];\n\t}\n\
    };\n#line 9 \"graph/all.hpp\"\n"
  code: '#include "./base.hpp"

    #include "./bellman_ford.hpp"

    #include "./cycle_detection.hpp"

    #include "./diameter.hpp"

    #include "./dijkstra.hpp"

    #include "./floyd.hpp"

    #include "./kruskal.hpp"

    #include "./lca.hpp"'
  dependsOn:
  - graph/base.hpp
  - base.hpp
  - graph/bellman_ford.hpp
  - graph/cycle_detection.hpp
  - graph/diameter.hpp
  - graph/dijkstra.hpp
  - graph/floyd.hpp
  - graph/kruskal.hpp
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
  - graph/lca.hpp
  isVerificationFile: false
  path: graph/all.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/all.hpp
layout: document
redirect_from:
- /library/graph/all.hpp
- /library/graph/all.hpp.html
title: graph/all.hpp
---
