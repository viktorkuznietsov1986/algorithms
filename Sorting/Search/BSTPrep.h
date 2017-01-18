#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename Key>
class BSTPrep
{
	struct Node {
		Key key;
		Node* left;
		Node* right;
		size_t height;

		Node(Key k, Node* l, Node* r, size_t h=0) : key(k), left(l), right(r), height(h) {}
	};

public:
	BSTPrep() {
		first = nullptr;
	}

	BSTPrep(const std::vector<Key>& items) {
		fillInWithTheArray(items, 0, items.size()-1);
	}

	virtual ~BSTPrep() {

	}

	void insert(Key k) {
		first = insert(first, k);
	}

	bool isEmpty() const { return size() == 0; }
	bool size() const { return N; }

	size_t height() const {
		return height(first);
	}

	std::string toString() {

		std::vector<std::list<Key>> depthCollection;
		depthCollection.resize(height()+1);

		buildDepthCollection(depthCollection);

		std::string result;

		for (int i = height(); i >= 0; --i) {
			for (std::list<int>::const_iterator elem = depthCollection[i].begin(); elem != depthCollection[i].end(); ++elem) {
				result += std::to_string(*elem) + " ";
			}
			result += "\n";
		}

		return result;
	}

protected:
	void fillInWithTheArray(const std::vector<Key>& items, int startIndex, int endIndex) {
		if (startIndex > endIndex)
			return;

		int mid = startIndex + (endIndex - startIndex) / 2;

		insert(items[mid]);

		fillInWithTheArray(items, startIndex, mid-1);
		fillInWithTheArray(items, mid+1, endIndex);
	}

	size_t height(Node* node) const {
		if (node == nullptr)
			return 0;

		return node->height;
	}

	void buildDepthCollection(std::vector<std::list<Key>>& collection) {
		buildDepthCollection(collection, first);
	}

	void buildDepthCollection(std::vector<std::list<Key>>& collection, Node* node) {
		if (node == nullptr)
			return;

		buildDepthCollection(collection, node->left);
		buildDepthCollection(collection, node->right);

		collection[node->height].push_back(node->key);
	}

	Node* insert(Node* node, Key k) {
		if (node == nullptr) {
			++N;
			return new Node(k, nullptr, nullptr);
		}

		if (k < node->key)
			node->left = insert(node->left, k);
		else
			node->right = insert(node->right, k);

		node->height = 1 + height(node->left) + height(node->right);

		return node;
	}

private:
	Node* first;
	size_t N;
};

