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
    document_title: "\u7D20\u56E0\u6570\u5206\u89E3\u3092\u3059\u308B"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"math/prime_factor.hpp\"\
    \n/// @brief \u7D20\u56E0\u6570\u5206\u89E3\u3092\u3059\u308B\n/// @param n \u7D20\
    \u56E0\u6570\u5206\u89E3\u3059\u308B\u6574\u6570\n/// @return map[p]=a:p^a\u304C\
    \u56E0\u6570\u306B\u542B\u307E\u308C\u308B\nmap<ll, int> prime_factor(ll n) {\n\
    \tmap<ll, int> ret;\n\tfor(ll i = 2; i * i <= n; i++) {\n\t\twhile(n % i == 0)\
    \ {\n\t\t\tret[i]++;\n\t\t\tn /= i;\n\t\t}\n\t}\n\tif(n != 1) ret[n] = 1;\n\t\
    return ret;\n}\n/// @brief \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306E\u524D\
    \u8A08\u7B97\u3092\u884C\u3046\n/// @param n \u9AD8\u901F\u7D20\u56E0\u6570\u5206\
    \u89E3\u3092\u884C\u3046\u6574\u6570\u306E\u6700\u5927\u5024\n/// @return \u9AD8\
    \u901F\u7D20\u56E0\u6570\u5206\u89E3\u7528\u306E\u7BE9\u914D\u5217\nvi sieve(int\
    \ n) {\n\tn++;\n\tvi res(n);\n\tstd::iota(res.begin(), res.end(), 0);\n\tfor(int\
    \ i = 2; i * i < n; ++i) {\n\t\tif(res[i] < i) continue;\n\t\tfor(int j = i *\
    \ i; j < n; j += i)\n\t\t\tif(res[j] == j) res[j] = i;\n\t}\n\treturn res;\n}\n\
    \n/// @brief \u524D\u8A08\u7B97\u3057\u305F\u7BE9\u914D\u5217\u3092\u7528\u3044\
    \u3066\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\n/// @param n \u7D20\u56E0\u6570\
    \u5206\u89E3\u3059\u308B\u6574\u6570\n/// @param min_factor \u524D\u8A08\u7B97\
    \u3057\u305F\u7BE9\u914D\u5217\n/// @return map[p]=a:p^a\u304C\u56E0\u6570\u306B\
    \u542B\u307E\u308C\u308B\nmap<int, int> factor(int n, const vi& min_factor) {\n\
    \tmap<int, int> res;\n\twhile(n > 1) {\n\t\tres[min_factor[n]]++;\n\t\tn /= min_factor[n];\n\
    \t}\n\treturn res;\n}\n"
  code: "#include \"../base.hpp\"\n/// @brief \u7D20\u56E0\u6570\u5206\u89E3\u3092\
    \u3059\u308B\n/// @param n \u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\u6574\u6570\
    \n/// @return map[p]=a:p^a\u304C\u56E0\u6570\u306B\u542B\u307E\u308C\u308B\nmap<ll,\
    \ int> prime_factor(ll n) {\n\tmap<ll, int> ret;\n\tfor(ll i = 2; i * i <= n;\
    \ i++) {\n\t\twhile(n % i == 0) {\n\t\t\tret[i]++;\n\t\t\tn /= i;\n\t\t}\n\t}\n\
    \tif(n != 1) ret[n] = 1;\n\treturn ret;\n}\n/// @brief \u9AD8\u901F\u7D20\u56E0\
    \u6570\u5206\u89E3\u306E\u524D\u8A08\u7B97\u3092\u884C\u3046\n/// @param n \u9AD8\
    \u901F\u7D20\u56E0\u6570\u5206\u89E3\u3092\u884C\u3046\u6574\u6570\u306E\u6700\
    \u5927\u5024\n/// @return \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u7528\u306E\
    \u7BE9\u914D\u5217\nvi sieve(int n) {\n\tn++;\n\tvi res(n);\n\tstd::iota(res.begin(),\
    \ res.end(), 0);\n\tfor(int i = 2; i * i < n; ++i) {\n\t\tif(res[i] < i) continue;\n\
    \t\tfor(int j = i * i; j < n; j += i)\n\t\t\tif(res[j] == j) res[j] = i;\n\t}\n\
    \treturn res;\n}\n\n/// @brief \u524D\u8A08\u7B97\u3057\u305F\u7BE9\u914D\u5217\
    \u3092\u7528\u3044\u3066\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\n/// @param\
    \ n \u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\u6574\u6570\n/// @param min_factor\
    \ \u524D\u8A08\u7B97\u3057\u305F\u7BE9\u914D\u5217\n/// @return map[p]=a:p^a\u304C\
    \u56E0\u6570\u306B\u542B\u307E\u308C\u308B\nmap<int, int> factor(int n, const\
    \ vi& min_factor) {\n\tmap<int, int> res;\n\twhile(n > 1) {\n\t\tres[min_factor[n]]++;\n\
    \t\tn /= min_factor[n];\n\t}\n\treturn res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/prime_factor.hpp
  requiredBy:
  - math/all.hpp
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_factor.hpp
layout: document
redirect_from:
- /library/math/prime_factor.hpp
- /library/math/prime_factor.hpp.html
title: "\u7D20\u56E0\u6570\u5206\u89E3\u3092\u3059\u308B"
---
