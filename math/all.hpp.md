---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base.hpp
    title: base.hpp
  - icon: ':warning:'
    path: math/comb.hpp
    title: math/comb.hpp
  - icon: ':warning:'
    path: math/diviser.hpp
    title: "\u7D04\u6570\u3092\u5168\u5217\u6319\u3059\u308B"
  - icon: ':warning:'
    path: math/eratos.hpp
    title: math/eratos.hpp
  - icon: ':warning:'
    path: math/extgcd.hpp
    title: "gcd(a,b)\u3068ax+by=gcd(a,b)\u3092\u6E80\u305F\u3059x,y\u3092\u6C42\u3081\
      \u308B"
  - icon: ':warning:'
    path: math/fact.hpp
    title: "Modint\u7528\u306E\u968E\u4E57\u8A08\u7B97\u95A2\u6570\u3067\u3059\u3002"
  - icon: ':warning:'
    path: math/gcd_lcm.hpp
    title: math/gcd_lcm.hpp
  - icon: ':warning:'
    path: math/geometry.hpp
    title: "a\u3068b\u306E\u5185\u7A4D\u3092\u6C42\u3081\u308B"
  - icon: ':warning:'
    path: math/powmod.hpp
    title: math/powmod.hpp
  - icon: ':warning:'
    path: math/prime_factor.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3\u3092\u3059\u308B"
  - icon: ':warning:'
    path: math/rational.hpp
    title: "\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
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
    \ vec) {\n\tos << join(vec, \" \");\n\treturn os;\n}\n#line 2 \"math/comb.hpp\"\
    \ntemplate<typename T>\nstruct Comb {\nprivate:\n\tvector<T> _fact;\n\tvector<T>\
    \ inv;\n\tint pre_build;\n\tvoid expand(int x) {\n\t\tif(pre_build == -1) return;\n\
    \t\twhile(SZ(_fact) <= x) {\n\t\t\tint next = SZ(_fact);\n\t\t\t_fact.push_back(_fact[next\
    \ - 1] * next);\n\t\t\tinv.push_back(_fact[next].inv());\n\t\t}\n\t}\n\n\tT nPr_calc(int\
    \ n, int r) {\n\t\tT ret = 1;\n\t\tfor(int i = n; i > n - r; i--) ret *= i;\n\t\
    \treturn ret;\n\t}\n\tT nCr_calc(int n, int r) {\n\t\tT ret = 1;\n\t\tREP(i, r)\
    \ {\n\t\t\tret *= n - i;\n\t\t\tret /= i + 1;\n\t\t}\n\t\treturn ret;\n\t}\n\n\
    public:\n\tComb(int pre_build = 0): pre_build(pre_build) {\n\t\tif(pre_build ==\
    \ -1) {\n\t\t\treturn;\n\t\t}\n\t\t_fact = vector<T>(pre_build + 1);\n\t\t_fact[0]\
    \ = 1;\n\t\tinv = vector<T>(pre_build + 1);\n\t\tREP(i, pre_build) {\n\t\t\t_fact[i\
    \ + 1] = _fact[i] * (i + 1);\n\t\t}\n\t\tinv[pre_build] = _fact[pre_build].inv();\n\
    \t\tREPR(i, pre_build) {\n\t\t\tinv[i] = inv[i + 1] * (i + 1);\n\t\t}\n\t}\n\t\
    T nPr(int n, int r) {\n\t\tassert(r >= 0);\n\t\tassert(n >= r);\n\t\texpand(n);\n\
    \t\tif(pre_build == -1) return nPr_calc(n, r);\n\t\treturn _fact[n] * inv[n -\
    \ r];\n\t}\n\tT nCr(int n, int r) {\n\t\tassert(r >= 0);\n\t\tassert(n >= r);\n\
    \t\texpand(n);\n\t\tif(pre_build == -1) return nCr_calc(n, r);\n\t\treturn _fact[n]\
    \ * inv[r] * inv[n - r];\n\t}\n\tT nHr(int n, int r) {\n\t\tassert(r >= 0);\n\t\
    \tassert(n >= 1);\n\t\texpand(n + r - 1);\n\t\treturn nCr(n + r - 1, r);\n\t}\n\
    \tT type_permission(vi V) {\n\t\tassert(pre_build != -1);\n\t\tint sum = 0;\n\t\
    \tfor(int i: V) {\n\t\t\tassert(i >= 0);\n\t\t\tsum += i;\n\t\t}\n\t\texpand(sum);\n\
    \t\tT ans = _fact[sum];\n\t\tfor(int i: V) ans *= inv[i];\n\t\treturn ans;\n\t\
    }\n\tT fact(int n) {\n\t\texpand(n);\n\t\treturn _fact[n];\n\t}\n\tT inv_fact(int\
    \ n) {\n\t\texpand(n);\n\t\treturn inv[n];\n\t}\n};\n#line 2 \"math/diviser.hpp\"\
    \n/// @brief \u7D04\u6570\u3092\u5168\u5217\u6319\u3059\u308B\n/// @param N \u6574\
    \u6570N\n/// @return N\u306E\u7D04\u6570\u304C\u5C0F\u3055\u3044\u9806\u306B\u683C\
    \u7D0D\u3055\u308C\u305F\u30EA\u30B9\u30C8\nvll get_divisers(ll N) {\n\tvll ret;\n\
    \tfor(ll i = 1; i * i <= N; i++) {\n\t\tif(N % i == 0) {\n\t\t\tret.push_back(i);\n\
    \t\t\tif(i * i != N) ret.push_back(N / i);\n\t\t}\n\t}\n\tso(ret);\n\treturn ret;\n\
    }\n#line 2 \"math/eratos.hpp\"\nvoid eratos(int n, vb& isprime) {\n\tisprime =\
    \ vb(n + 1, true);\n\tisprime[0] = false;\n\tisprime[1] = false;\n\tint last =\
    \ ((int) sqrt(n)) + 1;\n\tFOR(i, 2, last) {\n\t\tif(isprime[i]) {\n\t\t\tint j\
    \ = i + i;\n\t\t\twhile(j <= n) {\n\t\t\t\tisprime[j] = false;\n\t\t\t\tj += i;\n\
    \t\t\t}\n\t\t}\n\t}\n}\n#line 2 \"math/extgcd.hpp\"\n/// @brief gcd(a,b)\u3068\
    ax+by=gcd(a,b)\u3092\u6E80\u305F\u3059x,y\u3092\u6C42\u3081\u308B\n/// @param\
    \ a \u5165\u529B1\u3064\u76EE\n/// @param b \u5165\u529B2\u3064\u76EE\n/// @param\
    \ x \u51FA\u529B1\u3064\u76EE\n/// @param y \u51FA\u529B2\u3064\u76EE\n/// @return\
    \ gcd(a,b)\nll extgcd(ll a, ll b, ll& x, ll& y) {\n\tll d = a;\n\tif(b != 0) {\n\
    \t\td = extgcd(b, a % b, y, x);\n\t\ty -= (a / b) * x;\n\t} else {\n\t\tx = 1;\n\
    \t\ty = 0;\n\t}\n\treturn d;\n}\n\n/// @brief \u4EFB\u610F\u306Em\u306B\u3064\u3044\
    \u3066n^{-1} mod m\u3092\u6C42\u3081\u308B.\n/// @param n \u9006\u5143\u3092\u6C42\
    \u3081\u305F\u3044\u5024\n/// @param m \u6CD5(\u7D20\u6570\u3067\u306A\u304F\u3066\
    \u3082\u3088\u3044)\n/// @return \u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1,\u5B58\
    \u5728\u3059\u308B\u306A\u3089\u9006\u5143\nll inv_extgcd(ll n, ll m) {\n\tll\
    \ x, y;\n\tll G = extgcd(n, m, x, y);\n\tif(G != 1) {\n\t\treturn -1;\n\t}\n\t\
    if(x < 0) {\n\t\tx += (abs(x) + 2 * m) / m * m;\n\t}\n\tx %= m;\n\treturn x;\n\
    }\n#line 3 \"math/powmod.hpp\"\nll powmod(ll a, ll p, ll m = MOD) {\n\tll ans\
    \ = 1;\n\tll mul = a;\n\tfor(; p > 0; p >>= 1) {\n\t\tif(p & 1) ans = (ans * mul)\
    \ % m;\n\t\t//mul\u3092\u66F4\u65B0\u30022\u56DE\u5206\u306E\u64CD\u4F5C\u3092\
    \u5165\u308C\u308B\u3002\n\t\tmul = (mul * mul) % m;\n\t}\n\treturn ans;\n}\n\
    #line 3 \"math/fact.hpp\"\n/// @brief Modint\u7528\u306E\u968E\u4E57\u8A08\u7B97\
    \u95A2\u6570\u3067\u3059\u3002\n/// @tparam T modint\u306E\u578B\n/// @param N\
    \ \u6C42\u3081\u308B\u968E\u4E57\u306E\u6700\u5927\u5024\n/// @param fact out:\u968E\
    \u4E57\ntemplate<class T>\nvoid setFact(int N, vector<T> &fact) {\n\tfact = vector<T>(N\
    \ + 1);\n\tfact[0] = T(1);\n\tFOR(i, 1, N + 1) {\n\t\tfact[i] = fact[i - 1] *\
    \ i;\n\t}\n}\n/// @brief ll\u7528\u306E\u968E\u4E57\u304A\u3088\u3073\u305D\u306E\
    \u9006\u5143\u8A08\u8A08\u7B97\u95A2\u6570\u3067\u3002\n/// @param N \u6C42\u3081\
    \u308B\u4F1A\u5834\u306E\u6700\u5927\u5024\n/// @param fact out:\u968E\u4E57\n\
    /// @param inv out:\u968E\u4E57\u306E\u9006\u5143\nvoid setFact(int N, vll &fact,\
    \ vll &inv) {\n\tfact = vector<ll>(N + 1);\n\tinv = vector<ll>(N + 1);\n\tfact[0]\
    \ = 1;\n\tFOR(i, 1, N + 1) {\n\t\tfact[i] = (fact[i - 1] * i) % MOD;\n\t}\n\t\
    inv[N] = powmod(fact[N], MOD - 2);\n\tREPR(i, N) {\n\t\tinv[i] = inv[i + 1] *\
    \ (i + 1) % MOD;\n\t}\n}\n#line 2 \"math/gcd_lcm.hpp\"\nll gcd(ll x, ll y) {\n\
    \tll r = 0;\n\tif(x < y) swap(x, y);\n\twhile(y > 0) {\n\t\tr = x % y;\n\t\tx\
    \ = y;\n\t\ty = r;\n\t}\n\treturn x;\n}\n\nll lcm(ll a, ll b) {\n\treturn a /\
    \ gcd(a, b) * b;\n}\n#line 2 \"math/geometry.hpp\"\ntypedef complex<double> Point;\n\
    typedef complex<double> Vec;\ntypedef pair<Point, Point> Line;\n#define X real()\n\
    #define Y imag()\n\nistream &operator>>(istream &is, Point &p) {\n\tdouble x,\
    \ y;\n\tis >> x >> y;\n\tp = Point(x, y);\n\treturn is;\n}\n\n/// @brief a\u3068\
    b\u306E\u5185\u7A4D\u3092\u6C42\u3081\u308B\n/// @param a \u4E00\u3064\u76EE\u306E\
    \u30D9\u30AF\u30C8\u30EB\n/// @param b \u4E8C\u3064\u76EE\u306E\u30D9\u30AF\u30C8\
    \u30EB\n/// @return a\u30FBb\ndouble dot(const Vec &a, const Vec &b) {\n\treturn\
    \ a.X * b.Y + a.X * b.Y;\n}\n\n/// @brief a\u3068b\u306E\u5916\u7A4D\u3092\u6C42\
    \u3081\u308B\n/// @param a \u4E00\u3064\u76EE\u306E\u30D9\u30AF\u30C8\u30EB\n\
    /// @param b \u4E8C\u3064\u76EE\u306E\u30D9\u30AF\u30C8\u30EB\n/// @return a\xD7\
    b\ndouble cross(const Vec &a, const Vec &b) {\n\treturn a.X * b.Y - a.Y * b.X;\n\
    }\n\n/// @brief \u30D9\u30AF\u30C8\u30EB\u306E\u5927\u304D\u3055\u3092\u6C42\u3081\
    \u308B\n/// @param v \u5927\u304D\u3055\u3092\u6C42\u3081\u308B\u30D9\u30AF\u30C8\
    \u30EB\n/// @return \u30D9\u30AF\u30C8\u30EBv\u306E\u5927\u304D\u3055\ndouble\
    \ size(const Vec &v) {\n\treturn sqrt(v.X * v.X + v.Y + v.Y);\n}\n\n/// @brief\
    \ \u7DDA\u5206\u3092\u30D9\u30AF\u30C8\u30EB\u306B\u5909\u63DB\u3057\u307E\u3059\
    \u3002\n/// @param l \u5909\u63DB\u3059\u308B\u7DDA\u5206\n/// @return \u7DDA\u5206\
    \u306E\u4E00\u3064\u76EE\u306E\u70B9\u304B\u3089\u4E8C\u3064\u3082\u306E\u70B9\
    \u3078\u306E\u30D9\u30AF\u30C8\u30EB\nVec convertToVector(const Line &l) {\n\t\
    return { l.second.X - l.first.X,\n\t\t\t l.second.Y - l.first.Y };\n}\n\n/// @brief\
    \ \u70B9\u3068\u7DDA\u5206\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\u3002\n///\
    \ @param p \u70B9\n/// @param l \u7DDA\u5206\n/// @return \u70B9\u3068\u7DDA\u5206\
    \u306E\u8DDD\u96E2\ndouble distance(const Point &p, const Line &l) {\n\tVec BA\
    \ = { p.X - l.first.X, p.Y - l.first.Y };\n\tVec BC = convertToVector(l);\n\t\
    Vec CA = { p.X - l.second.X, p.Y - l.second.Y };\n\tassert(size(BC) != 0);\n\t\
    if(dot(BA, BC) < 0) return size(BA);\n\tif(dot(CA, -BC) < 0) return size(CA);\n\
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
    }\n\treturn ret;\n}\n#line 2 \"math/prime_factor.hpp\"\n/// @brief \u7D20\u56E0\
    \u6570\u5206\u89E3\u3092\u3059\u308B\n/// @param n \u7D20\u56E0\u6570\u5206\u89E3\
    \u3059\u308B\u6574\u6570\n/// @return map[p]=a:p^a\u304C\u56E0\u6570\u306B\u542B\
    \u307E\u308C\u308B\nmap<ll, int> prime_factor(ll n) {\n\tmap<ll, int> ret;\n\t\
    for(ll i = 2; i * i <= n; i++) {\n\t\twhile(n % i == 0) {\n\t\t\tret[i]++;\n\t\
    \t\tn /= i;\n\t\t}\n\t}\n\tif(n != 1) ret[n] = 1;\n\treturn ret;\n}\n/// @brief\
    \ \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306E\u524D\u8A08\u7B97\u3092\u884C\
    \u3046\n/// @param n \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u3092\u884C\u3046\
    \u6574\u6570\u306E\u6700\u5927\u5024\n/// @return \u9AD8\u901F\u7D20\u56E0\u6570\
    \u5206\u89E3\u7528\u306E\u7BE9\u914D\u5217\nvi sieve(int n) {\n\tn++;\n\tvi res(n);\n\
    \tstd::iota(res.begin(), res.end(), 0);\n\tfor(int i = 2; i * i < n; ++i) {\n\t\
    \tif(res[i] < i) continue;\n\t\tfor(int j = i * i; j < n; j += i)\n\t\t\tif(res[j]\
    \ == j) res[j] = i;\n\t}\n\treturn res;\n}\n\n/// @brief \u524D\u8A08\u7B97\u3057\
    \u305F\u7BE9\u914D\u5217\u3092\u7528\u3044\u3066\u9AD8\u901F\u7D20\u56E0\u6570\
    \u5206\u89E3\n/// @param n \u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\u6574\u6570\
    \n/// @param min_factor \u524D\u8A08\u7B97\u3057\u305F\u7BE9\u914D\u5217\n///\
    \ @return map[p]=a:p^a\u304C\u56E0\u6570\u306B\u542B\u307E\u308C\u308B\nmap<int,\
    \ int> factor(int n, const vi& min_factor) {\n\tmap<int, int> res;\n\twhile(n\
    \ > 1) {\n\t\tres[min_factor[n]]++;\n\t\tn /= min_factor[n];\n\t}\n\treturn res;\n\
    }\n#line 2 \"math/rational.hpp\"\ntemplate<typename S = __int128_t, bool doReduction\
    \ = true>\nstruct Rational {\nprivate:\n\tS child, parent;\n\tS originalChild,\
    \ originalParent;\n\tusing R = Rational<S, doReduction>;\n\npublic:\n\tRational()\
    \ {\n\t\tR(0, 1);\n\t}\n\t/// @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n\t/// @param c \u5206\u5B50\n\t/// @param p \u5206\u6BCD\n\tRational(S c, S\
    \ p) {\n\t\tassert(p != 0);\n\t\toriginalChild = c;\n\t\toriginalParent = p;\n\
    \t\tif(c == 0) {\n\t\t\tchild = 0;\n\t\t\tparent = 1;\n\t\t} else if(!doReduction)\
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
    };\n#line 11 \"math/all.hpp\"\n"
  code: '#include "./comb.hpp"

    #include "./diviser.hpp"

    #include "./eratos.hpp"

    #include "./extgcd.hpp"

    #include "./fact.hpp"

    #include "./gcd_lcm.hpp"

    #include "./geometry.hpp"

    #include "./powmod.hpp"

    #include "./prime_factor.hpp"

    #include "./rational.hpp"'
  dependsOn:
  - math/comb.hpp
  - base.hpp
  - math/diviser.hpp
  - math/eratos.hpp
  - math/extgcd.hpp
  - math/fact.hpp
  - math/powmod.hpp
  - math/gcd_lcm.hpp
  - math/geometry.hpp
  - math/prime_factor.hpp
  - math/rational.hpp
  isVerificationFile: false
  path: math/all.hpp
  requiredBy: []
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/all.hpp
layout: document
redirect_from:
- /library/math/all.hpp
- /library/math/all.hpp.html
title: math/all.hpp
---
