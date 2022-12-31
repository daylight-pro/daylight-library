---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':warning:'
    path: atcoder/dsu.hpp
    title: atcoder/dsu.hpp
  - icon: ':warning:'
    path: atcoder/fenwicktree.hpp
    title: atcoder/fenwicktree.hpp
  - icon: ':warning:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':warning:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':warning:'
    path: atcoder/internal_queue.hpp
    title: atcoder/internal_queue.hpp
  - icon: ':warning:'
    path: atcoder/internal_scc.hpp
    title: atcoder/internal_scc.hpp
  - icon: ':warning:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':warning:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':warning:'
    path: atcoder/math.hpp
    title: atcoder/math.hpp
  - icon: ':warning:'
    path: atcoder/maxflow.hpp
    title: atcoder/maxflow.hpp
  - icon: ':warning:'
    path: atcoder/mincostflow.hpp
    title: atcoder/mincostflow.hpp
  - icon: ':warning:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':warning:'
    path: atcoder/scc.hpp
    title: atcoder/scc.hpp
  - icon: ':warning:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':warning:'
    path: atcoder/string.hpp
    title: atcoder/string.hpp
  - icon: ':warning:'
    path: atcoder/twosat.hpp
    title: atcoder/twosat.hpp
  - icon: ':warning:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7DE8\u96C6\u53EF\u80FD\u30D7\u30E9\u30A4\u30AA\u30EA\u30C6\u30A3\
      \u30FC\u30AD\u30E5\u30FC"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 1 \"atcoder/all\"\n\
    #include <atcoder/convolution>\n#include <atcoder/dsu>\n#include <atcoder/fenwicktree>\n\
    #include <atcoder/lazysegtree>\n#include <atcoder/math>\n#include <atcoder/maxflow>\n\
    #include <atcoder/mincostflow>\n#include <atcoder/modint>\n#include <atcoder/scc>\n\
    #include <atcoder/segtree>\n#include <atcoder/string>\n#include <atcoder/twosat>\n\
    #line 3 \"structure/editable_priority_queue.hpp\"\nusing namespace atcoder;\n\n\
    namespace inner_editable_pq {\npair<ll, int> op(pair<ll, int> a, pair<ll, int>\
    \ b) {\n\treturn min(a, b);\n}\npair<ll, int> e() {\n\treturn { LINF, -1 };\n\
    }\n}\n/// @brief \u7DE8\u96C6\u53EF\u80FD\u30D7\u30E9\u30A4\u30AA\u30EA\u30C6\u30A3\
    \u30FC\u30AD\u30E5\u30FC\nstruct editable_priority_queue {\nprivate:\n\tsegtree<pair<ll,\
    \ int>, inner_editable_pq::op,\n\t\t\tinner_editable_pq::e>\n\t\tseg;\n\tint sz;\n\
    \tint N;\n\npublic:\n\teditable_priority_queue(vll& v) {\n\t\tsz = SZ(v);\n\t\t\
    N = SZ(v);\n\t\tvector<pair<ll, int>> V;\n\t\tREP(i, N) {\n\t\t\tif(v[i] == inner_editable_pq::e().first)\
    \ {\n\t\t\t\tV.emplace_back(v[i], -1);\n\t\t\t} else {\n\t\t\t\tV.emplace_back(v[i],\
    \ i);\n\t\t\t}\n\t\t}\n\t\tseg = segtree<pair<ll, int>, inner_editable_pq::op,\n\
    \t\t\t\t\t  inner_editable_pq::e>(V);\n\t}\n\t/// @brief \u914D\u5217\u306Ei\u756A\
    \u76EE\u306E\u5024\u306B\u30A2\u30AF\u30BB\u30B9\u3059\u308B\n\t/// @param i \u30A2\
    \u30AF\u30BB\u30B9\u3059\u308B\u914D\u5217\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9(0-indexed)\n\t/// @return \u914D\u5217\u306Ei\u756A\u76EE\u306E\u5024\n\
    \tll get(int i) {\n\t\tauto [a, b] = seg.get(i);\n\t\treturn a;\n\t}\n\t/// @brief\
    \ \u914D\u5217\u306Ei\u756A\u76EE\u306E\u5024\u3092x\u306B\u5909\u66F4\u3059\u308B\
    \n\t/// @param i \u5909\u66F4\u3059\u308B\u914D\u5217\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9(0-indexed)\n\t/// @param x \u5909\u66F4\u5F8C\u306E\u5024\n\tvoid\
    \ set(int i, ll x) {\n\t\tauto [a, b] = seg.get(i);\n\t\tif(b == -1) sz++;\n\t\
    \tif(x == inner_editable_pq::e().first) {\n\t\t\tseg.set(i, { x, -1 });\n\t\t\t\
    sz--;\n\t\t} else {\n\t\t\tseg.set(i, { x, i });\n\t\t}\n\t}\n\t/// @brief \u914D\
    \u5217\u306E[0,size)\u306E\u4E2D\u3067\u6700\u5C0F\u306E\u5024\u6C42\u3081\u308B\
    (\u540C\u7387\u306E\u5834\u5408\u306F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u6700\
    \u5C0F)\n\t/// @return {\u6700\u5C0F\u306E\u8981\u7D20,\u6700\u5C0F\u8981\u7D20\
    \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9}\n\tpair<ll, int> top() {\n\t\treturn\
    \ top(0, N);\n\t}\n\t/// @brief \u914D\u5217\u306E[0,r)\u306E\u4E2D\u3067\u6700\
    \u5C0F\u306E\u5024\u6C42\u3081\u308B(\u540C\u7387\u306E\u5834\u5408\u306F\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u6700\u5C0F)\n\t/// @param r \u63A2\u7D22\u7BC4\
    \u56F2\u306E\u53F3\u7AEF(exclusive)\n\t/// @return {\u6700\u5C0F\u306E\u8981\u7D20\
    ,\u6700\u5C0F\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9}\n\tpair<ll,\
    \ int> top(int r) {\n\t\treturn top(0, r);\n\t}\n\t/// @brief \u914D\u5217\u306E\
    [l,r)\u306E\u4E2D\u3067\u6700\u5C0F\u306E\u5024\u3092\u6C42\u3081\u308B(\u540C\
    \u7387\u306E\u5834\u5408\u306F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u6700\u5C0F\
    )\n\t/// @param l \u63A2\u7D22\u7BC4\u56F2\u306E\u5DE6\u7AEF(inclusive)\n\t///\
    \ @param r \u63A2\u7D22\u7BC4\u56F2\u306E\u53F3\u7AEF(exclusive)\n\t/// @return\
    \ {\u6700\u5C0F\u306E\u8981\u7D20,\u6700\u5C0F\u8981\u7D20\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9}\n\tpair<ll, int> top(int l, int r) {\n\t\tauto [a, b] = seg.prod(l,\
    \ r);\n\t\treturn { a, b };\n\t}\n\t/// @brief \u914D\u5217\u306E[0,size)\u306E\
    \u4E2D\u3067\u6700\u5C0F\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B(\u540C\
    \u7387\u306E\u5834\u5408\u306F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u6700\u5C0F\
    )\n\tvoid pop() {\n\t\treturn pop(0, N);\n\t}\n\t/// @brief \u914D\u5217\u306E\
    [0,r)\u306E\u4E2D\u3067\u6700\u5C0F\u306E\u5024\u3092\u524A\u9664\u3059\u308B\
    (\u540C\u7387\u306E\u5834\u5408\u306F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u6700\
    \u5C0F)\n\t/// @param r \u63A2\u7D22\u7BC4\u56F2\u306E\u53F3\u7AEF(exclusive)\n\
    \tvoid pop(int r) {\n\t\treturn pop(0, r);\n\t}\n\t/// @brief \u914D\u5217\u306E\
    [l,r)\u306E\u4E2D\u3067\u6700\u5C0F\u306E\u5024\u3092\u524A\u9664\u3059\u308B\
    (\u540C\u7387\u306E\u5834\u5408\u306F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u6700\
    \u5C0F)\n\t/// @param l \u63A2\u7D22\u7BC4\u56F2\u306E\u5DE6\u7AEF(inclusive)\n\
    \t/// @param r \u63A2\u7D22\u7BC4\u56F2\u306E\u53F3\u7AEF(exclusive)\n\tvoid pop(int\
    \ l, int r) {\n\t\tauto [a, b] = seg.prod(l, r);\n\t\tif(b == -1) {\n\t\t\treturn;\n\
    \t\t}\n\t\tseg.set(b, inner_editable_pq::e());\n\t\tsz--;\n\t}\n\t/// @brief \u914D\
    \u5217\u306E\u8981\u7D20\u304C\u3059\u3079\u3066\u524A\u9664\u3055\u308C\u3066\
    \u3044\u308B\u304B\u8ABF\u3079\u308B\n\t/// @return \u914D\u5217\u306E\u8981\u7D20\
    \u304C\u3059\u3079\u3066\u524A\u9664\u3055\u308C\u3066\u3044\u308B\u306A\u3089\
    true,\u305D\u3046\u3067\u306A\u3051\u308C\u3070false\n\tbool empty() {\n\t\treturn\
    \ sz == 0;\n\t}\n\t/// @brief \u914D\u5217\u306Ei\u756A\u76EE\u306E\u8981\u7D20\
    \u304C\u524A\u9664\u3055\u308C\u3066\u3044\u308B\u304B\u8ABF\u3079\u308B\n\t///\
    \ @param i \u524A\u9664\u3055\u308C\u3066\u3044\u308B\u304B\u8ABF\u3079\u308B\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9(0-indexed)\n\t/// @return \u914D\u5217\u306Ei\u756A\
    \u76EE\u306E\u8981\u7D20\u304C\u524A\u9664\u3055\u308C\u3066\u3044\u308B\u306A\
    \u3089true,\u305D\u3046\u3067\u306A\u3051\u308C\u3070false\n\tbool is_removed(int\
    \ i) {\n\t\tauto p = seg.get(i);\n\t\treturn p == inner_editable_pq::e();\n\t\
    }\n\t/// @brief \u914D\u5217\u306E\u524A\u9664\u3055\u308C\u3066\u3044\u306A\u3044\
    \u8981\u7D20\u306E\u6570\u3092\u8FD4\u3059\n\t/// @return \u914D\u5217\u306E\u8981\
    \u7D20\u6570\n\tsize_t size() {\n\t\treturn sz;\n\t}\n};\n"
  code: "#include \"../base.hpp\"\n#include \"atcoder/all\"\nusing namespace atcoder;\n\
    \nnamespace inner_editable_pq {\npair<ll, int> op(pair<ll, int> a, pair<ll, int>\
    \ b) {\n\treturn min(a, b);\n}\npair<ll, int> e() {\n\treturn { LINF, -1 };\n\
    }\n}\n/// @brief \u7DE8\u96C6\u53EF\u80FD\u30D7\u30E9\u30A4\u30AA\u30EA\u30C6\u30A3\
    \u30FC\u30AD\u30E5\u30FC\nstruct editable_priority_queue {\nprivate:\n\tsegtree<pair<ll,\
    \ int>, inner_editable_pq::op,\n\t\t\tinner_editable_pq::e>\n\t\tseg;\n\tint sz;\n\
    \tint N;\n\npublic:\n\teditable_priority_queue(vll& v) {\n\t\tsz = SZ(v);\n\t\t\
    N = SZ(v);\n\t\tvector<pair<ll, int>> V;\n\t\tREP(i, N) {\n\t\t\tif(v[i] == inner_editable_pq::e().first)\
    \ {\n\t\t\t\tV.emplace_back(v[i], -1);\n\t\t\t} else {\n\t\t\t\tV.emplace_back(v[i],\
    \ i);\n\t\t\t}\n\t\t}\n\t\tseg = segtree<pair<ll, int>, inner_editable_pq::op,\n\
    \t\t\t\t\t  inner_editable_pq::e>(V);\n\t}\n\t/// @brief \u914D\u5217\u306Ei\u756A\
    \u76EE\u306E\u5024\u306B\u30A2\u30AF\u30BB\u30B9\u3059\u308B\n\t/// @param i \u30A2\
    \u30AF\u30BB\u30B9\u3059\u308B\u914D\u5217\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9(0-indexed)\n\t/// @return \u914D\u5217\u306Ei\u756A\u76EE\u306E\u5024\n\
    \tll get(int i) {\n\t\tauto [a, b] = seg.get(i);\n\t\treturn a;\n\t}\n\t/// @brief\
    \ \u914D\u5217\u306Ei\u756A\u76EE\u306E\u5024\u3092x\u306B\u5909\u66F4\u3059\u308B\
    \n\t/// @param i \u5909\u66F4\u3059\u308B\u914D\u5217\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9(0-indexed)\n\t/// @param x \u5909\u66F4\u5F8C\u306E\u5024\n\tvoid\
    \ set(int i, ll x) {\n\t\tauto [a, b] = seg.get(i);\n\t\tif(b == -1) sz++;\n\t\
    \tif(x == inner_editable_pq::e().first) {\n\t\t\tseg.set(i, { x, -1 });\n\t\t\t\
    sz--;\n\t\t} else {\n\t\t\tseg.set(i, { x, i });\n\t\t}\n\t}\n\t/// @brief \u914D\
    \u5217\u306E[0,size)\u306E\u4E2D\u3067\u6700\u5C0F\u306E\u5024\u6C42\u3081\u308B\
    (\u540C\u7387\u306E\u5834\u5408\u306F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u6700\
    \u5C0F)\n\t/// @return {\u6700\u5C0F\u306E\u8981\u7D20,\u6700\u5C0F\u8981\u7D20\
    \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9}\n\tpair<ll, int> top() {\n\t\treturn\
    \ top(0, N);\n\t}\n\t/// @brief \u914D\u5217\u306E[0,r)\u306E\u4E2D\u3067\u6700\
    \u5C0F\u306E\u5024\u6C42\u3081\u308B(\u540C\u7387\u306E\u5834\u5408\u306F\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u6700\u5C0F)\n\t/// @param r \u63A2\u7D22\u7BC4\
    \u56F2\u306E\u53F3\u7AEF(exclusive)\n\t/// @return {\u6700\u5C0F\u306E\u8981\u7D20\
    ,\u6700\u5C0F\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9}\n\tpair<ll,\
    \ int> top(int r) {\n\t\treturn top(0, r);\n\t}\n\t/// @brief \u914D\u5217\u306E\
    [l,r)\u306E\u4E2D\u3067\u6700\u5C0F\u306E\u5024\u3092\u6C42\u3081\u308B(\u540C\
    \u7387\u306E\u5834\u5408\u306F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u6700\u5C0F\
    )\n\t/// @param l \u63A2\u7D22\u7BC4\u56F2\u306E\u5DE6\u7AEF(inclusive)\n\t///\
    \ @param r \u63A2\u7D22\u7BC4\u56F2\u306E\u53F3\u7AEF(exclusive)\n\t/// @return\
    \ {\u6700\u5C0F\u306E\u8981\u7D20,\u6700\u5C0F\u8981\u7D20\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9}\n\tpair<ll, int> top(int l, int r) {\n\t\tauto [a, b] = seg.prod(l,\
    \ r);\n\t\treturn { a, b };\n\t}\n\t/// @brief \u914D\u5217\u306E[0,size)\u306E\
    \u4E2D\u3067\u6700\u5C0F\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B(\u540C\
    \u7387\u306E\u5834\u5408\u306F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u6700\u5C0F\
    )\n\tvoid pop() {\n\t\treturn pop(0, N);\n\t}\n\t/// @brief \u914D\u5217\u306E\
    [0,r)\u306E\u4E2D\u3067\u6700\u5C0F\u306E\u5024\u3092\u524A\u9664\u3059\u308B\
    (\u540C\u7387\u306E\u5834\u5408\u306F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u6700\
    \u5C0F)\n\t/// @param r \u63A2\u7D22\u7BC4\u56F2\u306E\u53F3\u7AEF(exclusive)\n\
    \tvoid pop(int r) {\n\t\treturn pop(0, r);\n\t}\n\t/// @brief \u914D\u5217\u306E\
    [l,r)\u306E\u4E2D\u3067\u6700\u5C0F\u306E\u5024\u3092\u524A\u9664\u3059\u308B\
    (\u540C\u7387\u306E\u5834\u5408\u306F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u6700\
    \u5C0F)\n\t/// @param l \u63A2\u7D22\u7BC4\u56F2\u306E\u5DE6\u7AEF(inclusive)\n\
    \t/// @param r \u63A2\u7D22\u7BC4\u56F2\u306E\u53F3\u7AEF(exclusive)\n\tvoid pop(int\
    \ l, int r) {\n\t\tauto [a, b] = seg.prod(l, r);\n\t\tif(b == -1) {\n\t\t\treturn;\n\
    \t\t}\n\t\tseg.set(b, inner_editable_pq::e());\n\t\tsz--;\n\t}\n\t/// @brief \u914D\
    \u5217\u306E\u8981\u7D20\u304C\u3059\u3079\u3066\u524A\u9664\u3055\u308C\u3066\
    \u3044\u308B\u304B\u8ABF\u3079\u308B\n\t/// @return \u914D\u5217\u306E\u8981\u7D20\
    \u304C\u3059\u3079\u3066\u524A\u9664\u3055\u308C\u3066\u3044\u308B\u306A\u3089\
    true,\u305D\u3046\u3067\u306A\u3051\u308C\u3070false\n\tbool empty() {\n\t\treturn\
    \ sz == 0;\n\t}\n\t/// @brief \u914D\u5217\u306Ei\u756A\u76EE\u306E\u8981\u7D20\
    \u304C\u524A\u9664\u3055\u308C\u3066\u3044\u308B\u304B\u8ABF\u3079\u308B\n\t///\
    \ @param i \u524A\u9664\u3055\u308C\u3066\u3044\u308B\u304B\u8ABF\u3079\u308B\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9(0-indexed)\n\t/// @return \u914D\u5217\u306Ei\u756A\
    \u76EE\u306E\u8981\u7D20\u304C\u524A\u9664\u3055\u308C\u3066\u3044\u308B\u306A\
    \u3089true,\u305D\u3046\u3067\u306A\u3051\u308C\u3070false\n\tbool is_removed(int\
    \ i) {\n\t\tauto p = seg.get(i);\n\t\treturn p == inner_editable_pq::e();\n\t\
    }\n\t/// @brief \u914D\u5217\u306E\u524A\u9664\u3055\u308C\u3066\u3044\u306A\u3044\
    \u8981\u7D20\u306E\u6570\u3092\u8FD4\u3059\n\t/// @return \u914D\u5217\u306E\u8981\
    \u7D20\u6570\n\tsize_t size() {\n\t\treturn sz;\n\t}\n};"
  dependsOn:
  - base.hpp
  - atcoder/convolution.hpp
  - atcoder/internal_bit.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  - atcoder/dsu.hpp
  - atcoder/fenwicktree.hpp
  - atcoder/lazysegtree.hpp
  - atcoder/math.hpp
  - atcoder/maxflow.hpp
  - atcoder/internal_queue.hpp
  - atcoder/mincostflow.hpp
  - atcoder/scc.hpp
  - atcoder/internal_scc.hpp
  - atcoder/segtree.hpp
  - atcoder/string.hpp
  - atcoder/twosat.hpp
  isVerificationFile: false
  path: structure/editable_priority_queue.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/editable_priority_queue.hpp
layout: document
redirect_from:
- /library/structure/editable_priority_queue.hpp
- /library/structure/editable_priority_queue.hpp.html
title: "\u7DE8\u96C6\u53EF\u80FD\u30D7\u30E9\u30A4\u30AA\u30EA\u30C6\u30A3\u30FC\u30AD\
  \u30E5\u30FC"
---
