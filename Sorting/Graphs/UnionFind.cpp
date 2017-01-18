#include "UnionFind.h"


UnionFind::UnionFind(int N) {
	items.resize(N);

	for (int i = 0; i < N; ++i) {
		items[i] = i;
	}
}


UnionFind::~UnionFind() {

}

bool UnionFind::connected(int i, int j) {
	return find(i) == find(j); 
}

void UnionFind::connect(int i, int j) {
	int u = find(i);
	int v = find(j);

	items[u] = items[v];
}

int UnionFind::find(int k) {
	auto i = k;

	if (items[i] == i)
		return i;
	
	i = find(items[i]);
	items[i] = i;

	return i;
}

