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
    document_title: "\u9589\u8DEF\u691C\u51FA"
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
    template<class T = ll>\nusing Graph = vector<Edges<T>>;\n#line 3 \"graph/cycle_detection.hpp\"\
    \n/// @brief \u9589\u8DEF\u691C\u51FA\n\nvi cycle_detection(Graph<>& G) {\n\t\
    int N = SZ(G);\n\tvi cycle;\n\tvb visited(N);\n\tvb seen(N);\n\tauto dfs = [&](auto\
    \ f, int cur, int pre = -1) -> int {\n\t\tif(seen[cur]) {\n\t\t\treturn cur;\n\
    \t\t}\n\t\tseen[cur] = true;\n\t\tfor(Edge e: G[cur]) {\n\t\t\tif(e.to == pre)\
    \ continue;\n\t\t\tif(visited[e.to]) continue;\n\t\t\tint begin = f(f, e.to, cur);\n\
    \t\t\tif(begin == -2) {\n\t\t\t\tvisited[cur] = true;\n\t\t\t\treturn -2;\n\t\t\
    \t}\n\t\t\tif(begin == -1) continue;\n\t\t\tif(begin == cur) {\n\t\t\t\tcycle.push_back(cur);\n\
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
    \treturn ret;\n}\n"
  code: "#include \"../base.hpp\"\n#include \"./base.hpp\"\n/// @brief \u9589\u8DEF\
    \u691C\u51FA\n\nvi cycle_detection(Graph<>& G) {\n\tint N = SZ(G);\n\tvi cycle;\n\
    \tvb visited(N);\n\tvb seen(N);\n\tauto dfs = [&](auto f, int cur, int pre = -1)\
    \ -> int {\n\t\tif(seen[cur]) {\n\t\t\treturn cur;\n\t\t}\n\t\tseen[cur] = true;\n\
    \t\tfor(Edge e: G[cur]) {\n\t\t\tif(e.to == pre) continue;\n\t\t\tif(visited[e.to])\
    \ continue;\n\t\t\tint begin = f(f, e.to, cur);\n\t\t\tif(begin == -2) {\n\t\t\
    \t\tvisited[cur] = true;\n\t\t\t\treturn -2;\n\t\t\t}\n\t\t\tif(begin == -1) continue;\n\
    \t\t\tif(begin == cur) {\n\t\t\t\tcycle.push_back(cur);\n\t\t\t\tvisited[cur]\
    \ = true;\n\t\t\t\treturn -2;\n\t\t\t}\n\t\t\tcycle.push_back(cur);\n\t\t\tvisited[cur]\
    \ = true;\n\t\t\treturn begin;\n\t\t}\n\t\tvisited[cur] = true;\n\t\treturn -1;\n\
    \t};\n\tREP(i, N) {\n\t\tif(!cycle.empty()) break;\n\t\tif(visited[i]) continue;\n\
    \t\tdfs(dfs, i);\n\t}\n\tif(cycle.empty()) {\n\t\treturn vi();\n\t}\n\trev(cycle);\n\
    \tvi C(N, -1);\n\tREP(i, SZ(cycle)) {\n\t\tC[cycle[i]] = i;\n\t}\n\tint ind =\
    \ 0;\n\tvi ret;\n\tusing P = pair<int, int>;\n\tset<P> S;\n\twhile(ind != -1)\
    \ {\n\t\tint v = cycle[ind];\n\t\tret.push_back(v);\n\t\tS.insert({ ind, SZ(ret)\
    \ - 1 });\n\t\tint next = -1;\n\t\tint pre = -1;\n\t\tfor(Edge e: G[v]) {\n\t\t\
    \tint n = C[e.to];\n\t\t\tif(n == -1) continue;\n\t\t\tif(n < ind) {\n\t\t\t\t\
    auto [a, b] = *S.lower_bound({ n, 0 });\n\t\t\t\tif(a != n) continue;\n\t\t\t\t\
    chmax(pre, b);\n\t\t\t}\n\t\t\tchmax(next, n);\n\t\t}\n\t\tif(pre != -1) {\n\t\
    \t\tvi new_ret;\n\t\t\tFOR(i, pre, SZ(ret)) {\n\t\t\t\tnew_ret.push_back(ret[i]);\n\
    \t\t\t}\n\t\t\tret = new_ret;\n\t\t\treturn ret;\n\t\t}\n\t\tind = next;\n\t}\n\
    \treturn ret;\n}"
  dependsOn:
  - base.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/cycle_detection.hpp
  requiredBy:
  - graph/all.hpp
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/cycle_detection.hpp
layout: document
redirect_from:
- /library/graph/cycle_detection.hpp
- /library/graph/cycle_detection.hpp.html
title: "\u9589\u8DEF\u691C\u51FA"
---
