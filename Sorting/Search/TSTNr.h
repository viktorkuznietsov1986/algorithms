#pragma once
#include "TSTBase.h"
template <typename T>
class TSTNr :
	public TSTBase<T>
{
private:
	virtual std::shared_ptr<T> get_internal(const std::shared_ptr<Node>& x, const std::string& key, int d) const {
		
		auto node = x;

		while (node && d < key.length()) {
			auto c = getChar(key, d);
			
			if (c < node->key) {
				node = node->left;
			}
			else if (c > node->key) {
				node = node->right;
			}
			else {
				++d;
				node = node->mid;
			}
		}

		if (node && d == key.length())
			return node->value;

		return std::shared_ptr<T>(nullptr);
	}

	virtual std::shared_ptr<Node> put_internal(std::shared_ptr<Node>& x, const std::string& key, const T& value, int d) {
		if (x == nullptr) {
			x = std::make_shared<Node>();
			auto c = getChar(key, d);
			x->key = c;
		}

		auto node = x;
		while (d < key.length()) {
			auto c = getChar(key, d);

			if (c < node->key) {
				if (node->left == nullptr) {
					node->left = std::make_shared<Node>();
					node->left->key = getChar(key, d);
				}

				node = node->left;
			}
			else if (c > node->key) {
				if (node->right == nullptr) {
					node->right = std::make_shared<Node>();
					node->right->key = getChar(key, d);
				}

				node = node->right;
			}
			else {
				++d;
				if (node->mid == nullptr) {
					node->mid = std::make_shared<Node>();
					node->mid->key = getChar(key, d);
				}
				
				node = node->mid;
			}
		}

		if (node->value == nullptr)
			++N;

		node->value = std::make_shared<T>(value);

		return x;
	}
};

