#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int row = 0; row < n; ++row)
    {
        string ansRow = "";

        for (int col = 0; col < n; ++col)
        {
            if ((arr1[row] & 1) || (arr2[row] & 1))
                ansRow = "#" + ansRow;
            else
                ansRow = " " + ansRow;

            arr1[row] = arr1[row] >> 1;
            arr2[row] = arr2[row] >> 1;
        }

        answer.push_back(ansRow);
    }

    return answer;
}