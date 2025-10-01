#include <bits/stdc++.h>
using namespace std;

template <typename Op, typename T>
concept MonoidOperation = requires(Op op, T a, T b) {
	{ op(a, b) } -> std::convertible_to<T>;
	{ Op::identity } -> std::convertible_to<T>;
};

template <typename T> struct AddMonoid {
	static constexpr T identity = T{};
	T operator()(const T &a, const T &b) const { return a + b; }
};

template <typename T, MonoidOperation<T> Op = AddMonoid<T>> class MonoidStack {
  private:
	std::stack<T> elements;
	std::stack<T> prefix;
	Op operation;

  public:
	MonoidStack() : operation(Op{}) {}
	explicit MonoidStack(Op op) : operation(op) {}
	void push(const T &value) {
		elements.push(value);
		if (prefix.empty()) {
			prefix.push(value);

		} else {
			T current = operation(prefix.top(), value);
			prefix.push(current);
		}
	}
	void push(const T &&value) {
		elements.push(std::move(value));
		if (prefix.empty()) {
			prefix.push(elements.top());
		} else {
			T current = operation(prefix.top(), elements.top());
			prefix.push(std::move(current));
		}
	}

	const T &top() { return elements.top(); }

	T combine() const {
		if (prefix.empty()) { return Op::identity; }
		return prefix.top();
	}

	bool empty() const { return elements.empty(); }
	size_t size() const { return elements.size(); }
	void clear() {
		while (!elements.empty()) {
			elements.pop();
			prefix.pop();
		}
	}
};

int main() {
	return 0;
}
