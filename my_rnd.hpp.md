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
    document_title: "\u4E71\u6570\u69CB\u9020\u4F53"
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"my_rnd.hpp\"\n\
    \n/// @brief \u4E71\u6570\u69CB\u9020\u4F53\nstruct my_rnd {\n\tmt19937_64 randomEngine;\n\
    \tmy_rnd() {\n\t\trandom_device randomDevice;\n\t\tvector<uint32_t> randomSeedVector(10);\n\
    \t\tgenerate(randomSeedVector.begin(),\n\t\t\t\t randomSeedVector.end(), ref(randomDevice));\n\
    \t\tseed_seq randomSeed(randomSeedVector.begin(),\n\t\t\t\t\t\t\trandomSeedVector.end());\n\
    \t\trandomEngine = mt19937_64(randomSeed);\n\t}\n\n\t/// @brief 0\u4EE5\u4E0A\
    upper\u672A\u6E80\u306E\u6574\u6570\u3092\u4E00\u3064\u30E9\u30F3\u30C0\u30E0\u306B\
    \u53D6\u5F97\u3059\u308B\n\t/// @param upper \u4E71\u6570\u306E\u4E0A\u9650\u5024\
    (exclusive)\n\t/// @return 0\u4EE5\u4E0Aupper\u672A\u6E80\u306E\u30E9\u30F3\u30C0\
    \u30E0\u306A\u6574\u6570\n\tint nextInt(int upper) {\n\t\tuniform_int_distribution<int>\
    \ randomIntDistribution(\n\t\t\t0, upper - 1);\n\t\treturn randomIntDistribution(randomEngine);\n\
    \t}\n\n\t/// @brief lower\u4EE5\u4E0Aupper\u672A\u6E80\u306E\u6574\u6570\u3092\
    \u4E00\u3064\u30E9\u30F3\u30C0\u30E0\u306B\u53D6\u5F97\u3059\u308B\n\t/// @param\
    \ lower \u4E71\u6570\u306E\u4E0B\u9650\u5024(inclusive)\n\t/// @param upper \u4E71\
    \u6570\u306E\u4E0A\u9650\u5024(exclusive)\n\t/// @return lower\u4EE5\u4E0Aupper\u672A\
    \u6E80\u306E\u30E9\u30F3\u30C0\u30E0\u306A\u6574\u6570\n\tint nextInt(int lower,\
    \ int upper) {\n\t\tuniform_int_distribution<int> randomIntDistribution(\n\t\t\
    \tlower, upper - 1);\n\t\treturn randomIntDistribution(randomEngine);\n\t}\n\n\
    \t/// @brief 0\u4EE5\u4E0Aupper\u672A\u6E80\u306E\u6574\u6570\u3092\u4E00\u3064\
    \u30E9\u30F3\u30C0\u30E0\u306B\u53D6\u5F97\u3059\u308B\n\t/// @param upper \u4E71\
    \u6570\u306E\u4E0A\u9650\u5024(exclusive)\n\t/// @return 0\u4EE5\u4E0Aupper\u672A\
    \u6E80\u306E\u30E9\u30F3\u30C0\u30E0\u306A\u6574\u6570\n\tll nextLong(ll upper)\
    \ {\n\t\tuniform_int_distribution<ll> randomIntDistribution(\n\t\t\t0, upper -\
    \ 1);\n\t\treturn randomIntDistribution(randomEngine);\n\t}\n\n\t/// @brief lower\u4EE5\
    \u4E0Aupper\u672A\u6E80\u306E\u6574\u6570\u3092\u4E00\u3064\u30E9\u30F3\u30C0\u30E0\
    \u306B\u53D6\u5F97\u3059\u308B\n\t/// @param lower \u4E71\u6570\u306E\u4E0B\u9650\
    \u5024(inclusive)\n\t/// @param upper \u4E71\u6570\u306E\u4E0A\u9650\u5024(exclusive)\n\
    \t/// @return lower\u4EE5\u4E0Aupper\u672A\u6E80\u306E\u30E9\u30F3\u30C0\u30E0\
    \u306A\u6574\u6570\n\tll nextLong(ll lower, ll upper) {\n\t\tuniform_int_distribution<ll>\
    \ randomIntDistribution(\n\t\t\tlower, upper - 1);\n\t\treturn randomIntDistribution(randomEngine);\n\
    \t}\n\n\t/// @brief 0\u4EE5\u4E0A1\u672A\u6E80\u306E\u5B9F\u6570\u3092\u30E9\u30F3\
    \u30C0\u30E0\u306B\u53D6\u5F97\u3059\u308B\n\t/// @return 0\u4EE5\u4E0A1\u672A\
    \u6E80\u306E\u30E9\u30F3\u30C0\u30E0\u306A\u5B9F\u6570\n\tdouble next() {\n\t\t\
    uniform_real_distribution<double>\n\t\t\trandomDoubleDistribution(0.0, 1.0);\n\
    \t\treturn randomDoubleDistribution(randomEngine);\n\t}\n\n\t/// @brief 0\u4EE5\
    \u4E0Aupper\u672A\u6E80\u306E\u5B9F\u6570\u3092\u30E9\u30F3\u30C0\u30E0\u306B\u53D6\
    \u5F97\u3059\u308B\n\t/// @param upper \u4E71\u6570\u306E\u4E0A\u9650\u5024(exclusive)\n\
    \t/// @return 0\u4EE5\u4E0Aupper\u672A\u6E80\u306E\u30E9\u30F3\u30C0\u30E0\u306A\
    \u5B9F\u6570\n\tdouble nextDouble(double upper) {\n\t\tuniform_real_distribution<double>\n\
    \t\t\trandomDoubleDistribution(0.0, upper);\n\t\treturn randomDoubleDistribution(randomEngine);\n\
    \t}\n};\n"
  code: "#include \"./base.hpp\"\n\n/// @brief \u4E71\u6570\u69CB\u9020\u4F53\nstruct\
    \ my_rnd {\n\tmt19937_64 randomEngine;\n\tmy_rnd() {\n\t\trandom_device randomDevice;\n\
    \t\tvector<uint32_t> randomSeedVector(10);\n\t\tgenerate(randomSeedVector.begin(),\n\
    \t\t\t\t randomSeedVector.end(), ref(randomDevice));\n\t\tseed_seq randomSeed(randomSeedVector.begin(),\n\
    \t\t\t\t\t\t\trandomSeedVector.end());\n\t\trandomEngine = mt19937_64(randomSeed);\n\
    \t}\n\n\t/// @brief 0\u4EE5\u4E0Aupper\u672A\u6E80\u306E\u6574\u6570\u3092\u4E00\
    \u3064\u30E9\u30F3\u30C0\u30E0\u306B\u53D6\u5F97\u3059\u308B\n\t/// @param upper\
    \ \u4E71\u6570\u306E\u4E0A\u9650\u5024(exclusive)\n\t/// @return 0\u4EE5\u4E0A\
    upper\u672A\u6E80\u306E\u30E9\u30F3\u30C0\u30E0\u306A\u6574\u6570\n\tint nextInt(int\
    \ upper) {\n\t\tuniform_int_distribution<int> randomIntDistribution(\n\t\t\t0,\
    \ upper - 1);\n\t\treturn randomIntDistribution(randomEngine);\n\t}\n\n\t/// @brief\
    \ lower\u4EE5\u4E0Aupper\u672A\u6E80\u306E\u6574\u6570\u3092\u4E00\u3064\u30E9\
    \u30F3\u30C0\u30E0\u306B\u53D6\u5F97\u3059\u308B\n\t/// @param lower \u4E71\u6570\
    \u306E\u4E0B\u9650\u5024(inclusive)\n\t/// @param upper \u4E71\u6570\u306E\u4E0A\
    \u9650\u5024(exclusive)\n\t/// @return lower\u4EE5\u4E0Aupper\u672A\u6E80\u306E\
    \u30E9\u30F3\u30C0\u30E0\u306A\u6574\u6570\n\tint nextInt(int lower, int upper)\
    \ {\n\t\tuniform_int_distribution<int> randomIntDistribution(\n\t\t\tlower, upper\
    \ - 1);\n\t\treturn randomIntDistribution(randomEngine);\n\t}\n\n\t/// @brief\
    \ 0\u4EE5\u4E0Aupper\u672A\u6E80\u306E\u6574\u6570\u3092\u4E00\u3064\u30E9\u30F3\
    \u30C0\u30E0\u306B\u53D6\u5F97\u3059\u308B\n\t/// @param upper \u4E71\u6570\u306E\
    \u4E0A\u9650\u5024(exclusive)\n\t/// @return 0\u4EE5\u4E0Aupper\u672A\u6E80\u306E\
    \u30E9\u30F3\u30C0\u30E0\u306A\u6574\u6570\n\tll nextLong(ll upper) {\n\t\tuniform_int_distribution<ll>\
    \ randomIntDistribution(\n\t\t\t0, upper - 1);\n\t\treturn randomIntDistribution(randomEngine);\n\
    \t}\n\n\t/// @brief lower\u4EE5\u4E0Aupper\u672A\u6E80\u306E\u6574\u6570\u3092\
    \u4E00\u3064\u30E9\u30F3\u30C0\u30E0\u306B\u53D6\u5F97\u3059\u308B\n\t/// @param\
    \ lower \u4E71\u6570\u306E\u4E0B\u9650\u5024(inclusive)\n\t/// @param upper \u4E71\
    \u6570\u306E\u4E0A\u9650\u5024(exclusive)\n\t/// @return lower\u4EE5\u4E0Aupper\u672A\
    \u6E80\u306E\u30E9\u30F3\u30C0\u30E0\u306A\u6574\u6570\n\tll nextLong(ll lower,\
    \ ll upper) {\n\t\tuniform_int_distribution<ll> randomIntDistribution(\n\t\t\t\
    lower, upper - 1);\n\t\treturn randomIntDistribution(randomEngine);\n\t}\n\n\t\
    /// @brief 0\u4EE5\u4E0A1\u672A\u6E80\u306E\u5B9F\u6570\u3092\u30E9\u30F3\u30C0\
    \u30E0\u306B\u53D6\u5F97\u3059\u308B\n\t/// @return 0\u4EE5\u4E0A1\u672A\u6E80\
    \u306E\u30E9\u30F3\u30C0\u30E0\u306A\u5B9F\u6570\n\tdouble next() {\n\t\tuniform_real_distribution<double>\n\
    \t\t\trandomDoubleDistribution(0.0, 1.0);\n\t\treturn randomDoubleDistribution(randomEngine);\n\
    \t}\n\n\t/// @brief 0\u4EE5\u4E0Aupper\u672A\u6E80\u306E\u5B9F\u6570\u3092\u30E9\
    \u30F3\u30C0\u30E0\u306B\u53D6\u5F97\u3059\u308B\n\t/// @param upper \u4E71\u6570\
    \u306E\u4E0A\u9650\u5024(exclusive)\n\t/// @return 0\u4EE5\u4E0Aupper\u672A\u6E80\
    \u306E\u30E9\u30F3\u30C0\u30E0\u306A\u5B9F\u6570\n\tdouble nextDouble(double upper)\
    \ {\n\t\tuniform_real_distribution<double>\n\t\t\trandomDoubleDistribution(0.0,\
    \ upper);\n\t\treturn randomDoubleDistribution(randomEngine);\n\t}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: my_rnd.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: my_rnd.hpp
layout: document
redirect_from:
- /library/my_rnd.hpp
- /library/my_rnd.hpp.html
title: "\u4E71\u6570\u69CB\u9020\u4F53"
---
