#include <vector>

class UnionFind
{
public:
	UnionFind(int N);
	~UnionFind();

	void connect(int i, int j);
	bool connected(int i, int j);

protected:
	int find(int k);

private:
	std::vector<int> items;
};


