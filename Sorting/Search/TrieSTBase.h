#pragma once
#include <memory>
#include <array>
#include <string>

template <typename T>
class TrieSTBase
{
protected:
	static const int R = 256;

	struct Node {
		std::shared_ptr<T> value;
		std::array<std::shared_ptr<Node>, R> next;
	};

public:
	TrieSTBase() : N(0) {
		root = std::make_shared<Node>();
	}

	virtual ~TrieSTBase() {
	}

	std::shared_ptr<T> get(const std::string& key) const {
		return get_internal(root, key, 0);
	}

	void put(const std::string& key, const T& value) {
		root = put_internal(root, key, 0, value);
	}

	int size() const { return N; }

protected:
	virtual std::shared_ptr<T> get_internal(const std::shared_ptr<Node>& x, const std::string& key, int d) const = 0;

	virtual std::shared_ptr<Node> put_internal(std::shared_ptr<Node>& x, const std::string& key, int d, const T& value) = 0;

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

