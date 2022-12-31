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
    document_title: "\u6709\u7406\u6570\u30E9\u30A4\u30D6\u30E9\u30EA"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"math/rational.hpp\"\
    \n\n/// @brief \u6709\u7406\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\n\ntemplate<typename\
    \ S = __int128_t, bool doReduction = true>\nstruct Rational {\nprivate:\n\tS child,\
    \ parent;\n\tS originalChild, originalParent;\n\tusing R = Rational<S, doReduction>;\n\
    \npublic:\n\tRational() {\n\t\tR(0, 1);\n\t}\n\t/// @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n\t/// @param c \u5206\u5B50\n\t/// @param p \u5206\u6BCD\n\
    \tRational(S c, S p) {\n\t\tassert(p != 0);\n\t\toriginalChild = c;\n\t\toriginalParent\
    \ = p;\n\t\tif(c == 0) {\n\t\t\tchild = 0;\n\t\t\tparent = 1;\n\t\t} else if(!doReduction)\
    \ {\n\t\t\tchild = c;\n\t\t\tparent = p;\n\t\t} else {\n\t\t\tS g = gcd(abs(c),\
    \ abs(p));\n\t\t\tc /= g;\n\t\t\tp /= g;\n\t\t\tc *= p / abs(p);\n\t\t\tchild\
    \ = c;\n\t\t\tparent = abs(p);\n\t\t}\n\t}\n\tR operator+(const R& r) const {\n\
    \t\tS new_p = parent * r.parent;\n\t\tS new_c = child * new_p / parent\n\t\t\t\
    + r.child * new_p / r.parent;\n\t\treturn R(new_c, new_p);\n\t}\n\tR operator-(const\
    \ R& r) const {\n\t\tS new_p = parent * r.parent;\n\t\tS new_c = child * new_p\
    \ / parent\n\t\t\t- r.child * new_p / r.parent;\n\t\treturn R(new_c, new_p);\n\
    \t}\n\tR operator*(const R& r) const {\n\t\treturn R(child * r.child, parent *\
    \ r.parent);\n\t}\n\tR operator/(const R& r) const {\n\t\treturn R(child * r.parent,\
    \ parent * r.child);\n\t}\n\tbool operator==(const R& r) const {\n\t\treturn child\
    \ == r.child && parent == r.parent;\n\t}\n\tbool operator!=(const R& r) const\
    \ {\n\t\treturn child != r.child || parent != r.parent;\n\t}\n\tbool operator<(const\
    \ R& r) const {\n\t\treturn child * r.parent < parent * r.child;\n\t}\n\tbool\
    \ operator>(const R& r) const {\n\t\treturn child * r.parent > parent * r.child;\n\
    \t}\n\tbool operator<=(const R& r) const {\n\t\treturn !(*this > r);\n\t}\n\t\
    bool operator>=(const R& r) const {\n\t\treturn !(*this < r);\n\t}\n\tR inv()\
    \ const {\n\t\treturn R(parent, child);\n\t}\n\tll getChild() const {\n\t\treturn\
    \ ll(child);\n\t}\n\tll getParent() const {\n\t\treturn ll(parent);\n\t}\n\tll\
    \ getOriginalChild() const {\n\t\treturn originalChild;\n\t}\n\tll getOriginalParent()\
    \ const {\n\t\treturn originalParent;\n\t}\n\t/// @brief \u5206\u6570\u3092\u5C11\
    \u6570\u306B\u5909\u63DB\u3059\u308B\n\t/// @return \u5206\u6570\u306E\u8868\u3059\
    \u5C11\u6570\n\tdouble getDouble() {\n\t\treturn double(child) / parent;\n\t}\n\
    };\n"
  code: "#include \"../base.hpp\"\n\n/// @brief \u6709\u7406\u6570\u30E9\u30A4\u30D6\
    \u30E9\u30EA\n\ntemplate<typename S = __int128_t, bool doReduction = true>\nstruct\
    \ Rational {\nprivate:\n\tS child, parent;\n\tS originalChild, originalParent;\n\
    \tusing R = Rational<S, doReduction>;\n\npublic:\n\tRational() {\n\t\tR(0, 1);\n\
    \t}\n\t/// @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\t/// @param c \u5206\
    \u5B50\n\t/// @param p \u5206\u6BCD\n\tRational(S c, S p) {\n\t\tassert(p != 0);\n\
    \t\toriginalChild = c;\n\t\toriginalParent = p;\n\t\tif(c == 0) {\n\t\t\tchild\
    \ = 0;\n\t\t\tparent = 1;\n\t\t} else if(!doReduction) {\n\t\t\tchild = c;\n\t\
    \t\tparent = p;\n\t\t} else {\n\t\t\tS g = gcd(abs(c), abs(p));\n\t\t\tc /= g;\n\
    \t\t\tp /= g;\n\t\t\tc *= p / abs(p);\n\t\t\tchild = c;\n\t\t\tparent = abs(p);\n\
    \t\t}\n\t}\n\tR operator+(const R& r) const {\n\t\tS new_p = parent * r.parent;\n\
    \t\tS new_c = child * new_p / parent\n\t\t\t+ r.child * new_p / r.parent;\n\t\t\
    return R(new_c, new_p);\n\t}\n\tR operator-(const R& r) const {\n\t\tS new_p =\
    \ parent * r.parent;\n\t\tS new_c = child * new_p / parent\n\t\t\t- r.child *\
    \ new_p / r.parent;\n\t\treturn R(new_c, new_p);\n\t}\n\tR operator*(const R&\
    \ r) const {\n\t\treturn R(child * r.child, parent * r.parent);\n\t}\n\tR operator/(const\
    \ R& r) const {\n\t\treturn R(child * r.parent, parent * r.child);\n\t}\n\tbool\
    \ operator==(const R& r) const {\n\t\treturn child == r.child && parent == r.parent;\n\
    \t}\n\tbool operator!=(const R& r) const {\n\t\treturn child != r.child || parent\
    \ != r.parent;\n\t}\n\tbool operator<(const R& r) const {\n\t\treturn child *\
    \ r.parent < parent * r.child;\n\t}\n\tbool operator>(const R& r) const {\n\t\t\
    return child * r.parent > parent * r.child;\n\t}\n\tbool operator<=(const R& r)\
    \ const {\n\t\treturn !(*this > r);\n\t}\n\tbool operator>=(const R& r) const\
    \ {\n\t\treturn !(*this < r);\n\t}\n\tR inv() const {\n\t\treturn R(parent, child);\n\
    \t}\n\tll getChild() const {\n\t\treturn ll(child);\n\t}\n\tll getParent() const\
    \ {\n\t\treturn ll(parent);\n\t}\n\tll getOriginalChild() const {\n\t\treturn\
    \ originalChild;\n\t}\n\tll getOriginalParent() const {\n\t\treturn originalParent;\n\
    \t}\n\t/// @brief \u5206\u6570\u3092\u5C11\u6570\u306B\u5909\u63DB\u3059\u308B\
    \n\t/// @return \u5206\u6570\u306E\u8868\u3059\u5C11\u6570\n\tdouble getDouble()\
    \ {\n\t\treturn double(child) / parent;\n\t}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/rational.hpp
  requiredBy:
  - math/all.hpp
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/rational.hpp
layout: document
redirect_from:
- /library/math/rational.hpp
- /library/math/rational.hpp.html
title: "\u6709\u7406\u6570\u30E9\u30A4\u30D6\u30E9\u30EA"
---
