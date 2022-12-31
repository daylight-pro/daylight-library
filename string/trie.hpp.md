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
    document_title: "\u30C8\u30E9\u30A4\u6728"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"string/trie.hpp\"\
    \n/// @brief \u30C8\u30E9\u30A4\u6728\n/// @tparam alphabet \u30A2\u30EB\u30D5\
    \u30A1\u30D9\u30C3\u30C8\u306E\u7A2E\u985E\u6570\n/// @tparam base \u30D9\u30FC\
    \u30B9\u3068\u306A\u308B\u30A2\u30EB\u30D5\u30A1\u30D9\u30C3\u30C8\ntemplate<int\
    \ alphabet, char base>\nstruct Trie {\n\tstruct Node {\n\t\tvi next;  //\u6B21\
    \u306E\u9802\u70B9\u756A\u53F7\n\t\tint num;  //\u3053\u306E\u9802\u70B9\u3067\
    \u7D42\u308F\u308B\u6587\u5B57\u5217\u306E\u6570\n\t\tint common;\t //\u3053\u306E\
    \u9802\u70B9\u3092\u901A\u308B\u6587\u5B57\u5217\u306E\u6570\n\t\tNode() {\n\t\
    \t\tnext.assign(alphabet, -1);\n\t\t\tnum = 0;\n\t\t\tcommon = 0;\n\t\t}\n\t};\n\
    \tvector<Node> nodes;\n\tTrie() {\n\t\tnodes.push_back(Node());\n\t}\n\t/// @brief\
    \ \u5358\u8A9Eword\u3092\u633F\u5165\n\t/// @param word \u633F\u5165\u3059\u308B\
    \u5358\u8A9E\n\tvoid insert(const string& word) {\n\t\tint cur = 0;\n\t\tnodes[0].common++;\n\
    \t\tREP(i, SZ(word)) {\n\t\t\tif(nodes[cur].next[word[i] - base] == -1) {\n\t\t\
    \t\tnodes[cur].next[word[i] - base]\n\t\t\t\t\t= node_count();\n\t\t\t\tcur =\
    \ node_count();\n\t\t\t\tnodes.push_back(Node());\n\t\t\t\tnodes[cur].common++;\n\
    \t\t\t} else {\n\t\t\t\tcur = nodes[cur].next[word[i] - base];\n\t\t\t\tnodes[cur].common++;\n\
    \t\t\t}\n\t\t}\n\t\tnodes[cur].num++;\n\t}\n\t/// @brief \u5358\u8A9E\u3092\u691C\
    \u7D22\u3059\u308B\u3002prefix\u304Ctrue\u306A\u3089\u5358\u8A9E\u3092prefix\u306B\
    \u6301\u3064\u5358\u8A9E\u304C\u3042\u308B\u304B\u8ABF\u3079\u308B\n\t/// @param\
    \ word \u691C\u7D22\u3059\u308B\u5358\u8A9E\n\t/// @param prefix \u691C\u7D22\u3092\
    prefix\u3067\u884C\u3046\u304B\u3069\u3046\u304B\n\t/// @return \u898B\u3064\u304B\
    \u3063\u305F\u3089true\n\tbool search(const string& word, bool prefix = false)\
    \ {\n\t\tint cur = 0;\n\t\tREP(i, SZ(word)) {\n\t\t\tcur = nodes[cur].next[word[i]\
    \ - base];\n\t\t\tif(cur == -1) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t}\n\t\t\
    return prefix || nodes[cur].num > 0;\n\t}\n\t/// @brief word\u306B\u6CBF\u3063\
    \u3066\u3001Trie\u6728\u3092dfs\u3059\u308B\u3002\n\t/// @param word \u9032\u884C\
    \u65B9\u5411\u3092\u8868\u3059\u5358\u8A9E\n\t/// @param f f(node,i)i\u756A\u76EE\
    \u306E\u6587\u5B57\u307E\u3067\u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\
    \u304Cnode\u3060\u3063\u305F\u6642\u306E\u51E6\u7406\n\tvoid dfs(const string&\
    \ word,\n\t\t\t const function<void(Node&, int)>& f) {\n\t\tint cur = 0;\n\t\t\
    f(nodes[cur], 0);\n\t\tREP(i, SZ(word)) {\n\t\t\tcur = nodes[cur].next[word[i]\
    \ - base];\n\t\t\tif(cur == -1) return;\n\t\t\tf(nodes[cur], i + 1);\n\t\t}\n\t\
    }\n\t/// @brief Trie\u6728\u306B\u633F\u5165\u3055\u308C\u305F\u5358\u8A9E\u306E\
    \u6570\u3092\u53D6\u5F97\n\t/// @return \u633F\u5165\u3055\u308C\u305F\u5358\u8A9E\
    \u6570\n\tsize_t size() const {\n\t\treturn nodes[0].common;\n\t}\n\t/// @brief\
    \ \u73FE\u5728\u306ETrie\u6728\u306E\u30CE\u30FC\u30C9\u6570\u3092\u6C42\u3081\
    \u308B\n\t/// @return \u73FE\u5728\u306E\u30CE\u30FC\u30C9\u6570\n\tint node_count()\
    \ const {\n\t\treturn SZ(nodes);\n\t}\n};\n"
  code: "#include \"../base.hpp\"\n/// @brief \u30C8\u30E9\u30A4\u6728\n/// @tparam\
    \ alphabet \u30A2\u30EB\u30D5\u30A1\u30D9\u30C3\u30C8\u306E\u7A2E\u985E\u6570\n\
    /// @tparam base \u30D9\u30FC\u30B9\u3068\u306A\u308B\u30A2\u30EB\u30D5\u30A1\u30D9\
    \u30C3\u30C8\ntemplate<int alphabet, char base>\nstruct Trie {\n\tstruct Node\
    \ {\n\t\tvi next;  //\u6B21\u306E\u9802\u70B9\u756A\u53F7\n\t\tint num;  //\u3053\
    \u306E\u9802\u70B9\u3067\u7D42\u308F\u308B\u6587\u5B57\u5217\u306E\u6570\n\t\t\
    int common;\t //\u3053\u306E\u9802\u70B9\u3092\u901A\u308B\u6587\u5B57\u5217\u306E\
    \u6570\n\t\tNode() {\n\t\t\tnext.assign(alphabet, -1);\n\t\t\tnum = 0;\n\t\t\t\
    common = 0;\n\t\t}\n\t};\n\tvector<Node> nodes;\n\tTrie() {\n\t\tnodes.push_back(Node());\n\
    \t}\n\t/// @brief \u5358\u8A9Eword\u3092\u633F\u5165\n\t/// @param word \u633F\
    \u5165\u3059\u308B\u5358\u8A9E\n\tvoid insert(const string& word) {\n\t\tint cur\
    \ = 0;\n\t\tnodes[0].common++;\n\t\tREP(i, SZ(word)) {\n\t\t\tif(nodes[cur].next[word[i]\
    \ - base] == -1) {\n\t\t\t\tnodes[cur].next[word[i] - base]\n\t\t\t\t\t= node_count();\n\
    \t\t\t\tcur = node_count();\n\t\t\t\tnodes.push_back(Node());\n\t\t\t\tnodes[cur].common++;\n\
    \t\t\t} else {\n\t\t\t\tcur = nodes[cur].next[word[i] - base];\n\t\t\t\tnodes[cur].common++;\n\
    \t\t\t}\n\t\t}\n\t\tnodes[cur].num++;\n\t}\n\t/// @brief \u5358\u8A9E\u3092\u691C\
    \u7D22\u3059\u308B\u3002prefix\u304Ctrue\u306A\u3089\u5358\u8A9E\u3092prefix\u306B\
    \u6301\u3064\u5358\u8A9E\u304C\u3042\u308B\u304B\u8ABF\u3079\u308B\n\t/// @param\
    \ word \u691C\u7D22\u3059\u308B\u5358\u8A9E\n\t/// @param prefix \u691C\u7D22\u3092\
    prefix\u3067\u884C\u3046\u304B\u3069\u3046\u304B\n\t/// @return \u898B\u3064\u304B\
    \u3063\u305F\u3089true\n\tbool search(const string& word, bool prefix = false)\
    \ {\n\t\tint cur = 0;\n\t\tREP(i, SZ(word)) {\n\t\t\tcur = nodes[cur].next[word[i]\
    \ - base];\n\t\t\tif(cur == -1) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t}\n\t\t\
    return prefix || nodes[cur].num > 0;\n\t}\n\t/// @brief word\u306B\u6CBF\u3063\
    \u3066\u3001Trie\u6728\u3092dfs\u3059\u308B\u3002\n\t/// @param word \u9032\u884C\
    \u65B9\u5411\u3092\u8868\u3059\u5358\u8A9E\n\t/// @param f f(node,i)i\u756A\u76EE\
    \u306E\u6587\u5B57\u307E\u3067\u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\
    \u304Cnode\u3060\u3063\u305F\u6642\u306E\u51E6\u7406\n\tvoid dfs(const string&\
    \ word,\n\t\t\t const function<void(Node&, int)>& f) {\n\t\tint cur = 0;\n\t\t\
    f(nodes[cur], 0);\n\t\tREP(i, SZ(word)) {\n\t\t\tcur = nodes[cur].next[word[i]\
    \ - base];\n\t\t\tif(cur == -1) return;\n\t\t\tf(nodes[cur], i + 1);\n\t\t}\n\t\
    }\n\t/// @brief Trie\u6728\u306B\u633F\u5165\u3055\u308C\u305F\u5358\u8A9E\u306E\
    \u6570\u3092\u53D6\u5F97\n\t/// @return \u633F\u5165\u3055\u308C\u305F\u5358\u8A9E\
    \u6570\n\tsize_t size() const {\n\t\treturn nodes[0].common;\n\t}\n\t/// @brief\
    \ \u73FE\u5728\u306ETrie\u6728\u306E\u30CE\u30FC\u30C9\u6570\u3092\u6C42\u3081\
    \u308B\n\t/// @return \u73FE\u5728\u306E\u30CE\u30FC\u30C9\u6570\n\tint node_count()\
    \ const {\n\t\treturn SZ(nodes);\n\t}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: "\u30C8\u30E9\u30A4\u6728"
---
