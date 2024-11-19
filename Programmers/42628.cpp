// Programmers 42628
// https://school.programmers.co.kr/learn/courses/30/lessons/42628

#include <vector>
#include <string>
#include <set>
using namespace std;

enum class OpType
{
	Insert,
	PopMax,
	PopMin,
};

// string을 파싱해 operation Type, Num 반환
vector<int> ParseInput(const string& str)
{
	vector<int> ans;
	int strInt = stoi(str.substr(2));

	if (str[0] == 'I')
	{
		ans.push_back((int)OpType::Insert);
		ans.push_back(strInt);
	}
	else if (str[0] == 'D')
	{
		if (strInt == 1)
		{
			ans.push_back((int)OpType::PopMax);
		}
		else
		{
			ans.push_back((int)OpType::PopMin);
		}
	}

	return ans;
}

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	multiset<int> sorted;

	for (const string& operation : operations)
	{
		vector<int> input = ParseInput(operation);
		if (input.empty()) continue;

		OpType op = (OpType)input[0];

		switch (op)
		{
		case OpType::Insert:
			sorted.insert(input[1]);

			break;

		case OpType::PopMax:
			if (sorted.empty()) continue;
			sorted.erase(--sorted.end());

			break;

		case OpType::PopMin:
			if (sorted.empty()) continue;
			sorted.erase(sorted.begin());

			break;
		}
	}

	return sorted.empty() ? vector<int>{0, 0} : vector<int>{ *(--sorted.end()) , *sorted.begin() };
}