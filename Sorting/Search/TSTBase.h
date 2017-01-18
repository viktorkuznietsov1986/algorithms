#pragma once
#include <memory>

template <typename T>
class TSTBase
{
protected:
	struct Node {
		char key;
		std::shared_ptr<T> value;
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> mid;
		std::shared_ptr<Node> right;
	};

public:
	TSTBase() : N(0) {

	}

	virtual ~TSTBase() {

	}

	std::shared_ptr<T> get(const std::string& key) const {
		return get_internal(root, key, 0);
	}

	void put(const std::string& key, const T& value) {
		root = put_internal(root, key, value, 0);
	}

	int size() const { return N; }

protected:
	virtual std::shared_ptr<T> get_internal(const std::shared_ptr<Node>& x, const std::string& key, int d) const = 0;

	virtual std::shared_ptr<Node> put_internal(std::shared_ptr<Node>& x, const std::string& key, const T& value, int d) = 0;

	int getChar(const std::string& s, int d) {
		if (d >= s.length())
			return -1;

		return s[d];
	}

	int getChar(const std::string& s, int d) const {
		if (d >= s.length())
			return -1;

		return s[d];
	}

protected:
	std::shared_ptr<Node> root;
	int N;
};

