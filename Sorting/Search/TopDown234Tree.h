#pragma once
#include "RedBlackBSTBase.h"
#include <stack>
template <typename Key, typename Value>
class TopDown234Tree :
	public RedBlackBSTBase<Key, Value>
{
public:
	TopDown234Tree() {

	}
	~TopDown234Tree() {

	}

	virtual void put(Key key, Value val) {
		if (root == nullptr) {
			root = new Node(key, val, 1, COLOR::BLACK);
			return;
		}

		auto x = root;
		Node* t = nullptr;
		std::stack<Node*> nodesToProcess;

		while (x != nullptr) {
			if (x->key == key) {
				x->value = val;
				return;
			}

			nodesToProcess.push(x);

			if (isRed(x->left) && isRed(x->right))
				flipColors(x);

			x = balance(x);

			t = x;

			if (key < x->key)
				x = x->left;
			else
				x = x->right;
		}

		x = t;

		if (nodesToProcess.size() > 0) {
			x = nodesToProcess.top();
			nodesToProcess.pop();
			if (key < x->key)
				x->left = new Node(key, val, 1, COLOR::RED);
			else
				x->right = new Node(key, val, 1, COLOR::RED);

			x = balanceTD(x);

			x->N = 1 + size(x->left) + size(x->right);

		}

		while (nodesToProcess.size() > 0) {
			auto t = nodesToProcess.top();
			nodesToProcess.pop();
			if (t->key > x->key)
				t->left = x;
			else
				t->right = x;

			t = balanceTD(t);
			t->N = 1 + size(t->left) + size(t->right);
			x = t;
		}

		root = x;

		setColor(root, COLOR::BLACK);
	}

protected:

	Node* balanceTD(Node* x) {
		if (x == nullptr)
			return nullptr;

		if (!isRed(x->left) && isRed(x->right))
			x = rotateLeft(x);

		if (isRed(x->left) && isRed(x->left->left))
			x = rotateRight(x);

		return x;
	}

	virtual Node* put_internal(Node* x, Key key, Value val) {
		if (x == nullptr) {
			return new Node(key, val, 1, COLOR::RED);
		}

		if (key == x->key) {
			x->value = val;
			return x;
		}

		if (isRed(x->right) && isRed(x->left)) {
			flipColors(x);
		}

		if (key < x->key) {
			x->left = put_internal(x->left, key, val);
		}
		else {
			x->right = put_internal(x->right, key, val);
		}

		if (!isRed(x->left) && isRed(x->right))
			x = rotateLeft(x);

		if (isRed(x->left) && isRed(x->left->left))
			x = rotateRight(x);

		x->N = 1 + size(x->left) + size(x->right);

		return x;
	}
};

