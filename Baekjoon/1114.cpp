#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstCut = 0;

// �ڸ� �� �ִ� ��ġ�� �������� �ڸ� �� �ִ��� Ȯ���ϴ� �Լ�
bool canCut(const vector<int>& positions, int maxPieceLength, int maxCuts, int totalLength) {
    int cuts = 0, prevCut = 0; // cuts: �ڸ� Ƚ��, prevCut: ������ �ڸ� ��ġ

    for (int position : positions) {
        if (position - prevCut > maxPieceLength) {
            cuts++;
            prevCut = position;
            if (cuts > maxCuts) {
                return false; // �ڸ� Ƚ���� �ʹ� ������ �Ұ���
            }
        }
    }

    // ���������� ���� ������ ������ �����ϴ��� Ȯ��
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
    cin >> L >> K >> C; // �볪�� ���� L, �ڸ� �� �ִ� ��ġ K, �ִ� �ڸ� �� �ִ� Ƚ�� C
    vector<int> positions(K);

    // �ڸ� �� �ִ� ��ġ �Է¹ޱ�
    for (int i = 0; i < K; ++i) {
        cin >> positions[i];
    }

    positions.push_back(0); // �볪���� ���� ���� ��ġ�� �߰�
    positions.push_back(L); // �볪���� ���� ������ ��ġ�� �߰�
    sort(positions.begin(), positions.end()); // �ڸ� �� �ִ� ��ġ���� ������������ ����

    int low = 1, high = L; // �ּڰ� 1���� �ִ� L���� ���� Ž��
    int result = L;

    while (low <= high) {
        int mid = (low + high) / 2; // �߰���, �ִ� �ڸ� �� �ִ� ���� ����
        if (canCut(positions, mid, C, L)) {
            result = mid;
            high = mid - 1; // �� ���� ������ ���̿��� �������� Ž��
        }
        else {
            low = mid + 1; // �� ū ������ ���̿��� �������� Ž��
        }
    }

    // ��� ���
    cout << result << " " << firstCut << endl;
    return 0;
}
