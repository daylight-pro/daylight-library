---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base.hpp
    title: base.hpp
  - icon: ':warning:'
    path: structure/abel.hpp
    title: structure/abel.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u9802\u70B9x\u3068\u9802\u70B9y\u304C\u9023\u7D50\u304B\u5224\
      \u5B9A\u3059\u308B"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"structure/abel.hpp\"\
    \ntemplate<typename T>\nstruct AbelAdd {\n\tusing value_type = T;\n\tstatic constexpr\
    \ T op(const T& a, const T& b) noexcept {\n\t\treturn a + b;\n\t}\n\tstatic constexpr\
    \ T inv(const T& a) noexcept {\n\t\treturn -a;\n\t}\n\tstatic constexpr T e()\
    \ {\n\t\treturn T(0);\n\t}\n};\ntemplate<typename T>\nstruct AbelXor {\n\tusing\
    \ value_type = T;\n\tstatic constexpr T op(const T& a, const T& b) noexcept {\n\
    \t\treturn a ^ b;\n\t}\n\tstatic constexpr T inv(const T& a) noexcept {\n\t\t\
    return a;\n\t}\n\tstatic constexpr T e() {\n\t\treturn T(0);\n\t}\n};\n#line 3\
    \ \"structure/potential_uf.hpp\"\ntemplate<typename Abel = AbelAdd<ll>>\nclass\
    \ potential_uf {\npublic:\n\tusing T = typename Abel::value_type;\n\tint treeCnt;\
    \  //\u30C4\u30EA\u30FC\u306E\u6570\n\tvi p;  //p => \u89AA\n\tvi num;\t //\u6728\
    \u306E\u8981\u7D20\u6570\n\tvi rank;\n\tvector<T> potential;\n\tint N;\n\tpotential_uf()\
    \ {\n\t}\n\tpotential_uf(int size) {\n\t\tN = size;\n\t\tp.resize(N, 0);\n\t\t\
    num.resize(N, 1);\n\t\trank.resize(N, 0);\n\t\tpotential.resize(N, Abel::e());\n\
    \t\ttreeCnt = N;\n\t\tREP(i, N) {\n\t\t\tp[i] = i;\n\t\t}\n\t}\n\n\t/// @brief\
    \ \u9802\u70B9x\u3068\u9802\u70B9y\u304C\u9023\u7D50\u304B\u5224\u5B9A\u3059\u308B\
    \n\t/// @param x \u4E00\u3064\u76EE\u306E\u9802\u70B9(0-indexed)\n\t/// @param\
    \ y \u4E8C\u3064\u76EE\u306E\u9802\u70B9(0-indexed)\n\t/// @return \u9023\u7D50\
    \u306A\u3089true\n\tbool same(int x, int y) {\n\t\treturn leader(x) == leader(y);\n\
    \t}\n\n\t/// @brief w[y] - w[x] = w\u3068\u306A\u308B\u3088\u3046\u306Bx\u3068\
    y\u3092\u63A5\u7D9A\u3059\u308B\n\t/// @param x \u89AA\u306E\u9802\u70B9\n\t///\
    \ @param y \u5B50\u306E\u9802\u70B9\n\t/// @param w \u30DD\u30C6\u30F3\u30B7\u30E3\
    \u30EB\u306E\u5DEE\n\tvoid merge(int x, int y, T w) {\n\t\tw = Abel::op(w, get_potential(x));\n\
    \t\tw = Abel::op(w, Abel::inv(get_potential(y)));\n\t\tlink(leader(x), leader(y),\
    \ w);\n\t}\n\nprivate:\n\tvoid link(int x, int y, T w) {\n\t\tif(x == y) return;\n\
    \t\tif(rank[x] < rank[y]) swap(x, y), w = Abel::inv(w);\n\t\t// x\u304C\u65B0\u305F\
    \u306A\u89AA\u306B\u306A\u308B\u3088\u3046\u306By\u3092\u63A5\u7D9A\n\t\tp[y]\
    \ = x;\n\t\tnum[x] += num[y];\n\t\tif(rank[x] == rank[y]) rank[x]++;\n\t\ttreeCnt--;\n\
    \t\tpotential[y] = w;\n\t}\n\npublic:\n\t/// @brief x\u304C\u5C5E\u3057\u3066\u3044\
    \u308B\u6728\u306E\u6839\u3092\u53D6\u5F97\n\t/// @param x \u9802\u70B9\u756A\u53F7\
    (0-indexed)\n\t/// @return x\u304C\u5C5E\u3057\u3066\u3044\u308B\u6728\u306E\u6839\
    \u306E\u9802\u70B9\u756A\u53F7\n\tint leader(int x) {\n\t\tif(p[x] == x)\n\t\t\
    \treturn x;\n\t\telse {\n\t\t\tint l = leader(p[x]);\n\t\t\tpotential[x]\n\t\t\
    \t\t= Abel::op(potential[x], potential[p[x]]);\n\t\t\treturn p[x] = l;\n\t\t}\n\
    \t}\n\n\t/// @brief \u9802\u70B9x\u306E\u6839\u304B\u3089\u306E\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u3092\u6C42\u3081\u308B\n\t/// @param x \u9802\u70B9\u756A\u53F7\
    (0-indexed)\n\t/// @return \u9802\u70B9x\u306E\u6839\u304B\u3089\u306E\u91CD\u307F\
    \n\tint get_potential(int x) {\n\t\tleader(x);\n\t\treturn potential[x];\n\t}\n\
    \n\t/// @brief w[y]-w[x]\u3092\u8FD4\u3059\u3002\n\t/// @param x \u89AA\u306E\u9802\
    \u70B9(0-indexed)\n\t/// @param y \u5B50\u306E\u9802\u70B9(0-indexed)\n\t/// @return\
    \ \u91CD\u307F\u306E\u5DEE\n\tint diff(int x, int y) {\n\t\treturn Abel::op(get_potential(y),\n\
    \t\t\t\t\t\tAbel::inv(get_potential(x)));\n\t}\n\n\t/// @brief \u9023\u7D50\u6210\
    \u5206\u306E\u500B\u6570\u3092\u8FD4\u3059\n\t/// @return \u9023\u7D50\u6210\u5206\
    \u306E\u500B\u6570\n\tint countTree() {\n\t\treturn treeCnt;\n\t}\n\n\t/// @brief\
    \ \u9802\u70B9a\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u8981\u7D20\
    \u6570\u3092\u6C42\u3081\u308B\n\t/// @param a \u9802\u70B9\u756A\u53F7(0-indexed)\n\
    \t/// @return \u9802\u70B9a\u3068\u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u5C5E\
    \u3059\u308B\u8981\u7D20\u6570\n\tint size(int a) {\n\t\treturn num[leader(a)];\n\
    \t}\n\n\tvvi groups() {\n\t\tmap<int, vi> m;\n\t\tREP(i, N) {\n\t\t\tm[leader(i)].push_back(i);\n\
    \t\t}\n\t\tvvi ret;\n\t\tfor(auto [_, v]: m) {\n\t\t\tret.push_back(v);\n\t\t\
    }\n\t\treturn ret;\n\t}\n};\n"
  code: "#include \"../base.hpp\"\n#include \"./abel.hpp\"\ntemplate<typename Abel\
    \ = AbelAdd<ll>>\nclass potential_uf {\npublic:\n\tusing T = typename Abel::value_type;\n\
    \tint treeCnt;  //\u30C4\u30EA\u30FC\u306E\u6570\n\tvi p;  //p => \u89AA\n\tvi\
    \ num;\t //\u6728\u306E\u8981\u7D20\u6570\n\tvi rank;\n\tvector<T> potential;\n\
    \tint N;\n\tpotential_uf() {\n\t}\n\tpotential_uf(int size) {\n\t\tN = size;\n\
    \t\tp.resize(N, 0);\n\t\tnum.resize(N, 1);\n\t\trank.resize(N, 0);\n\t\tpotential.resize(N,\
    \ Abel::e());\n\t\ttreeCnt = N;\n\t\tREP(i, N) {\n\t\t\tp[i] = i;\n\t\t}\n\t}\n\
    \n\t/// @brief \u9802\u70B9x\u3068\u9802\u70B9y\u304C\u9023\u7D50\u304B\u5224\u5B9A\
    \u3059\u308B\n\t/// @param x \u4E00\u3064\u76EE\u306E\u9802\u70B9(0-indexed)\n\
    \t/// @param y \u4E8C\u3064\u76EE\u306E\u9802\u70B9(0-indexed)\n\t/// @return\
    \ \u9023\u7D50\u306A\u3089true\n\tbool same(int x, int y) {\n\t\treturn leader(x)\
    \ == leader(y);\n\t}\n\n\t/// @brief w[y] - w[x] = w\u3068\u306A\u308B\u3088\u3046\
    \u306Bx\u3068y\u3092\u63A5\u7D9A\u3059\u308B\n\t/// @param x \u89AA\u306E\u9802\
    \u70B9\n\t/// @param y \u5B50\u306E\u9802\u70B9\n\t/// @param w \u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u306E\u5DEE\n\tvoid merge(int x, int y, T w) {\n\t\tw = Abel::op(w,\
    \ get_potential(x));\n\t\tw = Abel::op(w, Abel::inv(get_potential(y)));\n\t\t\
    link(leader(x), leader(y), w);\n\t}\n\nprivate:\n\tvoid link(int x, int y, T w)\
    \ {\n\t\tif(x == y) return;\n\t\tif(rank[x] < rank[y]) swap(x, y), w = Abel::inv(w);\n\
    \t\t// x\u304C\u65B0\u305F\u306A\u89AA\u306B\u306A\u308B\u3088\u3046\u306By\u3092\
    \u63A5\u7D9A\n\t\tp[y] = x;\n\t\tnum[x] += num[y];\n\t\tif(rank[x] == rank[y])\
    \ rank[x]++;\n\t\ttreeCnt--;\n\t\tpotential[y] = w;\n\t}\n\npublic:\n\t/// @brief\
    \ x\u304C\u5C5E\u3057\u3066\u3044\u308B\u6728\u306E\u6839\u3092\u53D6\u5F97\n\t\
    /// @param x \u9802\u70B9\u756A\u53F7(0-indexed)\n\t/// @return x\u304C\u5C5E\u3057\
    \u3066\u3044\u308B\u6728\u306E\u6839\u306E\u9802\u70B9\u756A\u53F7\n\tint leader(int\
    \ x) {\n\t\tif(p[x] == x)\n\t\t\treturn x;\n\t\telse {\n\t\t\tint l = leader(p[x]);\n\
    \t\t\tpotential[x]\n\t\t\t\t= Abel::op(potential[x], potential[p[x]]);\n\t\t\t\
    return p[x] = l;\n\t\t}\n\t}\n\n\t/// @brief \u9802\u70B9x\u306E\u6839\u304B\u3089\
    \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u6C42\u3081\u308B\n\t/// @param\
    \ x \u9802\u70B9\u756A\u53F7(0-indexed)\n\t/// @return \u9802\u70B9x\u306E\u6839\
    \u304B\u3089\u306E\u91CD\u307F\n\tint get_potential(int x) {\n\t\tleader(x);\n\
    \t\treturn potential[x];\n\t}\n\n\t/// @brief w[y]-w[x]\u3092\u8FD4\u3059\u3002\
    \n\t/// @param x \u89AA\u306E\u9802\u70B9(0-indexed)\n\t/// @param y \u5B50\u306E\
    \u9802\u70B9(0-indexed)\n\t/// @return \u91CD\u307F\u306E\u5DEE\n\tint diff(int\
    \ x, int y) {\n\t\treturn Abel::op(get_potential(y),\n\t\t\t\t\t\tAbel::inv(get_potential(x)));\n\
    \t}\n\n\t/// @brief \u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092\u8FD4\u3059\
    \n\t/// @return \u9023\u7D50\u6210\u5206\u306E\u500B\u6570\n\tint countTree()\
    \ {\n\t\treturn treeCnt;\n\t}\n\n\t/// @brief \u9802\u70B9a\u304C\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u8981\u7D20\u6570\u3092\u6C42\u3081\u308B\n\t///\
    \ @param a \u9802\u70B9\u756A\u53F7(0-indexed)\n\t/// @return \u9802\u70B9a\u3068\
    \u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\u308B\u8981\u7D20\u6570\
    \n\tint size(int a) {\n\t\treturn num[leader(a)];\n\t}\n\n\tvvi groups() {\n\t\
    \tmap<int, vi> m;\n\t\tREP(i, N) {\n\t\t\tm[leader(i)].push_back(i);\n\t\t}\n\t\
    \tvvi ret;\n\t\tfor(auto [_, v]: m) {\n\t\t\tret.push_back(v);\n\t\t}\n\t\treturn\
    \ ret;\n\t}\n};"
  dependsOn:
  - base.hpp
  - structure/abel.hpp
  isVerificationFile: false
  path: structure/potential_uf.hpp
  requiredBy: []
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/potential_uf.hpp
layout: document
redirect_from:
- /library/structure/potential_uf.hpp
- /library/structure/potential_uf.hpp.html
title: "\u9802\u70B9x\u3068\u9802\u70B9y\u304C\u9023\u7D50\u304B\u5224\u5B9A\u3059\
  \u308B"
---
