#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> trees;
int M = 0;

int main()
{
	int N = 0;
	int maxTree = 0;

	// 0. Input
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int tree = 0;
		cin >> tree;

		maxTree = max(maxTree, tree);
		trees.push_back(tree);
	}

	// 1. paramater serach
	int low = 0;
	int hight = maxTree;
	int mid = 0;

	while (low <= hight)
	{
		mid = low + (hight - low) / 2;
		long long sum = 0;

		for (int tree : trees)
		{
			if (tree > mid)
			{
				sum += (tree - mid);

				if (sum >= M)
				{
					break;
				}
			}
		}

		if (sum >= M)
		{
			maxTree = mid;
			low = mid + 1;
		}
		else
		{
			hight = mid - 1;
		}
	}

	cout << maxTree;
	return 0;
}