// https://www.acmicpc.net/problem/1747
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

bool checkNPrime[1003002] = {};

void SieveOfEratosThenes()
{
	checkNPrime[1] = true;

	for (int i = 2; i < 1003002; ++i)
	{
		if (!checkNPrime[i])
		{
			for (int j = i * 2; j < 1003002; j += i)
				checkNPrime[j] = true;
		}
	}
}

bool isPalindrome(int n)
{
	string strNum = to_string(n);
	int len = strNum.length();

	for (int i = 0; i < len / 2; ++i)
	{
		if (strNum[i] != strNum[len - i - 1])
			return false;
	}

	return true;
}

void solution()
{
	// 1. input
	int N = 0;
	cin >> N;

	// 2. find min num
	for (int i = N; ; ++i)
	{
		if (!checkNPrime[i] && isPalindrome(i))
		{
			cout << i;
			return;
		}
	}
}

int main()
{
	SieveOfEratosThenes();
	solution();

	return 0;
}