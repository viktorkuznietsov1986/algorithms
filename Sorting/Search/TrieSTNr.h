#pragma once
#include "TrieSTBase.h"


template <typename T>
class TrieSTNr : public TrieSTBase<T>
{
private:
	virtual std::shared_ptr<T> get_internal(const std::shared_ptr<Node>& x, const std::string& key, int d) const {
		auto node = x;
		while (node && d < key.length()) {
			auto c = getChar(key, d++);
			node = node->next[c];
		}

		if (node && d == key.length())
			return node->value;

		return std::shared_ptr<T>(nullptr);
	}

	virtual std::shared_ptr<Node> put_internal(std::shared_ptr<Node>& x, const std::string& key, int d, const T& value) {

		if (x == nullptr)
			x = std::make_shared<Node>();

		auto node = x;
		while (d < key.length()) {
			auto c = getChar(key, d++);

			if (node->next[c] == nullptr) {
				node->next[c] = std::make_shared<Node>();
			}

			node = node->next[c];
		}

		if (d == key.length()) {
			if (node->value == nullptr)
				++N;

			node->value = std::make_shared<T>(value);
		}

		return x;
	}
};

