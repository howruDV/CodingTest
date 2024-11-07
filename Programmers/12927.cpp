// Programmers 12927
// https://school.programmers.co.kr/learn/courses/30/lessons/12927

#include <string>
#include <vector>
#include <queue>
using namespace std;

// Time Complexity : O(nlogn)
long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq{ works.begin(), works.end() };

    // 1. 큰 값부터 찾아가며 값을 줄임
    for (int i = 0; i < n; ++i)
    {
        if (pq.empty())
            return 0;

        int max = pq.top() - 1;
        pq.pop();

        if (max > 0)
        {
            pq.push(max);
        }
    }

    // 2. 피로도 계산
    while (!pq.empty())
    {
        int max = pq.top();
        pq.pop();

        answer += max * max;
    }

    return answer;
}