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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"math/matrix.hpp\"\
    \ntemplate<typename T>\nvector<vector<T>> multiMatrix(const vector<vector<T>>\
    \ &A,\n\t\t\t\t\t\t\t  const vector<vector<T>> &B) {\n\tint N = SZ(A);\n\tint\
    \ M = SZ(B[0]);\n\tint L = SZ(A[0]);\n\tauto ret = make_v<T>(N, M);\n\tREP(i,\
    \ N) {\n\t\tREP(j, M) {\n\t\t\tREP(k, L) {\n\t\t\t\tret[i][j] += A[i][k] * B[k][j];\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn ret;\n}\n\ntemplate<typename T>\nvector<vector<T>>\
    \ powMatrix(const vector<vector<T>> &A,\n\t\t\t\t\t\t\tll p) {\n\tauto ans = make_v<T>(SZ(A),\
    \ SZ(A));\n\tREP(i, SZ(A)) ans[i][i] = 1;\n\tauto mul = A;\n\tfor(; p > 0; p >>=\
    \ 1) {\n\t\tif((p & 1) == 1) ans = multiMatrix(ans, mul);\n\t\tmul = multiMatrix(mul,\
    \ mul);\n\t}\n\treturn ans;\n}\n"
  code: "#include \"../base.hpp\"\ntemplate<typename T>\nvector<vector<T>> multiMatrix(const\
    \ vector<vector<T>> &A,\n\t\t\t\t\t\t\t  const vector<vector<T>> &B) {\n\tint\
    \ N = SZ(A);\n\tint M = SZ(B[0]);\n\tint L = SZ(A[0]);\n\tauto ret = make_v<T>(N,\
    \ M);\n\tREP(i, N) {\n\t\tREP(j, M) {\n\t\t\tREP(k, L) {\n\t\t\t\tret[i][j] +=\
    \ A[i][k] * B[k][j];\n\t\t\t}\n\t\t}\n\t}\n\treturn ret;\n}\n\ntemplate<typename\
    \ T>\nvector<vector<T>> powMatrix(const vector<vector<T>> &A,\n\t\t\t\t\t\t\t\
    ll p) {\n\tauto ans = make_v<T>(SZ(A), SZ(A));\n\tREP(i, SZ(A)) ans[i][i] = 1;\n\
    \tauto mul = A;\n\tfor(; p > 0; p >>= 1) {\n\t\tif((p & 1) == 1) ans = multiMatrix(ans,\
    \ mul);\n\t\tmul = multiMatrix(mul, mul);\n\t}\n\treturn ans;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
