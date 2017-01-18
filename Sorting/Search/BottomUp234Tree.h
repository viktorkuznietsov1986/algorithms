#pragma once
#include "RedBlackBSTBase.h"
template <typename Key, typename Value>
class BottomUp234Tree :
	public RedBlackBSTBase<Key, Value>
{
public:
	BottomUp234Tree() {

	}

	virtual ~BottomUp234Tree() {

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
			if (isRed(x->right) && isRed(x->left)) {
				if (x->left->left == nullptr && x->left->right == nullptr)
					flipColors(x);
			}

			x->left = put_internal(x->left, key, val);
		}
		else {
			if (isRed(x->right) && isRed(x->left)) {
				if (x->right->left == nullptr && x->right->right == nullptr)
					flipColors(x);
			}

			x->right = put_internal(x->right, key, val);
		}

		if (isRed(x->left) && isRed(x->left->left))
			x = rotateRight(x);

		if (isRed(x->left) && isRed(x->right))
			flipColors(x);

		x->N = 1 + size(x->left) + size(x->right);

		return x;
	}
};

