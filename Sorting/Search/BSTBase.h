#pragma once
#include "IIndexedSymbolTable.h"
#include <algorithm>
#include <stack>
#include <queue>

template <typename Key, typename Value>
class BSTBase :
	public IIndexedSymbolTable<Key, Value>
{
protected:
	struct Node {
		Key key;
		Value value;
		Node* left;
		Node* right;
		int N;
		int height;
		
		Node(Key k, Value v, int n, int h) : key(k), value(v), left(nullptr), right(nullptr), N(n), height(h) {

		}
	};

	Node* root;
	Node* recentNode;

public:
	BSTBase() {
		root = nullptr;
		recentNode = nullptr;
	}

	virtual ~BSTBase() {
		std::queue<Node*> cleanupQueue;
		cleanupQueue.push(root);

		while (!cleanupQueue.empty()) {
			auto element = cleanupQueue.front();
			cleanupQueue.pop();

			if (element->left != nullptr)
				cleanupQueue.push(element->left);

			if (element->right != nullptr)
				cleanupQueue.push(element->right);

			delete element;
		}
	}

	virtual void put(Key key, Value val) {
		if (recentNode != nullptr && recentNode->key == key) {
			recentNode->value = val;
		}
		else {
			root = put_internal(root, key, val);
		}
	}

	virtual std::shared_ptr<Value> get(Key key) {
		if (recentNode != nullptr && recentNode->key == key) {
			return std::shared_ptr<Value>(new Value(recentNode->value));
		}

		return std::shared_ptr<Value>(new Value(get_internal(root, key)->value));
	}

	virtual void Delete(Key key) {
		root = DeleteInternal(root, key);
	}

	virtual bool contains(Key key) const {
		return get_internal(root, key) != nullptr;
	}

	virtual bool isEmpty() const {
		return size() == 0;
	}

	virtual size_t size() const {
		return size(root);
	}

	virtual int rank(Key key) const {
		return rank_internal(root, key);
	}

	virtual Key min() const {
		return min_internal(root)->key;
	}

	virtual Key max() const {
		return max_internal(root)->key;
	}

	virtual Key ceiling(Key key) const { // smallest key greater or equal to key
		auto n = ceiling_internal(root, key);

		/*if (n == nullptr)
		return nullptr;*/

		return n->key;
	}

	virtual Key floor(Key key) const { // largest key smaller or equal to key
		auto n = floor_internal(root, key);

		/*if (n == nullptr)
		return nullptr;*/

		return n->key;
	}

	virtual int size(Key lo, Key hi) const {
		// todo implement
		return 0;
	}

	virtual Key select(int k) const {
		return select_internal(root, k)->key;
		//return selectNr(k)->key;
	}

	virtual void deleteMin() {
		root = deleteMinInternal(root);
	}

	virtual void deleteMax() {
		root = deleteMaxInternal(root);
	}

	size_t height() const {
		return height_internal(root);
	}

	size_t height_linear() const {
		return height_linear_internal(root);
	}

	float avgCompares() const {
		return internalPath(root, 1) / size();
	}

	std::queue<Key> keys() const {
		return keys(min(), max());
	}

	std::queue<Key> keys(Key min, Key max) const {
		std::queue<Key> result;
		keys_internal(root, result, min, max);
		//keysNr(result, min, max);
		return result;
	}

	std::queue<Key> keysReverse() const {
		return keysReverse(min(), max());
	}

	std::queue<Key> keysReverse(Key min, Key max) const {
		std::queue<Key> result;

		keys_reverse_internal(root, result, min, max);

		return result;
	}

protected:
	float internalPath(Node* x, int level) const {
		if (x == nullptr)
			return 0;

		float pathLeft = internalPath(x->left, level+1);
		float pathRight = internalPath(x->right, level+1);

		return (float)level + pathLeft + pathRight;
	}

	virtual size_t height_linear_internal(const Node* x) const = 0;

	virtual size_t height_internal(const Node* x) const = 0;

	virtual void keys_internal(Node* x, std::queue<Key>& q, Key lo, Key hi) const = 0;

	virtual void keys_reverse_internal(Node* x, std::queue<Key>& q, Key lo, Key hi) const = 0;

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
			x->right = deleteMinInternal(t->right);
			x->left = t->left;
			delete t;
		}

		x->N = size(x->left) + size(x->right) + 1;
		x->height = std::max(height_linear_internal(x->left), height_linear_internal(x->right)) + 1;

		return x;
	}

	virtual Node* deleteMaxInternal(Node* x) {
		if (x->right == nullptr)
			return x->left;

		x->right = deleteMaxInternal(x->right);
		x->N = size(x->left) + size(x->right) + 1;
		x->height = std::max(height_linear_internal(x->left), height_linear_internal(x->right)) + 1;

		return x;
	}

	virtual Node* deleteMinInternal(Node* x) {
		if (x->left == nullptr)
			return x->right;

		x->left = deleteMinInternal(x->left);
		x->N = size(x->left) + size(x->right) + 1;
		x->height = std::max(height_linear_internal(x->left), height_linear_internal(x->right)) + 1;

		return x;
	}

	virtual int rank_internal(Node* x, Key k) const = 0;

	virtual Node* select_internal(Node* x, int k) const = 0;

	virtual Node* ceiling_internal(Node* n, Key key) const = 0;

	virtual Node* floor_internal(Node* n, Key key) const = 0;

	virtual size_t size(Node* x) const {
		if (x == nullptr)
			return 0;

		return x->N;
	}

	virtual Node* get_internal(Node* node, Key key) = 0;

	virtual Node* get_internal(Node* node, Key key) const = 0;

	virtual Node* put_internal(Node* node, Key key, Value val) = 0;

	size_t getHeight(Node* x) const {
		if (x == nullptr)
			return 0;

		return x->height;
	}

	virtual Node* min_internal(Node* n) const = 0;

	virtual Node* max_internal(Node* n) const = 0;
};

