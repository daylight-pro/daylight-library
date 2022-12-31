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
    document_title: "\u30AD\u30E5\u30FC\u306B\u8981\u7D20v\u3092\u8FFD\u52A0\u3059\
      \u308B"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"structure/deletable_priority_queue.hpp\"\
    \n\ntemplate<typename T, typename vec = vector<T>,\n\t\t typename cmp = less<typename\
    \ vec::value_type>>\nstruct deletable_priority_queue {\nprivate:\n\tmap<T, T>\
    \ M;\n\tpriority_queue<T, vec, cmp> Q;\n\tint sz;\n\npublic:\n\tdeletable_priority_queue()\
    \ {\n\t\tsz = 0;\n\t}\n\t/// @brief \u30AD\u30E5\u30FC\u306B\u8981\u7D20v\u3092\
    \u8FFD\u52A0\u3059\u308B\n\t/// @param v \u8FFD\u52A0\u3059\u308B\u8981\u7D20\n\
    \tvoid push(T v) {\n\t\tQ.push(v);\n\t\tM[v]++;\n\t\tsz++;\n\t}\n\t/// @brief\
    \ \u30AD\u30E5\u30FC\u304B\u3089\u8981\u7D20v\u3092\u524A\u9664\u3059\u308B\n\t\
    /// @param v \u524A\u9664\u3059\u308B\u8981\u7D20\n\t/// @return \u524A\u9664\u304C\
    \u6210\u529F\u3057\u305F\u304B\u3069\u3046\u304B\n\tbool del(T v) {\n\t\tif(M[v]\
    \ == 0) return false;\n\t\tM[v]--;\n\t\tsz--;\n\t\twhile(!Q.empty() && M[Q.top()]\
    \ == 0) {\n\t\t\tQ.pop();\n\t\t}\n\t\treturn true;\n\t}\n\t/// @brief \u30AD\u30E5\
    \u30FC\u306E\u6700\u5927\u5143\u3092\u53D6\u308A\u51FA\u3059\n\t/// @return \u30AD\
    \u30E5\u30FC\u306E\u6700\u5927\u5143\n\tT top() {\n\t\treturn Q.top();\n\t}\n\t\
    /// @brief \u30AD\u30E5\u30FC\u306E\u6700\u5927\u5143\u3092\u524A\u9664\u3059\u308B\
    \n\tvoid pop() {\n\t\twhile(M[Q.top()] == 0) {\n\t\t\tQ.pop();\n\t\t}\n\t\tM[Q.top()]--;\n\
    \t\tsz--;\n\t\tQ.pop();\n\t\twhile(!Q.empty() && M[Q.top()] == 0) {\n\t\t\tQ.pop();\n\
    \t\t}\n\t}\n\t/// @brief \u30AD\u30E5\u30FC\u304C\u8981\u7D20v\u3092\u542B\u3080\
    \u304B\u3092\u5224\u5B9A\u3059\u308B\n\t/// @param v \u30AD\u30E5\u30FC\u304C\u542B\
    \u3080\u304B\u3092\u5224\u5B9A\u3059\u308B\u8981\u7D20\n\t/// @return \u30AD\u30E5\
    \u30FC\u304Cv\u3092\u542B\u3080\u304B\u3069\u3046\u304B\n\tbool contains(T v)\
    \ {\n\t\treturn M[v] > 0;\n\t}\n\t/// @brief \u30AD\u30E5\u30FC\u306E\u8981\u7D20\
    \u6570\u3092\u53D6\u5F97\u3059\u308B\n\t/// @return \u30AD\u30E5\u30FC\u306E\u8981\
    \u7D20\u6570\n\tsize_t size() {\n\t\treturn (size_t) sz;\n\t}\n};\n"
  code: "#include \"../base.hpp\"\n\ntemplate<typename T, typename vec = vector<T>,\n\
    \t\t typename cmp = less<typename vec::value_type>>\nstruct deletable_priority_queue\
    \ {\nprivate:\n\tmap<T, T> M;\n\tpriority_queue<T, vec, cmp> Q;\n\tint sz;\n\n\
    public:\n\tdeletable_priority_queue() {\n\t\tsz = 0;\n\t}\n\t/// @brief \u30AD\
    \u30E5\u30FC\u306B\u8981\u7D20v\u3092\u8FFD\u52A0\u3059\u308B\n\t/// @param v\
    \ \u8FFD\u52A0\u3059\u308B\u8981\u7D20\n\tvoid push(T v) {\n\t\tQ.push(v);\n\t\
    \tM[v]++;\n\t\tsz++;\n\t}\n\t/// @brief \u30AD\u30E5\u30FC\u304B\u3089\u8981\u7D20\
    v\u3092\u524A\u9664\u3059\u308B\n\t/// @param v \u524A\u9664\u3059\u308B\u8981\
    \u7D20\n\t/// @return \u524A\u9664\u304C\u6210\u529F\u3057\u305F\u304B\u3069\u3046\
    \u304B\n\tbool del(T v) {\n\t\tif(M[v] == 0) return false;\n\t\tM[v]--;\n\t\t\
    sz--;\n\t\twhile(!Q.empty() && M[Q.top()] == 0) {\n\t\t\tQ.pop();\n\t\t}\n\t\t\
    return true;\n\t}\n\t/// @brief \u30AD\u30E5\u30FC\u306E\u6700\u5927\u5143\u3092\
    \u53D6\u308A\u51FA\u3059\n\t/// @return \u30AD\u30E5\u30FC\u306E\u6700\u5927\u5143\
    \n\tT top() {\n\t\treturn Q.top();\n\t}\n\t/// @brief \u30AD\u30E5\u30FC\u306E\
    \u6700\u5927\u5143\u3092\u524A\u9664\u3059\u308B\n\tvoid pop() {\n\t\twhile(M[Q.top()]\
    \ == 0) {\n\t\t\tQ.pop();\n\t\t}\n\t\tM[Q.top()]--;\n\t\tsz--;\n\t\tQ.pop();\n\
    \t\twhile(!Q.empty() && M[Q.top()] == 0) {\n\t\t\tQ.pop();\n\t\t}\n\t}\n\t///\
    \ @brief \u30AD\u30E5\u30FC\u304C\u8981\u7D20v\u3092\u542B\u3080\u304B\u3092\u5224\
    \u5B9A\u3059\u308B\n\t/// @param v \u30AD\u30E5\u30FC\u304C\u542B\u3080\u304B\u3092\
    \u5224\u5B9A\u3059\u308B\u8981\u7D20\n\t/// @return \u30AD\u30E5\u30FC\u304Cv\u3092\
    \u542B\u3080\u304B\u3069\u3046\u304B\n\tbool contains(T v) {\n\t\treturn M[v]\
    \ > 0;\n\t}\n\t/// @brief \u30AD\u30E5\u30FC\u306E\u8981\u7D20\u6570\u3092\u53D6\
    \u5F97\u3059\u308B\n\t/// @return \u30AD\u30E5\u30FC\u306E\u8981\u7D20\u6570\n\
    \tsize_t size() {\n\t\treturn (size_t) sz;\n\t}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: structure/deletable_priority_queue.hpp
  requiredBy: []
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/deletable_priority_queue.hpp
layout: document
redirect_from:
- /library/structure/deletable_priority_queue.hpp
- /library/structure/deletable_priority_queue.hpp.html
title: "\u30AD\u30E5\u30FC\u306B\u8981\u7D20v\u3092\u8FFD\u52A0\u3059\u308B"
---
