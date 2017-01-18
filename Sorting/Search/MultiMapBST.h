#pragma once
#include "BST.h"

template <typename Key, typename Value>
class MultiMapBST :
	public BST<Key, Value>
{
public:
	MultiMapBST() {

	}
	virtual ~MultiMapBST() {

	}

	virtual void Delete(Key k) {
		while (contains(k)) {
			root = DeleteInternal(root, k);
		}
	}

protected:
	virtual Node* put_internal(Node* node, Key key, Value val) {
		if (node == nullptr) {
			return new Node(key, val, 1, 1);
		}

		if (node->key == key && node->value == val)
			return node;
		else if (key <= node->key)
			node->left = put_internal(node->left, key, val);
		else
			node->right = put_internal(node->right, key, val);

		node->N = size(node->left) + size(node->right) + 1;

		node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

		return node;
	}

	virtual Node* DeleteInternal(Node* x, Key k) {
		if (x == nullptr)
			return nullptr;

		if (k < x->key)
			x->left = DeleteInternal(x->left, k);
		else if (k > x->key)
			x->right = DeleteInternal(x->right, k);
		else {
			auto t = x;
			x = min_internal(x->right);
			if (x == nullptr) {
				x = t->left;
			}
			else {
				x->right = deleteMinInternal(t->right);
				x->left = t->left;
			}
			delete t;
		}

		x->N = size(x->left) + size(x->right) + 1;
		x->height = std::max(height_linear_internal(x->left), height_linear_internal(x->right)) + 1;

		return x;
	}
};

