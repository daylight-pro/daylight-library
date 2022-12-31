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
    document_title: Li Chao Segmenttree
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"structure/li_chao_segtree.hpp\"\
    \n\n/// @brief Li Chao Segmenttree\n/// @tparam T \u578B\n/// @tparam e \u5358\
    \u4F4D\u5143\ntemplate<typename T, const T e>\nclass cht {\n\tstruct line {\n\t\
    \tT a, b;\n\t\tline(T a = 0, T b = e): a(a), b(b) {\n\t\t}\n\t\tT get(T x) {\n\
    \t\t\treturn a * x + b;\n\t\t}\n\t};\n\tvector<line> V;\n\tvector<T> X;\n\tint\
    \ sz;\n\n\tvoid _add_line(line L, int k, int l, int r) {\n\t\tint m = (l + r)\
    \ / 2;\n\t\tT lx = X[l], mx = X[m], rx = X[r - 1];\n\t\tbool left = (L.get(lx)\
    \ < V[k].get(lx));\n\t\tbool mid = (L.get(mx) < V[k].get(mx));\n\t\tbool right\
    \ = (L.get(rx) < V[k].get(rx));\n\t\tif(left && right) {\n\t\t\t//\u533A\u9593\
    \u5185\u3067\u65B0\u3057\u3044\u7DDA\u306E\u307B\u3046\u304C\u5E38\u306B\u5C0F\
    \u3055\u3044\n\t\t\tV[k] = L;\n\t\t\treturn;\n\t\t}\n\t\tif(!left && !right) {\n\
    \t\t\t//\u533A\u9593\u5185\u3067\u53E4\u3044\u7DDA\u306E\u307B\u3046\u304C\u5E38\
    \u306B\u5C0F\u3055\u3044\n\t\t\treturn;\n\t\t}\n\t\tif(mid) {\n\t\t\t//\u5BFE\u79F0\
    \u6027\u3092\u5229\u7528\u3059\u308B\u305F\u3081\u306B\u3001\u5165\u308C\u66FF\
    \u3048\n\t\t\tswap(L, V[k]);\n\t\t}\n\t\tif(left != mid) {\n\t\t\t//\u533A\u9593\
    \u306E\u5DE6\u534A\u5206\u3067\u4EA4\u308F\u308B\n\t\t\t_add_line(L, 2 * k + 1,\
    \ l, m);\n\t\t} else {\n\t\t\t//\u533A\u9593\u306E\u53F3\u534A\u5206\u3067\u4EA4\
    \u308F\u308B\n\t\t\t_add_line(L, 2 * k + 2, m, r);\n\t\t}\n\t}\n\npublic:\n\t\
    /// @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\t/// @param _X \u30AF\u30A8\
    \u30EA\u306Ex\u5EA7\u6A19\u306E\u914D\u5217\n\t/// @param fill _X\u306E\u4F59\u3063\
    \u305F\u90E8\u5206\u3092\u57CB\u3081\u308B\u5024(max(_X)\u306E\u6570\u500D\u7A0B\
    \u5EA6\u3067\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\
    \u5024)\n\tcht(vector<T> const& _X, T fill): X(_X) {\n\t\tint N = SZ(X);\n\t\t\
    int N0 = 1;\n\t\tif(__builtin_popcount(N) == 1) N--;\n\t\twhile(N > 0) {\n\t\t\
    \tN >>= 1;\n\t\t\tN0 <<= 1;\n\t\t}\n\t\tsz = N0;\n\t\twhile(SZ(X) < sz) {\n\t\t\
    \tX.push_back(fill);\n\t\t}\n\t\tV.resize(sz * 2 + 1);\n\t}\n\t/// @brief f(X[k])\u306E\
    \u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\u3002\n\t/// @param k \u30AF\u30A8\u30EA\
    \u96C6\u5408\u3067\u306EX\u5EA7\u6A19\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n\t/// @return f(X[k])\u306E\u6700\u5C0F\u5024\n\tT query(int k) {\n\t\tT x =\
    \ X[k];\n\t\tk += sz - 1;\n\t\tT ret = e;\n\t\twhile(true) {\n\t\t\tchmin(ret,\
    \ V[k].get(x));\n\t\t\tif(k == 0) break;\n\t\t\tk = (k - 1) / 2;\n\t\t}\n\t\t\
    return ret;\n\t}\n\n\t/// @brief ax+b\u3068\u306A\u308B\u76F4\u7DDA\u3092\u8FFD\
    \u52A0\u3057\u307E\u3059\u3002\n\t/// @param a \u76F4\u7DDA\u306E\u50BE\u304D\n\
    \t/// @param b \u76F4\u7DDA\u306Ey\u5207\u7247\n\tvoid add_line(T a, T b) {\n\t\
    \t_add_line(line(a, b), 0, 0, sz);\n\t}\n};\n"
  code: "#include \"../base.hpp\"\n\n/// @brief Li Chao Segmenttree\n/// @tparam T\
    \ \u578B\n/// @tparam e \u5358\u4F4D\u5143\ntemplate<typename T, const T e>\n\
    class cht {\n\tstruct line {\n\t\tT a, b;\n\t\tline(T a = 0, T b = e): a(a), b(b)\
    \ {\n\t\t}\n\t\tT get(T x) {\n\t\t\treturn a * x + b;\n\t\t}\n\t};\n\tvector<line>\
    \ V;\n\tvector<T> X;\n\tint sz;\n\n\tvoid _add_line(line L, int k, int l, int\
    \ r) {\n\t\tint m = (l + r) / 2;\n\t\tT lx = X[l], mx = X[m], rx = X[r - 1];\n\
    \t\tbool left = (L.get(lx) < V[k].get(lx));\n\t\tbool mid = (L.get(mx) < V[k].get(mx));\n\
    \t\tbool right = (L.get(rx) < V[k].get(rx));\n\t\tif(left && right) {\n\t\t\t\
    //\u533A\u9593\u5185\u3067\u65B0\u3057\u3044\u7DDA\u306E\u307B\u3046\u304C\u5E38\
    \u306B\u5C0F\u3055\u3044\n\t\t\tV[k] = L;\n\t\t\treturn;\n\t\t}\n\t\tif(!left\
    \ && !right) {\n\t\t\t//\u533A\u9593\u5185\u3067\u53E4\u3044\u7DDA\u306E\u307B\
    \u3046\u304C\u5E38\u306B\u5C0F\u3055\u3044\n\t\t\treturn;\n\t\t}\n\t\tif(mid)\
    \ {\n\t\t\t//\u5BFE\u79F0\u6027\u3092\u5229\u7528\u3059\u308B\u305F\u3081\u306B\
    \u3001\u5165\u308C\u66FF\u3048\n\t\t\tswap(L, V[k]);\n\t\t}\n\t\tif(left != mid)\
    \ {\n\t\t\t//\u533A\u9593\u306E\u5DE6\u534A\u5206\u3067\u4EA4\u308F\u308B\n\t\t\
    \t_add_line(L, 2 * k + 1, l, m);\n\t\t} else {\n\t\t\t//\u533A\u9593\u306E\u53F3\
    \u534A\u5206\u3067\u4EA4\u308F\u308B\n\t\t\t_add_line(L, 2 * k + 2, m, r);\n\t\
    \t}\n\t}\n\npublic:\n\t/// @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\
    \t/// @param _X \u30AF\u30A8\u30EA\u306Ex\u5EA7\u6A19\u306E\u914D\u5217\n\t///\
    \ @param fill _X\u306E\u4F59\u3063\u305F\u90E8\u5206\u3092\u57CB\u3081\u308B\u5024\
    (max(_X)\u306E\u6570\u500D\u7A0B\u5EA6\u3067\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u3057\u306A\u3044\u5024)\n\tcht(vector<T> const& _X, T fill): X(_X)\
    \ {\n\t\tint N = SZ(X);\n\t\tint N0 = 1;\n\t\tif(__builtin_popcount(N) == 1) N--;\n\
    \t\twhile(N > 0) {\n\t\t\tN >>= 1;\n\t\t\tN0 <<= 1;\n\t\t}\n\t\tsz = N0;\n\t\t\
    while(SZ(X) < sz) {\n\t\t\tX.push_back(fill);\n\t\t}\n\t\tV.resize(sz * 2 + 1);\n\
    \t}\n\t/// @brief f(X[k])\u306E\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\u3002\
    \n\t/// @param k \u30AF\u30A8\u30EA\u96C6\u5408\u3067\u306EX\u5EA7\u6A19\u306E\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n\t/// @return f(X[k])\u306E\u6700\u5C0F\u5024\
    \n\tT query(int k) {\n\t\tT x = X[k];\n\t\tk += sz - 1;\n\t\tT ret = e;\n\t\t\
    while(true) {\n\t\t\tchmin(ret, V[k].get(x));\n\t\t\tif(k == 0) break;\n\t\t\t\
    k = (k - 1) / 2;\n\t\t}\n\t\treturn ret;\n\t}\n\n\t/// @brief ax+b\u3068\u306A\
    \u308B\u76F4\u7DDA\u3092\u8FFD\u52A0\u3057\u307E\u3059\u3002\n\t/// @param a \u76F4\
    \u7DDA\u306E\u50BE\u304D\n\t/// @param b \u76F4\u7DDA\u306Ey\u5207\u7247\n\tvoid\
    \ add_line(T a, T b) {\n\t\t_add_line(line(a, b), 0, 0, sz);\n\t}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: structure/li_chao_segtree.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/li_chao_segtree.hpp
layout: document
redirect_from:
- /library/structure/li_chao_segtree.hpp
- /library/structure/li_chao_segtree.hpp.html
title: Li Chao Segmenttree
---
