#pragma once
#include "daylight/base.hpp"
template<typename T = ll>
struct Range {
private:
	pair<T, T> P;
	pair<bool, bool> bound;
	pair<bool, bool> inclusive;

public:
	Range() {
	}
	Range& left(T x, bool inclusive = true) {
		P.first = x;
		this->bound.first = true;
		this->inclusive.first = inclusive;
		return *this;
	}
	Range& right(T x, bool inclusive = true) {
		P.second = x;
		this->bound.second = true;
		this->inclusive.second = inclusive;
		return *this;
	}
	pair<bool, T> getLeft() {
		return { bound.first, P.first };
	}
	pair<bool, T> getRight() {
		return { bound.second, P.second };
	}
	bool isLeftInclusive() {
		return inclusive.first;
	}
	bool isRightInclusive() {
		return inclusive.second;
	}
};