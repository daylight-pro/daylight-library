#include "daylight/base.hpp"

/// @brief Sliding Window Aggregation

template<typename S>
struct FoldableStack {
private:
	function<S(S, S)> op;
	S e;
	struct Node {
		S value, sum;
		Node(const S &value, const S &sum)
			: value(value), sum(sum) {
		}
	};
	stack<Node> ST;
	bool reversed;

public:
	FoldableStack(const function<S(S, S)> &op, const S &e,
				  bool reversed = false)
		: op(op), e(e), reversed(reversed) {
	}

	void push(const S &s) {
		if(ST.empty())
			ST.emplace(s, s);
		else if(reversed)
			ST.emplace(s, op(s, ST.top().sum));
		else
			ST.emplace(s, op(ST.top().sum, s));
	}

	S pop() {
		assert(!ST.empty() && "FoldableStack is empty");
		S ret = ST.top().value;
		ST.pop();
		return ret;
	}

	S fold() const {
		if(ST.empty()) return e;
		return ST.top().sum;
	}

	S top() const {
		assert(!ST.empty() && "FoldableStack is empty");
		return ST.top().value;
	}

	bool empty() const {
		return ST.empty();
	}

	size_t size() const {
		return ST.size();
	}
};

template<typename S>
struct FoldableQueue {
private:
	FoldableStack<S> frontS, backS;
	function<S(S, S)> op;
	void move() {
		assert(!backS.empty());
		frontS.push(backS.pop());
		while(!backS.empty()) {
			frontS.push(backS.pop());
		}
	}

public:
	FoldableQueue(const function<S(S, S)> &op, const S &e)
		: frontS(op, e, true), backS(op, e), op(op) {
	}

	void push(const S &s) {
		backS.push(s);
	}

	S pop() {
		assert(!empty() && "FoldableQueue is empty");
		if(frontS.empty()) move();
		return frontS.pop();
	}

	S front() {
		assert(!empty() && "FoldableQueue is empty");
		if(frontS.empty()) move();
		return frontS.top();
	}

	S fold() const {
		return op(frontS.fold(), backS.fold());
	}

	bool empty() const {
		return frontS.empty() && backS.empty();
	}

	size_t size() const {
		return frontS.size() + backS.size();
	}
};

template<typename S>
struct FoldableDeque {
private:
	FoldableStack<S> frontS, backS;
	function<S(S, S)> op;
	void move() {
		if(frontS.empty()) {
			stack<S> tmp;
			int sz = backS.size();
			REP(_, sz / 2) {
				tmp.push(backS.pop());
			}
			while(!backS.empty()) {
				frontS.push(backS.pop());
			}
			while(!tmp.empty()) {
				backS.push(tmp.top());
				tmp.pop();
			}
		} else {
			stack<S> tmp;
			int sz = frontS.size();
			REP(_, sz / 2) {
				tmp.push(frontS.top());
				frontS.pop();
			}
			while(!frontS.empty()) {
				backS.push(frontS.pop());
			}
			while(!tmp.empty()) {
				frontS.push(tmp.top());
				tmp.pop();
			}
		}
	}

public:
	FoldableDeque(const function<S(S, S)> &op, const S &e)
		: frontS(op, e, true), backS(op, e), op(op) {
	}
	void push_front(const S &s) {
		frontS.push(s);
	}
	void push_back(const S &s) {
		backS.push(s);
	}

	S pop_front() {
		assert(!empty() && "FoldableDeque is empty");
		if(frontS.empty()) move();
		return frontS.pop();
	}

	S pop_back() {
		assert(!empty() && "FoldableDeque is empty");
		if(backS.empty()) move();
		return backS.pop();
	}

	S front() {
		assert(!empty() && "FoldableDeque is empty");
		if(frontS.empty()) move();
		return frontS.top();
	}

	S back() {
		assert(!empty() && "FoldableDeque is empty");
		if(backS.empty()) move();
		return backS.top();
	}

	S fold() const {
		return op(frontS.fold(), backS.fold());
	}

	bool empty() const {
		return frontS.empty() && backS.empty();
	}

	size_t size() const {
		return frontS.size() + backS.size();
	}
};
