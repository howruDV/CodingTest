#include <iostream>
#include <vector>
using namespace std;

void Input(vector<vector<int>>& Friends, vector<bool>& Visit)
{
	int n = 0, m = 0;
	cin >> n >> m;
	Friends.resize(n, vector<int>());
	Visit.resize(n);

	for (int i = 0; i < m; ++i)
	{
		int friend0 = 0, friend1 = 0;
		cin >> friend0 >> friend1;

		Friends[friend0].push_back(friend1);
		Friends[friend1].push_back(friend0);
	}
}

// 현재 Idx 기준으로 남은 조합 모두 탐색
void recursion(const vector<vector<int>>& Friends, vector<bool>& Visit, int& Answer, int PairCount, int Idx)
{
	Visit[Idx] = true;

	for (int Friend : Friends[Idx])
	{
		if (!Visit[Friend])
		{
			Visit[Friend] = true;

			// 모든 pair를 구성한 경우
			if (PairCount + 1 == Friends.size() / 2)
			{
				Answer++;
				Visit[Idx] = false;
			}
			// 모든 pair를 구성하지 않은 경우 : 남은 pair 구성 진행
			else
			{
				for (int i = 0; i < Friends.size(); ++i)
				{
					if (!Visit[i])
					{
						recursion(Friends, Visit, Answer, PairCount + 1, i);
						break;
					}
				}
			}

			Visit[Friend] = false;
		}
	}

	Visit[Idx] = false;
}

int main()
{
	// input test case
	int C = 0;
	cin >> C;

	// solution
	for (int i = 0; i < C; ++i)
	{
		int Answer = 0;
		vector<vector<int>> Friends;
		vector<bool> Visit;

		Input(Friends, Visit);
		recursion(Friends, Visit, Answer, 0, 0);

		cout << Answer << endl;
	}

	return 0;
}