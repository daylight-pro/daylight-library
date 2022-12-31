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
    document_title: "\u30D0\u30A4\u30CA\u30EA\u30C8\u30E9\u30A4\u6728"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"structure/binary_trie.hpp\"\
    \n\n/// @brief \u30D0\u30A4\u30CA\u30EA\u30C8\u30E9\u30A4\u6728\n/// @tparam T\
    \ \u6574\u6570\u306E\u578B\n/// @tparam MAX_LOG \u30D3\u30C3\u30C8\u6570\ntemplate<typename\
    \ T, int MAX_LOG = 32>\nstruct BinaryTrie {\n\tstruct Node {\n\t\tvi next;  //\u6B21\
    \u306E\u9802\u70B9\u756A\u53F7\n\t\tint common;\t //\u3053\u306E\u9802\u70B9\u3092\
    \u901A\u308B\u6587\u5B57\u5217\u306E\u6570\n\t\tT lazy;\n\t\tNode() {\n\t\t\t\
    next.assign(2, -1);\n\t\t\tcommon = 0;\n\t\t\tlazy = 0;\n\t\t}\n\t};\n\n\tvector<Node>\
    \ nodes;\n\t/// @brief \u7A7A\u306E\u30C8\u30E9\u30A4\u6728\u3092\u751F\u6210\n\
    \tBinaryTrie() {\n\t\tnodes.push_back(Node());\n\t}\n\n\t/// @brief \u5168\u8981\
    \u7D20\u306B\u3064\u3044\u3066val\u3068\u306EXOR\u3067\u4E0A\u66F8\u304D\u3059\
    \u308B\n\t/// @param val\n\tvoid apply_xor(T val) {\n\t\tnodes[0].lazy ^= val;\n\
    \t}\n\nprivate:\n\t/// @brief \u9045\u5EF6\u4F1D\u64AD\n\t/// @param cur \u30CE\
    \u30FC\u30C9\u756A\u53F7\n\t/// @param b \u30D3\u30C3\u30C8\u756A\u53F7\n\tvoid\
    \ push(int cur, int b) {\n\t\tif((nodes[cur].lazy >> (T) b) & (T) 1) {\n\t\t\t\
    swap(nodes[cur].next[0], nodes[cur].next[1]);\n\t\t}\n\t\tREP(i, 2) {\n\t\t\t\
    if(nodes[cur].next[i] != -1) {\n\t\t\t\tnodes[nodes[cur].next[i]].lazy\n\t\t\t\
    \t\t^= nodes[cur].lazy;\n\t\t\t}\n\t\t}\n\t\tnodes[cur].lazy = 0;\n\t}\n\npublic:\n\
    \t/// @brief val\u3092\u30C8\u30E9\u30A4\u6728\u306B\u8FFD\u52A0\u3059\u308B\n\
    \t/// @param val \u8FFD\u52A0\u3059\u308B\u5024\n\t/// @param cur (\u30CE\u30FC\
    \u30C9\u756A\u53F7)\n\t/// @param b (\u30D3\u30C3\u30C8\u756A\u53F7)\n\tvoid add(T\
    \ val, int cur = 0, int b = MAX_LOG - 1) {\n\t\tnodes[cur].common++;\n\t\tif(b\
    \ < 0) {\n\t\t\treturn;\n\t\t}\n\t\tpush(cur, b);\n\t\tint nxt = (val >> (T) b)\
    \ & (T) 1;\n\t\tif(nodes[cur].next[nxt] == -1) {\n\t\t\tnodes[cur].next[nxt] =\
    \ SZ(nodes);\n\t\t\tnodes.push_back(Node());\n\t\t}\n\t\tadd(val, nodes[cur].next[nxt],\
    \ b - 1);\n\t}\n\t/// @brief val\u3092\u30C8\u30E9\u30A4\u6728\u304B\u3089\u524A\
    \u9664\u3059\u308B\n\t/// @param val \u524A\u9664\u3059\u308B\u5024\n\t/// @param\
    \ cur (\u30CE\u30FC\u30C9\u756A\u53F7)\n\t/// @param b (\u30D3\u30C3\u30C8\u756A\
    \u53F7)\n\tvoid erase(T val, int cur = 0, int b = MAX_LOG - 1) {\n\t\tassert(cur\
    \ != -1);\n\t\tnodes[cur].common--;\n\t\tif(b < 0) {\n\t\t\treturn;\n\t\t}\n\t\
    \tpush(cur, b);\n\t\tint nxt = (val >> (T) b) & (T) 1;\n\t\terase(val, nodes[cur].next[nxt],\
    \ b - 1);\n\t}\n\t/// @brief \u5168\u8981\u7D20\u3092bxor\u3068\u306EXOR\u3067\
    \u7F6E\u304D\u63DB\u3048\u305F\u3068\u304D,\u6700\u5C0F\u306E\u5024\n\t/// @param\
    \ bxor (\u4EFB\u610F)XOR\u3092\u53D6\u308B\u5024\n\t/// @param cur (\u30CE\u30FC\
    \u30C9\u756A\u53F7)\n\t/// @param b (\u30D3\u30C3\u30C8\u756A\u53F7)\n\t/// @return\
    \ \u6700\u5C0F\u5024\n\tT min_element(T bxor = 0, int cur = 0,\n\t\t\t\t  int\
    \ b = MAX_LOG - 1) {\n\t\tif(b < 0) return 0;\n\t\tpush(cur, b);\n\t\tint nxt\
    \ = (bxor >> (T) b) & (T) 1;\n\t\tint ind = nodes[cur].next[nxt];\n\t\tif(ind\
    \ == -1 || nodes[ind].common == 0) {\n\t\t\tnxt = nxt ^ 1;\n\t\t}\n\t\treturn\
    \ min_element(bxor, nodes[cur].next[nxt],\n\t\t\t\t\t\t   b - 1)\n\t\t\t| ((T)\
    \ nxt << (T) b);\n\t}\n\t/// @brief \u5168\u8981\u7D20\u3092bxor\u3068\u306EXOR\u3067\
    \u7F6E\u304D\u63DB\u3048\u305F\u3068\u304D,\u6700\u5927\u5024\u3092\u6C42\u3081\
    \u308B\n\t/// @param bxor (\u4EFB\u610F)XOR\u3092\u53D6\u308B\u5024\n\t/// @param\
    \ cur (\u30CE\u30FC\u30C9\u756A\u53F7)\n\t/// @param b (\u30D3\u30C3\u30C8\u756A\
    \u53F7)\n\t/// @return \u6700\u5927\u5024\n\tT max_element(T bxor = 0) {\n\t\t\
    return min_element(~bxor);\n\t}\n\t/// @brief val\u672A\u6E80\u306E\u8981\u7D20\
    \u306E\u6570\u3092\u6C42\u3081\u308B\n\t/// @param val \u691C\u7D22\u3059\u308B\
    \u5024\n\t/// @param cur (\u30CE\u30FC\u30C9\u756A\u53F7)\n\t/// @param b (\u30D3\
    \u30C3\u30C8\u756A\u53F7)\n\tint lower_bound_rank(T val, int cur = 0,\n\t\t\t\t\
    \t\t int b = MAX_LOG - 1) {\n\t\tif(cur == -1 || b < 0) return 0;\n\t\tpush(cur,\
    \ b);\n\t\tint nxt = (val >> (T) b) & (T) 1;\n\t\tint ret = lower_bound_rank(\n\
    \t\t\tval, nodes[cur].next[nxt], b - 1);\n\t\tif(nxt == 1 && nodes[cur].next[0]\
    \ != -1) {\n\t\t\tret += nodes[nodes[cur].next[0]].common;\n\t\t}\n\t\treturn\
    \ ret;\n\t}\n\n\t/// @brief val\u4EE5\u4E0B\u306E\u8981\u7D20\u306E\u6570\u3092\
    \u6C42\u3081\u308B\n\t/// @param val \u691C\u7D22\u3059\u308B\u5024\n\t/// @param\
    \ cur (\u30CE\u30FC\u30C9\u756A\u53F7)\n\t/// @param b (\u30D3\u30C3\u30C8\u756A\
    \u53F7)\n\tint upper_bound_rank(T val) {\n\t\treturn lower_bound_rank(val + 1);\n\
    \t}\n\n\t/// @brief k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u8981\u7D20\u3092\u6C42\
    \u3081\u308B\n\t/// @param k \u6C42\u3081\u308B\u8981\u7D20\u306E\u9806\u4F4D\
    (0-indexed)\n\t/// @param cur (\u30CE\u30FC\u30C9\u756A\u53F7)\n\t/// @param b\
    \ (\u30D3\u30C3\u30C8\u756A\u53F7)\n\t/// @return k\u756A\u76EE\u306B\u5C0F\u3055\
    \u3044\u8981\u7D20\n\tT kth_smallest(int k, int cur = 0,\n\t\t\t\t   int b = MAX_LOG\
    \ - 1) {\n\t\tif(b < 0) return 0;\n\t\tint lower_ind = nodes[cur].next[0];\n\t\
    \tint lower_cnt = 0;\n\t\tif(lower_ind != -1) {\n\t\t\tlower_cnt = nodes[lower_ind].common;\n\
    \t\t}\n\t\tif(k < lower_cnt) {\n\t\t\treturn kth_smallest(k, nodes[cur].next[0],\n\
    \t\t\t\t\t\t\t\tb - 1);\n\t\t} else {\n\t\t\treturn kth_smallest(k - lower_cnt,\n\
    \t\t\t\t\t\t\t\tnodes[cur].next[1], b - 1)\n\t\t\t\t| ((T) 1 << (T) b);\n\t\t\
    }\n\t}\n\t/// @brief k\u756A\u76EE\u306B\u5927\u304D\u3044\u8981\u7D20\u3092\u6C42\
    \u3081\u308B\n\t/// @param k \u6C42\u3081\u308B\u8981\u7D20\u306E\u9806\u4F4D\
    (0-indexed)\n\t/// @return k\u756A\u76EE\u306B\u5927\u304D\u3044\u8981\u7D20\n\
    \tT kth_largest(int k) {\n\t\treturn kth_smallest(SZ(size()) - 1 - k);\n\t}\n\n\
    \tT operator[](int k) {\n\t\treturn kth_smallest(k);\n\t}\n\n\t/// @brief val\u304C\
    \u30C8\u30E9\u30A4\u6728\u306B\u3044\u304F\u3064\u683C\u7D0D\u3055\u308C\u3066\
    \u3044\u308B\u304B\u6C42\u3081\u308B\n\t/// @param val \u691C\u7D22\u3059\u308B\
    \u5024\n\tint count(T val) {\n\t\tint cur = 0;\n\t\tREPR(b, MAX_LOG) {\n\t\t\t\
    push(cur, b);\n\t\t\tcur = nodes[cur].next[(val >> (T) b) & (T) 1];\n\t\t\tif(cur\
    \ == -1) return 0;\n\t\t}\n\t\treturn nodes[cur].common;\n\t}\n\t/// @brief \u30C8\
    \u30E9\u30A4\u6728\u306B\u683C\u7D0D\u3055\u308C\u305F\u6574\u6570\u306E\u6570\
    \u3092\u6570\u3048\u308B\n\t/// @return \u30C8\u30E9\u30A4\u6728\u306B\u683C\u7D0D\
    \u3055\u308C\u305F\u6574\u6570\u306E\u6570\n\tsize_t size() const {\n\t\treturn\
    \ nodes[0].common;\n\t}\n\t/// @brief \u30C8\u30E9\u30A4\u6728\u304C\u7A7A\u304B\
    \u5224\u5B9A\u3059\u308B\n\t/// @return \u30C8\u30E9\u30A4\u6728\u304C\u7A7A\u306A\
    \u3089true\n\tbool empty() const {\n\t\treturn nodes[0].common == 0;\n\t}\n};\n"
  code: "#include \"../base.hpp\"\n\n/// @brief \u30D0\u30A4\u30CA\u30EA\u30C8\u30E9\
    \u30A4\u6728\n/// @tparam T \u6574\u6570\u306E\u578B\n/// @tparam MAX_LOG \u30D3\
    \u30C3\u30C8\u6570\ntemplate<typename T, int MAX_LOG = 32>\nstruct BinaryTrie\
    \ {\n\tstruct Node {\n\t\tvi next;  //\u6B21\u306E\u9802\u70B9\u756A\u53F7\n\t\
    \tint common;\t //\u3053\u306E\u9802\u70B9\u3092\u901A\u308B\u6587\u5B57\u5217\
    \u306E\u6570\n\t\tT lazy;\n\t\tNode() {\n\t\t\tnext.assign(2, -1);\n\t\t\tcommon\
    \ = 0;\n\t\t\tlazy = 0;\n\t\t}\n\t};\n\n\tvector<Node> nodes;\n\t/// @brief \u7A7A\
    \u306E\u30C8\u30E9\u30A4\u6728\u3092\u751F\u6210\n\tBinaryTrie() {\n\t\tnodes.push_back(Node());\n\
    \t}\n\n\t/// @brief \u5168\u8981\u7D20\u306B\u3064\u3044\u3066val\u3068\u306E\
    XOR\u3067\u4E0A\u66F8\u304D\u3059\u308B\n\t/// @param val\n\tvoid apply_xor(T\
    \ val) {\n\t\tnodes[0].lazy ^= val;\n\t}\n\nprivate:\n\t/// @brief \u9045\u5EF6\
    \u4F1D\u64AD\n\t/// @param cur \u30CE\u30FC\u30C9\u756A\u53F7\n\t/// @param b\
    \ \u30D3\u30C3\u30C8\u756A\u53F7\n\tvoid push(int cur, int b) {\n\t\tif((nodes[cur].lazy\
    \ >> (T) b) & (T) 1) {\n\t\t\tswap(nodes[cur].next[0], nodes[cur].next[1]);\n\t\
    \t}\n\t\tREP(i, 2) {\n\t\t\tif(nodes[cur].next[i] != -1) {\n\t\t\t\tnodes[nodes[cur].next[i]].lazy\n\
    \t\t\t\t\t^= nodes[cur].lazy;\n\t\t\t}\n\t\t}\n\t\tnodes[cur].lazy = 0;\n\t}\n\
    \npublic:\n\t/// @brief val\u3092\u30C8\u30E9\u30A4\u6728\u306B\u8FFD\u52A0\u3059\
    \u308B\n\t/// @param val \u8FFD\u52A0\u3059\u308B\u5024\n\t/// @param cur (\u30CE\
    \u30FC\u30C9\u756A\u53F7)\n\t/// @param b (\u30D3\u30C3\u30C8\u756A\u53F7)\n\t\
    void add(T val, int cur = 0, int b = MAX_LOG - 1) {\n\t\tnodes[cur].common++;\n\
    \t\tif(b < 0) {\n\t\t\treturn;\n\t\t}\n\t\tpush(cur, b);\n\t\tint nxt = (val >>\
    \ (T) b) & (T) 1;\n\t\tif(nodes[cur].next[nxt] == -1) {\n\t\t\tnodes[cur].next[nxt]\
    \ = SZ(nodes);\n\t\t\tnodes.push_back(Node());\n\t\t}\n\t\tadd(val, nodes[cur].next[nxt],\
    \ b - 1);\n\t}\n\t/// @brief val\u3092\u30C8\u30E9\u30A4\u6728\u304B\u3089\u524A\
    \u9664\u3059\u308B\n\t/// @param val \u524A\u9664\u3059\u308B\u5024\n\t/// @param\
    \ cur (\u30CE\u30FC\u30C9\u756A\u53F7)\n\t/// @param b (\u30D3\u30C3\u30C8\u756A\
    \u53F7)\n\tvoid erase(T val, int cur = 0, int b = MAX_LOG - 1) {\n\t\tassert(cur\
    \ != -1);\n\t\tnodes[cur].common--;\n\t\tif(b < 0) {\n\t\t\treturn;\n\t\t}\n\t\
    \tpush(cur, b);\n\t\tint nxt = (val >> (T) b) & (T) 1;\n\t\terase(val, nodes[cur].next[nxt],\
    \ b - 1);\n\t}\n\t/// @brief \u5168\u8981\u7D20\u3092bxor\u3068\u306EXOR\u3067\
    \u7F6E\u304D\u63DB\u3048\u305F\u3068\u304D,\u6700\u5C0F\u306E\u5024\n\t/// @param\
    \ bxor (\u4EFB\u610F)XOR\u3092\u53D6\u308B\u5024\n\t/// @param cur (\u30CE\u30FC\
    \u30C9\u756A\u53F7)\n\t/// @param b (\u30D3\u30C3\u30C8\u756A\u53F7)\n\t/// @return\
    \ \u6700\u5C0F\u5024\n\tT min_element(T bxor = 0, int cur = 0,\n\t\t\t\t  int\
    \ b = MAX_LOG - 1) {\n\t\tif(b < 0) return 0;\n\t\tpush(cur, b);\n\t\tint nxt\
    \ = (bxor >> (T) b) & (T) 1;\n\t\tint ind = nodes[cur].next[nxt];\n\t\tif(ind\
    \ == -1 || nodes[ind].common == 0) {\n\t\t\tnxt = nxt ^ 1;\n\t\t}\n\t\treturn\
    \ min_element(bxor, nodes[cur].next[nxt],\n\t\t\t\t\t\t   b - 1)\n\t\t\t| ((T)\
    \ nxt << (T) b);\n\t}\n\t/// @brief \u5168\u8981\u7D20\u3092bxor\u3068\u306EXOR\u3067\
    \u7F6E\u304D\u63DB\u3048\u305F\u3068\u304D,\u6700\u5927\u5024\u3092\u6C42\u3081\
    \u308B\n\t/// @param bxor (\u4EFB\u610F)XOR\u3092\u53D6\u308B\u5024\n\t/// @param\
    \ cur (\u30CE\u30FC\u30C9\u756A\u53F7)\n\t/// @param b (\u30D3\u30C3\u30C8\u756A\
    \u53F7)\n\t/// @return \u6700\u5927\u5024\n\tT max_element(T bxor = 0) {\n\t\t\
    return min_element(~bxor);\n\t}\n\t/// @brief val\u672A\u6E80\u306E\u8981\u7D20\
    \u306E\u6570\u3092\u6C42\u3081\u308B\n\t/// @param val \u691C\u7D22\u3059\u308B\
    \u5024\n\t/// @param cur (\u30CE\u30FC\u30C9\u756A\u53F7)\n\t/// @param b (\u30D3\
    \u30C3\u30C8\u756A\u53F7)\n\tint lower_bound_rank(T val, int cur = 0,\n\t\t\t\t\
    \t\t int b = MAX_LOG - 1) {\n\t\tif(cur == -1 || b < 0) return 0;\n\t\tpush(cur,\
    \ b);\n\t\tint nxt = (val >> (T) b) & (T) 1;\n\t\tint ret = lower_bound_rank(\n\
    \t\t\tval, nodes[cur].next[nxt], b - 1);\n\t\tif(nxt == 1 && nodes[cur].next[0]\
    \ != -1) {\n\t\t\tret += nodes[nodes[cur].next[0]].common;\n\t\t}\n\t\treturn\
    \ ret;\n\t}\n\n\t/// @brief val\u4EE5\u4E0B\u306E\u8981\u7D20\u306E\u6570\u3092\
    \u6C42\u3081\u308B\n\t/// @param val \u691C\u7D22\u3059\u308B\u5024\n\t/// @param\
    \ cur (\u30CE\u30FC\u30C9\u756A\u53F7)\n\t/// @param b (\u30D3\u30C3\u30C8\u756A\
    \u53F7)\n\tint upper_bound_rank(T val) {\n\t\treturn lower_bound_rank(val + 1);\n\
    \t}\n\n\t/// @brief k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u8981\u7D20\u3092\u6C42\
    \u3081\u308B\n\t/// @param k \u6C42\u3081\u308B\u8981\u7D20\u306E\u9806\u4F4D\
    (0-indexed)\n\t/// @param cur (\u30CE\u30FC\u30C9\u756A\u53F7)\n\t/// @param b\
    \ (\u30D3\u30C3\u30C8\u756A\u53F7)\n\t/// @return k\u756A\u76EE\u306B\u5C0F\u3055\
    \u3044\u8981\u7D20\n\tT kth_smallest(int k, int cur = 0,\n\t\t\t\t   int b = MAX_LOG\
    \ - 1) {\n\t\tif(b < 0) return 0;\n\t\tint lower_ind = nodes[cur].next[0];\n\t\
    \tint lower_cnt = 0;\n\t\tif(lower_ind != -1) {\n\t\t\tlower_cnt = nodes[lower_ind].common;\n\
    \t\t}\n\t\tif(k < lower_cnt) {\n\t\t\treturn kth_smallest(k, nodes[cur].next[0],\n\
    \t\t\t\t\t\t\t\tb - 1);\n\t\t} else {\n\t\t\treturn kth_smallest(k - lower_cnt,\n\
    \t\t\t\t\t\t\t\tnodes[cur].next[1], b - 1)\n\t\t\t\t| ((T) 1 << (T) b);\n\t\t\
    }\n\t}\n\t/// @brief k\u756A\u76EE\u306B\u5927\u304D\u3044\u8981\u7D20\u3092\u6C42\
    \u3081\u308B\n\t/// @param k \u6C42\u3081\u308B\u8981\u7D20\u306E\u9806\u4F4D\
    (0-indexed)\n\t/// @return k\u756A\u76EE\u306B\u5927\u304D\u3044\u8981\u7D20\n\
    \tT kth_largest(int k) {\n\t\treturn kth_smallest(SZ(size()) - 1 - k);\n\t}\n\n\
    \tT operator[](int k) {\n\t\treturn kth_smallest(k);\n\t}\n\n\t/// @brief val\u304C\
    \u30C8\u30E9\u30A4\u6728\u306B\u3044\u304F\u3064\u683C\u7D0D\u3055\u308C\u3066\
    \u3044\u308B\u304B\u6C42\u3081\u308B\n\t/// @param val \u691C\u7D22\u3059\u308B\
    \u5024\n\tint count(T val) {\n\t\tint cur = 0;\n\t\tREPR(b, MAX_LOG) {\n\t\t\t\
    push(cur, b);\n\t\t\tcur = nodes[cur].next[(val >> (T) b) & (T) 1];\n\t\t\tif(cur\
    \ == -1) return 0;\n\t\t}\n\t\treturn nodes[cur].common;\n\t}\n\t/// @brief \u30C8\
    \u30E9\u30A4\u6728\u306B\u683C\u7D0D\u3055\u308C\u305F\u6574\u6570\u306E\u6570\
    \u3092\u6570\u3048\u308B\n\t/// @return \u30C8\u30E9\u30A4\u6728\u306B\u683C\u7D0D\
    \u3055\u308C\u305F\u6574\u6570\u306E\u6570\n\tsize_t size() const {\n\t\treturn\
    \ nodes[0].common;\n\t}\n\t/// @brief \u30C8\u30E9\u30A4\u6728\u304C\u7A7A\u304B\
    \u5224\u5B9A\u3059\u308B\n\t/// @return \u30C8\u30E9\u30A4\u6728\u304C\u7A7A\u306A\
    \u3089true\n\tbool empty() const {\n\t\treturn nodes[0].common == 0;\n\t}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/binary_trie.hpp
layout: document
redirect_from:
- /library/structure/binary_trie.hpp
- /library/structure/binary_trie.hpp.html
title: "\u30D0\u30A4\u30CA\u30EA\u30C8\u30E9\u30A4\u6728"
---
