---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: atcoder/internal_scc.hpp
    title: atcoder/internal_scc.hpp
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
    links: []
  bundledCode: "#line 1 \"atcoder/scc.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <atcoder/internal_scc>\n#include <cassert>\n#include <vector>\n\nnamespace atcoder\
    \ {\n\nstruct scc_graph {\n  public:\n    scc_graph() : internal(0) {}\n    scc_graph(int\
    \ n) : internal(n) {}\n\n    void add_edge(int from, int to) {\n        int n\
    \ = internal.num_vertices();\n        assert(0 <= from && from < n);\n       \
    \ assert(0 <= to && to < n);\n        internal.add_edge(from, to);\n    }\n\n\
    \    std::vector<std::vector<int>> scc() { return internal.scc(); }\n\n  private:\n\
    \    internal::scc_graph internal;\n};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_SCC_HPP\n#define ATCODER_SCC_HPP 1\n\n#include <algorithm>\n\
    #include <atcoder/internal_scc>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ atcoder {\n\nstruct scc_graph {\n  public:\n    scc_graph() : internal(0) {}\n\
    \    scc_graph(int n) : internal(n) {}\n\n    void add_edge(int from, int to)\
    \ {\n        int n = internal.num_vertices();\n        assert(0 <= from && from\
    \ < n);\n        assert(0 <= to && to < n);\n        internal.add_edge(from, to);\n\
    \    }\n\n    std::vector<std::vector<int>> scc() { return internal.scc(); }\n\
    \n  private:\n    internal::scc_graph internal;\n};\n\n}  // namespace atcoder\n\
    \n#endif  // ATCODER_SCC_HPP\n"
  dependsOn:
  - atcoder/internal_scc.hpp
  isVerificationFile: false
  path: atcoder/scc.hpp
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
documentation_of: atcoder/scc.hpp
layout: document
redirect_from:
- /library/atcoder/scc.hpp
- /library/atcoder/scc.hpp.html
title: atcoder/scc.hpp
---
