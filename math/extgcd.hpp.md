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
    document_title: "\u62E1\u5F35GCD"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"math/extgcd.hpp\"\
    \n/// @brief \u62E1\u5F35GCD\n/// @brief gcd(a,b)\u3068ax+by=gcd(a,b)\u3092\u6E80\
    \u305F\u3059x,y\u3092\u6C42\u3081\u308B\n/// @param a \u5165\u529B1\u3064\u76EE\
    \n/// @param b \u5165\u529B2\u3064\u76EE\n/// @param x \u51FA\u529B1\u3064\u76EE\
    \n/// @param y \u51FA\u529B2\u3064\u76EE\n/// @return gcd(a,b)\nll extgcd(ll a,\
    \ ll b, ll& x, ll& y) {\n\tll d = a;\n\tif(b != 0) {\n\t\td = extgcd(b, a % b,\
    \ y, x);\n\t\ty -= (a / b) * x;\n\t} else {\n\t\tx = 1;\n\t\ty = 0;\n\t}\n\treturn\
    \ d;\n}\n\n/// @brief \u4EFB\u610F\u306Em\u306B\u3064\u3044\u3066n^{-1} mod m\u3092\
    \u6C42\u3081\u308B.\n/// @param n \u9006\u5143\u3092\u6C42\u3081\u305F\u3044\u5024\
    \n/// @param m \u6CD5(\u7D20\u6570\u3067\u306A\u304F\u3066\u3082\u3088\u3044)\n\
    /// @return \u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1,\u5B58\u5728\u3059\u308B\
    \u306A\u3089\u9006\u5143\nll inv_extgcd(ll n, ll m) {\n\tll x, y;\n\tll G = extgcd(n,\
    \ m, x, y);\n\tif(G != 1) {\n\t\treturn -1;\n\t}\n\tif(x < 0) {\n\t\tx += (abs(x)\
    \ + 2 * m) / m * m;\n\t}\n\tx %= m;\n\treturn x;\n}\n"
  code: "#include \"../base.hpp\"\n/// @brief \u62E1\u5F35GCD\n/// @brief gcd(a,b)\u3068\
    ax+by=gcd(a,b)\u3092\u6E80\u305F\u3059x,y\u3092\u6C42\u3081\u308B\n/// @param\
    \ a \u5165\u529B1\u3064\u76EE\n/// @param b \u5165\u529B2\u3064\u76EE\n/// @param\
    \ x \u51FA\u529B1\u3064\u76EE\n/// @param y \u51FA\u529B2\u3064\u76EE\n/// @return\
    \ gcd(a,b)\nll extgcd(ll a, ll b, ll& x, ll& y) {\n\tll d = a;\n\tif(b != 0) {\n\
    \t\td = extgcd(b, a % b, y, x);\n\t\ty -= (a / b) * x;\n\t} else {\n\t\tx = 1;\n\
    \t\ty = 0;\n\t}\n\treturn d;\n}\n\n/// @brief \u4EFB\u610F\u306Em\u306B\u3064\u3044\
    \u3066n^{-1} mod m\u3092\u6C42\u3081\u308B.\n/// @param n \u9006\u5143\u3092\u6C42\
    \u3081\u305F\u3044\u5024\n/// @param m \u6CD5(\u7D20\u6570\u3067\u306A\u304F\u3066\
    \u3082\u3088\u3044)\n/// @return \u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1,\u5B58\
    \u5728\u3059\u308B\u306A\u3089\u9006\u5143\nll inv_extgcd(ll n, ll m) {\n\tll\
    \ x, y;\n\tll G = extgcd(n, m, x, y);\n\tif(G != 1) {\n\t\treturn -1;\n\t}\n\t\
    if(x < 0) {\n\t\tx += (abs(x) + 2 * m) / m * m;\n\t}\n\tx %= m;\n\treturn x;\n\
    }"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/extgcd.hpp
  requiredBy:
  - math/all.hpp
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/extgcd.hpp
layout: document
redirect_from:
- /library/math/extgcd.hpp
- /library/math/extgcd.hpp.html
title: "\u62E1\u5F35GCD"
---
