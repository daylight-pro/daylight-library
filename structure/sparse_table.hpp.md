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
    document_title: "\u524D\u8A08\u7B97\u3092\u884C\u3046"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"structure/sparse_table.hpp\"\
    \n\ntemplate<typename S, typename F>\nstruct sparse_table {\nprivate:\n\tvector<vector<S>>\
    \ V;\n\tF op;\n\tvi lookup;\n\npublic:\n\t/// @brief \u524D\u8A08\u7B97\u3092\u884C\
    \u3046\n\t/// @param _V \u914D\u5217\u306E\u5024\n\t/// @param op \u6F14\u7B97\
    \u3092\u8868\u3059\u30E9\u30E0\u30C0\u5F0F\n\tsparse_table(vector<S> _V, F op):\
    \ op(op) {\n\t\tint N = SZ(_V);\n\t\tint len = 0;\n\t\twhile((1 << len) <= N)\
    \ len++;\n\t\tV.assign(len, vector<S>(1 << len));\n\t\tREP(i, N) {\n\t\t\tV[0][i]\
    \ = _V[i];\n\t\t}\n\t\tFOR(i, 1, len) {\n\t\t\tfor(int j = 0; j + (1 << i) <=\
    \ (1 << len);\n\t\t\t\tj++) {\n\t\t\t\tV[i][j] = op(V[i - 1][j],\n\t\t\t\t\t\t\
    \t V[i - 1][j + (1 << (i - 1))]);\n\t\t\t}\n\t\t}\n\t\tlookup.resize(N + 1);\n\
    \t\tFOR(i, 2, SZ(lookup)) {\n\t\t\tlookup[i] = lookup[i >> 1] + 1;\n\t\t}\n\t\
    }\n\t/// @brief [l,r)\u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\u5F97\u3059\u308B\
    \n\t/// @param l \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param r \u533A\
    \u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @return \u6F14\u7B97\u7D50\u679C\n\t\
    inline S prod(int l, int r) {\n\t\tint len = lookup[r - l];\n\t\treturn op(V[len][l],\
    \ V[len][r - (1 << len)]);\n\t}\n};\n"
  code: "#include \"../base.hpp\"\n\ntemplate<typename S, typename F>\nstruct sparse_table\
    \ {\nprivate:\n\tvector<vector<S>> V;\n\tF op;\n\tvi lookup;\n\npublic:\n\t///\
    \ @brief \u524D\u8A08\u7B97\u3092\u884C\u3046\n\t/// @param _V \u914D\u5217\u306E\
    \u5024\n\t/// @param op \u6F14\u7B97\u3092\u8868\u3059\u30E9\u30E0\u30C0\u5F0F\
    \n\tsparse_table(vector<S> _V, F op): op(op) {\n\t\tint N = SZ(_V);\n\t\tint len\
    \ = 0;\n\t\twhile((1 << len) <= N) len++;\n\t\tV.assign(len, vector<S>(1 << len));\n\
    \t\tREP(i, N) {\n\t\t\tV[0][i] = _V[i];\n\t\t}\n\t\tFOR(i, 1, len) {\n\t\t\tfor(int\
    \ j = 0; j + (1 << i) <= (1 << len);\n\t\t\t\tj++) {\n\t\t\t\tV[i][j] = op(V[i\
    \ - 1][j],\n\t\t\t\t\t\t\t V[i - 1][j + (1 << (i - 1))]);\n\t\t\t}\n\t\t}\n\t\t\
    lookup.resize(N + 1);\n\t\tFOR(i, 2, SZ(lookup)) {\n\t\t\tlookup[i] = lookup[i\
    \ >> 1] + 1;\n\t\t}\n\t}\n\t/// @brief [l,r)\u306E\u6F14\u7B97\u7D50\u679C\u3092\
    \u53D6\u5F97\u3059\u308B\n\t/// @param l \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\
    \t/// @param r \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @return \u6F14\
    \u7B97\u7D50\u679C\n\tinline S prod(int l, int r) {\n\t\tint len = lookup[r -\
    \ l];\n\t\treturn op(V[len][l], V[len][r - (1 << len)]);\n\t}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/sparse_table.hpp
layout: document
redirect_from:
- /library/structure/sparse_table.hpp
- /library/structure/sparse_table.hpp.html
title: "\u524D\u8A08\u7B97\u3092\u884C\u3046"
---
