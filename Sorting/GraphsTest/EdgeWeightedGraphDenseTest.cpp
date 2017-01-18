#include "stdafx.h"
#include "CppUnitTest.h"
#include "EdgeWeightedGraphDense.h"

#include <memory>
#include <algorithm>
#include <list>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphsTest
{
	TEST_CLASS(EdgeWeightedGraphDenseTest)
	{
		std::list<int> fillInTheAdjVert() {
			std::list<int> result;

			result.push_back(0);
			result.push_back(1);
			result.push_back(2);
			result.push_back(4);
			result.push_back(5);

			return result;
		}

		bool compareAdjVertices(const std::list<Edge>& adj, const std::list<int>& adjVert, int vertexToExclude) {
			bool result = true;
			
			std::list<int>::const_iterator adjVertIt = adjVert.cbegin();
			for (std::list<Edge>::const_iterator adjit = adj.cbegin(); adjit != adj.cend() && adjVertIt != adjVert.cend(); ++adjit, ++adjVertIt) {
				auto w = adjit->other(vertexToExclude);
				auto v = *adjVertIt;

				if (w == v)
					continue;

				result = false;
				break;


			}

			return result;
		}

	public:

		TEST_METHOD(EdgeWeightedGraphDense_BasicFlow)
		{
			auto g = std::make_unique<EdgeWeightedGraphDense>(8);
			g->addEdge(4, 5, 0.35);
			g->addEdge(4, 7, 0.37);
			g->addEdge(5, 7, 0.28);
			g->addEdge(0, 7, 0.16);
			g->addEdge(1, 5, 0.32);
			g->addEdge(0, 4, 0.38);
			g->addEdge(2, 3, 0.17);
			g->addEdge(1, 7, 0.19);
			g->addEdge(0, 2, 0.26);
			g->addEdge(1, 2, 0.36);
			g->addEdge(1, 3, 0.29);
			g->addEdge(2, 7, 0.34);
			g->addEdge(6, 2, 0.40);
			g->addEdge(3, 6, 0.52);
			g->addEdge(6, 0, 0.58);
			g->addEdge(6, 4, 0.93);

			Assert::IsTrue(g->V() == 8);
			Assert::IsTrue(g->E() == 16);

			auto adj = g->adj(7);
			Assert::IsTrue(adj.size() == 5);

			auto adjVert = { 0, 1, 2, 4, 5 };

			Assert::IsTrue(compareAdjVertices(adj, adjVert, 7));
		}

	};
}