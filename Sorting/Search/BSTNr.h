#pragma once
#include "BSTBase.h"

#include <stack>
template <typename Key, typename Value>
class BSTNr :
	public BSTBase<Key, Value>
{
public:
	BSTNr() {

	}

	~BSTNr() {

	}

protected:
	virtual Node* select_internal(Node* x, int r) const {

		while (x != nullptr) {
			int t = x->N;
			if (r == t)
				return x;
			else if (r < t) {
				if (x->left != nullptr) {
					x = x->left;
				}
				else {
					break;
				}
			}
			else {
				x = x->right;
				r -= t - 1;
			}
		}

		return x;
	}

	virtual int rank_internal(Node* x, Key k) const {
		
		int r = 0;

		while (x != nullptr) {
			if (k == x->key) {
				if (x->left != nullptr)
					r = x->N;

				break;
			}
			else if (k < x->key) {
				x = x->left;
			}
			else {
				x = x->right;
				r += x->N + 1;
			}
		}

		return r;
	}

	virtual Node* floor_internal(Node* x, Key k) const {
		Node* t = x;

		while (x != nullptr) {
			if (k < x->key)
				x = x->left;
			else if (k > x->key) {
				t = x;
				x = x->right;
				if (x != nullptr && x->left != nullptr) {
					x = x->left;
				}
				else {
					break;
				}
			}
			else {
				t = x;
				break;
			}
		}

		return t;
	}

	virtual Node* ceiling_internal(Node* x, Key k) const {
		auto t = x;

		while (x != nullptr) {
			if (k > x->key)
				x = x->right;
			else if (k < x->key) {
				t = x;
				x = x->left;
				if (x != nullptr && x->right != nullptr) {
					x = x->right;
				}
				else {
					break;
				}
			}
			else {
				t = x;
				break;
			}
		}

		return t;
	}

	virtual Node* min_internal(Node* x) const {
		Node* t = nullptr;
		while (x != nullptr) {
			t = x;
			x = x->left;
		}

		return t;
	}

	virtual Node* max_internal(Node* x) const {
		Node* t = nullptr;

		while (x != nullptr) {
			t = x;
			x = x->right;
		}

		return t;
	}

	virtual Node* put_internal(Node* x, Key key, Value val) {
		if (x == nullptr)
			return new Node(key, val, 1, 1);

		auto node = x;
		std::stack<Node*> path;

		while (node != nullptr) {
			path.push(node);

			if (key == node->key) {
				node->value = val;
				return x;
			}

			if (key < node->key)
				node = node->left;
			else
				node = node->right;
		}

		Node* prev = path.top();

		if (prev != nullptr) {
			if (key < prev->key) {
				prev->left = new Node(key, val, 1, 1);
			}
			else {
				prev->right = new Node(key, val, 1, 1);
			}
		}

		while (!path.empty()) {
			Node* n = path.top();
			path.pop();
			n->N += 1;
			n->height = 1 + std::max(getHeight(n->left), getHeight(n->right));
		}

		return x;
	}

	virtual Node* get_internal(Node* x, Key key) {
		Node* n = x;

		while (n != nullptr) {
			if (key == n->key)
				return n;

			if (key < n->key)
				n = n->left;
			else
				n = n->right;
		}

		return nullptr;
	}

	virtual Node* get_internal(Node* x, Key key) const {
		Node* n = const_cast<Node*>(x);

		while (n != nullptr) {
			if (key == n->key)
				return n;

			if (key < n->key)
				n = n->left;
			else
				n = n->right;
		}

		return nullptr;
	}

	virtual void keys_internal(Node* x, std::queue<Key>& q, Key lo, Key hi) const {

		std::stack<Node*> nodes;

		if (x != nullptr) {
			nodes.push(x);
		}

		while (!nodes.empty()) {
			if (x->left != nullptr) {
				nodes.push(x->left);
				x = x->left;
			}
			else {
				auto n = nodes.top();
				nodes.pop();
				auto t = n->key;
				if (t >= lo && t <= hi) {
					q.push(t);
				}

				if (n->right != nullptr) {
					nodes.push(n->right);
					x = n->right;
				}
			}
		}
	}

	virtual void keys_reverse_internal(Node* x, std::queue<Key>& q, Key lo, Key hi) const {

		std::stack<Node*> nodes;

		if (x != nullptr) {
			nodes.push(x);
		}

		while (!nodes.empty()) {
			if (x->right != nullptr) {
				nodes.push(x->right);
				x = x->right;
			}
			else {
				auto n = nodes.top();
				nodes.pop();
				auto t = n->key;
				if (t >= lo && t <= hi) {
					q.push(t);
				}

				if (n->left != nullptr) {
					nodes.push(n->left);
					x = n->left;
				}
			}
		}
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
};

