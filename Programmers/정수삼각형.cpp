#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Idea : 현재 가능한 최대값을 담은 DP 기록, 이전 DP 참고해 DP값 갱신
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