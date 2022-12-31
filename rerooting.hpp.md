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
    document_title: "\u5168\u65B9\u4F4D\u6728DP"
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
    template<class T = ll>\nusing Graph = vector<Edges<T>>;\n#line 3 \"rerooting.hpp\"\
    \n/// @brief \u5168\u65B9\u4F4D\u6728DP\n/// @tparam Data DP\u30C6\u30FC\u30D6\
    \u30EB\u306E\u8981\u7D20\u306E\u578B\n/// @tparam Cost \u30B0\u30E9\u30D5\u306E\
    \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B\ntemplate<typename Data, typename Cost\
    \ = ll>\nstruct Rerooting {\n\tvector<Data> dp, memo;\n\tGraph<> G;\n\tint N =\
    \ -1;\n\tusing F1 = function<Data(Data, Data)>;\n\tusing F2 = function<Data(Data,\
    \ Edge<Cost>)>;\n\tF1 merge;\n\tF2 apply;\n\tData e, leaf;\n\t/// @brief \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\t/// @param n \u9802\u70B9\u6570\n\t///\
    \ @param merge \u30E2\u30CE\u30A4\u30C9\u306E\u5408\u6210\u95A2\u6570\n\t/// @param\
    \ apply \u90E8\u5206\u6728\u306E\u5BC4\u4E0E\u3092\u6C42\u3081\u308B\u95A2\u6570\
    \n\t/// @param e \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n\t/// @param\
    \ leaf \u8449\u306E\u30E2\u30CE\u30A4\u30C9\n\tRerooting(int n, F1 merge, F2 apply,\
    \ Data e, Data leaf)\n\t\t: N(n),\n\t\t  merge(merge),\n\t\t  apply(apply),\n\t\
    \t  e(e),\n\t\t  leaf(leaf) {\n\t\tG = Graph<Cost>(n);\n\t}\n\n\t/// @brief \u8FBA\
    \u3092\u8FFD\u52A0\u3059\u308B\n\t/// @param e \u8FFD\u52A0\u3059\u308B\u8FBA\n\
    \tvoid add_edge(Edge<Cost> e) {\n\t\tassert(0 <= e.from && e.from < N && 0 <=\
    \ e.to\n\t\t\t   && e.to < N);\n\t\tG[e.from].push_back(e);\n\t}\n\n\t/// @brief\
    \ \u5168\u65B9\u4F4D\u6728DP\u3092\u884C\u3046\n\t/// @return \u5168\u65B9\u4F4D\
    \u6728DP\u306E\u7D50\u679C\n\tvector<Data> build() {\n\t\tmemo = vector<Data>(SZ(G),\
    \ e);\n\t\tdp = vector<Data>(SZ(G));\n\t\tdfs1(0);\n\t\tdfs2(0, e);\n\t\treturn\
    \ dp;\n\t}\n\nprivate:\n\tvoid dfs1(int cur, int pre = -1) {\n\t\tbool isLeaf\
    \ = true;\n\t\tfor(Edge<Cost> edge: G[cur]) {\n\t\t\tif(edge.to == pre) continue;\n\
    \t\t\tdfs1(edge.to, cur);\n\t\t\tisLeaf = false;\n\t\t\tmemo[cur] = merge(\n\t\
    \t\t\tmemo[cur],\n\t\t\t\tapply(memo[edge.to],\n\t\t\t\t\t  Edge(edge.to, cur,\
    \ edge.cost)));\n\t\t}\n\t\tif(isLeaf) memo[cur] = leaf;\n\t}\n\n\tvoid dfs2(int\
    \ cur, const Data val, int pre = -1) {\n\t\t// ds\u306Fcur\u304B\u3089\u884C\u304F\
    \u3053\u3068\u304C\u3067\u304D\u308B\u5168\u3066\u306E\u9802\u70B9\u306B\u3064\
    \u3044\u3066\n\t\t// \u305D\u306E\u9802\u70B9\u3092\u6839\u3068\u3057\u305F\u90E8\
    \u5206\u6728\u306E\u5BC4\u4E0E\u3092\u914D\u5217\u306B\u3057\u305F\u3082\u306E\
    \n\t\t// \u4E00\u756A\u6700\u521D\u304C\u89AA\u304B\u3089\u306E\u5BC4\u4E0E\u3001\
    \u305D\u306E\u3042\u3068\u306B\u5B50\u304B\u3089\u306E\u5BC4\u4E0E\n\t\tvector<Data>\
    \ ds { val };\n\t\tfor(Edge<Cost> edge: G[cur]) {\n\t\t\tif(edge.to == pre) continue;\n\
    \t\t\tds.push_back(\n\t\t\t\tapply(memo[edge.to],\n\t\t\t\t\t  Edge<Cost>(edge.to,\
    \ cur, edge.cost)));\n\t\t}\n\t\tint N = SZ(ds);\n\t\tvector<Data> dp_left(N +\
    \ 1, e), dp_right(N + 1, e);\n\t\t// dp_left[i] => ds\u306E[0,i)\u306E\u5BC4\u4E0E\
    \u306E\u7DCF\u548C\n\t\tREP(i, N) dp_left[i + 1] = merge(dp_left[i], ds[i]);\n\
    \t\t// dp_right[i] => ds\u306E[i,N)\u306E\u5BC4\u4E0E\u306E\u7DCF\u548C\n\t\t\
    REPR(i, N)\n\t\tdp_right[i] = merge(dp_right[i + 1], ds[i]);\n\t\t// cur\u3092\
    \u6839\u3068\u3059\u308B\u5834\u5408\u306E\u7B54\u3048\u306Fds\u306E[0,N)\u306E\
    \u5BC4\u4E0E\u306E\u7DCF\u548C\n\t\tdp[cur] = dp_left[N];\n\t\tint ind = 1;  //\
    \ \u89AA\u4EE5\u5916\u306E\u9802\u70B9\u306B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \u3092\u3064\u3051\u308B\n\t\tfor(Edge<Cost> edge: G[cur]) {\n\t\t\tif(edge.to\
    \ == pre) continue;\n\t\t\t// edge.to\u4EE5\u5916\u306Ecur\u306B\u3064\u306A\u304C\
    \u308B\u9802\u70B9\u3092\u9802\u70B9\u3068\u3057\u305F\u90E8\u5206\u6728\u306E\
    \u5BC4\u4E0E\u306E\u7DCF\u548C\n\t\t\tData sub\n\t\t\t\t= merge(dp_left[ind],\
    \ dp_right[ind + 1]);\n\t\t\tdfs2(edge.to,\n\t\t\t\t apply(sub,\n\t\t\t\t\t  \
    \ Edge<Cost>(cur, edge.to, edge.cost)),\n\t\t\t\t cur);\n\t\t\tind++;\n\t\t}\n\
    \t}\n};\n"
  code: "#include \"./base.hpp\"\n#include \"./graph/base.hpp\"\n/// @brief \u5168\
    \u65B9\u4F4D\u6728DP\n/// @tparam Data DP\u30C6\u30FC\u30D6\u30EB\u306E\u8981\u7D20\
    \u306E\u578B\n/// @tparam Cost \u30B0\u30E9\u30D5\u306E\u8FBA\u306E\u30B3\u30B9\
    \u30C8\u306E\u578B\ntemplate<typename Data, typename Cost = ll>\nstruct Rerooting\
    \ {\n\tvector<Data> dp, memo;\n\tGraph<> G;\n\tint N = -1;\n\tusing F1 = function<Data(Data,\
    \ Data)>;\n\tusing F2 = function<Data(Data, Edge<Cost>)>;\n\tF1 merge;\n\tF2 apply;\n\
    \tData e, leaf;\n\t/// @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\t///\
    \ @param n \u9802\u70B9\u6570\n\t/// @param merge \u30E2\u30CE\u30A4\u30C9\u306E\
    \u5408\u6210\u95A2\u6570\n\t/// @param apply \u90E8\u5206\u6728\u306E\u5BC4\u4E0E\
    \u3092\u6C42\u3081\u308B\u95A2\u6570\n\t/// @param e \u30E2\u30CE\u30A4\u30C9\u306E\
    \u5358\u4F4D\u5143\n\t/// @param leaf \u8449\u306E\u30E2\u30CE\u30A4\u30C9\n\t\
    Rerooting(int n, F1 merge, F2 apply, Data e, Data leaf)\n\t\t: N(n),\n\t\t  merge(merge),\n\
    \t\t  apply(apply),\n\t\t  e(e),\n\t\t  leaf(leaf) {\n\t\tG = Graph<Cost>(n);\n\
    \t}\n\n\t/// @brief \u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n\t/// @param e \u8FFD\
    \u52A0\u3059\u308B\u8FBA\n\tvoid add_edge(Edge<Cost> e) {\n\t\tassert(0 <= e.from\
    \ && e.from < N && 0 <= e.to\n\t\t\t   && e.to < N);\n\t\tG[e.from].push_back(e);\n\
    \t}\n\n\t/// @brief \u5168\u65B9\u4F4D\u6728DP\u3092\u884C\u3046\n\t/// @return\
    \ \u5168\u65B9\u4F4D\u6728DP\u306E\u7D50\u679C\n\tvector<Data> build() {\n\t\t\
    memo = vector<Data>(SZ(G), e);\n\t\tdp = vector<Data>(SZ(G));\n\t\tdfs1(0);\n\t\
    \tdfs2(0, e);\n\t\treturn dp;\n\t}\n\nprivate:\n\tvoid dfs1(int cur, int pre =\
    \ -1) {\n\t\tbool isLeaf = true;\n\t\tfor(Edge<Cost> edge: G[cur]) {\n\t\t\tif(edge.to\
    \ == pre) continue;\n\t\t\tdfs1(edge.to, cur);\n\t\t\tisLeaf = false;\n\t\t\t\
    memo[cur] = merge(\n\t\t\t\tmemo[cur],\n\t\t\t\tapply(memo[edge.to],\n\t\t\t\t\
    \t  Edge(edge.to, cur, edge.cost)));\n\t\t}\n\t\tif(isLeaf) memo[cur] = leaf;\n\
    \t}\n\n\tvoid dfs2(int cur, const Data val, int pre = -1) {\n\t\t// ds\u306Fcur\u304B\
    \u3089\u884C\u304F\u3053\u3068\u304C\u3067\u304D\u308B\u5168\u3066\u306E\u9802\
    \u70B9\u306B\u3064\u3044\u3066\n\t\t// \u305D\u306E\u9802\u70B9\u3092\u6839\u3068\
    \u3057\u305F\u90E8\u5206\u6728\u306E\u5BC4\u4E0E\u3092\u914D\u5217\u306B\u3057\
    \u305F\u3082\u306E\n\t\t// \u4E00\u756A\u6700\u521D\u304C\u89AA\u304B\u3089\u306E\
    \u5BC4\u4E0E\u3001\u305D\u306E\u3042\u3068\u306B\u5B50\u304B\u3089\u306E\u5BC4\
    \u4E0E\n\t\tvector<Data> ds { val };\n\t\tfor(Edge<Cost> edge: G[cur]) {\n\t\t\
    \tif(edge.to == pre) continue;\n\t\t\tds.push_back(\n\t\t\t\tapply(memo[edge.to],\n\
    \t\t\t\t\t  Edge<Cost>(edge.to, cur, edge.cost)));\n\t\t}\n\t\tint N = SZ(ds);\n\
    \t\tvector<Data> dp_left(N + 1, e), dp_right(N + 1, e);\n\t\t// dp_left[i] =>\
    \ ds\u306E[0,i)\u306E\u5BC4\u4E0E\u306E\u7DCF\u548C\n\t\tREP(i, N) dp_left[i +\
    \ 1] = merge(dp_left[i], ds[i]);\n\t\t// dp_right[i] => ds\u306E[i,N)\u306E\u5BC4\
    \u4E0E\u306E\u7DCF\u548C\n\t\tREPR(i, N)\n\t\tdp_right[i] = merge(dp_right[i +\
    \ 1], ds[i]);\n\t\t// cur\u3092\u6839\u3068\u3059\u308B\u5834\u5408\u306E\u7B54\
    \u3048\u306Fds\u306E[0,N)\u306E\u5BC4\u4E0E\u306E\u7DCF\u548C\n\t\tdp[cur] = dp_left[N];\n\
    \t\tint ind = 1;  // \u89AA\u4EE5\u5916\u306E\u9802\u70B9\u306B\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\u3092\u3064\u3051\u308B\n\t\tfor(Edge<Cost> edge: G[cur]) {\n\
    \t\t\tif(edge.to == pre) continue;\n\t\t\t// edge.to\u4EE5\u5916\u306Ecur\u306B\
    \u3064\u306A\u304C\u308B\u9802\u70B9\u3092\u9802\u70B9\u3068\u3057\u305F\u90E8\
    \u5206\u6728\u306E\u5BC4\u4E0E\u306E\u7DCF\u548C\n\t\t\tData sub\n\t\t\t\t= merge(dp_left[ind],\
    \ dp_right[ind + 1]);\n\t\t\tdfs2(edge.to,\n\t\t\t\t apply(sub,\n\t\t\t\t\t  \
    \ Edge<Cost>(cur, edge.to, edge.cost)),\n\t\t\t\t cur);\n\t\t\tind++;\n\t\t}\n\
    \t}\n};"
  dependsOn:
  - base.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: rerooting.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: rerooting.hpp
layout: document
redirect_from:
- /library/rerooting.hpp
- /library/rerooting.hpp.html
title: "\u5168\u65B9\u4F4D\u6728DP"
---
