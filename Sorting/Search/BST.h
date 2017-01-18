#pragma once
#include "BSTBase.h"
#include <algorithm>
#include <stack>
#include <queue>

template <typename Key, typename Value>
class BST : public BSTBase<Key, Value>
{
public:
	BST() {
	}

	virtual ~BST() {
	}

protected:

	virtual Node* get_internal(Node* node, Key key) {
		if (node == nullptr)
			return nullptr;

		if (node->key == key)
			return node;

		if (key < node->key)
			return get_internal(node->left, key);
		else
			return get_internal(node->right, key);
	}

	virtual Node* get_internal(Node* node, Key key) const {
		if (node == nullptr)
			return nullptr;

		if (node->key == key)
			return node;

		if (key < node->key)
			return get_internal(node->left, key);
		else
			return get_internal(node->right, key);
	}

	virtual Node* put_internal(Node* node, Key key, Value val) {
		if (node == nullptr) {
			return new Node(key, val, 1, 1);
		}

		if (node->key == key)
			node->value = val;
		else if (key < node->key)
			node->left = put_internal(node->left, key, val);
		else
			node->right = put_internal(node->right, key, val);

		node->N = size(node->left) + size(node->right) + 1;

		node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

		return node;
	}

	virtual void keys_internal(Node* x, std::queue<Key>& q, Key lo, Key hi) const {
		if (x == nullptr)
			return;

		keys_internal(x->left, q, lo, hi);

		if (x->key >= lo && x->key <= hi)
			q.push(x->key);

		keys_internal(x->right, q, lo, hi);
	}

	virtual void keys_reverse_internal(Node* x, std::queue<Key>& q, Key lo, Key hi) const {
		if (x == nullptr)
			return;

		keys_reverse_internal(x->right, q, lo, hi);

		if (x->key >= lo && x->key <= hi)
			q.push(x->key);

		keys_reverse_internal(x->left, q, lo, hi);
	}

	

	
	
	virtual size_t height_linear_internal(const Node* x) const {
		if (x == nullptr)
			return 0;

		return x->height;
	}

	virtual size_t height_internal(const Node* x) const {
		if (x == nullptr)
			return 0;

		size_t hRight = height_internal(x->right);
		size_t hLeft = height_internal(x->left);

		size_t h = hRight;
		if (hLeft > hRight)
			h = hLeft;

		return 1 + h;
	}

	virtual int rank_internal(Node* x, Key k) const {
		if (x == nullptr)
			return 0;

		int t = size(x->left);

		if (x->key == k)
			return t;

		if (k < x->key)
			return rank_internal(x->left, k);

		return t + 1 + rank_internal(x->right, k);


	}

	virtual Node* select_internal(Node* x, int k) const {
		if (x == nullptr)
			return nullptr;

		int t = size(x->left);

		if (t > k)
			return select_internal(x->left, k);

		if (t == k)
			return x;

		return select_internal(x->right, k - t - 1);
	}

	virtual Node* ceiling_internal(Node* n, Key key) const {
		if (n == nullptr) {
			return nullptr;
		}

		if (key == n->key)
			return n;

		if (key > n->key) {
			return ceiling_internal(n->right, key);
		}

		Node* node = ceiling_internal(n->left, key);

		if (node != nullptr) {
			return node;
		}

		return n;
	}

	virtual Node* floor_internal(Node* n, Key key) const {
		if (n == nullptr) {
			return nullptr;
		}

		if (key == n->key)
			return n;

		if (key < n->key) {
			return floor_internal(n->left, key);
		}

		Node* node = floor_internal(n->right, key);

		if (node != nullptr) {
			return node;
		}

		return n;
	}

	virtual Node* min_internal(Node* n) const {
		if (n == nullptr)
			return nullptr;
		
		if (n->left == nullptr)
			return n;

		return min_internal(n->left);
	}

	virtual Node* max_internal(Node* n) const {
		if (n->right == nullptr)
			return n;

		return max_internal(n->right);
	}


};

