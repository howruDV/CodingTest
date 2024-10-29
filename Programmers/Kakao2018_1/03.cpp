#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) return cities.size() * 5;
    int answer = 0;
    deque<string> cache;

    for (string it : cities)
    {
        transform(it.begin(), it.end(), it.begin(), [](const char& c) {return toupper(c); });

        if (cache.size() < cacheSize)
        {
            cache.push_back(it);
            answer += 5;
            continue;
        }

        deque<string>::iterator iter = find(cache.begin(), cache.end(), it);
        if (iter != cache.end())
        {
            cache.erase(iter);
            answer += 1;
        }
        else
        {
            cache.pop_front();
            answer += 5;
        }

        cache.push_back(it);
    }

    return answer;
}