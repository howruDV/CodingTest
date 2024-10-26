#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstCut = 0;

// 자를 수 있는 위치를 바탕으로 자를 수 있는지 확인하는 함수
bool canCut(const vector<int>& positions, int maxPieceLength, int maxCuts, int totalLength) {
    int cuts = 0, prevCut = 0; // cuts: 자른 횟수, prevCut: 이전에 자른 위치

    for (int position : positions) {
        if (position - prevCut > maxPieceLength) {
            cuts++;
            prevCut = position;
            if (cuts > maxCuts) {
                return false; // 자른 횟수가 너무 많으면 불가능
            }
        }
    }

    // 마지막으로 남은 조각이 조건을 만족하는지 확인
    if (totalLength - prevCut > maxPieceLength) {
        cuts++;
        prevCut = positions.back();
    }

    if (cuts <= maxCuts)
    {
        firstCut = prevCut;
        return true;
    }
    return false;
}

int main() {
    int L, K, C;
    cin >> L >> K >> C; // 통나무 길이 L, 자를 수 있는 위치 K, 최대 자를 수 있는 횟수 C
    vector<int> positions(K);

    // 자를 수 있는 위치 입력받기
    for (int i = 0; i < K; ++i) {
        cin >> positions[i];
    }

    positions.push_back(0); // 통나무의 가장 왼쪽 위치도 추가
    positions.push_back(L); // 통나무의 가장 오른쪽 위치도 추가
    sort(positions.begin(), positions.end()); // 자를 수 있는 위치들을 오름차순으로 정렬

    int low = 1, high = L; // 최솟값 1부터 최댓값 L까지 이진 탐색
    int result = L;

    while (low <= high) {
        int mid = (low + high) / 2; // 중간값, 최대 자를 수 있는 조각 길이
        if (canCut(positions, mid, C, L)) {
            result = mid;
            high = mid - 1; // 더 작은 조각의 길이에서 가능한지 탐색
        }
        else {
            low = mid + 1; // 더 큰 조각의 길이에서 가능한지 탐색
        }
    }

    // 결과 출력
    cout << result << " " << firstCut << endl;
    return 0;
}
