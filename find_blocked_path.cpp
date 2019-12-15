#include <iostream>
#include <vector>
#include <algorithm>
#include <forward_list>
using namespace std;

vector<vector<int>> getDangerousPaths(vector<forward_list<int>> graph, int v)
{
	vector<vector<int>> dangerousPaths;
	for(int i = 0; i < graph.size(); i++)
	{
		for(auto it1 = graph[i].begin(); it1 != graph[i].end(); it1++)
		{
			bool cyclePath = false;
			for(auto it2 = graph[i].begin(); it2 != graph[i].end(); it2++)
			{
				if(it2 != it1)
				{
					forward_list<int>::iterator it3;
					it3 = find(graph[*it2].begin(), graph[*it2].end(), *it1);
					if(it3 == graph[*it2].end())
					{
						cyclePath = false;
					}
					else
					{
						cyclePath = true;
						break;
					}
				}
			}
			if(!cyclePath)
			{
				vector<vector<int>>::iterator it4;
				vector<int> temp = { *it1, i };
				it4 = find(dangerousPaths.begin(), dangerousPaths.end(), temp);
				if(it4 == dangerousPaths.end())
				{
					vector<int> arr = { i, *it1 };
					dangerousPaths.push_back(arr);
				}
			}
		}
	}
	return dangerousPaths;
}

int main()
{
	vector<forward_list<int>> graph(7);
	
	/* Graph sample 1 */
	/*graph[0].assign({1, 2, 3});
	graph[1].assign({0, 2});
	graph[2].assign({0, 1, 3, 4});
	graph[3].assign({0, 2, 4});
	graph[4].assign({2, 3, 5, 6});
	graph[5].assign({4});
	graph[6].assign({4});*/

	/* Graph sample 2 */
	graph[0].assign({1, 3});
	graph[1].assign({0, 3});
	graph[2].assign({3, 4, 5});
	graph[3].assign({0, 1, 2});
	graph[4].assign({2, 6});
	graph[5].assign({2});
	graph[6].assign({4});
	vector<vector<int>> dangerousPaths = getDangerousPaths(graph, 0);
	for(int i = 0; i < dangerousPaths.size(); i++)
	{
		cout << dangerousPaths[i][0] << " " << dangerousPaths[i][1] << endl;
	}
	return 0;
}