// https://www.acmicpc.net/problem/1946
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int T;
vector<vector<pair<int, int>>> scorePerTest;

void input()
{
	cin >> T;
	scorePerTest.resize(T);

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;

		for (int j = 0; j < N; j++)
		{
			int score1, score2;
			cin >> score1 >> score2;
			scorePerTest[i].push_back({ score1, score2 });
		}
		sort(scorePerTest[i].begin(), scorePerTest[i].end());
	}
}

void solution(int _test)
{
	int count = 1;
	int passScore = scorePerTest[_test][0].second;
	deque<pair<int, int>> explore;
	for (int i = 1; i < scorePerTest[_test].size(); ++i)
	{
		if (scorePerTest[_test][i].second < scorePerTest[_test][0].second)
			explore.push_back(scorePerTest[_test][i]);
	}

	while (!explore.empty())
	{
		pair<int, int> curScore = explore.front();
		explore.pop_front();

		if (curScore.second < passScore)
		{
			passScore = curScore.second;
			count++;
		}
	}

	cout << count << endl;
}

int main()
{
	input();
	for (int i=0; i<T; ++i)
		solution(i);

	return 0;
}