#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Idea : ���� ������ �ִ밪�� ���� DP ���, ���� DP ������ DP�� ����
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<int> DP (triangle.size() + 2, 0);
    
    for (int i = 0; i < triangle.size(); ++i)
    {
        vector<int> newDP(triangle.size() + 2, 0);

        for (int j = 1; j <= triangle[i].size(); ++j)
        {
            const int triIdx = j - 1;
            newDP[j] = triangle[i][triIdx] + max(DP[j - 1], DP[j]);
            answer = max(answer, newDP[j]); 
        }

        DP = newDP;
    }

    return answer;
}