// LeetCode 0020. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

#include <list>
#include <string>
using namespace::std;

// Time Complexity O(n)
class Solution {
public:
	bool isValid(string s) {
		list<char> stack;

		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				stack.push_back(s[i]);
			}
			else
			{
				if (stack.empty())
					return false;

				char stackPop = stack.back();
				stack.pop_back();

				if (!((s[i] == ')' && stackPop == '(')
					|| (s[i] == '}' && stackPop == '{')
					|| (s[i] == ']' && stackPop == '[')))
					return false;
			}
		}

		if (stack.empty())
			return true;
		return false;
	}
};