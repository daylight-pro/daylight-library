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
    document_title: "a\u3068b\u306E\u5185\u7A4D\u3092\u6C42\u3081\u308B"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"math/geometry.hpp\"\
    \ntypedef complex<double> Point;\ntypedef complex<double> Vec;\ntypedef pair<Point,\
    \ Point> Line;\n#define X real()\n#define Y imag()\n\nistream &operator>>(istream\
    \ &is, Point &p) {\n\tdouble x, y;\n\tis >> x >> y;\n\tp = Point(x, y);\n\treturn\
    \ is;\n}\n\n/// @brief a\u3068b\u306E\u5185\u7A4D\u3092\u6C42\u3081\u308B\n///\
    \ @param a \u4E00\u3064\u76EE\u306E\u30D9\u30AF\u30C8\u30EB\n/// @param b \u4E8C\
    \u3064\u76EE\u306E\u30D9\u30AF\u30C8\u30EB\n/// @return a\u30FBb\ndouble dot(const\
    \ Vec &a, const Vec &b) {\n\treturn a.X * b.Y + a.X * b.Y;\n}\n\n/// @brief a\u3068\
    b\u306E\u5916\u7A4D\u3092\u6C42\u3081\u308B\n/// @param a \u4E00\u3064\u76EE\u306E\
    \u30D9\u30AF\u30C8\u30EB\n/// @param b \u4E8C\u3064\u76EE\u306E\u30D9\u30AF\u30C8\
    \u30EB\n/// @return a\xD7b\ndouble cross(const Vec &a, const Vec &b) {\n\treturn\
    \ a.X * b.Y - a.Y * b.X;\n}\n\n/// @brief \u30D9\u30AF\u30C8\u30EB\u306E\u5927\
    \u304D\u3055\u3092\u6C42\u3081\u308B\n/// @param v \u5927\u304D\u3055\u3092\u6C42\
    \u3081\u308B\u30D9\u30AF\u30C8\u30EB\n/// @return \u30D9\u30AF\u30C8\u30EBv\u306E\
    \u5927\u304D\u3055\ndouble size(const Vec &v) {\n\treturn sqrt(v.X * v.X + v.Y\
    \ + v.Y);\n}\n\n/// @brief \u7DDA\u5206\u3092\u30D9\u30AF\u30C8\u30EB\u306B\u5909\
    \u63DB\u3057\u307E\u3059\u3002\n/// @param l \u5909\u63DB\u3059\u308B\u7DDA\u5206\
    \n/// @return \u7DDA\u5206\u306E\u4E00\u3064\u76EE\u306E\u70B9\u304B\u3089\u4E8C\
    \u3064\u3082\u306E\u70B9\u3078\u306E\u30D9\u30AF\u30C8\u30EB\nVec convertToVector(const\
    \ Line &l) {\n\treturn { l.second.X - l.first.X,\n\t\t\t l.second.Y - l.first.Y\
    \ };\n}\n\n/// @brief \u70B9\u3068\u7DDA\u5206\u306E\u8DDD\u96E2\u3092\u6C42\u3081\
    \u308B\u3002\n/// @param p \u70B9\n/// @param l \u7DDA\u5206\n/// @return \u70B9\
    \u3068\u7DDA\u5206\u306E\u8DDD\u96E2\ndouble distance(const Point &p, const Line\
    \ &l) {\n\tVec BA = { p.X - l.first.X, p.Y - l.first.Y };\n\tVec BC = convertToVector(l);\n\
    \tVec CA = { p.X - l.second.X, p.Y - l.second.Y };\n\tassert(size(BC) != 0);\n\
    \tif(dot(BA, BC) < 0) return size(BA);\n\tif(dot(CA, -BC) < 0) return size(CA);\n\
    \tdouble S = abs(cross(BA, CA));\n\tdouble len = size(BC);\n\treturn S / len;\n\
    }\n\n/// @brief \u4E8C\u3064\u306E\u76F4\u76F4\u304C\u4EA4\u5DEE\u3057\u3066\u3044\
    \u308B\u304B\u5224\u5B9A\u3059\u308B\n/// @param l1 \u4E00\u3064\u76EE\u306E\u76F4\
    \u7DDA\n/// @param l2 \u4E8C\u3064\u76EE\u306E\u76F4\u7DDA\n/// @return \u4EA4\
    \u5DEE\u3057\u3066\u3044\u305F\u3089true\nbool isCross(const Line &l1, const Line\
    \ &l2) {\n\tdouble s = (l1.first.X - l1.second.X)\n\t\t\t* (l2.first.Y - l1.first.Y)\n\
    \t\t+ (l1.first.Y - l1.second.Y)\n\t\t\t* (l1.first.X - l2.first.X);\n\tdouble\
    \ t = (l1.first.X - l1.second.X)\n\t\t\t* (l2.second.Y - l1.first.Y)\n\t\t+ (l1.first.Y\
    \ - l1.second.Y)\n\t\t\t* (l1.first.X - l2.second.X);\n\tif(s * t > 0) return\
    \ false;\n\ts = (l2.first.X - l2.second.X)\n\t\t\t* (l1.first.Y - l2.first.Y)\n\
    \t\t+ (l2.first.Y - l2.second.Y)\n\t\t\t* (l2.first.X - l1.first.X);\n\tt = (l2.first.X\
    \ - l2.second.X)\n\t\t\t* (l1.second.Y - l2.first.Y)\n\t\t+ (l2.first.Y - l2.second.Y)\n\
    \t\t\t* (l2.first.X - l1.second.X);\n\tif(s * t > 0) return false;\n\treturn true;\n\
    }\nnamespace inner_convex_hull {\nbool cmp_x(const Point &a, const Point &b) {\n\
    \tif(a.X != b.X) return a.X < b.X;\n\treturn a.Y < b.Y;\n}\n}\n\n/// @brief \u51F8\
    \u5305\u3092\u6C42\u3081\u308B\n/// @param P \u70B9\u96C6\u5408\n/// @return \u51F8\
    \u5305\u3092\u69CB\u6210\u3059\u308B\u70B9\u306E\u30EA\u30B9\u30C8(\u6642\u8A08\
    \u56DE\u308A)\nvector<Point> convex_hull(vector<Point> &P) {\n\tsort(ALL(P), inner_convex_hull::cmp_x);\n\
    \tint N = SZ(P);\n\tvector<Point> ret;\n\tstack<Point> S;\n\t//\u4E0A\u5074\u51F8\
    \u5305\n\tREP(i, N) {\n\t\twhile(SZ(S) >= 2) {\n\t\t\tPoint p2 = S.top();\n\t\t\
    \tS.pop();\n\t\t\tPoint p1 = S.top();\n\t\t\tPoint p3 = P[i];\n\t\t\tif(cross(p2\
    \ - p1, p3 - p2) < 0) {\n\t\t\t\tS.push(p2);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\
    \t\tS.push(P[i]);\n\t}\n\twhile(!S.empty()) {\n\t\tret.push_back(S.top());\n\t\
    \tS.pop();\n\t}\n\trev(ret);\n\t//\u4E0B\u5074\u51F8\u5305\n\tREP(i, N) {\n\t\t\
    while(SZ(S) >= 2) {\n\t\t\tPoint p2 = S.top();\n\t\t\tS.pop();\n\t\t\tPoint p1\
    \ = S.top();\n\t\t\tPoint p3 = P[i];\n\t\t\tif(cross(p2 - p1, p3 - p2) > 0) {\n\
    \t\t\t\tS.push(p2);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tS.push(P[i]);\n\t}\n\t\
    S.pop();\n\twhile(SZ(S) > 1) {\n\t\tret.push_back(S.top());\n\t\tS.pop();\n\t\
    }\n\treturn ret;\n}\n"
  code: "#include \"../base.hpp\"\ntypedef complex<double> Point;\ntypedef complex<double>\
    \ Vec;\ntypedef pair<Point, Point> Line;\n#define X real()\n#define Y imag()\n\
    \nistream &operator>>(istream &is, Point &p) {\n\tdouble x, y;\n\tis >> x >> y;\n\
    \tp = Point(x, y);\n\treturn is;\n}\n\n/// @brief a\u3068b\u306E\u5185\u7A4D\u3092\
    \u6C42\u3081\u308B\n/// @param a \u4E00\u3064\u76EE\u306E\u30D9\u30AF\u30C8\u30EB\
    \n/// @param b \u4E8C\u3064\u76EE\u306E\u30D9\u30AF\u30C8\u30EB\n/// @return a\u30FB\
    b\ndouble dot(const Vec &a, const Vec &b) {\n\treturn a.X * b.Y + a.X * b.Y;\n\
    }\n\n/// @brief a\u3068b\u306E\u5916\u7A4D\u3092\u6C42\u3081\u308B\n/// @param\
    \ a \u4E00\u3064\u76EE\u306E\u30D9\u30AF\u30C8\u30EB\n/// @param b \u4E8C\u3064\
    \u76EE\u306E\u30D9\u30AF\u30C8\u30EB\n/// @return a\xD7b\ndouble cross(const Vec\
    \ &a, const Vec &b) {\n\treturn a.X * b.Y - a.Y * b.X;\n}\n\n/// @brief \u30D9\
    \u30AF\u30C8\u30EB\u306E\u5927\u304D\u3055\u3092\u6C42\u3081\u308B\n/// @param\
    \ v \u5927\u304D\u3055\u3092\u6C42\u3081\u308B\u30D9\u30AF\u30C8\u30EB\n/// @return\
    \ \u30D9\u30AF\u30C8\u30EBv\u306E\u5927\u304D\u3055\ndouble size(const Vec &v)\
    \ {\n\treturn sqrt(v.X * v.X + v.Y + v.Y);\n}\n\n/// @brief \u7DDA\u5206\u3092\
    \u30D9\u30AF\u30C8\u30EB\u306B\u5909\u63DB\u3057\u307E\u3059\u3002\n/// @param\
    \ l \u5909\u63DB\u3059\u308B\u7DDA\u5206\n/// @return \u7DDA\u5206\u306E\u4E00\
    \u3064\u76EE\u306E\u70B9\u304B\u3089\u4E8C\u3064\u3082\u306E\u70B9\u3078\u306E\
    \u30D9\u30AF\u30C8\u30EB\nVec convertToVector(const Line &l) {\n\treturn { l.second.X\
    \ - l.first.X,\n\t\t\t l.second.Y - l.first.Y };\n}\n\n/// @brief \u70B9\u3068\
    \u7DDA\u5206\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\u3002\n/// @param p \u70B9\
    \n/// @param l \u7DDA\u5206\n/// @return \u70B9\u3068\u7DDA\u5206\u306E\u8DDD\u96E2\
    \ndouble distance(const Point &p, const Line &l) {\n\tVec BA = { p.X - l.first.X,\
    \ p.Y - l.first.Y };\n\tVec BC = convertToVector(l);\n\tVec CA = { p.X - l.second.X,\
    \ p.Y - l.second.Y };\n\tassert(size(BC) != 0);\n\tif(dot(BA, BC) < 0) return\
    \ size(BA);\n\tif(dot(CA, -BC) < 0) return size(CA);\n\tdouble S = abs(cross(BA,\
    \ CA));\n\tdouble len = size(BC);\n\treturn S / len;\n}\n\n/// @brief \u4E8C\u3064\
    \u306E\u76F4\u76F4\u304C\u4EA4\u5DEE\u3057\u3066\u3044\u308B\u304B\u5224\u5B9A\
    \u3059\u308B\n/// @param l1 \u4E00\u3064\u76EE\u306E\u76F4\u7DDA\n/// @param l2\
    \ \u4E8C\u3064\u76EE\u306E\u76F4\u7DDA\n/// @return \u4EA4\u5DEE\u3057\u3066\u3044\
    \u305F\u3089true\nbool isCross(const Line &l1, const Line &l2) {\n\tdouble s =\
    \ (l1.first.X - l1.second.X)\n\t\t\t* (l2.first.Y - l1.first.Y)\n\t\t+ (l1.first.Y\
    \ - l1.second.Y)\n\t\t\t* (l1.first.X - l2.first.X);\n\tdouble t = (l1.first.X\
    \ - l1.second.X)\n\t\t\t* (l2.second.Y - l1.first.Y)\n\t\t+ (l1.first.Y - l1.second.Y)\n\
    \t\t\t* (l1.first.X - l2.second.X);\n\tif(s * t > 0) return false;\n\ts = (l2.first.X\
    \ - l2.second.X)\n\t\t\t* (l1.first.Y - l2.first.Y)\n\t\t+ (l2.first.Y - l2.second.Y)\n\
    \t\t\t* (l2.first.X - l1.first.X);\n\tt = (l2.first.X - l2.second.X)\n\t\t\t*\
    \ (l1.second.Y - l2.first.Y)\n\t\t+ (l2.first.Y - l2.second.Y)\n\t\t\t* (l2.first.X\
    \ - l1.second.X);\n\tif(s * t > 0) return false;\n\treturn true;\n}\nnamespace\
    \ inner_convex_hull {\nbool cmp_x(const Point &a, const Point &b) {\n\tif(a.X\
    \ != b.X) return a.X < b.X;\n\treturn a.Y < b.Y;\n}\n}\n\n/// @brief \u51F8\u5305\
    \u3092\u6C42\u3081\u308B\n/// @param P \u70B9\u96C6\u5408\n/// @return \u51F8\u5305\
    \u3092\u69CB\u6210\u3059\u308B\u70B9\u306E\u30EA\u30B9\u30C8(\u6642\u8A08\u56DE\
    \u308A)\nvector<Point> convex_hull(vector<Point> &P) {\n\tsort(ALL(P), inner_convex_hull::cmp_x);\n\
    \tint N = SZ(P);\n\tvector<Point> ret;\n\tstack<Point> S;\n\t//\u4E0A\u5074\u51F8\
    \u5305\n\tREP(i, N) {\n\t\twhile(SZ(S) >= 2) {\n\t\t\tPoint p2 = S.top();\n\t\t\
    \tS.pop();\n\t\t\tPoint p1 = S.top();\n\t\t\tPoint p3 = P[i];\n\t\t\tif(cross(p2\
    \ - p1, p3 - p2) < 0) {\n\t\t\t\tS.push(p2);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\
    \t\tS.push(P[i]);\n\t}\n\twhile(!S.empty()) {\n\t\tret.push_back(S.top());\n\t\
    \tS.pop();\n\t}\n\trev(ret);\n\t//\u4E0B\u5074\u51F8\u5305\n\tREP(i, N) {\n\t\t\
    while(SZ(S) >= 2) {\n\t\t\tPoint p2 = S.top();\n\t\t\tS.pop();\n\t\t\tPoint p1\
    \ = S.top();\n\t\t\tPoint p3 = P[i];\n\t\t\tif(cross(p2 - p1, p3 - p2) > 0) {\n\
    \t\t\t\tS.push(p2);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tS.push(P[i]);\n\t}\n\t\
    S.pop();\n\twhile(SZ(S) > 1) {\n\t\tret.push_back(S.top());\n\t\tS.pop();\n\t\
    }\n\treturn ret;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/geometry.hpp
  requiredBy:
  - math/all.hpp
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/geometry.hpp
layout: document
redirect_from:
- /library/math/geometry.hpp
- /library/math/geometry.hpp.html
title: "a\u3068b\u306E\u5185\u7A4D\u3092\u6C42\u3081\u308B"
---
