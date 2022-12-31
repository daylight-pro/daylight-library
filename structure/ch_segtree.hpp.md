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
    document_title: "\u30BB\u30B0\u6728\u3092\u914D\u5217\u306E\u5185\u5BB9\u3067\u521D\
      \u671F\u5316\u3059\u308B"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"structure/ch_segtree.hpp\"\
    \nclass SegmentTreeBeats {\nprivate:\n\tconst ll inf = 1e18;\n\tint n, n0;\n\t\
    vll max_v, smax_v, max_c;\n\tvll min_v, smin_v, min_c;\n\tvll sum;\n\tvll len,\
    \ ladd, lval;\n\n\tvoid update_node_max(int k, ll x) {\n\t\tsum[k] += (x - max_v[k])\
    \ * max_c[k];\n\n\t\tif(max_v[k] == min_v[k]) {\n\t\t\tmax_v[k] = min_v[k] = x;\n\
    \t\t} else if(max_v[k] == smin_v[k]) {\n\t\t\tmax_v[k] = smin_v[k] = x;\n\t\t\
    } else {\n\t\t\tmax_v[k] = x;\n\t\t}\n\n\t\tif(lval[k] != inf && x < lval[k])\
    \ {\n\t\t\tlval[k] = x;\n\t\t}\n\t}\n\tvoid update_node_min(int k, ll x) {\n\t\
    \tsum[k] += (x - min_v[k]) * min_c[k];\n\n\t\tif(max_v[k] == min_v[k]) {\n\t\t\
    \tmax_v[k] = min_v[k] = x;\n\t\t} else if(smax_v[k] == min_v[k]) {\n\t\t\tmin_v[k]\
    \ = smax_v[k] = x;\n\t\t} else {\n\t\t\tmin_v[k] = x;\n\t\t}\n\n\t\tif(lval[k]\
    \ != inf && lval[k] < x) {\n\t\t\tlval[k] = x;\n\t\t}\n\t}\n\n\tvoid push(int\
    \ k) {\n\t\tif(n0 - 1 <= k) return;\n\n\t\tif(lval[k] != inf) {\n\t\t\tupdateall(2\
    \ * k + 1, lval[k]);\n\t\t\tupdateall(2 * k + 2, lval[k]);\n\t\t\tlval[k] = inf;\n\
    \t\t\treturn;\n\t\t}\n\n\t\tif(ladd[k] != 0) {\n\t\t\taddall(2 * k + 1, ladd[k]);\n\
    \t\t\taddall(2 * k + 2, ladd[k]);\n\t\t\tladd[k] = 0;\n\t\t}\n\n\t\tif(max_v[k]\
    \ < max_v[2 * k + 1]) {\n\t\t\tupdate_node_max(2 * k + 1, max_v[k]);\n\t\t}\n\t\
    \tif(min_v[2 * k + 1] < min_v[k]) {\n\t\t\tupdate_node_min(2 * k + 1, min_v[k]);\n\
    \t\t}\n\n\t\tif(max_v[k] < max_v[2 * k + 2]) {\n\t\t\tupdate_node_max(2 * k +\
    \ 2, max_v[k]);\n\t\t}\n\t\tif(min_v[2 * k + 2] < min_v[k]) {\n\t\t\tupdate_node_min(2\
    \ * k + 2, min_v[k]);\n\t\t}\n\t}\n\n\tvoid update(int k) {\n\t\tsum[k] = sum[2\
    \ * k + 1] + sum[2 * k + 2];\n\n\t\tif(max_v[2 * k + 1] < max_v[2 * k + 2]) {\n\
    \t\t\tmax_v[k] = max_v[2 * k + 2];\n\t\t\tmax_c[k] = max_c[2 * k + 2];\n\t\t\t\
    smax_v[k]\n\t\t\t\t= max(max_v[2 * k + 1], smax_v[2 * k + 2]);\n\t\t} else if(max_v[2\
    \ * k + 1] > max_v[2 * k + 2]) {\n\t\t\tmax_v[k] = max_v[2 * k + 1];\n\t\t\tmax_c[k]\
    \ = max_c[2 * k + 1];\n\t\t\tsmax_v[k]\n\t\t\t\t= max(smax_v[2 * k + 1], max_v[2\
    \ * k + 2]);\n\t\t} else {\n\t\t\tmax_v[k] = max_v[2 * k + 1];\n\t\t\tmax_c[k]\
    \ = max_c[2 * k + 1] + max_c[2 * k + 2];\n\t\t\tsmax_v[k]\n\t\t\t\t= max(smax_v[2\
    \ * k + 1], smax_v[2 * k + 2]);\n\t\t}\n\n\t\tif(min_v[2 * k + 1] < min_v[2 *\
    \ k + 2]) {\n\t\t\tmin_v[k] = min_v[2 * k + 1];\n\t\t\tmin_c[k] = min_c[2 * k\
    \ + 1];\n\t\t\tsmin_v[k]\n\t\t\t\t= min(smin_v[2 * k + 1], min_v[2 * k + 2]);\n\
    \t\t} else if(min_v[2 * k + 1] > min_v[2 * k + 2]) {\n\t\t\tmin_v[k] = min_v[2\
    \ * k + 2];\n\t\t\tmin_c[k] = min_c[2 * k + 2];\n\t\t\tsmin_v[k]\n\t\t\t\t= min(min_v[2\
    \ * k + 1], smin_v[2 * k + 2]);\n\t\t} else {\n\t\t\tmin_v[k] = min_v[2 * k +\
    \ 1];\n\t\t\tmin_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];\n\t\t\tsmin_v[k]\n\
    \t\t\t\t= min(smin_v[2 * k + 1], smin_v[2 * k + 2]);\n\t\t}\n\t}\n\n\tvoid _update_min(ll\
    \ x, int a, int b, int k, int l,\n\t\t\t\t\t int r) {\n\t\tif(b <= l || r <= a\
    \ || max_v[k] <= x) {\n\t\t\treturn;\n\t\t}\n\t\tif(a <= l && r <= b && smax_v[k]\
    \ < x) {\n\t\t\tupdate_node_max(k, x);\n\t\t\treturn;\n\t\t}\n\n\t\tpush(k);\n\
    \t\t_update_min(x, a, b, 2 * k + 1, l, (l + r) / 2);\n\t\t_update_min(x, a, b,\
    \ 2 * k + 2, (l + r) / 2, r);\n\t\tupdate(k);\n\t}\n\n\tvoid _update_max(ll x,\
    \ int a, int b, int k, int l,\n\t\t\t\t\t int r) {\n\t\tif(b <= l || r <= a ||\
    \ x <= min_v[k]) {\n\t\t\treturn;\n\t\t}\n\t\tif(a <= l && r <= b && x < smin_v[k])\
    \ {\n\t\t\tupdate_node_min(k, x);\n\t\t\treturn;\n\t\t}\n\n\t\tpush(k);\n\t\t\
    _update_max(x, a, b, 2 * k + 1, l, (l + r) / 2);\n\t\t_update_max(x, a, b, 2 *\
    \ k + 2, (l + r) / 2, r);\n\t\tupdate(k);\n\t}\n\n\tvoid addall(int k, ll x) {\n\
    \t\tmax_v[k] += x;\n\t\tif(smax_v[k] != -inf) smax_v[k] += x;\n\t\tmin_v[k] +=\
    \ x;\n\t\tif(smin_v[k] != inf) smin_v[k] += x;\n\n\t\tsum[k] += len[k] * x;\n\t\
    \tif(lval[k] != inf) {\n\t\t\tlval[k] += x;\n\t\t} else {\n\t\t\tladd[k] += x;\n\
    \t\t}\n\t}\n\n\tvoid updateall(int k, ll x) {\n\t\tmax_v[k] = x;\n\t\tsmax_v[k]\
    \ = -inf;\n\t\tmin_v[k] = x;\n\t\tsmin_v[k] = inf;\n\t\tmax_c[k] = min_c[k] =\
    \ len[k];\n\n\t\tsum[k] = x * len[k];\n\t\tlval[k] = x;\n\t\tladd[k] = 0;\n\t\
    }\n\n\tvoid _add_val(ll x, int a, int b, int k, int l, int r) {\n\t\tif(b <= l\
    \ || r <= a) {\n\t\t\treturn;\n\t\t}\n\t\tif(a <= l && r <= b) {\n\t\t\taddall(k,\
    \ x);\n\t\t\treturn;\n\t\t}\n\n\t\tpush(k);\n\t\t_add_val(x, a, b, 2 * k + 1,\
    \ l, (l + r) / 2);\n\t\t_add_val(x, a, b, 2 * k + 2, (l + r) / 2, r);\n\t\tupdate(k);\n\
    \t}\n\n\tvoid _update_val(ll x, int a, int b, int k, int l,\n\t\t\t\t\t int r)\
    \ {\n\t\tif(b <= l || r <= a) {\n\t\t\treturn;\n\t\t}\n\t\tif(a <= l && r <= b)\
    \ {\n\t\t\tupdateall(k, x);\n\t\t\treturn;\n\t\t}\n\n\t\tpush(k);\n\t\t_update_val(x,\
    \ a, b, 2 * k + 1, l, (l + r) / 2);\n\t\t_update_val(x, a, b, 2 * k + 2, (l +\
    \ r) / 2, r);\n\t\tupdate(k);\n\t}\n\n\tll _query_max(int a, int b, int k, int\
    \ l, int r) {\n\t\tif(b <= l || r <= a) {\n\t\t\treturn -inf;\n\t\t}\n\t\tif(a\
    \ <= l && r <= b) {\n\t\t\treturn max_v[k];\n\t\t}\n\t\tpush(k);\n\t\tll lv =\
    \ _query_max(a, b, 2 * k + 1, l, (l + r) / 2);\n\t\tll rv = _query_max(a, b, 2\
    \ * k + 2, (l + r) / 2, r);\n\t\treturn max(lv, rv);\n\t}\n\n\tll _query_min(int\
    \ a, int b, int k, int l, int r) {\n\t\tif(b <= l || r <= a) {\n\t\t\treturn inf;\n\
    \t\t}\n\t\tif(a <= l && r <= b) {\n\t\t\treturn min_v[k];\n\t\t}\n\t\tpush(k);\n\
    \t\tll lv = _query_min(a, b, 2 * k + 1, l, (l + r) / 2);\n\t\tll rv = _query_min(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n\t\treturn min(lv, rv);\n\t}\n\n\tll _query_sum(int\
    \ a, int b, int k, int l, int r) {\n\t\tif(b <= l || r <= a) {\n\t\t\treturn 0;\n\
    \t\t}\n\t\tif(a <= l && r <= b) {\n\t\t\treturn sum[k];\n\t\t}\n\t\tpush(k);\n\
    \t\tll lv = _query_sum(a, b, 2 * k + 1, l, (l + r) / 2);\n\t\tll rv = _query_sum(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n\t\treturn lv + rv;\n\t}\n\npublic:\n\tSegmentTreeBeats(int\
    \ N): SegmentTreeBeats(vll(N)) {\n\t}\n\n\t/// @brief \u30BB\u30B0\u6728\u3092\
    \u914D\u5217\u306E\u5185\u5BB9\u3067\u521D\u671F\u5316\u3059\u308B\n\t/// @param\
    \ a \u30BB\u30B0\u6728\u306E\u521D\u671F\u5024\n\tSegmentTreeBeats(const vll &a)\
    \ {\n\t\tn = SZ(a);\n\t\tn0 = 1;\n\t\twhile(n0 < n) n0 <<= 1;\n\n\t\tmax_v = vll(n0\
    \ * 2);\n\t\tsmax_v = vll(n0 * 2), max_c = vll(n0 * 2);\n\t\tmin_v = vll(n0 *\
    \ 2);\n\t\tsmin_v = vll(n0 * 2), min_c = vll(n0 * 2);\n\t\tsum = vll(n0 * 2);\n\
    \t\tlen = vll(n0 * 2), ladd = vll(n0 * 2),\n\t\tlval = vll(n0 * 2);\n\t\tfor(int\
    \ i = 0; i < 2 * n0; ++i)\n\t\t\tladd[i] = 0, lval[i] = inf;\n\t\tlen[0] = n0;\n\
    \t\tfor(int i = 0; i < n0 - 1; ++i)\n\t\t\tlen[2 * i + 1] = len[2 * i + 2] = (len[i]\
    \ >> 1);\n\n\t\tfor(int i = 0; i < n; ++i) {\n\t\t\tmax_v[n0 - 1 + i] = min_v[n0\
    \ - 1 + i]\n\t\t\t\t= sum[n0 - 1 + i] = a[i];\n\t\t\tsmax_v[n0 - 1 + i] = -inf;\n\
    \t\t\tsmin_v[n0 - 1 + i] = inf;\n\t\t\tmax_c[n0 - 1 + i] = min_c[n0 - 1 + i] =\
    \ 1;\n\t\t}\n\n\t\tfor(int i = n; i < n0; ++i) {\n\t\t\tmax_v[n0 - 1 + i] = smax_v[n0\
    \ - 1 + i] = -inf;\n\t\t\tmin_v[n0 - 1 + i] = smin_v[n0 - 1 + i] = inf;\n\t\t\t\
    max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;\n\t\t}\n\t\tfor(int i = n0 - 2; i >=\
    \ 0; i--) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\n\t/// @brief p\u756A\u76EE\u306E\u8981\
    \u7D20\u306B\u30A2\u30AF\u30BB\u30B9\n\t/// @param p \u30A2\u30AF\u30BB\u30B9\u3059\
    \u308B\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9(0-indexed)\n\t///\
    \ @return p\u756A\u76EE\u306E\u8981\u7D20\n\tll get(int p) {\n\t\treturn prod_sum(p,\
    \ p + 1);\n\t}\n\n\t/// @brief p\u756A\u76EE\u306E\u8981\u7D20\u3092x\u306B\u5909\
    \u66F4\n\t/// @param p \u5909\u66F4\u3059\u308B\u8981\u7D20\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9(0-indexed)\n\t/// @param x \u5909\u66F4\u5F8C\u306E\u5024\n\
    \tvoid set(int p, ll x) {\n\t\tapply_update(p, p + 1, x);\n\t}\n\n\t/// @brief\
    \ \u533A\u9593[a,b)\u3067v[i]\u2190min(v[i],x)\n\t/// @param a \u533A\u9593\u306E\
    \u5DE6\u7AEF(inclusive)\n\t/// @param b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n\
    \t/// @param x min\u3092\u3068\u308B\u5024\n\tvoid apply_chmin(int a, int b, ll\
    \ x) {\n\t\t_update_min(x, a, b, 0, 0, n0);\n\t}\n\n\t/// @brief \u533A\u9593\
    [a,b)\u3067v[i]\u2190max(v[i],x)\n\t/// @param a \u533A\u9593\u306E\u5DE6\u7AEF\
    (inclusive)\n\t/// @param b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @param\
    \ x max\u3092\u3068\u308B\u5024\n\tvoid apply_chmax(int a, int b, ll x) {\n\t\t\
    _update_max(x, a, b, 0, 0, n0);\n\t}\n\n\t/// @brief \u533A\u9593[a,b)\u3067v[i]\u2190\
    v[i]+x\n\t/// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param\
    \ b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @param x \u52A0\u7B97\u3059\
    \u308B\u5024\n\tvoid apply_add(int a, int b, ll x) {\n\t\t_add_val(x, a, b, 0,\
    \ 0, n0);\n\t}\n\n\t/// @brief \u533A\u9593[a,b)\u3067v[i]\u2190x\n\t/// @param\
    \ a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param b \u533A\u9593\u306E\
    \u53F3\u7AEF(exclusive)\n\t/// @param x \u66F4\u65B0\u3059\u308B\u5024\n\tvoid\
    \ apply_update(int a, int b, ll x) {\n\t\t_update_val(x, a, b, 0, 0, n0);\n\t\
    }\n\n\t/// @brief \u533A\u9593[a,b)\u306E\u6700\u5927\u5024\u3092\u53D6\u5F97\n\
    \t/// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param b \u533A\
    \u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @return \u533A\u9593[a,b)\u306E\u6700\
    \u5927\u5024\n\tll prod_max(int a, int b) {\n\t\treturn _query_max(a, b, 0, 0,\
    \ n0);\n\t}\n\n\t/// @brief \u533A\u9593[a,b)\u306E\u6700\u5C0F\u5024\u3092\u53D6\
    \u5F97\n\t/// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param\
    \ b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @return \u533A\u9593[a,b)\u306E\
    \u6700\u5C0F\u5024\n\tll prod_min(int a, int b) {\n\t\treturn _query_min(a, b,\
    \ 0, 0, n0);\n\t}\n\n\t/// @brief \u533A\u9593[a,b)\u306E\u548C\u3092\u53D6\u5F97\
    \n\t/// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param b \u533A\
    \u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @return \u533A\u9593[a,b)\u306E\u548C\
    \n\tll prod_sum(int a, int b) {\n\t\treturn _query_sum(a, b, 0, 0, n0);\n\t}\n\
    \n\t/// @brief \u5168\u4F53\u306E\u6700\u5927\u5024\u3092\u53D6\u5F97\n\t/// @return\
    \ \u5168\u4F53\u306E\u6700\u5927\u5024\n\tll all_prod_max() {\n\t\treturn prod_max(0,\
    \ n);\n\t}\n\n\t/// @brief \u5168\u4F53\u306E\u6700\u5C0F\u5024\u3092\u53D6\u5F97\
    \n\t/// @return \u5168\u4F53\u306E\u6700\u5C0F\u5024\n\tll all_prod_min() {\n\t\
    \treturn prod_min(0, n);\n\t}\n\n\t/// @brief \u5168\u4F53\u306E\u7DCF\u548C\u3092\
    \u53D6\u5F97\n\t/// @return \u5168\u4F53\u306E\u7DCF\u548C\n\tll all_prod_sum()\
    \ {\n\t\treturn prod_sum(0, n);\n\t}\n};\n"
  code: "#include \"../base.hpp\"\nclass SegmentTreeBeats {\nprivate:\n\tconst ll\
    \ inf = 1e18;\n\tint n, n0;\n\tvll max_v, smax_v, max_c;\n\tvll min_v, smin_v,\
    \ min_c;\n\tvll sum;\n\tvll len, ladd, lval;\n\n\tvoid update_node_max(int k,\
    \ ll x) {\n\t\tsum[k] += (x - max_v[k]) * max_c[k];\n\n\t\tif(max_v[k] == min_v[k])\
    \ {\n\t\t\tmax_v[k] = min_v[k] = x;\n\t\t} else if(max_v[k] == smin_v[k]) {\n\t\
    \t\tmax_v[k] = smin_v[k] = x;\n\t\t} else {\n\t\t\tmax_v[k] = x;\n\t\t}\n\n\t\t\
    if(lval[k] != inf && x < lval[k]) {\n\t\t\tlval[k] = x;\n\t\t}\n\t}\n\tvoid update_node_min(int\
    \ k, ll x) {\n\t\tsum[k] += (x - min_v[k]) * min_c[k];\n\n\t\tif(max_v[k] == min_v[k])\
    \ {\n\t\t\tmax_v[k] = min_v[k] = x;\n\t\t} else if(smax_v[k] == min_v[k]) {\n\t\
    \t\tmin_v[k] = smax_v[k] = x;\n\t\t} else {\n\t\t\tmin_v[k] = x;\n\t\t}\n\n\t\t\
    if(lval[k] != inf && lval[k] < x) {\n\t\t\tlval[k] = x;\n\t\t}\n\t}\n\n\tvoid\
    \ push(int k) {\n\t\tif(n0 - 1 <= k) return;\n\n\t\tif(lval[k] != inf) {\n\t\t\
    \tupdateall(2 * k + 1, lval[k]);\n\t\t\tupdateall(2 * k + 2, lval[k]);\n\t\t\t\
    lval[k] = inf;\n\t\t\treturn;\n\t\t}\n\n\t\tif(ladd[k] != 0) {\n\t\t\taddall(2\
    \ * k + 1, ladd[k]);\n\t\t\taddall(2 * k + 2, ladd[k]);\n\t\t\tladd[k] = 0;\n\t\
    \t}\n\n\t\tif(max_v[k] < max_v[2 * k + 1]) {\n\t\t\tupdate_node_max(2 * k + 1,\
    \ max_v[k]);\n\t\t}\n\t\tif(min_v[2 * k + 1] < min_v[k]) {\n\t\t\tupdate_node_min(2\
    \ * k + 1, min_v[k]);\n\t\t}\n\n\t\tif(max_v[k] < max_v[2 * k + 2]) {\n\t\t\t\
    update_node_max(2 * k + 2, max_v[k]);\n\t\t}\n\t\tif(min_v[2 * k + 2] < min_v[k])\
    \ {\n\t\t\tupdate_node_min(2 * k + 2, min_v[k]);\n\t\t}\n\t}\n\n\tvoid update(int\
    \ k) {\n\t\tsum[k] = sum[2 * k + 1] + sum[2 * k + 2];\n\n\t\tif(max_v[2 * k +\
    \ 1] < max_v[2 * k + 2]) {\n\t\t\tmax_v[k] = max_v[2 * k + 2];\n\t\t\tmax_c[k]\
    \ = max_c[2 * k + 2];\n\t\t\tsmax_v[k]\n\t\t\t\t= max(max_v[2 * k + 1], smax_v[2\
    \ * k + 2]);\n\t\t} else if(max_v[2 * k + 1] > max_v[2 * k + 2]) {\n\t\t\tmax_v[k]\
    \ = max_v[2 * k + 1];\n\t\t\tmax_c[k] = max_c[2 * k + 1];\n\t\t\tsmax_v[k]\n\t\
    \t\t\t= max(smax_v[2 * k + 1], max_v[2 * k + 2]);\n\t\t} else {\n\t\t\tmax_v[k]\
    \ = max_v[2 * k + 1];\n\t\t\tmax_c[k] = max_c[2 * k + 1] + max_c[2 * k + 2];\n\
    \t\t\tsmax_v[k]\n\t\t\t\t= max(smax_v[2 * k + 1], smax_v[2 * k + 2]);\n\t\t}\n\
    \n\t\tif(min_v[2 * k + 1] < min_v[2 * k + 2]) {\n\t\t\tmin_v[k] = min_v[2 * k\
    \ + 1];\n\t\t\tmin_c[k] = min_c[2 * k + 1];\n\t\t\tsmin_v[k]\n\t\t\t\t= min(smin_v[2\
    \ * k + 1], min_v[2 * k + 2]);\n\t\t} else if(min_v[2 * k + 1] > min_v[2 * k +\
    \ 2]) {\n\t\t\tmin_v[k] = min_v[2 * k + 2];\n\t\t\tmin_c[k] = min_c[2 * k + 2];\n\
    \t\t\tsmin_v[k]\n\t\t\t\t= min(min_v[2 * k + 1], smin_v[2 * k + 2]);\n\t\t} else\
    \ {\n\t\t\tmin_v[k] = min_v[2 * k + 1];\n\t\t\tmin_c[k] = min_c[2 * k + 1] + min_c[2\
    \ * k + 2];\n\t\t\tsmin_v[k]\n\t\t\t\t= min(smin_v[2 * k + 1], smin_v[2 * k +\
    \ 2]);\n\t\t}\n\t}\n\n\tvoid _update_min(ll x, int a, int b, int k, int l,\n\t\
    \t\t\t\t int r) {\n\t\tif(b <= l || r <= a || max_v[k] <= x) {\n\t\t\treturn;\n\
    \t\t}\n\t\tif(a <= l && r <= b && smax_v[k] < x) {\n\t\t\tupdate_node_max(k, x);\n\
    \t\t\treturn;\n\t\t}\n\n\t\tpush(k);\n\t\t_update_min(x, a, b, 2 * k + 1, l, (l\
    \ + r) / 2);\n\t\t_update_min(x, a, b, 2 * k + 2, (l + r) / 2, r);\n\t\tupdate(k);\n\
    \t}\n\n\tvoid _update_max(ll x, int a, int b, int k, int l,\n\t\t\t\t\t int r)\
    \ {\n\t\tif(b <= l || r <= a || x <= min_v[k]) {\n\t\t\treturn;\n\t\t}\n\t\tif(a\
    \ <= l && r <= b && x < smin_v[k]) {\n\t\t\tupdate_node_min(k, x);\n\t\t\treturn;\n\
    \t\t}\n\n\t\tpush(k);\n\t\t_update_max(x, a, b, 2 * k + 1, l, (l + r) / 2);\n\t\
    \t_update_max(x, a, b, 2 * k + 2, (l + r) / 2, r);\n\t\tupdate(k);\n\t}\n\n\t\
    void addall(int k, ll x) {\n\t\tmax_v[k] += x;\n\t\tif(smax_v[k] != -inf) smax_v[k]\
    \ += x;\n\t\tmin_v[k] += x;\n\t\tif(smin_v[k] != inf) smin_v[k] += x;\n\n\t\t\
    sum[k] += len[k] * x;\n\t\tif(lval[k] != inf) {\n\t\t\tlval[k] += x;\n\t\t} else\
    \ {\n\t\t\tladd[k] += x;\n\t\t}\n\t}\n\n\tvoid updateall(int k, ll x) {\n\t\t\
    max_v[k] = x;\n\t\tsmax_v[k] = -inf;\n\t\tmin_v[k] = x;\n\t\tsmin_v[k] = inf;\n\
    \t\tmax_c[k] = min_c[k] = len[k];\n\n\t\tsum[k] = x * len[k];\n\t\tlval[k] = x;\n\
    \t\tladd[k] = 0;\n\t}\n\n\tvoid _add_val(ll x, int a, int b, int k, int l, int\
    \ r) {\n\t\tif(b <= l || r <= a) {\n\t\t\treturn;\n\t\t}\n\t\tif(a <= l && r <=\
    \ b) {\n\t\t\taddall(k, x);\n\t\t\treturn;\n\t\t}\n\n\t\tpush(k);\n\t\t_add_val(x,\
    \ a, b, 2 * k + 1, l, (l + r) / 2);\n\t\t_add_val(x, a, b, 2 * k + 2, (l + r)\
    \ / 2, r);\n\t\tupdate(k);\n\t}\n\n\tvoid _update_val(ll x, int a, int b, int\
    \ k, int l,\n\t\t\t\t\t int r) {\n\t\tif(b <= l || r <= a) {\n\t\t\treturn;\n\t\
    \t}\n\t\tif(a <= l && r <= b) {\n\t\t\tupdateall(k, x);\n\t\t\treturn;\n\t\t}\n\
    \n\t\tpush(k);\n\t\t_update_val(x, a, b, 2 * k + 1, l, (l + r) / 2);\n\t\t_update_val(x,\
    \ a, b, 2 * k + 2, (l + r) / 2, r);\n\t\tupdate(k);\n\t}\n\n\tll _query_max(int\
    \ a, int b, int k, int l, int r) {\n\t\tif(b <= l || r <= a) {\n\t\t\treturn -inf;\n\
    \t\t}\n\t\tif(a <= l && r <= b) {\n\t\t\treturn max_v[k];\n\t\t}\n\t\tpush(k);\n\
    \t\tll lv = _query_max(a, b, 2 * k + 1, l, (l + r) / 2);\n\t\tll rv = _query_max(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n\t\treturn max(lv, rv);\n\t}\n\n\tll _query_min(int\
    \ a, int b, int k, int l, int r) {\n\t\tif(b <= l || r <= a) {\n\t\t\treturn inf;\n\
    \t\t}\n\t\tif(a <= l && r <= b) {\n\t\t\treturn min_v[k];\n\t\t}\n\t\tpush(k);\n\
    \t\tll lv = _query_min(a, b, 2 * k + 1, l, (l + r) / 2);\n\t\tll rv = _query_min(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n\t\treturn min(lv, rv);\n\t}\n\n\tll _query_sum(int\
    \ a, int b, int k, int l, int r) {\n\t\tif(b <= l || r <= a) {\n\t\t\treturn 0;\n\
    \t\t}\n\t\tif(a <= l && r <= b) {\n\t\t\treturn sum[k];\n\t\t}\n\t\tpush(k);\n\
    \t\tll lv = _query_sum(a, b, 2 * k + 1, l, (l + r) / 2);\n\t\tll rv = _query_sum(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n\t\treturn lv + rv;\n\t}\n\npublic:\n\tSegmentTreeBeats(int\
    \ N): SegmentTreeBeats(vll(N)) {\n\t}\n\n\t/// @brief \u30BB\u30B0\u6728\u3092\
    \u914D\u5217\u306E\u5185\u5BB9\u3067\u521D\u671F\u5316\u3059\u308B\n\t/// @param\
    \ a \u30BB\u30B0\u6728\u306E\u521D\u671F\u5024\n\tSegmentTreeBeats(const vll &a)\
    \ {\n\t\tn = SZ(a);\n\t\tn0 = 1;\n\t\twhile(n0 < n) n0 <<= 1;\n\n\t\tmax_v = vll(n0\
    \ * 2);\n\t\tsmax_v = vll(n0 * 2), max_c = vll(n0 * 2);\n\t\tmin_v = vll(n0 *\
    \ 2);\n\t\tsmin_v = vll(n0 * 2), min_c = vll(n0 * 2);\n\t\tsum = vll(n0 * 2);\n\
    \t\tlen = vll(n0 * 2), ladd = vll(n0 * 2),\n\t\tlval = vll(n0 * 2);\n\t\tfor(int\
    \ i = 0; i < 2 * n0; ++i)\n\t\t\tladd[i] = 0, lval[i] = inf;\n\t\tlen[0] = n0;\n\
    \t\tfor(int i = 0; i < n0 - 1; ++i)\n\t\t\tlen[2 * i + 1] = len[2 * i + 2] = (len[i]\
    \ >> 1);\n\n\t\tfor(int i = 0; i < n; ++i) {\n\t\t\tmax_v[n0 - 1 + i] = min_v[n0\
    \ - 1 + i]\n\t\t\t\t= sum[n0 - 1 + i] = a[i];\n\t\t\tsmax_v[n0 - 1 + i] = -inf;\n\
    \t\t\tsmin_v[n0 - 1 + i] = inf;\n\t\t\tmax_c[n0 - 1 + i] = min_c[n0 - 1 + i] =\
    \ 1;\n\t\t}\n\n\t\tfor(int i = n; i < n0; ++i) {\n\t\t\tmax_v[n0 - 1 + i] = smax_v[n0\
    \ - 1 + i] = -inf;\n\t\t\tmin_v[n0 - 1 + i] = smin_v[n0 - 1 + i] = inf;\n\t\t\t\
    max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;\n\t\t}\n\t\tfor(int i = n0 - 2; i >=\
    \ 0; i--) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\n\t/// @brief p\u756A\u76EE\u306E\u8981\
    \u7D20\u306B\u30A2\u30AF\u30BB\u30B9\n\t/// @param p \u30A2\u30AF\u30BB\u30B9\u3059\
    \u308B\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9(0-indexed)\n\t///\
    \ @return p\u756A\u76EE\u306E\u8981\u7D20\n\tll get(int p) {\n\t\treturn prod_sum(p,\
    \ p + 1);\n\t}\n\n\t/// @brief p\u756A\u76EE\u306E\u8981\u7D20\u3092x\u306B\u5909\
    \u66F4\n\t/// @param p \u5909\u66F4\u3059\u308B\u8981\u7D20\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9(0-indexed)\n\t/// @param x \u5909\u66F4\u5F8C\u306E\u5024\n\
    \tvoid set(int p, ll x) {\n\t\tapply_update(p, p + 1, x);\n\t}\n\n\t/// @brief\
    \ \u533A\u9593[a,b)\u3067v[i]\u2190min(v[i],x)\n\t/// @param a \u533A\u9593\u306E\
    \u5DE6\u7AEF(inclusive)\n\t/// @param b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n\
    \t/// @param x min\u3092\u3068\u308B\u5024\n\tvoid apply_chmin(int a, int b, ll\
    \ x) {\n\t\t_update_min(x, a, b, 0, 0, n0);\n\t}\n\n\t/// @brief \u533A\u9593\
    [a,b)\u3067v[i]\u2190max(v[i],x)\n\t/// @param a \u533A\u9593\u306E\u5DE6\u7AEF\
    (inclusive)\n\t/// @param b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @param\
    \ x max\u3092\u3068\u308B\u5024\n\tvoid apply_chmax(int a, int b, ll x) {\n\t\t\
    _update_max(x, a, b, 0, 0, n0);\n\t}\n\n\t/// @brief \u533A\u9593[a,b)\u3067v[i]\u2190\
    v[i]+x\n\t/// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param\
    \ b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @param x \u52A0\u7B97\u3059\
    \u308B\u5024\n\tvoid apply_add(int a, int b, ll x) {\n\t\t_add_val(x, a, b, 0,\
    \ 0, n0);\n\t}\n\n\t/// @brief \u533A\u9593[a,b)\u3067v[i]\u2190x\n\t/// @param\
    \ a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param b \u533A\u9593\u306E\
    \u53F3\u7AEF(exclusive)\n\t/// @param x \u66F4\u65B0\u3059\u308B\u5024\n\tvoid\
    \ apply_update(int a, int b, ll x) {\n\t\t_update_val(x, a, b, 0, 0, n0);\n\t\
    }\n\n\t/// @brief \u533A\u9593[a,b)\u306E\u6700\u5927\u5024\u3092\u53D6\u5F97\n\
    \t/// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param b \u533A\
    \u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @return \u533A\u9593[a,b)\u306E\u6700\
    \u5927\u5024\n\tll prod_max(int a, int b) {\n\t\treturn _query_max(a, b, 0, 0,\
    \ n0);\n\t}\n\n\t/// @brief \u533A\u9593[a,b)\u306E\u6700\u5C0F\u5024\u3092\u53D6\
    \u5F97\n\t/// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param\
    \ b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @return \u533A\u9593[a,b)\u306E\
    \u6700\u5C0F\u5024\n\tll prod_min(int a, int b) {\n\t\treturn _query_min(a, b,\
    \ 0, 0, n0);\n\t}\n\n\t/// @brief \u533A\u9593[a,b)\u306E\u548C\u3092\u53D6\u5F97\
    \n\t/// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param b \u533A\
    \u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @return \u533A\u9593[a,b)\u306E\u548C\
    \n\tll prod_sum(int a, int b) {\n\t\treturn _query_sum(a, b, 0, 0, n0);\n\t}\n\
    \n\t/// @brief \u5168\u4F53\u306E\u6700\u5927\u5024\u3092\u53D6\u5F97\n\t/// @return\
    \ \u5168\u4F53\u306E\u6700\u5927\u5024\n\tll all_prod_max() {\n\t\treturn prod_max(0,\
    \ n);\n\t}\n\n\t/// @brief \u5168\u4F53\u306E\u6700\u5C0F\u5024\u3092\u53D6\u5F97\
    \n\t/// @return \u5168\u4F53\u306E\u6700\u5C0F\u5024\n\tll all_prod_min() {\n\t\
    \treturn prod_min(0, n);\n\t}\n\n\t/// @brief \u5168\u4F53\u306E\u7DCF\u548C\u3092\
    \u53D6\u5F97\n\t/// @return \u5168\u4F53\u306E\u7DCF\u548C\n\tll all_prod_sum()\
    \ {\n\t\treturn prod_sum(0, n);\n\t}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: structure/ch_segtree.hpp
  requiredBy: []
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/ch_segtree.hpp
layout: document
redirect_from:
- /library/structure/ch_segtree.hpp
- /library/structure/ch_segtree.hpp.html
title: "\u30BB\u30B0\u6728\u3092\u914D\u5217\u306E\u5185\u5BB9\u3067\u521D\u671F\u5316\
  \u3059\u308B"
---
