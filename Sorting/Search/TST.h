#pragma once

#include "TSTBase.h"

template <typename T>
class TST : public TSTBase<T>
{
public:
	TST() {

	}

	~TST() {

	}

private:
	virtual std::shared_ptr<T> get_internal(const std::shared_ptr<Node>& x, const std::string& key, int d) const {
		if (x == nullptr) {
			return std::shared_ptr<T>(nullptr);
		}
		
		if (d == key.length()) {
			return x->value;
		}

		auto c = getChar(key, d);

		if (c == -1) {
			return std::shared_ptr<T>(nullptr);
		}
		
		if (c == x->key) {
			return get_internal(x->mid, key, d + 1);
		}
		else if (c < x->key) {
			return get_internal(x->left, key, d);
		}
		else {
			return get_internal(x->right, key, d);
		}

	}

	virtual std::shared_ptr<Node> put_internal(std::shared_ptr<Node>& x, const std::string& key, const T& value, int d) {
		if (x == nullptr) {
			x = std::make_shared<Node>();
			auto c = getChar(key, d);
			x->key = c;

			if (d == key.length()) {
				x->value = std::make_shared<T>(value);

				++N;
			}
			else {
				x->mid = put_internal(x->mid, key, value, d + 1);
			}

			return x;
		}

		auto c = getChar(key, d);

		if (d == key.length()) {
			if (x->value == nullptr) {
				++N;
			}

			x->value = std::make_shared<T>(value);
		}
		else if (c < x->key) {
			x->left = put_internal(x->left, key, value, d);
		}
		else if (c > x->key) {
			x->right = put_internal(x->right, key, value, d);
		}
		else {
			x->mid = put_internal(x->mid, key, value, d + 1);
		}

		return x;
	}
};

