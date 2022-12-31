---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/potential_uf.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUF"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u53EF\u63DB\u7FA4\u30E9\u30A4\u30D6\u30E9\u30EA"
    links: []
  bundledCode: "#line 2 \"structure/abel.hpp\"\n/// @brief \u53EF\u63DB\u7FA4\u30E9\
    \u30A4\u30D6\u30E9\u30EA\n\ntemplate<typename T>\nstruct AbelAdd {\n\tusing value_type\
    \ = T;\n\tstatic constexpr T op(const T& a, const T& b) noexcept {\n\t\treturn\
    \ a + b;\n\t}\n\tstatic constexpr T inv(const T& a) noexcept {\n\t\treturn -a;\n\
    \t}\n\tstatic constexpr T e() {\n\t\treturn T(0);\n\t}\n};\ntemplate<typename\
    \ T>\nstruct AbelXor {\n\tusing value_type = T;\n\tstatic constexpr T op(const\
    \ T& a, const T& b) noexcept {\n\t\treturn a ^ b;\n\t}\n\tstatic constexpr T inv(const\
    \ T& a) noexcept {\n\t\treturn a;\n\t}\n\tstatic constexpr T e() {\n\t\treturn\
    \ T(0);\n\t}\n};\n"
  code: "#pragma once\n/// @brief \u53EF\u63DB\u7FA4\u30E9\u30A4\u30D6\u30E9\u30EA\
    \n\ntemplate<typename T>\nstruct AbelAdd {\n\tusing value_type = T;\n\tstatic\
    \ constexpr T op(const T& a, const T& b) noexcept {\n\t\treturn a + b;\n\t}\n\t\
    static constexpr T inv(const T& a) noexcept {\n\t\treturn -a;\n\t}\n\tstatic constexpr\
    \ T e() {\n\t\treturn T(0);\n\t}\n};\ntemplate<typename T>\nstruct AbelXor {\n\
    \tusing value_type = T;\n\tstatic constexpr T op(const T& a, const T& b) noexcept\
    \ {\n\t\treturn a ^ b;\n\t}\n\tstatic constexpr T inv(const T& a) noexcept {\n\
    \t\treturn a;\n\t}\n\tstatic constexpr T e() {\n\t\treturn T(0);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/abel.hpp
  requiredBy:
  - structure/potential_uf.hpp
  timestamp: '2022-12-31 14:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/abel.hpp
layout: document
redirect_from:
- /library/structure/abel.hpp
- /library/structure/abel.hpp.html
title: "\u53EF\u63DB\u7FA4\u30E9\u30A4\u30D6\u30E9\u30EA"
---
