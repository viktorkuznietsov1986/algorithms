#pragma once
#include <queue>
#include <memory>

template <typename Key, typename Value>
class RedBlackBSTBase
{
protected:
	typedef enum COLOR {
		RED,
		BLACK
	};

	struct Node {
		Key key;
		Value value;
		Node* left;
		Node* right;
		int N;
		COLOR color;

		Node(Key k, Value v, int n, COLOR c) : key(k), value(v), N(n), color(c), left(nullptr), right(nullptr) {}
	};

	virtual void setColor(Node* x, COLOR c) {
		if (x == nullptr)
			return;

		x->color = c;
	}

	virtual COLOR getColor(const Node* x) const {
		if (x == nullptr)
			return COLOR::BLACK;

		return x->color;
	}

	virtual bool isRed(const Node* x) const {
		if (x == nullptr) {
			return false;
		}

		return getColor(x) == COLOR::RED;
	}

	virtual Node* rotateLeft(Node* h) {
		Node* x = h->right;
		h->right = x->left;
		x->left = h;
		setColor(x, getColor(h));
		setColor(h, COLOR::RED);
		x->N = h->N;
		h->N = 1 + size(h->left) + size(h->right);

		return x;
	}

	virtual Node* rotateRight(Node* h) {
		Node* x = h->left;
		h->left = x->right;
		x->right = h;
		setColor(x, getColor(h));
		setColor(h, COLOR::RED);
		x->N = h->N;
		h->N = 1 + size(h->left) + size(h->right);

		return x;
	}

	virtual void flipColors(Node* x) {
		setColor(x, COLOR::RED);
		setColor(x->left, COLOR::BLACK);
		setColor(x->right, COLOR::BLACK);
	}

	virtual void flipColors1(Node* x) {
		if (getColor(x) == COLOR::RED)
			setColor(x, COLOR::BLACK);
		else 
			setColor(x, COLOR::RED);

		if (getColor(x->left) == COLOR::RED)
			setColor(x->left, COLOR::BLACK);
		else
			setColor(x->left, COLOR::RED);

		if (getColor(x->right) == COLOR::RED)
			setColor(x->right, COLOR::BLACK);
		else
			setColor(x->right, COLOR::RED);
	}

	Node* root;
	Node* recentlyTouchedNode;
public:
	RedBlackBSTBase() {
		root = nullptr;
		recentlyTouchedNode = nullptr;
	}

	virtual ~RedBlackBSTBase() {
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

	virtual int size() const {
		return size(root);
	}

	virtual void put(Key key, Value val) {
		if (recentlyTouchedNode != nullptr) {
			if (key == recentlyTouchedNode->key) {
				recentlyTouchedNode->value = val;
				return;
			}
		}

		root = put_internal(root, key, val);
		setColor(root, COLOR::BLACK);
	}

	virtual std::shared_ptr<Value> get(Key key) {
		if (recentlyTouchedNode != nullptr) {
			if (key == recentlyTouchedNode->key)
				return std::shared_ptr<Value>(new Value(recentlyTouchedNode->value));
		}

		auto node = get_internal(root, key);

		recentlyTouchedNode = node;

		if (node == nullptr)
			return std::shared_ptr<Value>(nullptr);

		return std::shared_ptr<Value>(new Value(node->value));
	}

	virtual bool contains(Key key) const {
		auto node = get_internal(root, key);

		return node != nullptr;
	}

protected:
	// need to be used only for delete 
	Node* balance(Node* x) {
		if (isRed(x->right)) {
			x = rotateLeft(x);
		}

		if (isRed(x->left) && isRed(x->left->left)) {
			x = rotateRight(x);
		}

		if (isRed(x->left) && isRed(x->right))
			flipColors1(x);

		x->N = 1 + size(x->left) + size(x->right);

		return x;
	}

	int size(Node* x) const {
		if (x == nullptr)
			return 0;

		return 1 + size(x->left) + size(x->right);
	}

	virtual Node* get_internal(Node* x, Key key) {
		if (x == nullptr)
			return nullptr;

		if (key == x->key)
			return x;

		if (key < x->key)
			return get_internal(x->left, key);

		return get_internal(x->right, key);
	}

	virtual Node* get_internal(Node* x, Key key) const {
		if (x == nullptr)
			return nullptr;

		if (key == x->key)
			return x;

		if (key < x->key)
			return get_internal(x->left, key);

		return get_internal(x->right, key);
	}

	virtual Node* put_internal(Node* x, Key key, Value val) = 0;
};

