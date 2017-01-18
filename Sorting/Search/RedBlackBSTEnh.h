#pragma once
#include "RedBlackBSTBase.h"

template <typename Key, typename Value>
class RedBlackBSTEnh :
	public RedBlackBSTBase<Key, Value>
{
protected:
	virtual void setColor(Node* x, COLOR c) {
		if (x == nullptr)
			return;

		if (getColor(x) == c)
			return;

		auto t = x->left;
		x->left = x->right;
		x->right = t;
	}

	virtual COLOR getColor(const Node* x) const {
		if (x == nullptr)
			return COLOR::BLACK;

		if (x->left == nullptr)
			return COLOR::RED;

		if (x->right == nullptr)
			return COLOR::BLACK;

		if (x->left->key < x->right->key)
			return COLOR::BLACK;

		return COLOR::RED;
	}

public:
	RedBlackBSTEnh() {

	}

	virtual ~RedBlackBSTEnh() {

	}

protected:

	virtual Node* put_internal(Node* x, Key key, Value val) {
		if (x == nullptr) {
			return new Node(key, val, 1, COLOR::RED);
		}

		if (x->key == key) {
			x->value = val;
			return x;
		}

		if (key < x->key) {
			x->left = put_internal(x->left, key, val);
		}
		else {
			x->right = put_internal(x->right, key, val);
		}

		if (!isRed(x->left) && isRed(x->right)) {
			x = rotateLeft(x);
		}

		if (isRed(x->left) && isRed(x->left->left)) {
			x = rotateRight(x);
		}

		if (isRed(x->left) && isRed(x->right))
			flipColors(x);

		x->N = 1 + size(x->left) + size(x->right);

		return x;
	}
};

