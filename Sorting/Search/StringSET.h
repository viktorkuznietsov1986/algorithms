#pragma once
#include <string>
#include <array>
#include <iostream>
#include <memory>
#include <vector>

class StringSET
{
	static const int R = 256;

	struct Node {
		std::array<std::shared_ptr<Node>, R> next;
		bool isEndOfTheKey;

		bool isEmpty() const {
			for (auto& n : next) {
				if (n != nullptr)
					return false;
			}

			return true;
		}
	};

public:
	StringSET();
	~StringSET();

	void add(const std::string& key);
	void Delete(const std::string& key);
	bool contains(const std::string& key) const;


	int size() const { return N; }
	bool isEmpty() const { return size() == 0; }

	std::string toString() const;

	friend std::ostream& operator<<(std::ostream& os, const StringSET& s);

private:
	void buildTheString(std::shared_ptr<Node>& node, const std::string& str, std::vector<std::string>& strings) const;

	int getChar(const std::string& s, int d) const;
	int getChar(const std::string& s, int d);

private:
	int N;
	std::shared_ptr<Node> root;
};

