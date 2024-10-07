// LeetCode 0316. Remove Duplicate Letters
// https://leetcode.com/problems/remove-duplicate-letters/

#include <string>
#include <unordered_map>
#include <set>
using namespace::std;

// Time Complexity O(n)
class Solution {
public:
	// ==========
	// (1) Stack
	// ==========
	// Time Complexity O(n)
	string removeDuplicateLetters(string s) {
		string ans = "";
		unordered_map<char, int> remainCount;

		// 0. create count map
		for (int i = 0; i < s.size(); ++i)
		{
			remainCount[s[i]]++;
		}

		// 1. make stack
		for (int i = 0; i < s.size(); ++i)
		{
			remainCount[s[i]]--;

			if (ans.find(s[i]) != string::npos)
				continue;

			if (ans.empty() || s[i] > ans.back())
			{
				ans += s[i];
			}
			else
			{
				while (!ans.empty() && s[i] <= ans.back() && remainCount[ans.back()] != 0)
				{
					ans.pop_back();
				}

				ans += s[i];
			}
		}

		return ans;
	}

	// ==============
	// (2) Recursion
	// ==============
	// Time Complexity O(n)
	string removeDuplicateLetters_recur(string s) {
		if (s.size() <= 1)
			return s;

		set<char> Member(s.begin(), s.end());

		for (char it : Member)
		{
			int Pos = s.find(it);
			string SubStr = s.substr(Pos);
			set<char> SubMember(SubStr.begin(), SubStr.end());

			if (SubMember == Member)
			{
				SubStr.erase(remove(SubStr.begin(), SubStr.end(), it), SubStr.end());
				return it + removeDuplicateLetters_recur(SubStr);
			}
		}

		return "";
	}
};