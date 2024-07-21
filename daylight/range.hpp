#pragma once
#include "daylight/base.hpp"
template<typename T = ll>
struct Range {
private:
	pair<T, T> P;
	pair<bool, bool> bound;
	pair<bool, bool> inclusive;
	int _id = -1;

public:
	Range() {
	}
	Range& left() {
		bound.first = false;
		inclusive.first = false;
		return *this;
	}
	Range& right() {
		bound.second = false;
		inclusive.second = false;
		return *this;
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
	Range& id(int id) {
		this->_id = id;
		return *this;
	}
	int getId() const {
		return _id;
	}
	optional<T> getLeft() const {
		if(!bound.first) return nullopt;
		return P.first;
	}
	optional<T> getRight() const {
		if(!bound.second) return nullopt;
		return P.second;
	}
	bool isLeftInclusive() const {
		return inclusive.first;
	}
	bool isRightInclusive() const {
		return inclusive.second;
	}
	bool isLeftBound() const {
		return bound.first;
	}
	bool isRightBound() const {
		return bound.second;
	}

	// 1 : this < r
	// 0 : this == r
	// -1 : this > r
	int compareLeft(const Range<T>& r) const {
		if(bound.first && !r.bound.first) return -1;
		if(!bound.first && r.bound.first) return 1;
		if(!bound.first && !r.bound.first) return 0;
		if(P.first < r.P.first) return 1;
		if(P.first > r.P.first) return -1;
		if(inclusive.first && !r.inclusive.first) return 1;
		if(!inclusive.first && r.inclusive.first) return -1;
		return 0;
	}

	int compareRight(const Range<T>& r) const {
		if(bound.second && !r.bound.second) return 1;
		if(!bound.second && r.bound.second) return -1;
		if(!bound.second && !r.bound.second) return 0;
		if(P.second < r.P.second) return 1;
		if(P.second > r.P.second) return -1;
		if(inclusive.second && !r.inclusive.second)
			return -1;
		if(!inclusive.second && r.inclusive.second)
			return 1;
		return 0;
	}
	bool operator<(const Range<T>& r) const {
		int leftcmp = compareLeft(r);
		int rightcmp = compareRight(r);
		if(leftcmp == 1) return true;
		if(leftcmp == -1) return false;
		if(rightcmp == 1) return true;
		if(rightcmp == -1) return false;
		return false;
	}

	bool cross(const Range<T>& r) const {
		Range<T> a = *this;
		Range<T> b = r;
		if(a.compareLeft(b) == -1) swap(a, b);
		auto ra = a.getRight();
		auto lb = b.getLeft();
		if((!ra) || (!lb)) return true;
		return ra.value() > lb.value();
	}

	bool contact(const Range<T>& r) const {
		Range<T> a = *this;
		Range<T> b = r;
		if(a.compareLeft(b) == -1) swap(a, b);
		auto ra = a.getRight();
		auto lb = b.getLeft();
		if((!ra) || (!lb)) return true;
		return ra.value() > lb.value()
			|| ((a.isRightInclusive()
				 || b.isLeftInclusive())
				&& ra.value() == lb.value());
	}

	bool contains(const Range<T>& r) const {
		int leftcmp = compareLeft(r);
		int rightcmp = compareRight(r);
		return leftcmp != -1 && rightcmp != 1;
	}

	bool contained(const Range<T>& r) const {
		return r.contains(this);
	}

	void extendLeft(const Range<T>& r) {
		if(compareLeft(r) == -1) {
			auto ret = r.getLeft();
			if(!ret)
				left();
			else
				left(ret.value(), r.isLeftInclusive());
		}
	}

	void extendRight(const Range<T>& r) {
		if(compareRight(r) == 1) {
			auto ret = r.getRight();
			if(!ret)
				right();
			else
				right(ret.value(), r.isRightInclusive());
		}
	}

	T countIntegerPoint() const {
		if(!bound.first || !bound.second) return 0;
		T ret = P.second - P.first - 1;
		if(inclusive.first) ret++;
		if(inclusive.second) ret++;
		return max(T(0), ret);
	}

	T countMiddlePoint() const {
		if(!bound.first || !bound.second) return 0;
		return max(T(0), P.second - P.first);
	}

	Range<T> intersect(const Range<T>& r) const {
		auto ret = r;
		if(compareLeft(r) == -1)
			ret.left(P.first, inclusive.first);
		if(compareRight(r) == 1)
			ret.right(P.second, inclusive.second);
		return ret;
	}

	bool empty() const {
		auto l = getLeft();
		auto r = getRight();
		if(!l || !r) return false;
		return l.value() == r.value()
			&& (!isLeftInclusive() || !isRightInclusive());
	}

	bool operator==(const Range<T>& r) const {
		return compareLeft(r) == 0 && compareRight(r) == 0;
	}
};