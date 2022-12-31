---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/all.hpp
    title: graph/all.hpp
  - icon: ':warning:'
    path: graph/kruskal.hpp
    title: "\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5"
  - icon: ':warning:'
    path: graph/manhattan_mst.hpp
    title: "\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3067MST"
  - icon: ':warning:'
    path: math/modlog.hpp
    title: "\u96E2\u6563\u5BFE\u6570"
  - icon: ':warning:'
    path: structure/editable_priority_queue.hpp
    title: "\u7DE8\u96C6\u53EF\u80FD\u30D7\u30E9\u30A4\u30AA\u30EA\u30C6\u30A3\u30FC\
      \u30AD\u30E5\u30FC"
  - icon: ':warning:'
    path: structure/segtree_builder.hpp
    title: structure/segtree_builder.hpp
  - icon: ':warning:'
    path: structure/zobrist_hash.hpp
    title: Zobrist Hash
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Fenwick_tree
  bundledCode: "#line 1 \"atcoder/fenwicktree.hpp\"\n\n\n\n#include <atcoder/internal_type_traits>\n\
    #include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\n// Reference:\
    \ https://en.wikipedia.org/wiki/Fenwick_tree\ntemplate <class T> struct fenwick_tree\
    \ {\n    using U = internal::to_unsigned_t<T>;\n\n  public:\n    fenwick_tree()\
    \ : _n(0) {}\n    fenwick_tree(int n) : _n(n), data(n) {}\n\n    void add(int\
    \ p, T x) {\n        assert(0 <= p && p < _n);\n        p++;\n        while (p\
    \ <= _n) {\n            data[p - 1] += U(x);\n            p += p & -p;\n     \
    \   }\n    }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        return sum(r) - sum(l);\n    }\n\n  private:\n    int _n;\n\
    \    std::vector<U> data;\n\n    U sum(int r) {\n        U s = 0;\n        while\
    \ (r > 0) {\n            s += data[r - 1];\n            r -= r & -r;\n       \
    \ }\n        return s;\n    }\n};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_FENWICKTREE_HPP\n#define ATCODER_FENWICKTREE_HPP 1\n\n#include\
    \ <atcoder/internal_type_traits>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ atcoder {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\ntemplate\
    \ <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n  public:\n    fenwick_tree() : _n(0) {}\n    fenwick_tree(int n) : _n(n), data(n)\
    \ {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n      \
    \  p++;\n        while (p <= _n) {\n            data[p - 1] += U(x);\n       \
    \     p += p & -p;\n        }\n    }\n\n    T sum(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n    }\n\n  private:\n\
    \    int _n;\n    std::vector<U> data;\n\n    U sum(int r) {\n        U s = 0;\n\
    \        while (r > 0) {\n            s += data[r - 1];\n            r -= r &\
    \ -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace atcoder\n\n\
    #endif  // ATCODER_FENWICKTREE_HPP\n"
  dependsOn:
  - atcoder/internal_type_traits.hpp
  isVerificationFile: false
  path: atcoder/fenwicktree.hpp
  requiredBy:
  - graph/kruskal.hpp
  - graph/all.hpp
  - graph/manhattan_mst.hpp
  - structure/zobrist_hash.hpp
  - structure/segtree_builder.hpp
  - structure/editable_priority_queue.hpp
  - math/modlog.hpp
  timestamp: '2022-12-31 13:55:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/fenwicktree.hpp
layout: document
redirect_from:
- /library/atcoder/fenwicktree.hpp
- /library/atcoder/fenwicktree.hpp.html
title: atcoder/fenwicktree.hpp
---
