// Leetcode 0241. Different Ways to Add Parentheses
// http://leetcode.com/problems/different-ways-to-add-parentheses/

#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	vector<int> elements;

	int CalcOp(char op, int num1, int num2)
	{
		int ans = 0;

		if (op == '+')
		{
			ans = num1 + num2;
		}
		else if (op == '-')
		{
			ans = num1 - num2;
		}
		else if (op == '*')
		{
			ans = num1 * num2;
		}

		return ans;
	}

	void CalcDiffComb(vector<int>& out, int left, int right)
	{
		if (left > right)
			return;
		else if (left == right)
		{
			out.push_back(elements[left]);
			return;
		}

		for (int i = left; i < right; i = i+2)
		{
			int op = i + 1;
			vector<int> leftOutput;
			vector<int> rightOutput;
			CalcDiffComb(leftOutput, left, op - 1);
			CalcDiffComb(rightOutput, op + 1, right);

			for (int leftIdx = 0; leftIdx < leftOutput.size(); ++leftIdx)
			{
				for (int rightIdx = 0; rightIdx < rightOutput.size(); ++rightIdx)
				{
					int calc = CalcOp(elements[op], leftOutput[leftIdx], rightOutput[rightIdx]);
					out.push_back(calc);
				}
			}
		}
	}

	vector<int> diffWaysToCompute(string expression) {
		int lastOpIdx = -1;

		// 1. parse expression
		for (int i = 0; i < expression.size(); ++i)
		{
			if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
			{
				string num = expression.substr(lastOpIdx + 1, (i - lastOpIdx - 1));

				elements.push_back(stoi(num));
				elements.push_back(expression[i]);
				lastOpIdx = i;
			}
		}

		string num = expression.substr(lastOpIdx + 1);
		elements.push_back(stoi(num));

		// 2. divide - conqure
		vector<int> ans;
		CalcDiffComb(ans, 0, elements.size() - 1);
		return ans;
	}
};