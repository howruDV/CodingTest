// https://www.acmicpc.net/problem/1764
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
unordered_map<string, int> noneHear;

void Input()
{
	string name;

	cin >> N >> M;

	// hear
	for (int i = 0; i < N; ++i)
	{
		cin >> name;
		noneHear[name] = 1;
	}
}

void Solution()
{
	vector<string> ans;
	string name;

	// sea
	for (int i = 0; i < M; ++i)
	{
		cin >> name;
		if (noneHear[name] == 1)
			ans.push_back(name);
	}

	sort(ans.begin(), ans.end());

	cout << ans.size();
	for (string& it : ans)
		cout << endl << it;
}

int main()
{
	Input();
	Solution();

	return 0;
}