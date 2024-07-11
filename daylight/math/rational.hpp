#include "daylight/base.hpp"
template<typename S = __int128_t, bool doReduction = true>
struct Rational {
private:
	S child, parent;
	S originalChild, originalParent;
	using R = Rational<S, doReduction>;

public:
	/// @brief コンストラクタ
	/// @param c 分子
	/// @param p 分母
	Rational(S c = S(0), S p = S(1)) {
		originalChild = c;
		originalParent = p;
		if(c == 0 && p == 0){
			child = 0;
			parent = 0;
		} else if(p == 0) {
			child = 1;
			parent = 0;
		} else if(c == 0) {
			child = 0;
			parent = 1;
		} else if(!doReduction) {
			child = c;
			parent = p;
		} else {
			S g = gcd(abs(c), abs(p));
			c /= g;
			p /= g;
			c *= p / abs(p);
			child = c;
			parent = abs(p);
		}
	}
	R operator+(const R& r) const {
		S new_p = parent * r.parent;
		S new_c = child * new_p / parent
			+ r.child * new_p / r.parent;
		return R(new_c, new_p);
	}
	R operator+(const ll& l) const {
		return *this + R(l);
	}
	R operator-(const R& r) const {
		S new_p = parent * r.parent;
		S new_c = child * new_p / parent
			- r.child * new_p / r.parent;
		return R(new_c, new_p);
	}
	R operator-(const ll& l) const {
		return *this - R(l);
	}
	R operator*(const R& r) const {
		return R(child * r.child, parent * r.parent);
	}
	R operator*(const ll& l) const {
		return *this * R(l);
	}
	R operator/(const R& r) const {
		return R(child * r.parent, parent * r.child);
	}
	R operator/(const ll& l) const {
		return *this / R(l);
	}
	R& operator+=(const R& r){
		S new_p = parent * r.parent;
		S new_c = child * new_p / parent
			+ r.child * new_p / r.parent;
		S g = gcd(new_p, new_c);
		parent = new_p / g;
		child = new_c / g;
		return *this;
	}
	R& operator-=(const R& r){
		S new_p = parent * r.parent;
		S new_c = child * new_p / parent
			- r.child * new_p / r.parent;
		S g = gcd(new_p, new_c);
		parent = new_p / g;
		child = new_c / g;
		return *this;
	}
	R& operator*=(const R& r){
		S new_p = parent * r.parent;
		S new_c = child * r.child;
		S g = gcd(new_p, new_c);
		parent = new_p / g;
		child = new_c / g;
		return *this;
	}
	R& operator/=(const R& r){
		S new_p = parent * r.child;
		S new_c = child * r.parent;
		S g = gcd(new_p, new_c);
		parent = new_p / g;
		child = new_c / g;
		return *this;
	}
	bool operator==(const R& r) const {
		return child == r.child && parent == r.parent;
	}
	bool operator==(const ll& r) const {
		return *this == R(r);
	}
	bool operator!=(const R& r) const {
		return child != r.child || parent != r.parent;
	}
	bool operator!=(const ll& r) const {
		return *this != R(r);
	}
	bool operator<(const R& r) const {
		return child * r.parent < parent * r.child;
	}
	bool operator<(const ll& r) const {
		return &this < R(r);
	}
	bool operator>(const R& r) const {
		return child * r.parent > parent * r.child;
	}
	bool operator>(const ll& r) const {
		return *this > R(r);
	}
	bool operator<=(const R& r) const {
		return !(*this > r);
	}
	bool operator<=(const ll& r) const {
		return *this <= R(r);
	}
	bool operator>=(const R& r) const {
		return !(*this < r);
	}
	bool operator>=(const ll& r) const {
		return *this >= R(r);
	}
	R inv() const {
		return R(parent, child);
	}
	ll getChild() const {
		return ll(child);
	}
	ll getParent() const {
		return ll(parent);
	}
	ll getOriginalChild() const {
		return originalChild;
	}
	ll getOriginalParent() const {
		return originalParent;
	}
	/// @brief 分数を少数に変換する
	/// @return 分数の表す少数
	double getDouble() {
		return double(child) / parent;
	}
	bool isNaN() const {
		return child == 0 && parent == 0;
	}
	bool isZero() const {
		return !isNaN() && child == 0;
	}
	bool isInf() const {
		return !isNaN() && parent == 0;
	}
	string val() const {
		if(isNaN()) return "NaN";
		else if(isZero()) return 0;
		else if(isInf()){
			if(getChild() > 0)return "inf";
			else return "-inf";
		}
		else
			return to_string(getChild()) + "/" + to_string(getParent());
	}
};

template<typename S = __int128_t, bool doReduction = true>
std::ostream &operator<<(std::ostream &os, const Rational<S, doReduction> &a) {
	if(a.isNaN()) os << "NaN";
	else if(a.isZero()) os << 0;
	else if(a.isInf()){
		if(a.getChild() > 0)os << "inf";
		else os << "-inf";
	}
	else
		os << a.getChild() << "/" << a.getParent();
	return os;
}