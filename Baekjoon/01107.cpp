// https://www.acmicpc.net/problem/1107
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int M;
vector<string> broken;

void input()
{
	cin >> N >> M;
	broken.resize(M);
	for (int i = 0; i < M; ++i)
		cin >> broken[i];
}

void solution()
{
	int ans = abs(N - 100);
	int beforeN = -1;
	int afterN = -1;

	for (int i = 0; i < 1000000; ++i)
	{
		string strI = to_string(i);
		bool channel = true;

		for (int j = 0; j < broken.size(); ++j)
		{
			if (strI.find(broken[j]) != string::npos)
				channel = false;
		}

		if (channel && i <= N)
			beforeN = i;
		else if (afterN == -1 && channel && i > N)
			afterN = i;
	}

	if (beforeN != -1)
		ans = min(ans, abs(N - beforeN) + (int)to_string(beforeN).length());
	if (afterN != -1)
		ans = min(ans, abs(N - afterN) + (int)to_string(afterN).length());

	cout << ans;
}

int main()
{
	input();
	solution();

	return 0;
}