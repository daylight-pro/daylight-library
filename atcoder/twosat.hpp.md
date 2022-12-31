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
    title: "\u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\u3092\u6C42\u3081\
      \u308B"
  - icon: ':warning:'
    path: graph/manhattan_mst.hpp
    title: graph/manhattan_mst.hpp
  - icon: ':warning:'
    path: math/modlog.hpp
    title: "a^n=b(mod m)\u3068\u306A\u308B\u6700\u5C0F\u306En\u3092\u6C42\u3081\u308B"
  - icon: ':warning:'
    path: structure/editable_priority_queue.hpp
    title: "\u914D\u5217\u306Ei\u756A\u76EE\u306E\u5024\u306B\u30A2\u30AF\u30BB\u30B9\
      \u3059\u308B"
  - icon: ':warning:'
    path: structure/segtree_builder.hpp
    title: structure/segtree_builder.hpp
  - icon: ':warning:'
    path: structure/zobrist_hash.hpp
    title: "\u96C6\u5408\u3092\u30CF\u30C3\u30B7\u30E5\u3059\u308B\u69CB\u9020\u4F53"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/twosat.hpp\"\n\n\n\n#include <atcoder/internal_scc>\n\
    #include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\n// Reference:\n\
    // B. Aspvall, M. Plass, and R. Tarjan,\n// A Linear-Time Algorithm for Testing\
    \ the Truth of Certain Quantified Boolean\n// Formulas\nstruct two_sat {\n  public:\n\
    \    two_sat() : _n(0), scc(0) {}\n    two_sat(int n) : _n(n), _answer(n), scc(2\
    \ * n) {}\n\n    void add_clause(int i, bool f, int j, bool g) {\n        assert(0\
    \ <= i && i < _n);\n        assert(0 <= j && j < _n);\n        scc.add_edge(2\
    \ * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));\n        scc.add_edge(2 * j + (g ?\
    \ 0 : 1), 2 * i + (f ? 1 : 0));\n    }\n    bool satisfiable() {\n        auto\
    \ id = scc.scc_ids().second;\n        for (int i = 0; i < _n; i++) {\n       \
    \     if (id[2 * i] == id[2 * i + 1]) return false;\n            _answer[i] =\
    \ id[2 * i] < id[2 * i + 1];\n        }\n        return true;\n    }\n    std::vector<bool>\
    \ answer() { return _answer; }\n\n  private:\n    int _n;\n    std::vector<bool>\
    \ _answer;\n    internal::scc_graph scc;\n};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_TWOSAT_HPP\n#define ATCODER_TWOSAT_HPP 1\n\n#include <atcoder/internal_scc>\n\
    #include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\n// Reference:\n\
    // B. Aspvall, M. Plass, and R. Tarjan,\n// A Linear-Time Algorithm for Testing\
    \ the Truth of Certain Quantified Boolean\n// Formulas\nstruct two_sat {\n  public:\n\
    \    two_sat() : _n(0), scc(0) {}\n    two_sat(int n) : _n(n), _answer(n), scc(2\
    \ * n) {}\n\n    void add_clause(int i, bool f, int j, bool g) {\n        assert(0\
    \ <= i && i < _n);\n        assert(0 <= j && j < _n);\n        scc.add_edge(2\
    \ * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));\n        scc.add_edge(2 * j + (g ?\
    \ 0 : 1), 2 * i + (f ? 1 : 0));\n    }\n    bool satisfiable() {\n        auto\
    \ id = scc.scc_ids().second;\n        for (int i = 0; i < _n; i++) {\n       \
    \     if (id[2 * i] == id[2 * i + 1]) return false;\n            _answer[i] =\
    \ id[2 * i] < id[2 * i + 1];\n        }\n        return true;\n    }\n    std::vector<bool>\
    \ answer() { return _answer; }\n\n  private:\n    int _n;\n    std::vector<bool>\
    \ _answer;\n    internal::scc_graph scc;\n};\n\n}  // namespace atcoder\n\n#endif\
    \  // ATCODER_TWOSAT_HPP\n"
  dependsOn:
  - atcoder/internal_scc.hpp
  isVerificationFile: false
  path: atcoder/twosat.hpp
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
documentation_of: atcoder/twosat.hpp
layout: document
redirect_from:
- /library/atcoder/twosat.hpp
- /library/atcoder/twosat.hpp.html
title: atcoder/twosat.hpp
---
