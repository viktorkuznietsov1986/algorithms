#include <iostream>
#include <memory>
#include <array>

#include "arrays.h"

#include "List.h"
#include "QueueFrom2Stacks.h"

#include "ThreeStacks.h"

#include "Digraph.h"
#include "DirectedDFS.h"
#include "BSTPrep.h"

#include "Bits.h"

#include "different.h"

#include "Table.h"

#include "Rectangle.h"

int main()
{
	/*auto str = "abflcde";
	auto str1 = "dcabacp";

	std::cout << "string " << str << " is unique: " << isStringWithUniqueCharacters(str) << std::endl;
	std::cout << "string " << str1 << " is unique: " << isStringWithUniqueCharacters(str1) << std::endl;
	std::cout << "string " << str << " is permutation of " << str1 << " : " << isPermutation(str, str1) << std::endl;
	
	auto str2 = "bcaa";
	auto str3 = "acba";

	std::cout << "string " << str2 << " is permutation of " << str3 << " : " << isPermutation(str2, str3) << std::endl;*/

	/*auto lst = std::make_unique<List<int>>();
	lst->AddLast(3);
	lst->AddLast(1);
	lst->AddLast(8);
	lst->AddLast(2);
	lst->AddLast(8);
	lst->AddLast(1);
	lst->AddLast(3);
	lst->AddLast(1);
	lst->AddLast(3);

	std::cout << *lst << std::endl;*/

	/*lst->removeDuplicates();

	std::cout << *lst << std::endl;*/

	/*lst->partition(3);
	std::cout << *lst << std::endl;*/



	/*QueueFrom2Stacks<int> q;

	for (int i = 0; i < 10; ++i)
		q.enqueue(i*i);

	for (int i = 0; i < 9; ++i)
		std::cout << q.dequeue() << std::endl;

	std::cout << "the last element is: " << q.dequeue() << std::endl;
	std::cout << "the queue is empty now: " << q.isEmpty() << std::endl;*/

	/*auto s = std::make_unique<ThreeStacks<int>>();
	
	for (int i = 0; i < 5; ++i) {
		s->push1(i);
		s->push2(i * 2);
		s->push3(i * 3);
	}

	for (int i = 0; i < 5; ++i) {
		std::cout << s->pop1() << std::endl;
	}

	for (int i = 0; i < 5; ++i) {
		std::cout << s->pop2() << std::endl;
	}

	for (int i = 0; i < 5; ++i) {
		std::cout << s->pop3() << std::endl;
	}*/

	/*auto g = std::make_unique<Digraph>(10);

	g->addEdge(1, 2);
	g->addEdge(2, 3);
	g->addEdge(2, 5);

	auto dfs = std::make_unique<DirectedDFS>(*g, 1);

	std::cout << "1 has route to 2: " << dfs->hasRouteTo(2) << std::endl;
	std::cout << "1 has route to 3: " << dfs->hasRouteTo(3) << std::endl;
	std::cout << "1 has route to 5: " << dfs->hasRouteTo(5) << std::endl;
	std::cout << "1 has route to 7: " << dfs->hasRouteTo(7) << std::endl;*/

	/*std::vector<int> a;

	a.push_back(0);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(6);
	a.push_back(8);
	a.push_back(9);
	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);

	int elementsCountA = a.size();

	std::vector<int> b;
	b.push_back(3);
	b.push_back(7);
	b.push_back(8);
	b.push_back(12);
	b.push_back(16);
	b.push_back(20);
	b.push_back(90);
	b.push_back(100);

	int newElementCount = elementsCountA + b.size();
	a.resize(newElementCount);

	a.push_back(13);
*/
	/*
	auto bst = std::make_unique<BSTPrep<int>>(a);*/
	/*bst->insert(10);
	bst->insert(3);
	bst->insert(13);*/

	//std::cout << bst->toString();

	/*int a = 1024;
	int b = 19;
	
	
	std::cout << Int32ToString(a) << std::endl;
	std::cout << Int32ToString(b) << std::endl;

	std::cout << Int32ToString(injectOneIntToAnother(a, b, 2, 6));*/

	//std::cout << flipBit(1775) << std::endl;


	//std::cout << doubleToBit(0.8) << std::endl;

	//std::cout << magicIndex(a, 0, a.size()-1) << std::endl;

	/*lastKLines("c:\\temp\\neimportlog.txt", 5);*/

	/*char c[10] = "test12345";
	std::cout << c << std::endl;

	reverse(c);
	std::cout << c << std::endl;*/

	/*auto arr = my2DAlloc(5, 5);

	arr[1][2] = 5;
	arr[1][4] = 1;

	arr[4][3] = 18;

	std::cout << arr[1][2] << std::endl;

	myDeAlloc(arr, 5);*/

	//std::cout << tripleStep(5) << std::endl;

	/*mergeTwoSortedArrays(a, elementsCountA, b);

	for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
		std::cout << *it << ", ";
	}*/

	/*std::cout << missingInt("c:\\temp\\test.txt");*/

	/*std::vector<std::string> a;
	a.push_back("at");
	a.push_back("");
	a.push_back("");
	a.push_back("");
	a.push_back("ball");
	a.push_back("");
	a.push_back("");
	a.push_back("car");
	a.push_back("");
	a.push_back("");
	a.push_back("dad");
	a.push_back("");
	a.push_back("");

	std::cout << sparseSearch(a, "car");*/

	/*std::array<std::array<int, 5>, 5> a = { {
		{1, 0, 1, 1, 0},
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1},
		{1, 1, 1, 1, 1}
	 } };

	auto b = my2DAlloc(5, 5);

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			b[i][j] = a[i][j];
	
	zeroMatrix(b, 5, 5);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			std::cout << a[i][j] << ", ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			std::cout << b[i][j] << ", ";
		}

		std::cout << std::endl;
	}

	myDeAlloc(b, 5);*/

	/*auto t = std::make_unique<Table>();
	t->eat();*/

	/*auto r1 = std::make_unique<Rectangle>(0, 0, 2, 2);
	auto r2 = std::make_unique<Rectangle>(0, 0, 1, 3);
	auto r3 = std::make_unique<Rectangle>(5, 5, 1, 3);
*/
	//std::cout << tripleStep(5) << std::endl;

	/*std::cout << "r1 intersects with r2: " << r1->intersects(*r2) << std::endl;
	std::cout << "r1 intersects with r3: " << r1->intersects(*r3) << std::endl;
*/
	//(2,4,5,6,4)
	std::vector<int> a;
	a.push_back(2);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(4);
	a.push_back(2);
	a.push_back(2);

	std::cout << sumOfMostCommonIntRuntime(a) << std::endl;
	std::cout << sumOfMostCommonIntSpace(a) << std::endl;
	
	std::cin.get();

	return 0;
}