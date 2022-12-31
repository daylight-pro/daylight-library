---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"math/comb.hpp\"\
    \ntemplate<typename T>\nstruct Comb {\nprivate:\n\tvector<T> _fact;\n\tvector<T>\
    \ inv;\n\tint pre_build;\n\tvoid expand(int x) {\n\t\tif(pre_build == -1) return;\n\
    \t\twhile(SZ(_fact) <= x) {\n\t\t\tint next = SZ(_fact);\n\t\t\t_fact.push_back(_fact[next\
    \ - 1] * next);\n\t\t\tinv.push_back(_fact[next].inv());\n\t\t}\n\t}\n\n\tT nPr_calc(int\
    \ n, int r) {\n\t\tT ret = 1;\n\t\tfor(int i = n; i > n - r; i--) ret *= i;\n\t\
    \treturn ret;\n\t}\n\tT nCr_calc(int n, int r) {\n\t\tT ret = 1;\n\t\tREP(i, r)\
    \ {\n\t\t\tret *= n - i;\n\t\t\tret /= i + 1;\n\t\t}\n\t\treturn ret;\n\t}\n\n\
    public:\n\tComb(int pre_build = 0): pre_build(pre_build) {\n\t\tif(pre_build ==\
    \ -1) {\n\t\t\treturn;\n\t\t}\n\t\t_fact = vector<T>(pre_build + 1);\n\t\t_fact[0]\
    \ = 1;\n\t\tinv = vector<T>(pre_build + 1);\n\t\tREP(i, pre_build) {\n\t\t\t_fact[i\
    \ + 1] = _fact[i] * (i + 1);\n\t\t}\n\t\tinv[pre_build] = _fact[pre_build].inv();\n\
    \t\tREPR(i, pre_build) {\n\t\t\tinv[i] = inv[i + 1] * (i + 1);\n\t\t}\n\t}\n\t\
    T nPr(int n, int r) {\n\t\tassert(r >= 0);\n\t\tassert(n >= r);\n\t\texpand(n);\n\
    \t\tif(pre_build == -1) return nPr_calc(n, r);\n\t\treturn _fact[n] * inv[n -\
    \ r];\n\t}\n\tT nCr(int n, int r) {\n\t\tassert(r >= 0);\n\t\tassert(n >= r);\n\
    \t\texpand(n);\n\t\tif(pre_build == -1) return nCr_calc(n, r);\n\t\treturn _fact[n]\
    \ * inv[r] * inv[n - r];\n\t}\n\tT nHr(int n, int r) {\n\t\tassert(r >= 0);\n\t\
    \tassert(n >= 1);\n\t\texpand(n + r - 1);\n\t\treturn nCr(n + r - 1, r);\n\t}\n\
    \tT type_permission(vi V) {\n\t\tassert(pre_build != -1);\n\t\tint sum = 0;\n\t\
    \tfor(int i: V) {\n\t\t\tassert(i >= 0);\n\t\t\tsum += i;\n\t\t}\n\t\texpand(sum);\n\
    \t\tT ans = _fact[sum];\n\t\tfor(int i: V) ans *= inv[i];\n\t\treturn ans;\n\t\
    }\n\tT fact(int n) {\n\t\texpand(n);\n\t\treturn _fact[n];\n\t}\n\tT inv_fact(int\
    \ n) {\n\t\texpand(n);\n\t\treturn inv[n];\n\t}\n};\n"
  code: "#include \"../base.hpp\"\ntemplate<typename T>\nstruct Comb {\nprivate:\n\
    \tvector<T> _fact;\n\tvector<T> inv;\n\tint pre_build;\n\tvoid expand(int x) {\n\
    \t\tif(pre_build == -1) return;\n\t\twhile(SZ(_fact) <= x) {\n\t\t\tint next =\
    \ SZ(_fact);\n\t\t\t_fact.push_back(_fact[next - 1] * next);\n\t\t\tinv.push_back(_fact[next].inv());\n\
    \t\t}\n\t}\n\n\tT nPr_calc(int n, int r) {\n\t\tT ret = 1;\n\t\tfor(int i = n;\
    \ i > n - r; i--) ret *= i;\n\t\treturn ret;\n\t}\n\tT nCr_calc(int n, int r)\
    \ {\n\t\tT ret = 1;\n\t\tREP(i, r) {\n\t\t\tret *= n - i;\n\t\t\tret /= i + 1;\n\
    \t\t}\n\t\treturn ret;\n\t}\n\npublic:\n\tComb(int pre_build = 0): pre_build(pre_build)\
    \ {\n\t\tif(pre_build == -1) {\n\t\t\treturn;\n\t\t}\n\t\t_fact = vector<T>(pre_build\
    \ + 1);\n\t\t_fact[0] = 1;\n\t\tinv = vector<T>(pre_build + 1);\n\t\tREP(i, pre_build)\
    \ {\n\t\t\t_fact[i + 1] = _fact[i] * (i + 1);\n\t\t}\n\t\tinv[pre_build] = _fact[pre_build].inv();\n\
    \t\tREPR(i, pre_build) {\n\t\t\tinv[i] = inv[i + 1] * (i + 1);\n\t\t}\n\t}\n\t\
    T nPr(int n, int r) {\n\t\tassert(r >= 0);\n\t\tassert(n >= r);\n\t\texpand(n);\n\
    \t\tif(pre_build == -1) return nPr_calc(n, r);\n\t\treturn _fact[n] * inv[n -\
    \ r];\n\t}\n\tT nCr(int n, int r) {\n\t\tassert(r >= 0);\n\t\tassert(n >= r);\n\
    \t\texpand(n);\n\t\tif(pre_build == -1) return nCr_calc(n, r);\n\t\treturn _fact[n]\
    \ * inv[r] * inv[n - r];\n\t}\n\tT nHr(int n, int r) {\n\t\tassert(r >= 0);\n\t\
    \tassert(n >= 1);\n\t\texpand(n + r - 1);\n\t\treturn nCr(n + r - 1, r);\n\t}\n\
    \tT type_permission(vi V) {\n\t\tassert(pre_build != -1);\n\t\tint sum = 0;\n\t\
    \tfor(int i: V) {\n\t\t\tassert(i >= 0);\n\t\t\tsum += i;\n\t\t}\n\t\texpand(sum);\n\
    \t\tT ans = _fact[sum];\n\t\tfor(int i: V) ans *= inv[i];\n\t\treturn ans;\n\t\
    }\n\tT fact(int n) {\n\t\texpand(n);\n\t\treturn _fact[n];\n\t}\n\tT inv_fact(int\
    \ n) {\n\t\texpand(n);\n\t\treturn inv[n];\n\t}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/comb.hpp
  requiredBy:
  - math/all.hpp
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/comb.hpp
layout: document
redirect_from:
- /library/math/comb.hpp
- /library/math/comb.hpp.html
title: math/comb.hpp
---
