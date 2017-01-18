#include "StringSET.h"

#include <stack>
#include <queue>


StringSET::StringSET() : N(0) {
	root = std::make_shared<Node>();
}


StringSET::~StringSET() {
}

void StringSET::add(const std::string& key) {
	int d = 0;

	auto node = root;
	while (d < key.length()) {
		auto c = getChar(key, d++);

		if (node->next[c] == nullptr) {
			node->next[c] = std::make_shared<Node>();

			if (d == key.length()) {
				++N;
				node->next[c]->isEndOfTheKey = true;
			}
		}

		node = node->next[c];
	}
	
}

void StringSET::Delete(const std::string& key) {
	int d = 0;
	auto node = root;

	auto s = std::make_unique<std::stack<std::shared_ptr<Node>>>();

	while (node && d < key.length()) {
		s->push(node);

		auto c = getChar(key, d++);
		node = node->next[c];
	}

	if (node && d == key.length()) {
		node->isEndOfTheKey = false;

		s->push(node);

		while (s->size()) {
			auto n = s->top();
			s->pop();
			
			if (n->isEmpty()) {
				n.reset();
			}
		}
	}
}

bool StringSET::contains(const std::string& key) const {
	auto node = root;

	int d = 0;

	while (node && d < key.length()) {
		auto c = getChar(key, d++);
		node = node->next[c];
	}

	return node != nullptr && node->isEndOfTheKey;
}

std::string StringSET::toString() const {
	std::string result = "";
	
	for (int i = 0; i < root->next.size(); ++i) {
		
		if (root->next[i]) {
			auto c = static_cast<char>(i);
			std::vector<std::string> strings;
			std::string s;
			s.push_back(c);

			if (root->next[i]->isEndOfTheKey) {
				strings.push_back(s);
			}

			buildTheString(root->next[i], s, strings);

			for (auto& str : strings) {
				result += str + " ";
			}
		}
	}

	// remove the last space symbol
	if (result.size()) {
		result.pop_back();
	}

	return result;
}

void StringSET::buildTheString(std::shared_ptr<Node>& node, const std::string& str, std::vector<std::string>& strings) const {
	if (node == nullptr)
		return;

	for (int i = 0; i < node->next.size(); ++i) {
		if (node->next[i]) {
			std::string s;
			s.push_back(static_cast<char>(i));
			auto nStr = str + s;
			if (node->next[i]->isEndOfTheKey) {
				strings.push_back(nStr);
			}

			buildTheString(node->next[i], nStr, strings);
		}
	}
}

std::ostream& operator<<(std::ostream& os, const StringSET& s) {
	os << s.toString();
	return os;
}

int StringSET::getChar(const std::string& s, int d) const {
	if (d >= s.length())
		return -1;

	return s[d];
}

int StringSET::getChar(const std::string& s, int d) {
	if (d >= s.length())
		return -1;

	return s[d];
}