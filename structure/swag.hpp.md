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
    document_title: "SWAG(\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024)"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"structure/swag.hpp\"\
    \n/// @brief SWAG(\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024)\n/// @tparam S \u8981\
    \u7D20\u306E\u578B\ntemplate<typename S>\nstruct SWAG {\nprivate:\n\tfunction<S(S,\
    \ S)> op;\n\tstruct node {\n\t\tS value, sum;\n\t\tnode(const S &value, const\
    \ S &sum)\n\t\t\t: value(value), sum(sum) {\n\t\t}\n\t};\n\tstack<node> front_t,\
    \ back_t;\n\n\tvoid move() {\n\t\tassert(!back_t.empty());\n\t\tfront_t.emplace(back_t.top().value,\n\
    \t\t\t\t\t\tback_t.top().value);\n\t\tback_t.pop();\n\t\twhile(!back_t.empty())\
    \ {\n\t\t\tfront_t.emplace(\n\t\t\t\tback_t.top().value,\n\t\t\t\top(back_t.top().value,\
    \ front_t.top().sum));\n\t\t\tback_t.pop();\n\t\t}\n\t}\n\npublic:\n\t/// @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\t/// @param op \u534A\u7FA4\u306E\
    \u6F14\u7B97\n\tSWAG(const function<S(S, S)> &op): op(op) {\n\t}\n\t/// @brief\
    \ SWAG\u306B\u8981\u7D20\u3092\u8FFD\u52A0\n\t/// @param s \u8FFD\u52A0\u3059\u308B\
    \u8981\u7D20\n\tvoid push(const S &s) {\n\t\tif(back_t.empty())\n\t\t\tback_t.emplace(s,\
    \ s);\n\t\telse\n\t\t\tback_t.emplace(s, op(s, back_t.top().sum));\n\t}\n\t///\
    \ @brief SWAG\u304B\u3089\u8981\u7D20\u3092\u524A\u9664\n\tvoid pop() {\n\t\t\
    if(front_t.empty()) {\n\t\t\tmove();\n\t\t}\n\t\tfront_t.pop();\n\t}\n\t/// @brief\
    \ SWAG\u306E\u5148\u982D\u8981\u7D20\u306B\u30A2\u30AF\u30BB\u30B9\n\t/// @return\
    \ \u5148\u982D\u8981\u7D20\u306E\u5024\n\tS front() {\n\t\tif(front_t.empty())\
    \ {\n\t\t\tmove();\n\t\t}\n\t\treturn front_t.top().value;\n\t}\n\t/// @brief\
    \ SWAG\u5185\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\n\t///\
    \ @return \u8981\u7D20\u306E\u7DCF\u7A4D\n\tS fold() const {\n\t\tassert(!empty());\n\
    \t\tif(front_t.empty()) {\n\t\t\treturn back_t.top().sum;\n\t\t} else if(back_t.empty())\
    \ {\n\t\t\treturn front_t.top().sum;\n\t\t} else {\n\t\t\treturn op(front_t.top().sum,\
    \ back_t.top().sum);\n\t\t}\n\t}\n\t/// @brief SWAG\u304C\u7A7A\u304B\u5224\u5B9A\
    \u3059\u308B\n\t/// @return SWAG\u304C\u7A7A\u306A\u3089true\n\tbool empty() const\
    \ {\n\t\treturn front_t.empty() && back_t.empty();\n\t}\n\t/// @brief SWAG\u5185\
    \u306E\u8981\u7D20\u306E\u6570\u3092\u53D6\u5F97\u3059\u308B\n\t/// @return SWAG\u5185\
    \u306E\u8981\u7D20\u306E\u6570\n\tsize_t size() {\n\t\treturn SZ(front_t) + SZ(back_t);\n\
    \t}\n\t/// @brief SWAG\u5185\u306E\u5168\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\
    \n\tvoid clear() {\n\t\tfront_t = stack<node>();\n\t\tback_t = stack<node>();\n\
    \t}\n};\n"
  code: "#include \"../base.hpp\"\n/// @brief SWAG(\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\
    \u5024)\n/// @tparam S \u8981\u7D20\u306E\u578B\ntemplate<typename S>\nstruct\
    \ SWAG {\nprivate:\n\tfunction<S(S, S)> op;\n\tstruct node {\n\t\tS value, sum;\n\
    \t\tnode(const S &value, const S &sum)\n\t\t\t: value(value), sum(sum) {\n\t\t\
    }\n\t};\n\tstack<node> front_t, back_t;\n\n\tvoid move() {\n\t\tassert(!back_t.empty());\n\
    \t\tfront_t.emplace(back_t.top().value,\n\t\t\t\t\t\tback_t.top().value);\n\t\t\
    back_t.pop();\n\t\twhile(!back_t.empty()) {\n\t\t\tfront_t.emplace(\n\t\t\t\t\
    back_t.top().value,\n\t\t\t\top(back_t.top().value, front_t.top().sum));\n\t\t\
    \tback_t.pop();\n\t\t}\n\t}\n\npublic:\n\t/// @brief \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n\t/// @param op \u534A\u7FA4\u306E\u6F14\u7B97\n\tSWAG(const function<S(S,\
    \ S)> &op): op(op) {\n\t}\n\t/// @brief SWAG\u306B\u8981\u7D20\u3092\u8FFD\u52A0\
    \n\t/// @param s \u8FFD\u52A0\u3059\u308B\u8981\u7D20\n\tvoid push(const S &s)\
    \ {\n\t\tif(back_t.empty())\n\t\t\tback_t.emplace(s, s);\n\t\telse\n\t\t\tback_t.emplace(s,\
    \ op(s, back_t.top().sum));\n\t}\n\t/// @brief SWAG\u304B\u3089\u8981\u7D20\u3092\
    \u524A\u9664\n\tvoid pop() {\n\t\tif(front_t.empty()) {\n\t\t\tmove();\n\t\t}\n\
    \t\tfront_t.pop();\n\t}\n\t/// @brief SWAG\u306E\u5148\u982D\u8981\u7D20\u306B\
    \u30A2\u30AF\u30BB\u30B9\n\t/// @return \u5148\u982D\u8981\u7D20\u306E\u5024\n\
    \tS front() {\n\t\tif(front_t.empty()) {\n\t\t\tmove();\n\t\t}\n\t\treturn front_t.top().value;\n\
    \t}\n\t/// @brief SWAG\u5185\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\n\t/// @return \u8981\u7D20\u306E\u7DCF\u7A4D\n\tS fold() const {\n\t\t\
    assert(!empty());\n\t\tif(front_t.empty()) {\n\t\t\treturn back_t.top().sum;\n\
    \t\t} else if(back_t.empty()) {\n\t\t\treturn front_t.top().sum;\n\t\t} else {\n\
    \t\t\treturn op(front_t.top().sum, back_t.top().sum);\n\t\t}\n\t}\n\t/// @brief\
    \ SWAG\u304C\u7A7A\u304B\u5224\u5B9A\u3059\u308B\n\t/// @return SWAG\u304C\u7A7A\
    \u306A\u3089true\n\tbool empty() const {\n\t\treturn front_t.empty() && back_t.empty();\n\
    \t}\n\t/// @brief SWAG\u5185\u306E\u8981\u7D20\u306E\u6570\u3092\u53D6\u5F97\u3059\
    \u308B\n\t/// @return SWAG\u5185\u306E\u8981\u7D20\u306E\u6570\n\tsize_t size()\
    \ {\n\t\treturn SZ(front_t) + SZ(back_t);\n\t}\n\t/// @brief SWAG\u5185\u306E\u5168\
    \u8981\u7D20\u3092\u524A\u9664\u3059\u308B\n\tvoid clear() {\n\t\tfront_t = stack<node>();\n\
    \t\tback_t = stack<node>();\n\t}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: structure/swag.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/swag.hpp
layout: document
redirect_from:
- /library/structure/swag.hpp
- /library/structure/swag.hpp.html
title: "SWAG(\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024)"
---
