#include "daylight/base.hpp"
#include "daylight/range.hpp"

/// @brief 区間をsetで管理するやつ
template<typename T>
struct RangeSet {
private:
	set<Range<T>> ranges;

public:
	RangeSet() {
	}

	/// @brief 区間を追加する
	Range<T> add(Range<T> r) {
		if(contains(r))
			return Range<T>().left(0, false).right(0,
												   false);
		auto it = ranges.lower_bound(r);
		if(it != ranges.begin()) {
			it--;
			if(it->contact(r)) {
				r.extendLeft(*it);
				ranges.erase(it);
			}
		}
		vector<Range<T>> to_erase;
		it = ranges.lower_bound(r);
		while(true) {
			if(it == ranges.end()) break;
			if(!r.contact(*it)) break;
			r.extendRight(*it);
			to_erase.push_back(*it);
			it++;
		}
		for(auto &e: to_erase) ranges.erase(e);
		ranges.insert(r);
		return r;
	}

	void remove(Range<T> r) {
		typename decltype(ranges)::iterator it
			= ranges.lower_bound(r);
		vector<Range<T>> to_erase;
		vector<Range<T>> to_insert;
		if(it != ranges.begin()) {
			it--;
			auto xa = r.getLeft();
			auto xb = it->getRight();
			if(it->contains(r)) {
				to_erase.push_back(*it);
				Range<T> tmp = *it;
				tmp.right(r.getLeft().second,
						  !r.isLeftInclusive());
				to_insert.push_back(tmp);
				tmp = *it;
				tmp.left(r.getRight().second,
						 !r.isRightInclusive());
				to_insert.push_back(tmp);
			} else if(!xa) {
				to_erase.push_back(*it);
			} else {
				if(!xb || xa.value() < xb.value()) {
					to_erase.push_back(*it);
					Range<T> tmp = *it;
					tmp.right(xa.value(),
							  !r.isLeftInclusive());
					to_insert.push_back(tmp);
				} else if(xa.value() == xb.value()
						  && r.isLeftInclusive()
						  && it->isRightInclusive()) {
					to_erase.push_back(*it);
					Range<T> tmp = *it;
					tmp.right(xb.value(), false);
					to_insert.push_back(tmp);
				}
			}
		}
		it = ranges.lower_bound(r);
		while(true) {
			if(it == ranges.end()) break;
			if(!r.contact(*it)) break;
			if(r.contains(*it))
				to_erase.push_back(*it);
			else {
				to_erase.push_back(*it);
				auto rb = r.getRight();
				if(rb) {
					Range<T> tmp = *it;
					tmp.left(rb.value(),
							 !r.isRightInclusive());
					to_insert.push_back(tmp);
				}
			}
			it++;
		}
		for(auto &e: to_erase) ranges.erase(e);
		for(auto &e: to_insert) ranges.insert(e);
	}

	optional<Range<T>> getLeft(Range<T> r) const {
		auto it = ranges.lower_bound(r);
		if(it != ranges.begin()) {
			it--;
			return *it;
		}
		return nullopt;
	}

	optional<Range<T>> getRight(Range<T> r) const {
		auto it = ranges.upper_bound(r);
		if(it != ranges.end()) {
			return *it;
		}
		return nullopt;
	}

	optional<Range<T>> get(T x) const {
		auto r = Range<T>().left(x, true).right(x, true);
		auto it = ranges.lower_bound(r);
		if(it != ranges.end()) {
			if(it->contains(r)) return *it;
		}
		if(it != ranges.begin()) {
			it--;
			if(it->contains(r)) return *it;
		}
		return nullopt;
	}

	bool contains(Range<T> r) const {
		auto it = ranges.lower_bound(r);
		if(it != ranges.end()) {
			if(it->contains(r)) return true;
		}
		if(it != ranges.begin()) {
			it--;
			if(it->contains(r)) return true;
		}
		return false;
	}

	vi getContainsRangeId(Range<T> r) const {
		vi ret;
		auto it = ranges.lower_bound(r);
		if(it != ranges.begin()) {
			it--;
			if(r.contains(*it)) ret.push_back(it->getId());
			it++;
		}
		while(true) {
			if(it == ranges.end()) break;
			if(!r.contains(*it)) break;
			ret.push_back(it->getId());
			it++;
		}
		return ret;
	}

	int getContainedRangeId(Range<T> r) const {
		auto it = ranges.lower_bound(r);
		if(it != ranges.end()) {
			if(it->contains(r)) return it->getId();
		}
		if(it != ranges.begin()) {
			it--;
			if(it->contains(r)) return it->getId();
		}
		return false;
	}

	vi getCrossRangeId(Range<T> r) const {
		vi ret;
		auto it = ranges.lower_bound(r);
		if(it != ranges.begin()) {
			it--;
			if(it->cross(r)) ret.push_back(it->getId());
			it++;
		}
		while(true) {
			if(it == ranges.end()) break;
			if(!r.cross(*it)) break;
			ret.push_back(it->getId());
			it++;
		}
		return ret;
	}

	vi getContactRangeId(Range<T> r) const {
		vi ret;
		auto it = ranges.lower_bound(r);
		if(it != ranges.begin()) {
			it--;
			if(it->contact(r)) ret.push_back(it->getId());
			it++;
		}
		while(true) {
			if(it == ranges.end()) break;
			if(!r.contact(*it)) break;
			ret.push_back(it->getId());
			it++;
		}
		return ret;
	}

	bool contains(T x) const {
		auto r = Range<T>().left(x, true).right(x, true);
		return contains(r);
	}

	vi getContainsRangeId(T x) const {
		auto r = Range<T>().left(x, true).right(x, true);
		return getContainsRangeId(r);
	}

	int getContainedRangeId(T x) const {
		auto r = Range<T>().left(x, true).right(x, true);
		return getContainedRangeId(r);
	}

	vi getCrossRangeId(T x) const {
		auto r = Range<T>().left(x, true).right(x, true);
		return getCrossRangeId(r);
	}

	vi getContactRangeId(T x) const {
		auto r = Range<T>().left(x, true).right(x, true);
		return getContactRangeId(r);
	}

	T countIntegerPoint(Range<T> r) const {
		auto it = ranges.lower_bound(r);
		T ret = 0;
		if(it != ranges.begin()) {
			it--;
			if(it->contact(r)) {
				auto R = r.intersect(*it);
				ret += R.countIntegerPoint();
			}
			it++;
		}
		while(true) {
			if(it == ranges.end()) break;
			if(!r.contact(*it)) break;
			auto R = r.intersect(*it);
			ret += R.countIntegerPoint();
			it++;
		}
		return ret;
	}

	T countMiddlePoint(Range<T> r) const {
		auto it = ranges.lower_bound(r);
		T ret = 0;
		if(it != ranges.begin()) {
			it--;
			if(it->contact(r)) {
				auto R = r.intersect(*it);
				ret += R.countMiddlePoint();
			}
			it++;
		}
		while(true) {
			if(it == ranges.end()) break;
			if(!r.contact(*it)) break;
			auto R = r.intersect(*it);
			ret += R.countMiddlePoint();
			it++;
		}
		return ret;
	}
};