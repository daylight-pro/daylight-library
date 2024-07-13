#include "daylight/base.hpp"
#include "daylight/graph/base.hpp"

template<typename T = ll>
class GraphBuilder {
private:
	int N, M;
	Graph<T> G;
	int index = 1;
	bool weighted = false;
	bool directed = true;

public:
	GraphBuilder(int N, int M): N(N), M(M) {
		G = Graph<T>(N);
	}

	GraphBuilder& setIndex(int index) {
		this->index = index;
		return *this;
	}

	GraphBuilder& setWeighted(bool weighted) {
		this->weighted = true;
		return *this;
	}

	GraphBuilder& setDirected(bool directed) {
		this->directed = directed;
		return *this;
	}

	Graph<T> build(istream& in) {
		REP(i, M) {
			int u, v;
			in >> u >> v;
			T c(1);
			if(weighted) {
				in >> c;
			}
			G[u].eb(u, v, c);
			if(!directed) {
				G[v].eb(v, u, c);
			}
		}
		return G;
	}
};

template<typename T = ll>
class TreeBuilder: public GraphBuilder<T> {
public:
	TreeBuilder(int N): GraphBuilder<T>(N, N - 1) {
	}
};