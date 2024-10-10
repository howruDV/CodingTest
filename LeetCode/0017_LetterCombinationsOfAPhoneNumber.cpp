// LeetCode 0017. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
private:
	vector<string> mappingChar[10]{
		vector<string>(),
		vector<string>(),
		vector<string>{"a","b","c"},
		vector<string>{"d","e","f"},
		vector<string>{"g","h","i"},
		vector<string>{"j","k","l"},
		vector<string>{"m","n","o"},
		vector<string>{"p","q","r","s"},
		vector<string>{"t","u","v"},
		vector<string>{"w","x","y","z"},
	};

public:
	// ==========
	// (0) BFS
	// ==========
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return vector<string>();

		deque<string> queue;
		queue.push_back("");

		// bfs : 현재 가진 letter에 가능한 조합 더 붙여 완성
		for (int i = 0; i < digits.size(); ++i)
		{
			deque<string> newStr;
			int curNum = digits[i] - '0';

			while (!queue.empty())
			{
				string curStr = queue.front();
				queue.pop_front();

				for (int j = 0; j < mappingChar[curNum].size(); ++j)
				{
					newStr.push_back(curStr + mappingChar[curNum][j]);
				}
			}

			queue = newStr;
		}

		return vector<string>(queue.begin(), queue.end());
	}

	// ==========
	// (1) DFS
	// ==========
	vector<string> ans;
	string digits_g;

	void dfs(int curIdx, string strPath)
	{
		if (curIdx >= digits_g.size())
		{
			ans.push_back(strPath);
			return;
		}

		int CurNum = digits_g[curIdx] - '0';
		curIdx++;

		for (int i = 0; i < mappingChar[CurNum].size(); ++i)
		{
			dfs(curIdx, strPath + mappingChar[CurNum][i]);
		}
	}

	vector<string> letterCombinations_dfs(string digits) {
		if (digits.empty())
			return ans;

		digits_g = digits;
		dfs(0, "");
		return ans;
	}
};