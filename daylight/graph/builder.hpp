#pragma once
#include "daylight/base.hpp"
#include "daylight/graph/base.hpp"

/// @brief グラフビルダー
template<typename T = ll>
class GraphBuilder {
private:
	int N, M;
	Graph<T> G;
	int index = 1;
	bool m_weighted = false;
	bool m_directed = false;
	bool m_tree_format = false;

public:
	GraphBuilder(int N): N(N), M(N - 1) {
		G = Graph<T>(N);
	}

	GraphBuilder(int N, int M): N(N), M(M) {
		G = Graph<T>(N);
	}

	GraphBuilder& setIndex(int index = 1) {
		this->index = index;
		return *this;
	}

	GraphBuilder& weighted(bool weighted = true) {
		this->m_weighted = weighted;
		return *this;
	}

	GraphBuilder& directed(bool directed = true) {
		this->m_directed = directed;
		return *this;
	}

	GraphBuilder& useTreeFormat(bool tree_format = true) {
		this->m_tree_format = tree_format;
		return *this;
	}

	Graph<T> build(istream& in) {
		if(this->m_tree_format) {
			FOR(i, 1, N) {
				int p;
				cin >> p;
				p -= index;
				T c(1);
				if(m_weighted) {
					in >> c;
				}
				G[p].eb(p, i, c);
				if(!m_directed) {
					G[i].eb(i, p, c);
				}
			}
		} else {
			REP(i, M) {
				int u, v;
				in >> u >> v;
				u -= index;
				v -= index;
				T c(1);
				if(m_weighted) {
					in >> c;
				}
				G[u].eb(u, v, c);
				if(!m_directed) {
					G[v].eb(v, u, c);
				}
			}
		}
		return G;
	}

	vector<vector<T>> buildMatrix(istream& in,
								  T non_edge = LINF) {
		vector<vector<T>> G(N, vector<T>(N, non_edge));
		if(this->m_tree_format) {
			FOR(i, 1, N) {
				int p;
				cin >> p;
				p -= index;
				T c(1);
				if(m_weighted) {
					in >> c;
				}
				G[p][i] = c;
				if(!m_directed) {
					G[i][p] = c;
				}
			}
		} else {
			REP(i, M) {
				int u, v;
				in >> u >> v;
				u -= index;
				v -= index;
				T c(1);
				if(m_weighted) {
					in >> c;
				}
				G[u][v] = c;
				if(!m_directed) {
					G[v][u] = c;
				}
			}
		}
		return G;
	}

	Edges<T> buildEdgeList(istream& in) {
		Edges<T> edges;
		if(this->m_tree_format) {
			FOR(i, 1, N) {
				int p;
				cin >> p;
				p -= index;
				T c(1);
				if(m_weighted) {
					in >> c;
				}
				edges.eb(p, i, c);
				if(!m_directed) {
					edges.eb(i, p, c);
				}
			}
		} else {
			REP(i, M) {
				int u, v;
				in >> u >> v;
				u -= index;
				v -= index;
				T c(1);
				if(m_weighted) {
					in >> c;
				}
				edges.eb(u, v, c);
				if(!m_directed) {
					edges.eb(v, u, c);
				}
			}
		}
		return edges;
	}
};