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
    document_title: "\u30C0\u30D6\u30EA\u30F3\u30B0"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"doubling.hpp\"\
    \n/// @brief \u30C0\u30D6\u30EA\u30F3\u30B0\n/// @tparam T \u30E2\u30CE\u30A4\u30C9\
    \u306E\u578B\ntemplate<class T = ll>\nstruct Doubling {\nprivate:\n\tint N;\n\t\
    vvi V;\n\tvector<vector<T>> S;\n\tvector<T> s;\n\tfunction<T(T, T)> op;\n\tfunction<T()>\
    \ e;\n\tbool hasMonoid = false;\n\n\tinline void build_next() {\n\t\tint n = SZ(V);\n\
    \t\tV.push_back(vi(N));\n\t\tif(hasMonoid) S.push_back(vector<T>(N));\n\t\tREP(i,\
    \ N) {\n\t\t\tV[n][i] = V[n - 1][V[n - 1][i]];\n\t\t\tif(hasMonoid)\n\t\t\t\t\
    S[n][i] = op(S[n - 1][i],\n\t\t\t\t\t\t\t S[n - 1][V[n - 1][i]]);\n\t\t}\n\t}\n\
    \npublic:\n\tDoubling() {\n\t}\n\n\t/// @brief \u30B5\u30A4\u30BAn\u306E\u6052\
    \u7B49\u5199\u50CF\u3067\u521D\u671F\u5316\n\t/// @param n \u30C0\u30D6\u30EA\u30F3\
    \u30B0\u306E\u30B5\u30A4\u30BA\n\tDoubling(int n) {\n\t\tvi v(n);\n\t\tREP(i,\
    \ n) v[i] = i;\n\t\tinit(v);\n\t}\n\n\t/// @brief \u5199\u50CF\u3092\u6307\u5B9A\
    \u3057\u3066\u521D\u671F\u5316\n\t/// @param v \u30C0\u30D6\u30EA\u30F3\u30B0\u306E\
    \u5199\u50CF\n\tDoubling(const vi& v) {\n\t\tinit(v);\n\t}\n\n\tvoid init(const\
    \ vi& v) {\n\t\tN = SZ(v);\n\t\tREP(i, N) {\n\t\t\tassert(v[i] >= 0 && v[i] <\
    \ N);\n\t\t}\n\t\tV.push_back(vi(N));\n\t\tREP(i, N) V[0][i] = v[i];\n\t}\n\t\
    /// @brief \u30C0\u30D6\u30EA\u30F3\u30B0\u306B\u30E2\u30CE\u30A4\u30C9\u3092\u8F09\
    \u305B\u308B\n\t/// @param _s _s[i]\u306Fi\u304B\u3089\u5EF6\u3073\u308B\u8FBA\
    \u306B\u5BFE\u5FDC\u3059\u308B\u30E2\u30CE\u30A4\u30C9\n\t/// @param _op \u30E2\
    \u30CE\u30A4\u30C9\u306E\u6F14\u7B97\n\t/// @param _e \u30E2\u30CE\u30A4\u30C9\
    \u306E\u5358\u4F4D\u5143\n\tvoid setMonoid(const vector<T>& _s,\n\t\t\t\t   const\
    \ function<T(T, T)>& _op,\n\t\t\t\t   const function<T()>& _e) {\n\t\tassert(SZ(_s)\
    \ == N);\n\t\thasMonoid = true;\n\t\top = _op;\n\t\te = _e;\n\t\ts = _s;\n\t\t\
    S.clear();\n\t\tS.push_back(vector<T>(N));\n\t\tREP(i, N) S[0][i] = s[i];\n\t\
    }\n\n\t/// @brief x\u3092L\u56DE\u5199\u50CF\u3057\u305F\u6642\u306E\u5024\u3092\
    \u6C42\u3081\u308B\n\t/// @param L \u5199\u50CF\u306E\u7E70\u308A\u8FD4\u3057\u56DE\
    \u6570\n\t/// @param x \u5199\u50CF\u306E\u521D\u671F\u5024\n\t/// @return x\u3092\
    L\u56DE\u5199\u50CF\u3057\u305F\u6642\u306E\u5024\n\tint get(ll L, int x) {\n\t\
    \tint ret = x;\n\t\tfor(int i = 0; L > 0ll; i++) {\n\t\t\tif(i >= SZ(V)) build_next();\n\
    \t\t\tif(L & 1ll) ret = V[i][ret];\n\t\t\tL >>= 1ll;\n\t\t}\n\t\treturn ret;\n\
    \t}\n\n\t/// @brief L\u56DE\u306E\u5199\u50CF\u3067\u305F\u3069\u3063\u305F\u8FBA\
    \u306B\u5BFE\u5FDC\u3059\u308B\u30E2\u30CE\u30A4\u30C9\u306E\u7DCF\u7A4D\u3092\
    \u6C42\u3081\u308B\n\t/// @param L \u5199\u50CF\u306E\u7E70\u308A\u8FD4\u3057\u56DE\
    \u6570\n\t/// @param x \u5199\u50CF\u306E\u521D\u671F\u5024\n\t/// @return L\u56DE\
    \u306E\u5199\u50CF\u3067\u305F\u3069\u3063\u305F\u8FBA\u306B\u5BFE\u5FDC\u3059\
    \u308B\u30E2\u30CE\u30A4\u30C9\u7A4D\n\tT prod(ll L, int x) {\n\t\tassert(hasMonoid);\n\
    \t\tint cur = x;\n\t\tT ret = e();\n\t\tfor(int i = 0; L > 0ll; i++) {\n\t\t\t\
    if(i >= SZ(V)) build_next();\n\t\t\tif(L & 1ll) {\n\t\t\t\tret = op(ret, S[i][cur]);\n\
    \t\t\t\tcur = V[i][cur];\n\t\t\t}\n\t\t\tL >>= 1ll;\n\t\t}\n\t\treturn ret;\n\t\
    }\n};\n"
  code: "#include \"./base.hpp\"\n/// @brief \u30C0\u30D6\u30EA\u30F3\u30B0\n/// @tparam\
    \ T \u30E2\u30CE\u30A4\u30C9\u306E\u578B\ntemplate<class T = ll>\nstruct Doubling\
    \ {\nprivate:\n\tint N;\n\tvvi V;\n\tvector<vector<T>> S;\n\tvector<T> s;\n\t\
    function<T(T, T)> op;\n\tfunction<T()> e;\n\tbool hasMonoid = false;\n\n\tinline\
    \ void build_next() {\n\t\tint n = SZ(V);\n\t\tV.push_back(vi(N));\n\t\tif(hasMonoid)\
    \ S.push_back(vector<T>(N));\n\t\tREP(i, N) {\n\t\t\tV[n][i] = V[n - 1][V[n -\
    \ 1][i]];\n\t\t\tif(hasMonoid)\n\t\t\t\tS[n][i] = op(S[n - 1][i],\n\t\t\t\t\t\t\
    \t S[n - 1][V[n - 1][i]]);\n\t\t}\n\t}\n\npublic:\n\tDoubling() {\n\t}\n\n\t///\
    \ @brief \u30B5\u30A4\u30BAn\u306E\u6052\u7B49\u5199\u50CF\u3067\u521D\u671F\u5316\
    \n\t/// @param n \u30C0\u30D6\u30EA\u30F3\u30B0\u306E\u30B5\u30A4\u30BA\n\tDoubling(int\
    \ n) {\n\t\tvi v(n);\n\t\tREP(i, n) v[i] = i;\n\t\tinit(v);\n\t}\n\n\t/// @brief\
    \ \u5199\u50CF\u3092\u6307\u5B9A\u3057\u3066\u521D\u671F\u5316\n\t/// @param v\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u306E\u5199\u50CF\n\tDoubling(const vi& v) {\n\
    \t\tinit(v);\n\t}\n\n\tvoid init(const vi& v) {\n\t\tN = SZ(v);\n\t\tREP(i, N)\
    \ {\n\t\t\tassert(v[i] >= 0 && v[i] < N);\n\t\t}\n\t\tV.push_back(vi(N));\n\t\t\
    REP(i, N) V[0][i] = v[i];\n\t}\n\t/// @brief \u30C0\u30D6\u30EA\u30F3\u30B0\u306B\
    \u30E2\u30CE\u30A4\u30C9\u3092\u8F09\u305B\u308B\n\t/// @param _s _s[i]\u306F\
    i\u304B\u3089\u5EF6\u3073\u308B\u8FBA\u306B\u5BFE\u5FDC\u3059\u308B\u30E2\u30CE\
    \u30A4\u30C9\n\t/// @param _op \u30E2\u30CE\u30A4\u30C9\u306E\u6F14\u7B97\n\t\
    /// @param _e \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n\tvoid setMonoid(const\
    \ vector<T>& _s,\n\t\t\t\t   const function<T(T, T)>& _op,\n\t\t\t\t   const function<T()>&\
    \ _e) {\n\t\tassert(SZ(_s) == N);\n\t\thasMonoid = true;\n\t\top = _op;\n\t\t\
    e = _e;\n\t\ts = _s;\n\t\tS.clear();\n\t\tS.push_back(vector<T>(N));\n\t\tREP(i,\
    \ N) S[0][i] = s[i];\n\t}\n\n\t/// @brief x\u3092L\u56DE\u5199\u50CF\u3057\u305F\
    \u6642\u306E\u5024\u3092\u6C42\u3081\u308B\n\t/// @param L \u5199\u50CF\u306E\u7E70\
    \u308A\u8FD4\u3057\u56DE\u6570\n\t/// @param x \u5199\u50CF\u306E\u521D\u671F\u5024\
    \n\t/// @return x\u3092L\u56DE\u5199\u50CF\u3057\u305F\u6642\u306E\u5024\n\tint\
    \ get(ll L, int x) {\n\t\tint ret = x;\n\t\tfor(int i = 0; L > 0ll; i++) {\n\t\
    \t\tif(i >= SZ(V)) build_next();\n\t\t\tif(L & 1ll) ret = V[i][ret];\n\t\t\tL\
    \ >>= 1ll;\n\t\t}\n\t\treturn ret;\n\t}\n\n\t/// @brief L\u56DE\u306E\u5199\u50CF\
    \u3067\u305F\u3069\u3063\u305F\u8FBA\u306B\u5BFE\u5FDC\u3059\u308B\u30E2\u30CE\
    \u30A4\u30C9\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\n\t/// @param L \u5199\u50CF\
    \u306E\u7E70\u308A\u8FD4\u3057\u56DE\u6570\n\t/// @param x \u5199\u50CF\u306E\u521D\
    \u671F\u5024\n\t/// @return L\u56DE\u306E\u5199\u50CF\u3067\u305F\u3069\u3063\u305F\
    \u8FBA\u306B\u5BFE\u5FDC\u3059\u308B\u30E2\u30CE\u30A4\u30C9\u7A4D\n\tT prod(ll\
    \ L, int x) {\n\t\tassert(hasMonoid);\n\t\tint cur = x;\n\t\tT ret = e();\n\t\t\
    for(int i = 0; L > 0ll; i++) {\n\t\t\tif(i >= SZ(V)) build_next();\n\t\t\tif(L\
    \ & 1ll) {\n\t\t\t\tret = op(ret, S[i][cur]);\n\t\t\t\tcur = V[i][cur];\n\t\t\t\
    }\n\t\t\tL >>= 1ll;\n\t\t}\n\t\treturn ret;\n\t}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: doubling.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: doubling.hpp
layout: document
redirect_from:
- /library/doubling.hpp
- /library/doubling.hpp.html
title: "\u30C0\u30D6\u30EA\u30F3\u30B0"
---
