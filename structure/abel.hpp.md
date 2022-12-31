---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/potential_uf.hpp
    title: "\u9802\u70B9x\u3068\u9802\u70B9y\u304C\u9023\u7D50\u304B\u5224\u5B9A\u3059\
      \u308B"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/abel.hpp\"\ntemplate<typename T>\nstruct AbelAdd\
    \ {\n\tusing value_type = T;\n\tstatic constexpr T op(const T& a, const T& b)\
    \ noexcept {\n\t\treturn a + b;\n\t}\n\tstatic constexpr T inv(const T& a) noexcept\
    \ {\n\t\treturn -a;\n\t}\n\tstatic constexpr T e() {\n\t\treturn T(0);\n\t}\n\
    };\ntemplate<typename T>\nstruct AbelXor {\n\tusing value_type = T;\n\tstatic\
    \ constexpr T op(const T& a, const T& b) noexcept {\n\t\treturn a ^ b;\n\t}\n\t\
    static constexpr T inv(const T& a) noexcept {\n\t\treturn a;\n\t}\n\tstatic constexpr\
    \ T e() {\n\t\treturn T(0);\n\t}\n};\n"
  code: "#pragma once\ntemplate<typename T>\nstruct AbelAdd {\n\tusing value_type\
    \ = T;\n\tstatic constexpr T op(const T& a, const T& b) noexcept {\n\t\treturn\
    \ a + b;\n\t}\n\tstatic constexpr T inv(const T& a) noexcept {\n\t\treturn -a;\n\
    \t}\n\tstatic constexpr T e() {\n\t\treturn T(0);\n\t}\n};\ntemplate<typename\
    \ T>\nstruct AbelXor {\n\tusing value_type = T;\n\tstatic constexpr T op(const\
    \ T& a, const T& b) noexcept {\n\t\treturn a ^ b;\n\t}\n\tstatic constexpr T inv(const\
    \ T& a) noexcept {\n\t\treturn a;\n\t}\n\tstatic constexpr T e() {\n\t\treturn\
    \ T(0);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/abel.hpp
  requiredBy:
  - structure/potential_uf.hpp
  timestamp: '2022-12-31 13:05:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/abel.hpp
layout: document
redirect_from:
- /library/structure/abel.hpp
- /library/structure/abel.hpp.html
title: structure/abel.hpp
---
