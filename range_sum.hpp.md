---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u533A\u9593\u548C"
    links: []
  bundledCode: "#line 1 \"range_sum.hpp\"\n/// @brief \u533A\u9593\u548C\n/// @tparam\
    \ T \u8981\u7D20\u306E\u578B\ntemplate<typename T>\nstruct RangeSum {\nprivate:\n\
    \tvector<T> V;\n\tint N = -1;\n\npublic:\n\tRangeSum(vector<T> &v) {\n\t\tN =\
    \ SZ(v);\n\t\tV = vector<T>(N + 1);\n\t\tV[0] = T(0);\n\t\tREP(i, N) {\n\t\t\t\
    V[i + 1] = v[i] + V[i];\n\t\t}\n\t}\n\n\t/// @brief \u533A\u9593[l,r)\u306E\u548C\
    \u3092\u6C42\u3081\u308B\n\t/// @param l \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\
    \t/// @param r \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n\t/// @return \u533A\
    \u9593[l,r)\u306E\u548C\n\tT sum(int l, int r) {\n\t\tchmax(l, 0);\n\t\tchmin(r,\
    \ N);\n\t\tchmax(r, l);\n\t\treturn V[r] - V[l];\n\t}\n};\n\ntemplate<typename\
    \ T>\nstruct RangeSum2D {\nprivate:\n\tvector<vector<T>> V;\n\tint H = -1;\n\t\
    int W = -1;\n\npublic:\n\tRangeSum2D(vector<vector<T>> &v) {\n\t\tH = SZ(v);\n\
    \t\tW = SZ(v[0]);\n\t\tV = vector<vector<T>>(H, vector<T>(W));\n\t\tREP(i, H)\
    \ {\n\t\t\tREP(j, W) {\n\t\t\t\tV[i][j] += v[i][j];\n\t\t\t\tif(i != 0) V[i][j]\
    \ += V[i - 1][j];\n\t\t\t\tif(j != 0) V[i][j] += V[i][j - 1];\n\t\t\t\tif(i !=\
    \ 0 && j != 0)\n\t\t\t\t\tV[i][j] -= V[i - 1][j - 1];\n\t\t\t}\n\t\t}\n\t}\n\n\
    \t/// @brief 2\u70B9\u3092\u5BFE\u89D2\u306B\u6301\u3064\u9577\u65B9\u5F62\u9818\
    \u57DF\u306E\u548C\u3092\u8A08\u7B97\u3059\u308B(2\u70B9\u3068\u3082\u542B\u3080\
    )\n\t/// @param y1 \u5DE6\u4E0A\u306Ey\u5EA7\u6A19\n\t/// @param x1 \u5DE6\u4E0A\
    \u306Ex\u5EA7\u6A19\n\t/// @param y2 \u53F3\u4E0B\u306Ey\u5EA7\u6A19\n\t/// @param\
    \ x2 \u53F3\u4E0B\u306Ex\u5EA7\u6A19\n\t/// @return \u9577\u65B9\u5F62\u9818\u57DF\
    \u306E\u548C\n\tT sum(int y1, int x1, int y2, int x2) {\n\t\tT ret = V[y2][x2];\n\
    \t\tif(y1 != 0) ret -= V[y1 - 1][x2];\n\t\tif(x1 != 0) ret -= V[y2][x1 - 1];\n\
    \t\tif(y1 != 0 && x1 != 0) ret += V[y1 - 1][x1 - 1];\n\t\treturn ret;\n\t}\n};\n"
  code: "/// @brief \u533A\u9593\u548C\n/// @tparam T \u8981\u7D20\u306E\u578B\ntemplate<typename\
    \ T>\nstruct RangeSum {\nprivate:\n\tvector<T> V;\n\tint N = -1;\n\npublic:\n\t\
    RangeSum(vector<T> &v) {\n\t\tN = SZ(v);\n\t\tV = vector<T>(N + 1);\n\t\tV[0]\
    \ = T(0);\n\t\tREP(i, N) {\n\t\t\tV[i + 1] = v[i] + V[i];\n\t\t}\n\t}\n\n\t///\
    \ @brief \u533A\u9593[l,r)\u306E\u548C\u3092\u6C42\u3081\u308B\n\t/// @param l\
    \ \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\t/// @param r \u533A\u9593\u306E\
    \u53F3\u7AEF(exclusive)\n\t/// @return \u533A\u9593[l,r)\u306E\u548C\n\tT sum(int\
    \ l, int r) {\n\t\tchmax(l, 0);\n\t\tchmin(r, N);\n\t\tchmax(r, l);\n\t\treturn\
    \ V[r] - V[l];\n\t}\n};\n\ntemplate<typename T>\nstruct RangeSum2D {\nprivate:\n\
    \tvector<vector<T>> V;\n\tint H = -1;\n\tint W = -1;\n\npublic:\n\tRangeSum2D(vector<vector<T>>\
    \ &v) {\n\t\tH = SZ(v);\n\t\tW = SZ(v[0]);\n\t\tV = vector<vector<T>>(H, vector<T>(W));\n\
    \t\tREP(i, H) {\n\t\t\tREP(j, W) {\n\t\t\t\tV[i][j] += v[i][j];\n\t\t\t\tif(i\
    \ != 0) V[i][j] += V[i - 1][j];\n\t\t\t\tif(j != 0) V[i][j] += V[i][j - 1];\n\t\
    \t\t\tif(i != 0 && j != 0)\n\t\t\t\t\tV[i][j] -= V[i - 1][j - 1];\n\t\t\t}\n\t\
    \t}\n\t}\n\n\t/// @brief 2\u70B9\u3092\u5BFE\u89D2\u306B\u6301\u3064\u9577\u65B9\
    \u5F62\u9818\u57DF\u306E\u548C\u3092\u8A08\u7B97\u3059\u308B(2\u70B9\u3068\u3082\
    \u542B\u3080)\n\t/// @param y1 \u5DE6\u4E0A\u306Ey\u5EA7\u6A19\n\t/// @param x1\
    \ \u5DE6\u4E0A\u306Ex\u5EA7\u6A19\n\t/// @param y2 \u53F3\u4E0B\u306Ey\u5EA7\u6A19\
    \n\t/// @param x2 \u53F3\u4E0B\u306Ex\u5EA7\u6A19\n\t/// @return \u9577\u65B9\u5F62\
    \u9818\u57DF\u306E\u548C\n\tT sum(int y1, int x1, int y2, int x2) {\n\t\tT ret\
    \ = V[y2][x2];\n\t\tif(y1 != 0) ret -= V[y1 - 1][x2];\n\t\tif(x1 != 0) ret -=\
    \ V[y2][x1 - 1];\n\t\tif(y1 != 0 && x1 != 0) ret += V[y1 - 1][x1 - 1];\n\t\treturn\
    \ ret;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: range_sum.hpp
  requiredBy: []
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: range_sum.hpp
layout: document
redirect_from:
- /library/range_sum.hpp
- /library/range_sum.hpp.html
title: "\u533A\u9593\u548C"
---
