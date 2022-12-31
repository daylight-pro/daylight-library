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
    document_title: "\u5404\u6587\u5B57\u306B\u3064\u3044\u3066\u3001\u305D\u306E\u6587\
      \u5B57\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u56DE\u6587\u306E\u534A\
      \u5F84\u3092\u3082\u3068\u3081\u308B"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"string/manacher.hpp\"\
    \n\n/// @brief \u5404\u6587\u5B57\u306B\u3064\u3044\u3066\u3001\u305D\u306E\u6587\
    \u5B57\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u56DE\u6587\u306E\u534A\
    \u5F84\u3092\u3082\u3068\u3081\u308B\n/// @param S \u5BFE\u8C61\u306E\u6587\u5B57\
    \u5217\n/// @return ret[i]:i\u6587\u5B57\u76EE\u3092\u4E2D\u5FC3\u3068\u3059\u308B\
    \u6700\u9577\u56DE\u6587\u306E\u534A\u5F84\nvi manacher(string& S) {\n\tint N\
    \ = SZ(S);\n\tint i = 0;\n\tint j = 0;\n\tvi ret(N);\n\twhile(i < N) {\n\t\twhile(i\
    \ - j >= 0 && i + j < N\n\t\t\t  && S[i - j] == S[i + j])\n\t\t\tj++;\n\t\tret[i]\
    \ = j;\n\t\tint k = 1;\n\t\twhile(i - k >= 0 && k + ret[i - k] < j) {\n\t\t\t\
    ret[i + k] = ret[i - k];\n\t\t\tk++;\n\t\t}\n\t\ti += k;\n\t\tj -= k;\n\t}\n\t\
    return ret;\n}\n\n/// @brief 2N-1\u500B\u306E\u5834\u6240(\u6587\u5B57\u3068\u3001\
    \u6587\u5B57\u3068\u6587\u5B57\u306E\u9593)\u306B\u3064\u3044\u3066\u3001\u305D\
    \u308C\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u56DE\u6587\u306E\u534A\
    \u5F84\n/// @param S \u5BFE\u8C61\u306E\u6587\u5B57\u5217\n/// @return ret[i](\u9577\
    \u30552N-1):\u5DE6\u304B\u3089i\u756A\u76EE\u306E\u5834\u6240\u3092\u4E2D\u5FC3\
    \u3068\u3059\u308B\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84\nvi ext_manacher(string&\
    \ S) {\n\tstringstream ss;\n\tint N = SZ(S);\n\tREP(i, N) {\n\t\tif(i != 0) ss\
    \ << \"$\";\n\t\tss << S[i];\n\t}\n\tstring s = ss.str();\n\tauto ret = manacher(s);\n\
    \tREP(i, 2 * N - 1) {\n\t\tif(i % 2 == 0) {\n\t\t\tret[i] = (ret[i] + 1) / 2;\n\
    \t\t} else {\n\t\t\tret[i] = ret[i] / 2;\n\t\t}\n\t}\n\treturn ret;\n}\n"
  code: "#include \"../base.hpp\"\n\n/// @brief \u5404\u6587\u5B57\u306B\u3064\u3044\
    \u3066\u3001\u305D\u306E\u6587\u5B57\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\
    \u9577\u56DE\u6587\u306E\u534A\u5F84\u3092\u3082\u3068\u3081\u308B\n/// @param\
    \ S \u5BFE\u8C61\u306E\u6587\u5B57\u5217\n/// @return ret[i]:i\u6587\u5B57\u76EE\
    \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84\
    \nvi manacher(string& S) {\n\tint N = SZ(S);\n\tint i = 0;\n\tint j = 0;\n\tvi\
    \ ret(N);\n\twhile(i < N) {\n\t\twhile(i - j >= 0 && i + j < N\n\t\t\t  && S[i\
    \ - j] == S[i + j])\n\t\t\tj++;\n\t\tret[i] = j;\n\t\tint k = 1;\n\t\twhile(i\
    \ - k >= 0 && k + ret[i - k] < j) {\n\t\t\tret[i + k] = ret[i - k];\n\t\t\tk++;\n\
    \t\t}\n\t\ti += k;\n\t\tj -= k;\n\t}\n\treturn ret;\n}\n\n/// @brief 2N-1\u500B\
    \u306E\u5834\u6240(\u6587\u5B57\u3068\u3001\u6587\u5B57\u3068\u6587\u5B57\u306E\
    \u9593)\u306B\u3064\u3044\u3066\u3001\u305D\u308C\u3092\u4E2D\u5FC3\u3068\u3059\
    \u308B\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84\n/// @param S \u5BFE\u8C61\u306E\
    \u6587\u5B57\u5217\n/// @return ret[i](\u9577\u30552N-1):\u5DE6\u304B\u3089i\u756A\
    \u76EE\u306E\u5834\u6240\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u56DE\
    \u6587\u306E\u534A\u5F84\nvi ext_manacher(string& S) {\n\tstringstream ss;\n\t\
    int N = SZ(S);\n\tREP(i, N) {\n\t\tif(i != 0) ss << \"$\";\n\t\tss << S[i];\n\t\
    }\n\tstring s = ss.str();\n\tauto ret = manacher(s);\n\tREP(i, 2 * N - 1) {\n\t\
    \tif(i % 2 == 0) {\n\t\t\tret[i] = (ret[i] + 1) / 2;\n\t\t} else {\n\t\t\tret[i]\
    \ = ret[i] / 2;\n\t\t}\n\t}\n\treturn ret;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: "\u5404\u6587\u5B57\u306B\u3064\u3044\u3066\u3001\u305D\u306E\u6587\u5B57\u3092\
  \u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84\u3092\u3082\
  \u3068\u3081\u308B"
---
