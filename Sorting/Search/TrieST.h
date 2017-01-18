#pragma once

#include "TrieSTBase.h"

template <typename T>
class TrieST : public TrieSTBase<T>
{
public:
	std::string floor(const std::string& key) const {
		if (get_internal(root, key, 0) != nullptr)
			return key;
		
		std::string result;

		auto node = root;
		auto d = 0;
		auto match = true;
		
		while (node) {
			bool isSet = false;

			if (match) {
				auto c = getChar(key, d++);
				if (node->next[c]) {
					result.push_back(c);
					node = node->next[c];
				}
				else {
					match = false;
					for (int i = c; i >= 0; --i) {
						if (node->next[i]) {
							result.push_back(static_cast<char>(i));
							node = node->next[i];
							break;
						}
					}
				}

				isSet = true;
			}
			else {
				for (int i = R - 1; i >= 0; --i) {
					auto c = static_cast<char>(i);
					if (node->next[i]) {
						result.push_back(c);
						node = node->next[i];
						isSet = true;
						break;
					}
				}
			}

			if (!isSet)
				break;
		}

		return result;
	}

	std::string ceiling(const std::string& key) const {
		if (get_internal(root, key, 0) != nullptr)
			return key;

		std::string result;

		auto node = root;
		auto d = 0;
		auto match = true;

		while (node != nullptr) {
			bool isSet = false;
			if (match) {
				auto c = getChar(key, d++);
				if (node->next[c] != nullptr) {
					result.push_back(c);
					node = node->next[c];
				}
				else {
					match = false;
					for (int i = c; i < R; ++i) {
						if (node->next[i] != nullptr) {
							result.push_back(static_cast<char>(i));
							node = node->next[i];
							break;
						}
					}
				}

				isSet = true;
			}
			else {
				for (int i = 0; i < R; ++i) {
					auto c = static_cast<char>(i);
					if (node->next[i] != nullptr) {
						result.push_back(c);
						node = node->next[i];
						isSet = true;
						break;
					}

				}
			}

			if (!isSet || (node != nullptr && node->value != nullptr))
				break;
		}

		return result;
	}

	int rank(const std::string& key) const {
		return -1;
	}

	std::string select(int rank) const {
		return "";
	}

private:


	virtual std::shared_ptr<T> get_internal(const std::shared_ptr<Node>& x, const std::string& key, int d) const {
		if (x == nullptr)
			return std::shared_ptr<T>(nullptr);

		if (d == key.length()) {
			return x->value;
		}
		else {
			auto c = getChar(key, d);
			return get_internal(x->next[c], key, d + 1);
		}
	}

	virtual std::shared_ptr<Node> put_internal(std::shared_ptr<Node>& x, const std::string& key, int d, const T& value) {
		if (x == nullptr) {
			x = std::make_shared<Node>();
		}

		if (d == key.length()) {
			if (x->value == nullptr) ++N;
			x->value = std::make_shared<T>(value);
			return x;
		}

		auto c = getChar(key, d);
		x->next[c] = put_internal(x->next[c], key, d + 1, value);

		return x;
	}
};

