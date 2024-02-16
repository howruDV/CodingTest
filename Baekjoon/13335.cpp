// https://www.acmicpc.net/problem/13335
#include <iostream>
#include <vector>
using namespace std;

int N, W, L;
vector<int> weight;
vector<int> homePos;

void Input()
{
	cin >> N >> W >> L;
	for (int i = 0; i < N; ++i)
	{
		weight.resize(N);
		homePos.resize(N, -1);
		cin >> weight[i];
	}
}

void Update(int _left, int _right, int& _weight, int& _time)
{
	for (int i = _left; i < _right; ++i)
	{
		if (homePos[i] > W)
			continue;
		else if (++homePos[i] == W)
			_weight -= weight[i];
	}
	_time++;
}

int Solution()
{
	int time = 0;
	int left = 0;
	int curWeight = 0;

	for (int right = 0; right < N; ++right)
	{
		Update(left, right, curWeight, time);
		while (curWeight + weight[right] > L)
			Update(left, right, curWeight, time);

		homePos[right]++;
		curWeight += weight[right];
	}
	time += W;

	return time;
}

int main()
{
	Input();
	cout << Solution();
	return 0;
}