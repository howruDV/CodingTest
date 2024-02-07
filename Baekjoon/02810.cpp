// https://www.acmicpc.net/problem/2810
#include <iostream>
using namespace std;

int N;

string input()
{
	bool bCouple = false;
	string str = "*";

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		char c;
		cin >> c;
		str += c;

		if (c == 'S')
			str += '*';
		else
		{
			if (bCouple)
			{
				str += '*';
				bCouple = false;
			}
			else
				bCouple = true;
		}
	}

	return str;
}

int solution(string seat)
{
	int ans = 0;
	int count = N;

	while (count > 0)
	{
		if (seat[0] == '*')
		{
			ans++;
			seat = seat.substr(2, seat.length() - 2);
		}
		else
		{
			if (seat[1] == '*')
			{
				ans++;
				seat = seat.substr(2, seat.length() - 2);
			}
			else
				seat = seat.substr(1, seat.length() - 1);
		}

		--count;
	}

	return ans;
}

int main()
{
	string N;
	N = input();
	cout << solution(N);
		
	return 0;
}