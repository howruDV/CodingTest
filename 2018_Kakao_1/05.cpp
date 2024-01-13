#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    unordered_map<string, int> elem;
    int sum = 0;
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    for (size_t i = 0; i < str1.size() - 1; ++i)
    {
        if (!(str1[i] >= 'A' && str1[i] <= 'Z' && str1[i + 1] >= 'A' && str1[i + 1] <= 'Z'))
            continue;

        string key = str1.substr(i, 2);
        elem[key]++;
        sum++;
    }

    for (size_t i = 0; i < str2.size() - 1; ++i)
    {
        if (!(str2[i] >= 'A' && str2[i] <= 'Z' && str2[i + 1] >= 'A' && str2[i + 1] <= 'Z'))
            continue;

        string key = str2.substr(i, 2);
        if (--elem[key] >= 0)
            answer++;
        else
            sum++;
    }

    if (sum == 0)
        answer = 65536;
    else
        answer = ((float)answer / (float)sum) * 65536;
    return answer;
}