#include "StringSortST.h"
#include <map>
#include <memory>


void StringSortST::sort(std::vector<std::string>& a, int w) {
	
	std::vector<std::string> aux;
	aux.resize(a.size());

	for (int i = w - 1; i >= 0; --i) {
		
		auto st = std::make_unique<std::map<char, int>>();
		

		for (int j = 0; j < a.size(); ++j) {
			auto c = a[j][i];

			if (st->find(c) != st->end()) {
				(*st)[c] += 1;
			}
			else {
				st->insert(std::pair<char, int>(c, 1));
			}
		}

		auto it = st->begin();
		auto next = it;
		++next;
		auto prev = it->second;
		it->second = 0;
		
		while (next != st->end()) {
			auto tmp = next->second;
			next->second = it->second + prev;
			prev = tmp;
			++it;
			++next;
		}

		for (int j = 0; j < a.size(); ++j) {
			auto c = a[j][i];
			auto position = (*st)[c];
			aux[position] = a[j];
			(*st)[c] += 1;
		}
		
		for (int j = 0; j < a.size(); ++j) {
			a[j] = aux[j];
		}

	}
}