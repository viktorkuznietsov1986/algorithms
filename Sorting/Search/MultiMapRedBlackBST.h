#pragma once
#include "RedBlackBST.h"

template <typename Key, typename Value>
class MultiMapRedBlackBST :
	public RedBlackBST<Key, Value>
{
private:
	

public:
	MultiMapRedBlackBST() {

	}
	virtual ~MultiMapRedBlackBST() {

	}

	virtual void put(Key key, Value val) {
		root = put_internal(root, key, val);
		setColor(root, COLOR::BLACK);
	}

	virtual void Delete(Key k) {
		while (contains(k)) {
			if (!isRed(root->left) && !isRed(root->right))
				setColor(root, COLOR::RED);

			root = deleteInternal(root, k);

			if (size() != 0)
				setColor(root, COLOR::BLACK);
		}
	}

protected:
	virtual Node* put_internal(Node* x, Key key, Value val) {
		if (x == nullptr) {
			return new Node(key, val, 1, COLOR::RED);
		}

		if (x->key == key && x->value == val) {
			return x;
		}

		if (key <= x->key) {
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

	virtual Node* deleteInternal(Node* x, Key k) {
		if (x == nullptr)
			return nullptr;

		if (k < x->key) {
			if (!isRed(x->left) && !isRed(x->left->left)) {
				x = moveRedLeft(x);
			}

			x->left = deleteInternal(x->left, k);
		}
		else {
			if (isRed(x->left))
				x = rotateRight(x);

			if (k == x->key && x->right == nullptr)
				return nullptr;

			if (!isRed(x->right) && !isRed(x->right->left))
				x = moveRedRight(x);

			if (k == x->key) {
				auto t = x;
				x = min_internal(x->right);
				x->right = deleteMinInternal(t->right);
				x->left = t->left;
				delete t;
			}
			else {
				x->right = deleteInternal(x->right, k);
			}
		}

		return balance(x);
	}
};

