// LeetCode 0179. Largest Number
// https://leetcode.com/problems/largest-number/description/
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// - Time Complexity O(n^2)
// - Space Complexity O(n)
class Solution0 {
public:
	string largestNumber(vector<int>& nums) {
		vector<list<string>> ret(10);
		string retStr;

		// 1. sort
		// - group by first digit
		// - compare insertion num with nums in group (already sorted nums)
		for (int it : nums)
		{
			string strIt = to_string(it);						// insertion num
			int idx = (int)strIt[0] - '0';						// insertion num's first digit
			list<string>::iterator iterRet = ret[idx].begin();	// sorted nums group

			// 2. compare by digit
			// - connect two nums to
			// - check if inserting num in front of cur num is larger
			// - (num group was already sorted, new insertionion is sorted index too)
			for (; iterRet != ret[idx].end(); ++iterRet)
			{
				string insertFirst = strIt + *iterRet;
				string compareFirst = *iterRet + strIt;
				if (insertFirst > compareFirst)
					break;
			}
			ret[idx].insert(iterRet, strIt);
		}

		// 2. make string
		for (int i = 9; i >= 0; --i)
		{
			// case: zero (in integers, "000" means "0")
			if (i == 0 && retStr.empty())
				return "0";

			for (string it : ret[i])
				retStr += it;
		}

		return retStr;
	}
};

// - Time Complexity O(nlog(n))
// - Space Complexity O(1)
class Solution1 {
private:
	bool static cmp(int a, int b)
	{
		return to_string(a) + to_string(b) > to_string(b) + to_string(a);
	}

public:
	string largestNumber(vector<int>& nums) {
		string strRet;

		// 1. sort
		sort(nums.begin(), nums.end(), cmp);

		// 2. make string
		if (nums[0] == 0)
			return "0";
		for (int it : nums)
			strRet += to_string(it);

		return strRet;
	}
};