---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30B5\u30A4\u30BAn\u3067\u8FBA\u304C\u306A\u3044UF\u3092\u751F\
      \u6210"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"structure/partial_persistent_uf.hpp\"\
    \n\nclass dsu {\nprivate:\n\tvi p;  //p => \u89AA\n\tvi time;\n\tvector<vector<PI>>\
    \ size;\n\tint N;\n\tint now;\n\npublic:\n\tdsu() {\n\t}\n\t/// @brief \u30B5\u30A4\
    \u30BAn\u3067\u8FBA\u304C\u306A\u3044UF\u3092\u751F\u6210\n\t/// @param sz \u9802\
    \u70B9\u6570\n\tdsu(int sz) {\n\t\tN = sz;\n\t\tnow = 0;\n\t\tp.resize(N, 1);\n\
    \t\ttime.resize(N, INF);\n\t\tsize.resize(N, vector<PI>(1, { 0, 1 }));\n\t}\n\n\
    \t/// @brief \u6642\u523Bt\u306E\u6642\u70B9\u3067x\u3068y\u304C\u540C\u3058\u9023\
    \u7D50\u6210\u5206\u306B\u5C5E\u3057\u3066\u3044\u308B\u304B\u5224\u5B9A\n\t///\
    \ @param x \u9802\u70B91\n\t/// @param y \u9802\u70B92\n\t/// @param t \u5224\u5B9A\
    \u3059\u308B\u6642\u9593\n\t/// @return \u540C\u4E00\u9023\u7D50\u6210\u5206\u306A\
    \u3089true\n\tbool same(int x, int y, int t) {\n\t\treturn leader(x, t) == leader(y,\
    \ t);\n\t}\n\n\t/// @brief \u6642\u523B\u30921\u9032\u3081\u3066x\u3068y\u3092\
    \u30DE\u30FC\u30B8\u3059\u308B\n\t/// @param x \u9802\u70B91\n\t/// @param y \u9802\
    \u70B92\n\t/// @return \u30DE\u30FC\u30B8\u5F8C\u306E\u6642\u523B\n\tint merge(int\
    \ x, int y) {\n\t\t++now;\n\t\tx = leader(x, now);\n\t\ty = leader(y, now);\n\t\
    \tif(x == y) return now;\n\t\tif(p[x] < p[y]) {\n\t\t\tswap(x, y);\n\t\t}\n\t\t\
    p[x] += p[y];\n\t\tsize[x].push_back({ now, p[x] });\n\t\tp[y] = x;\n\t\ttime[y]\
    \ = now;\n\t\treturn now;\n\t}\n\n\t/// @brief \u6642\u523Bt\u6642\u70B9\u3067\
    \u306Ex\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u30EA\u30FC\u30C0\
    \u30FC\u3092\u53D6\u5F97\n\t/// @param x \u9802\u70B9\n\t/// @param t \u6642\u523B\
    \n\t/// @return \u30EA\u30FC\u30C0\u30FC\u306E\u9802\u70B9\u756A\u53F7\n\tint\
    \ leader(int x, int t) {\n\t\tif(time[x] > t)\n\t\t\treturn x;\n\t\telse\n\t\t\
    \treturn leader(p[x], t);\n\t}\n\n\t/// @brief \u73FE\u5728\u306E\u6642\u523B\u3092\
    \u53D6\u5F97\u3059\u308B\n\t/// @return \u73FE\u5728\u306E\u6642\u523B\n\tint\
    \ get_time() {\n\t\treturn now;\n\t}\n\n\t/// @brief \u6642\u523Bt\u6642\u70B9\
    \u3067\u306Ex\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\
    \u30BA\u3092\u6C42\u3081\u308B\n\t/// @param x \u9802\u70B9\u756A\u53F7\n\t///\
    \ @param t \u6642\u523B\n\t/// @return \u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\
    \u30BA\n\tint get_size(int x, int t) {\n\t\tx = leader(x, t);\n\t\tauto it = upper_bound(ALL(size[x]),\
    \ PI { t, 0 });\n\t\tit--;\n\t\treturn (*it).second;\n\t};\n};\n"
  code: "#include \"../base.hpp\"\n\nclass dsu {\nprivate:\n\tvi p;  //p => \u89AA\
    \n\tvi time;\n\tvector<vector<PI>> size;\n\tint N;\n\tint now;\n\npublic:\n\t\
    dsu() {\n\t}\n\t/// @brief \u30B5\u30A4\u30BAn\u3067\u8FBA\u304C\u306A\u3044UF\u3092\
    \u751F\u6210\n\t/// @param sz \u9802\u70B9\u6570\n\tdsu(int sz) {\n\t\tN = sz;\n\
    \t\tnow = 0;\n\t\tp.resize(N, 1);\n\t\ttime.resize(N, INF);\n\t\tsize.resize(N,\
    \ vector<PI>(1, { 0, 1 }));\n\t}\n\n\t/// @brief \u6642\u523Bt\u306E\u6642\u70B9\
    \u3067x\u3068y\u304C\u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3057\u3066\
    \u3044\u308B\u304B\u5224\u5B9A\n\t/// @param x \u9802\u70B91\n\t/// @param y \u9802\
    \u70B92\n\t/// @param t \u5224\u5B9A\u3059\u308B\u6642\u9593\n\t/// @return \u540C\
    \u4E00\u9023\u7D50\u6210\u5206\u306A\u3089true\n\tbool same(int x, int y, int\
    \ t) {\n\t\treturn leader(x, t) == leader(y, t);\n\t}\n\n\t/// @brief \u6642\u523B\
    \u30921\u9032\u3081\u3066x\u3068y\u3092\u30DE\u30FC\u30B8\u3059\u308B\n\t/// @param\
    \ x \u9802\u70B91\n\t/// @param y \u9802\u70B92\n\t/// @return \u30DE\u30FC\u30B8\
    \u5F8C\u306E\u6642\u523B\n\tint merge(int x, int y) {\n\t\t++now;\n\t\tx = leader(x,\
    \ now);\n\t\ty = leader(y, now);\n\t\tif(x == y) return now;\n\t\tif(p[x] < p[y])\
    \ {\n\t\t\tswap(x, y);\n\t\t}\n\t\tp[x] += p[y];\n\t\tsize[x].push_back({ now,\
    \ p[x] });\n\t\tp[y] = x;\n\t\ttime[y] = now;\n\t\treturn now;\n\t}\n\n\t/// @brief\
    \ \u6642\u523Bt\u6642\u70B9\u3067\u306Ex\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u30EA\u30FC\u30C0\u30FC\u3092\u53D6\u5F97\n\t/// @param x \u9802\u70B9\
    \n\t/// @param t \u6642\u523B\n\t/// @return \u30EA\u30FC\u30C0\u30FC\u306E\u9802\
    \u70B9\u756A\u53F7\n\tint leader(int x, int t) {\n\t\tif(time[x] > t)\n\t\t\t\
    return x;\n\t\telse\n\t\t\treturn leader(p[x], t);\n\t}\n\n\t/// @brief \u73FE\
    \u5728\u306E\u6642\u523B\u3092\u53D6\u5F97\u3059\u308B\n\t/// @return \u73FE\u5728\
    \u306E\u6642\u523B\n\tint get_time() {\n\t\treturn now;\n\t}\n\n\t/// @brief \u6642\
    \u523Bt\u6642\u70B9\u3067\u306Ex\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\
    \u306E\u30B5\u30A4\u30BA\u3092\u6C42\u3081\u308B\n\t/// @param x \u9802\u70B9\u756A\
    \u53F7\n\t/// @param t \u6642\u523B\n\t/// @return \u9023\u7D50\u6210\u5206\u306E\
    \u30B5\u30A4\u30BA\n\tint get_size(int x, int t) {\n\t\tx = leader(x, t);\n\t\t\
    auto it = upper_bound(ALL(size[x]), PI { t, 0 });\n\t\tit--;\n\t\treturn (*it).second;\n\
    \t};\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: structure/partial_persistent_uf.hpp
  requiredBy: []
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/partial_persistent_uf.hpp
layout: document
redirect_from:
- /library/structure/partial_persistent_uf.hpp
- /library/structure/partial_persistent_uf.hpp.html
title: "\u30B5\u30A4\u30BAn\u3067\u8FBA\u304C\u306A\u3044UF\u3092\u751F\u6210"
---
