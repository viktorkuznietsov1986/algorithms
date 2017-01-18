#pragma once


#include "RedBlackBSTBase.h"

template <typename Key, typename Value>
class RedBlackBST : public RedBlackBSTBase<Key, Value>
{


public:
	RedBlackBST() {
		
	}

	~RedBlackBST() {
		
	}
	
	virtual void deleteMin() {
		if (!isRed(root->left) && !isRed(root->right))
			setColor(root, COLOR::RED);

		root = deleteMinInternal(root);

		if (size() != 0)
			setColor(root, COLOR::BLACK);
	}

	virtual void deleteMax() {
		if (!isRed(root->left) && !isRed(root->right))
			setColor(root, COLOR::RED);

		root = deleteMaxInternal(root);

		if (size() != 0)
			setColor(root, COLOR::BLACK);
	}

	virtual void Delete(Key key) {
		if (!isRed(root->left) && !isRed(root->right))
			setColor(root, COLOR::RED);

		root = deleteInternal(root, key);

		if (size() != 0)
			setColor(root, COLOR::BLACK);
	}

	

protected:
	virtual Node* deleteInternal(Node* x, Key k) {
		if (x == nullptr)
			return nullptr;

		if (k < x->key) {
			if (!isRed(x->left) && !isRed(x->left->left)) {
				x = moveRedLeft(x);
			}

			x->left = deleteInternal(x->left, k);
		}
		else if (k > x->key) {
			if (!isRed(x->right) && !isRed(x->right->left))
				x = moveRedRight(x);

			x->right = deleteInternal(x->right, k);
		}
		else {
			if (x->right == nullptr)
				return nullptr;

			auto t = x;
			x = min_internal(x->right);
			x->right = deleteMinInternal(t->right);
			x->left = t->left;
			delete t;
		}

		return balance(x);
	}

	Node* min_internal(Node* x) {
		if (x == nullptr)
			return nullptr;

		if (x->left == nullptr)
			return x;

		return min_internal(x->left);
	}

	Node* moveRedLeft(Node* x) {
		flipColors(x);

		if (isRed(x->left->right)) {
			x->right = rotateRight(x->right);
			x = rotateLeft(x);
		}

		return x;
	}

	Node* moveRedRight(Node* x) {
		flipColors(x);

		if (isRed(x->left->left)) {
			x->left = rotateLeft(x->left);
			x = rotateRight(x);
		}

		return x;
	}

	virtual Node* deleteMinInternal(Node* x) {
		if (x->left == nullptr)
			return nullptr;

		if (!isRed(x->left) && !isRed(x->left->left)) {
			x = moveRedLeft(x);
		}

		if (x->left != nullptr)
			x->left = deleteMinInternal(x->left);

		return balance(x);
	}

	virtual Node* deleteMaxInternal(Node* x) {
		if (isRed(x->left))
			x = rotateRight(x);
		
		if (x->right == nullptr)
			return nullptr;

		if (!isRed(x->right) && !isRed(x->right->left)) {
			x = moveRedRight(x);
		}

		x->right = deleteMaxInternal(x->right);

		return balance(x);
	}

	virtual Node* put_internal(Node* x, Key key, Value val) {
		if (x == nullptr) {
			recentlyTouchedNode = new Node(key, val, 1, COLOR::RED);
			return recentlyTouchedNode;
		}

		if (x->key == key) {
			x->value = val;
			recentlyTouchedNode = x;
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

