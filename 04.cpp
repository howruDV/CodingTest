#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<vector<int>> wating(n + 1); // (int, int, ...)[n+1]

    // 1. Parse Timetable
    for (int i = 0; i < timetable.size(); ++i)
    {
        int time = 0;
        stringstream ss(timetable[i]);
        string s;
        while (getline(ss, s, ':'))
            time = time * 60 + stoi(s);

        // put bus waiting
        for (int j = 0; j < n; ++j)
        {
            if (time <= 9 * 60 + t * j)
            {
                wating[j].push_back(time);
                break;
            }
        }
    }

    // 2. caculate queue
    int min = 0;
    for (int i = 0; i < n; ++i)
    {
        if (wating[i].size() < m)
            min = 9 * 60 + t * i;
        else
        {
            sort(wating[i].begin(), wating[i].end());
            min = wating[i][m - 1] - 1;

            int conSz = wating[i].size();
            for (int j = m; j < conSz; j++)
            {
                wating[i + 1].push_back(wating[i].back());
                wating[i].pop_back();
            }
        }
    }

    answer = ((min / 60 < 10) ? "0" + to_string(min / 60) : to_string(min / 60)) + ":"
        + ((min % 60 < 10) ? "0" + to_string(min % 60) : to_string(min % 60));
    return answer;
}