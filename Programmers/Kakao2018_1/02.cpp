#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int curFieldIdx = 0;
    vector<int> score;

    while (!dartResult.empty())
    {
        int step = 1;

        switch (curFieldIdx)
        {
            // case: score
        case 0:
        {
            if (dartResult[0] == '1' && dartResult[1] == '0')
            {
                score.push_back(10);
                step = 2;
            }
            else
            {
                score.push_back(dartResult[0] - '0');
            }
            break;
        }

        // case: bonus
        case 1:
        {
            int ex = 0;
            if (dartResult[0] == 'S') ex = 1;
            else if (dartResult[0] == 'D') ex = 2;
            else ex = 3;

            score[score.size() - 1] = pow(score[score.size() - 1], ex);
            break;
        }

        // case: option
        case 2:
        {
            if (dartResult[0] >= '0' && dartResult[0] <= '9')
            {
                step = 0;
                break;
            }

            bool op = (dartResult[0] == '*') ? 0 : 1;
            if (op == 0)
            {
                score[score.size() - 1] *= 2;
                if (score.size() != 1)
                    score[score.size() - 2] *= 2;
            }
            else
            {
                score[score.size() - 1] *= -1;
            }

            break;
        }
        }

        dartResult = string(dartResult.begin() + step, dartResult.end());
        if (++curFieldIdx > 2) curFieldIdx = 0;
    }

    for (size_t i = 0; i < score.size(); ++i)
        answer += score[i];
    return answer;
}