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
    document_title: "\u5C3A\u53D6\u308A\u6CD5"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"double_pointer.hpp\"\
    \n/// @brief \u5C3A\u53D6\u308A\u6CD5\n\n/// @brief \u5404l\u306B\u3064\u3044\u3066\
    check(l,r)==true\u306B\u306A\u308B\u6700\u5C0F\u306Er\u3092\u6C42\u3081\u308B\u3002\
    \n/// @param left \u63A2\u7D22\u7BC4\u56F2\u306E\u5DE6\u7AEF(inclusive)\n/// @param\
    \ right \u63A2\u7D22\u7BC4\u56F2\u306E\u53F3\u7AEF(exclusive)\n/// @param check\
    \ ()->\u73FE\u5728\u306E\u7BC4\u56F2\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u304B\n/// @param add (\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9,\u5DE6\u304B\u3089\
    \u306E\u64CD\u4F5C\u304B)\n/// @param del (\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    ,\u5DE6\u304B\u3089\u306E\u64CD\u4F5C\u304B)\n/// @param update \u5404l\u306B\u3064\
    \u3044\u3066check(l,r)==true\u306B\u306A\u308B\u6700\u5927\u306Er\u3068\u3068\u3082\
    \u306B1\u5EA6\u306E\u307F\u547C\u3070\u308C\u308B\nvoid doublePointerMinRight(\n\
    \tint left, int right, function<bool()> check,\n\tfunction<void(int, bool)> add,\n\
    \tfunction<void(int, bool)> del,\n\tfunction<void(int, int)> update) {\n\tint\
    \ r = left;\n\tfor(int l = left; l < right; l++) {\n\t\twhile(r < right && check())\
    \ {\n\t\t\tadd(r++, false);\n\t\t}\n\t\tif(!check()) break;\n\t\tupdate(l, r);\n\
    \t\tdel(l, true);\n\t}\n}\n\n/// @brief \u5404l\u306B\u3064\u3044\u3066check(l,r)==true\u306B\
    \u306A\u308B\u6700\u5927\u306Er\u3092\u6C42\u3081\u308B\u3002\n/// @param left\
    \ \u63A2\u7D22\u7BC4\u56F2\u306E\u5DE6\u7AEF(inclusive)\n/// @param right \u63A2\
    \u7D22\u7BC4\u56F2\u306E\u53F3\u7AEF(exclusive)\n/// @param check ()->\u73FE\u5728\
    \u306E\u7BC4\u56F2\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\n/// @param\
    \ add (\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9,\u5DE6\u304B\u3089\u306E\u64CD\u4F5C\
    \u304B)\n/// @param del (\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9,\u5DE6\u304B\u3089\
    \u306E\u64CD\u4F5C\u304B)\n/// @param update \u5404l\u306B\u3064\u3044\u3066check(l,r)==true\u306B\
    \u306A\u308B\u6700\u5927\u306Er\u3068\u3068\u3082\u306B1\u5EA6\u306E\u307F\u547C\
    \u3070\u308C\u308B\nvoid doublePointerMaxRight(\n\tint left, int right, function<bool()>\
    \ check,\n\tfunction<void(int, bool)> add,\n\tfunction<void(int, bool)> del,\n\
    \tfunction<void(int, int)> update) {\n\tint r = left;\n\tfor(int l = left; l <\
    \ right; l++) {\n\t\twhile(r < right) {\n\t\t\tadd(r++, false);\n\t\t\tif(!check())\
    \ {\n\t\t\t\tr--;\n\t\t\t\tdel(r, false);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\t\
    update(l, r);\n\t\tif(l == r) {\n\t\t\tr++;\n\t\t} else {\n\t\t\tdel(l, true);\n\
    \t\t}\n\t}\n}\n"
  code: "#include \"./base.hpp\"\n/// @brief \u5C3A\u53D6\u308A\u6CD5\n\n/// @brief\
    \ \u5404l\u306B\u3064\u3044\u3066check(l,r)==true\u306B\u306A\u308B\u6700\u5C0F\
    \u306Er\u3092\u6C42\u3081\u308B\u3002\n/// @param left \u63A2\u7D22\u7BC4\u56F2\
    \u306E\u5DE6\u7AEF(inclusive)\n/// @param right \u63A2\u7D22\u7BC4\u56F2\u306E\
    \u53F3\u7AEF(exclusive)\n/// @param check ()->\u73FE\u5728\u306E\u7BC4\u56F2\u304C\
    \u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\n/// @param add (\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9,\u5DE6\u304B\u3089\u306E\u64CD\u4F5C\u304B)\n/// @param del\
    \ (\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9,\u5DE6\u304B\u3089\u306E\u64CD\u4F5C\u304B\
    )\n/// @param update \u5404l\u306B\u3064\u3044\u3066check(l,r)==true\u306B\u306A\
    \u308B\u6700\u5927\u306Er\u3068\u3068\u3082\u306B1\u5EA6\u306E\u307F\u547C\u3070\
    \u308C\u308B\nvoid doublePointerMinRight(\n\tint left, int right, function<bool()>\
    \ check,\n\tfunction<void(int, bool)> add,\n\tfunction<void(int, bool)> del,\n\
    \tfunction<void(int, int)> update) {\n\tint r = left;\n\tfor(int l = left; l <\
    \ right; l++) {\n\t\twhile(r < right && check()) {\n\t\t\tadd(r++, false);\n\t\
    \t}\n\t\tif(!check()) break;\n\t\tupdate(l, r);\n\t\tdel(l, true);\n\t}\n}\n\n\
    /// @brief \u5404l\u306B\u3064\u3044\u3066check(l,r)==true\u306B\u306A\u308B\u6700\
    \u5927\u306Er\u3092\u6C42\u3081\u308B\u3002\n/// @param left \u63A2\u7D22\u7BC4\
    \u56F2\u306E\u5DE6\u7AEF(inclusive)\n/// @param right \u63A2\u7D22\u7BC4\u56F2\
    \u306E\u53F3\u7AEF(exclusive)\n/// @param check ()->\u73FE\u5728\u306E\u7BC4\u56F2\
    \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\n/// @param add (\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9,\u5DE6\u304B\u3089\u306E\u64CD\u4F5C\u304B)\n/// @param\
    \ del (\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9,\u5DE6\u304B\u3089\u306E\u64CD\u4F5C\
    \u304B)\n/// @param update \u5404l\u306B\u3064\u3044\u3066check(l,r)==true\u306B\
    \u306A\u308B\u6700\u5927\u306Er\u3068\u3068\u3082\u306B1\u5EA6\u306E\u307F\u547C\
    \u3070\u308C\u308B\nvoid doublePointerMaxRight(\n\tint left, int right, function<bool()>\
    \ check,\n\tfunction<void(int, bool)> add,\n\tfunction<void(int, bool)> del,\n\
    \tfunction<void(int, int)> update) {\n\tint r = left;\n\tfor(int l = left; l <\
    \ right; l++) {\n\t\twhile(r < right) {\n\t\t\tadd(r++, false);\n\t\t\tif(!check())\
    \ {\n\t\t\t\tr--;\n\t\t\t\tdel(r, false);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\t\
    update(l, r);\n\t\tif(l == r) {\n\t\t\tr++;\n\t\t} else {\n\t\t\tdel(l, true);\n\
    \t\t}\n\t}\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: double_pointer.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: double_pointer.hpp
layout: document
redirect_from:
- /library/double_pointer.hpp
- /library/double_pointer.hpp.html
title: "\u5C3A\u53D6\u308A\u6CD5"
---
