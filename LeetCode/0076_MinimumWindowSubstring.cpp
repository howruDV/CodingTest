// Leetcode 0076. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/description/
// Time Complexity O(n+m)

#include <string>
#include <unordered_map>
#include <deque>
using namespace std;

// Idea : queue에 발견한 문자열 넣으며 탐색 시작위치 조절하기
// Time Complexity : O(n+m)
class Solution {
public:
	string minWindow(string s, string t) {
		// 1. 발견해야하는 문자열 기록
		int findRemain = t.size();
		unordered_map<char, int> charRemain;

		for (char c : t)
		{
			charRemain[c]++;
		}

		// 2. 문자열 탐색
		deque<int> findIdx;
		vector<int> shortestWindow; // front, size

		for (int i = 0; i < s.size(); ++i)
		{
			if (charRemain.count(s[i]))
			{
				// 2.1. 위치 업데이트
				if (charRemain[s[i]] > 0)
				{
					findRemain--;
				}

				charRemain[s[i]]--;
				findIdx.push_back(i);

				// 2.2. 윈도우 업데이트
				while (findRemain <= 0)
				{
					int newSize = findIdx.back() - findIdx.front() + 1;

					if (shortestWindow.empty() || newSize < shortestWindow[1])
					{
						shortestWindow = vector<int>{ findIdx.front(), newSize };
					}

					if (charRemain[s[findIdx.front()]] >= 0)
					{
						findRemain++;
					}

					charRemain[s[findIdx.front()]]++;
					findIdx.pop_front();
				}
			}
		}

		return shortestWindow.empty() ? "" : s.substr(shortestWindow[0], shortestWindow[1]);
	}
};