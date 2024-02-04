// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>
using namespace std;

int N;
int ans = 0;
vector<int> rowPlacedCol;

void solution(int row)
{
	// row���� ������ �Ʒ��� Ž��
	if (row == N)
	{
		ans++;
		return;
	}

	// col ����
	for (int col = 0; col < N; ++col)
	{
		bool canPlace = true;
		rowPlacedCol[row] = col;

		// ���డ��(������ �� ����) Ȯ��
		for (int rec = 0; rec < row; ++rec)
		{
			if (rowPlacedCol[row] == rowPlacedCol[rec] || abs(rowPlacedCol[row] - rowPlacedCol[rec]) == row - rec)
			{
				canPlace = false;
				break;
			}
		}
		
		// ���� ����
		if (canPlace)
			solution(row + 1);
	}
}

int main()
{
	cin >> N;
	rowPlacedCol.resize(N);

	solution(0);
	cout << ans;

	return 0;
}